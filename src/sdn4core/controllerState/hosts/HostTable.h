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

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Host Table that can learn and lookup network hosts for an SDN controller application.
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
        std::string nodeName = "UNKNOWN";
        inet::MACAddress macAddress;
        std::string switch_id = "";
        int portno = -1; // Input port
        std::vector<unsigned int> vids = {0}; // VLAN ID
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
     * Look up a host by by the given MAC address.
     * @param address The address to look up
     * @return A host entry matching the MAC address if found, else nullptr
     */
    virtual HostEntry* getHostForMacAddress(inet::MACAddress& address);

    /**
     * Look up a host by the given IP address.
     * @param address The address to look up
     * @return A host entry matching the IP address if found, else nullptr
     */
    virtual HostEntry* getHostForIPAddress(inet::L3Address& address);

    /**
     * Look up hosts connected to a switch.
     * @param switch_id The switch id to look up
     * @return A list of host entries connected to the host
     */
    virtual HostList getHostsForSwitch(std::string& switch_id);

    /**
     * TODO Specify interface for table insertion!
     */

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

protected:

    simtime_t agingTime;    // Max idle time for address table entries
    simtime_t lastPurge; // Time of the last call of removeAgedEntriesFromAllVlans()
    HostMapByIp hostsByIp;
    HostMapByMac hostsByMac;
    HostMapBySwitch hostsBySwitch;
};

} /*end namespace SDN4CoRE*/

#endif
