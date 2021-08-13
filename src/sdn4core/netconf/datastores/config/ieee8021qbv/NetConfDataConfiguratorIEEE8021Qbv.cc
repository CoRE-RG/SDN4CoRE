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

//SDN4CoRE
#include <sdn4core/netconf/datastores/config/ieee8021qbv/NetConfDataConfiguratorIEEE8021Qbv.h>
#include <sdn4core/netconf/datastructures/ieee8021qbv/NetConfConfigIEEE8021Qbv.h>

using namespace std;
using namespace CoRE4INET;

namespace SDN4CoRE {

Define_Module(NetConfDataConfiguratorIEEE8021Qbv);

void NetConfDataConfiguratorIEEE8021Qbv::initialize()
{
    NetConfDataConfiguratorBase::initialize();
    //find number of ports
    int numPorts = getParentModule()->getParentModule()->getSubmodule("etherMAC",0)->getVectorSize();

    //find IEEE8021QbvGateControlList modules of this device
    for(int i=0; i<numPorts; i++){
        cModule* module = getParentModule()->getParentModule()->getSubmodule("etherMAC",i)->getSubmodule("shaper")->getSubmodule("gateControlList");
        if(module){
            if(IEEE8021QbvGateControlList* gateControlListModule = dynamic_cast<IEEE8021QbvGateControlList*>(module)){
                _gateControlListModules[i] = gateControlListModule;
            } else {
                cRuntimeError("Module found in \"^.etherMAC.shaper.gateControlList\", but is no IEEE8021QbvGateControlList");
            }
        } else {
            cRuntimeError("No Module found in \"^.etherMAC.shaper.gateControlList\"");
        }
    }
}

NetConfConfig* NetConfDataConfiguratorIEEE8021Qbv::getConfig(
        NetConfFilter& filter) {
    Enter_Method("getConfig()");
    //todo add filter option
    NetConfConfigIEEE8021Qbv* config = new NetConfConfigIEEE8021Qbv();
    for (std::map<int, CoRE4INET::IEEE8021QbvGateControlList*>::iterator controlListIter =
            _gateControlListModules.begin();
            controlListIter != _gateControlListModules.end();
            ++controlListIter) {

        NetConfConfigIEEE8021Qbv::IEEE8021QbvGateConfig_t gateConfig;
        gateConfig.port = controlListIter->first;
        gateConfig.gateControlList = controlListIter->second->par("controlList").stdstringValue();
    }

    return dynamic_cast<NetConfConfig*>(config);
}

bool NetConfDataConfiguratorIEEE8021Qbv::editConfig(int defaultOperation,
        int errorOption, NetConfConfig* config) {
     Enter_Method("editConfig()");

    bool valid = validateConfig(config);
    if(valid){
        if(NetConfConfigIEEE8021Qbv* qbvConfig = dynamic_cast<NetConfConfigIEEE8021Qbv*>(config)){
            for (std::map<int, CoRE4INET::IEEE8021QbvGateControlList*>::iterator controlListIter =
                    _gateControlListModules.begin();
                    controlListIter != _gateControlListModules.end();
                    ++controlListIter) {
                if(NetConfConfigIEEE8021Qbv::IEEE8021QbvGateConfig_t* gateConfig = qbvConfig->getGateConfigurationForPort(controlListIter->first)){
                    controlListIter->second->setGateControlList(gateConfig->gateControlList);
                }
            }
        }
    }
    if(valid){
        emit(editConfigOkSignal,1L);
    }else{
        emit(editConfigErrorSignal,1L);
    }
    return valid;
}

bool NetConfDataConfiguratorIEEE8021Qbv::validateConfig( NetConfConfig* config, int defaultOperationg) {
    Enter_Method("validateConfig()");
    NetConfConfigIEEE8021Qbv* qbvConfig = dynamic_cast<NetConfConfigIEEE8021Qbv*>(config);
    bool valid = qbvConfig != nullptr;
    if(valid){
        for (auto gateConfig : qbvConfig->getGateConfigurations()) {
            auto found = _gateControlListModules.find(gateConfig->port);
            if(found == _gateControlListModules.end()) {
                valid = false;
                break;
            }
        }
    }
    return valid;
}

} /* namespace SDN4CoRE */
