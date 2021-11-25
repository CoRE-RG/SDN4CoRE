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
#include <fstream>
#include <iostream>

#include <sdn4core/controllerState/base/PortModule.h>
#include <sdn4core/utility/dynamicmodules/DynamicModuleHandling.h>

using namespace omnetpp;

namespace SDN4CoRE {

#define MODULE_SPACING 70

/**
 * Workaround to count module creations for the template class.
 * Used to set display options.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class ControllerStateManagementWithID: public cSimpleModule {
public:
    ControllerStateManagementWithID() :
            managerID(nextID++) {
        WATCH(managerID);
    }

    const int getMangerID() {
        return managerID;
    }

private:
    static int nextID;
    const int managerID;
};

/**
 * SimpleModule to manage controller state @see~ControllerState
 *
 * TODO is it possible that cached switches etc. are removed at
 * runtime and thus the cache should be verified?
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
template<class ManagedType = cModule>
class ControllerStateManagementBase: public ControllerStateManagementWithID {
public:
    /**
     * Read a configuration from the XML and load it into the controller state.
     * @param configuration the XML configuration to read.
     * @return true if the controller state has changed.
     */
    virtual bool loadConfig(cXMLElement* configuration) {
        return false;
    }

    /**
     * Interface function to dump XML config to file if specified in the parameter "dumpConfig".
     * Calls dumpConfigToStream() to get the state as XML from the implementing class.
     */
    virtual void dumpConfig() {
        std::string filename = par("dumpConfig").stdstringValue();
        if(!filename.empty()) {
            std::ofstream file;
            file.open(filename.c_str(), std::ios::app);
            if (!file.is_open())
                throw cRuntimeError("Cannot open output file");
            dumpConfigToStream(file);
            file.close();
        }
    }

    /**
     * Dumps the managed state as formatted XML into the given output stream provided by the user.
     * @param stream the output stream to write to (can be, e.g., a filestream or stringstream)
     * @param indentTabs number of tabs to use for base indentation at beginning of each line.
     */
    virtual void dumpConfigToStream(std::ostream& stream, int indentTabs = 0) {
        std::string indent = std::string(indentTabs, '\t');
        stream << indent << "<!--not implemented for this manager-->" << std::endl;
    }

protected:

    virtual void initialize() override {
        loadConfig(par("config"));
    }
    ;

    virtual void finish() override {
        dumpConfig();
    }
    ;

    /**
     * Get the switch state compound module for the switch.
     *
     * @param swMacAddr The info of the switch to look for.
     * @return The switch state compound module, nullptr if not found.
     */
    cModule* getSwitch(std::string swMacAddr) {
        if (cachedSwitches.find(swMacAddr)
                != cachedSwitches.end()) {
            return cachedSwitches[swMacAddr];
        }
        return findSwitchState(swMacAddr);
    }

    /**
     * Checks whether a given switch is already present else create
     * the compound module.
     *
     * @param swMacAddr The info of the switch to look for.
     * @return the compound module that was created/found.
     */
    cModule* getOrCreateSwitch(std::string swMacAddr) {
        cModule* switchModule = getSwitch(swMacAddr);
        if (!switchModule) {
            switchModule = createFinalizeAndScheduleDynamicModule(
                    "sdn4core.controllerState.base.ControllerSwitchState",
                    "switchState", this->getParentModule(), true);
            if (!switchModule) {
                throw cRuntimeError(
                        "Could not create state module for switch %s ",
                        swMacAddr.c_str());
            }
            onCreateSwitch(switchModule, swMacAddr);
        }
        return switchModule;
    }

    /**
     * Function to be executed when a new switch module was successfully created.
     * @param switchModule The newly created switchModule
     * @param swMacAddr Info about the created switch.
     */
    void onCreateSwitch(cModule* switchModule, std::string swMacAddr) {
        switchModule->par("switchName").setStringValue(swMacAddr);
        setModuleDisplayName(switchModule, swMacAddr);
        cachedSwitches[swMacAddr] = switchModule;
    }

