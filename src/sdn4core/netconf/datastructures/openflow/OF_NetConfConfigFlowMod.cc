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


#include <sdn4core/netconf/datastructures/openflow/OF_NetConfConfigFlowMod.h>

namespace SDN4CoRE {

OF_NetConfConfigFlowMod::OF_NetConfConfigFlowMod(){}

OF_NetConfConfigFlowMod::~OF_NetConfConfigFlowMod(){}

OF_NetConfConfigFlowMod::OF_NetConfConfigFlowMod(const OF_NetConfConfigFlowMod &old_obj){
    this->flowTableConfigs = old_obj.flowTableConfigs;
}

void OF_NetConfConfigFlowMod::setFlowTableConfigs(std::vector<OF_FlowTableConfig_t*> flowTableConfigs){
    this->flowTableConfigs = flowTableConfigs;
}

void OF_NetConfConfigFlowMod::addFlowTableConfig(OF_FlowTableConfig_t* flowTableConfig){
    this->flowTableConfigs.push_back(flowTableConfig);
}

std::vector<OF_NetConfConfigFlowMod::OF_FlowTableConfig_t*> OF_NetConfConfigFlowMod::getFlowTableConfigs(){
    return this->flowTableConfigs;
}

unsigned int OF_NetConfConfigFlowMod::getByteSize(){
    return sizeof(OF_FlowTableConfig_t) * flowTableConfigs.size();
}

NetConfConfig_Base *OF_NetConfConfigFlowMod::dup()const {
    return new OF_NetConfConfigFlowMod(*this);
}

}
