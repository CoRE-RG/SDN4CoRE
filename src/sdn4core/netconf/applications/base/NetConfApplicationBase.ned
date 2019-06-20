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

package sdn4core.netconf.applications.base;

import sdn4core.netconf.applications.INetConfApplication;
//
// Contains the common interface of a netconf application.
// This module needs to be connected to the NetConf client.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple NetConfApplicationBase like INetConfApplication
{
     parameters:
        @class(SDN4CoRE::NetConfApplicationBase);
        // xml format for NetConf server remotes parameters
        // structure:
        // 	<server_connections>
		//		<connection local_port="123" remote_address="node1" remote_port="830" connect_at="1"/>
		//		<connection local_port="124" remote_address="node2" remote_port="830" connect_at="2"/>
		// 	</server_connections>
        xml serverConnections= default(xml("<server_connections/>"));
    gates:
        // connection to NetConf client application 
        input applicationIn;
        output applicationOut;    
}
