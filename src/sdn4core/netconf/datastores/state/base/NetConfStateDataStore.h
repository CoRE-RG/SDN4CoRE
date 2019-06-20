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

#ifndef SDN4CORE_NETCONF_DATASTORES_STATE_NETCONFSTATEDATASTORE_H_
#define SDN4CORE_NETCONF_DATASTORES_STATE_NETCONFSTATEDATASTORE_H_


#include "sdn4core/netconf/datastructures/base/NetConfFilter.h"
#include "sdn4core/netconf/datastructures/base/NetConfConfig.h"

namespace SDN4CoRE {

/**
 * Provides a base implementation for the interface of a NetConfStateDataStore.
 * This must be inherited by a device specific state data store.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfStateDataStore {
public:
    NetConfStateDataStore();
    virtual ~NetConfStateDataStore();

    /**
     * Creates a NetConfConfig from the current state data that only contains elements in the filter.
     * @param filter    the filter to be applied, if empty the whole state data set is returned
     * @return          the requested configuration data
     */
    virtual NetConfConfig* get(NetConfFilter& filter) = 0;
};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_NETCONF_DATASTORES_STATE_NETCONFSTATEDATASTORE_H_ */
