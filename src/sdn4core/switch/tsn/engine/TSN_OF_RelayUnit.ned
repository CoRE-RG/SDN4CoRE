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

package sdn4core.switch.tsn.engine;

import sdn4core.switch.avb.engine.AVB_OF_RelayUnit;

//
// The TSN_OF_RelayUnit is the switching engine of the TSN capable OpenFlow Switch.
// It is directly connected to the TCP module to communicate with the OF Controller.
// It handles the forwarding of incoming packets by matching them with the OpenFlowTable 
// (@see~IOpenFlowFlowTable) entries.
// It adds the capability of handling the SRP protocol to the ~OF_RelayUnit module.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple TSN_OF_RelayUnit extends AVB_OF_RelayUnit
{
    parameters:
        @class(SDN4CoRE::TSN_OF_RelayUnit);
    
}
