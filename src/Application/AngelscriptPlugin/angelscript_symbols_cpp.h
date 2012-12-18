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

static Framework *Framework_Factory_int_char_ptrptr(int argc,char ** argv, Framework *self)
{
	return new Framework(argc,argv);
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

static void float2_ctor_(float2 *self)
{
	new(self) float2();
}

static void float2_ctor_const_float2_ref(const float2 & rhs, float2 *self)
{
	new(self) float2(rhs);
}

static void float2_ctor_float_float(float x,float y, float2 *self)
{
	new(self) float2(x,y);
}

static void float2_ctor_float(float scalar, float2 *self)
{
	new(self) float2(scalar);
}

static void float2_ctor_const_float_ptr(const float * data, float2 *self)
{
	new(self) float2(data);
}

static void float3_ctor_(float3 *self)
{
	new(self) float3();
}

static void float3_ctor_const_float3_ref(const float3 & rhs, float3 *self)
{
	new(self) float3(rhs);
}

static void float3_ctor_float_float_float(float x,float y,float z, float3 *self)
{
	new(self) float3(x,y,z);
}

static void float3_ctor_float(float scalar, float3 *self)
{
	new(self) float3(scalar);
}

static void float3_ctor_const_float2_ref_float(const float2 & xy,float z, float3 *self)
{
	new(self) float3(xy,z);
}

static void float3_ctor_const_float_ptr(const float * data, float3 *self)
{
	new(self) float3(data);
}

static void float4_ctor_(float4 *self)
{
	new(self) float4();
}

static void float4_ctor_const_float4_ref(const float4 & rhs, float4 *self)
{
	new(self) float4(rhs);
}

static void float4_ctor_float_float_float_float(float x,float y,float z,float w, float4 *self)
{
	new(self) float4(x,y,z,w);
}

static void float4_ctor_const_float3_ref_float(const float3 & xyz,float w, float4 *self)
{
	new(self) float4(xyz,w);
}

static void float4_ctor_const_float2_ref_float_float(const float2 & xy,float z,float w, float4 *self)
{
	new(self) float4(xy,z,w);
}

static void float4_ctor_const_float_ptr(const float * data, float4 *self)
{
	new(self) float4(data);
}

static void float3x3_ctor_(float3x3 *self)
{
	new(self) float3x3();
}

static void float3x3_ctor_const_float3x3_ref(const float3x3 & rhs, float3x3 *self)
{
	new(self) float3x3(rhs);
}

static void float3x3_ctor_float_float_float_float_float_float_float_float_float(float _00,float _01,float _02,float _10,float _11,float _12,float _20,float _21,float _22, float3x3 *self)
{
	new(self) float3x3(_00,_01,_02,_10,_11,_12,_20,_21,_22);
}

static void float3x3_ctor_const_float3_ref_const_float3_ref_const_float3_ref(const float3 & col0,const float3 & col1,const float3 & col2, float3x3 *self)
{
	new(self) float3x3(col0,col1,col2);
}

static void float3x3_ctor_const_Quat_ref(const Quat & orientation, float3x3 *self)
{
	new(self) float3x3(orientation);
}

static void float3x4_ctor_(float3x4 *self)
{
	new(self) float3x4();
}

static void float3x4_ctor_const_float3x4_ref(const float3x4 & rhs, float3x4 *self)
{
	new(self) float3x4(rhs);
}

static void float3x4_ctor_float_float_float_float_float_float_float_float_float_float_float_float(float _00,float _01,float _02,float _03,float _10,float _11,float _12,float _13,float _20,float _21,float _22,float _23, float3x4 *self)
{
	new(self) float3x4(_00,_01,_02,_03,_10,_11,_12,_13,_20,_21,_22,_23);
}

static void float3x4_ctor_const_float3x3_ref(const float3x3 & other, float3x4 *self)
{
	new(self) float3x4(other);
}

static void float3x4_ctor_const_float3x3_ref_const_float3_ref(const float3x3 & other,const float3 & translate, float3x4 *self)
{
	new(self) float3x4(other,translate);
}

static void float3x4_ctor_const_float3_ref_const_float3_ref_const_float3_ref_const_float3_ref(const float3 & col0,const float3 & col1,const float3 & col2,const float3 & col3, float3x4 *self)
{
	new(self) float3x4(col0,col1,col2,col3);
}

static void float3x4_ctor_const_Quat_ref(const Quat & orientation, float3x4 *self)
{
	new(self) float3x4(orientation);
}

static void float3x4_ctor_const_Quat_ref_const_float3_ref(const Quat & orientation,const float3 & translation, float3x4 *self)
{
	new(self) float3x4(orientation,translation);
}

static void float4x4_ctor_(float4x4 *self)
{
	new(self) float4x4();
}

static void float4x4_ctor_const_float4x4_ref(const float4x4 & rhs, float4x4 *self)
{
	new(self) float4x4(rhs);
}

static void float4x4_ctor_float_float_float_float_float_float_float_float_float_float_float_float_float_float_float_float(float _00,float _01,float _02,float _03,float _10,float _11,float _12,float _13,float _20,float _21,float _22,float _23,float _30,float _31,float _32,float _33, float4x4 *self)
{
	new(self) float4x4(_00,_01,_02,_03,_10,_11,_12,_13,_20,_21,_22,_23,_30,_31,_32,_33);
}

static void float4x4_ctor_const_float3x3_ref(const float3x3 & other, float4x4 *self)
{
	new(self) float4x4(other);
}

static void float4x4_ctor_const_float3x4_ref(const float3x4 & other, float4x4 *self)
{
	new(self) float4x4(other);
}

static void float4x4_ctor_const_float4_ref_const_float4_ref_const_float4_ref_const_float4_ref(const float4 & col0,const float4 & col1,const float4 & col2,const float4 & col3, float4x4 *self)
{
	new(self) float4x4(col0,col1,col2,col3);
}

static void float4x4_ctor_const_Quat_ref(const Quat & orientation, float4x4 *self)
{
	new(self) float4x4(orientation);
}

static void float4x4_ctor_const_Quat_ref_const_float3_ref(const Quat & orientation,const float3 & translation, float4x4 *self)
{
	new(self) float4x4(orientation,translation);
}

static void Quat_ctor_(Quat *self)
{
	new(self) Quat();
}

static void Quat_ctor_const_Quat_ref(const Quat & rhs, Quat *self)
{
	new(self) Quat(rhs);
}

static void Quat_ctor_const_float_ptr(const float * data, Quat *self)
{
	new(self) Quat(data);
}

static void Quat_ctor_const_float3x3_ref(const float3x3 & rotationMatrix, Quat *self)
{
	new(self) Quat(rotationMatrix);
}

static void Quat_ctor_const_float3x4_ref(const float3x4 & rotationMatrix, Quat *self)
{
	new(self) Quat(rotationMatrix);
}

static void Quat_ctor_const_float4x4_ref(const float4x4 & rotationMatrix, Quat *self)
{
	new(self) Quat(rotationMatrix);
}

static void Quat_ctor_float_float_float_float(float x,float y,float z,float w, Quat *self)
{
	new(self) Quat(x,y,z,w);
}

static void Quat_ctor_const_float3_ref_float(const float3 & rotationAxis,float rotationAngleRadians, Quat *self)
{
	new(self) Quat(rotationAxis,rotationAngleRadians);
}

static void TranslateOp_ctor_(TranslateOp *self)
{
	new(self) TranslateOp();
}

static void TranslateOp_ctor_const_float3_ref(const float3 & offset, TranslateOp *self)
{
	new(self) TranslateOp(offset);
}

static void TranslateOp_ctor_float_float_float(float x,float y,float z, TranslateOp *self)
{
	new(self) TranslateOp(x,y,z);
}

static void ScaleOp_ctor_(ScaleOp *self)
{
	new(self) ScaleOp();
}

static void ScaleOp_ctor_const_float3_ref(const float3 & scale, ScaleOp *self)
{
	new(self) ScaleOp(scale);
}

static void ScaleOp_ctor_float_float_float(float sx,float sy,float sz, ScaleOp *self)
{
	new(self) ScaleOp(sx,sy,sz);
}

static void AABB_ctor_(AABB *self)
{
	new(self) AABB();
}

static void AABB_ctor_const_float3_ref_const_float3_ref(const float3 & minPoint,const float3 & maxPoint, AABB *self)
{
	new(self) AABB(minPoint,maxPoint);
}

static void AABB_ctor_const_OBB_ref(const OBB & obb, AABB *self)
{
	new(self) AABB(obb);
}

static void AABB_ctor_const_Sphere_ref(const Sphere & s, AABB *self)
{
	new(self) AABB(s);
}

static void Capsule_ctor_(Capsule *self)
{
	new(self) Capsule();
}

static void Capsule_ctor_const_LineSegment_ref_float(const LineSegment & endPoints,float radius, Capsule *self)
{
	new(self) Capsule(endPoints,radius);
}

static void Capsule_ctor_const_float3_ref_const_float3_ref_float(const float3 & bottomPoint,const float3 & topPoint,float radius, Capsule *self)
{
	new(self) Capsule(bottomPoint,topPoint,radius);
}

static void Circle_ctor_(Circle *self)
{
	new(self) Circle();
}

static void Circle_ctor_const_float3_ref_const_float3_ref_float(const float3 & center,const float3 & normal,float radius, Circle *self)
{
	new(self) Circle(center,normal,radius);
}

static void Frustum_ctor_(Frustum *self)
{
	new(self) Frustum();
}

static void Line_ctor_(Line *self)
{
	new(self) Line();
}

static void Line_ctor_const_float3_ref_const_float3_ref(const float3 & pos,const float3 & dir, Line *self)
{
	new(self) Line(pos,dir);
}

static void Line_ctor_const_Ray_ref(const Ray & ray, Line *self)
{
	new(self) Line(ray);
}

static void Line_ctor_const_LineSegment_ref(const LineSegment & lineSegment, Line *self)
{
	new(self) Line(lineSegment);
}

static void LineSegment_ctor_(LineSegment *self)
{
	new(self) LineSegment();
}

static void LineSegment_ctor_const_float3_ref_const_float3_ref(const float3 & a,const float3 & b, LineSegment *self)
{
	new(self) LineSegment(a,b);
}

static void LineSegment_ctor_const_Ray_ref_float(const Ray & ray,float d, LineSegment *self)
{
	new(self) LineSegment(ray,d);
}

static void LineSegment_ctor_const_Line_ref_float(const Line & line,float d, LineSegment *self)
{
	new(self) LineSegment(line,d);
}

static void OBB_ctor_(OBB *self)
{
	new(self) OBB();
}

static void OBB_ctor_const_AABB_ref(const AABB & aabb, OBB *self)
{
	new(self) OBB(aabb);
}

static void Plane_ctor_(Plane *self)
{
	new(self) Plane();
}

static void Plane_ctor_const_float3_ref_float(const float3 & normal,float d, Plane *self)
{
	new(self) Plane(normal,d);
}

static void Plane_ctor_const_float3_ref_const_float3_ref_const_float3_ref(const float3 & v1,const float3 & v2,const float3 & v3, Plane *self)
{
	new(self) Plane(v1,v2,v3);
}

static void Plane_ctor_const_float3_ref_const_float3_ref(const float3 & point,const float3 & normal, Plane *self)
{
	new(self) Plane(point,normal);
}

static void Plane_ctor_const_Ray_ref_const_float3_ref(const Ray & line,const float3 & normal, Plane *self)
{
	new(self) Plane(line,normal);
}

static void Plane_ctor_const_Line_ref_const_float3_ref(const Line & line,const float3 & normal, Plane *self)
{
	new(self) Plane(line,normal);
}

static void Plane_ctor_const_LineSegment_ref_const_float3_ref(const LineSegment & line,const float3 & normal, Plane *self)
{
	new(self) Plane(line,normal);
}

static void Ray_ctor_(Ray *self)
{
	new(self) Ray();
}

static void Ray_ctor_const_float3_ref_const_float3_ref(const float3 & pos,const float3 & dir, Ray *self)
{
	new(self) Ray(pos,dir);
}

static void Ray_ctor_const_Line_ref(const Line & line, Ray *self)
{
	new(self) Ray(line);
}

static void Ray_ctor_const_LineSegment_ref(const LineSegment & lineSegment, Ray *self)
{
	new(self) Ray(lineSegment);
}

static void Sphere_ctor_(Sphere *self)
{
	new(self) Sphere();
}

static void Sphere_ctor_const_float3_ref_float(const float3 & center,float radius, Sphere *self)
{
	new(self) Sphere(center,radius);
}

static void Sphere_ctor_const_float3_ref_const_float3_ref(const float3 & pointA,const float3 & pointB, Sphere *self)
{
	new(self) Sphere(pointA,pointB);
}

static void Sphere_ctor_const_float3_ref_const_float3_ref_const_float3_ref(const float3 & pointA,const float3 & pointB,const float3 & pointC, Sphere *self)
{
	new(self) Sphere(pointA,pointB,pointC);
}

static void Sphere_ctor_const_float3_ref_const_float3_ref_const_float3_ref_const_float3_ref(const float3 & pointA,const float3 & pointB,const float3 & pointC,const float3 & pointD, Sphere *self)
{
	new(self) Sphere(pointA,pointB,pointC,pointD);
}

static void Triangle_ctor_(Triangle *self)
{
	new(self) Triangle();
}

static void Triangle_ctor_const_float3_ref_const_float3_ref_const_float3_ref(const float3 & a,const float3 & b,const float3 & c, Triangle *self)
{
	new(self) Triangle(a,b,c);
}

static void Clock_ctor_(Clock *self)
{
	new(self) Clock();
}

static void LCG_ctor_(LCG *self)
{
	new(self) LCG();
}

static void LCG_ctor_u32_u32_u32_u32(u32 seed,u32 multiplier,u32 increment,u32 modulus, LCG *self)
{
	new(self) LCG(seed,multiplier,increment,modulus);
}

void RegisterAngelscriptObjects(asIScriptEngine *engine)
{
	int r;

	r = engine->RegisterObjectType("Framework", sizeof(Framework), asOBJ_REF | asOBJ_NOCOUNT | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR | asOBJ_APP_CLASS_ASSIGNMENT); assert(r >= 0);
	r = engine->RegisterObjectType("SceneAPI", sizeof(SceneAPI), asOBJ_REF | asOBJ_NOCOUNT | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("Scene", sizeof(Scene), asOBJ_REF | asOBJ_NOCOUNT | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("Entity", sizeof(Entity), asOBJ_REF | asOBJ_NOCOUNT | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("IComponent", sizeof(IComponent), asOBJ_REF | asOBJ_NOCOUNT | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("IAttribute", sizeof(IAttribute), asOBJ_REF | asOBJ_NOCOUNT | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("float2", sizeof(float2), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("float3", sizeof(float3), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("float4", sizeof(float4), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("float3x3", sizeof(float3x3), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR | asOBJ_APP_CLASS_ASSIGNMENT); assert(r >= 0);
	r = engine->RegisterObjectType("float3x4", sizeof(float3x4), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR | asOBJ_APP_CLASS_ASSIGNMENT); assert(r >= 0);
	r = engine->RegisterObjectType("float4x4", sizeof(float4x4), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR | asOBJ_APP_CLASS_ASSIGNMENT); assert(r >= 0);
	r = engine->RegisterObjectType("Quat", sizeof(Quat), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR | asOBJ_APP_CLASS_COPY_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("TranslateOp", sizeof(TranslateOp), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("ScaleOp", sizeof(ScaleOp), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("AABB", sizeof(AABB), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("Capsule", sizeof(Capsule), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("Circle", sizeof(Circle), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("Frustum", sizeof(Frustum), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("Line", sizeof(Line), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("LineSegment", sizeof(LineSegment), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("OBB", sizeof(OBB), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("Plane", sizeof(Plane), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("Ray", sizeof(Ray), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("Sphere", sizeof(Sphere), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("Triangle", sizeof(Triangle), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("Clock", sizeof(Clock), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR); assert(r >= 0);
	r = engine->RegisterObjectType("LCG", sizeof(LCG), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CONSTRUCTOR); assert(r >= 0);


// /*(char ** is not known to angelscript)*/ 	r = engine->RegisterObjectBehaviour("Framework", asBEHAVE_FACTORY, "Framework@ f(int,char **)", AS_FUNCTION(Framework_ctor_int_char_ptrptr, Framework, (int,char **)), AS_CALL_CONVENTION); assert(r >= 0);	r = engine->RegisterObjectBehaviour("Framework", asBEHAVE_DESTRUCT, "void f()", AS_DESTRUCTOR(Framework, Framework_dtor), AS_CTOR_CONVENTION); assert(r >= 0);	r = engine->RegisterObjectMethod("Framework", "void Go()", AS_METHOD_FUNCTION_PR(Framework, Go, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
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



	r = engine->RegisterObjectProperty("float2", "float x", asOFFSET(float2, x)); assert(r >= 0);
	r = engine->RegisterObjectProperty("float2", "float y", asOFFSET(float2, y)); assert(r >= 0);
// /* const float2 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float2", "const float2 zero", asOFFSET(float2, zero)); assert(r >= 0);
// /* const float2 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float2", "const float2 one", asOFFSET(float2, one)); assert(r >= 0);
// /* const float2 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float2", "const float2 unitX", asOFFSET(float2, unitX)); assert(r >= 0);
// /* const float2 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float2", "const float2 unitY", asOFFSET(float2, unitY)); assert(r >= 0);
// /* const float2 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float2", "const float2 nan", asOFFSET(float2, nan)); assert(r >= 0);
// /* const float2 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float2", "const float2 inf", asOFFSET(float2, inf)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float2", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(float2_ctor_, float2, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float2", asBEHAVE_CONSTRUCT, "void f(const float2 &in)", AS_CONSTRUCTOR(float2_ctor_const_float2_ref, float2, (const float2 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float2", asBEHAVE_CONSTRUCT, "void f(float,float)", AS_CONSTRUCTOR(float2_ctor_float_float, float2, (float,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float2", asBEHAVE_CONSTRUCT, "void f(float)", AS_CONSTRUCTOR(float2_ctor_float, float2, (float)), AS_CTOR_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectBehaviour("float2", asBEHAVE_CONSTRUCT, "void f(const float *)", AS_CONSTRUCTOR(float2_ctor_const_float_ptr, float2, (const float *)), AS_CTOR_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float2", "float * ptr()", AS_METHOD_FUNCTION_PR(float2, ptr, (), float *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float2", "const float * ptr() const", AS_METHOD_FUNCTION_PR(float2, ptr, () const, const float *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float2", "float & operator[](int)", AS_METHOD_FUNCTION_PR(float2, operator[], (int), float &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float2", "CONST_WIN32 float operator[](int) const", AS_METHOD_FUNCTION_PR(float2, operator[], (int) const, CONST_WIN32 float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float2", "float & At(int)", AS_METHOD_FUNCTION_PR(float2, At, (int), float &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float2", "CONST_WIN32 float At(int) const", AS_METHOD_FUNCTION_PR(float2, At, (int) const, CONST_WIN32 float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 opAdd(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, operator+, (const float2 &) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 opSub() const", AS_METHOD_FUNCTION_PR(float2, operator-, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 opSub(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, operator-, (const float2 &) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 opMul(float) const", AS_METHOD_FUNCTION_PR(float2, operator*, (float) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 opDiv(float) const", AS_METHOD_FUNCTION_PR(float2, operator/, (float) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float2 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float2", "float2 & opAdd=(const float2 &in)", AS_METHOD_FUNCTION_PR(float2, operator+=, (const float2 &), float2 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float2 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float2", "float2 & opSub=(const float2 &in)", AS_METHOD_FUNCTION_PR(float2, operator-=, (const float2 &), float2 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float2 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float2", "float2 & opMul=(float)", AS_METHOD_FUNCTION_PR(float2, operator*=, (float), float2 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float2 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float2", "float2 & opDiv=(float)", AS_METHOD_FUNCTION_PR(float2, operator/=, (float), float2 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Add(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, Add, (const float2 &) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Add(float) const", AS_METHOD_FUNCTION_PR(float2, Add, (float) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Sub(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, Sub, (const float2 &) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Sub(float) const", AS_METHOD_FUNCTION_PR(float2, Sub, (float) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 SubLeft(float) const", AS_METHOD_FUNCTION_PR(float2, SubLeft, (float) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Mul(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, Mul, (const float2 &) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Mul(float) const", AS_METHOD_FUNCTION_PR(float2, Mul, (float) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Div(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, Div, (const float2 &) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Div(float) const", AS_METHOD_FUNCTION_PR(float2, Div, (float) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 DivLeft(float) const", AS_METHOD_FUNCTION_PR(float2, DivLeft, (float) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 xx() const", AS_METHOD_FUNCTION_PR(float2, xx, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 xy() const", AS_METHOD_FUNCTION_PR(float2, xy, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 yx() const", AS_METHOD_FUNCTION_PR(float2, yx, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 yy() const", AS_METHOD_FUNCTION_PR(float2, yy, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Swizzled(int,int) const", AS_METHOD_FUNCTION_PR(float2, Swizzled, (int,int) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float3 Swizzled(int,int,int) const", AS_METHOD_FUNCTION_PR(float2, Swizzled, (int,int,int) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float4 Swizzled(int,int,int,int) const", AS_METHOD_FUNCTION_PR(float2, Swizzled, (int,int,int,int) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "void SetFromScalar(float)", AS_METHOD_FUNCTION_PR(float2, SetFromScalar, (float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "void Set(float,float)", AS_METHOD_FUNCTION_PR(float2, Set, (float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float Length() const", AS_METHOD_FUNCTION_PR(float2, Length, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float LengthSq() const", AS_METHOD_FUNCTION_PR(float2, LengthSq, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float Normalize()", AS_METHOD_FUNCTION_PR(float2, Normalize, (), float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Normalized() const", AS_METHOD_FUNCTION_PR(float2, Normalized, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float ScaleToLength(float)", AS_METHOD_FUNCTION_PR(float2, ScaleToLength, (float), float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 ScaledToLength(float) const", AS_METHOD_FUNCTION_PR(float2, ScaledToLength, (float) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "bool IsNormalized(float) const", AS_METHOD_FUNCTION_PR(float2, IsNormalized, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "bool IsZero(float) const", AS_METHOD_FUNCTION_PR(float2, IsZero, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "bool IsFinite() const", AS_METHOD_FUNCTION_PR(float2, IsFinite, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "bool IsPerpendicular(const float2 &in,float) const", AS_METHOD_FUNCTION_PR(float2, IsPerpendicular, (const float2 &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "bool Equals(const float2 &in,float) const", AS_METHOD_FUNCTION_PR(float2, Equals, (const float2 &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "bool Equals(float,float,float) const", AS_METHOD_FUNCTION_PR(float2, Equals, (float,float,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float SumOfElements() const", AS_METHOD_FUNCTION_PR(float2, SumOfElements, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float ProductOfElements() const", AS_METHOD_FUNCTION_PR(float2, ProductOfElements, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float AverageOfElements() const", AS_METHOD_FUNCTION_PR(float2, AverageOfElements, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float MinElement() const", AS_METHOD_FUNCTION_PR(float2, MinElement, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "int MinElementIndex() const", AS_METHOD_FUNCTION_PR(float2, MinElementIndex, () const, int), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float MaxElement() const", AS_METHOD_FUNCTION_PR(float2, MaxElement, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "int MaxElementIndex() const", AS_METHOD_FUNCTION_PR(float2, MaxElementIndex, () const, int), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Abs() const", AS_METHOD_FUNCTION_PR(float2, Abs, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Neg() const", AS_METHOD_FUNCTION_PR(float2, Neg, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Recip() const", AS_METHOD_FUNCTION_PR(float2, Recip, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Min(float) const", AS_METHOD_FUNCTION_PR(float2, Min, (float) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Min(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, Min, (const float2 &) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Max(float) const", AS_METHOD_FUNCTION_PR(float2, Max, (float) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Max(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, Max, (const float2 &) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Clamp(float,float) const", AS_METHOD_FUNCTION_PR(float2, Clamp, (float,float) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Clamp(const float2 &in,const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, Clamp, (const float2 &,const float2 &) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Clamp01() const", AS_METHOD_FUNCTION_PR(float2, Clamp01, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float Distance(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, Distance, (const float2 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float DistanceSq(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, DistanceSq, (const float2 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float Dot(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, Dot, (const float2 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Perp() const", AS_METHOD_FUNCTION_PR(float2, Perp, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float PerpDot(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, PerpDot, (const float2 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "void Rotate90CW()", AS_METHOD_FUNCTION_PR(float2, Rotate90CW, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Rotated90CW() const", AS_METHOD_FUNCTION_PR(float2, Rotated90CW, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "void Rotate90CCW()", AS_METHOD_FUNCTION_PR(float2, Rotate90CCW, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Rotated90CCW() const", AS_METHOD_FUNCTION_PR(float2, Rotated90CCW, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Reflect(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, Reflect, (const float2 &) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Refract(const float2 &in,float,float) const", AS_METHOD_FUNCTION_PR(float2, Refract, (const float2 &,float,float) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 ProjectTo(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, ProjectTo, (const float2 &) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 ProjectToNorm(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, ProjectToNorm, (const float2 &) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float AngleBetween(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, AngleBetween, (const float2 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float AngleBetweenNorm(const float2 &in) const", AS_METHOD_FUNCTION_PR(float2, AngleBetweenNorm, (const float2 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "void Decompose(const float2 &in,float2 &out,float2 &out) const", AS_METHOD_FUNCTION_PR(float2, Decompose, (const float2 &,float2 &,float2 &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float2", "float2 Lerp(const float2 &in,float) const", AS_METHOD_FUNCTION_PR(float2, Lerp, (const float2 &,float) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	//.classmethod(// /*(const char * is not known to angelscript)*/ 	//.classmethod(	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(


	r = engine->RegisterObjectProperty("float3", "float x", asOFFSET(float3, x)); assert(r >= 0);
	r = engine->RegisterObjectProperty("float3", "float y", asOFFSET(float3, y)); assert(r >= 0);
	r = engine->RegisterObjectProperty("float3", "float z", asOFFSET(float3, z)); assert(r >= 0);
// /* const float3 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float3", "const float3 zero", asOFFSET(float3, zero)); assert(r >= 0);
// /* const float3 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float3", "const float3 one", asOFFSET(float3, one)); assert(r >= 0);
// /* const float3 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float3", "const float3 unitX", asOFFSET(float3, unitX)); assert(r >= 0);
// /* const float3 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float3", "const float3 unitY", asOFFSET(float3, unitY)); assert(r >= 0);
// /* const float3 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float3", "const float3 unitZ", asOFFSET(float3, unitZ)); assert(r >= 0);
// /* const float3 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float3", "const float3 nan", asOFFSET(float3, nan)); assert(r >= 0);
// /* const float3 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float3", "const float3 inf", asOFFSET(float3, inf)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(float3_ctor_, float3, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3", asBEHAVE_CONSTRUCT, "void f(const float3 &in)", AS_CONSTRUCTOR(float3_ctor_const_float3_ref, float3, (const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3", asBEHAVE_CONSTRUCT, "void f(float,float,float)", AS_CONSTRUCTOR(float3_ctor_float_float_float, float3, (float,float,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3", asBEHAVE_CONSTRUCT, "void f(float)", AS_CONSTRUCTOR(float3_ctor_float, float3, (float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3", asBEHAVE_CONSTRUCT, "void f(const float2 &in,float)", AS_CONSTRUCTOR(float3_ctor_const_float2_ref_float, float3, (const float2 &,float)), AS_CTOR_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectBehaviour("float3", asBEHAVE_CONSTRUCT, "void f(const float *)", AS_CONSTRUCTOR(float3_ctor_const_float_ptr, float3, (const float *)), AS_CTOR_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3", "float * ptr()", AS_METHOD_FUNCTION_PR(float3, ptr, (), float *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3", "const float * ptr() const", AS_METHOD_FUNCTION_PR(float3, ptr, () const, const float *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3", "float & operator[](int)", AS_METHOD_FUNCTION_PR(float3, operator[], (int), float &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3", "CONST_WIN32 float operator[](int) const", AS_METHOD_FUNCTION_PR(float3, operator[], (int) const, CONST_WIN32 float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3", "float & At(int)", AS_METHOD_FUNCTION_PR(float3, At, (int), float &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3", "CONST_WIN32 float At(int) const", AS_METHOD_FUNCTION_PR(float3, At, (int) const, CONST_WIN32 float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 opAdd(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, operator+, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 opSub() const", AS_METHOD_FUNCTION_PR(float3, operator-, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 opSub(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, operator-, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 opMul(float) const", AS_METHOD_FUNCTION_PR(float3, operator*, (float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 opDiv(float) const", AS_METHOD_FUNCTION_PR(float3, operator/, (float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3", "float3 & opAdd=(const float3 &in)", AS_METHOD_FUNCTION_PR(float3, operator+=, (const float3 &), float3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3", "float3 & opSub=(const float3 &in)", AS_METHOD_FUNCTION_PR(float3, operator-=, (const float3 &), float3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3", "float3 & opMul=(float)", AS_METHOD_FUNCTION_PR(float3, operator*=, (float), float3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3", "float3 & opDiv=(float)", AS_METHOD_FUNCTION_PR(float3, operator/=, (float), float3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Add(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, Add, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Add(float) const", AS_METHOD_FUNCTION_PR(float3, Add, (float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Sub(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, Sub, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Sub(float) const", AS_METHOD_FUNCTION_PR(float3, Sub, (float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 SubLeft(float) const", AS_METHOD_FUNCTION_PR(float3, SubLeft, (float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Mul(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, Mul, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Mul(float) const", AS_METHOD_FUNCTION_PR(float3, Mul, (float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Div(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, Div, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Div(float) const", AS_METHOD_FUNCTION_PR(float3, Div, (float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 DivLeft(float) const", AS_METHOD_FUNCTION_PR(float3, DivLeft, (float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float2 xx() const", AS_METHOD_FUNCTION_PR(float3, xx, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float2 xy() const", AS_METHOD_FUNCTION_PR(float3, xy, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float2 xz() const", AS_METHOD_FUNCTION_PR(float3, xz, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float2 yx() const", AS_METHOD_FUNCTION_PR(float3, yx, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float2 yy() const", AS_METHOD_FUNCTION_PR(float3, yy, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float2 yz() const", AS_METHOD_FUNCTION_PR(float3, yz, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float2 zx() const", AS_METHOD_FUNCTION_PR(float3, zx, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float2 zy() const", AS_METHOD_FUNCTION_PR(float3, zy, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float2 zz() const", AS_METHOD_FUNCTION_PR(float3, zz, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 xxx() const", AS_METHOD_FUNCTION_PR(float3, xxx, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 xxy() const", AS_METHOD_FUNCTION_PR(float3, xxy, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 xxz() const", AS_METHOD_FUNCTION_PR(float3, xxz, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 xyx() const", AS_METHOD_FUNCTION_PR(float3, xyx, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 xyy() const", AS_METHOD_FUNCTION_PR(float3, xyy, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 xyz() const", AS_METHOD_FUNCTION_PR(float3, xyz, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 xzx() const", AS_METHOD_FUNCTION_PR(float3, xzx, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 xzy() const", AS_METHOD_FUNCTION_PR(float3, xzy, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 xzz() const", AS_METHOD_FUNCTION_PR(float3, xzz, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 yxx() const", AS_METHOD_FUNCTION_PR(float3, yxx, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 yxy() const", AS_METHOD_FUNCTION_PR(float3, yxy, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 yxz() const", AS_METHOD_FUNCTION_PR(float3, yxz, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 yyx() const", AS_METHOD_FUNCTION_PR(float3, yyx, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 yyy() const", AS_METHOD_FUNCTION_PR(float3, yyy, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 yyz() const", AS_METHOD_FUNCTION_PR(float3, yyz, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 yzx() const", AS_METHOD_FUNCTION_PR(float3, yzx, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 yzy() const", AS_METHOD_FUNCTION_PR(float3, yzy, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 yzz() const", AS_METHOD_FUNCTION_PR(float3, yzz, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 zxx() const", AS_METHOD_FUNCTION_PR(float3, zxx, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 zxy() const", AS_METHOD_FUNCTION_PR(float3, zxy, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 zxz() const", AS_METHOD_FUNCTION_PR(float3, zxz, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 zyx() const", AS_METHOD_FUNCTION_PR(float3, zyx, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 zyy() const", AS_METHOD_FUNCTION_PR(float3, zyy, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 zyz() const", AS_METHOD_FUNCTION_PR(float3, zyz, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 zzx() const", AS_METHOD_FUNCTION_PR(float3, zzx, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 zzy() const", AS_METHOD_FUNCTION_PR(float3, zzy, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 zzz() const", AS_METHOD_FUNCTION_PR(float3, zzz, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float2 Swizzled(int,int) const", AS_METHOD_FUNCTION_PR(float3, Swizzled, (int,int) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Swizzled(int,int,int) const", AS_METHOD_FUNCTION_PR(float3, Swizzled, (int,int,int) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float4 Swizzled(int,int,int,int) const", AS_METHOD_FUNCTION_PR(float3, Swizzled, (int,int,int,int) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "void SetFromScalar(float)", AS_METHOD_FUNCTION_PR(float3, SetFromScalar, (float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "void Set(float,float,float)", AS_METHOD_FUNCTION_PR(float3, Set, (float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "void SetFromSphericalCoordinates(float,float,float)", AS_METHOD_FUNCTION_PR(float3, SetFromSphericalCoordinates, (float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "void SetFromSphericalCoordinates(float,float)", AS_METHOD_FUNCTION_PR(float3, SetFromSphericalCoordinates, (float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float4 ToPos4() const", AS_METHOD_FUNCTION_PR(float3, ToPos4, () const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float4 ToDir4() const", AS_METHOD_FUNCTION_PR(float3, ToDir4, () const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 ToSphericalCoordinates() const", AS_METHOD_FUNCTION_PR(float3, ToSphericalCoordinates, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float2 ToSphericalCoordinatesNormalized() const", AS_METHOD_FUNCTION_PR(float3, ToSphericalCoordinatesNormalized, () const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float Length() const", AS_METHOD_FUNCTION_PR(float3, Length, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float LengthSq() const", AS_METHOD_FUNCTION_PR(float3, LengthSq, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float Normalize()", AS_METHOD_FUNCTION_PR(float3, Normalize, (), float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Normalized() const", AS_METHOD_FUNCTION_PR(float3, Normalized, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float ScaleToLength(float)", AS_METHOD_FUNCTION_PR(float3, ScaleToLength, (float), float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 ScaledToLength(float) const", AS_METHOD_FUNCTION_PR(float3, ScaledToLength, (float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "bool IsNormalized(float) const", AS_METHOD_FUNCTION_PR(float3, IsNormalized, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "bool IsZero(float) const", AS_METHOD_FUNCTION_PR(float3, IsZero, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "bool IsFinite() const", AS_METHOD_FUNCTION_PR(float3, IsFinite, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "bool IsPerpendicular(const float3 &in,float) const", AS_METHOD_FUNCTION_PR(float3, IsPerpendicular, (const float3 &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "bool Equals(const float3 &in,float) const", AS_METHOD_FUNCTION_PR(float3, Equals, (const float3 &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "bool Equals(float,float,float,float) const", AS_METHOD_FUNCTION_PR(float3, Equals, (float,float,float,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float SumOfElements() const", AS_METHOD_FUNCTION_PR(float3, SumOfElements, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float ProductOfElements() const", AS_METHOD_FUNCTION_PR(float3, ProductOfElements, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float AverageOfElements() const", AS_METHOD_FUNCTION_PR(float3, AverageOfElements, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float MinElement() const", AS_METHOD_FUNCTION_PR(float3, MinElement, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "int MinElementIndex() const", AS_METHOD_FUNCTION_PR(float3, MinElementIndex, () const, int), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float MaxElement() const", AS_METHOD_FUNCTION_PR(float3, MaxElement, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "int MaxElementIndex() const", AS_METHOD_FUNCTION_PR(float3, MaxElementIndex, () const, int), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Abs() const", AS_METHOD_FUNCTION_PR(float3, Abs, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Neg() const", AS_METHOD_FUNCTION_PR(float3, Neg, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Recip() const", AS_METHOD_FUNCTION_PR(float3, Recip, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Min(float) const", AS_METHOD_FUNCTION_PR(float3, Min, (float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Min(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, Min, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Max(float) const", AS_METHOD_FUNCTION_PR(float3, Max, (float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Max(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, Max, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Clamp(float,float) const", AS_METHOD_FUNCTION_PR(float3, Clamp, (float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Clamp(const float3 &in,const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, Clamp, (const float3 &,const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Clamp01() const", AS_METHOD_FUNCTION_PR(float3, Clamp01, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float Distance(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, Distance, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float Distance(const Line &in) const", AS_METHOD_FUNCTION_PR(float3, Distance, (const Line &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float Distance(const Ray &in) const", AS_METHOD_FUNCTION_PR(float3, Distance, (const Ray &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float Distance(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(float3, Distance, (const LineSegment &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float Distance(const Plane &in) const", AS_METHOD_FUNCTION_PR(float3, Distance, (const Plane &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float Distance(const Triangle &in) const", AS_METHOD_FUNCTION_PR(float3, Distance, (const Triangle &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float Distance(const AABB &in) const", AS_METHOD_FUNCTION_PR(float3, Distance, (const AABB &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float Distance(const OBB &in) const", AS_METHOD_FUNCTION_PR(float3, Distance, (const OBB &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float Distance(const Sphere &in) const", AS_METHOD_FUNCTION_PR(float3, Distance, (const Sphere &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float Distance(const Capsule &in) const", AS_METHOD_FUNCTION_PR(float3, Distance, (const Capsule &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float DistanceSq(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, DistanceSq, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float Dot(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, Dot, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Cross(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, Cross, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3x3 OuterProduct(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, OuterProduct, (const float3 &) const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Perpendicular(const float3 &in,const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, Perpendicular, (const float3 &,const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 AnotherPerpendicular(const float3 &in,const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, AnotherPerpendicular, (const float3 &,const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Reflect(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, Reflect, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Refract(const float3 &in,float,float) const", AS_METHOD_FUNCTION_PR(float3, Refract, (const float3 &,float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 ProjectTo(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, ProjectTo, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 ProjectToNorm(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, ProjectToNorm, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float AngleBetween(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, AngleBetween, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float AngleBetweenNorm(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3, AngleBetweenNorm, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "void Decompose(const float3 &in,float3 &out,float3 &out) const", AS_METHOD_FUNCTION_PR(float3, Decompose, (const float3 &,float3 &,float3 &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3", "float3 Lerp(const float3 &in,float) const", AS_METHOD_FUNCTION_PR(float3, Lerp, (const float3 &,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	//.classmethod(	//.classmethod(	//.classmethod(// /*(const char * is not known to angelscript)*/ 	//.classmethod(	//.classmethod(	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(	//.classmethod(	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(	//.classmethod(	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(


	r = engine->RegisterObjectProperty("float4", "float x", asOFFSET(float4, x)); assert(r >= 0);
	r = engine->RegisterObjectProperty("float4", "float y", asOFFSET(float4, y)); assert(r >= 0);
	r = engine->RegisterObjectProperty("float4", "float z", asOFFSET(float4, z)); assert(r >= 0);
	r = engine->RegisterObjectProperty("float4", "float w", asOFFSET(float4, w)); assert(r >= 0);
// /* const float4 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float4", "const float4 zero", asOFFSET(float4, zero)); assert(r >= 0);
// /* const float4 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float4", "const float4 one", asOFFSET(float4, one)); assert(r >= 0);
// /* const float4 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float4", "const float4 unitX", asOFFSET(float4, unitX)); assert(r >= 0);
// /* const float4 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float4", "const float4 unitY", asOFFSET(float4, unitY)); assert(r >= 0);
// /* const float4 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float4", "const float4 unitZ", asOFFSET(float4, unitZ)); assert(r >= 0);
// /* const float4 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float4", "const float4 unitW", asOFFSET(float4, unitW)); assert(r >= 0);
// /* const float4 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float4", "const float4 nan", asOFFSET(float4, nan)); assert(r >= 0);
// /* const float4 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float4", "const float4 inf", asOFFSET(float4, inf)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float4", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(float4_ctor_, float4, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float4", asBEHAVE_CONSTRUCT, "void f(const float4 &in)", AS_CONSTRUCTOR(float4_ctor_const_float4_ref, float4, (const float4 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float4", asBEHAVE_CONSTRUCT, "void f(float,float,float,float)", AS_CONSTRUCTOR(float4_ctor_float_float_float_float, float4, (float,float,float,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float4", asBEHAVE_CONSTRUCT, "void f(const float3 &in,float)", AS_CONSTRUCTOR(float4_ctor_const_float3_ref_float, float4, (const float3 &,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float4", asBEHAVE_CONSTRUCT, "void f(const float2 &in,float,float)", AS_CONSTRUCTOR(float4_ctor_const_float2_ref_float_float, float4, (const float2 &,float,float)), AS_CTOR_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectBehaviour("float4", asBEHAVE_CONSTRUCT, "void f(const float *)", AS_CONSTRUCTOR(float4_ctor_const_float_ptr, float4, (const float *)), AS_CTOR_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4", "float * ptr()", AS_METHOD_FUNCTION_PR(float4, ptr, (), float *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4", "const float * ptr() const", AS_METHOD_FUNCTION_PR(float4, ptr, () const, const float *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4", "float & operator[](int)", AS_METHOD_FUNCTION_PR(float4, operator[], (int), float &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4", "CONST_WIN32 float operator[](int) const", AS_METHOD_FUNCTION_PR(float4, operator[], (int) const, CONST_WIN32 float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4", "float & At(int)", AS_METHOD_FUNCTION_PR(float4, At, (int), float &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4", "CONST_WIN32 float At(int) const", AS_METHOD_FUNCTION_PR(float4, At, (int) const, CONST_WIN32 float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 opAdd(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, operator+, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 opSub() const", AS_METHOD_FUNCTION_PR(float4, operator-, () const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 opSub(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, operator-, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 opMul(float) const", AS_METHOD_FUNCTION_PR(float4, operator*, (float) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 opDiv(float) const", AS_METHOD_FUNCTION_PR(float4, operator/, (float) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4", "float4 & opAdd=(const float4 &in)", AS_METHOD_FUNCTION_PR(float4, operator+=, (const float4 &), float4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4", "float4 & opSub=(const float4 &in)", AS_METHOD_FUNCTION_PR(float4, operator-=, (const float4 &), float4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4", "float4 & opMul=(float)", AS_METHOD_FUNCTION_PR(float4, operator*=, (float), float4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4", "float4 & opDiv=(float)", AS_METHOD_FUNCTION_PR(float4, operator/=, (float), float4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Add(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, Add, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Add(float) const", AS_METHOD_FUNCTION_PR(float4, Add, (float) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Sub(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, Sub, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Sub(float) const", AS_METHOD_FUNCTION_PR(float4, Sub, (float) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 SubLeft(float) const", AS_METHOD_FUNCTION_PR(float4, SubLeft, (float) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Mul(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, Mul, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Mul(float) const", AS_METHOD_FUNCTION_PR(float4, Mul, (float) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Div(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, Div, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Div(float) const", AS_METHOD_FUNCTION_PR(float4, Div, (float) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 DivLeft(float) const", AS_METHOD_FUNCTION_PR(float4, DivLeft, (float) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float3 xyz() const", AS_METHOD_FUNCTION_PR(float4, xyz, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float2 Swizzled(int,int) const", AS_METHOD_FUNCTION_PR(float4, Swizzled, (int,int) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float3 Swizzled(int,int,int) const", AS_METHOD_FUNCTION_PR(float4, Swizzled, (int,int,int) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Swizzled(int,int,int,int) const", AS_METHOD_FUNCTION_PR(float4, Swizzled, (int,int,int,int) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "void SetFromScalar(float)", AS_METHOD_FUNCTION_PR(float4, SetFromScalar, (float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "void SetFromScalar(float,float)", AS_METHOD_FUNCTION_PR(float4, SetFromScalar, (float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "void Set(float,float,float,float)", AS_METHOD_FUNCTION_PR(float4, Set, (float,float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float LengthSq3() const", AS_METHOD_FUNCTION_PR(float4, LengthSq3, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float Length3() const", AS_METHOD_FUNCTION_PR(float4, Length3, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float LengthSq4() const", AS_METHOD_FUNCTION_PR(float4, LengthSq4, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float Length4() const", AS_METHOD_FUNCTION_PR(float4, Length4, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float Normalize3()", AS_METHOD_FUNCTION_PR(float4, Normalize3, (), float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float Normalize4()", AS_METHOD_FUNCTION_PR(float4, Normalize4, (), float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Normalized3() const", AS_METHOD_FUNCTION_PR(float4, Normalized3, () const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Normalized4() const", AS_METHOD_FUNCTION_PR(float4, Normalized4, () const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "bool NormalizeW()", AS_METHOD_FUNCTION_PR(float4, NormalizeW, (), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "bool IsWZeroOrOne(float) const", AS_METHOD_FUNCTION_PR(float4, IsWZeroOrOne, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "bool IsZero3(float) const", AS_METHOD_FUNCTION_PR(float4, IsZero3, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "bool IsZero4(float) const", AS_METHOD_FUNCTION_PR(float4, IsZero4, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "bool IsNormalized3(float) const", AS_METHOD_FUNCTION_PR(float4, IsNormalized3, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "bool IsNormalized4(float) const", AS_METHOD_FUNCTION_PR(float4, IsNormalized4, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "void Scale3(float)", AS_METHOD_FUNCTION_PR(float4, Scale3, (float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float ScaleToLength3(float)", AS_METHOD_FUNCTION_PR(float4, ScaleToLength3, (float), float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 ScaledToLength3(float) const", AS_METHOD_FUNCTION_PR(float4, ScaledToLength3, (float) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "bool IsFinite() const", AS_METHOD_FUNCTION_PR(float4, IsFinite, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "bool IsPerpendicular3(const float4 &in,float) const", AS_METHOD_FUNCTION_PR(float4, IsPerpendicular3, (const float4 &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float SumOfElements() const", AS_METHOD_FUNCTION_PR(float4, SumOfElements, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float ProductOfElements() const", AS_METHOD_FUNCTION_PR(float4, ProductOfElements, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float AverageOfElements() const", AS_METHOD_FUNCTION_PR(float4, AverageOfElements, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float MinElement() const", AS_METHOD_FUNCTION_PR(float4, MinElement, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "int MinElementIndex() const", AS_METHOD_FUNCTION_PR(float4, MinElementIndex, () const, int), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float MaxElement() const", AS_METHOD_FUNCTION_PR(float4, MaxElement, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "int MaxElementIndex() const", AS_METHOD_FUNCTION_PR(float4, MaxElementIndex, () const, int), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Abs() const", AS_METHOD_FUNCTION_PR(float4, Abs, () const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Neg3() const", AS_METHOD_FUNCTION_PR(float4, Neg3, () const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Neg4() const", AS_METHOD_FUNCTION_PR(float4, Neg4, () const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Recip3() const", AS_METHOD_FUNCTION_PR(float4, Recip3, () const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Recip4() const", AS_METHOD_FUNCTION_PR(float4, Recip4, () const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Min(float) const", AS_METHOD_FUNCTION_PR(float4, Min, (float) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Min(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, Min, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Max(float) const", AS_METHOD_FUNCTION_PR(float4, Max, (float) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Max(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, Max, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Clamp(float,float) const", AS_METHOD_FUNCTION_PR(float4, Clamp, (float,float) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Clamp(const float4 &in,const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, Clamp, (const float4 &,const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Clamp01() const", AS_METHOD_FUNCTION_PR(float4, Clamp01, () const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Lerp(const float4 &in,float) const", AS_METHOD_FUNCTION_PR(float4, Lerp, (const float4 &,float) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float Distance3Sq(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, Distance3Sq, (const float4 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float Distance3(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, Distance3, (const float4 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float Dot3(const float3 &in) const", AS_METHOD_FUNCTION_PR(float4, Dot3, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float Dot3(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, Dot3, (const float4 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float Dot4(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, Dot4, (const float4 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Cross3(const float3 &in) const", AS_METHOD_FUNCTION_PR(float4, Cross3, (const float3 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Cross3(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, Cross3, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4x4 OuterProduct(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, OuterProduct, (const float4 &) const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Perpendicular3(const float3 &in,const float3 &in) const", AS_METHOD_FUNCTION_PR(float4, Perpendicular3, (const float3 &,const float3 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 AnotherPerpendicular3(const float3 &in,const float3 &in) const", AS_METHOD_FUNCTION_PR(float4, AnotherPerpendicular3, (const float3 &,const float3 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 Reflect3(const float3 &in) const", AS_METHOD_FUNCTION_PR(float4, Reflect3, (const float3 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float AngleBetween3(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, AngleBetween3, (const float4 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float AngleBetweenNorm3(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, AngleBetweenNorm3, (const float4 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float AngleBetween4(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, AngleBetween4, (const float4 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float AngleBetweenNorm4(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4, AngleBetweenNorm4, (const float4 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 ProjectTo3(const float3 &in) const", AS_METHOD_FUNCTION_PR(float4, ProjectTo3, (const float3 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "float4 ProjectToNorm3(const float3 &in) const", AS_METHOD_FUNCTION_PR(float4, ProjectToNorm3, (const float3 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "bool Equals(const float4 &in,float) const", AS_METHOD_FUNCTION_PR(float4, Equals, (const float4 &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4", "bool Equals(float,float,float,float,float) const", AS_METHOD_FUNCTION_PR(float4, Equals, (float,float,float,float,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	//.classmethod(	//.classmethod(// /*(const char * is not known to angelscript)*/ 	//.classmethod(	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(


// /* Exposing array types as fields are not supported by angelscript. */ 	r = engine->RegisterObjectProperty("float3x3", "float v", asOFFSET(float3x3, v)); assert(r >= 0);
// /* const float3x3 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float3x3", "const float3x3 zero", asOFFSET(float3x3, zero)); assert(r >= 0);
// /* const float3x3 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float3x3", "const float3x3 identity", asOFFSET(float3x3, identity)); assert(r >= 0);
// /* const float3x3 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float3x3", "const float3x3 nan", asOFFSET(float3x3, nan)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3x3", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(float3x3_ctor_, float3x3, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3x3", asBEHAVE_CONSTRUCT, "void f(const float3x3 &in)", AS_CONSTRUCTOR(float3x3_ctor_const_float3x3_ref, float3x3, (const float3x3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3x3", asBEHAVE_CONSTRUCT, "void f(float,float,float,float,float,float,float,float,float)", AS_CONSTRUCTOR(float3x3_ctor_float_float_float_float_float_float_float_float_float, float3x3, (float,float,float,float,float,float,float,float,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3x3", asBEHAVE_CONSTRUCT, "void f(const float3 &in,const float3 &in,const float3 &in)", AS_CONSTRUCTOR(float3x3_ctor_const_float3_ref_const_float3_ref_const_float3_ref, float3x3, (const float3 &,const float3 &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3x3", asBEHAVE_CONSTRUCT, "void f(const Quat &in)", AS_CONSTRUCTOR(float3x3_ctor_const_Quat_ref, float3x3, (const Quat &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "Quat ToQuat() const", AS_METHOD_FUNCTION_PR(float3x3, ToQuat, () const, Quat), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 GetScale() const", AS_METHOD_FUNCTION_PR(float3x3, GetScale, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(MatrixProxy < Cols > & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "MatrixProxy < Cols > & operator[](int)", AS_METHOD_FUNCTION_PR(float3x3, operator[], (int), MatrixProxy < Cols > &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const MatrixProxy < Cols > & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "const MatrixProxy < Cols > & operator[](int) const", AS_METHOD_FUNCTION_PR(float3x3, operator[], (int) const, const MatrixProxy < Cols > &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "float & At(int,int)", AS_METHOD_FUNCTION_PR(float3x3, At, (int,int), float &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "CONST_WIN32 float At(int,int) const", AS_METHOD_FUNCTION_PR(float3x3, At, (int,int) const, CONST_WIN32 float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "float3 & Row(int)", AS_METHOD_FUNCTION_PR(float3x3, Row, (int), float3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "const float3 & Row(int) const", AS_METHOD_FUNCTION_PR(float3x3, Row, (int) const, const float3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "float3 & Row3(int)", AS_METHOD_FUNCTION_PR(float3x3, Row3, (int), float3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "const float3 & Row3(int) const", AS_METHOD_FUNCTION_PR(float3x3, Row3, (int) const, const float3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float3 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "CONST_WIN32 float3 Col(int) const", AS_METHOD_FUNCTION_PR(float3x3, Col, (int) const, CONST_WIN32 float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float3 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "CONST_WIN32 float3 Col3(int) const", AS_METHOD_FUNCTION_PR(float3x3, Col3, (int) const, CONST_WIN32 float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float3 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "CONST_WIN32 float3 Diagonal() const", AS_METHOD_FUNCTION_PR(float3x3, Diagonal, () const, CONST_WIN32 float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void ScaleRow(int,float)", AS_METHOD_FUNCTION_PR(float3x3, ScaleRow, (int,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void ScaleCol(int,float)", AS_METHOD_FUNCTION_PR(float3x3, ScaleCol, (int,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 WorldX() const", AS_METHOD_FUNCTION_PR(float3x3, WorldX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 WorldY() const", AS_METHOD_FUNCTION_PR(float3x3, WorldY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 WorldZ() const", AS_METHOD_FUNCTION_PR(float3x3, WorldZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "float * ptr()", AS_METHOD_FUNCTION_PR(float3x3, ptr, (), float *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "const float * ptr() const", AS_METHOD_FUNCTION_PR(float3x3, ptr, () const, const float *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void SetRow(int,float,float,float)", AS_METHOD_FUNCTION_PR(float3x3, SetRow, (int,float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void SetRow(int,const float3 &in)", AS_METHOD_FUNCTION_PR(float3x3, SetRow, (int,const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "void SetRow(int,const float *)", AS_METHOD_FUNCTION_PR(float3x3, SetRow, (int,const float *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void SetCol(int,float,float,float)", AS_METHOD_FUNCTION_PR(float3x3, SetCol, (int,float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void SetCol(int,const float3 &in)", AS_METHOD_FUNCTION_PR(float3x3, SetCol, (int,const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "void SetCol(int,const float *)", AS_METHOD_FUNCTION_PR(float3x3, SetCol, (int,const float *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void Set(float,float,float,float,float,float,float,float,float)", AS_METHOD_FUNCTION_PR(float3x3, Set, (float,float,float,float,float,float,float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void Set(const float3x3 &in)", AS_METHOD_FUNCTION_PR(float3x3, Set, (const float3x3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "void Set(const float *)", AS_METHOD_FUNCTION_PR(float3x3, Set, (const float *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void Set(int,int,float)", AS_METHOD_FUNCTION_PR(float3x3, Set, (int,int,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void SetIdentity()", AS_METHOD_FUNCTION_PR(float3x3, SetIdentity, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void SwapColumns(int,int)", AS_METHOD_FUNCTION_PR(float3x3, SwapColumns, (int,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void SwapRows(int,int)", AS_METHOD_FUNCTION_PR(float3x3, SwapRows, (int,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void SetRotatePartX(float)", AS_METHOD_FUNCTION_PR(float3x3, SetRotatePartX, (float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void SetRotatePartY(float)", AS_METHOD_FUNCTION_PR(float3x3, SetRotatePartY, (float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void SetRotatePartZ(float)", AS_METHOD_FUNCTION_PR(float3x3, SetRotatePartZ, (float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void SetRotatePart(const float3 &in,float)", AS_METHOD_FUNCTION_PR(float3x3, SetRotatePart, (const float3 &,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void SetRotatePart(const Quat &in)", AS_METHOD_FUNCTION_PR(float3x3, SetRotatePart, (const Quat &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3x3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "float3x3 & operator=(const Quat &in)", AS_METHOD_FUNCTION_PR(float3x3, operator=, (const Quat &), float3x3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3x3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "float3x3 & operator=(const float3x3 &in)", AS_METHOD_FUNCTION_PR(float3x3, operator=, (const float3x3 &), float3x3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float Determinant() const", AS_METHOD_FUNCTION_PR(float3x3, Determinant, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool Inverse()", AS_METHOD_FUNCTION_PR(float3x3, Inverse, (), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3x3 Inverted() const", AS_METHOD_FUNCTION_PR(float3x3, Inverted, () const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool InverseColOrthogonal()", AS_METHOD_FUNCTION_PR(float3x3, InverseColOrthogonal, (), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool InverseOrthogonalUniformScale()", AS_METHOD_FUNCTION_PR(float3x3, InverseOrthogonalUniformScale, (), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void InverseOrthonormal()", AS_METHOD_FUNCTION_PR(float3x3, InverseOrthonormal, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void Transpose()", AS_METHOD_FUNCTION_PR(float3x3, Transpose, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3x3 Transposed() const", AS_METHOD_FUNCTION_PR(float3x3, Transposed, () const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool InverseTranspose()", AS_METHOD_FUNCTION_PR(float3x3, InverseTranspose, (), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3x3 InverseTransposed() const", AS_METHOD_FUNCTION_PR(float3x3, InverseTransposed, () const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float Trace() const", AS_METHOD_FUNCTION_PR(float3x3, Trace, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void Orthonormalize(int,int,int)", AS_METHOD_FUNCTION_PR(float3x3, Orthonormalize, (int,int,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void RemoveScale()", AS_METHOD_FUNCTION_PR(float3x3, RemoveScale, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 Transform(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3x3, Transform, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 Transform(float,float,float) const", AS_METHOD_FUNCTION_PR(float3x3, Transform, (float,float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 TransformLeft(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3x3, TransformLeft, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float4 Transform(const float4 &in) const", AS_METHOD_FUNCTION_PR(float3x3, Transform, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "void BatchTransform(float3 *,int) const", AS_METHOD_FUNCTION_PR(float3x3, BatchTransform, (float3 *,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "void BatchTransform(float3 *,int,int) const", AS_METHOD_FUNCTION_PR(float3x3, BatchTransform, (float3 *,int,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "void BatchTransform(float4 *,int) const", AS_METHOD_FUNCTION_PR(float3x3, BatchTransform, (float4 *,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "void BatchTransform(float4 *,int,int) const", AS_METHOD_FUNCTION_PR(float3x3, BatchTransform, (float4 *,int,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3x3 opMul(const float3x3 &in) const", AS_METHOD_FUNCTION_PR(float3x3, operator*, (const float3x3 &) const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3x3 opMul(const Quat &in) const", AS_METHOD_FUNCTION_PR(float3x3, operator*, (const Quat &) const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 opMul(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3x3, operator*, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float4 opMul(const float4 &in) const", AS_METHOD_FUNCTION_PR(float3x3, operator*, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3x3 opMul(float) const", AS_METHOD_FUNCTION_PR(float3x3, operator*, (float) const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3x3 opDiv(float) const", AS_METHOD_FUNCTION_PR(float3x3, operator/, (float) const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3x3 opAdd(const float3x3 &in) const", AS_METHOD_FUNCTION_PR(float3x3, operator+, (const float3x3 &) const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3x3 opSub(const float3x3 &in) const", AS_METHOD_FUNCTION_PR(float3x3, operator-, (const float3x3 &) const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3x3 opSub() const", AS_METHOD_FUNCTION_PR(float3x3, operator-, () const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3x3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "float3x3 & opMul=(float)", AS_METHOD_FUNCTION_PR(float3x3, operator*=, (float), float3x3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3x3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "float3x3 & opDiv=(float)", AS_METHOD_FUNCTION_PR(float3x3, operator/=, (float), float3x3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3x3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "float3x3 & opAdd=(const float3x3 &in)", AS_METHOD_FUNCTION_PR(float3x3, operator+=, (const float3x3 &), float3x3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3x3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x3", "float3x3 & opSub=(const float3x3 &in)", AS_METHOD_FUNCTION_PR(float3x3, operator-=, (const float3x3 &), float3x3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool IsFinite() const", AS_METHOD_FUNCTION_PR(float3x3, IsFinite, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool IsIdentity(float) const", AS_METHOD_FUNCTION_PR(float3x3, IsIdentity, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool IsLowerTriangular(float) const", AS_METHOD_FUNCTION_PR(float3x3, IsLowerTriangular, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool IsUpperTriangular(float) const", AS_METHOD_FUNCTION_PR(float3x3, IsUpperTriangular, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool IsInvertible(float) const", AS_METHOD_FUNCTION_PR(float3x3, IsInvertible, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool IsSymmetric(float) const", AS_METHOD_FUNCTION_PR(float3x3, IsSymmetric, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool IsSkewSymmetric(float) const", AS_METHOD_FUNCTION_PR(float3x3, IsSkewSymmetric, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool HasUnitaryScale(float) const", AS_METHOD_FUNCTION_PR(float3x3, HasUnitaryScale, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool HasNegativeScale() const", AS_METHOD_FUNCTION_PR(float3x3, HasNegativeScale, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool HasUniformScale(float) const", AS_METHOD_FUNCTION_PR(float3x3, HasUniformScale, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool IsRowOrthogonal(float) const", AS_METHOD_FUNCTION_PR(float3x3, IsRowOrthogonal, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool IsColOrthogonal(float) const", AS_METHOD_FUNCTION_PR(float3x3, IsColOrthogonal, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool IsColOrthogonal3(float) const", AS_METHOD_FUNCTION_PR(float3x3, IsColOrthogonal3, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool IsOrthonormal(float) const", AS_METHOD_FUNCTION_PR(float3x3, IsOrthonormal, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "bool Equals(const float3x3 &in,float) const", AS_METHOD_FUNCTION_PR(float3x3, Equals, (const float3x3 &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 ToEulerXYX() const", AS_METHOD_FUNCTION_PR(float3x3, ToEulerXYX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 ToEulerXZX() const", AS_METHOD_FUNCTION_PR(float3x3, ToEulerXZX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 ToEulerYXY() const", AS_METHOD_FUNCTION_PR(float3x3, ToEulerYXY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 ToEulerYZY() const", AS_METHOD_FUNCTION_PR(float3x3, ToEulerYZY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 ToEulerZXZ() const", AS_METHOD_FUNCTION_PR(float3x3, ToEulerZXZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 ToEulerZYZ() const", AS_METHOD_FUNCTION_PR(float3x3, ToEulerZYZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 ToEulerXYZ() const", AS_METHOD_FUNCTION_PR(float3x3, ToEulerXYZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 ToEulerXZY() const", AS_METHOD_FUNCTION_PR(float3x3, ToEulerXZY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 ToEulerYXZ() const", AS_METHOD_FUNCTION_PR(float3x3, ToEulerYXZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 ToEulerYZX() const", AS_METHOD_FUNCTION_PR(float3x3, ToEulerYZX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 ToEulerZXY() const", AS_METHOD_FUNCTION_PR(float3x3, ToEulerZXY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 ToEulerZYX() const", AS_METHOD_FUNCTION_PR(float3x3, ToEulerZYX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 ExtractScale() const", AS_METHOD_FUNCTION_PR(float3x3, ExtractScale, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "void Decompose(Quat &out,float3 &out) const", AS_METHOD_FUNCTION_PR(float3x3, Decompose, (Quat &,float3 &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("float3x3", "void Decompose(float3x3 &,float3 &) const", AS_METHOD_FUNCTION_PR(float3x3, Decompose, (float3x3 &,float3 &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3x3 Mul(const float3x3 &in) const", AS_METHOD_FUNCTION_PR(float3x3, Mul, (const float3x3 &) const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3x4 Mul(const float3x4 &in) const", AS_METHOD_FUNCTION_PR(float3x3, Mul, (const float3x4 &) const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float4x4 Mul(const float4x4 &in) const", AS_METHOD_FUNCTION_PR(float3x3, Mul, (const float4x4 &) const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3x3 Mul(const Quat &in) const", AS_METHOD_FUNCTION_PR(float3x3, Mul, (const Quat &) const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 Mul(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3x3, Mul, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 MulPos(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3x3, MulPos, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x3", "float3 MulDir(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3x3, MulDir, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(


// /* Exposing array types as fields are not supported by angelscript. */ 	r = engine->RegisterObjectProperty("float3x4", "float v", asOFFSET(float3x4, v)); assert(r >= 0);
// /* const float3x4 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float3x4", "const float3x4 zero", asOFFSET(float3x4, zero)); assert(r >= 0);
// /* const float3x4 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float3x4", "const float3x4 identity", asOFFSET(float3x4, identity)); assert(r >= 0);
// /* const float3x4 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float3x4", "const float3x4 nan", asOFFSET(float3x4, nan)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3x4", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(float3x4_ctor_, float3x4, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3x4", asBEHAVE_CONSTRUCT, "void f(const float3x4 &in)", AS_CONSTRUCTOR(float3x4_ctor_const_float3x4_ref, float3x4, (const float3x4 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3x4", asBEHAVE_CONSTRUCT, "void f(float,float,float,float,float,float,float,float,float,float,float,float)", AS_CONSTRUCTOR(float3x4_ctor_float_float_float_float_float_float_float_float_float_float_float_float, float3x4, (float,float,float,float,float,float,float,float,float,float,float,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3x4", asBEHAVE_CONSTRUCT, "void f(const float3x3 &in)", AS_CONSTRUCTOR(float3x4_ctor_const_float3x3_ref, float3x4, (const float3x3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3x4", asBEHAVE_CONSTRUCT, "void f(const float3x3 &in,const float3 &in)", AS_CONSTRUCTOR(float3x4_ctor_const_float3x3_ref_const_float3_ref, float3x4, (const float3x3 &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3x4", asBEHAVE_CONSTRUCT, "void f(const float3 &in,const float3 &in,const float3 &in,const float3 &in)", AS_CONSTRUCTOR(float3x4_ctor_const_float3_ref_const_float3_ref_const_float3_ref_const_float3_ref, float3x4, (const float3 &,const float3 &,const float3 &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3x4", asBEHAVE_CONSTRUCT, "void f(const Quat &in)", AS_CONSTRUCTOR(float3x4_ctor_const_Quat_ref, float3x4, (const Quat &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float3x4", asBEHAVE_CONSTRUCT, "void f(const Quat &in,const float3 &in)", AS_CONSTRUCTOR(float3x4_ctor_const_Quat_ref_const_float3_ref, float3x4, (const Quat &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 GetScale() const", AS_METHOD_FUNCTION_PR(float3x4, GetScale, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(MatrixProxy < Cols > & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "MatrixProxy < Cols > & operator[](int)", AS_METHOD_FUNCTION_PR(float3x4, operator[], (int), MatrixProxy < Cols > &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const MatrixProxy < Cols > & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "const MatrixProxy < Cols > & operator[](int) const", AS_METHOD_FUNCTION_PR(float3x4, operator[], (int) const, const MatrixProxy < Cols > &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "float & At(int,int)", AS_METHOD_FUNCTION_PR(float3x4, At, (int,int), float &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "CONST_WIN32 float At(int,int) const", AS_METHOD_FUNCTION_PR(float3x4, At, (int,int) const, CONST_WIN32 float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "float4 & Row(int)", AS_METHOD_FUNCTION_PR(float3x4, Row, (int), float4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "const float4 & Row(int) const", AS_METHOD_FUNCTION_PR(float3x4, Row, (int) const, const float4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "float3 & Row3(int)", AS_METHOD_FUNCTION_PR(float3x4, Row3, (int), float3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "const float3 & Row3(int) const", AS_METHOD_FUNCTION_PR(float3x4, Row3, (int) const, const float3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float3 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "CONST_WIN32 float3 Col(int) const", AS_METHOD_FUNCTION_PR(float3x4, Col, (int) const, CONST_WIN32 float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float3 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "CONST_WIN32 float3 Col3(int) const", AS_METHOD_FUNCTION_PR(float3x4, Col3, (int) const, CONST_WIN32 float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float3 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "CONST_WIN32 float3 Diagonal() const", AS_METHOD_FUNCTION_PR(float3x4, Diagonal, () const, CONST_WIN32 float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void ScaleRow3(int,float)", AS_METHOD_FUNCTION_PR(float3x4, ScaleRow3, (int,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void ScaleRow(int,float)", AS_METHOD_FUNCTION_PR(float3x4, ScaleRow, (int,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void ScaleCol(int,float)", AS_METHOD_FUNCTION_PR(float3x4, ScaleCol, (int,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float3x3 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "CONST_WIN32 float3x3 Float3x3Part() const", AS_METHOD_FUNCTION_PR(float3x4, Float3x3Part, () const, CONST_WIN32 float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float3 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "CONST_WIN32 float3 TranslatePart() const", AS_METHOD_FUNCTION_PR(float3x4, TranslatePart, () const, CONST_WIN32 float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float3x3 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "CONST_WIN32 float3x3 RotatePart() const", AS_METHOD_FUNCTION_PR(float3x4, RotatePart, () const, CONST_WIN32 float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 WorldX() const", AS_METHOD_FUNCTION_PR(float3x4, WorldX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 WorldY() const", AS_METHOD_FUNCTION_PR(float3x4, WorldY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 WorldZ() const", AS_METHOD_FUNCTION_PR(float3x4, WorldZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "float * ptr()", AS_METHOD_FUNCTION_PR(float3x4, ptr, (), float *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "const float * ptr() const", AS_METHOD_FUNCTION_PR(float3x4, ptr, () const, const float *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SetRow(int,const float3 &in,float)", AS_METHOD_FUNCTION_PR(float3x4, SetRow, (int,const float3 &,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SetRow(int,const float4 &in)", AS_METHOD_FUNCTION_PR(float3x4, SetRow, (int,const float4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "void SetRow(int,const float *)", AS_METHOD_FUNCTION_PR(float3x4, SetRow, (int,const float *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SetRow(int,float,float,float,float)", AS_METHOD_FUNCTION_PR(float3x4, SetRow, (int,float,float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SetCol(int,const float3 &in)", AS_METHOD_FUNCTION_PR(float3x4, SetCol, (int,const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "void SetCol(int,const float *)", AS_METHOD_FUNCTION_PR(float3x4, SetCol, (int,const float *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SetCol(int,float,float,float)", AS_METHOD_FUNCTION_PR(float3x4, SetCol, (int,float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void Set(float,float,float,float,float,float,float,float,float,float,float,float)", AS_METHOD_FUNCTION_PR(float3x4, Set, (float,float,float,float,float,float,float,float,float,float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void Set(const float3x4 &in)", AS_METHOD_FUNCTION_PR(float3x4, Set, (const float3x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "void Set(const float *)", AS_METHOD_FUNCTION_PR(float3x4, Set, (const float *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void Set(int,int,float)", AS_METHOD_FUNCTION_PR(float3x4, Set, (int,int,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void Set3x3Part(const float3x3 &in)", AS_METHOD_FUNCTION_PR(float3x4, Set3x3Part, (const float3x3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SetIdentity()", AS_METHOD_FUNCTION_PR(float3x4, SetIdentity, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SwapColumns(int,int)", AS_METHOD_FUNCTION_PR(float3x4, SwapColumns, (int,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SwapRows(int,int)", AS_METHOD_FUNCTION_PR(float3x4, SwapRows, (int,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SetTranslatePart(float,float,float)", AS_METHOD_FUNCTION_PR(float3x4, SetTranslatePart, (float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SetTranslatePart(const float3 &in)", AS_METHOD_FUNCTION_PR(float3x4, SetTranslatePart, (const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SetRotatePartX(float)", AS_METHOD_FUNCTION_PR(float3x4, SetRotatePartX, (float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SetRotatePartY(float)", AS_METHOD_FUNCTION_PR(float3x4, SetRotatePartY, (float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SetRotatePartZ(float)", AS_METHOD_FUNCTION_PR(float3x4, SetRotatePartZ, (float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SetRotatePart(const float3 &in,float)", AS_METHOD_FUNCTION_PR(float3x4, SetRotatePart, (const float3 &,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SetRotatePart(const Quat &in)", AS_METHOD_FUNCTION_PR(float3x4, SetRotatePart, (const Quat &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void SetRotatePart(const float3x3 &in)", AS_METHOD_FUNCTION_PR(float3x4, SetRotatePart, (const float3x3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "float3x4 & operator=(const float3x3 &in)", AS_METHOD_FUNCTION_PR(float3x4, operator=, (const float3x3 &), float3x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "float3x4 & operator=(const Quat &in)", AS_METHOD_FUNCTION_PR(float3x4, operator=, (const Quat &), float3x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "float3x4 & operator=(const float3x4 &in)", AS_METHOD_FUNCTION_PR(float3x4, operator=, (const float3x4 &), float3x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float Determinant() const", AS_METHOD_FUNCTION_PR(float3x4, Determinant, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool Inverse()", AS_METHOD_FUNCTION_PR(float3x4, Inverse, (), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3x4 Inverted() const", AS_METHOD_FUNCTION_PR(float3x4, Inverted, () const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool InverseColOrthogonal()", AS_METHOD_FUNCTION_PR(float3x4, InverseColOrthogonal, (), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool InverseOrthogonalUniformScale()", AS_METHOD_FUNCTION_PR(float3x4, InverseOrthogonalUniformScale, (), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void InverseOrthonormal()", AS_METHOD_FUNCTION_PR(float3x4, InverseOrthonormal, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void Transpose3()", AS_METHOD_FUNCTION_PR(float3x4, Transpose3, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3x4 Transposed3() const", AS_METHOD_FUNCTION_PR(float3x4, Transposed3, () const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool InverseTranspose()", AS_METHOD_FUNCTION_PR(float3x4, InverseTranspose, (), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3x4 InverseTransposed() const", AS_METHOD_FUNCTION_PR(float3x4, InverseTransposed, () const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float Trace() const", AS_METHOD_FUNCTION_PR(float3x4, Trace, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void Orthonormalize(int,int,int)", AS_METHOD_FUNCTION_PR(float3x4, Orthonormalize, (int,int,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void RemoveScale()", AS_METHOD_FUNCTION_PR(float3x4, RemoveScale, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 TransformPos(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3x4, TransformPos, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 TransformPos(float,float,float) const", AS_METHOD_FUNCTION_PR(float3x4, TransformPos, (float,float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 TransformDir(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3x4, TransformDir, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 TransformDir(float,float,float) const", AS_METHOD_FUNCTION_PR(float3x4, TransformDir, (float,float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float4 Transform(const float4 &in) const", AS_METHOD_FUNCTION_PR(float3x4, Transform, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "void BatchTransformPos(float3 *,int) const", AS_METHOD_FUNCTION_PR(float3x4, BatchTransformPos, (float3 *,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "void BatchTransformPos(float3 *,int,int) const", AS_METHOD_FUNCTION_PR(float3x4, BatchTransformPos, (float3 *,int,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "void BatchTransformDir(float3 *,int) const", AS_METHOD_FUNCTION_PR(float3x4, BatchTransformDir, (float3 *,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "void BatchTransformDir(float3 *,int,int) const", AS_METHOD_FUNCTION_PR(float3x4, BatchTransformDir, (float3 *,int,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "void BatchTransform(float4 *,int) const", AS_METHOD_FUNCTION_PR(float3x4, BatchTransform, (float4 *,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "void BatchTransform(float4 *,int,int) const", AS_METHOD_FUNCTION_PR(float3x4, BatchTransform, (float4 *,int,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3x4 opMul(const float3x3 &in) const", AS_METHOD_FUNCTION_PR(float3x4, operator*, (const float3x3 &) const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3x4 opMul(const float3x4 &in) const", AS_METHOD_FUNCTION_PR(float3x4, operator*, (const float3x4 &) const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3x4 opMul(const Quat &in) const", AS_METHOD_FUNCTION_PR(float3x4, operator*, (const Quat &) const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float4 opMul(const float4 &in) const", AS_METHOD_FUNCTION_PR(float3x4, operator*, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3x4 opMul(float) const", AS_METHOD_FUNCTION_PR(float3x4, operator*, (float) const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3x4 opDiv(float) const", AS_METHOD_FUNCTION_PR(float3x4, operator/, (float) const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3x4 opAdd(const float3x4 &in) const", AS_METHOD_FUNCTION_PR(float3x4, operator+, (const float3x4 &) const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3x4 opSub(const float3x4 &in) const", AS_METHOD_FUNCTION_PR(float3x4, operator-, (const float3x4 &) const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3x4 opSub() const", AS_METHOD_FUNCTION_PR(float3x4, operator-, () const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "float3x4 & opMul=(float)", AS_METHOD_FUNCTION_PR(float3x4, operator*=, (float), float3x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "float3x4 & opDiv=(float)", AS_METHOD_FUNCTION_PR(float3x4, operator/=, (float), float3x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "float3x4 & opAdd=(const float3x4 &in)", AS_METHOD_FUNCTION_PR(float3x4, operator+=, (const float3x4 &), float3x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float3x4", "float3x4 & opSub=(const float3x4 &in)", AS_METHOD_FUNCTION_PR(float3x4, operator-=, (const float3x4 &), float3x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool IsFinite() const", AS_METHOD_FUNCTION_PR(float3x4, IsFinite, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool IsIdentity(float) const", AS_METHOD_FUNCTION_PR(float3x4, IsIdentity, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool IsLowerTriangular(float) const", AS_METHOD_FUNCTION_PR(float3x4, IsLowerTriangular, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool IsUpperTriangular(float) const", AS_METHOD_FUNCTION_PR(float3x4, IsUpperTriangular, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool IsInvertible(float) const", AS_METHOD_FUNCTION_PR(float3x4, IsInvertible, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool IsSymmetric(float) const", AS_METHOD_FUNCTION_PR(float3x4, IsSymmetric, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool IsSkewSymmetric(float) const", AS_METHOD_FUNCTION_PR(float3x4, IsSkewSymmetric, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool HasUnitaryScale(float) const", AS_METHOD_FUNCTION_PR(float3x4, HasUnitaryScale, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool HasNegativeScale() const", AS_METHOD_FUNCTION_PR(float3x4, HasNegativeScale, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool HasUniformScale(float) const", AS_METHOD_FUNCTION_PR(float3x4, HasUniformScale, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool IsRowOrthogonal(float) const", AS_METHOD_FUNCTION_PR(float3x4, IsRowOrthogonal, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool IsColOrthogonal(float) const", AS_METHOD_FUNCTION_PR(float3x4, IsColOrthogonal, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool IsColOrthogonal3(float) const", AS_METHOD_FUNCTION_PR(float3x4, IsColOrthogonal3, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool IsOrthonormal(float) const", AS_METHOD_FUNCTION_PR(float3x4, IsOrthonormal, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "bool Equals(const float3x4 &in,float) const", AS_METHOD_FUNCTION_PR(float3x4, Equals, (const float3x4 &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 ToEulerXYX() const", AS_METHOD_FUNCTION_PR(float3x4, ToEulerXYX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 ToEulerXZX() const", AS_METHOD_FUNCTION_PR(float3x4, ToEulerXZX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 ToEulerYXY() const", AS_METHOD_FUNCTION_PR(float3x4, ToEulerYXY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 ToEulerYZY() const", AS_METHOD_FUNCTION_PR(float3x4, ToEulerYZY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 ToEulerZXZ() const", AS_METHOD_FUNCTION_PR(float3x4, ToEulerZXZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 ToEulerZYZ() const", AS_METHOD_FUNCTION_PR(float3x4, ToEulerZYZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 ToEulerXYZ() const", AS_METHOD_FUNCTION_PR(float3x4, ToEulerXYZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 ToEulerXZY() const", AS_METHOD_FUNCTION_PR(float3x4, ToEulerXZY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 ToEulerYXZ() const", AS_METHOD_FUNCTION_PR(float3x4, ToEulerYXZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 ToEulerYZX() const", AS_METHOD_FUNCTION_PR(float3x4, ToEulerYZX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 ToEulerZXY() const", AS_METHOD_FUNCTION_PR(float3x4, ToEulerZXY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 ToEulerZYX() const", AS_METHOD_FUNCTION_PR(float3x4, ToEulerZYX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 ExtractScale() const", AS_METHOD_FUNCTION_PR(float3x4, ExtractScale, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "void Decompose(float3 &out,Quat &out,float3 &out) const", AS_METHOD_FUNCTION_PR(float3x4, Decompose, (float3 &,Quat &,float3 &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("float3x4", "void Decompose(float3 &,float3x3 &,float3 &) const", AS_METHOD_FUNCTION_PR(float3x4, Decompose, (float3 &,float3x3 &,float3 &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("float3x4", "void Decompose(float3 &,float3x4 &,float3 &) const", AS_METHOD_FUNCTION_PR(float3x4, Decompose, (float3 &,float3x4 &,float3 &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3x4 Mul(const float3x3 &in) const", AS_METHOD_FUNCTION_PR(float3x4, Mul, (const float3x3 &) const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3x4 Mul(const float3x4 &in) const", AS_METHOD_FUNCTION_PR(float3x4, Mul, (const float3x4 &) const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float4x4 Mul(const float4x4 &in) const", AS_METHOD_FUNCTION_PR(float3x4, Mul, (const float4x4 &) const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3x4 Mul(const Quat &in) const", AS_METHOD_FUNCTION_PR(float3x4, Mul, (const Quat &) const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 MulPos(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3x4, MulPos, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float3 MulDir(const float3 &in) const", AS_METHOD_FUNCTION_PR(float3x4, MulDir, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float3x4", "float4 Mul(const float4 &in) const", AS_METHOD_FUNCTION_PR(float3x4, Mul, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(


// /* Exposing array types as fields are not supported by angelscript. */ 	r = engine->RegisterObjectProperty("float4x4", "float v", asOFFSET(float4x4, v)); assert(r >= 0);
// /* const float4x4 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float4x4", "const float4x4 zero", asOFFSET(float4x4, zero)); assert(r >= 0);
// /* const float4x4 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float4x4", "const float4x4 identity", asOFFSET(float4x4, identity)); assert(r >= 0);
// /* const float4x4 is not known to angelscript. */ 	r = engine->RegisterObjectProperty("float4x4", "const float4x4 nan", asOFFSET(float4x4, nan)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float4x4", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(float4x4_ctor_, float4x4, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float4x4", asBEHAVE_CONSTRUCT, "void f(const float4x4 &in)", AS_CONSTRUCTOR(float4x4_ctor_const_float4x4_ref, float4x4, (const float4x4 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float4x4", asBEHAVE_CONSTRUCT, "void f(float,float,float,float,float,float,float,float,float,float,float,float,float,float,float,float)", AS_CONSTRUCTOR(float4x4_ctor_float_float_float_float_float_float_float_float_float_float_float_float_float_float_float_float, float4x4, (float,float,float,float,float,float,float,float,float,float,float,float,float,float,float,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float4x4", asBEHAVE_CONSTRUCT, "void f(const float3x3 &in)", AS_CONSTRUCTOR(float4x4_ctor_const_float3x3_ref, float4x4, (const float3x3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float4x4", asBEHAVE_CONSTRUCT, "void f(const float3x4 &in)", AS_CONSTRUCTOR(float4x4_ctor_const_float3x4_ref, float4x4, (const float3x4 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float4x4", asBEHAVE_CONSTRUCT, "void f(const float4 &in,const float4 &in,const float4 &in,const float4 &in)", AS_CONSTRUCTOR(float4x4_ctor_const_float4_ref_const_float4_ref_const_float4_ref_const_float4_ref, float4x4, (const float4 &,const float4 &,const float4 &,const float4 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float4x4", asBEHAVE_CONSTRUCT, "void f(const Quat &in)", AS_CONSTRUCTOR(float4x4_ctor_const_Quat_ref, float4x4, (const Quat &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("float4x4", asBEHAVE_CONSTRUCT, "void f(const Quat &in,const float3 &in)", AS_CONSTRUCTOR(float4x4_ctor_const_Quat_ref_const_float3_ref, float4x4, (const Quat &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 GetScale() const", AS_METHOD_FUNCTION_PR(float4x4, GetScale, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 ComplementaryProjection() const", AS_METHOD_FUNCTION_PR(float4x4, ComplementaryProjection, () const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(MatrixProxy < Cols > & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "MatrixProxy < Cols > & operator[](int)", AS_METHOD_FUNCTION_PR(float4x4, operator[], (int), MatrixProxy < Cols > &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const MatrixProxy < Cols > & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "const MatrixProxy < Cols > & operator[](int) const", AS_METHOD_FUNCTION_PR(float4x4, operator[], (int) const, const MatrixProxy < Cols > &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "float & At(int,int)", AS_METHOD_FUNCTION_PR(float4x4, At, (int,int), float &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "CONST_WIN32 float At(int,int) const", AS_METHOD_FUNCTION_PR(float4x4, At, (int,int) const, CONST_WIN32 float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "float4 & Row(int)", AS_METHOD_FUNCTION_PR(float4x4, Row, (int), float4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "const float4 & Row(int) const", AS_METHOD_FUNCTION_PR(float4x4, Row, (int) const, const float4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "float3 & Row3(int)", AS_METHOD_FUNCTION_PR(float4x4, Row3, (int), float3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float3 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "const float3 & Row3(int) const", AS_METHOD_FUNCTION_PR(float4x4, Row3, (int) const, const float3 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float4 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "CONST_WIN32 float4 Col(int) const", AS_METHOD_FUNCTION_PR(float4x4, Col, (int) const, CONST_WIN32 float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float3 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "CONST_WIN32 float3 Col3(int) const", AS_METHOD_FUNCTION_PR(float4x4, Col3, (int) const, CONST_WIN32 float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float4 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "CONST_WIN32 float4 Diagonal() const", AS_METHOD_FUNCTION_PR(float4x4, Diagonal, () const, CONST_WIN32 float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float3 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "CONST_WIN32 float3 Diagonal3() const", AS_METHOD_FUNCTION_PR(float4x4, Diagonal3, () const, CONST_WIN32 float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void ScaleRow3(int,float)", AS_METHOD_FUNCTION_PR(float4x4, ScaleRow3, (int,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void ScaleRow(int,float)", AS_METHOD_FUNCTION_PR(float4x4, ScaleRow, (int,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void ScaleCol3(int,float)", AS_METHOD_FUNCTION_PR(float4x4, ScaleCol3, (int,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void ScaleCol(int,float)", AS_METHOD_FUNCTION_PR(float4x4, ScaleCol, (int,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float3x3 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "const float3x3 Float3x3Part() const", AS_METHOD_FUNCTION_PR(float4x4, Float3x3Part, () const, const float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "float3x4 & Float3x4Part()", AS_METHOD_FUNCTION_PR(float4x4, Float3x4Part, (), float3x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float3x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "const float3x4 & Float3x4Part() const", AS_METHOD_FUNCTION_PR(float4x4, Float3x4Part, () const, const float3x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float3 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "CONST_WIN32 float3 TranslatePart() const", AS_METHOD_FUNCTION_PR(float4x4, TranslatePart, () const, CONST_WIN32 float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(CONST_WIN32 float3x3 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "CONST_WIN32 float3x3 RotatePart() const", AS_METHOD_FUNCTION_PR(float4x4, RotatePart, () const, CONST_WIN32 float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 WorldX() const", AS_METHOD_FUNCTION_PR(float4x4, WorldX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 WorldY() const", AS_METHOD_FUNCTION_PR(float4x4, WorldY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 WorldZ() const", AS_METHOD_FUNCTION_PR(float4x4, WorldZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "float * ptr()", AS_METHOD_FUNCTION_PR(float4x4, ptr, (), float *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "const float * ptr() const", AS_METHOD_FUNCTION_PR(float4x4, ptr, () const, const float *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetRow3(int,const float3 &in)", AS_METHOD_FUNCTION_PR(float4x4, SetRow3, (int,const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "void SetRow3(int,const float *)", AS_METHOD_FUNCTION_PR(float4x4, SetRow3, (int,const float *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetRow3(int,float,float,float)", AS_METHOD_FUNCTION_PR(float4x4, SetRow3, (int,float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetRow(int,const float3 &in,float)", AS_METHOD_FUNCTION_PR(float4x4, SetRow, (int,const float3 &,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetRow(int,const float4 &in)", AS_METHOD_FUNCTION_PR(float4x4, SetRow, (int,const float4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "void SetRow(int,const float *)", AS_METHOD_FUNCTION_PR(float4x4, SetRow, (int,const float *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetRow(int,float,float,float,float)", AS_METHOD_FUNCTION_PR(float4x4, SetRow, (int,float,float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetCol3(int,const float3 &in)", AS_METHOD_FUNCTION_PR(float4x4, SetCol3, (int,const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "void SetCol3(int,const float *)", AS_METHOD_FUNCTION_PR(float4x4, SetCol3, (int,const float *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetCol3(int,float,float,float)", AS_METHOD_FUNCTION_PR(float4x4, SetCol3, (int,float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetCol(int,const float3 &in,float)", AS_METHOD_FUNCTION_PR(float4x4, SetCol, (int,const float3 &,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetCol(int,const float4 &in)", AS_METHOD_FUNCTION_PR(float4x4, SetCol, (int,const float4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "void SetCol(int,const float *)", AS_METHOD_FUNCTION_PR(float4x4, SetCol, (int,const float *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetCol(int,float,float,float,float)", AS_METHOD_FUNCTION_PR(float4x4, SetCol, (int,float,float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void Set(float,float,float,float,float,float,float,float,float,float,float,float,float,float,float,float)", AS_METHOD_FUNCTION_PR(float4x4, Set, (float,float,float,float,float,float,float,float,float,float,float,float,float,float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void Set(const float4x4 &in)", AS_METHOD_FUNCTION_PR(float4x4, Set, (const float4x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "void Set(const float *)", AS_METHOD_FUNCTION_PR(float4x4, Set, (const float *), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void Set(int,int,float)", AS_METHOD_FUNCTION_PR(float4x4, Set, (int,int,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void Set3x3Part(const float3x3 &in)", AS_METHOD_FUNCTION_PR(float4x4, Set3x3Part, (const float3x3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void Set3x4Part(const float3x4 &in)", AS_METHOD_FUNCTION_PR(float4x4, Set3x4Part, (const float3x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetIdentity()", AS_METHOD_FUNCTION_PR(float4x4, SetIdentity, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SwapColumns(int,int)", AS_METHOD_FUNCTION_PR(float4x4, SwapColumns, (int,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SwapColumns3(int,int)", AS_METHOD_FUNCTION_PR(float4x4, SwapColumns3, (int,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SwapRows(int,int)", AS_METHOD_FUNCTION_PR(float4x4, SwapRows, (int,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SwapRows3(int,int)", AS_METHOD_FUNCTION_PR(float4x4, SwapRows3, (int,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetTranslatePart(float,float,float)", AS_METHOD_FUNCTION_PR(float4x4, SetTranslatePart, (float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetTranslatePart(const float3 &in)", AS_METHOD_FUNCTION_PR(float4x4, SetTranslatePart, (const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetRotatePartX(float)", AS_METHOD_FUNCTION_PR(float4x4, SetRotatePartX, (float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetRotatePartY(float)", AS_METHOD_FUNCTION_PR(float4x4, SetRotatePartY, (float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetRotatePartZ(float)", AS_METHOD_FUNCTION_PR(float4x4, SetRotatePartZ, (float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetRotatePart(const float3 &in,float)", AS_METHOD_FUNCTION_PR(float4x4, SetRotatePart, (const float3 &,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetRotatePart(const Quat &in)", AS_METHOD_FUNCTION_PR(float4x4, SetRotatePart, (const Quat &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void SetRotatePart(const float3x3 &in)", AS_METHOD_FUNCTION_PR(float4x4, SetRotatePart, (const float3x3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "float4x4 & operator=(const float3x3 &in)", AS_METHOD_FUNCTION_PR(float4x4, operator=, (const float3x3 &), float4x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "float4x4 & operator=(const float3x4 &in)", AS_METHOD_FUNCTION_PR(float4x4, operator=, (const float3x4 &), float4x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "float4x4 & operator=(const float4x4 &in)", AS_METHOD_FUNCTION_PR(float4x4, operator=, (const float4x4 &), float4x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "float4x4 & operator=(const Quat &in)", AS_METHOD_FUNCTION_PR(float4x4, operator=, (const Quat &), float4x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float Determinant3() const", AS_METHOD_FUNCTION_PR(float4x4, Determinant3, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float Determinant4() const", AS_METHOD_FUNCTION_PR(float4x4, Determinant4, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3x3 SubMatrix(int,int) const", AS_METHOD_FUNCTION_PR(float4x4, SubMatrix, (int,int) const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float Minor(int,int) const", AS_METHOD_FUNCTION_PR(float4x4, Minor, (int,int) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 Adjugate() const", AS_METHOD_FUNCTION_PR(float4x4, Adjugate, () const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("float4x4", "bool CholeskyDecompose(float4x4 &) const", AS_METHOD_FUNCTION_PR(float4x4, CholeskyDecompose, (float4x4 &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("float4x4", "bool LUDecompose(float4x4 &,float4x4 &) const", AS_METHOD_FUNCTION_PR(float4x4, LUDecompose, (float4x4 &,float4x4 &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool Inverse()", AS_METHOD_FUNCTION_PR(float4x4, Inverse, (), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 Inverted() const", AS_METHOD_FUNCTION_PR(float4x4, Inverted, () const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool InverseColOrthogonal()", AS_METHOD_FUNCTION_PR(float4x4, InverseColOrthogonal, (), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool InverseOrthogonalUniformScale()", AS_METHOD_FUNCTION_PR(float4x4, InverseOrthogonalUniformScale, (), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void InverseOrthonormal()", AS_METHOD_FUNCTION_PR(float4x4, InverseOrthonormal, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void Transpose()", AS_METHOD_FUNCTION_PR(float4x4, Transpose, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 Transposed() const", AS_METHOD_FUNCTION_PR(float4x4, Transposed, () const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool InverseTranspose()", AS_METHOD_FUNCTION_PR(float4x4, InverseTranspose, (), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 InverseTransposed() const", AS_METHOD_FUNCTION_PR(float4x4, InverseTransposed, () const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float Trace() const", AS_METHOD_FUNCTION_PR(float4x4, Trace, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void Orthogonalize3(int,int,int)", AS_METHOD_FUNCTION_PR(float4x4, Orthogonalize3, (int,int,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void Orthogonalize3()", AS_METHOD_FUNCTION_PR(float4x4, Orthogonalize3, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void Orthonormalize3(int,int,int)", AS_METHOD_FUNCTION_PR(float4x4, Orthonormalize3, (int,int,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void Orthonormalize3()", AS_METHOD_FUNCTION_PR(float4x4, Orthonormalize3, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void RemoveScale()", AS_METHOD_FUNCTION_PR(float4x4, RemoveScale, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void Pivot()", AS_METHOD_FUNCTION_PR(float4x4, Pivot, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 TransformPos(const float3 &in) const", AS_METHOD_FUNCTION_PR(float4x4, TransformPos, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 TransformPos(float,float,float) const", AS_METHOD_FUNCTION_PR(float4x4, TransformPos, (float,float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 TransformDir(const float3 &in) const", AS_METHOD_FUNCTION_PR(float4x4, TransformDir, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 TransformDir(float,float,float) const", AS_METHOD_FUNCTION_PR(float4x4, TransformDir, (float,float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4 Transform(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4x4, Transform, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "void TransformPos(float3 *,int) const", AS_METHOD_FUNCTION_PR(float4x4, TransformPos, (float3 *,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "void TransformPos(float3 *,int,int) const", AS_METHOD_FUNCTION_PR(float4x4, TransformPos, (float3 *,int,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "void TransformDir(float3 *,int) const", AS_METHOD_FUNCTION_PR(float4x4, TransformDir, (float3 *,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "void TransformDir(float3 *,int,int) const", AS_METHOD_FUNCTION_PR(float4x4, TransformDir, (float3 *,int,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "void Transform(float4 *,int) const", AS_METHOD_FUNCTION_PR(float4x4, Transform, (float4 *,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "void Transform(float4 *,int,int) const", AS_METHOD_FUNCTION_PR(float4x4, Transform, (float4 *,int,int) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 opMul(const float3x3 &in) const", AS_METHOD_FUNCTION_PR(float4x4, operator*, (const float3x3 &) const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 opMul(const float3x4 &in) const", AS_METHOD_FUNCTION_PR(float4x4, operator*, (const float3x4 &) const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 opMul(const float4x4 &in) const", AS_METHOD_FUNCTION_PR(float4x4, operator*, (const float4x4 &) const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 opMul(const Quat &in) const", AS_METHOD_FUNCTION_PR(float4x4, operator*, (const Quat &) const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4 opMul(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4x4, operator*, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 opMul(float) const", AS_METHOD_FUNCTION_PR(float4x4, operator*, (float) const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 opDiv(float) const", AS_METHOD_FUNCTION_PR(float4x4, operator/, (float) const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 opAdd(const float4x4 &in) const", AS_METHOD_FUNCTION_PR(float4x4, operator+, (const float4x4 &) const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 opSub(const float4x4 &in) const", AS_METHOD_FUNCTION_PR(float4x4, operator-, (const float4x4 &) const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 opSub() const", AS_METHOD_FUNCTION_PR(float4x4, operator-, () const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "float4x4 & opMul=(float)", AS_METHOD_FUNCTION_PR(float4x4, operator*=, (float), float4x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "float4x4 & opDiv=(float)", AS_METHOD_FUNCTION_PR(float4x4, operator/=, (float), float4x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "float4x4 & opAdd=(const float4x4 &in)", AS_METHOD_FUNCTION_PR(float4x4, operator+=, (const float4x4 &), float4x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float4x4 & is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("float4x4", "float4x4 & opSub=(const float4x4 &in)", AS_METHOD_FUNCTION_PR(float4x4, operator-=, (const float4x4 &), float4x4 &), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool IsFinite() const", AS_METHOD_FUNCTION_PR(float4x4, IsFinite, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool IsIdentity(float) const", AS_METHOD_FUNCTION_PR(float4x4, IsIdentity, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool IsLowerTriangular(float) const", AS_METHOD_FUNCTION_PR(float4x4, IsLowerTriangular, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool IsUpperTriangular(float) const", AS_METHOD_FUNCTION_PR(float4x4, IsUpperTriangular, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool IsInvertible(float) const", AS_METHOD_FUNCTION_PR(float4x4, IsInvertible, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool IsSymmetric(float) const", AS_METHOD_FUNCTION_PR(float4x4, IsSymmetric, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool IsSkewSymmetric(float) const", AS_METHOD_FUNCTION_PR(float4x4, IsSkewSymmetric, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool IsIdempotent(float) const", AS_METHOD_FUNCTION_PR(float4x4, IsIdempotent, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool HasUnitaryScale(float) const", AS_METHOD_FUNCTION_PR(float4x4, HasUnitaryScale, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool HasNegativeScale() const", AS_METHOD_FUNCTION_PR(float4x4, HasNegativeScale, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool HasUniformScale(float) const", AS_METHOD_FUNCTION_PR(float4x4, HasUniformScale, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool IsRowOrthogonal3(float) const", AS_METHOD_FUNCTION_PR(float4x4, IsRowOrthogonal3, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool IsColOrthogonal3(float) const", AS_METHOD_FUNCTION_PR(float4x4, IsColOrthogonal3, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool IsOrthonormal3(float) const", AS_METHOD_FUNCTION_PR(float4x4, IsOrthonormal3, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool Equals(const float4x4 &in,float) const", AS_METHOD_FUNCTION_PR(float4x4, Equals, (const float4x4 &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "bool ContainsProjection(float) const", AS_METHOD_FUNCTION_PR(float4x4, ContainsProjection, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 ToEulerXYX() const", AS_METHOD_FUNCTION_PR(float4x4, ToEulerXYX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 ToEulerXZX() const", AS_METHOD_FUNCTION_PR(float4x4, ToEulerXZX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 ToEulerYXY() const", AS_METHOD_FUNCTION_PR(float4x4, ToEulerYXY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 ToEulerYZY() const", AS_METHOD_FUNCTION_PR(float4x4, ToEulerYZY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 ToEulerZXZ() const", AS_METHOD_FUNCTION_PR(float4x4, ToEulerZXZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 ToEulerZYZ() const", AS_METHOD_FUNCTION_PR(float4x4, ToEulerZYZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 ToEulerXYZ() const", AS_METHOD_FUNCTION_PR(float4x4, ToEulerXYZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 ToEulerXZY() const", AS_METHOD_FUNCTION_PR(float4x4, ToEulerXZY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 ToEulerYXZ() const", AS_METHOD_FUNCTION_PR(float4x4, ToEulerYXZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 ToEulerYZX() const", AS_METHOD_FUNCTION_PR(float4x4, ToEulerYZX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 ToEulerZXY() const", AS_METHOD_FUNCTION_PR(float4x4, ToEulerZXY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 ToEulerZYX() const", AS_METHOD_FUNCTION_PR(float4x4, ToEulerZYX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 ExtractScale() const", AS_METHOD_FUNCTION_PR(float4x4, ExtractScale, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "void Decompose(float3 &out,Quat &out,float3 &out) const", AS_METHOD_FUNCTION_PR(float4x4, Decompose, (float3 &,Quat &,float3 &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("float4x4", "void Decompose(float3 &,float3x3 &,float3 &) const", AS_METHOD_FUNCTION_PR(float4x4, Decompose, (float3 &,float3x3 &,float3 &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("float4x4", "void Decompose(float3 &,float3x4 &,float3 &) const", AS_METHOD_FUNCTION_PR(float4x4, Decompose, (float3 &,float3x4 &,float3 &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("float4x4", "void Decompose(float3 &,float4x4 &,float3 &) const", AS_METHOD_FUNCTION_PR(float4x4, Decompose, (float3 &,float4x4 &,float3 &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 Mul(const float3x3 &in) const", AS_METHOD_FUNCTION_PR(float4x4, Mul, (const float3x3 &) const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 Mul(const float3x4 &in) const", AS_METHOD_FUNCTION_PR(float4x4, Mul, (const float3x4 &) const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 Mul(const float4x4 &in) const", AS_METHOD_FUNCTION_PR(float4x4, Mul, (const float4x4 &) const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4x4 Mul(const Quat &in) const", AS_METHOD_FUNCTION_PR(float4x4, Mul, (const Quat &) const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 MulPos(const float3 &in) const", AS_METHOD_FUNCTION_PR(float4x4, MulPos, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float3 MulDir(const float3 &in) const", AS_METHOD_FUNCTION_PR(float4x4, MulDir, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("float4x4", "float4 Mul(const float4 &in) const", AS_METHOD_FUNCTION_PR(float4x4, Mul, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(


	r = engine->RegisterObjectProperty("Quat", "float x", asOFFSET(Quat, x)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Quat", "float y", asOFFSET(Quat, y)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Quat", "float z", asOFFSET(Quat, z)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Quat", "float w", asOFFSET(Quat, w)); assert(r >= 0);
// /* const Quat is not known to angelscript. */ 	r = engine->RegisterObjectProperty("Quat", "const Quat identity", asOFFSET(Quat, identity)); assert(r >= 0);
// /* const Quat is not known to angelscript. */ 	r = engine->RegisterObjectProperty("Quat", "const Quat nan", asOFFSET(Quat, nan)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Quat", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(Quat_ctor_, Quat, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Quat", asBEHAVE_CONSTRUCT, "void f(const Quat &in)", AS_CONSTRUCTOR(Quat_ctor_const_Quat_ref, Quat, (const Quat &)), AS_CTOR_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectBehaviour("Quat", asBEHAVE_CONSTRUCT, "void f(const float *)", AS_CONSTRUCTOR(Quat_ctor_const_float_ptr, Quat, (const float *)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Quat", asBEHAVE_CONSTRUCT, "void f(const float3x3 &in)", AS_CONSTRUCTOR(Quat_ctor_const_float3x3_ref, Quat, (const float3x3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Quat", asBEHAVE_CONSTRUCT, "void f(const float3x4 &in)", AS_CONSTRUCTOR(Quat_ctor_const_float3x4_ref, Quat, (const float3x4 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Quat", asBEHAVE_CONSTRUCT, "void f(const float4x4 &in)", AS_CONSTRUCTOR(Quat_ctor_const_float4x4_ref, Quat, (const float4x4 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Quat", asBEHAVE_CONSTRUCT, "void f(float,float,float,float)", AS_CONSTRUCTOR(Quat_ctor_float_float_float_float, Quat, (float,float,float,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Quat", asBEHAVE_CONSTRUCT, "void f(const float3 &in,float)", AS_CONSTRUCTOR(Quat_ctor_const_float3_ref_float, Quat, (const float3 &,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 WorldX() const", AS_METHOD_FUNCTION_PR(Quat, WorldX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 WorldY() const", AS_METHOD_FUNCTION_PR(Quat, WorldY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 WorldZ() const", AS_METHOD_FUNCTION_PR(Quat, WorldZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 Axis() const", AS_METHOD_FUNCTION_PR(Quat, Axis, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float Angle() const", AS_METHOD_FUNCTION_PR(Quat, Angle, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float Dot(const Quat &in) const", AS_METHOD_FUNCTION_PR(Quat, Dot, (const Quat &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float LengthSq() const", AS_METHOD_FUNCTION_PR(Quat, LengthSq, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float Length() const", AS_METHOD_FUNCTION_PR(Quat, Length, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float Normalize()", AS_METHOD_FUNCTION_PR(Quat, Normalize, (), float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "Quat Normalized() const", AS_METHOD_FUNCTION_PR(Quat, Normalized, () const, Quat), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "bool IsNormalized(float) const", AS_METHOD_FUNCTION_PR(Quat, IsNormalized, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "bool IsInvertible(float) const", AS_METHOD_FUNCTION_PR(Quat, IsInvertible, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "bool IsFinite() const", AS_METHOD_FUNCTION_PR(Quat, IsFinite, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "bool Equals(const Quat &in,float) const", AS_METHOD_FUNCTION_PR(Quat, Equals, (const Quat &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Quat", "float * ptr()", AS_METHOD_FUNCTION_PR(Quat, ptr, (), float *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Quat", "const float * ptr() const", AS_METHOD_FUNCTION_PR(Quat, ptr, () const, const float *), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "void Inverse()", AS_METHOD_FUNCTION_PR(Quat, Inverse, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "Quat Inverted() const", AS_METHOD_FUNCTION_PR(Quat, Inverted, () const, Quat), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float InverseAndNormalize()", AS_METHOD_FUNCTION_PR(Quat, InverseAndNormalize, (), float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "void Conjugate()", AS_METHOD_FUNCTION_PR(Quat, Conjugate, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "Quat Conjugated() const", AS_METHOD_FUNCTION_PR(Quat, Conjugated, () const, Quat), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 Transform(float,float,float) const", AS_METHOD_FUNCTION_PR(Quat, Transform, (float,float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 Transform(const float3 &in) const", AS_METHOD_FUNCTION_PR(Quat, Transform, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float4 Transform(const float4 &in) const", AS_METHOD_FUNCTION_PR(Quat, Transform, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "Quat Lerp(const Quat &in,float) const", AS_METHOD_FUNCTION_PR(Quat, Lerp, (const Quat &,float) const, Quat), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "Quat Slerp(const Quat &in,float) const", AS_METHOD_FUNCTION_PR(Quat, Slerp, (const Quat &,float) const, Quat), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float AngleBetween(const Quat &in) const", AS_METHOD_FUNCTION_PR(Quat, AngleBetween, (const Quat &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 AxisFromTo(const Quat &in) const", AS_METHOD_FUNCTION_PR(Quat, AxisFromTo, (const Quat &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "void ToAxisAngle(float3 &out,float &out) const", AS_METHOD_FUNCTION_PR(Quat, ToAxisAngle, (float3 &,float &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "void SetFromAxisAngle(const float3 &in,float)", AS_METHOD_FUNCTION_PR(Quat, SetFromAxisAngle, (const float3 &,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "void Set(const float3x3 &in)", AS_METHOD_FUNCTION_PR(Quat, Set, (const float3x3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "void Set(const float3x4 &in)", AS_METHOD_FUNCTION_PR(Quat, Set, (const float3x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "void Set(const float4x4 &in)", AS_METHOD_FUNCTION_PR(Quat, Set, (const float4x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "void Set(float,float,float,float)", AS_METHOD_FUNCTION_PR(Quat, Set, (float,float,float,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 ToEulerXYX() const", AS_METHOD_FUNCTION_PR(Quat, ToEulerXYX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 ToEulerXZX() const", AS_METHOD_FUNCTION_PR(Quat, ToEulerXZX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 ToEulerYXY() const", AS_METHOD_FUNCTION_PR(Quat, ToEulerYXY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 ToEulerYZY() const", AS_METHOD_FUNCTION_PR(Quat, ToEulerYZY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 ToEulerZXZ() const", AS_METHOD_FUNCTION_PR(Quat, ToEulerZXZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 ToEulerZYZ() const", AS_METHOD_FUNCTION_PR(Quat, ToEulerZYZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 ToEulerXYZ() const", AS_METHOD_FUNCTION_PR(Quat, ToEulerXYZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 ToEulerXZY() const", AS_METHOD_FUNCTION_PR(Quat, ToEulerXZY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 ToEulerYXZ() const", AS_METHOD_FUNCTION_PR(Quat, ToEulerYXZ, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 ToEulerYZX() const", AS_METHOD_FUNCTION_PR(Quat, ToEulerYZX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 ToEulerZXY() const", AS_METHOD_FUNCTION_PR(Quat, ToEulerZXY, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 ToEulerZYX() const", AS_METHOD_FUNCTION_PR(Quat, ToEulerZYX, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3x3 ToFloat3x3() const", AS_METHOD_FUNCTION_PR(Quat, ToFloat3x3, () const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3x4 ToFloat3x4() const", AS_METHOD_FUNCTION_PR(Quat, ToFloat3x4, () const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float4x4 ToFloat4x4() const", AS_METHOD_FUNCTION_PR(Quat, ToFloat4x4, () const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "Quat opMul(const Quat &in) const", AS_METHOD_FUNCTION_PR(Quat, operator*, (const Quat &) const, Quat), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 opMul(const float3 &in) const", AS_METHOD_FUNCTION_PR(Quat, operator*, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "Quat opDiv(const Quat &in) const", AS_METHOD_FUNCTION_PR(Quat, operator/, (const Quat &) const, Quat), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "Quat Mul(const Quat &in) const", AS_METHOD_FUNCTION_PR(Quat, Mul, (const Quat &) const, Quat), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "Quat Mul(const float3x3 &in) const", AS_METHOD_FUNCTION_PR(Quat, Mul, (const float3x3 &) const, Quat), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float3 Mul(const float3 &in) const", AS_METHOD_FUNCTION_PR(Quat, Mul, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Quat", "float4 Mul(const float4 &in) const", AS_METHOD_FUNCTION_PR(Quat, Mul, (const float4 &) const, float4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(// /*(const char * is not known to angelscript)*/ 	//.classmethod(


	r = engine->RegisterObjectProperty("TranslateOp", "float x", asOFFSET(TranslateOp, x)); assert(r >= 0);
	r = engine->RegisterObjectProperty("TranslateOp", "float y", asOFFSET(TranslateOp, y)); assert(r >= 0);
	r = engine->RegisterObjectProperty("TranslateOp", "float z", asOFFSET(TranslateOp, z)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("TranslateOp", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(TranslateOp_ctor_, TranslateOp, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("TranslateOp", asBEHAVE_CONSTRUCT, "void f(const float3 &in)", AS_CONSTRUCTOR(TranslateOp_ctor_const_float3_ref, TranslateOp, (const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("TranslateOp", asBEHAVE_CONSTRUCT, "void f(float,float,float)", AS_CONSTRUCTOR(TranslateOp_ctor_float_float_float, TranslateOp, (float,float,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("TranslateOp", "float3 Offset() const", AS_METHOD_FUNCTION_PR(TranslateOp, Offset, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("TranslateOp", "float3x4 ToFloat3x4() const", AS_METHOD_FUNCTION_PR(TranslateOp, ToFloat3x4, () const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("TranslateOp", "float4x4 ToFloat4x4() const", AS_METHOD_FUNCTION_PR(TranslateOp, ToFloat4x4, () const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Implicit conversion operators are not supported)*/ 	r = engine->RegisterObjectMethod("TranslateOp", " operator float3x4() const", AS_METHOD_FUNCTION_PR(TranslateOp, operator float3x4, () const, ), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Implicit conversion operators are not supported)*/ 	r = engine->RegisterObjectMethod("TranslateOp", " operator float4x4() const", AS_METHOD_FUNCTION_PR(TranslateOp, operator float4x4, () const, ), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);



	r = engine->RegisterObjectProperty("ScaleOp", "float x", asOFFSET(ScaleOp, x)); assert(r >= 0);
	r = engine->RegisterObjectProperty("ScaleOp", "float y", asOFFSET(ScaleOp, y)); assert(r >= 0);
	r = engine->RegisterObjectProperty("ScaleOp", "float z", asOFFSET(ScaleOp, z)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("ScaleOp", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(ScaleOp_ctor_, ScaleOp, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("ScaleOp", asBEHAVE_CONSTRUCT, "void f(const float3 &in)", AS_CONSTRUCTOR(ScaleOp_ctor_const_float3_ref, ScaleOp, (const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("ScaleOp", asBEHAVE_CONSTRUCT, "void f(float,float,float)", AS_CONSTRUCTOR(ScaleOp_ctor_float_float_float, ScaleOp, (float,float,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("ScaleOp", "float3 Offset() const", AS_METHOD_FUNCTION_PR(ScaleOp, Offset, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Implicit conversion operators are not supported)*/ 	r = engine->RegisterObjectMethod("ScaleOp", " operator float3x3() const", AS_METHOD_FUNCTION_PR(ScaleOp, operator float3x3, () const, ), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Implicit conversion operators are not supported)*/ 	r = engine->RegisterObjectMethod("ScaleOp", " operator float3x4() const", AS_METHOD_FUNCTION_PR(ScaleOp, operator float3x4, () const, ), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Implicit conversion operators are not supported)*/ 	r = engine->RegisterObjectMethod("ScaleOp", " operator float4x4() const", AS_METHOD_FUNCTION_PR(ScaleOp, operator float4x4, () const, ), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("ScaleOp", "float3x3 ToFloat3x3() const", AS_METHOD_FUNCTION_PR(ScaleOp, ToFloat3x3, () const, float3x3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("ScaleOp", "float3x4 ToFloat3x4() const", AS_METHOD_FUNCTION_PR(ScaleOp, ToFloat3x4, () const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("ScaleOp", "float4x4 ToFloat4x4() const", AS_METHOD_FUNCTION_PR(ScaleOp, ToFloat4x4, () const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);



	r = engine->RegisterObjectProperty("AABB", "float3 minPoint", asOFFSET(AABB, minPoint)); assert(r >= 0);
	r = engine->RegisterObjectProperty("AABB", "float3 maxPoint", asOFFSET(AABB, maxPoint)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("AABB", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(AABB_ctor_, AABB, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("AABB", asBEHAVE_CONSTRUCT, "void f(const float3 &in,const float3 &in)", AS_CONSTRUCTOR(AABB_ctor_const_float3_ref_const_float3_ref, AABB, (const float3 &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("AABB", asBEHAVE_CONSTRUCT, "void f(const OBB &in)", AS_CONSTRUCTOR(AABB_ctor_const_OBB_ref, AABB, (const OBB &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("AABB", asBEHAVE_CONSTRUCT, "void f(const Sphere &in)", AS_CONSTRUCTOR(AABB_ctor_const_Sphere_ref, AABB, (const Sphere &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float MinX() const", AS_METHOD_FUNCTION_PR(AABB, MinX, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float MinY() const", AS_METHOD_FUNCTION_PR(AABB, MinY, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float MinZ() const", AS_METHOD_FUNCTION_PR(AABB, MinZ, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float MaxX() const", AS_METHOD_FUNCTION_PR(AABB, MaxX, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float MaxY() const", AS_METHOD_FUNCTION_PR(AABB, MaxY, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float MaxZ() const", AS_METHOD_FUNCTION_PR(AABB, MaxZ, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void SetNegativeInfinity()", AS_METHOD_FUNCTION_PR(AABB, SetNegativeInfinity, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void SetFromCenterAndSize(const float3 &in,const float3 &in)", AS_METHOD_FUNCTION_PR(AABB, SetFromCenterAndSize, (const float3 &,const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void SetFrom(const OBB &in)", AS_METHOD_FUNCTION_PR(AABB, SetFrom, (const OBB &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void SetFrom(const Sphere &in)", AS_METHOD_FUNCTION_PR(AABB, SetFrom, (const Sphere &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "void SetFrom(const float3 *,int)", AS_METHOD_FUNCTION_PR(AABB, SetFrom, (const float3 *,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "Polyhedron ToPolyhedron() const", AS_METHOD_FUNCTION_PR(AABB, ToPolyhedron, () const, Polyhedron), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "OBB ToOBB() const", AS_METHOD_FUNCTION_PR(AABB, ToOBB, () const, OBB), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "Sphere MinimalEnclosingSphere() const", AS_METHOD_FUNCTION_PR(AABB, MinimalEnclosingSphere, () const, Sphere), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "Sphere MaximalContainedSphere() const", AS_METHOD_FUNCTION_PR(AABB, MaximalContainedSphere, () const, Sphere), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool IsFinite() const", AS_METHOD_FUNCTION_PR(AABB, IsFinite, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool IsDegenerate() const", AS_METHOD_FUNCTION_PR(AABB, IsDegenerate, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float3 CenterPoint() const", AS_METHOD_FUNCTION_PR(AABB, CenterPoint, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float3 Centroid() const", AS_METHOD_FUNCTION_PR(AABB, Centroid, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float3 PointInside(float,float,float) const", AS_METHOD_FUNCTION_PR(AABB, PointInside, (float,float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "LineSegment Edge(int) const", AS_METHOD_FUNCTION_PR(AABB, Edge, (int) const, LineSegment), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float3 CornerPoint(int) const", AS_METHOD_FUNCTION_PR(AABB, CornerPoint, (int) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float3 ExtremePoint(const float3 &in) const", AS_METHOD_FUNCTION_PR(AABB, ExtremePoint, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float3 PointOnEdge(int,float) const", AS_METHOD_FUNCTION_PR(AABB, PointOnEdge, (int,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float3 FaceCenterPoint(int) const", AS_METHOD_FUNCTION_PR(AABB, FaceCenterPoint, (int) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float3 FacePoint(int,float,float) const", AS_METHOD_FUNCTION_PR(AABB, FacePoint, (int,float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float3 FaceNormal(int) const", AS_METHOD_FUNCTION_PR(AABB, FaceNormal, (int) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "Plane FacePlane(int) const", AS_METHOD_FUNCTION_PR(AABB, FacePlane, (int) const, Plane), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "void GetCornerPoints(float3 *) const", AS_METHOD_FUNCTION_PR(AABB, GetCornerPoints, (float3 *) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Plane * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "void GetFacePlanes(Plane *) const", AS_METHOD_FUNCTION_PR(AABB, GetFacePlanes, (Plane *) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float3 Size() const", AS_METHOD_FUNCTION_PR(AABB, Size, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float3 HalfSize() const", AS_METHOD_FUNCTION_PR(AABB, HalfSize, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float3 Diagonal() const", AS_METHOD_FUNCTION_PR(AABB, Diagonal, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float3 HalfDiagonal() const", AS_METHOD_FUNCTION_PR(AABB, HalfDiagonal, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float Volume() const", AS_METHOD_FUNCTION_PR(AABB, Volume, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float SurfaceArea() const", AS_METHOD_FUNCTION_PR(AABB, SurfaceArea, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("AABB", "float3 RandomPointInside(LCG &) const", AS_METHOD_FUNCTION_PR(AABB, RandomPointInside, (LCG &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("AABB", "float3 RandomPointOnSurface(LCG &) const", AS_METHOD_FUNCTION_PR(AABB, RandomPointOnSurface, (LCG &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("AABB", "float3 RandomPointOnEdge(LCG &) const", AS_METHOD_FUNCTION_PR(AABB, RandomPointOnEdge, (LCG &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("AABB", "float3 RandomCornerPoint(LCG &) const", AS_METHOD_FUNCTION_PR(AABB, RandomCornerPoint, (LCG &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void Translate(const float3 &in)", AS_METHOD_FUNCTION_PR(AABB, Translate, (const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void Scale(const float3 &in,float)", AS_METHOD_FUNCTION_PR(AABB, Scale, (const float3 &,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void Scale(const float3 &in,const float3 &in)", AS_METHOD_FUNCTION_PR(AABB, Scale, (const float3 &,const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void TransformAsAABB(const float3x3 &in)", AS_METHOD_FUNCTION_PR(AABB, TransformAsAABB, (const float3x3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void TransformAsAABB(const float3x4 &in)", AS_METHOD_FUNCTION_PR(AABB, TransformAsAABB, (const float3x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void TransformAsAABB(const float4x4 &in)", AS_METHOD_FUNCTION_PR(AABB, TransformAsAABB, (const float4x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void TransformAsAABB(const Quat &in)", AS_METHOD_FUNCTION_PR(AABB, TransformAsAABB, (const Quat &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "OBB Transform(const float3x3 &in) const", AS_METHOD_FUNCTION_PR(AABB, Transform, (const float3x3 &) const, OBB), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "OBB Transform(const float3x4 &in) const", AS_METHOD_FUNCTION_PR(AABB, Transform, (const float3x4 &) const, OBB), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "OBB Transform(const float4x4 &in) const", AS_METHOD_FUNCTION_PR(AABB, Transform, (const float4x4 &) const, OBB), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "OBB Transform(const Quat &in) const", AS_METHOD_FUNCTION_PR(AABB, Transform, (const Quat &) const, OBB), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float3 ClosestPoint(const float3 &in) const", AS_METHOD_FUNCTION_PR(AABB, ClosestPoint, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float Distance(const float3 &in) const", AS_METHOD_FUNCTION_PR(AABB, Distance, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "float Distance(const Sphere &in) const", AS_METHOD_FUNCTION_PR(AABB, Distance, (const Sphere &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool Contains(const float3 &in) const", AS_METHOD_FUNCTION_PR(AABB, Contains, (const float3 &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool Contains(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(AABB, Contains, (const LineSegment &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool Contains(const AABB &in) const", AS_METHOD_FUNCTION_PR(AABB, Contains, (const AABB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool Contains(const OBB &in) const", AS_METHOD_FUNCTION_PR(AABB, Contains, (const OBB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool Contains(const Sphere &in) const", AS_METHOD_FUNCTION_PR(AABB, Contains, (const Sphere &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool Contains(const Triangle &in) const", AS_METHOD_FUNCTION_PR(AABB, Contains, (const Triangle &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "bool Contains(const Polygon &in) const", AS_METHOD_FUNCTION_PR(AABB, Contains, (const Polygon &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool Contains(const Frustum &in) const", AS_METHOD_FUNCTION_PR(AABB, Contains, (const Frustum &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "bool Contains(const Polyhedron &in) const", AS_METHOD_FUNCTION_PR(AABB, Contains, (const Polyhedron &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "bool Intersects(const Ray &in,float *,float *) const", AS_METHOD_FUNCTION_PR(AABB, Intersects, (const Ray &,float *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "bool Intersects(const Line &in,float *,float *) const", AS_METHOD_FUNCTION_PR(AABB, Intersects, (const Line &,float *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "bool Intersects(const LineSegment &in,float *,float *) const", AS_METHOD_FUNCTION_PR(AABB, Intersects, (const LineSegment &,float *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool Intersects(const Plane &in) const", AS_METHOD_FUNCTION_PR(AABB, Intersects, (const Plane &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool Intersects(const AABB &in) const", AS_METHOD_FUNCTION_PR(AABB, Intersects, (const AABB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool Intersects(const OBB &in) const", AS_METHOD_FUNCTION_PR(AABB, Intersects, (const OBB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "bool Intersects(const Sphere &in,float3 *) const", AS_METHOD_FUNCTION_PR(AABB, Intersects, (const Sphere &,float3 *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool Intersects(const Capsule &in) const", AS_METHOD_FUNCTION_PR(AABB, Intersects, (const Capsule &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool Intersects(const Triangle &in) const", AS_METHOD_FUNCTION_PR(AABB, Intersects, (const Triangle &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "bool Intersects(const Polygon &in) const", AS_METHOD_FUNCTION_PR(AABB, Intersects, (const Polygon &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool Intersects(const Frustum &in) const", AS_METHOD_FUNCTION_PR(AABB, Intersects, (const Frustum &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "bool Intersects(const Polyhedron &in) const", AS_METHOD_FUNCTION_PR(AABB, Intersects, (const Polyhedron &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void ProjectToAxis(const float3 &in,float &out,float &out) const", AS_METHOD_FUNCTION_PR(AABB, ProjectToAxis, (const float3 &,float &,float &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void Enclose(const float3 &in)", AS_METHOD_FUNCTION_PR(AABB, Enclose, (const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void Enclose(const LineSegment &in)", AS_METHOD_FUNCTION_PR(AABB, Enclose, (const LineSegment &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void Enclose(const AABB &in)", AS_METHOD_FUNCTION_PR(AABB, Enclose, (const AABB &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void Enclose(const OBB &in)", AS_METHOD_FUNCTION_PR(AABB, Enclose, (const OBB &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void Enclose(const Sphere &in)", AS_METHOD_FUNCTION_PR(AABB, Enclose, (const Sphere &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void Enclose(const Triangle &in)", AS_METHOD_FUNCTION_PR(AABB, Enclose, (const Triangle &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void Enclose(const Capsule &in)", AS_METHOD_FUNCTION_PR(AABB, Enclose, (const Capsule &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "void Enclose(const Frustum &in)", AS_METHOD_FUNCTION_PR(AABB, Enclose, (const Frustum &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "void Enclose(const Polygon &in)", AS_METHOD_FUNCTION_PR(AABB, Enclose, (const Polygon &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "void Enclose(const Polyhedron &in)", AS_METHOD_FUNCTION_PR(AABB, Enclose, (const Polyhedron &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "void Enclose(const float3 *,int)", AS_METHOD_FUNCTION_PR(AABB, Enclose, (const float3 *,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "void Triangulate(int,int,int,float3 *,float3 *,float2 *) const", AS_METHOD_FUNCTION_PR(AABB, Triangulate, (int,int,int,float3 *,float3 *,float2 *) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("AABB", "void ToEdgeList(float3 *) const", AS_METHOD_FUNCTION_PR(AABB, ToEdgeList, (float3 *) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "AABB Intersection(const AABB &in) const", AS_METHOD_FUNCTION_PR(AABB, Intersection, (const AABB &) const, AABB), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("AABB", "bool IntersectRayAABB(const float3 &in,const float3 &in,float &out,float &out) const", AS_METHOD_FUNCTION_PR(AABB, IntersectRayAABB, (const float3 &,const float3 &,float &,float &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float3 * is not known to angelscript)*/ 	//.classmethod(// /*(const float3 * is not known to angelscript)*/ 	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(


	r = engine->RegisterObjectProperty("Capsule", "LineSegment l", asOFFSET(Capsule, l)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Capsule", "float r", asOFFSET(Capsule, r)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Capsule", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(Capsule_ctor_, Capsule, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Capsule", asBEHAVE_CONSTRUCT, "void f(const LineSegment &in,float)", AS_CONSTRUCTOR(Capsule_ctor_const_LineSegment_ref_float, Capsule, (const LineSegment &,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Capsule", asBEHAVE_CONSTRUCT, "void f(const float3 &in,const float3 &in,float)", AS_CONSTRUCTOR(Capsule_ctor_const_float3_ref_const_float3_ref_float, Capsule, (const float3 &,const float3 &,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "void SetFrom(const Sphere &in)", AS_METHOD_FUNCTION_PR(Capsule, SetFrom, (const Sphere &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float LineLength() const", AS_METHOD_FUNCTION_PR(Capsule, LineLength, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float Height() const", AS_METHOD_FUNCTION_PR(Capsule, Height, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float Diameter() const", AS_METHOD_FUNCTION_PR(Capsule, Diameter, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float3 Bottom() const", AS_METHOD_FUNCTION_PR(Capsule, Bottom, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float3 Center() const", AS_METHOD_FUNCTION_PR(Capsule, Center, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float3 Centroid() const", AS_METHOD_FUNCTION_PR(Capsule, Centroid, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float3 ExtremePoint(const float3 &in) const", AS_METHOD_FUNCTION_PR(Capsule, ExtremePoint, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float3 Top() const", AS_METHOD_FUNCTION_PR(Capsule, Top, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float3 UpDirection() const", AS_METHOD_FUNCTION_PR(Capsule, UpDirection, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float Volume() const", AS_METHOD_FUNCTION_PR(Capsule, Volume, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float SurfaceArea() const", AS_METHOD_FUNCTION_PR(Capsule, SurfaceArea, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "Circle CrossSection(float) const", AS_METHOD_FUNCTION_PR(Capsule, CrossSection, (float) const, Circle), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "LineSegment HeightLineSegment() const", AS_METHOD_FUNCTION_PR(Capsule, HeightLineSegment, () const, LineSegment), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool IsFinite() const", AS_METHOD_FUNCTION_PR(Capsule, IsFinite, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float3 PointInside(float,float,float) const", AS_METHOD_FUNCTION_PR(Capsule, PointInside, (float,float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float3 UniformPointPerhapsInside(float,float,float) const", AS_METHOD_FUNCTION_PR(Capsule, UniformPointPerhapsInside, (float,float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "AABB MinimalEnclosingAABB() const", AS_METHOD_FUNCTION_PR(Capsule, MinimalEnclosingAABB, () const, AABB), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "OBB MinimalEnclosingOBB() const", AS_METHOD_FUNCTION_PR(Capsule, MinimalEnclosingOBB, () const, OBB), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("Capsule", "float3 RandomPointInside(LCG &) const", AS_METHOD_FUNCTION_PR(Capsule, RandomPointInside, (LCG &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("Capsule", "float3 RandomPointOnSurface(LCG &) const", AS_METHOD_FUNCTION_PR(Capsule, RandomPointOnSurface, (LCG &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "void Translate(const float3 &in)", AS_METHOD_FUNCTION_PR(Capsule, Translate, (const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "void Scale(const float3 &in,float)", AS_METHOD_FUNCTION_PR(Capsule, Scale, (const float3 &,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "void Transform(const float3x3 &in)", AS_METHOD_FUNCTION_PR(Capsule, Transform, (const float3x3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "void Transform(const float3x4 &in)", AS_METHOD_FUNCTION_PR(Capsule, Transform, (const float3x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "void Transform(const float4x4 &in)", AS_METHOD_FUNCTION_PR(Capsule, Transform, (const float4x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "void Transform(const Quat &in)", AS_METHOD_FUNCTION_PR(Capsule, Transform, (const Quat &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float3 ClosestPoint(const float3 &in) const", AS_METHOD_FUNCTION_PR(Capsule, ClosestPoint, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float Distance(const float3 &in) const", AS_METHOD_FUNCTION_PR(Capsule, Distance, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float Distance(const Plane &in) const", AS_METHOD_FUNCTION_PR(Capsule, Distance, (const Plane &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float Distance(const Sphere &in) const", AS_METHOD_FUNCTION_PR(Capsule, Distance, (const Sphere &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float Distance(const Ray &in) const", AS_METHOD_FUNCTION_PR(Capsule, Distance, (const Ray &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float Distance(const Line &in) const", AS_METHOD_FUNCTION_PR(Capsule, Distance, (const Line &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float Distance(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(Capsule, Distance, (const LineSegment &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "float Distance(const Capsule &in) const", AS_METHOD_FUNCTION_PR(Capsule, Distance, (const Capsule &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Contains(const float3 &in) const", AS_METHOD_FUNCTION_PR(Capsule, Contains, (const float3 &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Contains(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(Capsule, Contains, (const LineSegment &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Contains(const Triangle &in) const", AS_METHOD_FUNCTION_PR(Capsule, Contains, (const Triangle &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Capsule", "bool Contains(const Polygon &in) const", AS_METHOD_FUNCTION_PR(Capsule, Contains, (const Polygon &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Contains(const AABB &in) const", AS_METHOD_FUNCTION_PR(Capsule, Contains, (const AABB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Contains(const OBB &in) const", AS_METHOD_FUNCTION_PR(Capsule, Contains, (const OBB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Contains(const Frustum &in) const", AS_METHOD_FUNCTION_PR(Capsule, Contains, (const Frustum &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Capsule", "bool Contains(const Polyhedron &in) const", AS_METHOD_FUNCTION_PR(Capsule, Contains, (const Polyhedron &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Intersects(const Ray &in) const", AS_METHOD_FUNCTION_PR(Capsule, Intersects, (const Ray &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Intersects(const Line &in) const", AS_METHOD_FUNCTION_PR(Capsule, Intersects, (const Line &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Intersects(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(Capsule, Intersects, (const LineSegment &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Intersects(const Plane &in) const", AS_METHOD_FUNCTION_PR(Capsule, Intersects, (const Plane &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Intersects(const Sphere &in) const", AS_METHOD_FUNCTION_PR(Capsule, Intersects, (const Sphere &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Intersects(const Capsule &in) const", AS_METHOD_FUNCTION_PR(Capsule, Intersects, (const Capsule &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Intersects(const AABB &in) const", AS_METHOD_FUNCTION_PR(Capsule, Intersects, (const AABB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Intersects(const OBB &in) const", AS_METHOD_FUNCTION_PR(Capsule, Intersects, (const OBB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Intersects(const Triangle &in) const", AS_METHOD_FUNCTION_PR(Capsule, Intersects, (const Triangle &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Capsule", "bool Intersects(const Polygon &in) const", AS_METHOD_FUNCTION_PR(Capsule, Intersects, (const Polygon &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Capsule", "bool Intersects(const Frustum &in) const", AS_METHOD_FUNCTION_PR(Capsule, Intersects, (const Frustum &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Capsule", "bool Intersects(const Polyhedron &in) const", AS_METHOD_FUNCTION_PR(Capsule, Intersects, (const Polyhedron &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);



	r = engine->RegisterObjectProperty("Circle", "float3 pos", asOFFSET(Circle, pos)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Circle", "float3 normal", asOFFSET(Circle, normal)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Circle", "float r", asOFFSET(Circle, r)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Circle", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(Circle_ctor_, Circle, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Circle", asBEHAVE_CONSTRUCT, "void f(const float3 &in,const float3 &in,float)", AS_CONSTRUCTOR(Circle_ctor_const_float3_ref_const_float3_ref_float, Circle, (const float3 &,const float3 &,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "float3 BasisU() const", AS_METHOD_FUNCTION_PR(Circle, BasisU, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "float3 BasisV() const", AS_METHOD_FUNCTION_PR(Circle, BasisV, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "float3 GetPoint(float) const", AS_METHOD_FUNCTION_PR(Circle, GetPoint, (float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "float3 GetPoint(float,float) const", AS_METHOD_FUNCTION_PR(Circle, GetPoint, (float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "float3 CenterPoint() const", AS_METHOD_FUNCTION_PR(Circle, CenterPoint, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "float3 Centroid() const", AS_METHOD_FUNCTION_PR(Circle, Centroid, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "float3 ExtremePoint(const float3 &in) const", AS_METHOD_FUNCTION_PR(Circle, ExtremePoint, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "Plane ContainingPlane() const", AS_METHOD_FUNCTION_PR(Circle, ContainingPlane, () const, Plane), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "bool EdgeContains(const float3 &in,float) const", AS_METHOD_FUNCTION_PR(Circle, EdgeContains, (const float3 &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "float DistanceToEdge(const float3 &in) const", AS_METHOD_FUNCTION_PR(Circle, DistanceToEdge, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "float DistanceToDisc(const float3 &in) const", AS_METHOD_FUNCTION_PR(Circle, DistanceToDisc, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "float3 ClosestPointToEdge(const float3 &in) const", AS_METHOD_FUNCTION_PR(Circle, ClosestPointToEdge, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "float3 ClosestPointToDisc(const float3 &in) const", AS_METHOD_FUNCTION_PR(Circle, ClosestPointToDisc, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Circle", "int Intersects(const Plane &in,float3 *,float3 *) const", AS_METHOD_FUNCTION_PR(Circle, Intersects, (const Plane &,float3 *,float3 *) const, int), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "int Intersects(const Plane &in) const", AS_METHOD_FUNCTION_PR(Circle, Intersects, (const Plane &) const, int), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "bool IntersectsDisc(const Line &in) const", AS_METHOD_FUNCTION_PR(Circle, IntersectsDisc, (const Line &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "bool IntersectsDisc(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(Circle, IntersectsDisc, (const LineSegment &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Circle", "bool IntersectsDisc(const Ray &in) const", AS_METHOD_FUNCTION_PR(Circle, IntersectsDisc, (const Ray &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);



// /* FrustumType is not known to angelscript. */ 	r = engine->RegisterObjectProperty("Frustum", "FrustumType type", asOFFSET(Frustum, type)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Frustum", "float3 pos", asOFFSET(Frustum, pos)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Frustum", "float3 front", asOFFSET(Frustum, front)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Frustum", "float3 up", asOFFSET(Frustum, up)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Frustum", "float nearPlaneDistance", asOFFSET(Frustum, nearPlaneDistance)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Frustum", "float farPlaneDistance", asOFFSET(Frustum, farPlaneDistance)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Frustum", "float horizontalFov", asOFFSET(Frustum, horizontalFov)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Frustum", "float orthographicWidth", asOFFSET(Frustum, orthographicWidth)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Frustum", "float verticalFov", asOFFSET(Frustum, verticalFov)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Frustum", "float orthographicHeight", asOFFSET(Frustum, orthographicHeight)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Frustum", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(Frustum_ctor_, Frustum, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "float AspectRatio() const", AS_METHOD_FUNCTION_PR(Frustum, AspectRatio, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "Plane NearPlane() const", AS_METHOD_FUNCTION_PR(Frustum, NearPlane, () const, Plane), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "Plane FarPlane() const", AS_METHOD_FUNCTION_PR(Frustum, FarPlane, () const, Plane), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "Plane LeftPlane() const", AS_METHOD_FUNCTION_PR(Frustum, LeftPlane, () const, Plane), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "Plane RightPlane() const", AS_METHOD_FUNCTION_PR(Frustum, RightPlane, () const, Plane), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "Plane TopPlane() const", AS_METHOD_FUNCTION_PR(Frustum, TopPlane, () const, Plane), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "Plane BottomPlane() const", AS_METHOD_FUNCTION_PR(Frustum, BottomPlane, () const, Plane), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "Plane GetPlane(int) const", AS_METHOD_FUNCTION_PR(Frustum, GetPlane, (int) const, Plane), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Plane * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Frustum", "void GetPlanes(Plane *) const", AS_METHOD_FUNCTION_PR(Frustum, GetPlanes, (Plane *) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "float3 CornerPoint(int) const", AS_METHOD_FUNCTION_PR(Frustum, CornerPoint, (int) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Frustum", "void GetCornerPoints(float3 *) const", AS_METHOD_FUNCTION_PR(Frustum, GetCornerPoints, (float3 *) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "float3 ExtremePoint(const float3 &in) const", AS_METHOD_FUNCTION_PR(Frustum, ExtremePoint, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "float3x4 WorldMatrix() const", AS_METHOD_FUNCTION_PR(Frustum, WorldMatrix, () const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "float3x4 ViewMatrix() const", AS_METHOD_FUNCTION_PR(Frustum, ViewMatrix, () const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "float4x4 ProjectionMatrix() const", AS_METHOD_FUNCTION_PR(Frustum, ProjectionMatrix, () const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "float4x4 ViewProjMatrix() const", AS_METHOD_FUNCTION_PR(Frustum, ViewProjMatrix, () const, float4x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "Ray LookAt(float,float) const", AS_METHOD_FUNCTION_PR(Frustum, LookAt, (float,float) const, Ray), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "Ray LookAtFromNearPlane(float,float) const", AS_METHOD_FUNCTION_PR(Frustum, LookAtFromNearPlane, (float,float) const, Ray), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "float3 Project(const float3 &in) const", AS_METHOD_FUNCTION_PR(Frustum, Project, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "float3 NearPlanePos(float,float) const", AS_METHOD_FUNCTION_PR(Frustum, NearPlanePos, (float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "float3 NearPlanePos(const float2 &in) const", AS_METHOD_FUNCTION_PR(Frustum, NearPlanePos, (const float2 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "float3 FarPlanePos(float,float) const", AS_METHOD_FUNCTION_PR(Frustum, FarPlanePos, (float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "float3 FarPlanePos(const float2 &in) const", AS_METHOD_FUNCTION_PR(Frustum, FarPlanePos, (const float2 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool IsFinite() const", AS_METHOD_FUNCTION_PR(Frustum, IsFinite, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "float Volume() const", AS_METHOD_FUNCTION_PR(Frustum, Volume, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("Frustum", "float3 RandomPointInside(LCG &) const", AS_METHOD_FUNCTION_PR(Frustum, RandomPointInside, (LCG &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "void Translate(const float3 &in)", AS_METHOD_FUNCTION_PR(Frustum, Translate, (const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "void Transform(const float3x3 &in)", AS_METHOD_FUNCTION_PR(Frustum, Transform, (const float3x3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "void Transform(const float3x4 &in)", AS_METHOD_FUNCTION_PR(Frustum, Transform, (const float3x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "void Transform(const float4x4 &in)", AS_METHOD_FUNCTION_PR(Frustum, Transform, (const float4x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "void Transform(const Quat &in)", AS_METHOD_FUNCTION_PR(Frustum, Transform, (const Quat &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "AABB MinimalEnclosingAABB() const", AS_METHOD_FUNCTION_PR(Frustum, MinimalEnclosingAABB, () const, AABB), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "OBB MinimalEnclosingOBB() const", AS_METHOD_FUNCTION_PR(Frustum, MinimalEnclosingOBB, () const, OBB), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Frustum", "Polyhedron ToPolyhedron() const", AS_METHOD_FUNCTION_PR(Frustum, ToPolyhedron, () const, Polyhedron), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Contains(const float3 &in) const", AS_METHOD_FUNCTION_PR(Frustum, Contains, (const float3 &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Contains(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(Frustum, Contains, (const LineSegment &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Contains(const Triangle &in) const", AS_METHOD_FUNCTION_PR(Frustum, Contains, (const Triangle &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Frustum", "bool Contains(const Polygon &in) const", AS_METHOD_FUNCTION_PR(Frustum, Contains, (const Polygon &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Contains(const AABB &in) const", AS_METHOD_FUNCTION_PR(Frustum, Contains, (const AABB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Contains(const OBB &in) const", AS_METHOD_FUNCTION_PR(Frustum, Contains, (const OBB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Contains(const Frustum &in) const", AS_METHOD_FUNCTION_PR(Frustum, Contains, (const Frustum &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Frustum", "bool Contains(const Polyhedron &in) const", AS_METHOD_FUNCTION_PR(Frustum, Contains, (const Polyhedron &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "float3 ClosestPoint(const float3 &in) const", AS_METHOD_FUNCTION_PR(Frustum, ClosestPoint, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "float Distance(const float3 &in) const", AS_METHOD_FUNCTION_PR(Frustum, Distance, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Intersects(const Ray &in) const", AS_METHOD_FUNCTION_PR(Frustum, Intersects, (const Ray &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Intersects(const Line &in) const", AS_METHOD_FUNCTION_PR(Frustum, Intersects, (const Line &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Intersects(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(Frustum, Intersects, (const LineSegment &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Intersects(const AABB &in) const", AS_METHOD_FUNCTION_PR(Frustum, Intersects, (const AABB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Intersects(const OBB &in) const", AS_METHOD_FUNCTION_PR(Frustum, Intersects, (const OBB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Intersects(const Plane &in) const", AS_METHOD_FUNCTION_PR(Frustum, Intersects, (const Plane &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Intersects(const Triangle &in) const", AS_METHOD_FUNCTION_PR(Frustum, Intersects, (const Triangle &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Frustum", "bool Intersects(const Polygon &in) const", AS_METHOD_FUNCTION_PR(Frustum, Intersects, (const Polygon &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Intersects(const Sphere &in) const", AS_METHOD_FUNCTION_PR(Frustum, Intersects, (const Sphere &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Intersects(const Capsule &in) const", AS_METHOD_FUNCTION_PR(Frustum, Intersects, (const Capsule &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Frustum", "bool Intersects(const Frustum &in) const", AS_METHOD_FUNCTION_PR(Frustum, Intersects, (const Frustum &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Frustum", "bool Intersects(const Polyhedron &in) const", AS_METHOD_FUNCTION_PR(Frustum, Intersects, (const Polyhedron &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(


	r = engine->RegisterObjectProperty("Line", "float3 pos", asOFFSET(Line, pos)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Line", "float3 dir", asOFFSET(Line, dir)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Line", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(Line_ctor_, Line, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Line", asBEHAVE_CONSTRUCT, "void f(const float3 &in,const float3 &in)", AS_CONSTRUCTOR(Line_ctor_const_float3_ref_const_float3_ref, Line, (const float3 &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Line", asBEHAVE_CONSTRUCT, "void f(const Ray &in)", AS_CONSTRUCTOR(Line_ctor_const_Ray_ref, Line, (const Ray &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Line", asBEHAVE_CONSTRUCT, "void f(const LineSegment &in)", AS_CONSTRUCTOR(Line_ctor_const_LineSegment_ref, Line, (const LineSegment &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "float3 GetPoint(float) const", AS_METHOD_FUNCTION_PR(Line, GetPoint, (float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "void Transform(const float3x3 &in)", AS_METHOD_FUNCTION_PR(Line, Transform, (const float3x3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "void Transform(const float3x4 &in)", AS_METHOD_FUNCTION_PR(Line, Transform, (const float3x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "void Transform(const float4x4 &in)", AS_METHOD_FUNCTION_PR(Line, Transform, (const float4x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "void Transform(const Quat &in)", AS_METHOD_FUNCTION_PR(Line, Transform, (const Quat &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "bool Contains(const float3 &in,float) const", AS_METHOD_FUNCTION_PR(Line, Contains, (const float3 &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "bool Contains(const Ray &in,float) const", AS_METHOD_FUNCTION_PR(Line, Contains, (const Ray &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "bool Contains(const LineSegment &in,float) const", AS_METHOD_FUNCTION_PR(Line, Contains, (const LineSegment &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "bool Equals(const Line &in,float) const", AS_METHOD_FUNCTION_PR(Line, Equals, (const Line &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "float Distance(const float3 &in,float *) const", AS_METHOD_FUNCTION_PR(Line, Distance, (const float3 &,float *) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "float Distance(const Ray &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Line, Distance, (const Ray &,float *,float *) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "float Distance(const Ray &in) const", AS_METHOD_FUNCTION_PR(Line, Distance, (const Ray &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "float Distance(const Line &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Line, Distance, (const Line &,float *,float *) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "float Distance(const Line &in) const", AS_METHOD_FUNCTION_PR(Line, Distance, (const Line &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "float Distance(const LineSegment &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Line, Distance, (const LineSegment &,float *,float *) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "float Distance(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(Line, Distance, (const LineSegment &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "float Distance(const Sphere &in) const", AS_METHOD_FUNCTION_PR(Line, Distance, (const Sphere &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "float Distance(const Capsule &in) const", AS_METHOD_FUNCTION_PR(Line, Distance, (const Capsule &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "float3 ClosestPoint(const float3 &in,float *) const", AS_METHOD_FUNCTION_PR(Line, ClosestPoint, (const float3 &,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "float3 ClosestPoint(const Ray &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Line, ClosestPoint, (const Ray &,float *,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "float3 ClosestPoint(const Line &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Line, ClosestPoint, (const Line &,float *,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "float3 ClosestPoint(const LineSegment &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Line, ClosestPoint, (const LineSegment &,float *,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "float3 ClosestPoint(const Triangle &in,float *,float *,float *) const", AS_METHOD_FUNCTION_PR(Line, ClosestPoint, (const Triangle &,float *,float *,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "bool Intersects(const Triangle &in,float *,float3 *) const", AS_METHOD_FUNCTION_PR(Line, Intersects, (const Triangle &,float *,float3 *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "bool Intersects(const Plane &in,float *) const", AS_METHOD_FUNCTION_PR(Line, Intersects, (const Plane &,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "bool Intersects(const Sphere &in,float3 *,float3 *,float *) const", AS_METHOD_FUNCTION_PR(Line, Intersects, (const Sphere &,float3 *,float3 *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "bool Intersects(const AABB &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Line, Intersects, (const AABB &,float *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "bool Intersects(const OBB &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Line, Intersects, (const OBB &,float *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "bool Intersects(const Capsule &in) const", AS_METHOD_FUNCTION_PR(Line, Intersects, (const Capsule &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "bool Intersects(const Polygon &in) const", AS_METHOD_FUNCTION_PR(Line, Intersects, (const Polygon &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "bool Intersects(const Frustum &in) const", AS_METHOD_FUNCTION_PR(Line, Intersects, (const Frustum &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Line", "bool Intersects(const Polyhedron &in) const", AS_METHOD_FUNCTION_PR(Line, Intersects, (const Polyhedron &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "bool IntersectsDisc(const Circle &in) const", AS_METHOD_FUNCTION_PR(Line, IntersectsDisc, (const Circle &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "Ray ToRay() const", AS_METHOD_FUNCTION_PR(Line, ToRay, () const, Ray), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Line", "LineSegment ToLineSegment(float) const", AS_METHOD_FUNCTION_PR(Line, ToLineSegment, (float) const, LineSegment), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	//.classmethod(// /*(float * is not known to angelscript)*/ 	//.classmethod(


	r = engine->RegisterObjectProperty("LineSegment", "float3 a", asOFFSET(LineSegment, a)); assert(r >= 0);
	r = engine->RegisterObjectProperty("LineSegment", "float3 b", asOFFSET(LineSegment, b)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("LineSegment", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(LineSegment_ctor_, LineSegment, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("LineSegment", asBEHAVE_CONSTRUCT, "void f(const float3 &in,const float3 &in)", AS_CONSTRUCTOR(LineSegment_ctor_const_float3_ref_const_float3_ref, LineSegment, (const float3 &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("LineSegment", asBEHAVE_CONSTRUCT, "void f(const Ray &in,float)", AS_CONSTRUCTOR(LineSegment_ctor_const_Ray_ref_float, LineSegment, (const Ray &,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("LineSegment", asBEHAVE_CONSTRUCT, "void f(const Line &in,float)", AS_CONSTRUCTOR(LineSegment_ctor_const_Line_ref_float, LineSegment, (const Line &,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "float3 GetPoint(float) const", AS_METHOD_FUNCTION_PR(LineSegment, GetPoint, (float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "float3 CenterPoint() const", AS_METHOD_FUNCTION_PR(LineSegment, CenterPoint, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "void Reverse()", AS_METHOD_FUNCTION_PR(LineSegment, Reverse, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "float3 Dir() const", AS_METHOD_FUNCTION_PR(LineSegment, Dir, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "float3 ExtremePoint(const float3 &in) const", AS_METHOD_FUNCTION_PR(LineSegment, ExtremePoint, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "void Transform(const float3x3 &in)", AS_METHOD_FUNCTION_PR(LineSegment, Transform, (const float3x3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "void Transform(const float3x4 &in)", AS_METHOD_FUNCTION_PR(LineSegment, Transform, (const float3x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "void Transform(const float4x4 &in)", AS_METHOD_FUNCTION_PR(LineSegment, Transform, (const float4x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "void Transform(const Quat &in)", AS_METHOD_FUNCTION_PR(LineSegment, Transform, (const Quat &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "float Length() const", AS_METHOD_FUNCTION_PR(LineSegment, Length, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "float LengthSq() const", AS_METHOD_FUNCTION_PR(LineSegment, LengthSq, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "bool IsFinite() const", AS_METHOD_FUNCTION_PR(LineSegment, IsFinite, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "bool Equals(const LineSegment &in,float) const", AS_METHOD_FUNCTION_PR(LineSegment, Equals, (const LineSegment &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "bool Contains(const float3 &in,float) const", AS_METHOD_FUNCTION_PR(LineSegment, Contains, (const float3 &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "bool Contains(const LineSegment &in,float) const", AS_METHOD_FUNCTION_PR(LineSegment, Contains, (const LineSegment &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LineSegment", "float3 ClosestPoint(const float3 &in,float *) const", AS_METHOD_FUNCTION_PR(LineSegment, ClosestPoint, (const float3 &,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LineSegment", "float3 ClosestPoint(const Ray &in,float *,float *) const", AS_METHOD_FUNCTION_PR(LineSegment, ClosestPoint, (const Ray &,float *,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LineSegment", "float3 ClosestPoint(const Line &in,float *,float *) const", AS_METHOD_FUNCTION_PR(LineSegment, ClosestPoint, (const Line &,float *,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LineSegment", "float3 ClosestPoint(const LineSegment &in,float *,float *) const", AS_METHOD_FUNCTION_PR(LineSegment, ClosestPoint, (const LineSegment &,float *,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LineSegment", "float Distance(const float3 &in,float *) const", AS_METHOD_FUNCTION_PR(LineSegment, Distance, (const float3 &,float *) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LineSegment", "float Distance(const Ray &in,float *,float *) const", AS_METHOD_FUNCTION_PR(LineSegment, Distance, (const Ray &,float *,float *) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LineSegment", "float Distance(const Line &in,float *,float *) const", AS_METHOD_FUNCTION_PR(LineSegment, Distance, (const Line &,float *,float *) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LineSegment", "float Distance(const LineSegment &in,float *,float *) const", AS_METHOD_FUNCTION_PR(LineSegment, Distance, (const LineSegment &,float *,float *) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "float Distance(const Plane &in) const", AS_METHOD_FUNCTION_PR(LineSegment, Distance, (const Plane &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "float Distance(const Sphere &in) const", AS_METHOD_FUNCTION_PR(LineSegment, Distance, (const Sphere &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "float Distance(const Capsule &in) const", AS_METHOD_FUNCTION_PR(LineSegment, Distance, (const Capsule &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "bool Intersects(const Plane &in) const", AS_METHOD_FUNCTION_PR(LineSegment, Intersects, (const Plane &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LineSegment", "bool Intersects(const Plane &in,float *) const", AS_METHOD_FUNCTION_PR(LineSegment, Intersects, (const Plane &,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LineSegment", "bool Intersects(const Triangle &in,float *,float3 *) const", AS_METHOD_FUNCTION_PR(LineSegment, Intersects, (const Triangle &,float *,float3 *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LineSegment", "bool Intersects(const Sphere &in,float3 *,float3 *,float *) const", AS_METHOD_FUNCTION_PR(LineSegment, Intersects, (const Sphere &,float3 *,float3 *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LineSegment", "bool Intersects(const AABB &in,float *,float *) const", AS_METHOD_FUNCTION_PR(LineSegment, Intersects, (const AABB &,float *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LineSegment", "bool Intersects(const OBB &in,float *,float *) const", AS_METHOD_FUNCTION_PR(LineSegment, Intersects, (const OBB &,float *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "bool Intersects(const Capsule &in) const", AS_METHOD_FUNCTION_PR(LineSegment, Intersects, (const Capsule &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LineSegment", "bool Intersects(const Polygon &in) const", AS_METHOD_FUNCTION_PR(LineSegment, Intersects, (const Polygon &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "bool Intersects(const Frustum &in) const", AS_METHOD_FUNCTION_PR(LineSegment, Intersects, (const Frustum &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LineSegment", "bool Intersects(const Polyhedron &in) const", AS_METHOD_FUNCTION_PR(LineSegment, Intersects, (const Polyhedron &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "bool Intersects(const LineSegment &in,float) const", AS_METHOD_FUNCTION_PR(LineSegment, Intersects, (const LineSegment &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "bool IntersectsDisc(const Circle &in) const", AS_METHOD_FUNCTION_PR(LineSegment, IntersectsDisc, (const Circle &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "Ray ToRay() const", AS_METHOD_FUNCTION_PR(LineSegment, ToRay, () const, Ray), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LineSegment", "Line ToLine() const", AS_METHOD_FUNCTION_PR(LineSegment, ToLine, () const, Line), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);



	r = engine->RegisterObjectProperty("OBB", "float3 pos", asOFFSET(OBB, pos)); assert(r >= 0);
	r = engine->RegisterObjectProperty("OBB", "float3 r", asOFFSET(OBB, r)); assert(r >= 0);
// /* Exposing array types as fields are not supported by angelscript. */ 	r = engine->RegisterObjectProperty("OBB", "float3 axis", asOFFSET(OBB, axis)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("OBB", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(OBB_ctor_, OBB, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("OBB", asBEHAVE_CONSTRUCT, "void f(const AABB &in)", AS_CONSTRUCTOR(OBB_ctor_const_AABB_ref, OBB, (const AABB &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "void SetNegativeInfinity()", AS_METHOD_FUNCTION_PR(OBB, SetNegativeInfinity, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "void SetFrom(const AABB &in)", AS_METHOD_FUNCTION_PR(OBB, SetFrom, (const AABB &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "void SetFrom(const AABB &in,const float3x3 &in)", AS_METHOD_FUNCTION_PR(OBB, SetFrom, (const AABB &,const float3x3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "void SetFrom(const AABB &in,const float3x4 &in)", AS_METHOD_FUNCTION_PR(OBB, SetFrom, (const AABB &,const float3x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "void SetFrom(const AABB &in,const float4x4 &in)", AS_METHOD_FUNCTION_PR(OBB, SetFrom, (const AABB &,const float4x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "void SetFrom(const AABB &in,const Quat &in)", AS_METHOD_FUNCTION_PR(OBB, SetFrom, (const AABB &,const Quat &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "void SetFrom(const Sphere &in)", AS_METHOD_FUNCTION_PR(OBB, SetFrom, (const Sphere &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("OBB", "bool SetFrom(const Polyhedron &in)", AS_METHOD_FUNCTION_PR(OBB, SetFrom, (const Polyhedron &), bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("OBB", "void SetFromApproximate(const float3 *,int)", AS_METHOD_FUNCTION_PR(OBB, SetFromApproximate, (const float3 *,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("OBB", "Polyhedron ToPolyhedron() const", AS_METHOD_FUNCTION_PR(OBB, ToPolyhedron, () const, Polyhedron), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "AABB MinimalEnclosingAABB() const", AS_METHOD_FUNCTION_PR(OBB, MinimalEnclosingAABB, () const, AABB), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "AABB MaximalContainedAABB() const", AS_METHOD_FUNCTION_PR(OBB, MaximalContainedAABB, () const, AABB), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "Sphere MinimalEnclosingSphere() const", AS_METHOD_FUNCTION_PR(OBB, MinimalEnclosingSphere, () const, Sphere), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "Sphere MaximalContainedSphere() const", AS_METHOD_FUNCTION_PR(OBB, MaximalContainedSphere, () const, Sphere), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float3 Size() const", AS_METHOD_FUNCTION_PR(OBB, Size, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float3 HalfSize() const", AS_METHOD_FUNCTION_PR(OBB, HalfSize, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float3 Diagonal() const", AS_METHOD_FUNCTION_PR(OBB, Diagonal, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float3 HalfDiagonal() const", AS_METHOD_FUNCTION_PR(OBB, HalfDiagonal, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float3x4 WorldToLocal() const", AS_METHOD_FUNCTION_PR(OBB, WorldToLocal, () const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float3x4 LocalToWorld() const", AS_METHOD_FUNCTION_PR(OBB, LocalToWorld, () const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "bool IsFinite() const", AS_METHOD_FUNCTION_PR(OBB, IsFinite, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "bool IsDegenerate() const", AS_METHOD_FUNCTION_PR(OBB, IsDegenerate, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float3 CenterPoint() const", AS_METHOD_FUNCTION_PR(OBB, CenterPoint, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float3 Centroid() const", AS_METHOD_FUNCTION_PR(OBB, Centroid, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float Volume() const", AS_METHOD_FUNCTION_PR(OBB, Volume, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float SurfaceArea() const", AS_METHOD_FUNCTION_PR(OBB, SurfaceArea, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float3 PointInside(float,float,float) const", AS_METHOD_FUNCTION_PR(OBB, PointInside, (float,float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "LineSegment Edge(int) const", AS_METHOD_FUNCTION_PR(OBB, Edge, (int) const, LineSegment), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float3 CornerPoint(int) const", AS_METHOD_FUNCTION_PR(OBB, CornerPoint, (int) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float3 ExtremePoint(const float3 &in) const", AS_METHOD_FUNCTION_PR(OBB, ExtremePoint, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float3 PointOnEdge(int,float) const", AS_METHOD_FUNCTION_PR(OBB, PointOnEdge, (int,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float3 FaceCenterPoint(int) const", AS_METHOD_FUNCTION_PR(OBB, FaceCenterPoint, (int) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float3 FacePoint(int,float,float) const", AS_METHOD_FUNCTION_PR(OBB, FacePoint, (int,float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "Plane FacePlane(int) const", AS_METHOD_FUNCTION_PR(OBB, FacePlane, (int) const, Plane), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("OBB", "void GetCornerPoints(float3 *) const", AS_METHOD_FUNCTION_PR(OBB, GetCornerPoints, (float3 *) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Plane * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("OBB", "void GetFacePlanes(Plane *) const", AS_METHOD_FUNCTION_PR(OBB, GetFacePlanes, (Plane *) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("OBB", "float3 RandomPointInside(LCG &) const", AS_METHOD_FUNCTION_PR(OBB, RandomPointInside, (LCG &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("OBB", "float3 RandomPointOnSurface(LCG &) const", AS_METHOD_FUNCTION_PR(OBB, RandomPointOnSurface, (LCG &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("OBB", "float3 RandomPointOnEdge(LCG &) const", AS_METHOD_FUNCTION_PR(OBB, RandomPointOnEdge, (LCG &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("OBB", "float3 RandomCornerPoint(LCG &) const", AS_METHOD_FUNCTION_PR(OBB, RandomCornerPoint, (LCG &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "void Translate(const float3 &in)", AS_METHOD_FUNCTION_PR(OBB, Translate, (const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "void Scale(const float3 &in,float)", AS_METHOD_FUNCTION_PR(OBB, Scale, (const float3 &,float), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "void Scale(const float3 &in,const float3 &in)", AS_METHOD_FUNCTION_PR(OBB, Scale, (const float3 &,const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "void Transform(const float3x3 &in)", AS_METHOD_FUNCTION_PR(OBB, Transform, (const float3x3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "void Transform(const float3x4 &in)", AS_METHOD_FUNCTION_PR(OBB, Transform, (const float3x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "void Transform(const float4x4 &in)", AS_METHOD_FUNCTION_PR(OBB, Transform, (const float4x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "void Transform(const Quat &in)", AS_METHOD_FUNCTION_PR(OBB, Transform, (const Quat &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float3 ClosestPoint(const float3 &in) const", AS_METHOD_FUNCTION_PR(OBB, ClosestPoint, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float Distance(const float3 &in) const", AS_METHOD_FUNCTION_PR(OBB, Distance, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "float Distance(const Sphere &in) const", AS_METHOD_FUNCTION_PR(OBB, Distance, (const Sphere &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "bool Contains(const float3 &in) const", AS_METHOD_FUNCTION_PR(OBB, Contains, (const float3 &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "bool Contains(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(OBB, Contains, (const LineSegment &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "bool Contains(const AABB &in) const", AS_METHOD_FUNCTION_PR(OBB, Contains, (const AABB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "bool Contains(const OBB &in) const", AS_METHOD_FUNCTION_PR(OBB, Contains, (const OBB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "bool Contains(const Triangle &in) const", AS_METHOD_FUNCTION_PR(OBB, Contains, (const Triangle &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("OBB", "bool Contains(const Polygon &in) const", AS_METHOD_FUNCTION_PR(OBB, Contains, (const Polygon &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "bool Contains(const Frustum &in) const", AS_METHOD_FUNCTION_PR(OBB, Contains, (const Frustum &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("OBB", "bool Contains(const Polyhedron &in) const", AS_METHOD_FUNCTION_PR(OBB, Contains, (const Polyhedron &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "bool Intersects(const AABB &in) const", AS_METHOD_FUNCTION_PR(OBB, Intersects, (const AABB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "bool Intersects(const OBB &in,float) const", AS_METHOD_FUNCTION_PR(OBB, Intersects, (const OBB &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "bool Intersects(const Plane &in) const", AS_METHOD_FUNCTION_PR(OBB, Intersects, (const Plane &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("OBB", "bool Intersects(const Ray &in,float *,float *) const", AS_METHOD_FUNCTION_PR(OBB, Intersects, (const Ray &,float *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("OBB", "bool Intersects(const Line &in,float *,float *) const", AS_METHOD_FUNCTION_PR(OBB, Intersects, (const Line &,float *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("OBB", "bool Intersects(const LineSegment &in,float *,float *) const", AS_METHOD_FUNCTION_PR(OBB, Intersects, (const LineSegment &,float *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("OBB", "bool Intersects(const Sphere &in,float3 *) const", AS_METHOD_FUNCTION_PR(OBB, Intersects, (const Sphere &,float3 *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "bool Intersects(const Capsule &in) const", AS_METHOD_FUNCTION_PR(OBB, Intersects, (const Capsule &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "bool Intersects(const Triangle &in) const", AS_METHOD_FUNCTION_PR(OBB, Intersects, (const Triangle &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("OBB", "bool Intersects(const Polygon &in) const", AS_METHOD_FUNCTION_PR(OBB, Intersects, (const Polygon &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "bool Intersects(const Frustum &in) const", AS_METHOD_FUNCTION_PR(OBB, Intersects, (const Frustum &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("OBB", "bool Intersects(const Polyhedron &in) const", AS_METHOD_FUNCTION_PR(OBB, Intersects, (const Polyhedron &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("OBB", "void Enclose(const float3 &in)", AS_METHOD_FUNCTION_PR(OBB, Enclose, (const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("OBB", "void Triangulate(int,int,int,float3 *,float3 *,float2 *) const", AS_METHOD_FUNCTION_PR(OBB, Triangulate, (int,int,int,float3 *,float3 *,float2 *) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("OBB", "void ToEdgeList(float3 *) const", AS_METHOD_FUNCTION_PR(OBB, ToEdgeList, (float3 *) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float3 * is not known to angelscript)*/ 	//.classmethod(// /*(const float3 * is not known to angelscript)*/ 	//.classmethod(	//.classmethod(	//.classmethod(


	r = engine->RegisterObjectProperty("Plane", "float3 normal", asOFFSET(Plane, normal)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Plane", "float d", asOFFSET(Plane, d)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Plane", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(Plane_ctor_, Plane, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Plane", asBEHAVE_CONSTRUCT, "void f(const float3 &in,float)", AS_CONSTRUCTOR(Plane_ctor_const_float3_ref_float, Plane, (const float3 &,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Plane", asBEHAVE_CONSTRUCT, "void f(const float3 &in,const float3 &in,const float3 &in)", AS_CONSTRUCTOR(Plane_ctor_const_float3_ref_const_float3_ref_const_float3_ref, Plane, (const float3 &,const float3 &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Plane", asBEHAVE_CONSTRUCT, "void f(const float3 &in,const float3 &in)", AS_CONSTRUCTOR(Plane_ctor_const_float3_ref_const_float3_ref, Plane, (const float3 &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Plane", asBEHAVE_CONSTRUCT, "void f(const Ray &in,const float3 &in)", AS_CONSTRUCTOR(Plane_ctor_const_Ray_ref_const_float3_ref, Plane, (const Ray &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Plane", asBEHAVE_CONSTRUCT, "void f(const Line &in,const float3 &in)", AS_CONSTRUCTOR(Plane_ctor_const_Line_ref_const_float3_ref, Plane, (const Line &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Plane", asBEHAVE_CONSTRUCT, "void f(const LineSegment &in,const float3 &in)", AS_CONSTRUCTOR(Plane_ctor_const_LineSegment_ref_const_float3_ref, Plane, (const LineSegment &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "void Set(const float3 &in,const float3 &in,const float3 &in)", AS_METHOD_FUNCTION_PR(Plane, Set, (const float3 &,const float3 &,const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "void Set(const float3 &in,const float3 &in)", AS_METHOD_FUNCTION_PR(Plane, Set, (const float3 &,const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "void ReverseNormal()", AS_METHOD_FUNCTION_PR(Plane, ReverseNormal, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float3 PointOnPlane() const", AS_METHOD_FUNCTION_PR(Plane, PointOnPlane, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float3 Point(float,float) const", AS_METHOD_FUNCTION_PR(Plane, Point, (float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float3 Point(float,float,const float3 &in) const", AS_METHOD_FUNCTION_PR(Plane, Point, (float,float,const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "void Transform(const float3x3 &in)", AS_METHOD_FUNCTION_PR(Plane, Transform, (const float3x3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "void Transform(const float3x4 &in)", AS_METHOD_FUNCTION_PR(Plane, Transform, (const float3x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "void Transform(const float4x4 &in)", AS_METHOD_FUNCTION_PR(Plane, Transform, (const float4x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "void Transform(const Quat &in)", AS_METHOD_FUNCTION_PR(Plane, Transform, (const Quat &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool IsInPositiveDirection(const float3 &in) const", AS_METHOD_FUNCTION_PR(Plane, IsInPositiveDirection, (const float3 &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool IsOnPositiveSide(const float3 &in) const", AS_METHOD_FUNCTION_PR(Plane, IsOnPositiveSide, (const float3 &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "int ExamineSide(const Triangle &in) const", AS_METHOD_FUNCTION_PR(Plane, ExamineSide, (const Triangle &) const, int), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool AreOnSameSide(const float3 &in,const float3 &in) const", AS_METHOD_FUNCTION_PR(Plane, AreOnSameSide, (const float3 &,const float3 &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float Distance(const float3 &in) const", AS_METHOD_FUNCTION_PR(Plane, Distance, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float Distance(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(Plane, Distance, (const LineSegment &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float Distance(const Sphere &in) const", AS_METHOD_FUNCTION_PR(Plane, Distance, (const Sphere &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float Distance(const Capsule &in) const", AS_METHOD_FUNCTION_PR(Plane, Distance, (const Capsule &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float SignedDistance(const float3 &in) const", AS_METHOD_FUNCTION_PR(Plane, SignedDistance, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float3x4 OrthoProjection() const", AS_METHOD_FUNCTION_PR(Plane, OrthoProjection, () const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float3 Project(const float3 &in) const", AS_METHOD_FUNCTION_PR(Plane, Project, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "LineSegment Project(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(Plane, Project, (const LineSegment &) const, LineSegment), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(bool * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Plane", "Line Project(const Line &in,bool *) const", AS_METHOD_FUNCTION_PR(Plane, Project, (const Line &,bool *) const, Line), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(bool * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Plane", "Ray Project(const Ray &in,bool *) const", AS_METHOD_FUNCTION_PR(Plane, Project, (const Ray &,bool *) const, Ray), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "Triangle Project(const Triangle &in) const", AS_METHOD_FUNCTION_PR(Plane, Project, (const Triangle &) const, Triangle), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Plane", "Polygon Project(const Polygon &in) const", AS_METHOD_FUNCTION_PR(Plane, Project, (const Polygon &) const, Polygon), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float3x4 ObliqueProjection(const float3 &in) const", AS_METHOD_FUNCTION_PR(Plane, ObliqueProjection, (const float3 &) const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float3 ObliqueProject(const float3 &in,const float3 &in) const", AS_METHOD_FUNCTION_PR(Plane, ObliqueProject, (const float3 &,const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float3x4 MirrorMatrix() const", AS_METHOD_FUNCTION_PR(Plane, MirrorMatrix, () const, float3x4), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float3 Mirror(const float3 &in) const", AS_METHOD_FUNCTION_PR(Plane, Mirror, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float3 Refract(const float3 &in,float,float) const", AS_METHOD_FUNCTION_PR(Plane, Refract, (const float3 &,float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float3 ClosestPoint(const float3 &in) const", AS_METHOD_FUNCTION_PR(Plane, ClosestPoint, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float3 ClosestPoint(const Ray &in) const", AS_METHOD_FUNCTION_PR(Plane, ClosestPoint, (const Ray &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float3 ClosestPoint(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(Plane, ClosestPoint, (const LineSegment &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool Contains(const float3 &in,float) const", AS_METHOD_FUNCTION_PR(Plane, Contains, (const float3 &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool Contains(const Line &in,float) const", AS_METHOD_FUNCTION_PR(Plane, Contains, (const Line &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool Contains(const Ray &in,float) const", AS_METHOD_FUNCTION_PR(Plane, Contains, (const Ray &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool Contains(const LineSegment &in,float) const", AS_METHOD_FUNCTION_PR(Plane, Contains, (const LineSegment &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool Contains(const Triangle &in,float) const", AS_METHOD_FUNCTION_PR(Plane, Contains, (const Triangle &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool Contains(const Circle &in,float) const", AS_METHOD_FUNCTION_PR(Plane, Contains, (const Circle &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Plane", "bool Contains(const Polygon &in,float) const", AS_METHOD_FUNCTION_PR(Plane, Contains, (const Polygon &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool SetEquals(const Plane &in,float) const", AS_METHOD_FUNCTION_PR(Plane, SetEquals, (const Plane &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool Equals(const Plane &in,float) const", AS_METHOD_FUNCTION_PR(Plane, Equals, (const Plane &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool IsParallel(const Plane &in,float) const", AS_METHOD_FUNCTION_PR(Plane, IsParallel, (const Plane &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "float DihedralAngle(const Plane &in) const", AS_METHOD_FUNCTION_PR(Plane, DihedralAngle, (const Plane &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Line * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Plane", "bool Intersects(const Plane &in,const Plane &in,Line *,float3 *) const", AS_METHOD_FUNCTION_PR(Plane, Intersects, (const Plane &,const Plane &,Line *,float3 *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "Line IntersectsPlane(const Plane &in) const", AS_METHOD_FUNCTION_PR(Plane, IntersectsPlane, (const Plane &) const, Line), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Line * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Plane", "bool Intersects(const Plane &in,Line *) const", AS_METHOD_FUNCTION_PR(Plane, Intersects, (const Plane &,Line *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Plane", "bool Intersects(const Ray &in,float *) const", AS_METHOD_FUNCTION_PR(Plane, Intersects, (const Ray &,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Plane", "bool Intersects(const Line &in,float *) const", AS_METHOD_FUNCTION_PR(Plane, Intersects, (const Line &,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Plane", "bool Intersects(const LineSegment &in,float *) const", AS_METHOD_FUNCTION_PR(Plane, Intersects, (const LineSegment &,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool Intersects(const Sphere &in) const", AS_METHOD_FUNCTION_PR(Plane, Intersects, (const Sphere &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool Intersects(const AABB &in) const", AS_METHOD_FUNCTION_PR(Plane, Intersects, (const AABB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool Intersects(const OBB &in) const", AS_METHOD_FUNCTION_PR(Plane, Intersects, (const OBB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Plane", "bool Intersects(const Polygon &in) const", AS_METHOD_FUNCTION_PR(Plane, Intersects, (const Polygon &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Plane", "bool Intersects(const Polyhedron &in) const", AS_METHOD_FUNCTION_PR(Plane, Intersects, (const Polyhedron &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool Intersects(const Triangle &in) const", AS_METHOD_FUNCTION_PR(Plane, Intersects, (const Triangle &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool Intersects(const Frustum &in) const", AS_METHOD_FUNCTION_PR(Plane, Intersects, (const Frustum &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool Intersects(const Capsule &in) const", AS_METHOD_FUNCTION_PR(Plane, Intersects, (const Capsule &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Plane", "int Intersects(const Circle &in,float3 *,float3 *) const", AS_METHOD_FUNCTION_PR(Plane, Intersects, (const Circle &,float3 *,float3 *) const, int), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "int Intersects(const Circle &in) const", AS_METHOD_FUNCTION_PR(Plane, Intersects, (const Circle &) const, int), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("Plane", "bool Clip(LineSegment &) const", AS_METHOD_FUNCTION_PR(Plane, Clip, (LineSegment &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("Plane", "bool Clip(float3 &,float3 &) const", AS_METHOD_FUNCTION_PR(Plane, Clip, (float3 &,float3 &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "int Clip(const Line &in,Ray &out) const", AS_METHOD_FUNCTION_PR(Plane, Clip, (const Line &,Ray &) const, int), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("Plane", "int Clip(const Triangle &in,Triangle &,Triangle &) const", AS_METHOD_FUNCTION_PR(Plane, Clip, (const Triangle &,Triangle &,Triangle &) const, int), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "bool PassesThroughOrigin(float) const", AS_METHOD_FUNCTION_PR(Plane, PassesThroughOrigin, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Plane", "Circle GenerateCircle(const float3 &in,float) const", AS_METHOD_FUNCTION_PR(Plane, GenerateCircle, (const float3 &,float) const, Circle), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);



	r = engine->RegisterObjectProperty("Ray", "float3 pos", asOFFSET(Ray, pos)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Ray", "float3 dir", asOFFSET(Ray, dir)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Ray", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(Ray_ctor_, Ray, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Ray", asBEHAVE_CONSTRUCT, "void f(const float3 &in,const float3 &in)", AS_CONSTRUCTOR(Ray_ctor_const_float3_ref_const_float3_ref, Ray, (const float3 &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Ray", asBEHAVE_CONSTRUCT, "void f(const Line &in)", AS_CONSTRUCTOR(Ray_ctor_const_Line_ref, Ray, (const Line &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Ray", asBEHAVE_CONSTRUCT, "void f(const LineSegment &in)", AS_CONSTRUCTOR(Ray_ctor_const_LineSegment_ref, Ray, (const LineSegment &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "float3 GetPoint(float) const", AS_METHOD_FUNCTION_PR(Ray, GetPoint, (float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "void Transform(const float3x3 &in)", AS_METHOD_FUNCTION_PR(Ray, Transform, (const float3x3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "void Transform(const float3x4 &in)", AS_METHOD_FUNCTION_PR(Ray, Transform, (const float3x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "void Transform(const float4x4 &in)", AS_METHOD_FUNCTION_PR(Ray, Transform, (const float4x4 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "void Transform(const Quat &in)", AS_METHOD_FUNCTION_PR(Ray, Transform, (const Quat &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "bool Contains(const float3 &in,float) const", AS_METHOD_FUNCTION_PR(Ray, Contains, (const float3 &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "bool Contains(const LineSegment &in,float) const", AS_METHOD_FUNCTION_PR(Ray, Contains, (const LineSegment &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "bool Equals(const Ray &in,float) const", AS_METHOD_FUNCTION_PR(Ray, Equals, (const Ray &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Ray", "float Distance(const float3 &in,float *) const", AS_METHOD_FUNCTION_PR(Ray, Distance, (const float3 &,float *) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "float Distance(const float3 &in) const", AS_METHOD_FUNCTION_PR(Ray, Distance, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Ray", "float Distance(const Ray &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Ray, Distance, (const Ray &,float *,float *) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "float Distance(const Ray &in) const", AS_METHOD_FUNCTION_PR(Ray, Distance, (const Ray &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Ray", "float Distance(const Line &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Ray, Distance, (const Line &,float *,float *) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "float Distance(const Line &in) const", AS_METHOD_FUNCTION_PR(Ray, Distance, (const Line &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Ray", "float Distance(const LineSegment &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Ray, Distance, (const LineSegment &,float *,float *) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "float Distance(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(Ray, Distance, (const LineSegment &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "float Distance(const Sphere &in) const", AS_METHOD_FUNCTION_PR(Ray, Distance, (const Sphere &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "float Distance(const Capsule &in) const", AS_METHOD_FUNCTION_PR(Ray, Distance, (const Capsule &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Ray", "float3 ClosestPoint(const float3 &in,float *) const", AS_METHOD_FUNCTION_PR(Ray, ClosestPoint, (const float3 &,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Ray", "float3 ClosestPoint(const Ray &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Ray, ClosestPoint, (const Ray &,float *,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Ray", "float3 ClosestPoint(const Line &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Ray, ClosestPoint, (const Line &,float *,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Ray", "float3 ClosestPoint(const LineSegment &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Ray, ClosestPoint, (const LineSegment &,float *,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Ray", "bool Intersects(const Triangle &in,float *,float3 *) const", AS_METHOD_FUNCTION_PR(Ray, Intersects, (const Triangle &,float *,float3 *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "bool Intersects(const Triangle &in) const", AS_METHOD_FUNCTION_PR(Ray, Intersects, (const Triangle &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Ray", "bool Intersects(const Plane &in,float *) const", AS_METHOD_FUNCTION_PR(Ray, Intersects, (const Plane &,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "bool Intersects(const Plane &in) const", AS_METHOD_FUNCTION_PR(Ray, Intersects, (const Plane &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Ray", "bool Intersects(const Sphere &in,float3 *,float3 *,float *) const", AS_METHOD_FUNCTION_PR(Ray, Intersects, (const Sphere &,float3 *,float3 *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "bool Intersects(const Sphere &in) const", AS_METHOD_FUNCTION_PR(Ray, Intersects, (const Sphere &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Ray", "bool Intersects(const AABB &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Ray, Intersects, (const AABB &,float *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "bool Intersects(const AABB &in) const", AS_METHOD_FUNCTION_PR(Ray, Intersects, (const AABB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Ray", "bool Intersects(const OBB &in,float *,float *) const", AS_METHOD_FUNCTION_PR(Ray, Intersects, (const OBB &,float *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "bool Intersects(const OBB &in) const", AS_METHOD_FUNCTION_PR(Ray, Intersects, (const OBB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "bool Intersects(const Capsule &in) const", AS_METHOD_FUNCTION_PR(Ray, Intersects, (const Capsule &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Ray", "bool Intersects(const Polygon &in) const", AS_METHOD_FUNCTION_PR(Ray, Intersects, (const Polygon &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "bool Intersects(const Frustum &in) const", AS_METHOD_FUNCTION_PR(Ray, Intersects, (const Frustum &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Ray", "bool Intersects(const Polyhedron &in) const", AS_METHOD_FUNCTION_PR(Ray, Intersects, (const Polyhedron &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "bool IntersectsDisc(const Circle &in) const", AS_METHOD_FUNCTION_PR(Ray, IntersectsDisc, (const Circle &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "Line ToLine() const", AS_METHOD_FUNCTION_PR(Ray, ToLine, () const, Line), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Ray", "LineSegment ToLineSegment(float) const", AS_METHOD_FUNCTION_PR(Ray, ToLineSegment, (float) const, LineSegment), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);



	r = engine->RegisterObjectProperty("Sphere", "float3 pos", asOFFSET(Sphere, pos)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Sphere", "float r", asOFFSET(Sphere, r)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Sphere", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(Sphere_ctor_, Sphere, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Sphere", asBEHAVE_CONSTRUCT, "void f(const float3 &in,float)", AS_CONSTRUCTOR(Sphere_ctor_const_float3_ref_float, Sphere, (const float3 &,float)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Sphere", asBEHAVE_CONSTRUCT, "void f(const float3 &in,const float3 &in)", AS_CONSTRUCTOR(Sphere_ctor_const_float3_ref_const_float3_ref, Sphere, (const float3 &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Sphere", asBEHAVE_CONSTRUCT, "void f(const float3 &in,const float3 &in,const float3 &in)", AS_CONSTRUCTOR(Sphere_ctor_const_float3_ref_const_float3_ref_const_float3_ref, Sphere, (const float3 &,const float3 &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Sphere", asBEHAVE_CONSTRUCT, "void f(const float3 &in,const float3 &in,const float3 &in,const float3 &in)", AS_CONSTRUCTOR(Sphere_ctor_const_float3_ref_const_float3_ref_const_float3_ref_const_float3_ref, Sphere, (const float3 &,const float3 &,const float3 &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "AABB MinimalEnclosingAABB() const", AS_METHOD_FUNCTION_PR(Sphere, MinimalEnclosingAABB, () const, AABB), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "AABB MaximalContainedAABB() const", AS_METHOD_FUNCTION_PR(Sphere, MaximalContainedAABB, () const, AABB), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "void SetNegativeInfinity()", AS_METHOD_FUNCTION_PR(Sphere, SetNegativeInfinity, (), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "float Volume() const", AS_METHOD_FUNCTION_PR(Sphere, Volume, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "float SurfaceArea() const", AS_METHOD_FUNCTION_PR(Sphere, SurfaceArea, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "float3 Centroid() const", AS_METHOD_FUNCTION_PR(Sphere, Centroid, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "float3 ExtremePoint(const float3 &in) const", AS_METHOD_FUNCTION_PR(Sphere, ExtremePoint, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "bool IsFinite() const", AS_METHOD_FUNCTION_PR(Sphere, IsFinite, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "bool IsDegenerate() const", AS_METHOD_FUNCTION_PR(Sphere, IsDegenerate, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "bool Contains(const float3 &in) const", AS_METHOD_FUNCTION_PR(Sphere, Contains, (const float3 &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "bool Contains(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(Sphere, Contains, (const LineSegment &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "bool Contains(const Triangle &in) const", AS_METHOD_FUNCTION_PR(Sphere, Contains, (const Triangle &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Sphere", "bool Contains(const Polygon &in) const", AS_METHOD_FUNCTION_PR(Sphere, Contains, (const Polygon &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "bool Contains(const AABB &in) const", AS_METHOD_FUNCTION_PR(Sphere, Contains, (const AABB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "bool Contains(const OBB &in) const", AS_METHOD_FUNCTION_PR(Sphere, Contains, (const OBB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "bool Contains(const Frustum &in) const", AS_METHOD_FUNCTION_PR(Sphere, Contains, (const Frustum &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Sphere", "bool Contains(const Polyhedron &in) const", AS_METHOD_FUNCTION_PR(Sphere, Contains, (const Polyhedron &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "bool Contains(const Sphere &in) const", AS_METHOD_FUNCTION_PR(Sphere, Contains, (const Sphere &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "bool Contains(const Capsule &in) const", AS_METHOD_FUNCTION_PR(Sphere, Contains, (const Capsule &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "float Distance(const float3 &in) const", AS_METHOD_FUNCTION_PR(Sphere, Distance, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "float Distance(const Sphere &in) const", AS_METHOD_FUNCTION_PR(Sphere, Distance, (const Sphere &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "float Distance(const Capsule &in) const", AS_METHOD_FUNCTION_PR(Sphere, Distance, (const Capsule &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "float Distance(const AABB &in) const", AS_METHOD_FUNCTION_PR(Sphere, Distance, (const AABB &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "float Distance(const OBB &in) const", AS_METHOD_FUNCTION_PR(Sphere, Distance, (const OBB &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "float Distance(const Plane &in) const", AS_METHOD_FUNCTION_PR(Sphere, Distance, (const Plane &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "float Distance(const Triangle &in) const", AS_METHOD_FUNCTION_PR(Sphere, Distance, (const Triangle &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "float Distance(const Ray &in) const", AS_METHOD_FUNCTION_PR(Sphere, Distance, (const Ray &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "float Distance(const Line &in) const", AS_METHOD_FUNCTION_PR(Sphere, Distance, (const Line &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "float Distance(const LineSegment &in) const", AS_METHOD_FUNCTION_PR(Sphere, Distance, (const LineSegment &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "float3 ClosestPoint(const float3 &in) const", AS_METHOD_FUNCTION_PR(Sphere, ClosestPoint, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Sphere", "bool Intersects(const LineSegment &in,float3 *,float3 *,float *) const", AS_METHOD_FUNCTION_PR(Sphere, Intersects, (const LineSegment &,float3 *,float3 *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Sphere", "bool Intersects(const Line &in,float3 *,float3 *,float *) const", AS_METHOD_FUNCTION_PR(Sphere, Intersects, (const Line &,float3 *,float3 *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Sphere", "bool Intersects(const Ray &in,float3 *,float3 *,float *) const", AS_METHOD_FUNCTION_PR(Sphere, Intersects, (const Ray &,float3 *,float3 *,float *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "bool Intersects(const Plane &in) const", AS_METHOD_FUNCTION_PR(Sphere, Intersects, (const Plane &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Sphere", "bool Intersects(const AABB &in,float3 *) const", AS_METHOD_FUNCTION_PR(Sphere, Intersects, (const AABB &,float3 *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Sphere", "bool Intersects(const OBB &in,float3 *) const", AS_METHOD_FUNCTION_PR(Sphere, Intersects, (const OBB &,float3 *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Sphere", "bool Intersects(const Triangle &in,float3 *) const", AS_METHOD_FUNCTION_PR(Sphere, Intersects, (const Triangle &,float3 *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "bool Intersects(const Capsule &in) const", AS_METHOD_FUNCTION_PR(Sphere, Intersects, (const Capsule &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Sphere", "bool Intersects(const Polygon &in) const", AS_METHOD_FUNCTION_PR(Sphere, Intersects, (const Polygon &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "bool Intersects(const Frustum &in) const", AS_METHOD_FUNCTION_PR(Sphere, Intersects, (const Frustum &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Sphere", "bool Intersects(const Polyhedron &in) const", AS_METHOD_FUNCTION_PR(Sphere, Intersects, (const Polyhedron &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "bool Intersects(const Sphere &in) const", AS_METHOD_FUNCTION_PR(Sphere, Intersects, (const Sphere &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "void Enclose(const float3 &in)", AS_METHOD_FUNCTION_PR(Sphere, Enclose, (const float3 &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Sphere", "void Enclose(const float3 *,int)", AS_METHOD_FUNCTION_PR(Sphere, Enclose, (const float3 *,int), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "void Enclose(const LineSegment &in)", AS_METHOD_FUNCTION_PR(Sphere, Enclose, (const LineSegment &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "void Enclose(const AABB &in)", AS_METHOD_FUNCTION_PR(Sphere, Enclose, (const AABB &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "void Enclose(const OBB &in)", AS_METHOD_FUNCTION_PR(Sphere, Enclose, (const OBB &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Sphere", "void Enclose(const Sphere &in)", AS_METHOD_FUNCTION_PR(Sphere, Enclose, (const Sphere &), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("Sphere", "float3 RandomPointInside(LCG &)", AS_METHOD_FUNCTION_PR(Sphere, RandomPointInside, (LCG &), float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("Sphere", "float3 RandomPointOnSurface(LCG &)", AS_METHOD_FUNCTION_PR(Sphere, RandomPointOnSurface, (LCG &), float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Sphere", "int Triangulate(float3 *,float3 *,float2 *,int)", AS_METHOD_FUNCTION_PR(Sphere, Triangulate, (float3 *,float3 *,float2 *,int), int), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(const float3 * is not known to angelscript)*/ 	//.classmethod(// /*(const float3 * is not known to angelscript)*/ 	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(// /*(inout refs are not supported for value types)*/ 	//.classmethod(


	r = engine->RegisterObjectProperty("Triangle", "float3 a", asOFFSET(Triangle, a)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Triangle", "float3 b", asOFFSET(Triangle, b)); assert(r >= 0);
	r = engine->RegisterObjectProperty("Triangle", "float3 c", asOFFSET(Triangle, c)); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Triangle", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(Triangle_ctor_, Triangle, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectBehaviour("Triangle", asBEHAVE_CONSTRUCT, "void f(const float3 &in,const float3 &in,const float3 &in)", AS_CONSTRUCTOR(Triangle_ctor_const_float3_ref_const_float3_ref_const_float3_ref, Triangle, (const float3 &,const float3 &,const float3 &)), AS_CTOR_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float3 BarycentricUVW(const float3 &in) const", AS_METHOD_FUNCTION_PR(Triangle, BarycentricUVW, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float2 BarycentricUV(const float3 &in) const", AS_METHOD_FUNCTION_PR(Triangle, BarycentricUV, (const float3 &) const, float2), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float3 Point(float,float,float) const", AS_METHOD_FUNCTION_PR(Triangle, Point, (float,float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float3 Point(const float3 &in) const", AS_METHOD_FUNCTION_PR(Triangle, Point, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float3 Point(float,float) const", AS_METHOD_FUNCTION_PR(Triangle, Point, (float,float) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float3 Point(const float2 &in) const", AS_METHOD_FUNCTION_PR(Triangle, Point, (const float2 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float3 Centroid() const", AS_METHOD_FUNCTION_PR(Triangle, Centroid, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float Area() const", AS_METHOD_FUNCTION_PR(Triangle, Area, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float Perimeter() const", AS_METHOD_FUNCTION_PR(Triangle, Perimeter, () const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "LineSegment Edge(int) const", AS_METHOD_FUNCTION_PR(Triangle, Edge, (int) const, LineSegment), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float3 Vertex(int) const", AS_METHOD_FUNCTION_PR(Triangle, Vertex, (int) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "Plane PlaneCCW() const", AS_METHOD_FUNCTION_PR(Triangle, PlaneCCW, () const, Plane), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "Plane PlaneCW() const", AS_METHOD_FUNCTION_PR(Triangle, PlaneCW, () const, Plane), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float3 NormalCCW() const", AS_METHOD_FUNCTION_PR(Triangle, NormalCCW, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float3 NormalCW() const", AS_METHOD_FUNCTION_PR(Triangle, NormalCW, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float3 UnnormalizedNormalCCW() const", AS_METHOD_FUNCTION_PR(Triangle, UnnormalizedNormalCCW, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float3 UnnormalizedNormalCW() const", AS_METHOD_FUNCTION_PR(Triangle, UnnormalizedNormalCW, () const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float3 ExtremePoint(const float3 &in) const", AS_METHOD_FUNCTION_PR(Triangle, ExtremePoint, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Triangle", "Polygon ToPolygon() const", AS_METHOD_FUNCTION_PR(Triangle, ToPolygon, () const, Polygon), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Triangle", "Polyhedron ToPolyhedron() const", AS_METHOD_FUNCTION_PR(Triangle, ToPolyhedron, () const, Polyhedron), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "AABB BoundingAABB() const", AS_METHOD_FUNCTION_PR(Triangle, BoundingAABB, () const, AABB), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "bool IsFinite() const", AS_METHOD_FUNCTION_PR(Triangle, IsFinite, () const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "bool IsDegenerate(float) const", AS_METHOD_FUNCTION_PR(Triangle, IsDegenerate, (float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "bool Contains(const float3 &in,float) const", AS_METHOD_FUNCTION_PR(Triangle, Contains, (const float3 &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "bool Contains(const LineSegment &in,float) const", AS_METHOD_FUNCTION_PR(Triangle, Contains, (const LineSegment &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "bool Contains(const Triangle &in,float) const", AS_METHOD_FUNCTION_PR(Triangle, Contains, (const Triangle &,float) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float Distance(const float3 &in) const", AS_METHOD_FUNCTION_PR(Triangle, Distance, (const float3 &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float Distance(const Sphere &in) const", AS_METHOD_FUNCTION_PR(Triangle, Distance, (const Sphere &) const, float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Triangle", "bool Intersects(const LineSegment &in,float *,float3 *) const", AS_METHOD_FUNCTION_PR(Triangle, Intersects, (const LineSegment &,float *,float3 *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Triangle", "bool Intersects(const Line &in,float *,float3 *) const", AS_METHOD_FUNCTION_PR(Triangle, Intersects, (const Line &,float *,float3 *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Triangle", "bool Intersects(const Ray &in,float *,float3 *) const", AS_METHOD_FUNCTION_PR(Triangle, Intersects, (const Ray &,float *,float3 *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "bool Intersects(const Plane &in) const", AS_METHOD_FUNCTION_PR(Triangle, Intersects, (const Plane &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Triangle", "bool Intersects(const Sphere &in,float3 *) const", AS_METHOD_FUNCTION_PR(Triangle, Intersects, (const Sphere &,float3 *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "bool Intersects(const Sphere &in) const", AS_METHOD_FUNCTION_PR(Triangle, Intersects, (const Sphere &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(LineSegment * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Triangle", "bool Intersects(const Triangle &in,LineSegment *) const", AS_METHOD_FUNCTION_PR(Triangle, Intersects, (const Triangle &,LineSegment *) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "bool Intersects(const AABB &in) const", AS_METHOD_FUNCTION_PR(Triangle, Intersects, (const AABB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "bool Intersects(const OBB &in) const", AS_METHOD_FUNCTION_PR(Triangle, Intersects, (const OBB &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polygon is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Triangle", "bool Intersects(const Polygon &in) const", AS_METHOD_FUNCTION_PR(Triangle, Intersects, (const Polygon &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "bool Intersects(const Frustum &in) const", AS_METHOD_FUNCTION_PR(Triangle, Intersects, (const Frustum &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(Polyhedron is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Triangle", "bool Intersects(const Polyhedron &in) const", AS_METHOD_FUNCTION_PR(Triangle, Intersects, (const Polyhedron &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "bool Intersects(const Capsule &in) const", AS_METHOD_FUNCTION_PR(Triangle, Intersects, (const Capsule &) const, bool), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "void ProjectToAxis(const float3 &in,float &out,float &out) const", AS_METHOD_FUNCTION_PR(Triangle, ProjectToAxis, (const float3 &,float &,float &) const, void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("Triangle", "float3 ClosestPoint(const float3 &in) const", AS_METHOD_FUNCTION_PR(Triangle, ClosestPoint, (const float3 &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Triangle", "float3 ClosestPoint(const LineSegment &in,float3 *) const", AS_METHOD_FUNCTION_PR(Triangle, ClosestPoint, (const LineSegment &,float3 *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Triangle", "float3 ClosestPoint(const Line &in,float *,float *,float *) const", AS_METHOD_FUNCTION_PR(Triangle, ClosestPoint, (const Line &,float *,float *,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float3 * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Triangle", "float3 ClosestPoint(const Triangle &in,float3 *) const", AS_METHOD_FUNCTION_PR(Triangle, ClosestPoint, (const Triangle &,float3 *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Triangle", "float3 ClosestPointToTriangleEdge(const Line &in,float *,float *,float *) const", AS_METHOD_FUNCTION_PR(Triangle, ClosestPointToTriangleEdge, (const Line &,float *,float *,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(float * is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("Triangle", "float3 ClosestPointToTriangleEdge(const LineSegment &in,float *,float *,float *) const", AS_METHOD_FUNCTION_PR(Triangle, ClosestPointToTriangleEdge, (const LineSegment &,float *,float *,float *) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("Triangle", "float3 RandomPointInside(LCG &) const", AS_METHOD_FUNCTION_PR(Triangle, RandomPointInside, (LCG &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("Triangle", "float3 RandomVertex(LCG &) const", AS_METHOD_FUNCTION_PR(Triangle, RandomVertex, (LCG &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(inout refs are not supported for value types)*/ 	r = engine->RegisterObjectMethod("Triangle", "float3 RandomPointOnEdge(LCG &) const", AS_METHOD_FUNCTION_PR(Triangle, RandomPointOnEdge, (LCG &) const, float3), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(


	r = engine->RegisterObjectBehaviour("Clock", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(Clock_ctor_, Clock, ()), AS_CTOR_CONVENTION); assert(r >= 0);
	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(// /*(tick_t is not known to angelscript)*/ 	//.classmethod(


	r = engine->RegisterObjectBehaviour("LCG", asBEHAVE_CONSTRUCT, "void f()", AS_CONSTRUCTOR(LCG_ctor_, LCG, ()), AS_CTOR_CONVENTION); assert(r >= 0);
// /*(u32 is not known to angelscript)*/ 	r = engine->RegisterObjectBehaviour("LCG", asBEHAVE_CONSTRUCT, "void f(u32,u32,u32,u32)", AS_CONSTRUCTOR(LCG_ctor_u32_u32_u32_u32, LCG, (u32,u32,u32,u32)), AS_CTOR_CONVENTION); assert(r >= 0);
// /*(u32 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LCG", "void Seed(u32,u32,u32,u32)", AS_METHOD_FUNCTION_PR(LCG, Seed, (u32,u32,u32,u32), void), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(u32 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LCG", "u32 Int()", AS_METHOD_FUNCTION_PR(LCG, Int, (), u32), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(u32 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LCG", "u32 MaxInt() const", AS_METHOD_FUNCTION_PR(LCG, MaxInt, () const, u32), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
// /*(u32 is not known to angelscript)*/ 	r = engine->RegisterObjectMethod("LCG", "u32 IntFast()", AS_METHOD_FUNCTION_PR(LCG, IntFast, (), u32), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LCG", "int Int(int,int)", AS_METHOD_FUNCTION_PR(LCG, Int, (int,int), int), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LCG", "float Float()", AS_METHOD_FUNCTION_PR(LCG, Float, (), float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);
	r = engine->RegisterObjectMethod("LCG", "float Float(float,float)", AS_METHOD_FUNCTION_PR(LCG, Float, (float,float), float), AS_MEMBER_CALL_CONVENTION); assert(r >= 0);



}
