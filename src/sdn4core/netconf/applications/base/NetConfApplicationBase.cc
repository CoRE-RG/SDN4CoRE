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

#include <string>

#include "sdn4core/netconf/messages/NetConfCtrlInfo_m.h"

namespace SDN4CoRE {

Define_Module(NetConfApplicationBase);

#define SELFMESSAGE_SEND_NETCONF "Send Netconf"

void NetConfApplicationBase::initialize() {
    cXMLElement* xmlServerConnections = par("serverConnections").xmlValue();
    if (xmlServerConnections) {
        if (strcmp(xmlServerConnections->getName(), "server_connections")
                == 0) {
            cXMLElementList applicationsXML =
                    xmlServerConnections->getChildrenByTagName("application");
            for (size_t i = 0; i < applicationsXML.size(); i++) { //the xml contains connections so set them.
                const char* clientAppHost = applicationsXML[i]->getAttribute(
                        "client_host");
                const char* clientAppIndex = applicationsXML[i]->getAttribute(
                        "client_app");
                const char* realHost = getParentModule()->getFullName();
                if (clientAppIndex && clientAppHost
                        && (atoi(clientAppIndex) == getIndex())
                        && (strcmp(realHost, clientAppHost) == 0)) {
                    cXMLElementList connectionsXML =
                            applicationsXML[i]->getChildrenByTagName(
                                    "connection");
                    for (size_t i = 0; i < connectionsXML.size(); i++) { //the xml contains connections so set them.
                        const char* localPort = connectionsXML[i]->getAttribute(
                                "local_port");
                        const char* remoteAddress =
                                connectionsXML[i]->getAttribute(
                                        "remote_address");
                        const char* remotePort =
                                connectionsXML[i]->getAttribute("remote_port");
                        const char* connectAt = connectionsXML[i]->getAttribute(
                                "connect_at");

                        if (localPort && remoteAddress && remotePort
                                && connectAt) {
                            // set the connection and push_back to array.
                            Connections_t connection;
                            connection.localPort = atoi(localPort);
                            connection.remoteAddress = remoteAddress;
                            connection.remotePort = atoi(remotePort);
                            connection.connectAt = std::stod(connectAt);
                            connection.state =
                                    ConnectionState_t::ConnectionStateWaiting;
                            _connections.push_back(connection);
                        }
                    }
                }
            }
        }
    }

    scheduleNextConnection();
}

void NetConfApplicationBase::scheduleNextConnection() {
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
        cMessage* msg = new cMessage();
        msg->setContextPointer(&_connections[index]);
        scheduleAt(next, msg);
        _connections[index].state = ConnectionState_t::ConnectionStateScheduled;
    }
}

void NetConfApplicationBase::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) {
        if(strcmp(msg->getName(), SELFMESSAGE_SEND_NETCONF) == 0){
            Connections_t* connection =
                    static_cast<Connections_t*>(msg->getContextPointer());

            if (connection) {
                send(createHelloFor(connection), gate("applicationOut"));
                connection->state = ConnectionState_t::ConnectionStateRequested;
            }
        } else if(strcmp(msg->getName(), SELFMESSAGE_SEND_NETCONF) == 0){

        }

        scheduleNextConnection();
    } else if (NetConfHello* hello = dynamic_cast<NetConfHello*>(msg)) {
        // todo verify that a connection was established.
        NetConfClientSessionInfoTCP* sessionInfo =
                (NetConfClientSessionInfoTCP*) hello->getContextPointer();
        Connections_t* connection = mapSessionInfoToConnection(sessionInfo);
        if (connection) {
            connection->session_id = sessionInfo->getSessionId();
            connection->state = ConnectionState_t::ConnectionStateEstablished;
            scheduleNextConfigurationFor(connection);
        }
    }

    delete msg;
}

NetConfHello* NetConfApplicationBase::createHelloFor(
        Connections_t* connection) {
    NetConfHello* hello = new NetConfHello("NetConfHello");
    hello->setByteLength(4);

    NetConfClientCtrlInfo_Connection* ctrl =
            new NetConfClientCtrlInfo_Connection();
    ctrl->setConnectAddress(connection->remoteAddress);
    ctrl->setConnectPort(connection->remotePort);
    ctrl->setLocalPort(connection->localPort);

    hello->setControlInfo(ctrl);
    return hello;
}

NetConfMessage_RPC* NetConfApplicationBase::createNetConfRPCForConfiguration(
        Connections_t* connection, int index) {
}

void NetConfApplicationBase::scheduleNextConfigurationFor(
        Connections_t* connection) {
    if (connection
            && (connection->state
                    == ConnectionState_t::ConnectionStateEstablished)) {
        int index = -1;
        SimTime next = SimTime::getMaxTime();
        for (size_t i = 0; i < connection->configurations.size(); i++) {
            auto configuration = connection->configurations[i];
            if (configuration.executeAt < next && configuration.executeAt >= simTime()
                    && (configuration.state
                            == ConfigurationState_t::ConfigurationStateWaiting)) {
                index = i;
                next = configuration.connectAt;
            }
        }

        if (index > -1) {
            cMessage* msg = new cMessage(SELFMESSAGE_SEND_NETCONF);
            NetConfMessage_RPC* rpc = createNetConfRPCForConfiguration(connection, index);
            msg->setContextPointer(rpc);
            scheduleAt(next, msg);
            _connections[index].state = ConnectionState_t::ConnectionStateScheduled;
        }
    }
}

NetConfApplicationBase::Connections_t* NetConfApplicationBase::mapSessionInfoToConnection(
        NetConfClientSessionInfoTCP* sessionInfo) {
    if (sessionInfo) {
        for (size_t i = 0; i < _connections.size(); i++) {
            auto connection = _connections[i];
            if (connection.state
                    == ConnectionState_t::ConnectionStateEstablished
                    && connection.session_id == sessionInfo->getSessionId()) {
                return &connection;
            }
            //connection not yet established so use ip address
            else if ((connection.session_id == -1)
                    && (strcmp(connection.remoteAddress,
                            sessionInfo->getSocket()->getRemoteAddress().str().c_str())
                            == 0)) {
                return &connection;
            }
        }
    }
    return nullptr;
}

}  // namespace SDN4CoRE
