Entity @me;

void main(Entity @me_)
{
    @me = me_;
    print("Hello, world!");

    EC_Placeable @placeable = me.placeable;
    float3 pos = placeable.WorldPosition();
    print(pos.ToString());
    
    Scene@ scene = me.ParentScene();
    EntityPtr ent = scene.EntityById(1);
    Entity @e = ent.get();
    print(e.placeable.WorldPosition().ToString());
    
    e.placeable.SetPosition(4,5,6);
}

float time = 0;

void update(float dt)
{
    time += dt;
    float3x3 m;
    m.SetRotatePartY(time);
    me.placeable.SetOrientation(m.ToQuat());
}
