#pragma once

#include "CoreTypes.h"
#include "IModule.h"
#include "LibRocketPluginApi.h"

class RenderInterfaceOgre3D;
class SystemInterfaceTundra;

namespace Rocket
{
    namespace Core
    {
        class Context;
    }
}

class LIBROCKETPLUGIN_API LibRocketPlugin : public IModule
{
    Q_OBJECT

public:
    LibRocketPlugin();
    ~LibRocketPlugin();

    // IModule override
    void Initialize();

    // IModule override
    void Uninitialize();

private:
    RenderInterfaceOgre3D* renderInterface;
    SystemInterfaceTundra* systemInterface;
};
