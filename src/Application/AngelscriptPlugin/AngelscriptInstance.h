#pragma once

#include "IScriptInstance.h"
#include "SceneFwd.h"
#include "AssetFwd.h"
#include "JavascriptFwd.h"

class AngelscriptModule;

/// Angelscript script instance used wit EC_Script.
class AngelscriptInstance : public IScriptInstance
{
    Q_OBJECT

public:
    /// Creates script engine for this script instance and loads the script but doesn't run it yet.
    /** @param scriptRef Script asset reference.
        @param module Javascript module. */
//    AngelscriptInstance(const QString &fileName, AngelscriptModule *module);

    /// Creates script engine for this script instance and loads the script but doesn't run it yet.
    /** @param scriptRef Script asset reference.
        @param module Javascript module. */
    AngelscriptInstance(Entity *me, ScriptAssetPtr scriptRef, AngelscriptModule *module);

    /// Creates script engine for this script instance and loads the script but doesn't run it yet.
    /** @param scriptRefs Script asset references.
        @param module Javascript module. */
//    AngelscriptInstance(const std::vector<ScriptAssetPtr>& scriptRefs, AngelscriptModule *module);

    /// Destroys script engine created for this script instance.
    virtual ~AngelscriptInstance();

    /// IScriptInstance override.
    void Load();

    /// IScriptInstance override.
    void Unload();

    /// IScriptInstance override.
    void Run();

    /// Return whether the script has been run.
    virtual bool IsEvaluated() const;

public slots:
    virtual QMap<QString, uint> DumpEngineInformation() { return QMap<QString, uint>(); }

private:
    AngelscriptModule *module;
    //boost::weak_ptr<ScriptAsset> scriptAsset;

    /// Script module names are ASCII in Angelscript.
    std::string scriptModuleName;

    /// Filenames can contain Unicode.
    QString scriptFilename;

    Entity *me;
};
