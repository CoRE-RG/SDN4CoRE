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

#include <sdn4core/netconf/datastores/config/dummy/NetConfConfigDataStoreDummy.h>
#include "NetConfDataStoreManagerDummy.h"

#include "sdn4core/netconf/datastores/state/dummy/NetConfStateDataStoreDummy.h"
#include <sdn4core/utility/dynamicmodules/DynamicModuleHandling.h>
namespace SDN4CoRE {

Define_Module(NetConfDataStoreManagerDummy);

void NetConfDataStoreManagerDummy::initializeDataStores() {
    NetConfConfigDataStoreDummy* store = dynamic_cast<NetConfConfigDataStoreDummy*> (
            createDynamicModule(
            "sdn4core.netconf.datastores.config.dummy.NetConfConfigDataStoreDummy",
            "configStores", this->getParentModule(), true));
    if(!store){
        throw cRuntimeError("Failed to create dummy data store.");
    }
    store->finalizeParameters();

    _configStores[_activeConfigName] = new NetConfConfigDataStoreDummy();
    _stateStore = new NetConfStateDataStoreDummy();

}


}  // namespace SDN4CoRE
