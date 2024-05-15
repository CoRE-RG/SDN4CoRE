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

#include "sdn4core/controllerState/hosts/HostTable.h"
// INET
#include "inet/linklayer/ethernet/EtherFrame_m.h"
#include "inet/networklayer/contract/INetworkDatagram.h"
// CoRE4INET
#include "core4inet/linklayer/ethernet/base/EtherFrameWithQTag_m.h"

#include <algorithm>

using namespace std;
using namespace inet;
using namespace openflow;
using namespace CoRE4INET;

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

bool HostTable::loadConfig(cXMLElement* configuration) {
    return loadConfigForSwitch("", configuration);
}

bool HostTable::loadConfigForSwitch(const std::string& swMacAddr,
        cXMLElement* configuration) {
    Enter_Method
    ("loadConfig");
    bool changed = false;
    if (configuration) {
        cXMLElement* hostTableXML;
        if (configuration->isName("hostTable")) {
            hostTableXML = configuration;
        } else {
            hostTableXML = configuration->getFirstChildWithTag("hostTable");
        }
        if (hostTableXML) {
            cXMLElementList hostsXML = hostTableXML->getChildrenByTagName(
                    "host");
            for (cXMLElement* hostXML : hostsXML) {
                if (const char * switch_id = hostXML->getAttribute(
                        "switch_id")) {
                    if (swMacAddr.empty()
                            || strcmp(switch_id, swMacAddr.c_str()) == 0) {
                        if (const char * macAddress = hostXML->getAttribute(
                                "macAddress")) {
                            MACAddress mac = MACAddress(macAddress);
                            if (!mac.isUnspecified()) {
                                if (const char * portC = hostXML->getAttribute(
                                        "port")) {
                                    int port = atoi(portC);
                                    HostEntry* entry = new HostEntry();
                                    if (const char * nodeName =
                                            hostXML->getAttribute("nodeName")) {
                                        entry->nodeName = nodeName;
                                    }
                                    entry->macAddress = mac;
                                    entry->switch_id = switch_id;
                                    entry->portno = port;
                                    const char * vlanIdsC =
                                            hostXML->getAttribute("vids");
                                    if (vlanIdsC == nullptr) {
                                        vlanIdsC = hostXML->getAttribute(
                                                "vlan_id");
                                    }
                                    if (vlanIdsC != nullptr) {
                                        for (auto vid : cStringTokenizer(
                                                vlanIdsC, ",").asIntVector()) {
                                            entry->vids.push_back(
                                                    static_cast<unsigned int>(vid));
                                        }
                                    } else {
                                        entry->vids.push_back(0);
                                    }
                                    const char * ipsC = hostXML->getAttribute(
                                            "ipAddresses");
                                    if (ipsC == nullptr) {
                                        ipsC = hostXML->getAttribute(
                                                "ipAddress");
                                    }
                                    if (ipsC != nullptr) {
                                        for (auto ipC : cStringTokenizer(ipsC,
                                                ",").asVector()) {
                                            L3Address ip = L3Address(
                                                    ipC.c_str());
                                            if (!ip.isUnspecified()) {
                                                entry->ipAddresses.push_back(
                                                        ip);
                                            }
                                        }
                                    }
                                    entry->learned = false;
                                    changed |= addHost(entry);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return changed;
}

void HostTable::dumpConfigToStream(std::ostream& stream, int indentTabs) {
    Enter_Method
    ("dumpConfigToStream");
    string indent = string(indentTabs, '\t');
    stream << indent << "<hostTable>" << endl;
    for (auto host : hostsByMac) {
        stream << string(indentTabs + 2, '\t') << "<host ";
        stream << "nodeName=\"" << host.second->nodeName << "\" ";
        stream << "macAddress=\"" << host.second->macAddress.str() << "\" ";
        stream << "port=\"" << host.second->portno << "\" ";
        stream << "vids=\"";
        bool first = true;
        for (auto vid : host.second->vids) {
            if (!first) {
                stream << ",";
            } else {
                first = false;
            }
            stream << vid;
        }
        stream << "\" ";
        stream << "ipAddresses=\"";
        first = true;
        for (auto ip : host.second->ipAddresses) {
            if (!first) {
                stream << ",";
            } else {
                first = false;
            }
            stream << ip.str();
        }
        stream << "\" ";
        stream << "/>" << endl;
    }
    stream << indent << "</hostTable>" << endl;
}

bool HostTable::update(OFP_Packet_In* packetIn, Switch_Info * swInfo) {
    Enter_Method
    ("HostTable::update()");
    bool newHost = false;
    if (EthernetIIFrame* eth =
            dynamic_cast<EthernetIIFrame *>(packetIn->getEncapsulatedPacket())) {
        const MACAddress& src_mac = eth->getSrc();
        HostEntry* host = getHostForMacAddress(src_mac, false);
        newHost = (host == nullptr);
        if (newHost) {
            host = new HostEntry();
            host->learned = true;
            host->macAddress = src_mac;
            const string& switch_id = swInfo->getMacAddress();
            host->switch_id = switch_id;
            host->portno =
                    packetIn->getEncapsulatedPacket()->getArrivalGate()->getIndex();
            // insert new host to table
            hostsByMac[src_mac] = host;
            if (hostsBySwitch.find(switch_id) == hostsBySwitch.end()) {
                hostsBySwitch[switch_id] = HostList();
            }
            hostsBySwitch[switch_id].push_back(host);
        }
        unsigned int vid = 0;
        if (EthernetIIFrameWithQTag* qframe =
                dynamic_cast<EthernetIIFrameWithQTag *>(eth)) {
            vid = qframe->getVID();
        }
        if (find(host->vids.begin(), host->vids.end(), vid)
                == host->vids.end()) {
            host->vids.push_back(vid);
        }
        if (eth->hasEncapsulatedPacket()) {
            if (INetworkDatagram* ip = dynamic_cast<INetworkDatagram *>(eth->getEncapsulatedPacket())) {
                const L3Address& src_ip = ip->getSourceAddress();
                if (find(host->ipAddresses.begin(), host->ipAddresses.end(),
                        src_ip) == host->ipAddresses.end()) {
                    host->ipAddresses.push_back(src_ip);
                    hostsByIp[src_ip] = host;
                }
            }
            //TODO Check what happens with ARP here.
        }
        host->lastUpdated = simTime();
    } else {
        throw cRuntimeError(
                "Received Packet_In does not contain an Ethernet Frame.");
    }
    return !newHost;
}

bool HostTable::update(Switch_Info* swInfo, MACAddress source, uint32_t in_port,
        int vlan_id) {
    Enter_Method
    ("HostTable::update()");
    HostEntry* host = getHostForMacAddress(source, false);
    const string& switch_id = swInfo->getMacAddress();
    bool newHost = (host == nullptr);
    if (newHost) {
        // we assume the first detection of the host mac as the entry point into the network.
        host = new HostEntry();
        host->learned = true;
        host->macAddress = source;
        host->portno = in_port;
        host->switch_id = switch_id;
        hostsByMac[source] = host;
        if (hostsBySwitch.find(switch_id) == hostsBySwitch.end()) {
            hostsBySwitch[switch_id] = HostList();
        }
        hostsBySwitch[switch_id].push_back(host);
    }
    if (find(host->vids.begin(), host->vids.end(), vlan_id)
            != host->vids.end()) {
        host->vids.push_back(vlan_id);
    }
    host->lastUpdated = simTime();
    return !newHost;
}

HostTable::HostEntry* HostTable::getHostForMacAddress(const MACAddress& address,
        bool doAging) {
    Enter_Method
    ("HostTable::getHostsForMacAddress()");
    auto iter = hostsByMac.find(address);
    if (iter == hostsByMac.end()) {
        // not found
        return nullptr;
    }
    if (doAging && isAgedHost(iter->second)) {
        removeHost(iter->second);
        return nullptr;
    }
    return iter->second;
}

HostTable::HostEntry* HostTable::getHostForIpAddress(const L3Address& address,
        bool doAging) {
    Enter_Method
    ("HostTable::getHostsForIPAddress()");
    auto iter = hostsByIp.find(address);
    if (iter == hostsByIp.end()) {
        // not found
        return nullptr;
    }
    if (doAging && isAgedHost(iter->second)) {
        removeHost(iter->second);
        return nullptr;
    }
    return iter->second;
}

HostTable::HostList HostTable::getHostsForSwitch(const string& switch_id,
        bool doAging) {
    Enter_Method
    ("HostTable::getHostsForSwitch()");
    auto iter = hostsBySwitch.find(switch_id);
    if (iter == hostsBySwitch.end()) {
        // not found
        return HostList();
    }
    if (doAging) {
        for (auto innerIt = iter->second.begin(); innerIt != iter->second.end();
                ) {
            auto curr = innerIt++;
            if (isAgedHost(*curr)) {
                removeHost(*curr);
            }
        }
    }
    return iter->second;
}

HostTable::HostEntry* HostTable::getHostForSwitchPort(const string& switch_id,
        int portno, bool doAging) {
    Enter_Method
    ("HostTable::getHostForSwitchPort()");
    auto hosts = getHostsForSwitch(switch_id, doAging);
    for (auto host : hosts) {
        if (host->portno == portno) {
            return host;
        }
    }
    return nullptr;
}

int HostTable::getHostCount() const {
    return hostsByMac.size();
}


void HostTable::removeAgedEntries() {
    for (auto iter = hostsByMac.begin(); iter != hostsByMac.end(); iter++) {
        if (isAgedHost(iter->second)) {
            removeHost(iter->second);
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
    for (auto iter = hostsByMac.begin(); iter != hostsByMac.end(); iter++) {
        delete iter->second;
    }
    hostsByMac.clear();
    hostsByIp.clear();
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
    WATCH_PTRMAP(hostsByMac);
}

void HostTable::handleMessage(cMessage* msg) {
    throw cRuntimeError("This module doesn't process messages");
}

void HostTable::refreshDisplay() const {
    char buf[50];
    sprintf(buf, "Hosts: %d", getHostCount());
    getDisplayString().setTagArg("t", 0, buf);
}

bool HostTable::addHost(HostEntry* entry) {
    if (!entry) {
        return false;
    }
    auto hostIt = hostsByMac.find(entry->macAddress);
    if (hostIt == hostsByMac.end()) {
        // entry does not exist save pointer in hostTable and lookup tables
        hostsByMac[entry->macAddress] = entry;
        if (hostsBySwitch.find(entry->switch_id) == hostsBySwitch.end()) {
            hostsBySwitch[entry->switch_id] = HostList();
        }
        hostsBySwitch[entry->switch_id].push_back(entry);
        for (auto ipAddress : entry->ipAddresses) {
            hostsByIp[ipAddress] = entry;
        }
        return true;
    }
    // entry already exist update ipAddresses and vlanIDs
    // TODO is it safe to assume that the MAC, name, switch id + port are always known on host creation?
    bool changed = false;
    HostEntry* old = hostIt->second;
    for (auto ipAddress : entry->ipAddresses) {
        auto ipIt = find(old->ipAddresses.begin(), old->ipAddresses.end(),
                ipAddress);
        if (ipIt == old->ipAddresses.end()) {
            old->ipAddresses.push_back(ipAddress);
            hostsByIp[ipAddress] = old;
            changed = true;
        }
    }
    for (auto vid : entry->vids) {
        auto vidIt = find(old->vids.begin(), old->vids.end(), vid);
        if (vidIt == old->vids.end()) {
            old->vids.push_back(vid);
            changed = true;
        }
    }
    if (!entry->learned && !entry->learned) {
        // offline configuration for a host we already learned
        old->learned = entry->learned;
        changed = true;
    }
    old->lastUpdated = simTime();
    if (old != entry) {
        delete entry;
    }
    return changed;
}

bool HostTable::removeHost(HostEntry* entry) {
    if (!entry) {
        return false;
    }
    auto hostIt = hostsByMac.find(entry->macAddress);
    if (hostIt == hostsByMac.end()) {
        delete entry;
        return false;
    } else {
        hostsByMac.erase(hostIt);
    }
    for (auto l3Addr : entry->ipAddresses) {
        auto ipIt = hostsByIp.find(l3Addr);
        if (ipIt != hostsByIp.end())
            hostsByIp.erase(ipIt);
    }
    auto switchIt = hostsBySwitch.find(entry->switch_id);
    if (switchIt != hostsBySwitch.end()) {
        auto switchHostIt = find(switchIt->second.begin(),
                switchIt->second.end(), entry);
        if (switchHostIt != switchIt->second.end())
            switchIt->second.erase(switchHostIt);
    }
    delete entry;
    return true;
}

bool HostTable::isAgedHost(HostEntry* entry) {
    return entry->learned && agingTime>0 && entry->lastUpdated + agingTime <= simTime();
}

} /*end namespace SDN4CoRE*/

