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

#include <sdn4core/netconf/datastores/manager/base/NetConfDataStoreManagerBase.h>
#include <sdn4core/netconf/server/base/NetConfServerBase.h>
//INET
#include "inet/common/ModuleAccess.h"

using namespace std;

namespace SDN4CoRE {

const char NetConfDataStoreManagerBase::REQUEST_IN_GATE_NAME[] = "requestIn";
const char NetConfDataStoreManagerBase::RESPONSE_OUT_GATE_NAME[] = "responseIn";

void NetConfDataStoreManagerBase::initialize() {
    handleParameterChange(nullptr);

    //find netconf data stores
    _netConfServer = inet::getModuleFromPar<NetConfServerBase>(
            par("pathToNetConfServer"), this, true);
    if (!_netConfServer) {
        string msg = "No NetConf server found in ";
        msg += par("pathToNetConfServer").stdstringValue();
        cRuntimeError(msg.c_str());
    }
    // TODO implement XML configuration.
}

void NetConfDataStoreManagerBase::handleParameterChange(const char* parname) {
    if (!parname || !strcmp(parname, "displayStatus")) {
        _displayStatus = par("displayStatus");
    }
    if (!parname || !strcmp(parname, "numMaxDataStores")) {
        _numMaxDataStores = par("numMaxDataStores");
    }
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::createRPCReplyElement_Data(
        NetConfConfig* config) {
    NetConf_RPCReplyElement_Data* dataReply = nullptr;
    if (config) {
        dataReply = new NetConf_RPCReplyElement_Data();
        dataReply->setConfig(*config);
    }

    return dynamic_cast<NetConf_RPCReplyElement*>(dataReply);
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::createRPCReplyElement_Error(
        int error_type, const char * error_tag, int error_severity,
        const char * error_app_tag = "") {
    // create error
    NetConf_RPCReplyElement_Error* errorReply =
            new NetConf_RPCReplyElement_Error();
    errorReply->setError_type(error_type);
    errorReply->setError_tag(error_tag);
    errorReply->setError_severity(error_severity);
    errorReply->setError_app_tag(error_app_tag);
    return dynamic_cast<NetConf_RPCReplyElement*>(errorReply);
}

void NetConfDataStoreManagerBase::handleMessage(cMessage *msg) {

    if (NetConfOperation* operation = dynamic_cast<NetConfOperation*>(msg)) {

        // the reply element to transmit after handling operation.
        NetConf_RPCReplyElement* reply = nullptr;

        // check if it is of type get config operation
        if (dynamic_cast<NetConfOperation_GetConfig*>(operation)) {
            reply = handleGetConfig(operation);
        }


        if (reply) {
            // attach control info
            reply->setControlInfo(
                    operation->removeControlInfo());
            // send the reply
            sendDirect(reply, _netConfServer->gate(RESPONSE_OUT_GATE_NAME));
        }


    } else {
        throw cRuntimeError("Received message the is not a netconf operation.");
    }
    delete msg;
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::handleGetConfig(
        NetConfOperation* operation) {
    NetConf_RPCReplyElement* reply = nullptr;

    // check if it is of type get config operation
    if (NetConfOperation_GetConfig* getConfig =
            dynamic_cast<NetConfOperation_GetConfig*>(operation)) {
        if (_configStores.count(getConfig->getSource())) {
            NetConfConfig* config =
                    _configStores[getConfig->getSource()].getConfig(
                            getConfig->getFilter());
            if (config) {
                // create response
                reply = createRPCReplyElement_Data(config);
            } else {
                // create error
                reply = createRPCReplyElement_Error(
                        NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                        "invalid data request",
                        NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
            }
        } else {
            // create error
            reply = createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                    "config store does not exist",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }
    }

    return reply;
}

}  // namespace SDN4CoRE
