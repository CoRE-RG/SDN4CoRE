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

//SDN4CoRE
#include <sdn4core/netconf/datastores/manager/base/NetConfDataStoreManagerBase.h>
#include <sdn4core/netconf/server/base/NetConfServerBase.h>

#include "sdn4core/netconf/messages/NetConfOperation_m.h"
#include "sdn4core/netconf/messages/NetConfCapability_m.h"
//INET
#include "inet/common/ModuleAccess.h"
//STD
#include <string>


using namespace std;

namespace SDN4CoRE {

const char NetConfServerBase::REQUEST_FWD_GATE_NAME[] = "requestIn";
const char NetConfServerBase::RESPONSE_IN_GATE_NAME[] = "responseIn";

const char NetConfServerBase::TRANSPORT_IN_GATE_NAME[] = "transportIn";
const char NetConfServerBase::TRANSPORT_OUT_GATE_NAME[] = "transportOut";

int NetConfServerBase::_nextSessionId = 0;

void NetConfServerBase::initialize() {
    ProcessingTimeSimulation::initialize();

    //find netconf data stores
    _configDataStoreManager = inet::getModuleFromPar<NetConfDataStoreManagerBase>(
            par("pathToConfigManager"), this, true);
    if (!_configDataStoreManager) {
        string msg = "No state data store found in ";
        msg += par("pathToConfigManager").stdstringValue();
        cRuntimeError(msg.c_str());
    }
}

NetConfMessage_RPCReply* NetConfServerBase::createRPCReply(
        NetConf_RPCReplyElement* element) {
    // if it is a reply detach NetConfCtrlInfo
    NetConfCtrlInfo* ctrl =
            dynamic_cast<NetConfCtrlInfo*>(element->removeControlInfo());
    // create NetConf reply message
    NetConfMessage_RPCReply* reply = new NetConfMessage_RPCReply("RPC Reply");
    reply->setMessage_id(ctrl->getMessage_id());
    reply->addByteLength(sizeof(ctrl->getMessage_id()));
    reply->encapsulate(element);
    // reattach control info and forward it.
    reply->setControlInfo(ctrl);
    return reply;
}

void NetConfServerBase::handleMessage(cMessage* msg) {

    if (msg->arrivedOn(RESPONSE_IN_GATE_NAME)) {
        // this should be a message from a data store --> check if it is NetConf_RPCReplyElement
        NetConf_RPCReplyElement* element = dynamic_cast<NetConf_RPCReplyElement*>(msg);
        if(element){
            // if it is a reply detach NetConfCtrlInfo
            NetConfMessage_RPCReply* reply = createRPCReply(element);
            sendToTransport(reply);
        } else {
            delete msg;
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
            NetConfServerSessionInfo* sessionInfo = findSessionInfoForMsg(msg);
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
                    NetConf_RPCReplyElement* element = createRPCReplyElement_Error(
                                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                                    "Incoming message not of type NETCONFMESSAGETYPE_RPC",
                                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR,"");

                    element->setControlInfo(netconf->removeControlInfo());
                    NetConfMessage_RPCReply* reply = createRPCReply(element);
                    sendToTransport(reply);
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
        NetConfServerSessionInfo* sessionInfo = openNewSession(msg);
        // create hello
        NetConfHello* reply = new NetConfHello("NetConfHello");
        reply->setSession_id(sessionInfo->getSessionId());
        //create and attach control info
        NetConfCtrlInfo* info = new NetConfCtrlInfo();
        info->setSession_id(sessionInfo->getSessionId());
        reply->setControlInfo(info);
        // send reply
        sendToTransport(reply);
    }
}

void NetConfServerBase::handleCloseSession(cMessage* msg) {
    if(NetConfOperation* operation = dynamic_cast<NetConfOperation*>(msg)){
        NetConfCtrlInfo* ctrl = dynamic_cast<NetConfCtrlInfo*>(operation->removeControlInfo());
        NetConf_RPCReplyElement* element;
        if(closeSession(ctrl->getSession_id())){
            //session was closed
            element = createRPCReplyElement_Ok();
        } else {
            //session could not be closed
            element = createRPCReplyElement_Error(
                            NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                            "Session could not be closed.",
                            NETCONF_REPLY_ERROR_SEVIRITY_ERROR,"");
        }

        // if it is a reply detach NetConfCtrlInfo
        element->setControlInfo(ctrl);
        NetConfMessage_RPCReply* reply = createRPCReply(element);
        sendToTransport(reply);
    }
}


NetConf_RPCReplyElement* NetConfServerBase::createRPCReplyElement_Error(
        int error_type, const char * error_tag, int error_severity,
        const char * error_app_tag = "") {
    // create error
    NetConf_RPCReplyElement_Error* errorReply =
            new NetConf_RPCReplyElement_Error();
    errorReply->setError_type(error_type);
    errorReply->setError_tag(error_tag);
    errorReply->setError_severity(error_severity);
    errorReply->setError_app_tag(error_app_tag);
    errorReply->addByteLength(std::strlen(error_tag) + std::strlen(error_app_tag));
    return dynamic_cast<NetConf_RPCReplyElement*>(errorReply);
}

NetConf_RPCReplyElement* NetConfServerBase::createRPCReplyElement_Ok() {
    NetConf_RPCReplyElement_Ok* okReply = new NetConf_RPCReplyElement_Ok();
    return dynamic_cast<NetConf_RPCReplyElement*>(okReply);
}

void NetConfServerBase::handleRPC(NetConfMessage* msg) {
    if(NetConfMessage_RPC* rpc = dynamic_cast<NetConfMessage_RPC*>(msg)){
        // decapsulate the operation
        if(NetConfOperation* operation = dynamic_cast<NetConfOperation*>(rpc->decapsulate())){
            //get the control info
            operation->setControlInfo(msg->removeControlInfo());
            if(dynamic_cast<NetConfOperation_CloseSession*>(operation)){
                handleCloseSession(operation);
            }

            //forward it to the config store manager
            sendDirect(operation, _configDataStoreManager->gate(REQUEST_FWD_GATE_NAME));

        }
    }
}

NetConfServerSessionInfo* NetConfServerBase::findSessionInfoForId(
        int sessionId) {

    for(auto i=_openSessions.begin(); i != _openSessions.end(); ++i) {
        if((*i)->getSessionId() == sessionId){
            return (*i);
        }
    }
    return NULL;
}

NetConfCtrlInfo* NetConfServerBase::createCtrlInfoFor(
        NetConfServerSessionInfo* sessionInfo, NetConfMessage* msg) {
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
