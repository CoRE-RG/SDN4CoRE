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
// STD
#include <list>
#include <map>
// INET
#include "inet/linklayer/common/MACAddress.h"
#include "inet/networklayer/common/L3Address.h"
//openflow
#include "openflow/openflow/controller/Switch_Info.h"

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Host Table that can learn and lookup network hosts for an SDN controller application.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class HostTable : public cSimpleModule
{
public:
    /**
     * Representation of a HostTable entry.
     * Contains the known MAC and IP Addresses, VLAN IDs, switch and port.
     */
    struct HostEntry {
        std::string nodeName = "UNKNOWN";
        inet::MACAddress macAddress; // VLAN ID
        unsigned int vid = 0;
        std::vector<inet::L3Address> ipAddresses;
        openflow::Switch_Info* switchInfo = nullptr;
        int portno = -1; // Input port
        bool learned = true; // true if learned during runtime, false if preconfigured
        const simtime_t insertionTime; // time when entry was created
        simtime_t lastUpdated; // for aging of unused entries

        HostEntry() : insertionTime(simTime()), lastUpdated(simTime()) {}
    };
    friend std::ostream& operator<<(std::ostream& os, const HostEntry& entry);
    struct MAC_compare
    {
        bool operator()(const MACAddress& u1, const MACAddress& u2) const { return u1.compareTo(u2) < 0; }
    };
    typedef std::list<HostEntry> HostList;
    typedef std::map<inet::MACAddress, HostEntry, MAC_compare> HostMap;
    typedef std::map<unsigned int, HostMap *> HostVLANMap;

public:
    HostTable();
    ~HostTable();

    /**
     * TODO implement lookup for IPs
     * @param address
     * @return
     */
    virtual HostList getHostsForMacAddress(inet::MACAddress& address);

    /**
     * TODO implement lookup for IPs
     * @param address
     * @return
     */
    virtual HostEntry* getHostForMacAddressAndVlan(inet::MACAddress& address, unsigned int vid);

    /**
     * TODO implement lookup for IPs
     * @param address
     * @return
     */
    virtual int getPortForHostMacAddress(inet::MACAddress& address, unsigned int vid = 0);

    /**
     * TODO Specify interface for table insertion!
     */

    /**
     * @brief Remove aged entries from a specified VLAN
     */
    virtual void removeAgedEntriesFromVlan(unsigned int vid = 0);
    /**
     * @brief Remove aged entries from all VLANs
     */
    virtual void removeAgedEntriesFromAllVlans();

    /*
     * It calls removeAgedEntriesFromAllVlans() if and only if at least
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
     * @brief Returns a Host Table for a specified VLAN ID
     */
    HostMap *getTableForVid(unsigned int vid);

    void removeAgedEntriesFromHostMap (HostMap* table);

protected:

    simtime_t agingTime;    // Max idle time for address table entries
    simtime_t lastPurge;    // Time of the last call of removeAgedEntriesFromAllVlans()
    HostVLANMap hosts;


};

} /*end namespace SDN4CoRE*/

#endif
