#include <assert.h>
#include <cassert>
#include <cstring>
#include <string>

#include "Framework.h"
#include "AngelscriptPlugin.h"
#include "SceneAPI.h"
#include "Scene/Scene.h"
#include "IComponent.h"
#include "EC_Script.h"
#include "AngelscriptInstance.h"

#include <angelscript.h>
#include <scriptstdstring/scriptstdstring.h>
#include <scriptbuilder/scriptbuilder.h>
#include <scriptarray/scriptarray.h>
#include <scriptstdstring/scriptstdstring.cpp>
#include <scriptbuilder/scriptbuilder.cpp>
#include <scriptarray/scriptarray.cpp>
#include "LoggingFunctions.h"

AngelscriptModule::AngelscriptModule()
:IModule("Angelscript"), engine(0), context(0)
{
}

extern "C"
{
#ifndef ANDROID
DLLEXPORT void TundraPluginMain(Framework *fw)
#else
DEFINE_STATIC_PLUGIN_MAIN(AngelscriptPlugin)
#endif
{
    Framework::SetInstance(fw); // Inside this DLL, remember the pointer to the global framework object.
    IModule *module = new AngelscriptModule();
    fw->RegisterModule(module);
}
}

void AngelscriptModule::Initialize()
{
    CreateScriptEngine();

    QObject::connect(GetFramework()->Scene(), SIGNAL(SceneAdded(const QString&)), this, SLOT(OnSceneAdded(const QString&)));
}

void AngelscriptModule::CreateScriptEngine()
{
    LogInfo("AngelscriptModule::CreateScriptEngine");
    engine = asCreateScriptEngine(ANGELSCRIPT_VERSION);
}

void AngelscriptModule::OnSceneAdded(const QString &name)
{
    Scene *scene = GetFramework()->Scene()->GetScene(name).get();
    assert(scene);
    if (!scene)
        return;

    QObject::connect(scene, SIGNAL(ComponentAdded(Entity*, IComponent*, AttributeChange::Type)), this, SLOT(OnComponentAdded(Entity*, IComponent*)));
}

void AngelscriptModule::OnComponentAdded(Entity *entity, IComponent *component)
{
    if (component->TypeName() == EC_Script::TypeNameStatic())
        QObject::connect(component, SIGNAL(ScriptAssetsChanged(const std::vector<ScriptAssetPtr>&)), this, SLOT(OnScriptAssetsChanged(const std::vector<ScriptAssetPtr>&)), Qt::UniqueConnection);
}

void AngelscriptModule::OnScriptAssetsChanged(const std::vector<ScriptAssetPtr>& newScripts)
{
    EC_Script *sender = dynamic_cast<EC_Script*>(this->sender());
    assert(sender && "JavascriptModule::ScriptAssetsChanged needs to be invoked from EC_Script!");
    if (!sender)
        return;
    if (newScripts.empty())
    {
        LogError("Script asset vector was empty");
        return;
    }

    Q_FOREACH(ScriptAssetPtr script, newScripts)
    {
        if (script->Name().endsWith(".as", Qt::CaseInsensitive))
        {
            ScriptInstance *scriptInstance = sender->ScriptInstance();
            if (!scriptInstance)
            {
                scriptInstance = new AngelscriptInstance(script->Name(), framework->GetModule<JavascriptModule>());
            }
        }
    }
}
