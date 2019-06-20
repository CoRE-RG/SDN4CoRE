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

#include "NetConfServerTCP.h"

#include "sdn4core/netconf/server/tcp/NetConfSessionInfoTCP.h"
//AUTO-GENERATED MESSAGES
#include "sdn4core/netconf/messages/NetConfCtrlInfo_m.h"

using namespace inet;

namespace SDN4CoRE {

Define_Module(NetConfServerTCP);

void NetConfServerTCP::initialize() {
    NetConfServerBase::initialize();

    // TCP socket; listen on incoming connections
    const char *address = par("address");
    int port = par("port");
    _serverSocket.setOutputGate(gate(TRANSPORT_OUT_GATE_NAME));
    _serverSocket.setDataTransferMode(TCP_TRANSFER_OBJECT);
    _serverSocket.bind(address ? L3Address(address) : L3Address(), port);
    _serverSocket.listen();
}

NetConfSessionInfo* NetConfServerTCP::openNewSession(cMessage* msg) {
    NetConfSessionInfoTCP* sessionInfo = dynamic_cast<NetConfSessionInfoTCP*>(findSessionInfoForMsg(msg));
    if(!sessionInfo){
        // create the new socket from the message
        TCPSocket *socket = new TCPSocket(msg);
        socket->setOutputGate(gate("TRANSPORT_OUT_GATE_NAME"));

        // create SessionInfo
        sessionInfo = new NetConfSessionInfoTCP();
        sessionInfo->setSessionId(_nextSessionId++);
        sessionInfo->setSocket(socket);
        sessionInfo->setConnId(socket->getConnectionId());

        // insert into open sessions
        _openSessions.push_back(*sessionInfo);
    }
    return sessionInfo;
}

bool NetConfServerTCP::closeSession(int session_id) {
    NetConfSessionInfoTCP* sessionInfo = dynamic_cast<NetConfSessionInfoTCP*>(findSessionInfoForId(session_id));
    if(!sessionInfo){
        // close socket
        sessionInfo->getSocket()->close();

        // insert into open sessions
        for(auto i=_openSessions.begin(); i != _openSessions.end(); ++i) {
            if((*i).getSessionId() == sessionInfo->getSessionId()){
                _openSessions.erase(i);
            }
        }
        return true;
    }
    return false;
}

void NetConfServerTCP::sendToTransport(cMessage* msg) {
    // Detach control info and use it for forwarding
    NetConfCtrlInfo* ctrl = dynamic_cast<NetConfCtrlInfo*>(msg->removeControlInfo());

    // get session info
    NetConfSessionInfoTCP* sessionInfo = dynamic_cast<NetConfSessionInfoTCP*>(findSessionInfoForId(ctrl->getSession_id()));

    // forward to tcp
    sessionInfo->getSocket()->send(msg);

    // delete control info
    delete ctrl;
}

NetConfSessionInfo* NetConfServerTCP::findSessionInfoForMsg(cMessage* msg) {
    TCPCommand *ind = dynamic_cast<TCPCommand *>(msg->getControlInfo());
    if (!ind)
        throw cRuntimeError("TCPSocketMap: findSocketFor(): no TCPCommand control info in message (not from TCP?)");

    int connId = ind->getConnId();
    for(auto i=_openSessions.begin(); i != _openSessions.end(); ++i) {
        NetConfSessionInfoTCP& sessionInfo = static_cast<NetConfSessionInfoTCP&>(*i);
        if(sessionInfo.getConnId() == connId){
            return &sessionInfo;
        }
    }
    return NULL;
}

}  // namespace SDN4CoRE
