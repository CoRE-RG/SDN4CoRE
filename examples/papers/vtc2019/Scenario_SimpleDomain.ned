

package openflow.custom;

import inet.common.misc.ThruputMeteringChannel;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import openflow.nodes.Open_Flow_Domain;
import openflow.openflow.controller.Open_Flow_Controller;
import openflow.utility.OpenFlowGraphAnalyzer;
import openflow.utility.StaticSpanningTree;


network Scenario_SimpleDomain
{
    @display("bgb=842,642;");


    types:
        channel backboneline extends ThruputMeteringChannel
        {
            delay = 1us;
            datarate = 40Gbps;
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

        domain1: Open_Flow_Domain {
            @display("p=322,367;is=vl");
        }



    connections allowunconnected:

        domain1.gateCPlane++ <--> backboneline <--> open_flow_controller1.ethg++;
}
