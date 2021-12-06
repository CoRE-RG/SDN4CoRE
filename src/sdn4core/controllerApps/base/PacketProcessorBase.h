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

#ifndef __SDN4CORE_PACKETPROCESSORBASE_H_
#define __SDN4CORE_PACKETPROCESSORBASE_H_

#include <omnetpp.h>
//STD
#include <map>
#include <string>
#include <vector>
//openflow
#include <openflow/openflow/protocol/OpenFlow.h>
#include "openflow/openflow/controller/Switch_Info.h"
#include "openflow/controllerApps/AbstractControllerApp.h"

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Base application for a packet processor.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class PacketProcessorBase: public openflow::AbstractControllerApp {
public:

    /**
     * Packet Filter is a map of a string key and a string value list.
     */
    class PacketFilter : public std::map<std::string, std::vector<std::string>> {
    public:
        /**
         * Initializes the PacketFilter map from a parameter string value.
         *
         * Syntax: "<key1>=<value11>,<value12>; ...; <keyK>=<valueK1>,...,<valueKV>"
         * A list of filters separated by semicolon ";". Each filter contains
         * exactly one key followed by "=" and a list of values separated with a comma ",".
         * accepted values keys are:
         *      key: "ethSrc" values: MAC address, e.g., AA-AA-AA-AA-AA-AA
         *      key: "ethDst" values: MAC address, e.g., AA-AA-AA-AA-AA-AA
         *      key: "etherType" values: etherType number, e.g., 0x0800 or 2048
         *      key: "vlanId" values: VLAN identifier, e.g., 42
         *      key: "vlanPcp" values: VLAN priority code points (0-7), e.g., 3
         *      key: "ipSrc" values: IP address with optional netmask, e.g., 192.168.178.42 or 192.168.178.1/24
         *      key: "ipDst" values: IP address with optional netmask, e.g., 192.168.178.42 or 192.168.178.1/24
         *      key: "ipProto" values: IP protocol, e.g. 0x11 or 17
         *      key: "udpSrc" values: UDP port, e.g., 1234
         *      key: "udpDst" values: UDP port, e.g., 1234
         *      key: "tcpSrc" values: TCP port, e.g., 1234
         *      key: "tcpDst" values: TCP port, e.g., 1234
         *
         * @param parameterValue The string from cPar::stdStringValue() to be parsed
         */
        void initializeFromPar(const std::string& parameterValue);

        bool matchesIntValue(std::string key, int value);
        bool matchesStringValue(std::string key, std::string value);
        bool matchesMACAddressValue(std::string key, inet::MACAddress value);
        bool matchesL3AddressValue(std::string key, inet::L3Address value);

        bool matchesPacketIn(openflow::OFP_Packet_In *packet_in_msg);
    };

    int getHardTimeout() const {
        return _hardTimeout;
    }

    int getIdleTimeout() const {
        return _idleTimeout;
    }

protected:
    void setHardTimeout(int hardTimeout) {
        this->_hardTimeout = hardTimeout;
    }

    void setIdleTimeout(int idleTimeout) {
        this->_idleTimeout = idleTimeout;
    }

    /**
     * Trys to locate the managerModule in the controllerState module.
     *
     * @param managerModule the name of the module to locate
     * @return the module of type T if found, else nullptr
     */
    template<typename T>
    T tryLocateStateManager(std::string managerModule) {
        cModule* controllerState = this->getParentModule()->getSubmodule(
                "controllerState");
        if(controllerState) {
            return dynamic_cast<T>(controllerState->getSubmodule(managerModule.c_str()));
        }
        return nullptr;
    }

    virtual void initialize() override;
    virtual void handleParameterChange(const char* parname) override;
    void receiveSignal(cComponent *src, simsignal_t id, cObject *obj,
            cObject *details) override;
    virtual void finish() override;

    /**
     * Checks whether the packetIn is filtered.
     * This is the case, if the packet either does not match any of the entries in a
     * non empty whitelist or it does match one entry in a non empty blacklist.
     * @param packet_in_msg the packet information to check for filtering
     * @return True if the packet is filtered, false indicates that it should be processed.
     */
    virtual bool isFiltered(openflow::OFP_Packet_In *packet_in_msg);

// --------------------- INTERFACE FUNCTIONS ----------------------//
    /**
     * Interface function for the main processing engine of packet_in messages.
     *
     * This default implementation does nothing
     *
     * @param packet_in_msg The packet in message
     */
    virtual void processPacketIn(openflow::OFP_Packet_In *packet_in_msg) {  }

    /**
     * Interface function for processing new switch connections.
     *
     * This default implementation calls loadOfflineConfigFromXML() for
     * the switch.
     *
     * @param info the new switch connected
     */
    virtual void processSwitchConnection(openflow::Switch_Info* info) {
        Enter_Method("processSwitchConnection()");
        loadOfflineConfigFromXML(info);
    }

    /**
     * Interface function to load an offline configuration for a newly connected switch.
     *
     * This default implementation does nothing and returns false.
     *
     * @param info  The switch to load the offline config for.
     * @return True if a config was loaded
     */
    virtual bool loadOfflineConfigFromXML(openflow::Switch_Info* info) {
        return false;
    }

    /**
     * Interface function to exports the current state as an XML formatted string.
     *
     * This default implementation returns an empty string.
     *
     * @return The current state as an XML formatted string
     */
    virtual std::string stateToXML() {
        return "";
    }

protected:
    /**
     * The cached flow rule IdleTimeOut parameter.
     */
    int _idleTimeout;
    /**
     * The cached flow rule HardTimeOut parameter.
     */
    int _hardTimeout;
    /**
     * A map with whitelisted packet filters cached from parameter.
     */
    PacketFilter _whitelist;
    /**
     * A map with blacklisted packet filters cached from parameter.
     */
    PacketFilter _blacklist;
};

} /*end namespace SDN4CoRE*/

#endif /* __SDN4CORE_PACKETPROCESSORBASE_H_ */
