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
        throw cRuntimeError(msg.c_str());
    }
    initializeDataStores();
    if (_configStores.empty()) {
        throw cRuntimeError(
                "No initial NetConf config data store created on startup");
    }
    if (!_stateStore) {
        throw cRuntimeError(
                "No initial NetConf state data store created on startup");
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

bool NetConfDataStoreManagerBase::createConfigStore(string target) {
    if (_configStores.count(target)) {
        // store already exists.
        return false;
    }
    return createOrReplaceConfigStore(target, _activeConfigName);
}

bool NetConfDataStoreManagerBase::createOrReplaceConfigStore(string target,
        string source) {
    // check if the source it valid
    if (_configStores.count(source)) {
        // source store does not exists.
        return false;
    }
    // delete target store first
    if (_configStores.count(target)) {
        deleteConfigStore(target);
    }

    // now we can create the new target by copying
    NetConfConfigDataStore* targetStore = _configStores[source]->copyConfig();
    if (!targetStore) {
        // the copy did not succeed for whatever reason...
        return false;
    }

    // everything went fine so copy and return.
    _configStores[target] = targetStore;
    return true;
}

bool NetConfDataStoreManagerBase::deleteConfigStore(const string& target) {
    // delete target store first
    if (_configStores.count(target)) {
        // target exists so delete it.
        NetConfConfigDataStore* temp = _configStores[target];
        _configStores.erase(target);
        delete temp;
        return true;
    }
    return false;
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::createRPCReplyElement_Data(
        NetConfConfig* config) {
    NetConf_RPCReplyElement_Data* dataReply = nullptr;
    if (config) {
        dataReply = new NetConf_RPCReplyElement_Data();
        dataReply->setConfig(*config);
        dataReply->setByteLength(config->getByteSize());
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
    errorReply->setByteLength(std::strlen(error_tag) + sizeof(error_type) + sizeof(error_severity) + std::strlen(error_app_tag));
    return dynamic_cast<NetConf_RPCReplyElement*>(errorReply);
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::createRPCReplyElement_Ok() {
    NetConf_RPCReplyElement_Ok* okReply = new NetConf_RPCReplyElement_Ok();
    okReply->setByteLength(4);
    return dynamic_cast<NetConf_RPCReplyElement*>(okReply);
}

void NetConfDataStoreManagerBase::handleMessage(cMessage *msg) {

    if (NetConfOperation* operation = dynamic_cast<NetConfOperation*>(msg)) {

        // the reply element to transmit after handling operation.
        NetConf_RPCReplyElement* reply = nullptr;

        // check if it is of type get config operation
        if (dynamic_cast<NetConfOperation_GetConfig*>(operation)) {
            reply = handleGetConfig(operation);
        }
        // check if it is of type edit config operation
        else if (dynamic_cast<NetConfOperation_EditConfig*>(operation)) {
            reply = handleEditConfig(operation);
        }
        // check if it is of type copy config operation
        else if (dynamic_cast<NetConfOperation_CopyConfig*>(operation)) {
            reply = handleCopyConfig(operation);
        }
        // check if it is of type delete config operation
        else if (dynamic_cast<NetConfOperation_DeleteConfig*>(operation)) {
            reply = handleDeleteConfig(operation);
        }
        // check if it is of type get operation
        else if (dynamic_cast<NetConfOperation_Get*>(operation)) {
            reply = handleGet(operation);
        }
        // this operation is not known.
        else {
            // create error
            reply = createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_RPC,
                    "This operation is not supported.",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }

        if (reply) {
            // attach control info
            reply->setControlInfo(operation->removeControlInfo());
            // send the reply
            sendDirect(reply, _netConfServer->gate(RESPONSE_OUT_GATE_NAME));
        } else {
            throw cRuntimeError(
                    "Received an operation that did not result in a reply, this should never happen!");
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
                    _configStores[getConfig->getSource()]->getConfig(
                            getConfig->getFilter());
            if (config) {
                // create response
                reply = createRPCReplyElement_Data(config);
            } else {
                // create error
                reply = createRPCReplyElement_Error(
                        NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                        "Failed to retrieve the data requested.",
                        NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
            }
        } else {
            // create error
            reply = createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                    "The Config store does not exist.",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }
    }

    return reply;
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::handleEditConfig(
        NetConfOperation* operation) {
    NetConf_RPCReplyElement* reply = nullptr;

    // check if it is of type edit config operation
    if (NetConfOperation_EditConfig* editConfig =
            dynamic_cast<NetConfOperation_EditConfig*>(operation)) {
        bool success = true;
        if (!_configStores.count(editConfig->getTarget())) {
            // if config store doesnt exist, create it.
            success = createConfigStore(editConfig->getTarget());
        }
        // pass on the edit config
        if (success) {
            success = _configStores[editConfig->getTarget()]->editConfig(
                    editConfig->getDefaultOperation(),
                    editConfig->getErrorOption(), editConfig->getConfig());
        }

        if (success) {
            // create response
            reply = createRPCReplyElement_Ok();
        } else {
            // create error
            reply = createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                    "Failed to apply config.",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }
    }

    return reply;
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::handleCopyConfig(
        NetConfOperation* operation) {
    NetConf_RPCReplyElement* reply = nullptr;

    // check if it is of type copy config operation
    if (NetConfOperation_CopyConfig* copyConfig =
            dynamic_cast<NetConfOperation_CopyConfig*>(operation)) {
        // if config store doesnt exist create it, else replace it
        bool success = createOrReplaceConfigStore(copyConfig->getTarget(),
                copyConfig->getSource());
        if (success) {
            // create response
            reply = createRPCReplyElement_Ok();
        } else {
            // create error
            reply = createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                    "Failed to copy config.",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }
    }

    return reply;
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::handleDeleteConfig(
        NetConfOperation* operation) {
    NetConf_RPCReplyElement* reply = nullptr;

    // check if it is of type delete config operation
    if (NetConfOperation_DeleteConfig* deleteConfig =
            dynamic_cast<NetConfOperation_DeleteConfig*>(operation)) {
        if (strcmp(deleteConfig->getTarget(), _activeConfigName.c_str())) {
            // delete the store
            bool success = deleteConfigStore(deleteConfig->getTarget());
            if (success) {
                // create response
                reply = createRPCReplyElement_Ok();
            } else {
                // create error
                reply = createRPCReplyElement_Error(
                        NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                        "Failed to delete config.",
                        NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
            }
        } else {
            // create error
            reply = createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                    "The running config must not be deleted.",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }
    }

    return reply;
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::handleGet(
        NetConfOperation* operation) {
    NetConf_RPCReplyElement* reply = nullptr;

    // check if it is of type get operation
    if (NetConfOperation_Get* get =
            dynamic_cast<NetConfOperation_Get*>(operation)) {
        NetConfConfig* config = _stateStore->get(get->getFilter());
        if (config) {
            // create response
            reply = createRPCReplyElement_Data(config);
        } else {
            // create error
            reply = createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                    "Failed to retrieve the data requested.",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }
    }

    return reply;
}

}  // namespace SDN4CoRE
