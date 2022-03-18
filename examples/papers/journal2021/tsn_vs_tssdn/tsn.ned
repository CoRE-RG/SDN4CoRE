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

package sdn4core.examples.papers.journal2021.tsn_vs_tssdn;

import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.node.ethernet.Eth100M;
import inet.node.ethernet.Eth1G;
import inet.node.ethernet.EtherSwitch;

//
// This is a simple network with two SDN switches and 5 hosts that is 
// used to evaluate the TSN + SDN performance of the switches.
//
// @author Timo Haeckel, for HAW Hamburg
//
network tsn
{
    submodules:
        configurator: IPv4NetworkConfigurator {
            @display("p=24,20");
        }

        controller: Controller {

            @display("p=300,25");
        }

        s1: Source {

            @display("p=50,150");
        }

        s2: Source {

            @display("p=50,300");
        }

        s3: Source {

            @display("p=400,300");
        }

        ct: Source {

            @display("p=50,226");
        }

        sink: Sink {

            @display("p=550,225");
        }

        switchleft: TSNSwitch {

            @display("p=200,225");
        }

        switchright: TSNSwitch {

            @display("p=400,225");
        }

        ethswitch: EtherSwitch {
            @display("p=300,125");
        }

    connections allowunconnected:
        ethswitch.ethg++ <--> Eth100M {  length = 1m; } <--> switchleft.gateControlPlane;
        ethswitch.ethg++ <--> Eth100M {  length = 1m; } <--> switchright.gateControlPlane;
        ethswitch.ethg++ <--> Eth100M {  length = 1m; } <--> controller.ethg++;
        
        switchleft.ethg++ <--> Eth100M {  length = 1m; } <--> switchright.ethg++;

        s1.ethg <--> Eth100M {  length = 1m; } <--> switchleft.ethg++;
        s2.ethg <--> Eth100M {  length = 1m; } <--> switchleft.ethg++;
        ct.ethg <--> Eth100M {  length = 1m; } <--> switchleft.ethg++;
        
        switchright.ethg++ <--> Eth100M {  length = 1m; } <--> s3.ethg;
        switchright.ethg++ <--> Eth100M {  length = 1m; } <--> sink.ethg;
}
