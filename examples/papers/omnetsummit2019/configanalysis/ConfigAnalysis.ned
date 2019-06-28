//
// c Timo Haeckel, for HAW Hamburg
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

package sdn4core.examples.papers.omnetsummit2019.configanalysis;

import inet.node.ethernet.Eth100M;
import inet.node.ethernet.Eth1G;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.node.ethernet.EtherSwitch;

//
// This is a simple network with one switch and X hosts that is 
// used to evaluate the performance of the relay unit.
//
// @author Timo Haeckel, for HAW Hamburg
//
network ConfigAnalysis
{
    parameters:
        int numHosts = default(8);

    submodules:
        configurator: IPv4NetworkConfigurator {
            @display("p=24,20");
        }

        controller: Controller {

            @display("p=341,33");
        }

        host[numHosts]: Host {

            @display("p=47,130,c,50");
        }

        sink: Host {

            @display("p=653,130,c,50");
        }

        switch1: Switch {

            @display("p=258,129");
        }

        switch2: Switch {

            @display("p=422,129");
        }

        ethswitch: EtherSwitch {
            @display("p=341,90");
        }

    connections allowunconnected:
        ethswitch.ethg++ <--> Eth1G {  length = 10m; } <--> switch1.gateControlPlane;
        ethswitch.ethg++ <--> Eth1G {  length = 10m; } <--> switch2.gateControlPlane;
        ethswitch.ethg++ <--> Eth1G {  length = 10m; } <--> controller.ethg++;

        for i=0..numHosts-1 {
            host[i].ethg <--> Eth100M {  length = 1m; } <--> switch1.gateDataPlane++;
        }
        switch1.gateDataPlane++ <--> Eth100M {  length = 1m; } <--> switch2.gateDataPlane++;
        sink.ethg <--> Eth100M {  length = 1m; } <--> switch2.gateDataPlane++;

}
