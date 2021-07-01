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

#include <sdn4core/netconf/datastructures/ieee8021qbv/NetConfConfigIEEE8021Qbv.h>

namespace SDN4CoRE {

NetConfConfigIEEE8021Qbv::NetConfConfigIEEE8021Qbv() {

}

NetConfConfigIEEE8021Qbv::~NetConfConfigIEEE8021Qbv() {
}

unsigned int  NetConfConfigIEEE8021Qbv::getByteSize() {
    return _gateConfigurations.size() * sizeof(IEEE8021QbvGateConfig_t);
}

NetConfConfigIEEE8021Qbv::IEEE8021QbvGateConfig_t* NetConfConfigIEEE8021Qbv::getGateConfigurationForPort(
        int port) {
    for(IEEE8021QbvGateConfig_t* gateConfig: _gateConfigurations){
        if(gateConfig->port == port) {
            return gateConfig;
        }
    }
    return nullptr;
}

void NetConfConfigIEEE8021Qbv::setGateConfiguration(IEEE8021QbvGateConfig_t* config) {
    for(auto gateConfig: _gateConfigurations){
        if(gateConfig->port == config->port) {
            gateConfig = config;
            return;
        }
    }
    _gateConfigurations.push_back(config);
}

} /* namespace SDN4CoRE */
