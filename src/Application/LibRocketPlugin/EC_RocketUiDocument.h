// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#include "LibRocketPluginApi.h"
#include "IComponent.h"
#include "AssetFwd.h"
#include "AssetReference.h"

#include <Rocket/Core/EventListener.h>
#include <QPoint>

namespace Rocket
{
    namespace Core
    {
        class Context;
        class Element;
        class ElementDocument;
    }
}

/// Rocket UI document component.
/** <table class="header">
    <tr>
    <td>
    <h2>Avatar</h2>

    Registered by LibRocketPlugin.

    <b>Attributes</b>:
    <ul>
    <li>AssetReference: documentRef
    <div> @copydoc documentRef</div>
    <li>bool: loopSound
    <div> @copydoc loopSound </div>
    </ul>

    <b>Exposes the following scriptable functions:</b>
    <ul>
    </ul>

    <b>Reacts on the following actions:</b>
    <ul>
    </ul>

    Does not emit any actions.
    </table> */
class LIBROCKETPLUGIN_API EC_RocketUiDocument : public IComponent, public Rocket::Core::EventListener
{
    Q_OBJECT
    COMPONENT_NAME("EC_RocketUiDocument", 54)
    
    /// Asset id for the UI document
    Q_PROPERTY(AssetReference documentRef READ getdocumentRef WRITE setdocumentRef);
    DEFINE_QPROPERTY_ATTRIBUTE(AssetReference, documentRef);
    /// Visible flag
    Q_PROPERTY(bool visible READ getvisible WRITE setvisible);
    DEFINE_QPROPERTY_ATTRIBUTE(bool, visible);
    
public:
    /// Do not directly allocate new components using operator new, but use the factory-based SceneAPI::CreateComponent functions instead.
    explicit EC_RocketUiDocument(Scene* scene);
    /// Destructor.
    ~EC_RocketUiDocument();
    
    /// Return the Rocket UI document.
    Rocket::Core::ElementDocument* GetDocument() { return document; }
    
    /// Handle Rocket event.
    virtual void ProcessEvent(Rocket::Core::Event& event);

public slots:
    /// Set the position of an element within the document
    void SetElementPosition(const QString& id, const QPoint& newPos);
    /// Set the size of an element within the document
    void SetElementSize(const QString& id, const QPoint& newSize);
    /// Return the position of an element within the document
    QPoint GetElementPosition(const QString& id);
    /// Return the size of an element within the document
    QPoint GetElementSize(const QString& id);
    
signals:
    /// Signaled when the UI document has been created
    void DocumentChanged();
    
private slots:
    /// Called when document asset has been downloaded.
    void OnDocumentAssetLoaded(AssetPtr asset);
    
private:
    /// Attributes have changed, check for modifications.
    void AttributesChanged();
    /// Remove the UI document.
    void RemoveDocument();
    /// Get the Rocket UI context from the LibRocket module.
    Rocket::Core::Context* GetContext();
    /// Go through the elements in the document recursively and subscribe to applicable events.
    void ProcessElementRecursive(Rocket::Core::Element* element);
    
    /// Instantiated UI document.
    Rocket::Core::ElementDocument* document;
    /// Manages document asset requests.
    AssetRefListenerPtr documentAsset;
};
