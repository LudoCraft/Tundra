#pragma once

#include "CoreTypes.h"
#include "IModule.h"
#include "LibRocketPluginApi.h"

class LIBROCKETPLUGIN_API LibRocketPlugin : public IModule
{
    Q_OBJECT

public:
    LibRocketPlugin();
    ~LibRocketPlugin();

    // IModule override
    void Load();

    // IModule override
    void Uninitialize();

    // IModule override
    void Unload();
};
