// For conditions of distribution and use, see copyright notice in license.txt

#include "StableHeaders.h"
#include "DebugOperatorNew.h"

#include "Client.h"
#include "TundraLogicModule.h"
#include "EventManager.h"
#include "ModuleManager.h"
#include "KristalliProtocolModule.h"
#include "KristalliProtocolModuleEvents.h"
#include "CoreStringUtils.h"
#include "SyncManager.h"
#include "TundraMessages.h"
#include "TundraEvents.h"
#include "PhysicsModule.h"
#include "SceneManager.h"

#include "MsgLogin.h"
#include "MsgLoginReply.h"
#include "MsgClientJoined.h"
#include "MsgClientLeft.h"

#include "MemoryLeakCheck.h"

#include <QDomElement>

using namespace kNet;

namespace TundraLogic
{

Client::Client(TundraLogicModule* owner, Foundation::Framework* fw) :
    owner_(owner),
    framework_(fw),
    loginstate_(NotConnected),
    reconnect_(false),
    client_id_(0)
{
    tundraEventCategory_ = framework_->GetEventManager()->QueryEventCategory("Tundra");
    kristalliEventCategory_ = framework_->GetEventManager()->QueryEventCategory("Kristalli");
}

Client::~Client()
{
}

void Client::Update(f64 frametime)
{
    // If we aren't a server, check pending login
    if (!owner_->IsServer())
        CheckLogin();
}

void Client::Login(const QString& address, unsigned short port, const QString& username, const QString& password, const QString &protocol)
{
    SetLoginProperty("username", username);
    SetLoginProperty("password", password);
    SetLoginProperty("address", address);
    SetLoginProperty("protocol", protocol);
    SetLoginProperty("port", QString::number(port));
    kNet::SocketTransportLayer transportLayer = kNet::InvalidTransportLayer;
    if (protocol.toLower() == "tcp")
        transportLayer = kNet::SocketOverTCP;
    else if (protocol.toLower() == "udp")
        transportLayer = kNet::SocketOverUDP;
    Login(address, port, transportLayer);
}

void Client::Login(const QString& address, unsigned short port, kNet::SocketTransportLayer protocol)
{
    if (owner_->IsServer())
    {
        TundraLogicModule::LogError("Already running a server, cannot login to a world as a client");
        return;
    }
    
    reconnect_ = false;
    if (protocol == kNet::InvalidTransportLayer)
        protocol = owner_->GetKristalliModule()->defaultTransport;
    owner_->GetKristalliModule()->Connect(address.toStdString().c_str(), port, protocol);
    loginstate_ = ConnectionPending;
    client_id_ = 0;
}

void Client::Logout(bool fail)
{
    if (loginstate_ != NotConnected)
    {
        if (GetConnection())
        {
            owner_->GetKristalliModule()->Disconnect();
            TundraLogicModule::LogInfo("Disconnected");
        }
        
        loginstate_ = NotConnected;
        client_id_ = 0;
        
        framework_->GetEventManager()->SendEvent(tundraEventCategory_, Events::EVENT_TUNDRA_DISCONNECTED, 0);
        framework_->RemoveScene("TundraClient");
        
        emit Disconnected();
    }
    
    if (fail)
        framework_->GetEventManager()->SendEvent(tundraEventCategory_, Events::EVENT_TUNDRA_LOGIN_FAILED, 0);
    else // An user deliberately disconnected from the world, and not due to a connection error.
    {
        // Clear all the login properties we used for this session, so that the next login session will start from an
        // empty set of login properties (just-in-case).
        properties.clear();
    }
}

bool Client::IsConnected() const
{
    return loginstate_ == LoggedIn;
}

void Client::SetLoginProperty(QString key, QString value)
{
    key = key.trimmed();
    value = value.trimmed();
    if (value.isEmpty())
        properties.erase(key);
    properties[key] = value;
}

QString Client::GetLoginProperty(QString key)
{
    return properties[key.trimmed()];
}

QString Client::LoginPropertiesAsXml()
{
    QDomDocument xml;
    QDomElement rootElem = xml.createElement("login");
    for(std::map<QString, QString>::iterator iter = properties.begin(); iter != properties.end(); ++iter)
    {
        QDomElement elem = xml.createElement(iter->first.toStdString().c_str());
        elem.setAttribute("value", iter->second.toStdString().c_str());
        rootElem.appendChild(elem);
    }
    xml.appendChild(rootElem);
    return xml.toString();
}

void Client::CheckLogin()
{
    kNet::MessageConnection* connection = GetConnection();
    
    switch (loginstate_)
    {
    case ConnectionPending:
        if ((connection) && (connection->GetConnectionState() == kNet::ConnectionOK))
        {
            loginstate_ = ConnectionEstablished;
            MsgLogin msg;
            emit AboutToConnect(); // This signal is used as a 'function call'. Any interested party can fill in
            // new content to the login properties of the client object, which will then be sent out on the line below.
            msg.loginData = StringToBuffer(LoginPropertiesAsXml().toStdString());
            connection->Send(msg);
        }
        break;
    
    case LoggedIn:
        // If we have logged in, but connection dropped, prepare to resend login
        if ((!connection) || (connection->GetConnectionState() != kNet::ConnectionOK))
        {
            loginstate_ = ConnectionPending;
        }
        break;
    }
}

kNet::MessageConnection* Client::GetConnection()
{
    return owner_->GetKristalliModule()->GetMessageConnection();
}

void Client::HandleKristalliEvent(event_id_t event_id, IEventData* data)
{
    if (event_id == KristalliProtocol::Events::NETMESSAGE_IN)
    {
        if (!owner_->IsServer())
        {
            KristalliProtocol::Events::KristalliNetMessageIn* eventData = checked_static_cast<KristalliProtocol::Events::KristalliNetMessageIn*>(data);
            HandleKristalliMessage(eventData->source, eventData->id, eventData->data, eventData->numBytes);
        }
    }
    if (event_id == KristalliProtocol::Events::CONNECTION_FAILED)
    {
        Logout(true);
    }
}

void Client::HandleKristalliMessage(MessageConnection* source, message_id_t id, const char* data, size_t numBytes)
{
    if (source != GetConnection())
    {
        TundraLogicModule::LogWarning("Client: dropping message " + ToString(id) + " from unknown source");
        return;
    }
    
    switch (id)
    {
    case cLoginReplyMessage:
        {
            MsgLoginReply msg(data, numBytes);
            HandleLoginReply(source, msg);
        }
        break;
    case cClientJoinedMessage:
        {
            MsgClientJoined msg(data, numBytes);
            HandleClientJoined(source, msg);
        }
        break;
    case cClientLeftMessage:
        {
            MsgClientLeft msg(data, numBytes);
            HandleClientLeft(source, msg);
        }
        break;
    }
}

void Client::HandleLoginReply(MessageConnection* source, const MsgLoginReply& msg)
{
    if (msg.success)
    {
        loginstate_ = LoggedIn;
        client_id_ = msg.userID;
        TundraLogicModule::LogInfo("Logged in successfully");
        
        // Note: create scene & send info of login success only on first connection, not on reconnect
        if (!reconnect_)
        {
            Scene::ScenePtr scene = framework_->CreateScene("TundraClient", true);
            // Create physics world in client (non-authoritative) mode
            Physics::PhysicsModule *physics = framework_->GetModule<Physics::PhysicsModule>();
            physics->CreatePhysicsWorldForScene(scene, true);
            
            framework_->SetDefaultWorldScene(scene);
            owner_->GetSyncManager()->RegisterToScene(scene);
            
            Events::TundraConnectedEventData event_data;
            event_data.user_id_ = msg.userID;
            framework_->GetEventManager()->SendEvent(tundraEventCategory_, Events::EVENT_TUNDRA_CONNECTED, &event_data);
            
            emit Connected();
        }
        else
        {
            // If we are reconnecting, empty the scene, as the server will send everything again anyway
            // Note: when we move to unordered communication, we must guarantee that the server does not send
            // any scene data before the login reply
            Scene::ScenePtr scene = framework_->GetScene("TundraClient");
            if (scene)
                scene->RemoveAllEntities();
        }
        reconnect_ = true;
    }
    else
    {
        Logout(true);
    }
}

void Client::HandleClientJoined(MessageConnection* source, const MsgClientJoined& msg)
{
}

void Client::HandleClientLeft(MessageConnection* source, const MsgClientLeft& msg)
{
}

}
