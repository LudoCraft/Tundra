Scene @scene;

void main(Entity @me)
{
    print("Hello, world!");
    EC_Placeable @placeable = me.placeable;
    float3 pos = placeable.WorldPosition();
    print(pos.ToString());
    
    Scene@ scene = me.ParentScene();
    EntityPtr ent = scene.EntityById(1);
    Entity @e = ent.get();
    print(e.placeable.WorldPosition().ToString());
}
