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
#include "sdn4core/netconf/messages/NetConfMessage_m.h"
#include "sdn4core/netconf/messages/NetConfOperation_m.h"
//INET
#include "inet/common/ModuleAccess.h"

using namespace std;

namespace SDN4CoRE {

Define_Module(NetConfServerBase);

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

            // forward it to the correct client
            forwardToTransport(reply, ctrl->getTransportInfo());
        }

    } else {
        //introduce processing delay
        ProcessingTimeSimulation::handleMessage(msg);
    }
}

void NetConfServerBase::processScheduledMessage(cMessage* msg) {
    if (msg->arrivedOn(TRANSPORT_IN_GATE_NAME)) {
        // this should be a message from a client --> check if it is NetConf
        NetConfMessage* netconf = dynamic_cast<NetConfMessage*>(msg);
        if (netconf) {
            NetConfMessage_RPC* rpc = dynamic_cast<NetConfMessage_RPC*>(netconf);
            if ((netconf->getMessageType()
                    == NetConfMessageType::NETCONFMESSAGETYPE_RPC) && rpc) {
                // decapsulate the operation

                // find the correct store

                // if it is a request attach NetConfCtrlInfo
                NetConfCtrlInfo* ctrl = new NetConfCtrlInfo();
                ctrl->setMessageType(rpc->getMessageType());
                ctrl->setMessage_id(rpc->getMessage_id());

                // forward it to the correct store

            }
        }
    }

    delete msg;
}

}  // namespace SDN4CoRE
