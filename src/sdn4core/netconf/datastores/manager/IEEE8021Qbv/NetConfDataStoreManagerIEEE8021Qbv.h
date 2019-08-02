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

#ifndef __SDN4CORE_NETCONFDATASTOREMANAGERIEEE8021QBV_H_
#define __SDN4CORE_NETCONFDATASTOREMANAGERIEEE8021QBV_H_

#include <omnetpp.h>

#include <sdn4core/netconf/datastores/manager/base/NetConfDataStoreManagerBase.h>

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * This is an IEEE8021Qbv netconf data store manager for the @see ~IEEE8021QbvOFNCSwitch.
 * It uses the IEEE8021Qbv config and state manager modules
 * (@see ~NetConfConfigDataStoreIEEE8021Qbv, ~NetConfStateDataStoreIEEE8021Qbv).
 * NetConfDataStoreManger implementations handle NetConf configuration and
 * state operations for a specific device.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfDataStoreManagerIEEE8021Qbv : public NetConfDataStoreManagerBase
{
protected:

    /**
     * Initializes the initial config and state data stores on startup.
     * This function must also set the _activeConfigName to the running config name.
     */
    virtual void initializeDataStores() override;

    /**
     * NOT SUPPORTED FOR THIS STORE
     * Handles a NetConfOperation_CopyConfig message, forwards it to the correct
     * config store and creates a reply.
     * @param operation     the NetConfOperation_CopyConfig message
     * @return              a NetConf_RPCReplyElement
     */
//    virtual NetConf_RPCReplyElement* handleCopyConfig(NetConfOperation* operation) override;

    /**
     * NOT SUPPORTED FOR THIS STORE
     * Handles a NetConfOperation_DeleteConfig message, forwards it to the correct
     * config store and creates a reply.
     * @param operation     the NetConfOperation_DeleteConfig message
     * @return              a NetConf_RPCReplyElement
     */
//    virtual NetConf_RPCReplyElement* handleDeleteConfig(NetConfOperation* operation) override;
};

}  // namespace SDN4CoRE

#endif
