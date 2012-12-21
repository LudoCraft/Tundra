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
#include <Rocket/Controls/ElementFormControlInput.h>

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
    {
        if (!documentRef.Get().ref.trimmed().isEmpty())
            documentAsset->HandleAssetRefChange(&documentRef);
        else
            RemoveDocument();
    }
    
    if (visible.ValueChanged() && document)
    {
        if (visible.Get())
            document->Show();
        else
            document->Hide();
    }
}

void EC_RocketUiDocument::SetElementPosition(const QString &id, const QPoint& newPos)
{
    if (document)
    {
        Rocket::Core::Element* element = document->GetElementById(Rocket::Core::String(id.toStdString().c_str()));
        if (element)
            element->SetOffset(Rocket::Core::Vector2f((float)newPos.x(), (float)newPos.y()), element->GetOffsetParent());
        else
            LogWarning("Element " + id + " not found for SetElementPosition");
    }
}

void EC_RocketUiDocument::SetElementSize(const QString &id, const QPoint& newSize)
{
    if (document)
    {
        Rocket::Core::Element* element = document->GetElementById(Rocket::Core::String(id.toStdString().c_str()));
        if (element)
        {
            /// \todo Works reliably only when element has 1 geometry box
            Rocket::Core::Box box = element->GetBox();
            box.SetContent(Rocket::Core::Vector2f((float)newSize.x(), (float)newSize.y()));
            element->SetBox(box);
        }
        else
            LogWarning("Element " + id + " not found for SetElementSize");
    }
}

void EC_RocketUiDocument::SetElementValue(const QString &id, const QString &newValue)
{
    if (document)
    {
        Rocket::Core::Element* element = document->GetElementById(Rocket::Core::String(id.toStdString().c_str()));
        if (element)
        {
            Rocket::Controls::ElementFormControlInput* inputElem = dynamic_cast<Rocket::Controls::ElementFormControlInput*>(element);
            if (inputElem)
                inputElem->SetValue(Rocket::Core::String(newValue.toStdString().c_str()));
            else
                LogWarning("Element " + id + " is not an input element");
        }
        else
            LogWarning("Element " + id + " not found for SetElementValue");
    }
    
}

QPoint EC_RocketUiDocument::GetElementPosition(const QString &id) const
{
    if (document)
    {
        Rocket::Core::Element* element = document->GetElementById(Rocket::Core::String(id.toStdString().c_str()));
        if (element)
        {
            const Rocket::Core::Vector2f& pos = element->GetRelativeOffset();
            return QPoint((int)pos.x, (int)pos.y);
        }
    }
    
    LogWarning("Element " + id + " not found for GetElementPosition");
    return QPoint(0,0);
}

QPoint EC_RocketUiDocument::GetElementSize(const QString &id) const
{
    if (document)
    {
        Rocket::Core::Element* element = document->GetElementById(Rocket::Core::String(id.toStdString().c_str()));
        if (element)
        {
            const Rocket::Core::Box& box = element->GetBox();
            return QPoint(box.GetSize().x, box.GetSize().y);
        }
    }
    
    LogWarning("Element " + id + " not found for GetElementSize");
    return QPoint(0,0);
}

QString EC_RocketUiDocument::GetElementValue(const QString &id) const
{
    if (document)
    {
        Rocket::Core::Element* element = document->GetElementById(Rocket::Core::String(id.toStdString().c_str()));
        if (element)
        {
            Rocket::Controls::ElementFormControlInput* inputElem = dynamic_cast<Rocket::Controls::ElementFormControlInput*>(element);
            if (inputElem)
                return QString(inputElem->GetValue().CString());
            else
                LogWarning("Element " + id + " is not an input element");
        }
    }
    
    LogWarning("Element " + id + " not found for GetElementValue");
    return QString();
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
    
    // Add event listeners
    AddEventListeners(document);
    
    if (visible.Get())
        document->Show();
    
    emit DocumentChanged();
}

void EC_RocketUiDocument::RemoveDocument()
{
    if (document)
    {
        // Remove all event listeners we may have added
        RemoveEventListeners(document);
        
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

void EC_RocketUiDocument::AddEventListeners(Rocket::Core::Element* element)
{
    if (!element)
        return;
    
    Rocket::Controls::ElementFormControlInput* inputElem = dynamic_cast<Rocket::Controls::ElementFormControlInput*>(element);
    if (inputElem)
    {
        inputElem->AddEventListener("change", this);
        inputElem->AddEventListener("click", this);
    }
    
    int numChildren = element->GetNumChildren();
    for (int i = 0; i < numChildren; ++i)
        AddEventListeners(element->GetChild(i));
}

void EC_RocketUiDocument::RemoveEventListeners(Rocket::Core::Element* element)
{
    if (!element)
        return;
    
    Rocket::Controls::ElementFormControlInput* inputElem = dynamic_cast<Rocket::Controls::ElementFormControlInput*>(element);
    if (inputElem)
    {
        inputElem->RemoveEventListener("change", this);
        inputElem->RemoveEventListener("click", this);
    }
    
    int numChildren = element->GetNumChildren();
    for (int i = 0; i < numChildren; ++i)
        RemoveEventListeners(element->GetChild(i));
}

void EC_RocketUiDocument::ProcessEvent(Rocket::Core::Event& event)
{
    Rocket::Core::Element* sender = event.GetCurrentElement();
    if (!sender)
        return;
    
    if (event.GetType() == "click")
        emit ElementClicked(QString(sender->GetId().CString()), QString(sender->GetTagName().CString()));
    else if (event.GetType() == "change")
    {
        Rocket::Controls::ElementFormControlInput* inputElem = dynamic_cast<Rocket::Controls::ElementFormControlInput*>(sender);
        if (inputElem)
            emit ElementValueChanged(QString(inputElem->GetId().CString()), QString(inputElem->GetTagName().CString()), QString(inputElem->GetValue().CString()));
    }
}

