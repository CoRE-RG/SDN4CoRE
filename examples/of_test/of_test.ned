

package sdn4core.examples.of_test;

import sdn4core.controller.base.OpenFlowControllerBase;
//INET
import inet.common.misc.ThruputMeteringChannel;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.node.ethernet.EtherSwitch;
//OPENFLOW
import openflow.utility.OpenFlowGraphAnalyzer;
import openflow.utility.StaticSpanningTree;

import sdn4core.nodes.base.OpenFlowDomain;

network of_test
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

        domain[numOFDomains]: OpenFlowDomain {
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
