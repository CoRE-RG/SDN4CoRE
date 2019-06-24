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

#include "NetConfClientBase.h"

namespace SDN4CoRE {

const char NetConfClientBase::APPLICATION_OUT_GATE_NAME[] = "applicationOut";
const char NetConfClientBase::APPLICATION_IN_GATE_NAME[] = "applicationIn";

const char NetConfClientBase::TRANSPORT_IN_GATE_NAME[] = "transportIn";
const char NetConfClientBase::TRANSPORT_OUT_GATE_NAME[] = "transportOut";

void NetConfClientBase::initialize()
{
    // Nothing to initialize?
}

void NetConfClientBase::handleMessage(cMessage *msg)
{
    if(msg->arrivedOn(APPLICATION_IN_GATE_NAME)){
        if (NetConfHello* hello = dynamic_cast<NetConfHello*>(msg)) {
            // received hello
            sendHello(hello);
        } else if (dynamic_cast<NetConfMessage*>(msg)){
            sendToTransport(msg);
        } else {
            throw cRuntimeError("Received message of unknown type from application.");
        }


    } else if (msg->arrivedOn(TRANSPORT_IN_GATE_NAME)){
        if (NetConfHello* hello = dynamic_cast<NetConfHello*>(msg)) {
            // received hello
            handleHello(hello);
        } else if (NetConfMessage* netconf = dynamic_cast<NetConfMessage*>(msg)){
            NetConfClientSessionInfo* sessionInfo = findSessionInfoForMsg(msg);
            if(sessionInfo) {
                // create control info
                netconf->removeControlInfo();
                netconf->setControlInfo(createCtrlInfoFor(sessionInfo,netconf));
                //check for mesage type
                switch(netconf->getMessageType()){
                case NetConfMessageType::NETCONFMESSAGETYPE_RPCREPLY:
                    // received RPC
                    send(msg,this->gate(APPLICATION_OUT_GATE_NAME, sessionInfo->getApplicationIndex()));
                    break;

                default:
                    throw cRuntimeError("Received NetConfMessage but its not Hello or RPCReply");
                    break;

                }

            } else {
                throw cRuntimeError("Received NetConfMessage but there is no session for it.");
            }

        }

    }
}

void NetConfClientBase::sendHello(NetConfHello* hello) {
    int appIndex = hello->getArrivalGate()->getIndex();
    NetConfClientSessionInfo* sessionInfo = openNewSession(hello);
    sessionInfo->setApplicationIndex(appIndex);
}

void NetConfClientBase::handleHello(NetConfHello* hello) {
    // received hello so open a new session
    NetConfClientSessionInfo* sessionInfo = findSessionInfoForMsg(hello);
    if(sessionInfo){
        sessionInfo->setSessionId(hello->getSession_id());
    }
    hello->setContextPointer(sessionInfo);
    send(hello,this->gate(APPLICATION_OUT_GATE_NAME, sessionInfo->getApplicationIndex()));
}

NetConfClientSessionInfo* NetConfClientBase::findSessionInfoForId(
        int sessionId) {

    for(auto i=_openSessions.begin(); i != _openSessions.end(); ++i) {
        if((*i)->getSessionId() == sessionId){
            return (*i);
        }
    }
    return NULL;
}

NetConfCtrlInfo* NetConfClientBase::createCtrlInfoFor(
        NetConfClientSessionInfo* sessionInfo, NetConfMessage* msg) {
    // create control info
    NetConfCtrlInfo* ctrl = new NetConfCtrlInfo();
    ctrl->setMessageType(msg->getMessageType());
    ctrl->setSession_id(sessionInfo->getSessionId());
    if(NetConfMessage_RPC* rpc = dynamic_cast<NetConfMessage_RPC*>(msg)){
        ctrl->setMessage_id(rpc->getMessage_id());
    } else if (NetConfMessage_RPCReply* rpc = dynamic_cast<NetConfMessage_RPCReply*>(msg)){
        ctrl->setMessage_id(rpc->getMessage_id());
    }
    return ctrl;
}

}  // namespace SDN4CoRE
