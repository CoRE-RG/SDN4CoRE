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

package sdn4core.netconf.client.tcp;

import sdn4core.netconf.client.base.NetConfClientBase;

//
// Contains the TCP specific implementation of a NetConf client.
// This module has to be connected to the tcp module.
//
// All responses will be forwarded to the applicaitonOut gate with the 
// same index as the arriving applicationIn gate   
//
// @author Timo Haeckel, for HAW Hamburg
//
simple NetConfClientTCP extends NetConfClientBase
{
    parameters:
        @class(SDN4CoRE::NetConfClientTCP);
}
