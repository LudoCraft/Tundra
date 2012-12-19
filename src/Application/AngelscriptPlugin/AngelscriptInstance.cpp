#include "AngelscriptInstance.h"
#include "AngelscriptPlugin.h"
#include "LoggingFunctions.h"
#include "ScriptAsset.h"

#include <angelscript.h>
#include <scriptbuilder/scriptbuilder.h>

/*
AngelscriptInstance::AngelscriptInstance(const QString &fileName, AngelscriptModule *module)
{
    LogInfo("AngelscriptInstance ctor");
}
*/
AngelscriptInstance::AngelscriptInstance(Entity *me_, ScriptAssetPtr scriptRef, AngelscriptModule *module_)
:module(module_), me(me_)
{
    LogInfo("AngelscriptInstance ctor");

//    scriptAsset = scriptRef;
    scriptModuleName = scriptRef->Name().toStdString();
    scriptFilename = scriptRef->DiskSource();

    Load();
}
/*
AngelscriptInstance::AngelscriptInstance(const std::vector<ScriptAssetPtr>& scriptRefs, AngelscriptModule *module)
{
    LogInfo("AngelscriptInstance ctor");
}
*/
AngelscriptInstance::~AngelscriptInstance()
{
    LogInfo("AngelscriptInstance dtor");
}   

void AngelscriptInstance::Load()
{
    LogInfo("AngelscriptInstance::Load");

    Unload();

    CScriptBuilder builder;
    int r = builder.StartNewModule(module->Engine(), scriptModuleName.c_str());
    if (r < 0)
    {
        LogError("AngelscriptInstance failed to start building new script module!");
        return;
    }

    r = builder.AddSectionFromFile(scriptFilename.toStdString().c_str()); ///\todo Look up how to pass unicode path names to Angelscript?
    if (r < 0)
    {
        LogError("Angelscript AddSectionFromFile failed. Please correct the errors in the script and try again.");
        return;
    }
    r = builder.BuildModule();
    if (r < 0)
    {
        LogError("Angelscript BuildModule failed. Please correct the errors in the script and try again.");
    }
}

void AngelscriptInstance::Unload()
{
    LogInfo("AngelscriptInstance::Unload");

    module->Engine()->DiscardModule(scriptModuleName.c_str());
}

void AngelscriptInstance::Run()
{
    LogInfo("AngelscriptInstance::Run");

    asIScriptModule *scriptModule = module->Engine()->GetModule(scriptModuleName.c_str());
    if (!scriptModule)
    {
        LogError("Angelscript Module '" + scriptModuleName + "' not loaded, cannot run script!");
        return;
    }

    asIScriptFunction *function = scriptModule->GetFunctionByDecl("void main(Entity @me)");
    if (function == 0)
    {
        LogError("Angelscript Module '" + scriptModuleName + "' does not contain an entry point function 'void main()', cannot run script!");
        return;
    }

    module->Context()->Prepare(function);
    module->Context()->SetArgObject(0, me);
    int r = module->Context()->Execute();
    if (r == asEXECUTION_EXCEPTION)
    {
        LogError(QString("An exception '") + module->Context()->GetExceptionString() + "' occurred. Please correct the code and try again.");
        return;
    }
}

bool AngelscriptInstance::IsEvaluated() const
{
    return false;
}
