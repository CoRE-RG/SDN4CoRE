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

package sdn4core.examples.soa.cbsExceedLatency;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.node.ethernet.Eth100M;

network cbsExample
{
    parameters:
		**.scheduler.tick = 8.0E-8s;
		**.forceBroadcast = true;
	submodules:
        configurator: IPv4NetworkConfigurator {
            parameters:
                config = xmldoc("ipv4config.xml");
                @display("p=68,34");
        }
        net: <default("Lev0")> like ILev {
            @display("p=254,240");
            nodePrefix = "net.";
        }
        dvcSinkFinal: Node {
            parameters:
                @display("i=block/sink;p=384,240");
                localAddress = "dvcSinkFinal";
            gates:
                ethg[1];
        }

        controller: Controller {
            @display("p=254,110");
        }
    connections:
        net.up <--> Eth100M {  length = 1m; } <--> dvcSinkFinal.ethg[0];
        
        for i = 0..sizeof(net.controlPlane)-1 {
        	net.controlPlane[i] <--> Eth100M {  length = 1m; } <--> controller.ethg++;
        }
}
