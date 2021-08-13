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

//SDN4CoRE
#include <sdn4core/netconf/datastores/config/multipart/NetConfDataConfiguratorMultipart.h>
#include <sdn4core/netconf/datastructures/multipart/NetConfConfigMultipart.h>
#include <sdn4core/netconf/messages/NetConfOperation_m.h>

namespace SDN4CoRE {

Define_Module(NetConfDataConfiguratorMultipart);

NetConfDataConfiguratorMultipart::~NetConfDataConfiguratorMultipart() {

}

void NetConfDataConfiguratorMultipart::initialize() {
    auto running = getParentModule()->getSubmodule("running");
    if (auto runningStore = dynamic_cast<NetConfRunningDataStore*>(running)){
        this->_runningDataStore = runningStore;
    } else {
        throw cRuntimeError("Running data store not found");
    }
}

NetConfConfig* SDN4CoRE::NetConfDataConfiguratorMultipart::getConfig(
        NetConfFilter& filter) {
    throw cRuntimeError("Get Config not implemented");
}

bool SDN4CoRE::NetConfDataConfiguratorMultipart::editConfig(
        int defaultOperation, int errorOption, NetConfConfig* config) {
    Enter_Method("editConfig()");
    bool status = true;
    if(NetConfConfigMultipart* multiPartConfig = dynamic_cast<NetConfConfigMultipart*>(config)){
        if((errorOption == NETCONFOPERATION_ERROROPTION_ROLLBACKONERROR) && !validateConfig(config)) {
            return false;
        }
        for(auto config : multiPartConfig->getConfigurations()){
            status &= _runningDataStore->editConfig(defaultOperation, errorOption, config);
            if(!status && (errorOption == NETCONFOPERATION_ERROROPTION_STOPONERROR)){
                return false;
            }
        }
    } else {
        return false;
    }
    //if no error or option was set NETCONFOPERATION_ERROROPTION_CONTINUEONERROR
    return status;
}

bool SDN4CoRE::NetConfDataConfiguratorMultipart::validateConfig( NetConfConfig* config, int defaultOperationg) {
    Enter_Method("validateConfig()");
    NetConfConfigMultipart* multiPartConfig = dynamic_cast<NetConfConfigMultipart*>(config);
    bool valid = multiPartConfig != nullptr;
    if(valid){
        for(auto config : multiPartConfig->getConfigurations()){
            if(!_runningDataStore->validateConfig(config)){
                valid = false;
                break;
            }
        }
    }
    return valid;
}

} /* namespace SDN4CoRE */
