// For conditions of distribution and use, see copyright notice in LICENSE

#include "AssetRefListener.h"
#include "EC_RocketUiDocument.h"
#include "Framework.h"
#include "IAsset.h"
#include "LibRocketPlugin.h"
#include "LoggingFunctions.h"


#ifdef IN
#undef IN
#endif
#include <Rocket/Core.h>
#include <Rocket/Core/ElementDocument.h>

EC_RocketUiDocument::EC_RocketUiDocument(Scene* scene) :
    IComponent(scene),
    documentRef(this, "Document ref", AssetReference("", "BinaryAsset")),
    visible(this, "Visible", true),
    document(0)
{
    documentAsset = AssetRefListenerPtr(new AssetRefListener());
    connect(documentAsset.get(), SIGNAL(Loaded(AssetPtr)), this, SLOT(OnDocumentAssetLoaded(AssetPtr)), Qt::UniqueConnection);
}

EC_RocketUiDocument::~EC_RocketUiDocument()
{
    RemoveDocument();
}

void EC_RocketUiDocument::AttributesChanged()
{
    if (!ViewEnabled())
        return;
    
    if (documentRef.ValueChanged())
        documentAsset->HandleAssetRefChange(&documentRef);
    
    if (visible.ValueChanged() && document)
    {
        if (visible.Get())
            document->Show();
        else
            document->Hide();
    }
}

void EC_RocketUiDocument::OnDocumentAssetLoaded(AssetPtr asset)
{
    // Remove old document if any
    RemoveDocument();
    
    if (!asset)
    {
        LogError("Null Rocket UI document asset");
        return;
    }
    
    Rocket::Core::Context* context = GetContext();
    if (!context)
    {
        LogError("No Rocket UI context, can not instantiate document");
        return;
    }
    
    /// \todo Implement using the raw asset data without going through the disk
    document = context->LoadDocument(Rocket::Core::String(asset->DiskSource().toStdString().c_str()));
    if (!document)
    {
        LogError("Failed to instantiate Rocket UI document");
        return;
    }
    
    if (visible.Get())
        document->Show();
}

void EC_RocketUiDocument::RemoveDocument()
{
    if (document)
    {
        document->RemoveReference();
        Rocket::Core::Context* context = GetContext();
        if (context)
            context->UnloadDocument(document);
        document = 0;
    }
}

Rocket::Core::Context* EC_RocketUiDocument::GetContext()
{
    if (!framework)
        return 0;
    LibRocketPlugin* module = GetFramework()->GetModule<LibRocketPlugin>();
    return module ? module->GetContext() : 0;
}


