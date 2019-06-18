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

#ifndef __SDN4CORE_NETCONFSERVER_H_
#define __SDN4CORE_NETCONFSERVER_H_

#include <omnetpp.h>
#include <unordered_map>
#include <string>

//forward declerations
//namespace SDN4CoRE {
//    class NetConfConfigDataStoreBase;
//    class NetConfStateDataStoreBase;
//}  // namespace SDN4CoRE

#include "sdn4core/netconf/server/base/NetConfConfigDataStoreBase.h"
#include "sdn4core/netconf/server/base/NetConfStateDataStoreBase.h"

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Base implementation for a NetConfServer, communicating with a NetConf client @see~NetConfClient.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfServerBase : public cSimpleModule
{

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    /**
     * Active configuration data store
     */
    std::string _activeConfigDataStore;

    /**
     * Cached reference to the NetConf configuration data stores.
     */
    std::unordered_map<std::string,NetConfConfigDataStoreBase*> _configDataStores;

    /**
     * Cached reference to the NetConf state data store.
     */
    NetConfStateDataStoreBase* _stateDataStore;

private:
    /**
     * Gate name (@directIn) for request inputs in data stores
     */
    static const char REQUEST_FWD_GATE_NAME []; // = "requestIn";
    /**
     * Gate name (@directIn) for response inputs to NetConf server
     */
    static const char RESPONSE_IN_GATE_NAME []; // = "responseIn";
    /**
     * Gate name for transport inputs
     */
    static const char TRANSPORT_IN_GATE_NAME []; //= "transportIn";
    /**
     * Gate name for transport outputs
     */
    static const char TRANSPORT_OUT_GATE_NAME []; //= "transportOut";

};

}  // namespace SDN4CoRE

#endif
