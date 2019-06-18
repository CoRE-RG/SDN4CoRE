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
#include <list>

#include "sdn4core/utility/processing/ProcessingTimeSimulation.h"

#include "sdn4core/netconf/server/base/NetConfConfigDataStoreBase.h"
#include "sdn4core/netconf/server/base/NetConfStateDataStoreBase.h"
// AUTO-GENERATED MESSAGES
#include "sdn4core/netconf/messages/NetConfMessage_m.h"

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Base implementation for a NetConfServer, communicating with a NetConf client @see~NetConfClient.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfServerBase : public ProcessingTimeSimulation
{

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    /**
     * @see ~ProcessingTimeSimulation::processScheduledMessage(cMessage *msg)
     */
    virtual void processScheduledMessage(cMessage *msg);

    /**
     * Forwards the message to the protocol specific transport layer.
     * The NetConfCtrlInfo_Transport should be attached to the message.
     * @param msg   the message to forward
     */
    virtual void forwardToTransport(cMessage* msg) = 0;

    /**
     * Extract the NetConfMessage from the message and attach protocol specific
     * transport layer information as NetConfCtrlInfo_Transport to the message.
     * @param msg   the message to forward
     * @return      the extracte NetConfMessage
     */
    virtual NetConfMessage* getNetConfFromTransport(cMessage* msg) = 0;

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
