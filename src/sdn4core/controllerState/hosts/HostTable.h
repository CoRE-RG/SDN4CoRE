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
#include <vector>
// INET
#include "inet/linklayer/common/MACAddress.h"
#include "inet/networklayer/contract/ipv4/IPv4Address.h"
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
    /**
     * Representation of a HostTable entry.
     * Contains the known MAC and IP Addresses, VLAN IDs, switch and port.
     */
    struct HostEntry {
        std::string nodeName = "UNKNOWN";
        inet::MACAddress macAddress; // VLAN ID
        std::vector<unsigned int> vlanIds = {0};
        std::vector<inet::L3Address> ipAddresses;
        openflow::Switch_Info* switchInfo = nullptr;
        int portno = -1; // Input port
        bool learned = true; // true if learned during runtime, false if preconfigured
        const simtime_t insertionTime; // time when entry was created
        simtime_t lastUpdated; // for aging of unused entries

        HostEntry() : insertionTime(simTime()), lastUpdated(simTime()) {}
    };

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

  protected:
    std::vector<HostEntry>


};

} /*end namespace SDN4CoRE*/

#endif
