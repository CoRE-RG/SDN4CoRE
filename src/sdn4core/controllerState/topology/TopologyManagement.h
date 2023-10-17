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

#ifndef __SDN4CORE_TOPOLOGYMANAGEMENT_H_
#define __SDN4CORE_TOPOLOGYMANAGEMENT_H_

#include <omnetpp.h>

#include <sdn4core/controllerState/base/ControllerStateManagementBase.h>

#include <sdn4core/controllerState/hosts/HostTable.h>
#include <sdn4core/controllerState/devices/DeviceTable.h>
// std
#include <list>
#include <map>
#include <algorithm>
// INET
#include "inet/linklayer/common/MACAddress.h"
#include "inet/networklayer/common/L3Address.h"
// openflow
#include "openflow/messages/OFP_Packet_In_m.h"
#include "openflow/openflow/controller/Switch_Info.h"

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * The Topology Management uses the @see~HostTable and @see~DeviceTable to discover hosts and routes.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class TopologyManagement: public ControllerStateManagementBase<cModule> {

public:
    TopologyManagement();
    ~TopologyManagement();

    typedef std::list<SwitchPort> Route;

    class McastRoute {
    public:
        std::map<std::string, std::list<int>> mcastRoute;

        /**
         * Insterts all switchports of the given route into the mcast route
         * @param route the route to be added
         */
        void mergeRoute(const Route& route) {
            // walk the route and add new switch ports to the map
            for(const SwitchPort& switchPort : route) {
                if(mcastRoute.find(switchPort.switchId) == mcastRoute.end())
                {
                    mcastRoute[switchPort.switchId] = std::list<int>();
                    mcastRoute[switchPort.switchId].push_back(switchPort.port);
                }
                else {
                    if(std::find(mcastRoute[switchPort.switchId].begin(),
                            mcastRoute[switchPort.switchId].end(), switchPort.port)
                                == mcastRoute[switchPort.switchId].end())
                    {
                        mcastRoute[switchPort.switchId].push_back(switchPort.port);
                    }
                }
            }
        }
    };

    /**
     * Find the outport for a packet_in and a switch info
     * @param swInfo Info about the switch
     * @param packetIn The incoming packet to route
     * @return The output port number if found, else -1
     */
    virtual int findOutportAtSwitch(openflow::Switch_Info * swInfo,
            openflow::OFP_Packet_In* packetIn);

    /**
     * Find the outport for a host MAC address at a certain switch.
     * @param switchId The switch id (device MAC address)
     * @param hostMac The MAC address of the host
     * @return The output port number if found, else -1
     */
    virtual int findOutportAtSwitch(std::string switchId,
            inet::MACAddress hostMac);

    /**
     * Find the outport for a host IP address at a certain switch.
     * @param switchId The switch id (device MAC address)
     * @param hostIp The IP address of the host
     * @return The output port number if found, else -1
     */
    virtual int findOutportAtSwitch(std::string switchId,
            inet::L3Address hostIp);

    /**
     * Find the outport for a host at a certain switch.
     * @param switchId The switch id (device MAC address)
     * @param host The HostEntry from the HostTable
     * @return The output port number if found, else -1
     */
    virtual int findOutportAtSwitch(std::string switchId,
            HostTable::HostEntry* host);

    /**
     * Find out the edge device and port to which the host MAC is connected.
     * @param hostMac The MAC address of the host
     * @return The switchId and port pair connected to the host if found, else nullptr
     */
    virtual SwitchPort findEdgePort(inet::MACAddress hostMac);

    /**
     * Find out the edge device and port to which the host IP is connected.
     * @param hostIp The IP address of the host
     * @return The switchId and port pair connected to the host if found, else nullptr
     */
    virtual SwitchPort findEdgePort(inet::L3Address hostIp);

    /**
     * Find out the edge device and port to which the host IP is connected.
     * @param host The HostEntry from the HostTable
     * @return The switchId and port pair connected to the host if found, else nullptr
     */
    virtual SwitchPort findEdgePort(HostTable::HostEntry* host);

    /**
     * Find a route through the topology to a host MAC starting at a switch.
     * @param fromSwitch The switch id (device MAC address) of the starting point
     * @param hostMac The MAC address of the host
     * @return An ordered list representing the path through the network,
     *         empty list if no route was found
     */
    virtual Route findRoute(std::string fromSwitch,
            inet::MACAddress hostMac);

    /**
     * Find a route through the topology to a host IP starting at a switch.
     * @param fromSwitch The switch id (device MAC address) of the starting point
     * @param hostIp The IP address of the host
     * @return An ordered list representing the path through the network,
     *         empty list if no route was found
     */
    virtual Route findRoute(std::string fromSwitch,
            inet::L3Address hostIp);

    /**
     * Find a route through the topology to a host starting at a switch.
     * @param fromSwitch The switch id (device MAC address) of the starting point
     * @param host The HostEntry from the HostTable
     * @return An ordered list representing the path through the network,
     *         empty list if no route was found
     */
    virtual Route findRoute(std::string fromSwitch,
            HostTable::HostEntry* host);

protected:
    /**
     * Calculate a route recursively from the switch to the host.
     * @param fromSwitch The switch to start from
     * @param host The host to get to
     * @return An ordered list representing the path through the network,
     *         empty list if no route was found
     */
    virtual Route calculateRoute(std::string fromSwitch,
            HostTable::HostEntry* host, std::string previousSwitch = "");

    /**
     * Looks up the host and switchId combination in the cache and returns the outport.
     * @param switchId the switch id to look for
     * @param host the host to look for
     * @return The outport if found, else -1
     */
    virtual int findNextHopInCache(std::string switchId,
            HostTable::HostEntry* host);

    /**
     * Removes an entry from the next hop cache.
     * @param switchId the switch of the entry
     * @param host the host of the entry
     */
    virtual void cacheInvalidateNextHop(std::string switchId,
            HostTable::HostEntry* host);

    /**
     * Add an entry to the next hop cache.
     * @param switchId the switch of the entry
     * @param host the host of the entry
     * @param port the port of the entry
     */
    virtual void cacheNextHop(std::string switchId,
            HostTable::HostEntry* host, int port);

    virtual void initialize() override;

protected:
    /**
     * Access to the host table module.
     */
    HostTable* hostTable;

    /**
     * Access to the device table module.
     */
    DeviceTable* deviceTable;

    /**
     * Cached hops for host entries using MACAddresses.
     */
    std::map<inet::MACAddress, std::map<std::string, int>> cachedHops;
};

} /*end namespace SDN4CoRE*/

#endif
