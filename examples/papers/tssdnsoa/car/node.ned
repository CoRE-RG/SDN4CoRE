
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

package sdn4core.examples.papers.tssdnsoa.car;

import soa4core.nodes.MiddlewareTSNHost;

module Node extends MiddlewareTSNHost
{
    parameters:           
        hasQoSNP = default(false);
        middleware.sm.typename = "SomeIpManager";
        middleware.sd.typename = "SomeIpSD";
		middleware.**.multicastInterface = "eth0";
		middleware.sm.initialDelay = default(uniform(0ms,10ms));
		middleware.sm.repetitionsMax=3;
		middleware.sm.repetitionBaseDelay = 100ms;
		middleware.sm.cyclicOfferDelay = 2s;
        services[*].applicationTCPPort = default(1000);
        services[*].qosGroups = default("SOMEIP_UDP");
        services[*].qosGroup = default("SOMEIP_UDP"); // default UDP, if mcast address set, make this SOMEIP_UDP_MCAST; if app is tcp set to SOMEIP_TCP
        services[*].instanceID = 0x0001;
        services[*].vlan_id = 0;
	submodules:
	connections:
}
