engine.ImportExtension("qt.core");

var animationStarted = false;

me.rocketuidocument.DocumentChanged.connect(StartAnimation);
me.rocketuidocument.documentRef = new AssetReference("labels.rml");

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
    for (var i = 0; i < 10; ++i)
    {
        var elemName = "div" + (i+1);

        var oldPos = me.rocketuidocument.GetElementPosition(elemName);
        var y = ((Math.sin(frame.WallClockTime() + i*0.25)*0.5)+0.5) * 500 + 200;
        me.rocketuidocument.SetElementPosition(elemName, new QPoint(oldPos.x(), y));
    }
}
