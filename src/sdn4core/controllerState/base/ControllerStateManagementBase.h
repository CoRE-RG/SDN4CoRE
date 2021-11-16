//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
// c Timo Haeckel, for HAW Hamburg
// 

#ifndef __SDN4CORE_CONTROLLERSTATEMANAGEMENTBASE_H_
#define __SDN4CORE_CONTROLLERSTATEMANAGEMENTBASE_H_

#include <omnetpp.h>

#include <map>
#include <string>
#include <utility>
#include <algorithm>

#include <sdn4core/controllerState/base/PortModule.h>
#include <sdn4core/utility/dynamicmodules/DynamicModuleHandling.h>

//openflow
#include "openflow/openflow/controller/Switch_Info.h"

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * SimpleModule to manage controller state @see~ControllerState
 *
 * TODO is it possible that cached switches etc. are removed at
 * runtime and thus the cache should be verified?
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
template<class ManagedType = cModule>
class ControllerStateManagementBase: public cSimpleModule {
protected:

    /**
     * Get the switch state compound module for the switch.
     *
     * @param swinfo The info of the switch to look for.
     * @return The switch state compound module, nullptr if not found.
     */
    cModule* getSwitch(openflow::Switch_Info* swinfo) {
        if (cachedSwitches.find(swinfo->getMacAddress())
                != cachedSwitches.end()) {
            return cachedSwitches[swinfo->getMacAddress()];
        }
        return findSwitchState(swinfo);
    }
    ;

    /**
     * Checks whether a given switch is already present else create
     * the compound module.
     *
     * @param swinfo The info of the switch to look for.
     * @return the compound module that was created/found.
     */
    cModule* getOrCreateSwitch(openflow::Switch_Info* swinfo) {
        cModule* switchModule = getSwitch(swinfo);
        if (!switchModule) {
            switchModule = createFinalizeAndScheduleDynamicModule(
                    "sdn4core.controllerState.base.ControllerSwitchState",
                    "switchState", this->getParentModule(), true);
            if (!switchModule) {
                throw cRuntimeError(
                        "Could not create state module for switch %s ",
                        swinfo->getMacAddress().c_str());
            }
            onCreateSwitch(switchModule, swinfo);
        }
        return switchModule;
    }
    ;

    /**
     * Function to be executed when a new switch module was successfully created.
     * @param switchModule The newly created switchModule
     * @param swinfo Info about the created switch.
     */
    void onCreateSwitch(cModule* switchModule, openflow::Switch_Info* swinfo) {
        switchModule->par("switchName").setStringValue(swinfo->getMacAddress());
        cachedSwitches[swinfo->getMacAddress()] = switchModule;
    }
    ;

    /**
     * Get the port module of a switch.
     *
     * @param swinfo The info of the switch to look for.
     * @param port The port id to look for.
     * @return The switch port module, nullptr if not found.
     */
    PortModule* getSwitchPort(openflow::Switch_Info* swinfo, int port) {
        std::pair<std::string, int> switchPortPair(swinfo->getMacAddress(),
                port);
        if (cachedSwitchPorts.find(switchPortPair) != cachedSwitchPorts.end()) {
            return cachedSwitchPorts[switchPortPair];
        }
        return findSwitchPort(swinfo, port);
    }
    ;

    /**
     * Checks whether a portmodule for the given switch port is already present
     * if not the module will be dynamically created.
     *
     * @param swinfo The info of the switch to look for.
     * @param port The port id to look for.
     * @return the compound module that was created/found.
     */
    PortModule* getOrCreateSwitchPort(openflow::Switch_Info* swinfo, int port) {
        PortModule* portModule = getSwitchPort(swinfo, port);
        if (!portModule) {
            cModule* switchModule = getOrCreateSwitch(swinfo);
            portModule =
                    dynamic_cast<PortModule*>(createFinalizeAndScheduleDynamicModule(
                            "sdn4core.controllerState.base.PortModule",
                            "portModules", switchModule, true));
            if (!portModule) {
                throw cRuntimeError(
                        "Could not create port module %s for switch %s ",
                        std::to_string(port).c_str(),
                        swinfo->getMacAddress().c_str());
            }
            onCreateSwitchPort(portModule, swinfo, port);
        }
        return portModule;
    }
    ;

