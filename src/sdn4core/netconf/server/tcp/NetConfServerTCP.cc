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

#include <sdn4core/netconf/datastructures/tcp/NetConfServerSessionInfoTCP.h>
#include "NetConfServerTCP.h"

#include "sdn4core/netconf/messages/NetConfCtrlInfo_m.h"

using namespace inet;

namespace SDN4CoRE {

Define_Module(NetConfServerTCP);

void NetConfServerTCP::initialize() {
    NetConfServerBase::initialize();

    // TCP socket; listen on incoming connections
    int port = par("localPort");
    _serverSocket.setOutputGate(gate(TRANSPORT_OUT_GATE_NAME));
    _serverSocket.setDataTransferMode(TCP_TRANSFER_OBJECT);
    _serverSocket.bind(port);
    _serverSocket.listen();
}

NetConfServerSessionInfo* NetConfServerTCP::openNewSession(cMessage* msg) {
    NetConfServerSessionInfoTCP* sessionInfo = dynamic_cast<NetConfServerSessionInfoTCP*>(findSessionInfoForMsg(msg));
    if(!sessionInfo){
        // create the new socket from the message
        TCPSocket *socket = new TCPSocket(msg);
        socket->setOutputGate(gate(TRANSPORT_OUT_GATE_NAME ));

        // create SessionInfo
        sessionInfo = new NetConfServerSessionInfoTCP();
        sessionInfo->setSessionId(_nextSessionId++);
        sessionInfo->setSocket(socket);
        sessionInfo->setConnId(socket->getConnectionId());

        // insert into open sessions
        _openSessions.push_back(sessionInfo);
    }
    return sessionInfo;
}

bool NetConfServerTCP::closeSession(int session_id) {
    NetConfServerSessionInfoTCP* sessionInfo = dynamic_cast<NetConfServerSessionInfoTCP*>(findSessionInfoForId(session_id));
    if(!sessionInfo){
        // close socket
        sessionInfo->getSocket()->close();

        // delete from open sessions
        for(auto i=_openSessions.begin(); i != _openSessions.end(); ++i) {
            if((*i)->getSessionId() == sessionInfo->getSessionId()){
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
    NetConfServerSessionInfoTCP* sessionInfo = dynamic_cast<NetConfServerSessionInfoTCP*>(findSessionInfoForId(ctrl->getSession_id()));

    // forward to tcp
    sessionInfo->getSocket()->send(msg);

    // delete control info
    delete ctrl;
}

NetConfServerSessionInfo* NetConfServerTCP::findSessionInfoForMsg(cMessage* msg) {
    TCPCommand *ind = dynamic_cast<TCPCommand *>(msg->getControlInfo());
    if (!ind)
        throw cRuntimeError("TCPSocketMap: findSocketFor(): no TCPCommand control info in message (not from TCP?)");

    int connId = ind->getConnId();
    for(auto i=_openSessions.begin(); i != _openSessions.end(); ++i) {
        NetConfServerSessionInfoTCP* sessionInfo = dynamic_cast<NetConfServerSessionInfoTCP*>(*i);
        if(sessionInfo->getConnId() == connId){
            return sessionInfo;
        }
    }
    return NULL;
}

}  // namespace SDN4CoRE
