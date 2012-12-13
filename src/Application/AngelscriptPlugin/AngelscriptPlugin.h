#pragma once

#include "IModule.h"
#include "SceneFwd.h"
#include "JavascriptFwd.h"

class AngelscriptModule : public IModule
{
public:
    AngelscriptModule();

    void Initialize();

private slots:
    void OnSceneAdded(const QString &name);
    void OnComponentAdded(Entity *entity, IComponent *component);
    void OnScriptAssetsChanged(const std::vector<ScriptAssetPtr>& newScripts);
};

