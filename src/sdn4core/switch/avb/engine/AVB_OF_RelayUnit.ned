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

package sdn4core.switch.avb.engine;

import sdn4core.switch.base.engine.OF_RelayUnit;

//
// The AVBOpenFlowRelay is the switching engine of the AVB capable OpenFlow Switch.
// It is directly connected to the TCP module to communicate with the OF Controller.
// It handles the forwarding of incoming packets by matching them with the OpenFlowTable 
// (@see~IOpenFlowFlowTable) entries.
// It adds the capability of handling the SRP protocol to the ~OF_RelayUnit module.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple AVB_OF_RelayUnit extends OF_RelayUnit
{
    parameters:
        @class(SDN4CoRE::AVB_OF_RelayUnit);
        @signal[forwardSRPtoConSig](type=CoRE4INET::SRPFrame);
        
        // Path to the SRP protocol module
    	string srpProtocolModule = default("^.srpProtocol");
    	
        //SRP Table module, default name is srpTable
        string srpTable = default("^.srpTable");
}
