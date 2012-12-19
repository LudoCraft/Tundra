// For conditions of distribution and use, see copyright notice in LICENSE

#include "CoreDefines.h"
#include "Framework.h"
#include "Application.h"
#include "AssetAPI.h"
#include "EC_RocketUiDocument.h"
#include "IAssetTransfer.h"
#include "IComponentFactory.h"
#include "InputAPI.h"

#include "LoggingFunctions.h"
#include "LibRocketPlugin.h"
#include "OgreRenderingModule.h"
#include "OgreWorld.h"
#include "Profiler.h"
#include "Renderer.h"
#include "RenderWindow.h"
#include "RenderInterfaceOgre3D.h"
#include "SceneAPI.h"
#include "SystemInterfaceTundra.h"

#include <Ogre/OgreSceneManager.h>

#ifdef IN
#undef IN
#endif
#include <Rocket/Controls.h>
#include <Rocket/Controls/ElementFormControlInput.h>
#include <Rocket/Core.h>
#include <Rocket/Core/ElementDocument.h>

LibRocketPlugin::LibRocketPlugin() :
    IModule("LibRocketPlugin"),
    systemInterface(0),
    renderInterface(0),
    context(0)
{
    InitKeyCodeMap();
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
        LogError("LibRocketPlugin: framework is not headless, but no renderwindow object! Skipping initialization.");
        return;
    }
    QObject::connect(rw, SIGNAL(Resized(int, int)), this, SLOT(OnRenderWindowResized(int, int)));
    
    systemInterface = new SystemInterfaceTundra(framework_);
    renderInterface = new RenderInterfaceOgre3D(framework_, rw->Width(), rw->Height());
    Rocket::Core::SetSystemInterface(systemInterface);
    Rocket::Core::SetRenderInterface(renderInterface);
    Rocket::Core::Initialise();
    Rocket::Controls::Initialise();
    
    context = Rocket::Core::CreateContext(Rocket::Core::String("Tundra"), Rocket::Core::Vector2i(rw->Width(), rw->Height()), renderInterface);
    if (!context)
    {
        LogError("LibRocketPlugin: Failed to create UI context");
        return;
    }
    
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
    
    inputContext = framework_->Input()->RegisterInputContext("RocketUi", 200);
    inputContext->SetTakeMouseEventsOverQt(true);
    inputContext->SetTakeKeyboardEventsOverQt(true);
    QObject::connect(inputContext.get(), SIGNAL(MouseEventReceived(MouseEvent *)), this, SLOT(OnMouseEventReceived(MouseEvent *)));
    QObject::connect(inputContext.get(), SIGNAL(KeyEventReceived(KeyEvent *)), this, SLOT(OnKeyEventReceived(KeyEvent *)));
   
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
    {
        PROFILE(LibRocketPlugin_UpdateUi);
        context->Update();
    }
}

void LibRocketPlugin::OnMouseEventReceived(MouseEvent* evt)
{
    switch (evt->eventType)
    {
    case MouseEvent::MouseMove:
        context->ProcessMouseMove(evt->x, evt->y, GetQualifierFlags());
        break;
    case MouseEvent::MousePressed:
        context->ProcessMouseButtonDown(ConvertMouseButton(evt->button), GetQualifierFlags());
        break;
    case MouseEvent::MouseReleased:
        context->ProcessMouseButtonUp(ConvertMouseButton(evt->button), GetQualifierFlags());
        break;
    }
    
    /// \todo Suppress mouse events to the 3D scene underneath as necessary
}

