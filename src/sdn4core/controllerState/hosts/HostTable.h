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

#ifndef __SDN4CORE_HOSTTABLE_H_
#define __SDN4CORE_HOSTTABLE_H_

#include <omnetpp.h>
#include <sdn4core/controllerState/base/ControllerStateManagementBase.h>
// STD
#include <list>
#include <map>
// INET
#include "inet/linklayer/common/MACAddress.h"
#include "inet/networklayer/common/L3Address.h"
// openflow
#include "openflow/messages/OFP_Packet_In_m.h"
#include "openflow/openflow/controller/Switch_Info.h"

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Host Table that can learn and lookup network hosts for an SDN controller application.
 * The table assumes the first detection point of the host mac as the entry point into the network.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class HostTable: public ControllerStateManagementBase<cModule> {
public:
    /**
     * Representation of a HostTable entry.
     * Contains the known MAC and IP Addresses, VLAN IDs, switch and port.
     */
    struct HostEntry {
        std::string nodeName = "UNKNOWN"; //TODO add node name for visualization
        inet::MACAddress macAddress;
        std::string switch_id = "";
        int portno = -1; // Input port
        std::vector<unsigned int> vids; // VLAN ID
        std::vector<inet::L3Address> ipAddresses;
        bool learned = true; // true if learned during runtime, false if preconfigured
        const simtime_t insertionTime; // time when entry was created
        simtime_t lastUpdated; // for aging of unused entries

        HostEntry() :
                insertionTime(simTime()), lastUpdated(simTime()) {
        }
    };
    friend std::ostream& operator<<(std::ostream& os, const HostEntry& entry);
    struct MAC_compare {
        bool operator()(const inet::MACAddress& u1, const inet::MACAddress& u2) const {
            return u1.compareTo(u2) < 0;
        }
    };
    typedef std::list<HostEntry*> HostList;
    typedef std::map<inet::MACAddress, HostEntry*, MAC_compare> HostMapByMac;
    typedef std::map<inet::L3Address, HostEntry*> HostMapByIp;
    typedef std::map<std::string, HostList> HostMapBySwitch;

public:
    HostTable();
    ~HostTable();

    virtual bool loadConfig(cXMLElement* configuration) override;

    virtual bool loadConfigForSwitch(const std::string& swMacAddr,
            cXMLElement* configuration) override;

    virtual void dumpConfigToStream(std::ostream& stream, int indentTabs = 0)
            override;

    /**
     * Update HostTable using the source info inside the packet in message.
     * @param packetIn The packet in information to learn.
     * @param swInfo The source switch of the packet in.
     * @return True if refreshed, false if a new entry was created.
     */
    virtual bool update(openflow::OFP_Packet_In* packetIn, openflow::Switch_Info * swInfo);

    /**
     * Update HostTable using minimal source info as in MACAddressTables.
     * @param sw_info the switch to update
     * @param source the source to update
     * @param in_port the in port to update
     * @param vlan_id the vlan id to update
     * @return True if refreshed, false if a new entry was created.
     */
    virtual bool update(openflow::Switch_Info* swInfo, inet::MACAddress source,
            uint32_t in_port, int vlan_id = 0);

    /**
     * Look up a host by by the given MAC address.
     * @param address The address to look up
     * @param doAging Check if the found entry is outdated
     * @return A host entry matching the MAC address if found, else nullptr
     */
    virtual HostEntry* getHostForMacAddress(const inet::MACAddress& address, bool doAging=true);

    /**
     * Look up a host by the given IP address.
     * @param address The address to look up
     * @param doAging Check if the found entry is outdated
     * @return A host entry matching the IP address if found, else nullptr
     */
    virtual HostEntry* getHostForIpAddress(const inet::L3Address& address, bool doAging=true);

    /**
     * Look up hosts connected to a switch.
     * @param switch_id The switch id to look up
     * @param doAging Check if the found entry is outdated
     * @return A list of host entries connected to the host
     */
    virtual HostList getHostsForSwitch(const std::string& switch_id, bool doAging=true);

    /**
     * Get the number of known hosts.
     * @note Is const because used in refreshDisplay() const
     * @return The number of hosts.
     */
    virtual int getHostCount() const;

    /**
     * @brief Remove aged entries
     */
    virtual void removeAgedEntries();

    /*
     * It calls removeAgedEntries() if and only if at least
     * 1 second has passed since the method was last called.
     */
    virtual void removeAgedEntriesIfNeeded();

    /**
     * For lifecycle: clears all entries from the vlanAddressTable.
     */
    virtual void clearTable();

    /**
     * Set the agingTime of host entries.
     * @param agingTime the aging time to set.
     */
    virtual void setAgingTime(simtime_t agingTime);

    /**
     * Reset the agingTime to the one specified in the module parameter.
     */
    virtual void resetDefaultAging();

protected:

    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

    /**
     * Updates the displaystring for links and switches
     */
    virtual void refreshDisplay() const override;

    /**
     * Add a host to the table updating an old entry or inserting the given pointer.
     * @note The pointer now belongs and its lifecycle will be managed by the table.
     * @param entry The entry to be added
     * @return True if an existing entry was refreshed, false if pointer was added
     */
    virtual bool addHost(HostEntry* entry);

    /**
     * Remove a host from the table.
     * @note The pointer will be invalidated!
     * @param entry The entry to be removed
     * @return True if removed, false if not found
     */
    virtual bool removeHost(HostEntry* entry);

    /**
     * Check if a host is aged based on the agingTime.
     * @param entry The host entry
     * @return True if the entry was last updated before aging time, else false
     *         False will also be returned for static hosts (learned=false)
     */
    virtual bool isAgedHost(HostEntry* entry);

protected:

    simtime_t agingTime;    // Max idle time for address table entries
    simtime_t lastPurge; // Time of the last call of removeAgedEntriesFromAllVlans()
    HostMapByIp hostsByIp;
    HostMapByMac hostsByMac;
    HostMapBySwitch hostsBySwitch;
};

} /*end namespace SDN4CoRE*/

#endif
