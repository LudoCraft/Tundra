// For conditions of distribution and use, see copyright notice in LICENSE

#pragma once

#include "TundraProtocolModuleFwd.h"
#include "SyncState.h"
#include "SceneFwd.h"
#include "AttributeChangeType.h"
#include "EntityAction.h"

#include <kNetFwd.h>
#include <kNet/Types.h>

#include <QObject>

class Framework;

namespace TundraLogic
{
/// Performs synchronization of the changes in a scene between the server and the client.
/** @todo Interest management functionality description.

    Alternatively, SyncManager and SceneSyncState can be used to implement prioritization logic on how and when
    a sync state is filled per client connection. */
class SyncManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float updatePeriod READ UpdatePeriod WRITE SetUpdatePeriod) /**< @copydoc updatePeriod_ */
    Q_PROPERTY(bool interestManagementEnabled READ IsInterestManagementEnabled WRITE SetInterestManagementEnabled) /**< @copydoc interestManagementEnabled */
    Q_PROPERTY(Entity *observer READ Observer WRITE SetObserver) /**< @copydoc observer */

public:
    explicit SyncManager(TundraLogicModule* owner);
    ~SyncManager();

    /// Registers to entity/component change signals from a specific scene and start syncing them
    void RegisterToScene(const ScenePtr &scene);

    /// Accumulates time & sends pending sync messages if enough time passed from last update
    void Update(f64 frametime);

    /// Creates new replication state for user and dirties it (server operation only)
    void NewUserConnected(const UserConnectionPtr &user);

    /// Enables or disables the interest management. @remark Interest management
    void SetInterestManagementEnabled(bool enabled) { interestManagementEnabled = enabled; }
    /// Returns is the interest management enabled. @remark Interest management
    bool IsInterestManagementEnabled() const { return interestManagementEnabled; }

    /// Sets the client's observer entity. @remark Interest management
    /** @note The entity needs to have EC_Placeable present. */
    void SetObserver(Entity *entity);
    /// Returns the observer entity, if any. @remark Interest management
    Entity *Observer() const { return observer.lock().get(); }

    /// Returns the update period
    float UpdatePeriod() const { return updatePeriod_; }

public slots:
    // DEPRECATED
    /// Sets the update period (seconds) @todo Doens't need to be a slot, exposed as property.
    void SetUpdatePeriod(float period); /**< @deprecated From scripts use 'updatePeriod' property @todo Make a non-slot. */
    float GetUpdatePeriod() const { return UpdatePeriod(); } /**< @deprecated Use UpdatePeriod or 'updatePeriod' @todo Remove */
    SceneSyncState* SceneState(int connectionId); /**< @deprecated Use UserConnection::SyncState @note Duplicate of of GetSceneSyncState. */
    SceneSyncState* SceneState(const UserConnectionPtr &connection); /**< @deprecated Use UserConnection::SyncState. */

signals:
    /// This signal is emitted when a new user connects and a new SceneSyncState is created for the connection.
    /// @note See signals of the SceneSyncState object to build prioritization logic how the sync state is filled.
    /// @remark Enables a 'pending' logic in SyncManager, with which a script can throttle the sending of entities to clients.
    void SceneStateCreated(UserConnection *user, SceneSyncState *state);

private slots:
    /// Trigger EC sync because of component attributes changing
    void OnAttributeChanged(IComponent* comp, IAttribute* attr, AttributeChange::Type change);

    /// Trigger EC sync because of component attribute added
    void OnAttributeAdded(IComponent* comp, IAttribute* attr, AttributeChange::Type change);

    /// Trigger EC sync because of component attribute removed
    void OnAttributeRemoved(IComponent* comp, IAttribute* attr, AttributeChange::Type change);
    
    /// Trigger EC sync because of component added to entity
    void OnComponentAdded(Entity* entity, IComponent* comp, AttributeChange::Type change);
    
    /// Trigger EC sync because of component removed from entity
    void OnComponentRemoved(Entity* entity, IComponent* comp, AttributeChange::Type change);
    
    /// Trigger sync of entity creation
    void OnEntityCreated(Entity* entity, AttributeChange::Type change);
    
    /// Trigger sync of entity removal
    void OnEntityRemoved(Entity* entity, AttributeChange::Type change);

    /// Trigger sync of entity action.
    void OnActionTriggered(Entity *entity, const QString &action, const QStringList &params, EntityAction::ExecTypeField type);

    /// Trigger sync of entity action to specific user
    void OnUserActionTriggered(UserConnection* user, Entity *entity, const QString &action, const QStringList &params);

    /// Handle a Kristalli protocol message
    void HandleKristalliMessage(kNet::MessageConnection* source, kNet::packet_id_t, kNet::message_id_t id, const char* data, size_t numBytes);

