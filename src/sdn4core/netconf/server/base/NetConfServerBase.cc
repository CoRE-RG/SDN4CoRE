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

#include <sdn4core/netconf/server/base/NetConfServerBase.h>
#include "sdn4core/netconf/server/base/NetConfConfigDataStoreBase.h"
#include "sdn4core/netconf/server/base/NetConfStateDataStoreBase.h"
//AUTO-GENERATED MESSAGES
#include "sdn4core/netconf/messages/NetConfOperation_m.h"
#include "sdn4core/netconf/messages/NetConfCapability_m.h"
//INET
#include "inet/common/ModuleAccess.h"

using namespace std;

namespace SDN4CoRE {

const char NetConfServerBase::REQUEST_FWD_GATE_NAME[] = "requestIn";
const char NetConfServerBase::RESPONSE_IN_GATE_NAME[] = "responseIn";

const char NetConfServerBase::TRANSPORT_IN_GATE_NAME[] = "transportIn";
const char NetConfServerBase::TRANSPORT_OUT_GATE_NAME[] = "transportOut";

void NetConfServerBase::initialize() {
    ProcessingTimeSimulation::initialize();

    //find netconf data stores
    _stateDataStore = inet::getModuleFromPar<NetConfStateDataStoreBase>(
            par("pathToStateDataStore"), this, true);
    if (!_stateDataStore) {
        string msg = "No state data store found in ";
        msg += par("pathToStateDataStore").stdstringValue();
        cRuntimeError(msg.c_str());
    }
    string path = par("pathToConfigDataStores").stdstringValue();
    int numStores = par("numConfigStores");
    for (int i = 0; i < numStores; i++) {
        path += "[" + to_string(i) + "]";
        if (NetConfConfigDataStoreBase* config =
                dynamic_cast<NetConfConfigDataStoreBase*>(this->getModuleByPath(
                        path.c_str()))) {
            _configDataStores[config->getName()] = config;
        } else {
            string msg = "No config data store found in ";
            msg += path;
            cRuntimeError(msg.c_str());
        }
    }
}

void NetConfServerBase::handleMessage(cMessage* msg) {

    if (msg->arrivedOn(RESPONSE_IN_GATE_NAME)) {
        // this should be a message from a data store --> check if it is NetConf_RPCReplyElement
        NetConf_RPCReplyElement* element = dynamic_cast<NetConf_RPCReplyElement*>(msg);
        if(element){
            // if it is a reply detach NetConfCtrlInfo
            NetConfCtrlInfo* ctrl = dynamic_cast<NetConfCtrlInfo*>(element->removeControlInfo());

            // create NetConf reply message
            NetConfMessage_RPCReply* reply = new NetConfMessage_RPCReply();
            reply->setMessage_id(ctrl->getMessage_id());
            reply->encapsulate(element);

            // re-attach transport control info
//            reply->setControlInfo(&ctrl->getTransportInfo());
            // forward it to the correct client
            sendToTransport(reply);
        }

    } else {
        //introduce processing delay
        ProcessingTimeSimulation::handleMessage(msg);
    }
}

void NetConfServerBase::processScheduledMessage(cMessage* msg) {
    if (msg->arrivedOn(TRANSPORT_IN_GATE_NAME)) {

        if (dynamic_cast<NetConfHello*>(msg)) {
            // received hello
            handleHello(msg);

        } else if (NetConfMessage* netconf = dynamic_cast<NetConfMessage*>(msg)){
            NetConfSessionInfo* sessionInfo = findSessionInfoForMsg(msg);
            if(sessionInfo) {
                // create control info
                netconf->removeControlInfo();
                netconf->setControlInfo(createCtrlInfoFor(sessionInfo,netconf));
                //check for mesage type
                switch(netconf->getMessageType()){
                case NetConfMessageType::NETCONFMESSAGETYPE_RPC:
                    // received RPC
                    handleRPC(netconf);
                    break;

                default:
                    break;

                }

            } else {
                throw cRuntimeError("Received NetConfMessage but there is no session for it.");
            }

        }
    }

    delete msg;
}

void NetConfServerBase::handleHello(cMessage* msg) {
    if (dynamic_cast<NetConfHello*>(msg)) {
        // received hello so open a new session
        NetConfSessionInfo* sessionInfo = openNewSession(msg);
        // create hello
        NetConfHello* reply = new NetConfHello();
        reply->setSession_id(sessionInfo->getSessionId());
        //create and attach control info
        NetConfCtrlInfo* info = new NetConfCtrlInfo();
        info->setSession_id(sessionInfo->getSessionId());
        reply->setControlInfo(info);
        // send reply
        sendToTransport(reply);
    }
}

void NetConfServerBase::handleRPC(NetConfMessage* msg) {
    // decapsulate the operation
    //
    //                // find the correct store
    //
    //                // if it is a request attach NetConfCtrlInfo
    //
    //
    //                // forward it to the correct store
}

NetConfSessionInfo* NetConfServerBase::findSessionInfoForId(
        int sessionId) {

    for(auto i=_openSessions.begin(); i != _openSessions.end(); ++i) {
        if((*i).getSessionId() == sessionId){
            return &(*i);
        }
    }
    return NULL;
}

NetConfCtrlInfo* NetConfServerBase::createCtrlInfoFor(
        NetConfSessionInfo* sessionInfo, NetConfMessage* msg) {
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
