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
#include <sdn4core/netconf/datastructures/multipart/NetConfConfigMultipart.h>

namespace SDN4CoRE {

NetConfConfigMultipart::NetConfConfigMultipart (const NetConfConfigMultipart &old_obj):NetConfConfig(old_obj) {
    for( auto old_config: old_obj._configs){
        NetConfConfig* newConfig = dynamic_cast<NetConfConfig*>(old_config->dup());
        take(newConfig);  // take ownership
        this->_configs.push_back(newConfig);
    }
}

SDN4CoRE::NetConfConfigMultipart::~NetConfConfigMultipart() {
    for( auto config: _configs){
       drop(config);  // release ownership
       if(config != nullptr){
           delete config;
       }
    }
}

unsigned int NetConfConfigMultipart::getByteSize() {
    unsigned int size = 0;
    for(auto config: _configs){
        size += config->getByteSize();
    }
    return size;
}

NetConfConfig_Base* NetConfConfigMultipart::dup() const {
    return new NetConfConfigMultipart(*this);
}

std::vector<NetConfConfig*> NetConfConfigMultipart::getConfigurations() {
    return _configs;
}

void NetConfConfigMultipart::setConfigurations(std::vector<NetConfConfig*> new_configs) {
    //remove old configs
    for( auto config: _configs){
       drop(config);  // release ownership
       if(config != nullptr){
           delete config;
       }
    }
    _configs.clear();
    //copy new ones
    for( auto config: new_configs){
        NetConfConfig* newConfig = dynamic_cast<NetConfConfig*>(config->dup());
        take(newConfig);  // take ownership
        this->_configs.push_back(newConfig);
    }
}

void NetConfConfigMultipart::addConfiguration(NetConfConfig* new_config) {
    take(new_config);  // take ownership
    _configs.push_back(new_config);
}

} /* namespace SDN4CoRE */

