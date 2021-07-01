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

#include <sdn4core/netconf/client/tcp/NetConfClientTCP.h>
#include <sdn4core/netconf/datastructures/tcp/NetConfClientSessionInfoTCP.h>
#include "inet/networklayer/common/L3AddressResolver.h"

using namespace inet;

namespace SDN4CoRE {

Define_Module(NetConfClientTCP);

void NetConfClientTCP::initialize()
{
    NetConfClientBase::initialize();

}

void NetConfClientTCP::handleMessage(cMessage* msg) {

    if(msg->getKind() == TCP_I_ESTABLISHED){
        NetConfClientSessionInfoTCP* sessionInfo = dynamic_cast<NetConfClientSessionInfoTCP*>(findSessionInfoForMsg(msg));
        sessionInfo->getSocket()->processMessage(msg);
    }else{
        NetConfClientBase::handleMessage(msg);
    }

}

void NetConfClientTCP::sendToTransport(cMessage* msg) {// Detach control info and use it for forwarding
    NetConfCtrlInfo* ctrl = dynamic_cast<NetConfCtrlInfo*>(msg->removeControlInfo());

    // get session info
    NetConfClientSessionInfoTCP* sessionInfo = dynamic_cast<NetConfClientSessionInfoTCP*>(findSessionInfoForId(ctrl->getSession_id()));

    // forward to tcp
    sessionInfo->getSocket()->send(msg);

    // delete control info
    delete ctrl;
}

NetConfClientSessionInfo* NetConfClientTCP::openNewSession(NetConfHello* hello) {
    NetConfClientCtrlInfo_Connection* ctrl = dynamic_cast<NetConfClientCtrlInfo_Connection*>(hello->removeControlInfo());
    NetConfClientSessionInfoTCP* sessionInfo = nullptr;

    if(ctrl){
        // create new socket
        TCPSocket *socket = new TCPSocket();
        socket->setOutputGate(gate(TRANSPORT_OUT_GATE_NAME));
        socket->setDataTransferMode(TCP_TRANSFER_OBJECT);
        socket->bind(ctrl->getLocalPort());

        sessionInfo = new NetConfClientSessionInfoTCP();
        sessionInfo->setSocket(socket);
        sessionInfo->setConnId(socket->getConnectionId());

        // insert into open sessions
        _openSessions.push_back(sessionInfo);

        // connect to the other socket.
        socket->connect(L3AddressResolver().resolve(ctrl->getConnectAddress()), ctrl->getConnectPort());

        // send the hello directly
        socket->send(hello);
    }

    delete ctrl;

    return dynamic_cast<NetConfClientSessionInfo*>(sessionInfo);
}

bool NetConfClientTCP::closeSession(int sessionId) {
    NetConfClientSessionInfoTCP* sessionInfo = dynamic_cast<NetConfClientSessionInfoTCP*>(findSessionInfoForId(sessionId));
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

NetConfClientSessionInfo* NetConfClientTCP::findSessionInfoForMsg(cMessage* msg) {
    TCPCommand *ind = dynamic_cast<TCPCommand *>(msg->getControlInfo());
    if (!ind)
        throw cRuntimeError("TCPSocketMap: findSocketFor(): no TCPCommand control info in message (not from TCP?)");

    int connId = ind->getConnId();
    for(auto i=_openSessions.begin(); i != _openSessions.end(); ++i) {
        NetConfClientSessionInfoTCP* sessionInfo = dynamic_cast<NetConfClientSessionInfoTCP*>(*i);
        if(sessionInfo->getConnId() == connId){
            return sessionInfo;
        }
    }
    return NULL;
}

}  // namespace SDN4CoRE
