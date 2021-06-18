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

#include <sdn4core/utility/dynamicparameters/DynamicChannelParameterChanger.h>
#include "inet/common/InitStages.h"

using namespace std;
using namespace inet;

namespace SDN4CoRE{
Define_Module(DynamicChannelParameterChanger);

void DynamicChannelParameterChanger::fillComponentToChange(vector<string>& paths){
    for (string path : paths){
        //resolve the module path
        cModule* module = this->getModuleByPath(path.c_str());
        if(!module) {
            throw cRuntimeError("The channels connected module %s was not found", path.c_str());
        }
        //find the gate
        string gateName = this->par("gateAtComponent");
        if(gateName.empty()) {
            throw cRuntimeError("Gate %s not specified", gateName.c_str());
        }
        if(!module->hasGate(gateName.c_str())){
            throw cRuntimeError("Module %s has no gate named %s ", path.c_str(), gateName.c_str());
        }
        //check weather it is a vector and the full vector should be updated
        int startIdx = this->par("gateIdx").intValue();
        int gateSize = module->gateSize(gateName.c_str());
        if(this->par("fullVector")) {
            if(!module->isGateVector(gateName.c_str())) {
                throw cRuntimeError("Changing the full vector is set but gate %s at module %s is no vector gate", gateName.c_str(), path.c_str());
            }
            startIdx = 0;
        }
        // add channels to components
        for (int i = startIdx; i < gateSize; i++) {
            vector<cComponent*> channels;
            //find in and outbound channels
            if(module->gateType(gateName.c_str()) == cGate::INOUT) {
                channels.push_back(getChannelForGate(module->gateHalf(gateName.c_str(), cGate::INPUT, i)));
                channels.push_back(getChannelForGate(module->gateHalf(gateName.c_str(), cGate::OUTPUT, i)));
            } else {
                channels.push_back(getChannelForGate(module->gate(gateName.c_str(), i)));
            }
            //add channels to components
            for(auto channel : channels){
                if(!channel){
                    throw cRuntimeError("Channel at gate %s with index %s in module %s", gateName.c_str(), to_string(i).c_str(), path.c_str());
                }
                if(!channel->hasPar(_parToChange.c_str())){
                    throw cRuntimeError("Channel at gate %s of module %s has no parameter named %s", gateName.c_str(), path.c_str(), _parToChange.c_str());
                }
                _componentsToChange[channel] = channel->par(_parToChange.c_str()).str();
            }
            //abort if not use full vector
            if(!this->par("fullVector")) {
               break;
            }
        }
    }
}

cComponent* DynamicChannelParameterChanger::getChannelForGate(cGate* gate) {
    cComponent* channel = nullptr;
    cGate* inOrigin = nullptr;
    switch(gate->getType()) {
    case cGate::INPUT:
        inOrigin = gate->getPreviousGate();
        if(!inOrigin) {
            throw cRuntimeError("Input gate %s in module %s seems unconnected", gate->getFullName(), gate->getOwner()->getFullName());
        }
        channel = dynamic_cast<cComponent*>(inOrigin->getChannel());
        break;
    case cGate::OUTPUT:
        channel = dynamic_cast<cComponent*>(gate->getChannel());
        break;
    default:
        break;
    }
    return channel;
}

} // namespace SDN4CoRE