private:
    /// Queue a message to the receiver from a given DataSerializer.
    void QueueMessage(kNet::MessageConnection* connection, kNet::message_id_t id, bool reliable, bool inOrder, kNet::DataSerializer& ds, EntitySyncState *state = 0);

    /// Craft a component full update, with all static and dynamic attributes.
    void WriteComponentFullUpdate(kNet::DataSerializer& ds, const ComponentPtr &comp);
    
    /// Handle entity action message.
    void HandleEntityAction(kNet::MessageConnection* source, MsgEntityAction& msg);
    /// Handle create entity message.
    void HandleCreateEntity(kNet::MessageConnection* source, const char* data, size_t numBytes);
    /// Handle create components message.
    void HandleCreateComponents(kNet::MessageConnection* source, const char* data, size_t numBytes);
    /// Handle create attributes message.
    void HandleCreateAttributes(kNet::MessageConnection* source, const char* data, size_t numBytes);
    /// Handle edit attributes message.
    void HandleEditAttributes(kNet::MessageConnection* source, const char* data, size_t numBytes);
    /// Handle remove attributes message.
    void HandleRemoveAttributes(kNet::MessageConnection* source, const char* data, size_t numBytes);
    /// Handle remove components message.
    void HandleRemoveComponents(kNet::MessageConnection* source, const char* data, size_t numBytes);
    /// Handle remove entities message.
    void HandleRemoveEntity(kNet::MessageConnection* source, const char* data, size_t numBytes);
    /// Handle create entity reply message.
    void HandleCreateEntityReply(kNet::MessageConnection* source, const char* data, size_t numBytes);
    /// Handle create components reply message.
    void HandleCreateComponentsReply(kNet::MessageConnection* source, const char* data, size_t numBytes);
    
    void HandleRigidBodyChanges(kNet::MessageConnection* source, kNet::packet_id_t packetId, const char* data, size_t numBytes);

    void ReplicateRigidBodyChanges(kNet::MessageConnection* destination, SceneSyncState* state);

    void InterpolateRigidBodies(f64 frametime, SceneSyncState* state);

    /// @remark Interest management.
    void HandleObserverPosition(kNet::MessageConnection* source, const char* data, size_t numBytes);

    /// Read client extrapolation time parameter from command line and match it to the current sync period.
    void GetClientExtrapolationTime();

    /// Process one sync state for changes in the scene
    /** If interestManagementEnabled == true, interest management prioritization will be used.
        @param destination MessageConnection where to send the messages
        @param state Syncstate to process */
    void ProcessSyncState(kNet::MessageConnection* destination, SceneSyncState* state);
    
    /// Validate the scene manipulation action. If returns false, it is ignored
    /** @param source Where the action came from
        @param messageID Network message id
        @param entityID What entity it affects */
    bool ValidateAction(kNet::MessageConnection* source, unsigned messageID, entity_id_t entityID);
    
    /// Get a syncstate that matches the messageconnection, for reflecting arrived changes back
    /** For client, this will always be serverSyncState. */
    SceneSyncState* GetSceneSyncState(kNet::MessageConnection* connection);

    ScenePtr GetRegisteredScene() const { return scene_.lock(); }

    /// Sends client's observer information. @remark Interest management
    void SendObserverPosition(kNet::MessageConnection* connection, SceneSyncState *senderState);
    /// (Re)computes priority for entity. @remark Interest management
    void ComputePriorityForEntitySyncState(SceneSyncState *sceneState, EntitySyncState *entityState, Entity *entity) const;
    /// (Re)computes priorities for all entities in the scene. @remark Interest management
    void ComputePrioritiesForEntitySyncStates(SceneSyncState *sceneState) const;

    TundraLogicModule* owner_;
    Framework* framework_;
    SceneWeakPtr scene_; ///< Scene that is being synced.
    float updatePeriod_; ///< Time period for update (seconds), by default 1/20th of a second
    float updateAcc_; ///< Time accumulator for update
    float maxLinExtrapTime_; ///< Physics client interpolation/extrapolation period length as number of network update intervals (default 3)
    bool noClientPhysicsHandoff_; ///< Disable client physics handoff -flag
    SceneSyncState serverSyncState; ///< Server sync state (client only)

    // Fixed buffers for crafting messages
    char createEntityBuffer_[64 * 1024];
    char createCompsBuffer_[64 * 1024];
    char editAttrsBuffer_[64 * 1024];
    char createAttrsBuffer_[16 * 1024];
    char attrDataBuffer_[16 * 1024];
    char removeCompsBuffer_[1024];
    char removeEntityBuffer_[1024];
    char removeAttrsBuffer_[1024];
    std::vector<u8> changedAttributes_;

    bool interestManagementEnabled; ///< Is the interest management enabled. @remark Interest management
    EntityWeakPtr observer; ///< If interestManagementEnabled true, the client's observer position information is sent to the server. @remark Interest management
};

}
