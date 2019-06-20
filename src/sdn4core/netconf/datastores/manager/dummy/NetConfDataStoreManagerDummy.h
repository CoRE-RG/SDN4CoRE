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

#ifndef __SDN4CORE_NETCONFDATASTOREMANAGERDUMMY_H_
#define __SDN4CORE_NETCONFDATASTOREMANAGERDUMMY_H_

#include <omnetpp.h>

#include <sdn4core/netconf/datastores/manager/base/NetConfDataStoreManagerBase.h>

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * This is a dummy netconf data store manager that uses the dummy config
 * and state manager (@see ~NetConfConfigDataStoreDummy, ~NetConfStateDataStoreDummy)
 * All request are answered empty and success.
 * NetConfDataStoreManger implementations handle NetConf configuration and
 * state operations for a specific device.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfDataStoreManagerDummy : public NetConfDataStoreManagerBase
{
  protected:

    /**
     * Initializes the initial config and state data stores on startup.
     * This function must also set the _activeConfigName to the running config name.
     */
    virtual void initializeDataStores() override;
};

}  // namespace SDN4CoRE

#endif
