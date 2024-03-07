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

package sdn4core.examples.soa.cbsMaxLatency;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.node.ethernet.Eth100M;

network cbsMaxLatency
{
    parameters:
        **.scheduler.tick = 8.0E-8s;
        **.forceBroadcast = true;
        int numStages = default(5);
        int numInputLinks = default(2);

    submodules:
        configurator: IPv4NetworkConfigurator {
            parameters:
                config = xmldoc("ipv4config.xml");
                @display("p=50,50");
        }

        talkerSrc[numInputLinks]: Node {
            parameters:
                @display("i=block/source;p=200,150,c,100");
                localAddress = "talkerSrc[" + string(index) + "]";
        }

        stage[numInputLinks]: Stages {
            parameters:
            	@display("i=block/network;p=350,150,c,100");
            	numStages = parent.numStages;
        }

        aggregateSwitch: Switch {
            @display("p=500,150");
        }
        
        sink: Node {
            parameters:
            	@display("p=650,150");
                localAddress = "sink";
        }

        controller: Controller {
            @display("p=350,50");
        }
        
    connections:
        // Controlplane
        aggregateSwitch.gateControlPlane <--> Eth100M { length = 1m; } <--> controller.ethg++;
        for j=0..(numStages*numInputLinks)-1 {
        	stage[j%numInputLinks].controlplane[j%numStages] <--> controller.ethg++;
    	}
    	// Dataplane
    	aggregateSwitch.gateDataPlane++ <--> Eth100M { length = 1m; } <--> sink.ethg++;
    	for i=0..numInputLinks-1 {
    		talkerSrc[i].ethg++ <--> stage[i].left;
    		stage[i].right <--> aggregateSwitch.gateDataPlane++;
    	}    	
}

