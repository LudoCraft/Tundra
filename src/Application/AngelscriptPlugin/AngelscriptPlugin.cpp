#include <assert.h>
#include <cassert>
#include <cstring>
#include <string>

#include "Framework.h"
#include "AssetAPI.h"
#include "GenericAssetFactory.h"
#include "AngelscriptPlugin.h"
#include "JavascriptModule.h"
#include "SceneAPI.h"
#include "Scene/Scene.h"
#include "IComponent.h"
#include "EC_Script.h"
#include "AngelscriptInstance.h"
#include "ScriptAsset.h"

#include <angelscript.h>
#include <scriptstdstring/scriptstdstring.h>
#include <scriptbuilder/scriptbuilder.h>
#include <scriptarray/scriptarray.h>
#include <scriptstdstring/scriptstdstring.cpp>
#include <scriptbuilder/scriptbuilder.cpp>
#include <scriptarray/scriptarray.cpp>
#include "LoggingFunctions.h"

#include "EC_Placeable.h"
#include "Math/float2.h"
#include "Math/float3.h"
#include "Math/float4.h"
#include "Math/float3x3.h"
#include "Math/float3x4.h"
#include "Math/float4x4.h"
#include "Math/Quat.h"
#include "Math/TransformOps.h"
#include "Algorithm/Random/LCG.h"
#include "Time/Clock.h"
#include "Geometry/AABB.h"
#include "Geometry/Capsule.h"
#include "Geometry/Circle.h"
#include "Geometry/Frustum.h"
#include "Geometry/Line.h"
#include "Geometry/LineSegment.h"
#include "Geometry/OBB.h"
#include "Geometry/Plane.h"
#include "Geometry/Ray.h"
#include "Geometry/Sphere.h"
#include "Geometry/Triangle.h"
#include "Entity.h"
#include "aswrappedcall_17.h"
#include "angelscript_symbols_cpp.h"

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

void AngelscriptModule::Load()
{
    framework_->Asset()->RegisterAssetTypeFactory(AssetTypeFactoryPtr(new GenericAssetFactory<ScriptAsset>("Script", ".as")));
}

void AngelscriptModule::Initialize()
{
    CreateScriptEngine();

    QObject::connect(GetFramework()->Scene(), SIGNAL(SceneAdded(const QString&)), this, SLOT(OnSceneAdded(const QString&)));
}

void MessageCallback(const asSMessageInfo *msg, void *param)
{
    char str[512];
    sprintf(str, "%s (%d, %d) : %s", msg->section, msg->row, msg->col, msg->message);
    if (msg->type == asMSGTYPE_ERROR)
        LogError(str);
    else if (msg->type == asMSGTYPE_WARNING)
        LogWarning(str);
    else
        LogInfo(str);
}

void print(std::string &msg)
{
    LogInfo(msg.c_str());
}

void AngelscriptModule::CreateScriptEngine()
{
    LogInfo("AngelscriptModule::CreateScriptEngine");
    engine = asCreateScriptEngine(ANGELSCRIPT_VERSION);

    int r = engine->SetMessageCallback(asFUNCTION(MessageCallback), 0, asCALL_CDECL); assert(r >= 0);
    RegisterStdString(engine);
    r = engine->RegisterGlobalFunction("void print(const string &in)", asFUNCTION(print), asCALL_CDECL); assert(r >= 0);

    RegisterScriptArray(engine, true);

    RegisterAngelscriptObjects(engine);

    context = engine->CreateContext();
    assert(context != 0);
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

    IScriptInstance *scriptInstance = sender->ScriptInstance();

    ///\todo Add support for multiple angelscript scripts.
    Q_FOREACH(ScriptAssetPtr script, newScripts)
    {
        if (script->Name().endsWith(".as", Qt::CaseInsensitive))
        {
            if (!scriptInstance)
            {
                scriptInstance = new AngelscriptInstance(sender->ParentEntity(), script, this);
            }
        }
    }

    if (sender->runOnLoad.Get() && sender->ShouldRun())
    {
        bool isApplication = !sender->applicationName.Get().trimmed().isEmpty();
        if (isApplication && framework_->HasCommandLineParameter("--disablerunonload"))
            return;
        scriptInstance->Run();
    }
}
