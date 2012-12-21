engine.ImportExtension("qt.core");

me.rocketuidocument.DocumentChanged.connect(OnDocumentChanged);
var origPos;
var origSize;

function OnDocumentChanged()
{
    origPos = me.rocketuidocument.GetElementPosition("main");
    origSize = me.rocketuidocument.GetElementSize("main");
    frame.Updated.connect(OnUpdate);
}

function OnUpdate(dt)
{
    var newPos = new QPoint(origPos.x(), (Math.sin(frame.WallClockTime()*5)*0.5 + 0.5) * 100 + 200);
    //var newSize = new QPoint((Math.sin(frame.WallClockTime()*4)*0.5 + 0.5) * 200 + 300, origSize.y());
    //me.rocketuidocument.SetElementSize("main", newSize);
    me.rocketuidocument.SetElementPosition("main", newPos);
}