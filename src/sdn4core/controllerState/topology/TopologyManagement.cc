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

#include "sdn4core/controllerState/topology/TopologyManagement.h"

// INET
#include "inet/linklayer/ethernet/EtherFrame_m.h"
// CoRE4INET
#include "core4inet/utilities/customWatch.h"

using namespace std;
using namespace inet;
using namespace openflow;
//using namespace CoRE4INET;

namespace SDN4CoRE {

Define_Module(TopologyManagement);

TopologyManagement::TopologyManagement() {
}

TopologyManagement::~TopologyManagement() {
}

int TopologyManagement::findOutportAtSwitch(Switch_Info* swInfo,
        OFP_Packet_In* packetIn) {
    if (swInfo != nullptr && packetIn != nullptr) {
        if (EthernetIIFrame* eth =
                dynamic_cast<EthernetIIFrame *>(packetIn->getEncapsulatedPacket())) {
            MACAddress hostMac = eth->getSrc();
            string switchId = swInfo->getMacAddress();
            return findOutportAtSwitch(switchId, hostMac);
        }
    }
    return -1;
}

int TopologyManagement::findOutportAtSwitch(string& switchId,
        MACAddress& hostMac) {
    return findOutportAtSwitch(switchId,
            hostTable->getHostForMacAddress(hostMac));
}

int TopologyManagement::findOutportAtSwitch(string& switchId,
        L3Address& hostIp) {
    return findOutportAtSwitch(switchId,
            hostTable->getHostForIpAddress(hostIp));
}

int TopologyManagement::findOutportAtSwitch(string& switchId,
        HostTable::HostEntry* host) {
    Enter_Method
    ("TopologyManagement::findOutportAtSwitch()");
    if (host) {
        int cachedHop = findNextHopInCache(switchId, host);
        if (cachedHop != -1) {
            return cachedHop;
        }
        Route route = findRoute(switchId, host);
        if (!route.empty()) {
            return route.front().port;
        }
    }
    return -1;
}

SwitchPort TopologyManagement::findEdgePort(MACAddress& hostMac) {
    return findEdgePort(hostTable->getHostForMacAddress(hostMac));
}

SwitchPort TopologyManagement::findEdgePort(L3Address& hostIp) {
    return findEdgePort(hostTable->getHostForIpAddress(hostIp));
}

SwitchPort TopologyManagement::findEdgePort(HostTable::HostEntry* host) {
    Enter_Method
    ("TopologyManagement::findEdgePort()");
    if (host) {
        // the hostTable already knows the edge port.
        return SwitchPort(host->switch_id, host->portno);
    }
    return SwitchPort();
}

TopologyManagement::Route TopologyManagement::findRoute(string& fromSwitch,
        MACAddress& hostMac) {
    return findRoute(fromSwitch, hostTable->getHostForMacAddress(hostMac));
}

TopologyManagement::Route TopologyManagement::findRoute(string& fromSwitch,
        L3Address& hostIp) {
    return findRoute(fromSwitch, hostTable->getHostForIpAddress(hostIp));
}

TopologyManagement::Route TopologyManagement::findRoute(string& fromSwitch,
        HostTable::HostEntry* host) {
    Route route;
    if (host) {
        route = calculateRoute(fromSwitch, host);
    }
    return route;
}

TopologyManagement::Route TopologyManagement::calculateRoute(string& fromSwitch,
        HostTable::HostEntry* host) {
    // check if abort recursion!
    if (host->switch_id == fromSwitch) {
        cacheNextHop(fromSwitch, host, host->portno);
        return Route({ SwitchPort(host->switch_id, host->portno) });
    }
    // check if cached
    int cachedPort = findNextHopInCache(fromSwitch, host);
    if (cachedPort != -1) {
        SwitchPort linked = deviceTable->getLinkedSwitchPort(fromSwitch,
                cachedPort);
        Route route = calculateRoute(linked.switchId, host);
        if (!route.empty()) {
            route.push_front(SwitchPort(fromSwitch, cachedPort));
            return route;
        } else {
            // cache must be wrong...
            cacheInvalidateNextHop(fromSwitch, host);
        }
    }
    // check all device links
    vector<DeviceLink_t> links = deviceTable->getDeviceLinksForSwitch(
            fromSwitch);
    for (auto& link : links) {
        Route route = calculateRoute(link.second.switchId, host);
        if (!route.empty()) {
            cacheNextHop(fromSwitch, host, link.first.port);
            route.push_front(SwitchPort(link.first.switchId, link.first.port));
            return route;
        }
    }
    return Route();
}

int TopologyManagement::findNextHopInCache(string& switchId,
        HostTable::HostEntry* host) {
    auto iter = cachedHops.find(host->macAddress);
    if (iter != cachedHops.end()) {
        auto inner = iter->second.find(switchId);
        if (inner != iter->second.end()) {
            return inner->second;
        }
    }
    return -1;
}

void TopologyManagement::cacheInvalidateNextHop(std::string& switchId,
        HostTable::HostEntry* host) {
    auto iter = cachedHops.find(host->macAddress);
    if (iter != cachedHops.end()) {
        auto inner = iter->second.find(switchId);
        if (inner != iter->second.end()) {
            iter->second.erase(inner);
        }
    }
}

void TopologyManagement::cacheNextHop(string& switchId,
        HostTable::HostEntry* host, int port) {
    auto iter = cachedHops.find(host->macAddress);
    if (iter != cachedHops.end()) {
        iter->second[switchId] = port;
    } else {
        cachedHops[host->macAddress] = { {switchId, port}};
    }
}

void TopologyManagement::initialize() {
    ControllerStateManagementBase::initialize();
    hostTable = check_and_cast<HostTable*>(
            getModuleByPath(par("hostTablePath").stringValue()));
    deviceTable = check_and_cast<DeviceTable*>(
            getModuleByPath(par("deviceTablePath").stringValue()));
    WATCH_MAPMAP(cachedHops);
}

} /*end namespace SDN4CoRE*/

