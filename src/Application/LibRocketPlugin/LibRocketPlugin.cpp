// For conditions of distribution and use, see copyright notice in LICENSE

#include "CoreDefines.h"
#include "Framework.h"
#include "Application.h"
#include "AssetAPI.h"
#include "EC_RocketUiDocument.h"
#include "IAssetTransfer.h"
#include "IComponentFactory.h"
#include "LoggingFunctions.h"
#include "LibRocketPlugin.h"
#include "OgreRenderingModule.h"
#include "OgreWorld.h"
#include "Renderer.h"
#include "RenderWindow.h"
#include "RenderInterfaceOgre3D.h"
#include "SceneAPI.h"
#include "SystemInterfaceTundra.h"

#include <Ogre/OgreSceneManager.h>

#ifdef IN
#undef IN
#endif
#include <Rocket/Core.h>
#include <Rocket/Core/ElementDocument.h>

LibRocketPlugin::LibRocketPlugin() :
    IModule("LibRocketPlugin"),
    systemInterface(0),
    renderInterface(0),
    context(0)
{
}

LibRocketPlugin::~LibRocketPlugin()
{
}

void LibRocketPlugin::Initialize()
{
    if (framework_->IsHeadless())
        return;
    
    OgreRenderer::OgreRenderingModule* module = framework_->GetModule<OgreRenderer::OgreRenderingModule>();
    OgreRenderer::RendererPtr renderer = module->GetRenderer();
    if (!renderer)
    {
        LogError("LibRocketPlugin: framework is not headless, but no renderer object! Skipping initialization.");
        return;
    }
    RenderWindow* rw = renderer->GetRenderWindow();
    if (!rw)
    {
        LogError("LibRocketPlugin: framework is not headless, but no renderwindow object! Skippinginitialization.");
        return;
    }
    QObject::connect(rw, SIGNAL(Resized(int, int)), this, SLOT(OnRenderWindowResized(int, int)));
    
    systemInterface = new SystemInterfaceTundra(framework_);
    renderInterface = new RenderInterfaceOgre3D(framework_, rw->Width(), rw->Height());
    Rocket::Core::SetSystemInterface(systemInterface);
    Rocket::Core::SetRenderInterface(renderInterface);
    Rocket::Core::Initialise();
    
    context = Rocket::Core::CreateContext(Rocket::Core::String("Tundra"), Rocket::Core::Vector2i(rw->Width(), rw->Height()), renderInterface);
    
    // Add self to default dummy scenemanager for UI rendering
    Ogre::SceneManager* sm = renderer->GetDefaultSceneManager();
    if (sm)
        sm->addRenderQueueListener(this);
    QObject::connect(module, SIGNAL(OgreWorldCreated(OgreWorld*)), this, SLOT(OnOgreWorldCreated(OgreWorld*)));
    
    // Windows only for now: get system font path and add default fonts
#ifdef WIN32
    Rocket::Core::String systemFontPath;
    char expandedSystemPath[256];
    
    if (ExpandEnvironmentStringsA("%WinDir%", expandedSystemPath, 256))
        systemFontPath = Rocket::Core::String(expandedSystemPath) + "\\Fonts\\";
    
    Rocket::Core::String defaultFontNames[] = {
        "arial.ttf",
        ""
    };
    
    unsigned idx = 0;
    while (defaultFontNames[idx].Length())
    {
        Rocket::Core::FontDatabase::LoadFontFace(systemFontPath + defaultFontNames[idx]);
        ++idx;
    }
#endif
    
    framework_->RegisterDynamicObject("rocketui", this);
}

void LibRocketPlugin::LoadFont(const QString& assetRef)
{
    AssetAPI* assetAPI = framework_->Asset();
    // If possible, try to install the font immediately
    AssetPtr asset = assetAPI->GetAsset(assetRef);
    if (asset)
    {
        LogInfo("LibRocketPlugin: loading font " + asset->Name());
        Rocket::Core::FontDatabase::LoadFontFace(Rocket::Core::String(asset->DiskSource().toStdString().c_str()));
        return;
    }
    
    // Else make an asset request
    AssetTransferPtr transfer = assetAPI->RequestAsset(assetRef);
    if (transfer)
        QObject::connect(transfer.get(), SIGNAL(Succeeded(AssetPtr)), this, SLOT(OnFontAssetLoaded(AssetPtr)), Qt::UniqueConnection);
}

void LibRocketPlugin::OnFontAssetLoaded(AssetPtr asset)
{
    if (!asset)
    {
        LogError("LibRocketPlugin: Null font asset");
        return;
    }
    
    LogInfo("LibRocketPlugin: loading font " + asset->Name());
    Rocket::Core::FontDatabase::LoadFontFace(Rocket::Core::String(asset->DiskSource().toStdString().c_str()));
}

void LibRocketPlugin::Unload()
{
    if (context)
    {
        context->RemoveReference();
        context = 0;
    }
    
    if (systemInterface && renderInterface)
    {
        Rocket::Core::Shutdown();
        delete systemInterface;
        delete renderInterface;
        systemInterface = 0;
        renderInterface = 0;
    }
}

