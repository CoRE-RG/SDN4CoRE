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

package sdn4core.nodes.ieee8021qbv;

import sdn4core.switch.ieee8021qbv.IEEE8021QbvOpenFlowSwitch;

//inet
import inet.common.misc.ThruputMeteringChannel;
import inet.node.ethernet.EtherSwitch;
import inet.node.inet.StandardHost;
//CoRE4INET


//
// AVB capable OpenFlow domain consisting of an OpenFlow switch and several hosts, but NO controller.
// @see~OpenFlowDomain
//
// @author Timo Haeckel, for HAW Hamburg
//
module IEEE8021Qbv_OpenFlowDomain
{
    parameters:
        @display("bgb=347,267;i=misc/cloud;is=vs;bgl=2");
        int numClients = default(0);
        int domainID = default(-1);

    gates:
        inout gateDPlane[] @labels(DataPlane-conn);
        inout gateCPlane[] @labels(ControlPlane-conn);
    types:
        channel ethernetline extends ThruputMeteringChannel
        {
            delay = 1us;
            datarate = 100Mbps;
            thruputDisplayFormat = "u";
        }
    submodules:
        open_flow_switch: IEEE8021QbvOpenFlowSwitch {
            @display("p=120,186");
            gates:
                gateDataPlane[sizeof(gateDPlane)+numClients];
        }

        etherSwitch: EtherSwitch {
            @display("p=240,186");
            gates:
                ethg[sizeof(gateCPlane)];
        }

        client[numClients]: StandardHost {
            @display("p=120,50,row,90");
        }
    connections allowunconnected:
        for i=0..sizeof(gateDPlane)-1 {
            gateDPlane[i] <--> open_flow_switch.gateDataPlane[i];
        }

        for i=0..numClients-1 {
            client[i].ethg++ <--> ethernetline <--> open_flow_switch.gateDataPlane[sizeof(gateDPlane)+i];
        }

        for i=0..sizeof(gateCPlane)-1 {
            etherSwitch.ethg[i] <--> gateCPlane[i];
        }

        etherSwitch.ethg++ <--> ethernetline <--> open_flow_switch.gateControlPlane;
}

