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
//STD
#include <string>
#include <unordered_map>

#include "sdn4core/netconf/datastores/config/base/NetConfConfigDataStore.h"
#include "sdn4core/netconf/datastores/state/base/NetConfStateDataStore.h"

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
     * Creates an rpc reply element containing the data
     * @param config    the config data to encapsulate
     * @return  the NetConf_RPCReplyElement_Data
     */
    NetConf_RPCReplyElement* createRPCReplyElement_Data(
            NetConfConfig* config);


    NetConf_RPCReplyElement* createRPCReplyElement_Error(
            int error_type, const char * error_tag, int error_severity,
            const char * error_app_tag);

    NetConf_RPCReplyElement* handleGetConfig(NetConfOperation* operation);

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
    std::unordered_map<std::string, NetConfConfigDataStore> _configStores;

    /**
     * State data store
     */
    NetConfStateDataStore _stateStore;


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
