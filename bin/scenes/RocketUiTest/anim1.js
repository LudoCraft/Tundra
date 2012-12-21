engine.ImportExtension("qt.core");

var animationStarted = false;

me.rocketuidocument.DocumentChanged.connect(StartAnimation);
me.rocketuidocument.documentRef = new AssetReference("tree.rml");

function StartAnimation()
{
    if (!animationStarted)
    {
        frame.Updated.connect(OnFrameUpdate);
        animationStarted = true;
    }
}

function OnFrameUpdate()
{
    var size = ((Math.sin(frame.WallClockTime())*0.5)+0.5) * 150 + 150;
    var x = ((Math.sin(frame.WallClockTime()*2.0)*0.5)+0.5) * 400 + 200;
    var y = ((Math.sin(frame.WallClockTime()*1.5)*0.5)+0.5) * 300 + 100;

    me.rocketuidocument.SetElementSize("tree", new QPoint(size, size));
    me.rocketuidocument.SetElementPosition("tree", new QPoint(x, y));
}