void LibRocketPlugin::OnRenderWindowResized(int width, int height)
{
    if (context)
        context->SetDimensions(Rocket::Core::Vector2i(width, height));
}

void LibRocketPlugin::OnOgreWorldCreated(OgreWorld* world)
{
    // Add self to newly created Ogre scenemanager for UI rendering
    world->OgreSceneManager()->addRenderQueueListener(this);
}


void LibRocketPlugin::Update(f64 timeStep)
{
    if (context)
        context->Update();
}

/*
 * This source file is part of libRocket, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://www.librocket.com
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

void LibRocketPlugin::renderQueueStarted(unsigned char queueGroupId, const Ogre::String& invocation, bool& skipThisInvocation)
{
    if (context && queueGroupId == Ogre::RENDER_QUEUE_OVERLAY && Ogre::Root::getSingleton().getRenderSystem()->_getViewport()->getOverlaysEnabled())
    {
        ConfigureRenderSystem();
        context->Render();
    }
}

// Builds an OpenGL-style orthographic projection matrix.
void BuildProjectionMatrix(Ogre::Matrix4& projection_matrix, int width, int height)
{
    float z_near = -1;
    float z_far = 1;

    projection_matrix = Ogre::Matrix4::ZERO;

    // Set up matrices.
    projection_matrix[0][0] = 2.0f / width;
    projection_matrix[0][3]= -1.0000000f;
    projection_matrix[1][1]= -2.0f / height;
    projection_matrix[1][3]= 1.0000000f;
    projection_matrix[2][2]= -2.0f / (z_far - z_near);
    projection_matrix[3][3]= 1.0000000f;
}

void LibRocketPlugin::ConfigureRenderSystem()
{
    Ogre::RenderSystem* render_system = Ogre::Root::getSingleton().getRenderSystem();

    // Set up the projection and view matrices.
    Ogre::Matrix4 projection_matrix;
    BuildProjectionMatrix(projection_matrix, context->GetDimensions().x, context->GetDimensions().y);
    render_system->_setProjectionMatrix(projection_matrix);
    render_system->_setViewMatrix(Ogre::Matrix4::IDENTITY);

    // Disable lighting, as all of Rocket's geometry is unlit.
    render_system->setLightingEnabled(false);
    // Disable depth-buffering; all of the geometry is already depth-sorted.
    render_system->_setDepthBufferParams(false, false);
    // Rocket generates anti-clockwise geometry, so enable clockwise-culling.
    render_system->_setCullingMode(Ogre::CULL_CLOCKWISE);
    // Disable fogging.
    render_system->_setFog(Ogre::FOG_NONE);
    // Enable writing to all four channels.
    render_system->_setColourBufferWriteEnabled(true, true, true, true);
    // Unbind any vertex or fragment programs bound previously by the application.
    render_system->unbindGpuProgram(Ogre::GPT_FRAGMENT_PROGRAM);
    render_system->unbindGpuProgram(Ogre::GPT_VERTEX_PROGRAM);

    // Set texture settings to clamp along both axes.
    Ogre::TextureUnitState::UVWAddressingMode addressing_mode;
    addressing_mode.u = Ogre::TextureUnitState::TAM_CLAMP;
    addressing_mode.v = Ogre::TextureUnitState::TAM_CLAMP;
    addressing_mode.w = Ogre::TextureUnitState::TAM_CLAMP;
    render_system->_setTextureAddressingMode(0, addressing_mode);

    // Set the texture coordinates for unit 0 to be read from unit 0.
    render_system->_setTextureCoordSet(0, 0);
    // Disable texture coordinate calculation.
    render_system->_setTextureCoordCalculation(0, Ogre::TEXCALC_NONE);
    // Enable linear filtering; images should be rendering 1 texel == 1 pixel, so point filtering could be used
    // except in the case of scaling tiled decorators.
    render_system->_setTextureUnitFiltering(0, Ogre::FO_LINEAR, Ogre::FO_LINEAR, Ogre::FO_POINT);
    // Disable texture coordinate transforms.
    render_system->_setTextureMatrix(0, Ogre::Matrix4::IDENTITY);
    // Reject pixels with an alpha of 0.
    render_system->_setAlphaRejectSettings(Ogre::CMPF_GREATER, 0, false);
    // Disable all texture units but the first.
    render_system->_disableTextureUnitsFrom(1);

    // Enable simple alpha blending.
    render_system->_setSceneBlending(Ogre::SBF_SOURCE_ALPHA, Ogre::SBF_ONE_MINUS_SOURCE_ALPHA);

    // Disable depth bias.
    render_system->_setDepthBias(0, 0);
}

extern "C"
{
DLLEXPORT void TundraPluginMain(Framework *fw)
{
    Framework::SetInstance(fw); // Inside this DLL, remember the pointer to the global framework object.
    fw->Scene()->RegisterComponentFactory(ComponentFactoryPtr(new GenericComponentFactory<EC_RocketUiDocument>()));
    IModule *module = new LibRocketPlugin();
    fw->RegisterModule(module);
}
}
