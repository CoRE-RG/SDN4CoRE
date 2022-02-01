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

using namespace std;
using namespace inet;

namespace SDN4CoRE {

Define_Module(HostTable);

std::ostream& operator<<(std::ostream& os, const HostTable::HostEntry& entry) {
    os << "{";
    os << "nodeName=" << entry.nodeName;
    os << ", macAddress=" << entry.macAddress;
    os << ", vid=" << entry.vid;
    os << ", ipAddresses={";
    bool first = true;
    for (auto & address : entry.ipAddresses) {
        if (first) {
            first = false;
        } else {
            os << ", ";
        }
        os << address.str();
    }
    os << "}";
    os << ", switchInfo=" << entry.switchInfo->getMacAddress(); // todo add full swinfo as string?
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
    for (auto & elem : hosts)
        delete elem.second;
}

HostTable::HostList HostTable::getHostsForMacAddress(
        inet::MACAddress& address) {
    Enter_Method
    ("HostTable::getHostsForMacAddress()");
    HostList found;
    for (auto& table : hosts) {
        auto iter = table.second->find(address);
        if (iter != table.second->end()) {
            if (iter->second.lastUpdated + agingTime <= simTime()) {
                // don't use (and throw out) aged entries
                EV << "Ignoring and deleting aged entry: " << iter->first
                          << " --> port" << iter->second.portno << "\n";
                table.second->erase(iter);
            } else if (iter->first == address) {
                found.push_back(iter->second);
            }
        }
    }
    return found;
}

HostTable::HostEntry* HostTable::getHostForMacAddressAndVlan(
        inet::MACAddress& address, unsigned int vid) {
    Enter_Method
    ("HostTable::getHostsForMacAddressAndVlan()");
    HostMap *table = getTableForVid(vid);
    // VLAN ID vid does not exist
    if (table == nullptr) {
        return nullptr;
    }
    auto iter = table->find(address);
    if (iter == table->end()) {
        // not found
        return nullptr;
    }
    if (iter->second.lastUpdated + agingTime <= simTime()) {
        // don't use (and throw out) aged entries
        EV << "Ignoring and deleting aged entry: " << iter->second.macAddress << " --> port"
                  << iter->second.portno << "\n";
        table->erase(iter);
        return nullptr;
    }
    return &(iter->second);
}

int HostTable::getPortForHostMacAddress(inet::MACAddress& address,
        unsigned int vid) {
    Enter_Method
    ("HostTable::getPortForHostMacAddress()");
    HostMap *table = getTableForVid(vid);
    // VLAN ID vid does not exist
    if (table == nullptr) {
        return -1;
    }
    auto iter = table->find(address);
    if (iter == table->end()) {
        // not found
        return -1;
    }
    if (iter->second.lastUpdated + agingTime <= simTime()) {
        // don't use (and throw out) aged entries
        EV << "Ignoring and deleting aged entry: " << iter->first << " --> port"
                  << iter->second.portno << "\n";
        table->erase(iter);
        return -1;
    }
    return iter->second.portno;
}

void HostTable::removeAgedEntriesFromVlan(unsigned int vid) {
    HostMap *table = getTableForVid(vid);
    if (table != nullptr) {
        removeAgedEntriesFromHostMap(table);
    }
}

void HostTable::removeAgedEntriesFromAllVlans() {
    for (auto& table : hosts) {
        removeAgedEntriesFromHostMap(table.second);
    }
}

void HostTable::removeAgedEntriesIfNeeded() {
    simtime_t now = simTime();
    if (now >= lastPurge + 1) {
        removeAgedEntriesFromAllVlans();
    }
    lastPurge = now;
}

void HostTable::clearTable() {
    for (auto & elem : hosts) {
        delete elem.second;
    }
    hosts.clear();
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
    WATCH_MAPMAP(hosts);
}

void HostTable::handleMessage(cMessage* msg) {
    throw cRuntimeError("This module doesn't process messages");
}

HostTable::HostMap* HostTable::getTableForVid(unsigned int vid) {
    auto iter = hosts.find(vid);
    if (iter != hosts.end()) {
        return iter->second;
    }
    return nullptr;
}

void HostTable::removeAgedEntriesFromHostMap(HostMap* table) {
    if (table == nullptr) {
        return;
    }
    for (auto iter = table->begin(); iter != table->end(); ) {
        if (iter->second.lastUpdated + agingTime <= simTime()) {
            // don't use (and throw out) aged entries
            EV << "Deleting aged entry: " << iter->first << " --> port"
                      << iter->second.portno << "\n";
            table->erase(iter);
        }
    }
}

} /*end namespace SDN4CoRE*/

