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

#ifndef SDN4CORE_CONTROLLERSTATE_IP_IPV4ROUTINGTABLE_H_
#define SDN4CORE_CONTROLLERSTATE_IP_IPV4ROUTINGTABLE_H_

#include <omnetpp.h>
#include <sdn4core/controllerState/ip/IPTableManagement.h>
//INET
#include "inet/networklayer/contract/ipv4/IPv4Address.h"
#include "inet/networklayer/ipv4/IPv4RoutingTable.h"

namespace SDN4CoRE {

/**
 * Extended MACAddressTable for controller state which has friend class IPTableManagement
 */
class FriendIPv4RoutingTable: public inet::IPv4RoutingTable {
    friend class IPTableManagement;
};

} /*end namespace SDN4CoRE*/

#endif /* SDN4CORE_CONTROLLERSTATE_IP_IPV4ROUTINGTABLE_H_ */