    /**
     * Function to be executed when a new port module was successfully created.
     * @param portModule The newly created portModule
     * @param swinfo Info about the created switch.
     * @param port The created port id.
     */
    virtual void onCreateSwitchPort(PortModule* portModule,
            openflow::Switch_Info* swinfo, int port) {
        portModule->setPort(port);
        cachedSwitchPorts[std::pair<std::string, int>(swinfo->getMacAddress(),
                port)] = portModule;
    }
    ;

    /**
     * Get the managed state module for the switch.
     *
     * @param swinfo The info of the switch to look for.
     * @return the managed state module, nullptr if not found.
     */
    ManagedType* getManagedState(openflow::Switch_Info* swinfo) {
        if (cachedManagedStates.find(swinfo->getMacAddress())
                != cachedManagedStates.end()) {
            return cachedManagedStates[swinfo->getMacAddress()];
        }
        return findManagedPerSwitchState(swinfo);
    }
    ;

    /**
     * Checks whether the state module already exists for a
     * given switch if not the module will be dynamically created.
     *
     * @param swinfo The info of the switch to look for.
     * @return the managed state module that was created/found.
     */
    ManagedType* getOrCreateManagedState(openflow::Switch_Info* swinfo) {
        ManagedType* managedState = getManagedState(swinfo);
        if (!managedState) {
            managedState = dynamic_cast<ManagedType*>(getOrCreatePerSwitchState(
                    swinfo, par("switchStateModulePath").stringValue(),
                    par("switchStateModuleName").stringValue()));
            if (!managedState) {
                throw cRuntimeError(
                        "Could not create managed switch state module for switch %s ",
                        swinfo->getMacAddress().c_str());
            }
            onCreateManagedState(managedState, swinfo);
        }
        return managedState;
    }
    ;

    /**
     * Function to be executed when a new managed state module was successfully created.
     * @param managedState The newly created managed state
     * @param swinfo Info about the created switch.
     */
    virtual void onCreateManagedState(ManagedType* managedState,
            openflow::Switch_Info* swinfo) {
        cachedManagedStates[swinfo->getMacAddress()] = managedState;
    }
    ;

    /**
     * Get a specific state module for the switch.
     *
     * @param swinfo The info of the switch to look for.
     * @param stateName The name of the switch state to look for.
     * @return the state module, nullptr if not found
     */
    cModule* getPerSwitchState(openflow::Switch_Info* swinfo,
            const char* stateName) {
        return findPerSwitchState(swinfo, stateName);
    }
    ;

    /**
     * Checks whether the managed state module already exists for a
     * given switch if not the module will be dynamically created.
     *
     * @param swinfo The info of the switch to look for.
     * @param stateModulePath ned module path to create a new module.
     * @param stateName The name of the switch state to look for.
     * @return the state module that was found/created.
     */
    cModule* getOrCreatePerSwitchState(openflow::Switch_Info* swinfo,
            const char* stateModulePath, const char* stateName) {
        cModule* state = findPerSwitchState(swinfo, stateName);
        if (!state) {
            if (cModule* switchModule = getOrCreateSwitch(swinfo)) {
                if (!(state = createFinalizeAndScheduleDynamicModule(
                        stateModulePath, stateName, switchModule, true))) {
                    throw cRuntimeError(
                            "Could not create state module %s for switch %s ",
                            stateName, swinfo->getMacAddress().c_str());
                }
                onCreatePerSwitchState(state, swinfo);
            }
        }
        return state;
    }
    ;

