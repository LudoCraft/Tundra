#include "AngelscriptInstance.h"

AngelscriptInstance::AngelscriptInstance(const QString &fileName, JavascriptModule *module)
{
}

AngelscriptInstance::AngelscriptInstance(ScriptAssetPtr scriptRef, JavascriptModule *module)
{
}

AngelscriptInstance::AngelscriptInstance(const std::vector<ScriptAssetPtr>& scriptRefs, JavascriptModule *module)
{
}

AngelscriptInstance::~AngelscriptInstance()
{
}

void AngelscriptInstance::Load()
{
}

void AngelscriptInstance::Unload()
{
}

void AngelscriptInstance::Run()
{
}

bool AngelscriptInstance::IsEvaluated() const
{
    return false;
}
