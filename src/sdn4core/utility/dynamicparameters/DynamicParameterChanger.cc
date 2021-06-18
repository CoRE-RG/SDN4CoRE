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

#include <sdn4core/utility/dynamicparameters/DynamicParameterChanger.h>
#include "inet/common/InitStages.h"
using namespace inet;

using namespace std;

namespace SDN4CoRE{
#define DPC_CHANGE_MSG_NAME "Change"
#define DPC_RESET_MSG_NAME "Reset"

Define_Module(DynamicParameterChanger);

int DynamicParameterChanger::numInitStages() const {
    return NUM_INIT_STAGES;
}

void DynamicParameterChanger::fillComponentToChange(vector<string>& paths){
    for (string path : paths){
        //resolve the module path
        cModule* module = this->getModuleByPath(path.c_str());
        if(!module) {
            throw cRuntimeError("Module %s not found", path.c_str());
        }

        cComponent* component =  dynamic_cast<cComponent*>(module);
        if(!component->hasPar(_parToChange.c_str())){
            throw cRuntimeError("Module %s has no parameter named %s", path.c_str(), _parToChange.c_str());
        }
        _componentsToChange[component] = component->par(_parToChange.c_str()).str();
    }
}

void DynamicParameterChanger::initialize(int stage)
{
    if(stage == INITSTAGE_LAST) {
        //buffer parameters
        auto paths = cStringTokenizer(this->par("pathToComponentsToChange"), ";").asVector();
        if (paths.empty()){
            //abort if no modules set
            return;
        }
        this->_parToChange = this->par("parToChange").stdstringValue();
        if(_parToChange.empty()) {
            throw cRuntimeError("Parameter to change %s is empty", this->par("parToChange").str().c_str());
        }
        this->_newValue = this->par("newValue").stdstringValue();
        if(_newValue.empty()) {
            throw cRuntimeError("New value %s is empty", this->par("newValue").str().c_str());
        }
        fillComponentToChange(paths);
        //schedule change and reset messages
        scheduleAt(this->par("changeAt").doubleValue(),new cMessage(DPC_CHANGE_MSG_NAME));
        if(this->par("enableReset").boolValue()) {
            scheduleAt(this->par("resetAt").doubleValue(),new cMessage(DPC_RESET_MSG_NAME));
        }
    }
}

void DynamicParameterChanger::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage() && strcmp(msg->getName(), DPC_CHANGE_MSG_NAME) == 0){
        changePars();
    } else if(msg->isSelfMessage() && strcmp(msg->getName(), DPC_RESET_MSG_NAME) == 0){
        resetPars();
    }
    delete msg;
}

void DynamicParameterChanger::changePars() {
    for(auto component : _componentsToChange) {
        _componentsToChange[component.first] = component.first->par(_parToChange.c_str()).str();
        component.first->par(this->_parToChange.c_str()).parse(this->_newValue.c_str());
    }
}

void DynamicParameterChanger::resetPars() {
    for(auto component : _componentsToChange) {
        component.first->par(this->_parToChange.c_str()).parse(component.second.c_str());
    }
}

} // namespace SDN4CoRE
