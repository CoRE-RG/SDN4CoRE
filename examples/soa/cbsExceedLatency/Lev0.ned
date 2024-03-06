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

//
// Nesting level 0
//

module Lev0 like ILev
{
    parameters:
        int recLevel = 0;
        int numControlPlaneLinks = 2;
        string nodePrefix = default("");
        @display("i=block/square;bgb=297,210");
    gates:
        inout up @display("p=n");
        inout controlPlane[numControlPlaneLinks];

    submodules:
        dvcGenLeft: Node {
            parameters:
                @display("i=block/source;p=70,140");
                localAddress = parent.nodePrefix + "dvcGenLeft";
            gates:
                ethg[1];
        }
        dvcGenRight: Node {
            parameters:
                @display("i=block/source;p=210,140");
                localAddress = parent.nodePrefix + "dvcGenRight";
            gates:
                ethg[1];
        }
        rec: Rec {
            parameters:
                recLevel = parent.recLevel;
                nodePrefix = parent.nodePrefix + "rec.";
                @display("p=140,70");
        }

    connections:
        for i = 0..sizeof(rec.controlPlane)-1 {
        	rec.controlPlane[i] <--> controlPlane[i];
        }
        
        dvcGenLeft.ethg[0] <-->  rec.inLeft;
        dvcGenRight.ethg[0] <--> rec.inRight;
        rec.up <--> up;
}
