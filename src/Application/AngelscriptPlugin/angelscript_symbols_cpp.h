#pragma once
#include <angelscript.h>

// If you want to use Angelscript's generic calling convention, #define USE_ANGELSCRIPT_GENERIC_CALL_CONVENTION before including this file.
// If you use the generic calling convention, you MUST #include <autowrapper/aswrappedcall.h> to bring the wrapper code. If your functions contain a large amount of input parameters,
// copy the file cpp/aswrappedcall_17.h to your project and include that file instead.
#if defined(USE_ANGELSCRIPT_GENERIC_CALL_CONVENTION)

#define AS_CALL_CONVENTION asCALL_GENERIC
#define AS_CTOR_CONVENTION asCALL_GENERIC
#define AS_MEMBER_CALL_CONVENTION asCALL_GENERIC
#define AS_FUNCTION WRAP_FN
#define AS_CONSTRUCTOR(ctorFuncName, className, parameters) WRAP_CON(className, parameters)
#define AS_DESTRUCTOR(className, dtorFunc) WRAP_DES(className)
#define AS_METHOD_FUNCTION_PR WRAP_MFN_PR

#else

#define AS_CALL_CONVENTION asCALL_CDECL
#define AS_CTOR_CONVENTION asCALL_CDECL_OBJLAST
#define AS_MEMBER_CALL_CONVENTION asCALL_THISCALL
#define AS_FUNCTION asFUNCTION
#define AS_CONSTRUCTOR(ctorFuncName, className, parameters) asFUNCTION(ctorFuncName)
#define AS_DESTRUCTOR(className, dtorFunc) asFUNCTION(dtorFunc)
#define AS_METHOD_FUNCTION_PR asMETHODPR

#endif

static void Framework_ctor_int_char_ptrptr(int argc,char ** argv, Framework *self)
{
	new(self) Framework(argc,argv);
}

static void Framework_dtor(void *memory)
{
	((Framework*)memory)->~Framework();
}

static void SceneAPI_dtor(void *memory)
{
	((SceneAPI*)memory)->~SceneAPI();
}

static void Scene_dtor(void *memory)
{
	((Scene*)memory)->~Scene();
}

static void Entity_dtor(void *memory)
{
	((Entity*)memory)->~Entity();
}

static void IComponent_dtor(void *memory)
{
	((IComponent*)memory)->~IComponent();
}

static void IAttribute_dtor(void *memory)
{
	((IAttribute*)memory)->~IAttribute();
}

