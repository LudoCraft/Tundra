#pragma once

#include "IModule.h"
#include "SceneFwd.h"
#include "JavascriptFwd.h"

class asIScriptEngine;
class asIScriptContext;

class AngelscriptModule : public IModule
{
    Q_OBJECT

public:
    AngelscriptModule();

    void Load();
    void Initialize();

    asIScriptEngine *Engine() { return engine; }
    asIScriptContext *Context() { return context; }

private slots:
    void OnSceneAdded(const QString &name);
    void OnComponentAdded(Entity *entity, IComponent *component);
    void OnScriptAssetsChanged(const std::vector<ScriptAssetPtr>& newScripts);

private:
    void CreateScriptEngine();

    asIScriptEngine *engine;
    asIScriptContext *context;
};
