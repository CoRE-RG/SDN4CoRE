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

#ifndef SDN4CORE_NETCONF_DATASTORES_CONFIG_NETCONFCONFIGDATASTORE_H_
#define SDN4CORE_NETCONF_DATASTORES_CONFIG_NETCONFCONFIGDATASTORE_H_

#include <string>

#include "sdn4core/netconf/messages/NetConfMessage_m.h"
#include "sdn4core/netconf/messages/NetConfOperation_m.h"

#include "sdn4core/netconf/datastores/datastructures/base/NetConfFilter.h"
#include "sdn4core/netconf/datastores/datastructures/base/NetConfConfig.h"

namespace SDN4CoRE {

/**
 * Provides a base implementation for the interface of a NetConfConfigDataStore.
 * This must be inherited by a device specific state data store.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfConfigDataStore {
public:
    NetConfConfigDataStore();
    virtual ~NetConfConfigDataStore();

    virtual NetConfConfig* getConfig(NetConfFilter& filter);
};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_NETCONF_DATASTORES_CONFIG_NETCONFCONFIGDATASTORE_H_ */
