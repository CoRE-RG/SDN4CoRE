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

#include "sdn4core/netconf/datastructures/base/NetConfFilter.h"
#include "sdn4core/netconf/datastructures/base/NetConfConfig.h"

namespace SDN4CoRE {

/**
 * Provides a base implementation for the interface of a NetConfConfigDataStore.
 * This must be inherited by a device specific state data store.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfConfigDataStore {
public:
    NetConfConfigDataStore() {

    };
    virtual ~NetConfConfigDataStore(){

    };

    /**
     * Creates a NetConfConfig from the current configuration data that only contains elements in the filter.
     * @param filter    the filter to be applied, if empty the whole config data set is returned
     * @return          the requested configuration data
     */
    virtual NetConfConfig* getConfig(NetConfFilter& filter) = 0;

    /**
     * Applies the changes in the config using the defaultOperation.
     * @param defaultOperation  Selects the default operation, one of @see ~NetConfOperation_Operation.
     * @param errorOption       Selects how to react on errors, one of @see ~NetConfOperation_ErrorOption.
     * @param config            The config to be applied
     * @return                  true if the changes could be applied, false if an error occurred.
     */
    virtual bool editConfig(int defaultOperation, int errorOption, NetConfConfig* config) = 0;

    /**
     * Creates a copy of this config data store and returns it.
     * @return  the copy of this configuration
     */
    virtual NetConfConfigDataStore* copyConfig() = 0;
};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_NETCONF_DATASTORES_CONFIG_NETCONFCONFIGDATASTORE_H_ */
