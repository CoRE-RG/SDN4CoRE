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

#include "inet/common/InitStages.h"

#include <sdn4core/controllerState/base/PortModule.h>
#include <sdn4core/utility/dynamicmodules/DynamicModuleHandling.h>

using namespace omnetpp;

namespace SDN4CoRE {

#define MODULE_SPACING 70


/**
 * Structure representing a switch port for the controller state and topology.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
struct SwitchPort {
    std::string switchId;
    int port;

    SwitchPort() : switchId(""), port(-1) {}
    SwitchPort(std::string switchId, int port) : switchId(switchId), port(port) {}
    bool empty() { return switchId.empty(); }

    bool operator<(const SwitchPort& other) const {
        if(this->switchId == other.switchId) {
            return this->port < other.port;
        }
        return this->switchId < other.switchId;
    }
    bool operator>(const SwitchPort& other) const {
        return other < *this;
    }
    bool operator==(const SwitchPort& other) const {
        return this->switchId == other.switchId && this->port == other.port;
    }
    bool operator!=(const SwitchPort& other) const {
        return !operator==(other);
    }
    friend std::ostream & operator << (std::ostream &out, const SwitchPort &switchPort) {
        out << "{switchId=\"" << switchPort.switchId << "\", port=\"" << switchPort.port << "\"}";
        return out;
    }
};

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
     * Read a configuration for one specific switch from the XML and load it
     * into the controller state.
     * @param configuration the XML configuration to read.
     * @return true if the controller state has changed.
     */
    virtual bool loadConfigForSwitch(const std::string& swMacAddr,
            cXMLElement* configuration) {
        return false;
    }