    /**
     * Get the port module of a switch.
     *
     * @param swMacAddr The info of the switch to look for.
     * @param port The port id to look for.
     * @return The switch port module, nullptr if not found.
     */
    PortModule* getSwitchPort(std::string swMacAddr, int port) {
        std::pair<std::string, int> switchPortPair(swMacAddr,
                port);
        if (cachedSwitchPorts.find(switchPortPair) != cachedSwitchPorts.end()) {
            return cachedSwitchPorts[switchPortPair];
        }
        return findSwitchPort(swMacAddr, port);
    }

    /**
     * Checks whether a portmodule for the given switch port is already present
     * if not the module will be dynamically created.
     *
     * @param swMacAddr The info of the switch to look for.
     * @param port The port id to look for.
     * @return the compound module that was created/found.
     */
    PortModule* getOrCreateSwitchPort(std::string swMacAddr, int port) {
        PortModule* portModule = getSwitchPort(swMacAddr, port);
        if (!portModule) {
            cModule* switchModule = getOrCreateSwitch(swMacAddr);
            portModule =
                    dynamic_cast<PortModule*>(createFinalizeAndScheduleDynamicModule(
                            "sdn4core.controllerState.base.PortModule",
                            "portModules", switchModule, true));
            if (!portModule) {
                throw cRuntimeError(
                        "Could not create port module %s for switch %s ",
                        std::to_string(port).c_str(),
                        swMacAddr.c_str());
            }
            onCreateSwitchPort(portModule, swMacAddr, port);
        }
        return portModule;
    }

    /**
     * Function to be executed when a new port module was successfully created.
     * @param portModule The newly created portModule
     * @param swMacAddr Info about the created switch.
     * @param port The created port id.
     */
    virtual void onCreateSwitchPort(PortModule* portModule,
            std::string swMacAddr, int port) {
        setModulePosition(portModule, MODULE_SPACING * (port + 1),
                MODULE_SPACING);
        setModuleDisplayName(portModule, "Port " + std::to_string(port));
        portModule->setPort(port);
        cachedSwitchPorts[std::pair<std::string, int>(swMacAddr,
                port)] = portModule;
    }

    /**
     * Get the managed state module for the switch.
     *
     * @param swMacAddr The info of the switch to look for.
     * @return the managed state module, nullptr if not found.
     */
    ManagedType* getManagedState(std::string swMacAddr) {
        if (cachedManagedStates.find(swMacAddr)
                != cachedManagedStates.end()) {
            return cachedManagedStates[swMacAddr];
        }
        return findManagedPerSwitchState(swMacAddr);
    }

    /**
     * Checks whether the state module already exists for a
     * given switch if not the module will be dynamically created.
     *
     * @param swMacAddr The info of the switch to look for.
     * @return the managed state module that was created/found.
     */
    ManagedType* getOrCreateManagedState(std::string swMacAddr) {
        ManagedType* managedState = getManagedState(swMacAddr);
        if (!managedState) {
            managedState = dynamic_cast<ManagedType*>(getOrCreatePerSwitchState(
                    swMacAddr, par("switchStateModulePath").stringValue(),
                    par("switchStateModuleName").stringValue()));
            if (!managedState) {
                throw cRuntimeError(
                        "Could not create managed switch state module for switch %s ",
                        swMacAddr.c_str());
            }
            onCreateManagedState(managedState, swMacAddr);
        }
        return managedState;
    }

    /**
     * Function to be executed when a new managed state module was successfully created.
     * @param managedState The newly created managed state
     * @param swMacAddr Info about the created switch.
     */
    virtual void onCreateManagedState(ManagedType* managedState,
            std::string& swMacAddr) {
        setModulePosition(managedState, MODULE_SPACING,
                MODULE_SPACING * (this->getMangerID() + 2));
        cachedManagedStates[swMacAddr] = managedState;
    }

    /**
     * Get a specific state module for the switch.
     *
     * @param swMacAddr The info of the switch to look for.
     * @param stateName The name of the switch state to look for.
     * @return the state module, nullptr if not found
     */
    cModule* getPerSwitchState(std::string& swMacAddr,
            const char* stateName) {
        return findPerSwitchState(swMacAddr, stateName);
    }