    /**
     * Function to be executed when a new managed state module was successfully created.
     * @param portModule The newly created portModule
     * @param swinfo Info about the created switch.
     */
    virtual void onCreatePerSwitchState(cModule* state,
            openflow::Switch_Info* swinfo) {
    }
    ;

private:
    /**
     * Finds switch state compound module containing all switch state modules in
     * the ned module hierarchy.
     *
     * @param swinfo The info of the switch to look for.
     * @return the switch state compound module if found, else nullptr.
     */
    cModule* findSwitchState(openflow::Switch_Info* swinfo) {
        cModule* found = nullptr;
        int numSwitches = getDynamicModuleVectorSize("switchState", this->getParentModule());
        for (int i = 0; i < numSwitches; i++) {
            cModule* currentModule = this->getParentModule()->getSubmodule(
                    "switchState", i);
            if (currentModule->par("switchName").stdstringValue()
                    == swinfo->getMacAddress()) {
                found = currentModule;
                cachedSwitches[swinfo->getMacAddress()] = currentModule;
                break;
                std::cout << "result equal" << std::endl;
            }
        }
        return found;
    }
    ;

    /**
     * Finds the port module for the given switch in the ned module hierarchy.
     *
     * @param swinfo The info of the switch to look for.
     * @return the switch port module if found, else nullptr.
     */
    PortModule* findSwitchPort(openflow::Switch_Info* swinfo, int port) {
        PortModule* found = nullptr;
        if (cModule* switchState = getSwitch(swinfo)) {
            if (auto portVec = switchState->getSubmodule("portModules", 0)) {
                for (int i = 0; i < portVec->getVectorSize(); i++) {
                    if ((found =
                            dynamic_cast<PortModule*>(switchState->getSubmodule(
                                    "portModules", i)))) {
                        if (found->getPort() == port) {
                            cachedSwitchPorts[std::pair<std::string, int>(
                                    swinfo->getMacAddress(), port)] = found;
                            break;
                        } else {
                            found = nullptr;
                        }
                    }
                }
            }
        }
        return found;
    }
    ;

    /**
     * Finds the managed switch state for the given switch in the ned module
     * hierarchy.
     *
     * @param swinfo The info of the switch to look for.
     * @return the managed state module if found, else nullptr.
     */
    ManagedType* findManagedPerSwitchState(openflow::Switch_Info* swinfo) {
        ManagedType* managedState =
                dynamic_cast<ManagedType*>(findPerSwitchState(swinfo,
                        par("switchStateModulePath").stringValue()));
        if (managedState) {
            cachedManagedStates[swinfo->getMacAddress()] = managedState;
        }
        return managedState;
    }
    ;

    /**
     * Finds a certain switch state for the given switch in the ned module
     * hierarchy.
     *
     * @param swinfo The info of the switch to look for.
     * @paran stateName The name of the switch state to look for.
     * @return the state module if found, else nullptr.
     */
    cModule* findPerSwitchState(openflow::Switch_Info* swinfo,
            const char* stateName, int index = -1) {
        if (cModule* switchState = getSwitch(swinfo)) {
            return switchState->getSubmodule(stateName, index);
        }
        return nullptr;
    }
    ;

protected:
    /**
     * Known switch state compound modules that are cached on creation
     * and dynamic lookups.
     *
     * map key is the switches MAC Address as a string from the swinfo.
     * map value is the cached cModule reference of the switch state compound
     * module.
     *
     * @note A switch module might exist that is unknown to this instance
     * of ControllerStateManagementBase! In some edge, cases modules that are
     * cached might not be valid anymore.
     */
    std::map<std::string, cModule*> cachedSwitches;

    /**
     * Known switch port modules that are cached on creation and dynamic lookups.
     *
     * map key is the pair of a switches MAC Address as a string from the swinfo
     * and the port index.
     * map value is the cached cModule reference of the switch PortModule.
     *
     * @note A switch module might exist that is unknown to this instance
     * of ControllerStateManagementBase! In some edge cases, modules that are
     * cached might not be valid anymore.
     */
    std::map<std::pair<std::string, int>, PortModule*> cachedSwitchPorts;

    /**
     * Known managed switch state modules that are cached on creation and
     * dynamic lookups.
     *
     * map key is the switches MAC Address as a string from the swinfo.
     * map value is the cached cModule reference of the switch state compound
     * module.
     *
     * @note A switch module might exist that is unknown to this instance
     * of ControllerStateManagementBase! In some edge cases, modules that are
     * cached might not be valid anymore.
     */
    std::map<std::string, ManagedType*> cachedManagedStates;

};

} // End namespace SDN4CoRE

#endif
