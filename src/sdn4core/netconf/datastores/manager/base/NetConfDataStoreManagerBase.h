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

#ifndef __SDN4CORE_NETCONFDATASTOREMANAGERBASE_H_
#define __SDN4CORE_NETCONFDATASTOREMANAGERBASE_H_

#include <omnetpp.h>
#include <sdn4core/netconf/datastores/config/base/NetConfConfigDataStoreBase.h>
#include <string>
#include <unordered_map>

#include "sdn4core/netconf/datastores/state/base/NetConfStateDataStore.h"
//AUTO-GENERATED MESSAGES
#include "sdn4core/netconf/messages/NetConfMessage_m.h"
#include "sdn4core/netconf/messages/NetConfOperation_m.h"

using namespace omnetpp;

namespace SDN4CoRE {
/**
 * forward declaration of NetConfDataStoreManagerBase
 */
class NetConfServerBase;

/**
 * Base implementation of a netconf config store manager.
 * NetConfDataStoreManger implementations handle NetConf configuration and
 * state operations for a specific device.
 *
 * It uses a @see ~NetConfStateDataStore to handle state operations and a map
 * @see~ NetConfConfigDataStore to handle config operations.
 * Device specific implementations should also use device specific types for
 * there data stores.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfDataStoreManagerBase : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleParameterChange(const char* parname);
    virtual void handleMessage(cMessage *msg);

    /**
     * Initializes the initial config and state data stores on startup.
     * This function must also set the _activeConfigName to the running config name.
     */
    virtual void initializeDataStores() = 0;

    /**
     * Creates an rpc reply element containing the data.
     * @param config    the config data to encapsulate
     * @return  the NetConf_RPCReplyElement_Data
     */
    virtual NetConf_RPCReplyElement* createRPCReplyElement_Data(
            NetConfConfig* config);

    /**
     * Creates an rpc reply element containing the error message.
     * @param error_type        Defines the conceptual layer that the error occurred.
     *                          One of @see ~NetConf_RPCReplyElement_Error_Type
     * @param error_tag         Contains a string identifying the error condition.
     * @param error_severity    Contains an enum identifying the error severity, as
     *                          determined by the device. One of @see ~NetConf_RPCReplyElement_Error_Severity
     * @param error_app_tag     Contains a string identifying the data-model-specific
     *                          or implementation-specific error condition, if one exists.
     * @return                  the NetConf_RPCReplyElement_Error
     */
    virtual NetConf_RPCReplyElement* createRPCReplyElement_Error(
            int error_type, const char * error_tag, int error_severity,
            const char * error_app_tag);

    /**
     * Creates an rpc reply element containing OK.
     * @return the NetConf_RPCReplyElement_Ok
     */
    virtual NetConf_RPCReplyElement* createRPCReplyElement_Ok();

    /**
     * Handles a NetConfOperation_GetConfig message, forwards it to the correct
     * config store and creates a reply.
     * @param operation     the NetConfOperation_GetConfig message
     * @return              a NetConf_RPCReplyElement
     */
    virtual NetConf_RPCReplyElement* handleGetConfig(NetConfOperation* operation);

    /**
     * Handles a NetConfOperation_EditConfig message, forwards it to the correct
     * config store and creates a reply.
     * @param operation     the NetConfOperation_EditConfig message
     * @return              a NetConf_RPCReplyElement
     */
    virtual NetConf_RPCReplyElement* handleEditConfig(NetConfOperation* operation);

    /**
     * Handles a NetConfOperation_CopyConfig message, forwards it to the correct
     * config store and creates a reply.
     * @param operation     the NetConfOperation_CopyConfig message
     * @return              a NetConf_RPCReplyElement
     */
    virtual NetConf_RPCReplyElement* handleCopyConfig(NetConfOperation* operation);

    /**
     * Handles a NetConfOperation_DeleteConfig message, forwards it to the correct
     * config store and creates a reply.
     * @param operation     the NetConfOperation_DeleteConfig message
     * @return              a NetConf_RPCReplyElement
     */
    virtual NetConf_RPCReplyElement* handleDeleteConfig(NetConfOperation* operation);

    /**
     * Handles a NetConfOperation_Get message, forwards it to the data
     * store and creates a reply.
     * @param operation     the NetConfOperation_Get message
     * @return              a NetConf_RPCReplyElement
     */
    virtual NetConf_RPCReplyElement* handleGet(NetConfOperation* operation);

    /**
     * Adds a new config data store to the _configStores by copying the active
     * config store and adding it to the map using the name as a key.
     * If the store already exists it is NOT replaced.
     * @param target    the name of the config store to create
     * @return          true if a new store was created
     */
    virtual bool createConfigStore (std::string target);

    /**
     * Creates/replaces the target config data store by copying the source
     * config store. If a new store is created it has to be inserted into _configStores.
     * @param target    the name of the config store to create/replace
     * @param source    the name of the config store to copy from
     */
    virtual bool createOrReplaceConfigStore (std::string target, std::string source);

    /**
     * Deletes the target config data store and removes it from _configStores.
     * BE CAREFUL this function will also delete the running config _activeConfigName!
     * @param target    the name of the config store to delete
     * @return          true if the config store was actually removed
     */
    virtual bool deleteConfigStore(const std::string& target);

    /**
     * Cached reference to the NetConf server.
     */
    NetConfServerBase* _netConfServer;

    /**
     * Cached parameter if the status should be displayed
     */
    bool _displayStatus;

    /**
     * Cached parameter for the maximum number of data stores.
     */
    int _numMaxDataStores;

    /**
     * Configuration data stores mapped to there name
     */
    std::unordered_map<std::string, NetConfConfigDataStoreBase*> _configStores;

    /**
     * Name of the running config. "running" by default"
     */
    std::string _activeConfigName = "running";

    /**
     * State data store
     */
    NetConfStateDataStore* _stateStore;

    /**
     * Gate name (@directIn) for request inputs in data stores
     */
    static const char REQUEST_IN_GATE_NAME []; // = "requestIn";
    /**
     * Gate name (@directIn) for response inputs to NetConf server
     */
    static const char RESPONSE_OUT_GATE_NAME []; // = "responseIn";

  private:
};

}  // namespace SDN4CoRE

#endif