    /**
     * Checks whether the managed state module already exists for a
     * given switch if not the module will be dynamically created.
     *
     * @param swMacAddr The info of the switch to look for.
     * @param stateModulePath ned module path to create a new module.
     * @param stateName The name of the switch state to look for.
     * @return the state module that was found/created.
     */
    cModule* getOrCreatePerSwitchState(std::string& swMacAddr,
            const char* stateModulePath, const char* stateName) {
        cModule* state = findPerSwitchState(swMacAddr, stateName);
        if (!state) {
            if (cModule* switchModule = getOrCreateSwitch(swMacAddr)) {
                if (!(state = createFinalizeAndScheduleDynamicModule(
                        stateModulePath, stateName, switchModule, true))) {
                    throw cRuntimeError(
                            "Could not create state module %s for switch %s ",
                            stateName, swMacAddr.c_str());
                }
                onCreatePerSwitchState(state, swMacAddr);
            }
        }
        return state;
    }

    /**
     * Function to be executed when a new managed state module was successfully created.
     * @param portModule The newly created portModule
     * @param swMacAddr Info about the created switch.
     */
    virtual void onCreatePerSwitchState(cModule* state,
            std::string& swMacAddr) {
    }

private:
    /**
     * Finds switch state compound module containing all switch state modules in
     * the ned module hierarchy.
     *
     * @param swMacAddr The info of the switch to look for.
     * @return the switch state compound module if found, else nullptr.
     */
    cModule* findSwitchState(std::string& swMacAddr) {
        cModule* found = nullptr;
        int numSwitches = getDynamicModuleVectorSize("switchState",
                this->getParentModule());
        for (int i = 0; i < numSwitches; i++) {
            cModule* currentModule = this->getParentModule()->getSubmodule(
                    "switchState", i);
            if (currentModule->par("switchName").stdstringValue()
                    == swMacAddr) {
                found = currentModule;
                cachedSwitches[swMacAddr] = currentModule;
                break;
                std::cout << "result equal" << std::endl;
            }
        }
        return found;
    }

    /**
     * Finds the port module for the given switch in the ned module hierarchy.
     *
     * @param swMacAddr The info of the switch to look for.
     * @return the switch port module if found, else nullptr.
     */
    PortModule* findSwitchPort(std::string& swMacAddr, int port) {
        PortModule* found = nullptr;
        if (cModule* switchState = getSwitch(swMacAddr)) {
            if (auto portVec = switchState->getSubmodule("portModules", 0)) {
                for (int i = 0; i < portVec->getVectorSize(); i++) {
                    if ((found =
                            dynamic_cast<PortModule*>(switchState->getSubmodule(
                                    "portModules", i)))) {
                        if (found->getPort() == port) {
                            cachedSwitchPorts[std::pair<std::string, int>(
                                    swMacAddr, port)] = found;
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

    /**
     * Finds the managed switch state for the given switch in the ned module
     * hierarchy.
     *
     * @param swMacAddr The info of the switch to look for.
     * @return the managed state module if found, else nullptr.
     */
    ManagedType* findManagedPerSwitchState(std::string& swMacAddr) {
        ManagedType* managedState =
                dynamic_cast<ManagedType*>(findPerSwitchState(swMacAddr,
                        par("switchStateModulePath").stringValue()));
        if (managedState) {
            cachedManagedStates[swMacAddr] = managedState;
        }
        return managedState;
    }

    /**
     * Finds a certain switch state for the given switch in the ned module
     * hierarchy.
     *
     * @param swMacAddr The info of the switch to look for.
     * @paran stateName The name of the switch state to look for.
     * @return the state module if found, else nullptr.
     */
    cModule* findPerSwitchState(std::string& swMacAddr,
            const char* stateName, int index = -1) {
        if (cModule* switchState = getSwitch(swMacAddr)) {
            return switchState->getSubmodule(stateName, index);
        }
        return nullptr;
    }

    void setModuleDisplayName(cModule* module, std::string name) {
        std::string newDisplayString = "t=" + name;
        module->getDisplayString().updateWith(newDisplayString.c_str());
    }

    void setModulePosition(cModule* module, int x, int y) {
        std::string newDisplayString = "p=" + std::to_string(x) + ","
                + std::to_string(y);
        module->getDisplayString().updateWith(newDisplayString.c_str());
    }

protected:
    /**
     * Known switch state compound modules that are cached on creation
     * and dynamic lookups.
     *
     * map key is the switches MAC Address as a string from the swMacAddr.
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
     * map key is the pair of a switches MAC Address as a string from the swMacAddr
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
     * map key is the switches MAC Address as a string from the swMacAddr.
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
