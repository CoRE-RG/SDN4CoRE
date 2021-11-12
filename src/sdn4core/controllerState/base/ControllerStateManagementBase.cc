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

#include "ControllerStateManagementBase.h"
#include <string>
#include <sdn4core/utility/dynamicmodules/DynamicModuleHandling.h>

// TODO implement type safety using template class instead of cModule type.

using namespace std;

namespace SDN4CoRE {

Define_Module(ControllerStateManagementBase);

cModule* ControllerStateManagementBase::checkOrCreateSwitch(
        openflow::Switch_Info* swinfo) {
    cModule* switchModule = findSwitchState(swinfo);
    if (!switchModule) {
        if ((switchModule = createFinalizeAndScheduleDynamicModule(
                "sdn4core.controllerState.base.ControllerSwitchState",
                "switchState", this->getParentModule(), true))) {
            switchModule->par("switchName").setStringValue(
                    swinfo->getMacAddress());
        } else {
            throw cRuntimeError("Could not create state module for switch %s ",
                    swinfo->getMacAddress().c_str());
        }
    }

    return switchModule;
}

PortModule* ControllerStateManagementBase::checkOrCreateSwitchPort(
        openflow::Switch_Info* swinfo, int port) {
    PortModule* portModule = findSwitchPort(swinfo, port);
    if (!portModule) {
        if (cModule* switchModule = checkOrCreateSwitch(swinfo)) {
            if ((portModule =
                    dynamic_cast<PortModule*>(createFinalizeAndScheduleDynamicModule(
                            "sdn4core.controllerState.base.PortModule",
                            "portModules", switchModule, true)))) {
                portModule->setPort(port);
            } else {
                throw cRuntimeError(
                        "Could not create port module %s for switch %s ",
                        to_string(port).c_str(), swinfo->getMacAddress().c_str());
            }
        }
    }

    return portModule;
}

cModule* ControllerStateManagementBase::checkOrCreateManagedPerSwitchState(
        openflow::Switch_Info* swinfo) {
    return checkOrCreatePerSwitchState(swinfo, par("switchStateModulePath").stringValue(),
            par("switchStateModuleName").stringValue());
}

cModule* ControllerStateManagementBase::checkOrCreatePerSwitchState(
        openflow::Switch_Info* swinfo, const char* stateModulePath, const char* stateName) {
    cModule* state = findPerSwitchState(swinfo, stateName);
    if (!state) {
        if (cModule* switchModule = checkOrCreateSwitch(swinfo)) {
            if (!(state = createFinalizeAndScheduleDynamicModule(
                    stateModulePath, stateName, switchModule, true))) {
                throw cRuntimeError(
                        "Could not create state module %s for switch %s ",
                        stateName, swinfo->getMacAddress().c_str());
            }
        }
    }

    return state;
}

cModule* ControllerStateManagementBase::findSwitchState(
        openflow::Switch_Info* swinfo) {
    cModule* found = nullptr;
    if (auto switchStateVec = this->getParentModule()->getSubmodule(
            "switchState", 0)) {
        for (int i = 0; i < switchStateVec->getVectorSize(); i++) {
            cModule* currentModule = this->getParentModule()->getSubmodule(
                    "switchState", i);
            if (currentModule->par("switchName").str()
                    == swinfo->getMacAddress()) {
                found = currentModule;
                break;
            }
        }
    }
    return found;
}

PortModule* ControllerStateManagementBase::findSwitchPort(
        openflow::Switch_Info* swinfo, int port) {
    PortModule* found = nullptr;
    cModule* switchState = findSwitchState(swinfo);
    if (auto portVec = switchState->getSubmodule("portModules", 0)) {
        for (int i = 0; i < portVec->getVectorSize(); i++) {
            if ((found = dynamic_cast<PortModule*>(switchState->getSubmodule(
                            "portModules", i)))) {
                if (found->getPort() == port) {
                    break;
                } else {
                    found = nullptr;
                }
            }
        }
    }
    return found;
}

cModule* ControllerStateManagementBase::findManagedPerSwitchState(
        openflow::Switch_Info* swinfo) {
    return findPerSwitchState(swinfo, par("switchStateModulePath").stringValue());
}

cModule* ControllerStateManagementBase::findPerSwitchState(
        openflow::Switch_Info* swinfo, const char* stateName, int index) {
    cModule* switchState = findSwitchState(swinfo);
    return switchState->getSubmodule("stateName", index);
}

} // End namespace SDN4CoRE
