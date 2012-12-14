#include "CoreDefines.h"
#include "Framework.h"
#include "LoggingFunctions.h"
#include "LibRocketPlugin.h"
#include "OgreRenderingModule.h"
#include "Renderer.h"
#include "RenderWindow.h"
#include "RenderInterfaceOgre3D.h"
#include "SystemInterfaceTundra.h"

#ifdef IN
#undef IN
#endif
#include <Rocket/Core.h>

LibRocketPlugin::LibRocketPlugin() :
    IModule("LibRocketPlugin"),
    systemInterface(0),
    renderInterface(0)
{
}

LibRocketPlugin::~LibRocketPlugin()
{
}

void LibRocketPlugin::Initialize()
{
    if (GetFramework()->IsHeadless())
        return;
    
    OgreRenderer::RendererPtr renderer = GetFramework()->GetModule<OgreRenderer::OgreRenderingModule>()->GetRenderer();
    if (!renderer)
    {
        LogError("Framework is not headless, but no renderer object! Skipping LibRocketPlugin initialization.");
        return;
    }
    RenderWindow* rw = renderer->GetRenderWindow();
    if (!rw)
    {
        LogError("Framework is not headless, but no renderwindow object! Skipping LibRocketPlugin initialization.");
        return;
    }
    
    systemInterface = new SystemInterfaceTundra(GetFramework());
    renderInterface = new RenderInterfaceOgre3D(rw->Width(), rw->Height());
    Rocket::Core::SetSystemInterface(systemInterface);
    Rocket::Core::SetRenderInterface(renderInterface);
    Rocket::Core::Initialise();
}

void LibRocketPlugin::Uninitialize()
{
    if (systemInterface && renderInterface)
    {
        Rocket::Core::Shutdown();
        delete systemInterface;
        delete renderInterface;
        systemInterface = 0;
        renderInterface = 0;
    }
}

extern "C"
{
DLLEXPORT void TundraPluginMain(Framework *fw)
{
    Framework::SetInstance(fw); // Inside this DLL, remember the pointer to the global framework object.
    IModule *module = new LibRocketPlugin();
    fw->RegisterModule(module);
}
}
