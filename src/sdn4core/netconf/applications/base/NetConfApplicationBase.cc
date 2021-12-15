//
// c Timo Haeckel, for HAW Hamburg
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "NetConfApplicationBase.h"

//STD
#include <string>
//INET
#include "inet/networklayer/common/L3AddressResolver.h"
//SDN4CoRE
#include <sdn4core/netconf/applications/configparser/base/NetConfAppConfigParserCollection.h>
#include <sdn4core/utility/xml/XMLUtility.h>

namespace SDN4CoRE {

Define_Module(NetConfApplicationBase);
#define SELFMESSAGE_SEND_NETCONF "Send Netconf"


NetConfApplicationBase::~NetConfApplicationBase() {
    for(auto conn : this->_connections){
        for(auto config : conn.configurations){
            delete config;
        }
    }
}

void NetConfApplicationBase::initialize() {
    cXMLElement* xmlServerConnections = par("serverConnections").xmlValue();
    if (xmlServerConnections) {
        if (strcmp(xmlServerConnections->getName(), "server_connections")
                == 0) {
            cXMLElementList applicationsXML =
                    xmlServerConnections->getChildrenByTagName("application");
            for (size_t i = 0; i < applicationsXML.size(); i++) {
                std::string clientAppHost = getStringAttributeFromXML(applicationsXML[i],"client_host");
                int clientAppIndex = getIntAttributeFromXML(applicationsXML[i],"client_app");
                const char* realHost = getParentModule()->getParentModule()->getFullName();
                if (clientAppIndex == getIndex() && (strcmp(realHost, clientAppHost.c_str()) == 0)) {

                    auto connectionList = NetConfAppConfigParserCollection::parseXMLConnectionList(
                            applicationsXML[i]->getChildrenByTagName("connection"), true);
                    for(auto connection : connectionList) {
                        _connections.push_back(connection);
                    }
                }
            }
        }
    }
    WATCH_VECTOR(_connections);
    bool scheduled = scheduleNextConnection();
    if (getEnvir()->isGUI()) {
        if(scheduled) {
            getDisplayString().setTagArg("i2", 0, "status/asleep");
        } else {
            getDisplayString().setTagArg("i2", 0, "status/stop");
        }
    }
}

bool NetConfApplicationBase::scheduleNextConnection() {
    bool scheduled = false;
    int index = -1;
    SimTime next = SimTime::getMaxTime();
    for (size_t i = 0; i < _connections.size(); i++) {
        auto connection = _connections[i];
        if (connection.connectAt < next && connection.connectAt >= simTime()
                && (connection.state
                        == ConnectionState_t::ConnectionStateWaiting)) {
            index = i;
            next = connection.connectAt;
        }
    }

    if (index > -1) {
        _connections[index].state = ConnectionState_t::ConnectionStateScheduled;
        cMessage* msg = new cMessage(SELFMESSAGE_SEND_HELLO);
        msg->setContextPointer(&_connections[index]);
        scheduleAt(next, msg);
        scheduled = true;
    }
    return scheduled;
}

bool NetConfApplicationBase::scheduleNextConfigurationFor(
        Connection_t* connection) {
    bool scheduled = false;
    if (connection
            && (connection->state
                    == ConnectionState_t::ConnectionStateEstablished)) {
        int index = -1;
        SimTime next = SimTime::getMaxTime();
        for (size_t i = 0; i < connection->configurations.size(); i++) {
            auto configuration = connection->configurations[i];
            if (configuration->executeAt < next
                    && configuration->executeAt >= simTime()
                    && (configuration->state
                            == Configuration_t::ConfigurationState_t::ConfigurationStateWaiting)) {
                index = i;
                next = configuration->executeAt;
            }
        }

        if (index > -1) {
            NetConfMessage_RPC* rpc = createNetConfRPCForConfiguration(
                    connection, connection->configurations[index], std::to_string(index));
            if (rpc) {
                rpc->setContextPointer(connection);
                cMessage* msg = new cMessage(SELFMESSAGE_SEND_NETCONF);
                msg->setContextPointer(rpc);
                scheduleAt(next, msg);
                scheduled = true;
                connection->configurations[index]->state =
                        Configuration_t::ConfigurationState_t::ConfigurationStateScheduled;
            } else {
                connection->configurations[index]->state =
                        Configuration_t::ConfigurationState_t::ConfigurationStateError;
            }
        }
    }
    return scheduled;
}

void NetConfApplicationBase::handleMessage(cMessage *msg) {
    static int activeConnections = 0;
    static int activeConfigurations = 0;
    bool scheduled = false;
    if (msg->isSelfMessage()) {
        if (strcmp(msg->getName(), SELFMESSAGE_SEND_HELLO) == 0) {

            Connection_t* connection =
                    static_cast<Connection_t*>(msg->getContextPointer());
            if (connection) {
                send(createHelloFor(connection), gate("applicationOut"));
                connection->state = ConnectionState_t::ConnectionStateRequested;
                activeConnections++;
                if (getEnvir()->isGUI())
                {
                    getDisplayString().setTagArg("i2", 0, "status/active");
                }
            }
            scheduled = scheduleNextConnection();
        } else if (strcmp(msg->getName(), SELFMESSAGE_SEND_NETCONF) == 0) {

            NetConfMessage_RPC* rpc = static_cast<NetConfMessage_RPC*> (msg->getContextPointer());
            if(rpc){
                Connection_t* connection =
                                    static_cast<Connection_t*>(rpc->getContextPointer());
                NetConfCtrlInfo* ctrl = dynamic_cast<NetConfCtrlInfo*>(rpc->getControlInfo());
                if(ctrl && connection){
                    connection->configurations[atoi(ctrl->getMessage_id())]->state = Configuration_t::ConfigurationState_t::ConfigurationStateRequested;
                    send(rpc, gate("applicationOut"));
                    activeConfigurations++;
                    scheduled = scheduleNextConfigurationFor(connection);
                    if(!scheduled) {
                        activeConnections--;
                    }
                }
            }
        }
    } else if (NetConfHello* hello = dynamic_cast<NetConfHello*>(msg)) {
        NetConfClientSessionInfoTCP* sessionInfo =
                (NetConfClientSessionInfoTCP*) hello->getContextPointer();
        Connection_t* connection = mapSessionInfoToConnection(sessionInfo);
        if (connection) {
            connection->session_id = sessionInfo->getSessionId();
            connection->state = ConnectionState_t::ConnectionStateEstablished;
            scheduled = scheduleNextConfigurationFor(connection);
            if(!scheduled) {
                activeConnections--;
            }
        }
    } else if (NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg)){
        if(NetConfCtrlInfo* info = dynamic_cast<NetConfCtrlInfo*>(reply->getControlInfo())){
            Connection_t* found = nullptr;
            for (size_t i = 0; i < _connections.size(); i++) {
                auto& connection = _connections[i];
                if (connection.state
                        == ConnectionState_t::ConnectionStateEstablished
                        && connection.session_id == info->getSession_id()) {
                    found = &connection;
                }
            }
            if(found){
                activeConfigurations--;
                if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket())){
                    found->configurations[atoi(info->getMessage_id())]->state = Configuration_t::ConfigurationState_t::ConfigurationStateSuccess;
                } else if(dynamic_cast<NetConf_RPCReplyElement_Error*>(reply->getEncapsulatedPacket())) {
                    found->configurations[atoi(info->getMessage_id())]->state = Configuration_t::ConfigurationState_t::ConfigurationStateError;
                }
            }
        }
    }
    if (getEnvir()->isGUI()) {
        if(activeConfigurations + activeConnections > 0) {
            //we are active
            getDisplayString().setTagArg("i2", 0, "status/active");
        } else if(scheduled) {
            getDisplayString().setTagArg("i2", 0, "status/asleep");
        } else {
            getDisplayString().setTagArg("i2", 0, "status/check");
        }
    }
    delete msg;
}

