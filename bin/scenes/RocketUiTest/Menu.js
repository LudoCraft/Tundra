// !ref: image.png

if (!framework.IsHeadless())
{
    me.rocketuidocument.ElementClicked.connect(HandleClick);
}

function HandleClick(id, tag)
{
    if (id == "noanim")
    {
       scene.GetEntityByName("Animation").script.scriptRef = new AssetReference("");
       scene.GetEntityByName("Animation").rocketuidocument.documentRef = new AssetReference("");
    }
    if (id == "anim1")
       scene.GetEntityByName("Animation").script.scriptRef = new AssetReference("anim1.js");
    if (id == "anim2")
       scene.GetEntityByName("Animation").script.scriptRef = new AssetReference("anim2.js");
}
