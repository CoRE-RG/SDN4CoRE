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

#include "sdn4core/controllerState/hosts/HostTable.h"

#include "core4inet/utilities/customWatch.h"

#include <algorithm>

using namespace std;
using namespace inet;

namespace SDN4CoRE {

Define_Module(HostTable);

std::ostream& operator<<(std::ostream& os, const HostTable::HostEntry& entry) {
    os << "{";
    os << "nodeName=" << entry.nodeName;
    os << ", macAddress=" << entry.macAddress;
    os << ", vid={";
    bool first = true;
    for (auto & vid : entry.vids) {
        if (first) {
            first = false;
        } else {
            os << ", ";
        }
        os << vid;
    }
    os << "}";
    os << ", ipAddresses={";
    first = true;
    for (auto & address : entry.ipAddresses) {
        if (first) {
            first = false;
        } else {
            os << ", ";
        }
        os << address.str();
    }
    os << "}";
    os << ", switch_id=" << entry.switch_id; // todo add full swinfo as string?
    os << ", portno=" << entry.portno;
    os << ", learned=" << entry.learned;
    os << ", insertionTime=" << entry.insertionTime;
    os << ", lastUpdated=" << entry.lastUpdated;
    os << "}";
    return os;
}

HostTable::HostTable() {
}

HostTable::~HostTable() {
    clearTable();
}

HostTable::HostEntry* HostTable::getHostForMacAddress(inet::MACAddress& address) {
    Enter_Method ("HostTable::getHostsForMacAddress()");
    auto iter = hostsByMac.find(address);
    if (iter == hostsByMac.end()) {
        // not found
        return nullptr;
    }
    if (iter->second->lastUpdated + agingTime <= simTime()) {
        removeHost(iter->second);
        return nullptr;
    }
    return iter->second;
}

HostTable::HostEntry* HostTable::getHostForIPAddress(inet::L3Address& address) {
    Enter_Method ("HostTable::getHostsForIPAddress()");
    auto iter = hostsByIp.find(address);
    if (iter == hostsByIp.end()) {
        // not found
        return nullptr;
    }
    if (iter->second->lastUpdated + agingTime <= simTime()) {
        removeHost(iter->second);
        return nullptr;
    }
    return iter->second;
}

HostTable::HostList HostTable::getHostsForSwitch(std::string& switch_id) {
    Enter_Method ("HostTable::getHostsForSwitch()");
    auto iter = hostsBySwitch.find(switch_id);
    if (iter == hostsBySwitch.end()) {
        // not found
        return HostList();
    }
    for (auto innerIt = iter->second.begin(); innerIt != iter->second.end();) {
        auto curr = innerIt++;
        if ((*curr)->lastUpdated + agingTime <= simTime()) {
            removeHost(*curr);
        }
    }
    return iter->second;
}

void HostTable::removeAgedEntries() {
    for (auto iter = hosts.begin(); iter != hosts.end();) {
        auto curr = iter++;
        if ((*curr)->lastUpdated + agingTime <= simTime()) {
            removeHost(*curr);
        }
    }
}

void HostTable::removeAgedEntriesIfNeeded() {
    simtime_t now = simTime();
    if (now >= lastPurge + 1) {
        removeAgedEntries();
    }
    lastPurge = now;
}

void HostTable::clearTable() {
    for (auto iter = hosts.begin(); iter != hosts.end();) {
        auto curr = iter++;
        delete (*curr);
    }
    hosts.clear();
    hostsByIp.clear();
    hostsByMac.clear();
    hostsBySwitch.clear();
}

void HostTable::setAgingTime(simtime_t agingTime) {
    this->agingTime = agingTime;
}

void HostTable::resetDefaultAging() {
    agingTime = par("agingTime");
}

void HostTable::initialize() {
    agingTime = par("agingTime");
    lastPurge = SIMTIME_ZERO;
    WATCH_LIST(hosts);
}

void HostTable::handleMessage(cMessage* msg) {
    throw cRuntimeError("This module doesn't process messages");
}

void HostTable::removeHost(HostEntry* entry) {
    auto hostIt = find(hosts.begin(), hosts.end(), entry);
    if(hostIt != hosts.end())
        hosts.erase(hostIt);
    auto macIt = hostsByMac.find(entry->macAddress);
    if(macIt != hostsByMac.end())
        hostsByMac.erase(macIt);
    for(auto l3Addr : entry->ipAddresses) {
        auto ipIt = hostsByIp.find(l3Addr);
        if(ipIt != hostsByIp.end())
            hostsByIp.erase(ipIt);
    }
    auto switchIt = hostsBySwitch.find(entry->switch_id);
    if(switchIt != hostsBySwitch.end()) {
        auto switchHostIt = find(switchIt->second.begin(), switchIt->second.end(), entry);
        if(switchHostIt != switchIt->second.end())
            switchIt->second.erase(switchHostIt);
    }
    delete entry;
}

} /*end namespace SDN4CoRE*/

