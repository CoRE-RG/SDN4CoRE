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

package sdn4core.examples.papers.tssdnsoa.cbsMaxLatency;
import inet.node.ethernet.Eth100M;

module Stages
{
	parameters:
	    int numStages = default(5);
	    
	gates:
	    inout left @display("m=w");
	    inout right @display("m=e");
	    inout controlplane[numStages];
	    
	submodules:
		
		ctSrc[numStages]: Node {
            parameters:
            	@display("i=block/source;p=100,100,r,50");
                localAddress = "stage[" + string(parentIndex())+ "].ctSrc[" + string(index) + "]";
		}
		
		stageSwitch[numStages]: Switch {
            @display("p=100,200,r,50");
		}
		
	connections:
	    left <--> Eth100M { length = 1m; @display("t=talker;m=w"); } <--> stageSwitch[0].gateDataPlane++;
	    for i = 0..numStages-2 {
	        stageSwitch[i].gateDataPlane++ <--> Eth100M { length = 1m; } <--> stageSwitch[i+1].gateDataPlane++;
	    }
	    right <--> Eth100M { length = 1m; @display("t=listener;m=e"); } <--> stageSwitch[numStages-1].gateDataPlane++;
	    for i = 0..numStages-1 {
	        stageSwitch[i].gateControlPlane <--> Eth100M { length = 1m; @display("t=cp;m=s"); } <--> controlplane[i];
			stageSwitch[i].gateDataPlane++ <--> Eth100M { length = 1m; } <--> ctSrc[i].ethg++;
	    }
	    
}
