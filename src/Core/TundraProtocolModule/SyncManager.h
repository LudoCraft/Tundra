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
/** SyncManager and SceneSyncState combined can be used to implement prioritization logic on how and when
    a sync state is filled per client connection. SyncManager object is only exposed to scripting on the server. */
class SyncManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool interestManagementEnabled READ IsInterestManagementEnabled WRITE SetInterestManagementEnabled) /**< @copydoc interestManagementEnabled */
    Q_PROPERTY(float updatePeriod READ UpdatePeriod WRITE SetUpdatePeriod) /**< @copydoc updatePeriod_ */

public:
    explicit SyncManager(TundraLogicModule* owner);
    ~SyncManager();

    /// Register to entity/component change signals from a specific scene and start syncing them
    void RegisterToScene(const ScenePtr &scene);

    /// Accumulate time & send pending sync messages if enough time passed from last update
    void Update(f64 frametime);

    /// Create new replication state for user and dirty it (server operation only)
    void NewUserConnected(const UserConnectionPtr &user);

    void SetInterestManagementEnabled(bool enable) { interestManagementEnabled = enable; }
    bool IsInterestManagementEnabled() const { return interestManagementEnabled; }

    /// Returns the update period
    float UpdatePeriod() const { return updatePeriod_; }

public slots:
    /// Sets the update period (seconds)
    /** @todo Doesn't need to be a slot, exposed as property. */
    void SetUpdatePeriod(float period);

    // DEPRECATED
    float GetUpdatePeriod() const { return UpdatePeriod(); } /**< @deprecated Use UpdatePeriod @ todo Remove */
    SceneSyncState* SceneState(int connectionId); /**< @deprecated Use UserConnection::SyncState @note Duplicate of of GetSceneSyncState @todo Add deprecated warning print and remove. */
    SceneSyncState* SceneState(const UserConnectionPtr &connection); /**< @deprecated Use UserConnection::SyncState @todo Add deprecated warning print and remove. */

signals:
    /// This signal is emitted when a new user connects and a new SceneSyncState is created for the connection.
    /// @note See signals of the SceneSyncState object to build prioritization logic how the sync state is filled.
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
    void QueueMessage(kNet::MessageConnection* connection, kNet::message_id_t id, bool reliable, bool inOrder, kNet::DataSerializer& ds);
    
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

    void HandleObserverPosition(kNet::MessageConnection* source, const char* data, size_t numBytes);

    /// Read client extrapolation time parameter from command line and match it to the current sync period.
    void GetClientExtrapolationTime();

    /// Process one sync state for changes in the scene
    /** \todo For now, sends all changed entities/components. In the future, this shall be subject to interest management
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

    /// (Re)computes priority for entity.
    void ComputePriorityForEntitySyncState(SceneSyncState *sceneState, EntitySyncState *entityState, Entity *entity);
    /// (Re)computes priorities for all entities in the scene.
    void ComputePrioritiesForEntitySyncStates(SceneSyncState *sceneState);

    /// Owning module
    TundraLogicModule* owner_;
    
    /// Framework pointer
    Framework* framework_;
    
    /// Scene pointer
    SceneWeakPtr scene_;
    
    /// Time period for update (seconds), default 1/20th of a second
    float updatePeriod_;
    /// Time accumulator for update
    float updateAcc_;
    
    /// Physics client interpolation/extrapolation period length as number of network update intervals (default 3)
    float maxLinExtrapTime_;
    /// Disable client physics handoff -flag
    bool noClientPhysicsHandoff_;
    
    /// Server sync state (client only)
    SceneSyncState serverSyncState;
    
    /// Fixed buffers for crafting messages
    char createEntityBuffer_[64 * 1024];
    char createCompsBuffer_[64 * 1024];
    char editAttrsBuffer_[64 * 1024];
    char createAttrsBuffer_[16 * 1024];
    char attrDataBuffer_[16 * 1024];
    char removeCompsBuffer_[1024];
    char removeEntityBuffer_[1024];
    char removeAttrsBuffer_[1024];
    std::vector<u8> changedAttributes_;

    bool interestManagementEnabled; ///< Is the interest management enabled.
};

}
