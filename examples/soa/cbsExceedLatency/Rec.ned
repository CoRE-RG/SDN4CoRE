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
import inet.node.ethernet.Eth100M;
import inet.node.ethernet.Eth1G;

//
// Switch connection
//

module Rec
{
    parameters:
        int recLevel = default(0);
        string nodePrefix = default("");
        @display("i=block/square;bgb=502,353");
    gates:
        inout inLeft;
        inout inRight;
        inout up @display("m=e");
        inout controlPlane[2];

    submodules:
        swtLeft: Switch { // left switch
            parameters:
                @display("p=220,190");
                eth[0].mac.address = "0A-00-00-00-0C-" + string(parent.recLevel) + "1";
            gates:
                gateDataPlane[5];
        }
        swtRight: Switch { // right switch
            parameters:
                @display("p=370,190");
                eth[0].mac.address = "0A-00-00-00-0C-" + string(parent.recLevel) + "2";
            gates:
                gateDataPlane[5];
        }

        // Instead of this sinks, ingress filters can be used.
        // These sinks support a simple visual control of the example.
        dvcSinkLeft: Node { // left sink
            parameters:
                @display("i=block/sink;p=220,90");
                localAddress = parent.nodePrefix + "dvcSinkLeft";
            gates:
                ethg[1];
        }
        dvcSinkRight: Node { // right sink
            parameters:
                @display("i=block/sink;p=370,90");
                localAddress = parent.nodePrefix + "dvcSinkRight";
            gates:
                ethg[1];
        }

        dvcGenBELeft: Node { // left BE generator
            parameters:
                @display("i=block/source;p=130,280");
                localAddress = parent.nodePrefix + "dvcGenBELeft";
            gates:
                ethg[1];
        }
        dvcGenBERight: Node { // right BE generator
            parameters:
                @display("i=block/source;p=280,280");
                localAddress = parent.nodePrefix + "dvcGenBERight";
            gates:
                ethg[1];
        }

        dvcGenFoi: Node { // foi generator generator
            parameters:
                @display("i=block/source;p=114,189");
                localAddress = parent.nodePrefix + "dvcGenFoi";
            gates:
                ethg[1];
        }

    connections:
        controlPlane[0] <--> swtLeft.gateControlPlane;
        controlPlane[1] <--> swtRight.gateControlPlane;
        
        swtLeft.gateDataPlane[0] <--> Eth100M {  length = 1m; } <--> dvcGenFoi.ethg[0];
        swtLeft.gateDataPlane[1] <--> Eth100M {  length = 1m; } <--> dvcGenBELeft.ethg[0];
        swtLeft.gateDataPlane[2] <--> Eth100M {  length = 1m; @display("m=s");} <--> inLeft;
        swtLeft.gateDataPlane[3] <--> Eth100M {  length = 1m; } <--> swtRight.gateDataPlane[0];
        swtLeft.gateDataPlane[4] <--> Eth100M {  length = 1m; } <--> dvcSinkLeft.ethg[0];

        swtRight.gateDataPlane[1] <--> Eth100M {  length = 1m; } <--> dvcGenBERight.ethg[0];
        swtRight.gateDataPlane[2] <--> Eth100M {  length = 1m; @display("m=s");} <--> inRight;
        swtRight.gateDataPlane[3]                                <--> up;
        swtRight.gateDataPlane[4] <--> Eth100M {  length = 1m; } <--> dvcSinkRight.ethg[0];
}
