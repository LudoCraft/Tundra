#include "CoreDefines.h"
#include "Framework.h"
#include "LoggingFunctions.h"
#include "LibRocketPlugin.h"

LibRocketPlugin::LibRocketPlugin() :
    IModule("LibRocketPlugin")
{
}

LibRocketPlugin::~LibRocketPlugin()
{
}

void LibRocketPlugin::Load()
{
}

void LibRocketPlugin::Uninitialize()
{
}

void LibRocketPlugin::Unload()
{
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
