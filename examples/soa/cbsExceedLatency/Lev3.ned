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
// Nesting level 3
//

module Lev3 like ILev
{
    parameters:
        int recLevel = 3;
        int numControlPlaneLinks = 30;
        string nodePrefix = default("");
        @display("i=block/square;bgb=447,406");
    gates:
        inout up @display("p=n");
        inout controlPlane[numControlPlaneLinks];

    submodules:
        left: Lev2 {
            parameters:
                @display("p=70,140");
                nodePrefix = parent.nodePrefix + "left.";
        }
        right: Lev2 {
            parameters:
                @display("p=210,140");
                nodePrefix = parent.nodePrefix + "right.";
        }
        rec: Rec {
            parameters:
                @display("p=140,70");
                recLevel = parent.recLevel;
                nodePrefix = parent.nodePrefix + "rec.";
        }

    connections:
        for i = 0..sizeof(rec.controlPlane)-1 {
        	rec.controlPlane[i] <--> controlPlane[i];
        }
        for i = 0..sizeof(left.controlPlane)-1 {
        	left.controlPlane[i] <--> controlPlane[i + sizeof(rec.controlPlane)];
        }
        for i = 0..sizeof(right.controlPlane)-1 {
        	right.controlPlane[i] <--> controlPlane[i + sizeof(rec.controlPlane) + sizeof(left.controlPlane)];
        }
        
        left.up  <--> rec.inLeft;
        right.up <--> rec.inRight;
        rec.up   <--> up;
}