void RegisterAngelscriptObjects(asIScriptEngine *engine)
{
	int r;

	r = engine->RegisterObjectType("Framework", sizeof(Framework), asOBJ_REF | asOBJ_NOCOUNT | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("SceneAPI", sizeof(SceneAPI), asOBJ_REF | asOBJ_NOCOUNT | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("Scene", sizeof(Scene), asOBJ_REF | asOBJ_NOCOUNT | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("Entity", sizeof(Entity), asOBJ_REF | asOBJ_NOCOUNT | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("IComponent", sizeof(IComponent), asOBJ_REF | asOBJ_NOCOUNT | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("IAttribute", sizeof(IAttribute), asOBJ_REF | asOBJ_NOCOUNT | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR); assert(r >= 0);


// /*(char ** is not known to angelscript)*/ 	r = engine->RegisterObjectBehaviour("Framework", asBEHAVE_CONSTRUCT, "void f(int,char **)", AS_CONSTRUCTOR(Framework_ctor_int_char_ptrptr, Framework, (int,char **)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Framework", asBEHAVE_DESTRUCT, "void f()", AS_DESTRUCTOR(Framework, Framework_dtor), AS_CTOR_CONVENTION); assert(r >= 0);	r = engine->RegisterObjectMethod("Framework", "void Go()", AS_METHOD_FUNCTION_PR(Framework, Go, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Framework", "void ProcessOneFrame()", AS_METHOD_FUNCTION_PR(Framework, ProcessOneFrame, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(T * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Framework", "T * GetModule() const", AS_METHOD_FUNCTION_PR(Framework, GetModule, () const, T *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IModule * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Framework", "void RegisterModule(IModule *)", AS_METHOD_FUNCTION_PR(Framework, RegisterModule, (IModule *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(QString is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Framework", "bool RegisterDynamicObject(QString,QObject *)", AS_METHOD_FUNCTION_PR(Framework, RegisterDynamicObject, (QString,QObject *), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Framework", "void CancelExit()", AS_METHOD_FUNCTION_PR(Framework, CancelExit, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Framework", "void ForceExit()", AS_METHOD_FUNCTION_PR(Framework, ForceExit, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Application * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Framework", "Application * App() const", AS_METHOD_FUNCTION_PR(Framework, App, () const, Application *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IRenderer * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Framework", "void RegisterRenderer(IRenderer *)", AS_METHOD_FUNCTION_PR(Framework, RegisterRenderer, (IRenderer *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IRenderer * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Framework", "IRenderer * Renderer() const", AS_METHOD_FUNCTION_PR(Framework, Renderer, () const, IRenderer *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Framework * is not known to angelscript)*/ 	//.classmethod(// /*(Framework * is not known to angelscript)*/ 	//.classmethod(// /*(StaticPluginRegistry * is not known to angelscript)*/ 	//.classmethod(


	r = engine->RegisterObjectBehaviour("SceneAPI", asBEHAVE_DESTRUCT, "void f()", AS_DESTRUCTOR(SceneAPI, SceneAPI_dtor), AS_CTOR_CONVENTION); assert(r >= 0);// /*(boost::shared_ptr< T > is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("SceneAPI", "boost::shared_ptr< T > CreateComponent(Scene *,const QString &in) const", AS_METHOD_FUNCTION_PR(SceneAPI, CreateComponent, (Scene *,const QString &) const, boost::shared_ptr< T >), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(SceneMap & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("SceneAPI", "SceneMap & Scenes()", AS_METHOD_FUNCTION_PR(SceneAPI, Scenes, (), SceneMap &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const SceneMap & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("SceneAPI", "const SceneMap & Scenes() const", AS_METHOD_FUNCTION_PR(SceneAPI, Scenes, () const, const SceneMap &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const QStringList & is not known to angelscript)*/ 	//.classmethod(


	r = engine->RegisterObjectBehaviour("Scene", asBEHAVE_DESTRUCT, "void f()", AS_DESTRUCTOR(Scene, Scene_dtor), AS_CTOR_CONVENTION); assert(r >= 0);// /*(const QString & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "const QString & Name() const", AS_METHOD_FUNCTION_PR(Scene, Name, () const, const QString &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(iterator is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "iterator begin()", AS_METHOD_FUNCTION_PR(Scene, begin, (), iterator), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(iterator is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "iterator end()", AS_METHOD_FUNCTION_PR(Scene, end, (), iterator), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const_iterator is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "const_iterator begin() const", AS_METHOD_FUNCTION_PR(Scene, begin, () const, const_iterator), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const_iterator is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "const_iterator end() const", AS_METHOD_FUNCTION_PR(Scene, end, () const, const_iterator), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const EntityMap & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "const EntityMap & Entities() const", AS_METHOD_FUNCTION_PR(Scene, Entities, () const, const EntityMap &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Scene", "bool opEquals(const Scene &in) const", AS_METHOD_FUNCTION_PR(Scene, operator==, (const Scene &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(operator != is implemented automatically by exposing operator == as opEquals)*/ 	r = engine->RegisterObjectMethod("Scene", "bool operator!=(const Scene &in) const", AS_METHOD_FUNCTION_PR(Scene, operator!=, (const Scene &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(operators <, <=, > and >= are implemented by exposing operator opCmp)*/ 	r = engine->RegisterObjectMethod("Scene", "bool operator<(const Scene &in) const", AS_METHOD_FUNCTION_PR(Scene, operator<, (const Scene &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(boost::shared_ptr< T > is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "boost::shared_ptr< T > GetWorld() const", AS_METHOD_FUNCTION_PR(Scene, GetWorld, () const, boost::shared_ptr< T >), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(entity_id_t is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "void ChangeEntityId(entity_id_t,entity_id_t)", AS_METHOD_FUNCTION_PR(Scene, ChangeEntityId, (entity_id_t,entity_id_t), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IAttribute * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "bool StartAttributeInterpolation(IAttribute *,IAttribute *,float)", AS_METHOD_FUNCTION_PR(Scene, StartAttributeInterpolation, (IAttribute *,IAttribute *,float), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IAttribute * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "bool EndAttributeInterpolation(IAttribute *)", AS_METHOD_FUNCTION_PR(Scene, EndAttributeInterpolation, (IAttribute *), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Scene", "void EndAllAttributeInterpolations()", AS_METHOD_FUNCTION_PR(Scene, EndAllAttributeInterpolations, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Scene", "void UpdateAttributeInterpolations(float)", AS_METHOD_FUNCTION_PR(Scene, UpdateAttributeInterpolations, (float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Scene", "bool IsInterpolating() const", AS_METHOD_FUNCTION_PR(Scene, IsInterpolating, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Framework * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "Framework * GetFramework() const", AS_METHOD_FUNCTION_PR(Scene, GetFramework, () const, Framework *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(SceneDesc is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "SceneDesc CreateSceneDescFromXml(const QString &in) const", AS_METHOD_FUNCTION_PR(Scene, CreateSceneDescFromXml, (const QString &) const, SceneDesc), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("Scene", "SceneDesc CreateSceneDescFromXml(QByteArray &,SceneDesc &) const", AS_METHOD_FUNCTION_PR(Scene, CreateSceneDescFromXml, (QByteArray &,SceneDesc &) const, SceneDesc), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(SceneDesc is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "SceneDesc CreateSceneDescFromBinary(const QString &in) const", AS_METHOD_FUNCTION_PR(Scene, CreateSceneDescFromBinary, (const QString &) const, SceneDesc), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("Scene", "SceneDesc CreateSceneDescFromBinary(QByteArray &,SceneDesc &) const", AS_METHOD_FUNCTION_PR(Scene, CreateSceneDescFromBinary, (QByteArray &,SceneDesc &) const, SceneDesc), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("Scene", "void SearchScriptAssetDependencies(const QString &in,SceneDesc &) const", AS_METHOD_FUNCTION_PR(Scene, SearchScriptAssetDependencies, (const QString &,SceneDesc &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(QList< Entity * > is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "QList< Entity * > CreateContentFromSceneDesc(const SceneDesc &in,bool,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(Scene, CreateContentFromSceneDesc, (const SceneDesc &,bool,AttributeChange::Type), QList< Entity * >), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IComponent * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "void EmitAttributeChanged(IComponent *,IAttribute *,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(Scene, EmitAttributeChanged, (IComponent *,IAttribute *,AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IComponent * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "void EmitAttributeAdded(IComponent *,IAttribute *,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(Scene, EmitAttributeAdded, (IComponent *,IAttribute *,AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IComponent * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "void EmitAttributeRemoved(IComponent *,IAttribute *,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(Scene, EmitAttributeRemoved, (IComponent *,IAttribute *,AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Entity * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "void EmitComponentAdded(Entity *,IComponent *,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(Scene, EmitComponentAdded, (Entity *,IComponent *,AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Entity * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "void EmitComponentRemoved(Entity *,IComponent *,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(Scene, EmitComponentRemoved, (Entity *,IComponent *,AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Entity * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "void EmitEntityRemoved(Entity *,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(Scene, EmitEntityRemoved, (Entity *,AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Entity * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "void EmitActionTriggered(Entity *,const QString &in,const QStringList &in,EntityAction::ExecTypeField)", AS_METHOD_FUNCTION_PR(Scene, EmitActionTriggered, (Entity *,const QString &,const QStringList &,EntityAction::ExecTypeField), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Entity * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "void EmitEntityAcked(Entity *,entity_id_t)", AS_METHOD_FUNCTION_PR(Scene, EmitEntityAcked, (Entity *,entity_id_t), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IComponent * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Scene", "void EmitComponentAcked(IComponent *,component_id_t)", AS_METHOD_FUNCTION_PR(Scene, EmitComponentAcked, (IComponent *,component_id_t), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);



	r = engine->RegisterObjectBehaviour("Entity", asBEHAVE_DESTRUCT, "void f()", AS_DESTRUCTOR(Entity, Entity_dtor), AS_CTOR_CONVENTION); assert(r >= 0);// /*(boost::shared_ptr< T > is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Entity", "boost::shared_ptr< T > GetComponent() const", AS_METHOD_FUNCTION_PR(Entity, GetComponent, () const, boost::shared_ptr< T >), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(std::vector< boost::shared_ptr< T > > is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Entity", "std::vector< boost::shared_ptr< T > > GetComponents() const", AS_METHOD_FUNCTION_PR(Entity, GetComponents, () const, std::vector< boost::shared_ptr< T > >), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(boost::shared_ptr< T > is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Entity", "boost::shared_ptr< T > GetComponent(const QString &in) const", AS_METHOD_FUNCTION_PR(Entity, GetComponent, (const QString &) const, boost::shared_ptr< T >), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Attribute < T > * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Entity", "Attribute < T > * GetAttribute(const QString &in) const", AS_METHOD_FUNCTION_PR(Entity, GetAttribute, (const QString &) const, Attribute < T > *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(std::vector< Attribute < T > > is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Entity", "std::vector< Attribute < T > > GetAttributes(const QString &in) const", AS_METHOD_FUNCTION_PR(Entity, GetAttributes, (const QString &) const, std::vector< Attribute < T > >), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("Entity", "void SerializeToBinary(kNet::DataSerializer &) const", AS_METHOD_FUNCTION_PR(Entity, SerializeToBinary, (kNet::DataSerializer &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IComponent * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Entity", "void EmitEnterView(IComponent *)", AS_METHOD_FUNCTION_PR(Entity, EmitEnterView, (IComponent *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IComponent * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Entity", "void EmitLeaveView(IComponent *)", AS_METHOD_FUNCTION_PR(Entity, EmitLeaveView, (IComponent *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Entity", "bool opEquals(const Entity &in) const", AS_METHOD_FUNCTION_PR(Entity, operator==, (const Entity &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(operator != is implemented automatically by exposing operator == as opEquals)*/ 	r = engine->RegisterObjectMethod("Entity", "bool operator!=(const Entity &in) const", AS_METHOD_FUNCTION_PR(Entity, operator!=, (const Entity &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(operators <, <=, > and >= are implemented by exposing operator opCmp)*/ 	r = engine->RegisterObjectMethod("Entity", "bool operator<(const Entity &in) const", AS_METHOD_FUNCTION_PR(Entity, operator<, (const Entity &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(component_id_t is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Entity", "void ChangeComponentId(component_id_t,component_id_t)", AS_METHOD_FUNCTION_PR(Entity, ChangeComponentId, (component_id_t,component_id_t), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(ComponentPtr is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Entity", "ComponentPtr CreateComponentWithId(component_id_t,u32,const QString &in,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(Entity, CreateComponentWithId, (component_id_t,u32,const QString &,AttributeChange::Type), ComponentPtr), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const ComponentMap & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Entity", "const ComponentMap & Components() const", AS_METHOD_FUNCTION_PR(Entity, Components, () const, const ComponentMap &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IAttribute * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Entity", "IAttribute * GetAttribute(const QString &in) const", AS_METHOD_FUNCTION_PR(Entity, GetAttribute, (const QString &) const, IAttribute *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(AttributeVector is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Entity", "AttributeVector GetAttributes(const QString &in) const", AS_METHOD_FUNCTION_PR(Entity, GetAttributes, (const QString &) const, AttributeVector), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const ActionMap & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Entity", "const ActionMap & Actions() const", AS_METHOD_FUNCTION_PR(Entity, Actions, () const, const ActionMap &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);



// /*(Scene * is not known to angelscript)*/ 		r = engine->RegisterObjectBehaviour("IComponent", asBEHAVE_DESTRUCT, "void f()", AS_DESTRUCTOR(IComponent, IComponent_dtor), AS_CTOR_CONVENTION); assert(r >= 0);// /*(const QString & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IComponent", "const QString & TypeName() const", AS_METHOD_FUNCTION_PR(IComponent, TypeName, () const, const QString &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(u32 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IComponent", "u32 TypeId() const", AS_METHOD_FUNCTION_PR(IComponent, TypeId, () const, u32), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const QString & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IComponent", "const QString & Name() const", AS_METHOD_FUNCTION_PR(IComponent, Name, () const, const QString &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(QString is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IComponent", "void SetName(const QString &in)", AS_METHOD_FUNCTION_PR(IComponent, SetName, (const QString &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Entity * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IComponent", "void SetParentEntity(Entity *)", AS_METHOD_FUNCTION_PR(IComponent, SetParentEntity, (Entity *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const AttributeVector & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IComponent", "const AttributeVector & Attributes() const", AS_METHOD_FUNCTION_PR(IComponent, Attributes, () const, const AttributeVector &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(AttributeVector is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IComponent", "AttributeVector NonEmptyAttributes() const", AS_METHOD_FUNCTION_PR(IComponent, NonEmptyAttributes, () const, AttributeVector), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Attribute < T > * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IComponent", "Attribute < T > * GetAttribute(const QString &in) const", AS_METHOD_FUNCTION_PR(IComponent, GetAttribute, (const QString &) const, Attribute < T > *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("IComponent", "void SerializeTo(QDomDocument &,QDomElement &,bool) const", AS_METHOD_FUNCTION_PR(IComponent, SerializeTo, (QDomDocument &,QDomElement &,bool) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("IComponent", "void DeserializeFrom(QDomElement &,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(IComponent, DeserializeFrom, (QDomElement &,AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("IComponent", "void SerializeToBinary(kNet::DataSerializer &) const", AS_METHOD_FUNCTION_PR(IComponent, SerializeToBinary, (kNet::DataSerializer &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("IComponent", "void DeserializeFromBinary(kNet::DataDeserializer &,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(IComponent, DeserializeFromBinary, (kNet::DataDeserializer &,AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IAttribute * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IComponent", "IAttribute * GetAttribute(const QString &in) const", AS_METHOD_FUNCTION_PR(IComponent, GetAttribute, (const QString &) const, IAttribute *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IAttribute * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IComponent", "IAttribute * CreateAttribute(u8,u32,const QString &in,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(IComponent, CreateAttribute, (u8,u32,const QString &,AttributeChange::Type), IAttribute *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(u8 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IComponent", "void RemoveAttribute(u8,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(IComponent, RemoveAttribute, (u8,AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("IComponent", "void SetReplicated(bool)", AS_METHOD_FUNCTION_PR(IComponent, SetReplicated, (bool), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);



// /*(IComponent * is not known to angelscript)*/ 		r = engine->RegisterObjectBehaviour("IAttribute", asBEHAVE_DESTRUCT, "void f()", AS_DESTRUCTOR(IAttribute, IAttribute_dtor), AS_CTOR_CONVENTION); assert(r >= 0);// /*(IComponent * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IAttribute", "IComponent * Owner() const", AS_METHOD_FUNCTION_PR(IAttribute, Owner, () const, IComponent *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const QString & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IAttribute", "const QString & Name() const", AS_METHOD_FUNCTION_PR(IAttribute, Name, () const, const QString &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("IAttribute", "string ToString() const", AS_METHOD_FUNCTION_PR(IAttribute, ToString, () const, std::string), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(AttributeChange::Type is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IAttribute", "void FromString(const string &in,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(IAttribute, FromString, (const std::string &,AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const QString & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IAttribute", "const QString & TypeName() const", AS_METHOD_FUNCTION_PR(IAttribute, TypeName, () const, const QString &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(u32 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IAttribute", "u32 TypeId() const", AS_METHOD_FUNCTION_PR(IAttribute, TypeId, () const, u32), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("IAttribute", "void ToBinary(kNet::DataSerializer &) const", AS_METHOD_FUNCTION_PR(IAttribute, ToBinary, (kNet::DataSerializer &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("IAttribute", "void FromBinary(kNet::DataDeserializer &,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(IAttribute, FromBinary, (kNet::DataDeserializer &,AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(QVariant is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IAttribute", "QVariant ToQVariant() const", AS_METHOD_FUNCTION_PR(IAttribute, ToQVariant, () const, QVariant), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(QVariant is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IAttribute", "void FromQVariant(const QVariant &in,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(IAttribute, FromQVariant, (const QVariant &,AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(QScriptValue is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IAttribute", "void FromScriptValue(const QScriptValue &in,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(IAttribute, FromScriptValue, (const QScriptValue &,AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(AttributeMetadata * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IAttribute", "void SetMetadata(AttributeMetadata *)", AS_METHOD_FUNCTION_PR(IAttribute, SetMetadata, (AttributeMetadata *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(AttributeMetadata * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IAttribute", "AttributeMetadata * Metadata() const", AS_METHOD_FUNCTION_PR(IAttribute, Metadata, () const, AttributeMetadata *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("IAttribute", "bool IsDynamic() const", AS_METHOD_FUNCTION_PR(IAttribute, IsDynamic, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(u8 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IAttribute", "u8 Index() const", AS_METHOD_FUNCTION_PR(IAttribute, Index, () const, u8), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(AttributeChange::Type is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IAttribute", "void Changed(AttributeChange::Type)", AS_METHOD_FUNCTION_PR(IAttribute, Changed, (AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IAttribute * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IAttribute", "IAttribute * Clone() const", AS_METHOD_FUNCTION_PR(IAttribute, Clone, () const, IAttribute *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IAttribute * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IAttribute", "void CopyValue(IAttribute *,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(IAttribute, CopyValue, (IAttribute *,AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(IAttribute * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("IAttribute", "void Interpolate(IAttribute *,IAttribute *,float,AttributeChange::Type)", AS_METHOD_FUNCTION_PR(IAttribute, Interpolate, (IAttribute *,IAttribute *,float,AttributeChange::Type), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("IAttribute", "bool ValueChanged() const", AS_METHOD_FUNCTION_PR(IAttribute, ValueChanged, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("IAttribute", "void ClearChangedFlag()", AS_METHOD_FUNCTION_PR(IAttribute, ClearChangedFlag, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);



}
