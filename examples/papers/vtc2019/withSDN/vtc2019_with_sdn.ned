

package sdn4core.examples.papers.vtc2019.withSDN;

import sdn4core.controller.base.OpenFlowControllerBase;

import inet.common.misc.ThruputMeteringChannel;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import sdn4core.nodes.avb.AVB_OpenFlowDomain;
import openflow.utility.OpenFlowGraphAnalyzer;
import openflow.utility.StaticSpanningTree;
import inet.node.ethernet.EtherSwitch;


network vtc2019_with_sdn
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
        channel ethernetline extends ThruputMeteringChannel
        {
            delay = 1us;
            datarate = 100Mbps;
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

        domain[numOFDomains]: AVB_OpenFlowDomain {
        }

		controllerNetwork: EtherSwitch {
        }


    connections allowunconnected:
        //interconnect the domains
        if numOFDomains >= 2 {
            domain[0].gateDPlane++ <--> ethernetline <--> domain[1].gateDPlane++;
        }
        
        //connect all domains to the controller network
        for i=0..numOFDomains-1 {
            domain[i].gateCPlane++ <--> backboneline <--> controllerNetwork.ethg++;
        }

        controllerNetwork.ethg++ <--> backboneline <--> open_flow_controller1.ethg++;
}
