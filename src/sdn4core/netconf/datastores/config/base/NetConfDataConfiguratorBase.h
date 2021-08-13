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

#ifndef __SDN4CORE_NETCONFCONFIGDATASTOREBASE_H_
#define __SDN4CORE_NETCONFCONFIGDATASTOREBASE_H_

//Omnet
#include <omnetpp.h>
//SDN4CoRE
#include <sdn4core/netconf/datastructures/base/NetConfConfig.h>
#include <sdn4core/netconf/datastructures/base/NetConfFilter.h>


using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Contains the base module implementation and provides interface methods of a netconf config data store.
 * NetConfConfigDataStore implementations execute netconf commands on the
 * device such as get, copy and edit config commands.
 * They are managed and dynamically created during runtime by
 * @see~INetConfDataStoreManager modules.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfDataConfiguratorBase : public cSimpleModule
{
  public:
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
     * Validate the given config if it valid or not
     * @param configSRP the configuration that should be tested
     * @param defaultOperation the desired default operation that should be executed
     */
    virtual bool validateConfig(NetConfConfig* config, int defaultOperation = 0) = 0;

  protected:
    /**
     *
     */
    static simsignal_t editConfigOkSignal;

    /**
     *
     */
    static simsignal_t editConfigErrorSignal;

};

} /* namespace SDN4CoRE */

#endif
