// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#include "AssetFwd.h"
#include "CoreTypes.h"
#include "IModule.h"
#include "InputFwd.h"
#include "LibRocketPluginApi.h"

#include <Ogre/OgreRenderQueueListener.h>
#include <map>

class OgreWorld;
class RenderInterfaceOgre3D;
class SystemInterfaceTundra;

namespace Rocket
{
    namespace Core
    {
        class Context;
    }
}

/// LibRocket UI interface plugin. Instantiates the Rocket UI.
class LIBROCKETPLUGIN_API LibRocketPlugin : public IModule, public Ogre::RenderQueueListener
{
    Q_OBJECT
    
public:
    LibRocketPlugin();
    ~LibRocketPlugin();
    
    // IModule override
    void Initialize();
    
    // IModule override
    void Unload();
    
    // IModule override
    void Update(f64 timeStep);
    
    /// Return the LibRocket UI context
    Rocket::Core::Context* GetContext() { return context; }
    
    /// Called from Ogre before a queue group is rendered. Used for Rocket UI rendering
    virtual void renderQueueStarted(unsigned char queueGroupId, const Ogre::String& invocation, bool& skipThisInvocation);
    
public slots:
    /// Load a font from an asset.
    void LoadFont(const QString& assetRef);
    
private slots:
    /// Resize LibRocket UI context when Ogre renderwindow changes size
    void OnRenderWindowResized(int width, int height);
    
    /// Handle font asset having been loaded
    void OnFontAssetLoaded(AssetPtr asset);
    
    /// Create Rocket renderqueue listener to a new scene
    void OnOgreWorldCreated(OgreWorld* world);
    
    /// Handle a mouse event and inject it to Rocket
    void OnMouseEventReceived(MouseEvent* evt);
    
    /// Handle a keyboard event and inject it to Rocket
    void OnKeyEventReceived(KeyEvent* evt);
    
private:
    /// Configure Ogre for UI rendering
    void ConfigureRenderSystem();
    
    /// Gather the current qualifier flags for LibRocket from keyboard
    int GetQualifierFlags();
    
    /// Convert Qt mouse button index to LibRocket
    int ConvertMouseButton(int button);
    
    /// Initialize keycode conversion map
    void InitKeyCodeMap();
    
    /// Rocket rendering interface
    RenderInterfaceOgre3D* renderInterface;

    /// Rocket system interface
    SystemInterfaceTundra* systemInterface;

    /// Rocket main UI context
    Rocket::Core::Context* context;

    /// Input context for injecting input to Rocket
    InputContextPtr inputContext;

    /// Keycode mapping between Qt & Rocket
    std::map<int, int> keyCodeMap;
};
