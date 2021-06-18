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
// c Timo Haeckel, for HAW Hamburg
// 

package sdn4core.switch.IEEE8021Qbv;

import sdn4core.netconf.nodes.NetConfManagedUnit;
import sdn4core.switch.IEEE8021Qbv.IEEE8021QbvOpenFlowSwitch;

//
// This module adds programmable parameters via NetConf two the original model of an OpenFlow Ethernet 
// switch that supports IEEE 802.1Qbv priority forwarding with Time-Aware Shaping (@see~CoRE4INET::IEEE8021QbvPHYPort).
// It forwards packets according to the flow table entries and is connected to the OpenFlow Controller.
//
// @author Timo Haeckel, for HAW Hamburg
//
module IEEE8021QbvOFNCSwitch extends IEEE8021QbvOpenFlowSwitch
{
    parameters:
        double nc_service_time @unit(s) = default(0s);
        string netConfServerType = default("NetConfServerTCP");
       	
       	int numConfigurators = default (2);
		string of_configuratorType = default("NetConfDataConfiguratorFlowTable");	
		string qbv_configuratorType = default("NetConfDataConfiguratorIEEE8021Qbv");

    gates:
        // no additional gates needed

    submodules:
        // Netconf Server module
        netconf : NetConfManagedUnit {
            processingTime = nc_service_time;
            netConfServerType = netConfServerType;
            numConfigurators = numConfigurators;	
            configurators[0].typename = of_configuratorType;
            configurators[1].typename = qbv_configuratorType;
        }
        

    connections:
        netconf.transportIn <-- tcp.appOut++;
        netconf.transportOut --> tcp.appIn++;

}
