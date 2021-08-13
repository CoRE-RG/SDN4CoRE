//
// c Tobias Haugg, Timo Haeckel, for HAW Hamburg
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

//SDN4CoRE
#include <sdn4core/netconf/datastores/store/running/NetConfRunningDataStore.h>
#include <sdn4core/netconf/datastores/config/base/NetConfDataConfiguratorBase.h>
#include <sdn4core/netconf/datastores/config/multipart/NetConfDataConfiguratorMultipart.h>
#include <sdn4core/utility/dynamicmodules/DynamicModuleHandling.h>


using namespace std;

namespace SDN4CoRE {

Define_Module(NetConfRunningDataStore);

void NetConfRunningDataStore::initialize() {
    NetConfDataStoreBase::initialize();
    auto configurators = getParentModule()->getSubmodule("configurators", 0);
    bool hasMultipart = false;
    if(configurators) {
        int numConfigurators = configurators->getVectorSize();
        for (int i = 0; i < numConfigurators; i++) {
            NetConfDataConfiguratorBase* configurator =
                    dynamic_cast<NetConfDataConfiguratorBase*>(getParentModule()->getSubmodule(
                            "configurators", i));
            if (configurator) {
                _configurators.push_back(configurator);
                if(auto multiPartConfig = dynamic_cast<NetConfDataConfiguratorMultipart*>(configurator)){
                    hasMultipart = true;
                }
            }
        }
    }
    if(!hasMultipart){
        auto multipartModule = createDynamicModule(
                "sdn4core.netconf.datastores.config.multipart.NetConfDataConfiguratorMultipart",
                "configurators",
                this->getParentModule(),
                true);
        if(auto multiPartConfig = dynamic_cast<NetConfDataConfiguratorMultipart*>(multipartModule)){
            multiPartConfig->finalizeParameters();
            _configurators.push_back(multiPartConfig);
        } else {
            throw cRuntimeError("Could not create multipart configurator module");
        }
    }
}

NetConfConfig *NetConfRunningDataStore::getConfig(NetConfFilter& filter) {
    Enter_Method("getConfig()");
    for (auto configurator : _configurators) {
        if (NetConfConfig* config = configurator->getConfig(filter)) {
            return config;
        }
    }
    return nullptr;
}

bool NetConfRunningDataStore::editConfig(int defaultOperation, int errorOption,
        NetConfConfig* config) {
    Enter_Method("editConfig()");
    bool newConfigs = false;
    for (auto configurator : _configurators) {
        if (configurator->editConfig(defaultOperation, errorOption, config)) {
            newConfigs = true;
        }
    }
    if(newConfigs){
        emit(editConfigOkSignal,1L);
    }else{
        emit(editConfigErrorSignal,1L);
    }
    return newConfigs;
}

bool NetConfRunningDataStore::validateConfig(NetConfConfig* config) {
   Enter_Method("validateConfig()");
   for (auto configurator : _configurators) {
       if (configurator->validateConfig(config)) {
           return true;
       }
   }
   return false;
}

}