NetConfHello* NetConfApplicationBase::createHelloFor(
        Connection_t* connection) {
    NetConfHello* hello = new NetConfHello("NetConfHello");

    NetConfClientCtrlInfo_Connection* ctrl =
            new NetConfClientCtrlInfo_Connection();
    ctrl->setConnectAddress(connection->remoteAddress.c_str());
    ctrl->setConnectPort(connection->remotePort);
    ctrl->setLocalPort(connection->localPort);

    hello->setControlInfo(ctrl);
    return hello;
}

NetConfOperation_EditConfig* NetConfApplicationBase::createEditConfigOperation(
        Configuration_t* config) {
    NetConfOperation_EditConfig* editconfig =
                        new NetConfOperation_EditConfig();
    editconfig->setTarget(config->target.c_str());
    editconfig->encapsulate(config->data->dup());
    editconfig->setDefaultOperation(
            NetConfOperation_Operation::NETCONFOPERATION_OPERATION_MERGE);
    editconfig->setErrorOption(
            NetConfOperation_ErrorOption::NETCONFOPERATION_ERROROPTION_CONTINUEONERROR);
    editconfig->addByteLength(sizeof(editconfig->getTarget()));
    return editconfig;
}

NetConfOperation_GetConfig* NetConfApplicationBase::createGetConfigOperation(
        Configuration_t* config) {
    NetConfOperation_GetConfig* getconfig =
                        new NetConfOperation_GetConfig();
    getconfig->setSource(config->source.c_str());
    getconfig->setFilter(*(config->filter));
    getconfig->addByteLength(
            sizeof(getconfig->getSource())
                    + config->filter->getByteSize());
    return getconfig;
}

NetConfOperation_CopyConfig* NetConfApplicationBase::createCopyConfigOperation(
        Configuration_t* config) {
    NetConfOperation_CopyConfig* copyconfig =
                        new NetConfOperation_CopyConfig();
    copyconfig->setSource(config->source.c_str());
    copyconfig->setTarget(config->target.c_str());
    copyconfig->addByteLength(
            sizeof(copyconfig->getSource())
                    + sizeof(copyconfig->getTarget()));
    return copyconfig;
}

