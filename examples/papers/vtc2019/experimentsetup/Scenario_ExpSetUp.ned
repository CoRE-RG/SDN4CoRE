

package openflow.custom.experimentsetup;

import inet.common.misc.ThruputMeteringChannel;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import openflow.nodes.Open_Flow_Domain;
import openflow.openflow.controller.Open_Flow_Controller;
import openflow.utility.OpenFlowGraphAnalyzer;
import openflow.utility.StaticSpanningTree;
import inet.node.ethernet.EtherSwitch;


network Scenario_ExpSetUp
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
        open_flow_controller1: Open_Flow_Controller {
            @display("p=322,190");
        }

        domain[numOFDomains]: Open_Flow_Domain {
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
