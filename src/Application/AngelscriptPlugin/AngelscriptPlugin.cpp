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

AngelscriptModule::AngelscriptModule()
:IModule("Angelscript")
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
    QObject::connect(GetFramework()->Scene(), SIGNAL(SceneAdded(const QString&)), this, SLOT(OnSceneAdded(const QString&)));
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
    // Reload the script.
}