NetConfOperation_DeleteConfig* NetConfApplicationBase::createDeleteConfigOperation(
        Configuration_t* config) {
    NetConfOperation_DeleteConfig* deleteconfig =
                        new NetConfOperation_DeleteConfig();
    deleteconfig->setTarget(config->target.c_str());
    deleteconfig->addByteLength(
                    sizeof(deleteconfig->getTarget()));
    return deleteconfig;
}

NetConfOperation_Lock* NetConfApplicationBase::createLockOperation(
        Configuration_t* config){
    NetConfOperation_Lock* lock =
                        new NetConfOperation_Lock();
    lock->setTarget(config->target.c_str());
    lock->addByteLength(
                    sizeof(lock->getTarget()));
    return lock;
}

NetConfOperation_Unlock* NetConfApplicationBase::createUnlockOperation(
        Configuration_t* config){
    NetConfOperation_Unlock* unlock =
                        new NetConfOperation_Unlock();
    unlock->setTarget(config->target.c_str());
    unlock->addByteLength(
                    sizeof(unlock->getTarget()));
    return unlock;
}

NetConfOperation_Commit* NetConfApplicationBase::createCommitOperation(
        Configuration_t* config){
    NetConfOperation_Commit* commit =
                        new NetConfOperation_Commit();
    return commit;
}

NetConfCtrlInfo* NetConfApplicationBase::createControlInfo(int messageType, int sessionId,
        const char* messageId) {
    NetConfCtrlInfo* ctrl = new NetConfCtrlInfo();
    ctrl->setMessageType(messageType);
    ctrl->setSession_id(sessionId);
    ctrl->setMessage_id(messageId);
    return ctrl;
}

NetConfMessage_RPC* NetConfApplicationBase::createNetConfRPCForConfiguration(
        Connection_t* connection, Configuration_t* config, std::string message_id) {
    NetConfMessage_RPC* rpc = new NetConfMessage_RPC();
    rpc->setMessage_id(message_id.c_str());
    rpc->addByteLength(
            sizeof(rpc->getMessageType())
                    + sizeof(rpc->getMessage_id()));
    if (config) {
        switch (config->type) {
        case Configuration_t::NetConfMessageType_EditConfig:
            rpc->setName("RPC EditConfig");
            rpc->encapsulate(createEditConfigOperation(config));
            break;

        case Configuration_t::NetConfMessageType_GetConfig:
            rpc->setName("RPC GetConfig");
            rpc->encapsulate(createGetConfigOperation(config));
            break;

        case Configuration_t::NetConfMessageType_CopyConfig:
            rpc->setName("RPC CopyConfig");
            rpc->encapsulate(createCopyConfigOperation(config));
            break;

        case Configuration_t::NetConfMessageType_DeleteConfig:
            rpc->setName("RPC DeleteConfig");
            rpc->encapsulate(createDeleteConfigOperation(config));
            break;

        case Configuration_t::NetConfMessageType_Lock:
            rpc->setName("RPC LockConfig");
            rpc->encapsulate(createLockOperation(config));
            break;

        case Configuration_t::NetConfMessageType_Unlock:
            rpc->setName("RPC UnlockConfig");
            rpc->encapsulate(createUnlockOperation(config));
            break;

        case Configuration_t::NetConfMessageType_Commit:
            rpc->setName("RPC CommitConfig");
            rpc->encapsulate(createCommitOperation(config));
            break;

        default:
            throw cRuntimeError("Can't create RPC for configuration: NetConfMessageType unknown.");
            break;
        }
    }
    rpc->setControlInfo(createControlInfo(rpc->getMessageType(), connection->session_id, rpc->getMessage_id()));
    return rpc;
}

NetConfApplicationBase::Connection_t* NetConfApplicationBase::mapSessionInfoToConnection(
        NetConfClientSessionInfoTCP* sessionInfo) {
    if (sessionInfo) {
        for (size_t i = 0; i < _connections.size(); i++) {
            auto& connection = _connections[i];
            if (connection.state
                    == ConnectionState_t::ConnectionStateEstablished
                    && connection.session_id == sessionInfo->getSessionId()) {
                return &connection;
            }
            //connection not yet established so use ip address
            else if ((connection.session_id == -1)
                    && (inet::L3AddressResolver().resolve(
                            connection.remoteAddress.c_str()).str() ==
                            sessionInfo->getSocket()->getRemoteAddress().str())) {
                return &connection;
            }
        }
    }
    return nullptr;
}

void NetConfApplicationBase::setConnnections(std::vector<NetConfApplicationBase::Connection_t>& connections){
    Enter_Method_Silent();
    _connections.clear();
    for(Connection_t& connection: connections){
        for(Configuration_t* configuration: connection.configurations){
            this->take(configuration->data);
        }
        _connections.push_back(connection);
    }
}

}  // namespace SDN4CoRE
