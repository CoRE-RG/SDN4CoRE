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
// c Timo Haeckel, for HAW Hamburg
// 

package sdn4core.controller.base;

//INET
import inet.node.inet.StandardHost;

//
// Base model of network controller to control the forwarding engines of networking devices in a network.
// As it extends the @see ~inet::StandardHost it can run any additional inet compatible application.
//
// @author Timo Haeckel, for HAW Hamburg
//
module NetworkControllerBase extends StandardHost
{
        @networkNode();
        @labels(node,ethernet-node);
        @display("i=device/server;bgb=795,445;i2=OpenFlow-Logo-small");
}