    /**
     * Interface function to dump XML config to file if specified in the parameter "dumpConfig".
     * Calls dumpConfigToStream() to get the state as XML from the implementing class.
     */
    virtual void dumpConfig() {
        std::string filename = par("dumpConfig").stdstringValue();
        if (!filename.empty()) {
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
        stream << indent << "<!--not implemented for this manager-->"
                << std::endl;
    }

protected:
    //used as a workaround for dynamically created modules during initialization from config
    virtual int numInitStages() const override {
        return inet::NUM_INIT_STAGES;
    }

    virtual void initialize() override {}

    virtual void initialize(int stage) override {
        if (stage == 0) {
            initialize();
        } else if (stage == inet::INITSTAGE_LAST) {
            loadConfig(par("config"));
        }
    }

    virtual void finish() override {
        dumpConfig();
    }

    /**
     * Get the switch state compound module for the switch.
     *
     * @param swMacAddr The info of the switch to look for.
     * @return The switch state compound module, nullptr if not found.
     */
    cModule* getSwitch(std::string swMacAddr) {
        if (cachedSwitches.find(swMacAddr) != cachedSwitches.end()) {
            return cachedSwitches[swMacAddr];
        }
        return findSwitchState(swMacAddr);
    }

    /**
     * Locates all known switches and returns them.
     *
     * @return a map of all switches with there switch mac address as the key.
     */
    const std::map<std::string, cModule*>& getAllSwitches() {
        refreshCachedSwitches();
        return cachedSwitches;
    }

    /**
     * Create a switch the compound module.
     *
     * @note This will throw an error if the module already exists.
     * Maybe use getOrCreateSwitch() instead.
     *
     * @param swMacAddr The info of the switch to look for.
     * @return the compound module that was created/found.
     */
    cModule* createSwitch(std::string swMacAddr) {
        cModule* switchModule = createFinalizeAndScheduleDynamicModule(
                    "sdn4core.controllerState.base.ControllerSwitchState",
                    "switchState", this->getParentModule(), true);
        if (!switchModule) {
            throw cRuntimeError(
                    "Could not create state module for switch %s ",
                    swMacAddr.c_str());
        }
        onCreateSwitch(switchModule, swMacAddr);
        return switchModule;
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
            switchModule = createSwitch(swMacAddr);
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
    PortModule* getSwitchPort(std::string swMacAddr, int port, cModule* switchModule = nullptr) {
        SwitchPort switchPortPair(swMacAddr, port);
        if (cachedSwitchPorts.find(switchPortPair) != cachedSwitchPorts.end()) {
            return cachedSwitchPorts[switchPortPair];
        }
        return findSwitchPort(swMacAddr, port);
    }

    /**
     * Locates all switch port objects an returns them.
     *
     * @return a map of all switch ports with there switch mac address and port as the key.
     */
    const std::map<SwitchPort, PortModule*>& getAllSwitchPorts() {
        refreshCachedPorts();
        return cachedSwitchPorts;
    }

    /**
     * Create a port module inside a switch compound module.
     *
     * @note This will throw an error if the module already exists.
     * Maybe use getOrCreateSwitchPort() instead.
     *
     * @param swMacAddr The info of the switch to look for.
     * @param port The port id to look for.
     * @return the compound module that was created/found.
     */
    PortModule* createSwitchPort(std::string swMacAddr, int port, cModule* switchModule = nullptr) {
        if(!switchModule) {
            switchModule = getOrCreateSwitch(swMacAddr);
        }
        PortModule* portModule =
                dynamic_cast<PortModule*>(createFinalizeAndScheduleDynamicModule(
                        "sdn4core.controllerState.base.PortModule",
                        "portModules", switchModule, true));
        if (!portModule) {
            throw cRuntimeError(
                    "Could not create port module %s for switch %s ",
                    std::to_string(port).c_str(), swMacAddr.c_str());
        }
        onCreateSwitchPort(portModule, swMacAddr, port);
        return portModule;
    }

    /**
     * Checks whether a portmodule for the given switch port is already present
     * if not the module will be dynamically created.
     *
     * @param swMacAddr The info of the switch to look for.
     * @param port The port id to look for.
     * @return the compound module that was created/found.
     */
    PortModule* getOrCreateSwitchPort(std::string swMacAddr, int port, cModule* switchModule = nullptr) {
        PortModule* portModule = getSwitchPort(swMacAddr, port, switchModule);
        if (!portModule) {
            portModule = createSwitchPort(swMacAddr, port);
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
        cachedSwitchPorts[SwitchPort(swMacAddr, port)] = portModule;
    }

    /**
     * Get the managed state module for the switch.
     *
     * @param swMacAddr The info of the switch to look for.
     * @return the managed state module, nullptr if not found.
     */
    ManagedType* getManagedState(std::string swMacAddr) {
        if (cachedManagedStates.find(swMacAddr) != cachedManagedStates.end()) {
            return cachedManagedStates[swMacAddr];
        }
        return findManagedPerSwitchState(swMacAddr);
    }

    /**
     * Locates all managed state objects an returns them.
     *
     * @return a map of all managed objects with there switch mac address as the key.
     */
    const std::map<std::string, ManagedType*>& getAllManagedStates() {
        refreshCachedManagedStates();
        return cachedManagedStates;
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
                    par("switchStateModuleName").stringValue(), false));
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
    cModule* getPerSwitchState(std::string& swMacAddr, const char* stateName) {
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
            const char* stateModulePath, const char* stateName, bool isVector) {
        cModule* state = getPerSwitchState(swMacAddr, stateName);
        if (!state) {
            if (cModule* switchModule = getOrCreateSwitch(swMacAddr)) {
                if (!(state = createFinalizeAndScheduleDynamicModule(
                        stateModulePath, stateName, switchModule, isVector))) {
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
        refreshCachedSwitches();
        auto found = cachedSwitches.find(swMacAddr);
        if (found != cachedSwitches.end()) {
            return found->second;
        }
        return nullptr;
    }

    /**
     * Locates all switches and adds them to the cache.
     */
    void refreshCachedSwitches() {
        cachedSwitches.clear();
        int numSwitches = getDynamicModuleVectorSize("switchState",
                this->getParentModule());
        for (int i = 0; i < numSwitches; i++) {
            cModule* currentModule = this->getParentModule()->getSubmodule(
                    "switchState", i);
            std::string mac = currentModule->par("switchName").stdstringValue();
            cachedSwitches[mac] = currentModule;
        }
    }

    /**
     * Finds the port module for the given switch in the ned module hierarchy.
     *
     * @param swMacAddr The info of the switch to look for.
     * @return the switch port module if found, else nullptr.
     */
    PortModule* findSwitchPort(std::string& swMacAddr, int port) {
        refreshCachedPorts();
        auto found = cachedSwitchPorts.find(SwitchPort(swMacAddr, port));
        if (found != cachedSwitchPorts.end()) {
            return found->second;
        }
        return nullptr;
    }

    /**
     * Locates all switch ports and adds them to the cache.
     */
    void refreshCachedPorts() {
        refreshCachedSwitches();
        cachedSwitchPorts.clear();
        for (auto sw : cachedSwitches) {
            int numPorts = getDynamicModuleVectorSize("portModules", sw.second);
            for (int i = 0; i < numPorts; i++) {
                PortModule* currentPort =
                        dynamic_cast<PortModule*>(sw.second->getSubmodule(
                                "portModules", i));
                int port = currentPort->getPort();
                cachedSwitchPorts[SwitchPort(sw.first, port)] = currentPort;
            }
        }
    }

    /**
     * Finds the managed switch state for the given switch in the ned module
     * hierarchy.
     *
     * @param swMacAddr The info of the switch to look for.
     * @return the managed state module if found, else nullptr.
     */
    ManagedType* findManagedPerSwitchState(std::string& swMacAddr) {
        auto found = cachedManagedStates.find(swMacAddr);
        if (found != cachedManagedStates.end()) {
            return found->second;
        }
        return nullptr;
    }

    /**
     * Locates all managed modules for switches and adds them to the cache.
     */
    void refreshCachedManagedStates() {
        refreshCachedSwitches();
        cachedManagedStates.clear();
        for (auto sw : cachedSwitches) {
            ManagedType* managedState =
                    dynamic_cast<ManagedType*>(sw.second->getSubmodule(
                            par("switchStateModuleName").stringValue(), 0));
            if (managedState) {
                cachedManagedStates[sw.first] = managedState;
            }
        }
    }

    /**
     * Finds a certain switch state for the given switch in the ned module
     * hierarchy.
     *
     * @param swMacAddr The info of the switch to look for.
     * @paran stateName The name of the switch state to look for.
     * @return the state module if found, else nullptr.
     */
    cModule* findPerSwitchState(std::string& swMacAddr, const char* stateName,
            int index = -1) {
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
    std::map<SwitchPort, PortModule*> cachedSwitchPorts;

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
