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

#include <sdn4core/netconf/datastores/config/IEEE8021Qbv/NetConfConfigDataStoreIEEE8021Qbv.h>

#include <sdn4core/netconf/datastructures/IEEE8021Qbv/NetConfConfigIEEE8021Qbv.h>

using namespace std;
using namespace CoRE4INET;

namespace SDN4CoRE {

NetConfConfigDataStoreIEEE8021Qbv::NetConfConfigDataStoreIEEE8021Qbv(
        unordered_map<int, IEEE8021QbvGateControlList*>& gateControlListModules) : NetConfConfigDataStore(){

    for (std::unordered_map<int, CoRE4INET::IEEE8021QbvGateControlList*>::iterator controlListIter =
            gateControlListModules.begin();
            controlListIter != gateControlListModules.end();
            ++controlListIter) {
        _gateControlListModules[controlListIter->first] = controlListIter->second;
    }
}

NetConfConfigDataStoreIEEE8021Qbv::~NetConfConfigDataStoreIEEE8021Qbv() {
}

NetConfConfig* NetConfConfigDataStoreIEEE8021Qbv::getConfig(
        NetConfFilter& filter) {
    //todo add filter option
    NetConfConfigIEEE8021Qbv* config = new NetConfConfigIEEE8021Qbv();
    for (std::unordered_map<int, CoRE4INET::IEEE8021QbvGateControlList*>::iterator controlListIter =
            _gateControlListModules.begin();
            controlListIter != _gateControlListModules.end();
            ++controlListIter) {

        NetConfConfigIEEE8021Qbv::IEEE8021QbvGateConfig_t gateConfig;
        gateConfig.port = controlListIter->first;
        gateConfig.gateControlList = controlListIter->second->par("controlList").stdstringValue();
    }

    return dynamic_cast<NetConfConfig*>(config);
}

bool NetConfConfigDataStoreIEEE8021Qbv::editConfig(int defaultOperation,
        int errorOption, NetConfConfig* config) {
    bool updated = false;
    NetConfConfigIEEE8021Qbv* qbvConfig = dynamic_cast<NetConfConfigIEEE8021Qbv*>(config);
    if(qbvConfig){
        for (std::unordered_map<int, CoRE4INET::IEEE8021QbvGateControlList*>::iterator controlListIter =
                _gateControlListModules.begin();
                controlListIter != _gateControlListModules.end();
                ++controlListIter) {

            NetConfConfigIEEE8021Qbv::IEEE8021QbvGateConfig_t* gateConfig = qbvConfig->getGateConfigurationForPort(controlListIter->first);
            if(gateConfig){
                controlListIter->second->par("controlList").setStringValue(gateConfig->gateControlList);
                updated = true;
            }
        }
    }

    return updated;
}

NetConfConfigDataStore* NetConfConfigDataStoreIEEE8021Qbv::copyConfig() {
    throw cRuntimeError(
            "Copy config operation on NetConfConfigDataStoreIEEE8021Qbv not supported.");
    return nullptr;
}

} /* namespace SDN4CoRE */
