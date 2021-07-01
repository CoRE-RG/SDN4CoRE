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

package sdn4core.examples.IEEE8021Qbv.of_test;

import sdn4core.nodes.ieee8021qbv.IEEE8021Qbv_OpenFlowDomain;
import sdn4core.controller.base.OpenFlowControllerBase;
//INET
import inet.node.ethernet.EtherSwitch;
import inet.common.misc.ThruputMeteringChannel;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
//OPENFLOW
import openflow.utility.OpenFlowGraphAnalyzer;
import openflow.utility.StaticSpanningTree;

//
// Example of a simple IEEE8021Qbv network controlled with an OpenFlow controller.
//
// @author Timo Haeckel, for HAW Hamburg
//
network IEEE8021Qbv_of_test
{
	parameters:
	    @display("bgb=842,642;");
	    int numOFDomains = default(1);

    types:
        channel backboneline extends ThruputMeteringChannel
        {
            delay = 1us;
            datarate = 1Gbps;
            thruputDisplayFormat = "u";
        }
    submodules:

        configurator: IPv4NetworkConfigurator {
            parameters:
                @display("p=198,190");
        }
        open_flow_controller1: OpenFlowControllerBase {
            @display("p=322,190");
        }

        domain[numOFDomains]: IEEE8021Qbv_OpenFlowDomain {
        }

		controllerNetwork: EtherSwitch {
        }


    connections allowunconnected:
        //interconnect the domains
        if numOFDomains >= 2 {
            domain[0].gateDPlane++ <--> backboneline <--> domain[1].gateDPlane++;
        }
        
        //connect all domains to the controller network
        for i=0..numOFDomains-1 {
            domain[i].gateCPlane++ <--> backboneline <--> controllerNetwork.ethg++;
        }

        controllerNetwork.ethg++ <--> backboneline <--> open_flow_controller1.ethg++;
}
