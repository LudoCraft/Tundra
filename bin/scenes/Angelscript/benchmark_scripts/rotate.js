print("Executing script.");

frame.Updated.connect(Update);

var time = 0;

function Update(frametime) {
    time += frametime;
    var m = new float3x3();
    m.SetRotatePartY(time);
    me.placeable.SetOrientation(m.ToQuat());
}