void LibRocketPlugin::OnKeyEventReceived(KeyEvent* evt)
{
    int rocketKeyCode = -1;
    std::map<int, int>::const_iterator i = keyCodeMap.find(evt->keyCode);
    if (i != keyCodeMap.end())
        rocketKeyCode = i->second;
    
    switch (evt->eventType)
    {
    case KeyEvent::KeyPressed:
        if (rocketKeyCode >= 0)
        {
            //LogInfo("Keydown qt " + QString::number(evt->keyCode) + " rocket " + QString::number(rocketKeyCode));
            context->ProcessKeyDown((Rocket::Core::Input::KeyIdentifier)rocketKeyCode, GetQualifierFlags());
        }
        //else
        //    LogInfo("Keyup qt " + QString::number(evt->keyCode) + " rocket key unknown");
        
        if (evt->text.length())
        {
            for (int j = 0; j < evt->text.length(); ++j)
            {
                //LogInfo("Textinput " + QString::number(evt->text[j].unicode()));
                context->ProcessTextInput(evt->text[j].unicode());
            }
        }
        break;
    case KeyEvent::KeyReleased:
        if (rocketKeyCode >= 0)
        {
            //LogInfo("Keyup qt " + QString::number(evt->keyCode) + " rocket " + QString::number(rocketKeyCode));
            context->ProcessKeyUp((Rocket::Core::Input::KeyIdentifier)rocketKeyCode, GetQualifierFlags());
        }
        //else
        //    LogInfo("Keyup qt " + QString::number(evt->keyCode) + " rocket key unknown");
        break;
    }
    
    // Suppress the key event from going to Qt if an input element is focused
    Rocket::Core::Element* el = context->GetFocusElement();
    if (el && dynamic_cast<Rocket::Controls::ElementFormControlInput*>(el))
        evt->Suppress();
}

int LibRocketPlugin::GetQualifierFlags()
{
    int flags = 0;
    
    if (inputContext->IsKeyDown(Qt::Key_Shift))
        flags |= Rocket::Core::Input::KM_SHIFT;
    if (inputContext->IsKeyDown(Qt::Key_Control))
        flags |= Rocket::Core::Input::KM_CTRL;
    if (inputContext->IsKeyDown(Qt::Key_Alt) || inputContext->IsKeyDown(Qt::Key_AltGr))
        flags |= Rocket::Core::Input::KM_ALT;
    if (inputContext->IsKeyDown(Qt::Key_NumLock))
        flags |= Rocket::Core::Input::KM_NUMLOCK;
    if (inputContext->IsKeyDown(Qt::Key_CapsLock))
        flags |= Rocket::Core::Input::KM_CAPSLOCK;
    
    return flags;
}

