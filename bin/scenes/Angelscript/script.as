void main(Entity @me)
{
    print("Hello, world!");
    EC_Placeable @placeable = me.placeable;
    float3 pos = placeable.WorldPosition();
    print(pos.ToString());
}
