//
// c Tobias Haugg, for HAW Hamburg
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

#ifndef SDN4CORE_NETCONF_DATASTORES_CONFIG_OPENFLOW_NETCONFDATACONFIGURATORFLOWTABLE_H_
#define SDN4CORE_NETCONF_DATASTORES_CONFIG_OPENFLOW_NETCONFDATACONFIGURATORFLOWTABLE_H_

//Omnet
#include <omnetpp.h>
//Openflow
#include "openflow/messages/Open_Flow_Message_m.h"
#include "openflow/openflow/switch/flowtable/OF_FlowTable.h"
//SDN4CoRE
#include <sdn4core/netconf/datastores/config/base/NetConfDataConfiguratorBase.h>


using namespace omnetpp;

namespace SDN4CoRE {


/**
 * Provides a FlowTable implementation for the interface of a NetConfConfigDataStore.
 *
 * @author Tobias Haugg, for HAW Hamburg
 */
class NetConfDataConfiguratorFlowTable: public NetConfDataConfiguratorBase {
public:
    /**
     * Creates a NetConfConfig from the current configuration data that only contains elements in the filter.
     * @param filter    the filter to be applied, if empty the whole config data set is returned
     * @return          the requested configuration data
     */
    virtual NetConfConfig* getConfig(const NetConfFilter& filter) override;

    /**
     * Applies the changes in the config using the defaultOperation.
     * @param defaultOperation  Selects the default operation, one of @see ~NetConfOperation_Operation.
     * @param errorOption       Selects how to react on errors, one of @see ~NetConfOperation_ErrorOption.
     * @param config            The config to be applied
     * @return                  true if the changes could be applied, false if an error occurred.
     */
    virtual bool editConfig(int defaultOperation, int errorOption, NetConfConfig* config) override;

    /**
     * Validate the given config if it valid or not
     * @param configSRP the configuration that should be tested
     * @param defaultOperation the desired default operation that should be executed
     */
    virtual bool validateConfig(NetConfConfig* config, int defaultOperation = 0) override;

protected:
    virtual void initialize() override;

    /**
     * The OpenFlow Flow Table containing match entries
     */
    std::vector<openflow::OF_FlowTable*> _flowTables;


};
}

#endif /* SDN4CORE_NETCONF_DATASTORES_CONFIG_OPENFLOW_NETCONFDATACONFIGURATORFLOWTABLE_H_ */