int LibRocketPlugin::ConvertMouseButton(int button)
{
    int idx = 0;
    while (button)
    {
        if (button & 1)
            return idx;
        ++idx;
        button >>= 1;
    }
    
    return -1;
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

void LibRocketPlugin::InitKeyCodeMap()
{
    /// \todo Not all-encompassing
    keyCodeMap[Qt::Key_A] = Rocket::Core::Input::KI_A;
    keyCodeMap[Qt::Key_B] = Rocket::Core::Input::KI_B;
    keyCodeMap[Qt::Key_C] = Rocket::Core::Input::KI_C;
    keyCodeMap[Qt::Key_D] = Rocket::Core::Input::KI_D;
    keyCodeMap[Qt::Key_E] = Rocket::Core::Input::KI_E;
    keyCodeMap[Qt::Key_F] = Rocket::Core::Input::KI_F;
    keyCodeMap[Qt::Key_G] = Rocket::Core::Input::KI_G;
    keyCodeMap[Qt::Key_H] = Rocket::Core::Input::KI_H;
    keyCodeMap[Qt::Key_I] = Rocket::Core::Input::KI_I;
    keyCodeMap[Qt::Key_J] = Rocket::Core::Input::KI_J;
    keyCodeMap[Qt::Key_K] = Rocket::Core::Input::KI_K;
    keyCodeMap[Qt::Key_L] = Rocket::Core::Input::KI_L;
    keyCodeMap[Qt::Key_M] = Rocket::Core::Input::KI_M;
    keyCodeMap[Qt::Key_N] = Rocket::Core::Input::KI_N;
    keyCodeMap[Qt::Key_O] = Rocket::Core::Input::KI_O;
    keyCodeMap[Qt::Key_P] = Rocket::Core::Input::KI_P;
    keyCodeMap[Qt::Key_Q] = Rocket::Core::Input::KI_Q;
    keyCodeMap[Qt::Key_R] = Rocket::Core::Input::KI_R;
    keyCodeMap[Qt::Key_S] = Rocket::Core::Input::KI_S;
    keyCodeMap[Qt::Key_T] = Rocket::Core::Input::KI_T;
    keyCodeMap[Qt::Key_U] = Rocket::Core::Input::KI_U;
    keyCodeMap[Qt::Key_V] = Rocket::Core::Input::KI_V;
    keyCodeMap[Qt::Key_W] = Rocket::Core::Input::KI_W;
    keyCodeMap[Qt::Key_X] = Rocket::Core::Input::KI_X;
    keyCodeMap[Qt::Key_Y] = Rocket::Core::Input::KI_Y;
    keyCodeMap[Qt::Key_Z] = Rocket::Core::Input::KI_Z;

    keyCodeMap[Qt::Key_0] = Rocket::Core::Input::KI_0;
    keyCodeMap[Qt::Key_1] = Rocket::Core::Input::KI_1;
    keyCodeMap[Qt::Key_2] = Rocket::Core::Input::KI_2;
    keyCodeMap[Qt::Key_3] = Rocket::Core::Input::KI_3;
    keyCodeMap[Qt::Key_4] = Rocket::Core::Input::KI_4;
    keyCodeMap[Qt::Key_5] = Rocket::Core::Input::KI_5;
    keyCodeMap[Qt::Key_6] = Rocket::Core::Input::KI_6;
    keyCodeMap[Qt::Key_7] = Rocket::Core::Input::KI_7;
    keyCodeMap[Qt::Key_8] = Rocket::Core::Input::KI_8;
    keyCodeMap[Qt::Key_9] = Rocket::Core::Input::KI_9;

    keyCodeMap[Qt::Key_Backspace] = Rocket::Core::Input::KI_BACK;
    keyCodeMap[Qt::Key_Tab] = Rocket::Core::Input::KI_TAB;

    keyCodeMap[Qt::Key_Clear] = Rocket::Core::Input::KI_CLEAR;
    keyCodeMap[Qt::Key_Return] = Rocket::Core::Input::KI_RETURN;

    keyCodeMap[Qt::Key_Pause] = Rocket::Core::Input::KI_PAUSE;
    keyCodeMap[Qt::Key_CapsLock] = Rocket::Core::Input::KI_CAPITAL;

    keyCodeMap[Qt::Key_Escape] = Rocket::Core::Input::KI_ESCAPE;

    keyCodeMap[Qt::Key_Space] = Rocket::Core::Input::KI_SPACE;
    keyCodeMap[Qt::Key_End] = Rocket::Core::Input::KI_END;
    keyCodeMap[Qt::Key_Home] = Rocket::Core::Input::KI_HOME;
    keyCodeMap[Qt::Key_Left] = Rocket::Core::Input::KI_LEFT;
    keyCodeMap[Qt::Key_Up] = Rocket::Core::Input::KI_UP;
    keyCodeMap[Qt::Key_Right] = Rocket::Core::Input::KI_RIGHT;
    keyCodeMap[Qt::Key_Left] = Rocket::Core::Input::KI_DOWN;
    keyCodeMap[Qt::Key_Select] = Rocket::Core::Input::KI_SELECT;
    keyCodeMap[Qt::Key_Execute] = Rocket::Core::Input::KI_EXECUTE;
    keyCodeMap[Qt::Key_Print] = Rocket::Core::Input::KI_SNAPSHOT;
    keyCodeMap[Qt::Key_Insert] = Rocket::Core::Input::KI_INSERT;
    keyCodeMap[Qt::Key_Delete] = Rocket::Core::Input::KI_DELETE;
    keyCodeMap[Qt::Key_Help] = Rocket::Core::Input::KI_HELP;

    keyCodeMap[Qt::Key_Sleep] = Rocket::Core::Input::KI_SLEEP;

    keyCodeMap[Qt::Key_F1] = Rocket::Core::Input::KI_F1;
    keyCodeMap[Qt::Key_F2] = Rocket::Core::Input::KI_F2;
    keyCodeMap[Qt::Key_F3] = Rocket::Core::Input::KI_F3;
    keyCodeMap[Qt::Key_F4] = Rocket::Core::Input::KI_F4;
    keyCodeMap[Qt::Key_F5] = Rocket::Core::Input::KI_F5;
    keyCodeMap[Qt::Key_F6] = Rocket::Core::Input::KI_F6;
    keyCodeMap[Qt::Key_F7] = Rocket::Core::Input::KI_F7;
    keyCodeMap[Qt::Key_F8] = Rocket::Core::Input::KI_F8;
    keyCodeMap[Qt::Key_F9] = Rocket::Core::Input::KI_F9;
    keyCodeMap[Qt::Key_F10] = Rocket::Core::Input::KI_F10;
    keyCodeMap[Qt::Key_F11] = Rocket::Core::Input::KI_F11;
    keyCodeMap[Qt::Key_F12] = Rocket::Core::Input::KI_F12;
    keyCodeMap[Qt::Key_F13] = Rocket::Core::Input::KI_F13;
    keyCodeMap[Qt::Key_F14] = Rocket::Core::Input::KI_F14;
    keyCodeMap[Qt::Key_F15] = Rocket::Core::Input::KI_F15;
    keyCodeMap[Qt::Key_F16] = Rocket::Core::Input::KI_F16;
    keyCodeMap[Qt::Key_F17] = Rocket::Core::Input::KI_F17;
    keyCodeMap[Qt::Key_F18] = Rocket::Core::Input::KI_F18;
    keyCodeMap[Qt::Key_F19] = Rocket::Core::Input::KI_F19;
    keyCodeMap[Qt::Key_F20] = Rocket::Core::Input::KI_F20;
    keyCodeMap[Qt::Key_F21] = Rocket::Core::Input::KI_F21;
    keyCodeMap[Qt::Key_F22] = Rocket::Core::Input::KI_F22;
    keyCodeMap[Qt::Key_F23] = Rocket::Core::Input::KI_F23;
    keyCodeMap[Qt::Key_F24] = Rocket::Core::Input::KI_F24;

    keyCodeMap[Qt::Key_NumLock] = Rocket::Core::Input::KI_NUMLOCK;
    keyCodeMap[Qt::Key_ScrollLock] = Rocket::Core::Input::KI_SCROLL;

    keyCodeMap[Qt::Key_Shift] = Rocket::Core::Input::KI_LSHIFT;
    keyCodeMap[Qt::Key_Control] = Rocket::Core::Input::KI_LCONTROL;
    keyCodeMap[Qt::Key_Alt] = Rocket::Core::Input::KI_LMENU;

    keyCodeMap[Qt::Key_Plus] = Rocket::Core::Input::KI_OEM_PLUS;
    keyCodeMap[Qt::Key_Minus] = Rocket::Core::Input::KI_OEM_MINUS;
    keyCodeMap[Qt::Key_Comma] = Rocket::Core::Input::KI_OEM_COMMA;
    keyCodeMap[Qt::Key_Period] = Rocket::Core::Input::KI_OEM_PERIOD;
}

void LibRocketPlugin::renderQueueStarted(unsigned char queueGroupId, const Ogre::String& invocation, bool& skipThisInvocation)
{
    if (context && queueGroupId == Ogre::RENDER_QUEUE_OVERLAY && Ogre::Root::getSingleton().getRenderSystem()->_getViewport()->getOverlaysEnabled())
    {
        PROFILE(LibRocketPlugin_RenderUi);
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
