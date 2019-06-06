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

package sdn4core.switch.avb.port;

import core4inet.applications.AS6802.CTApplicationBase;

//
// The AVBEthInterfaceConnectionGateway represents a realtime-ethernet port to the switching engine. 
// It receives all the messages incoming on this port and forwards them to the upperLayerOut.
// Packets received on the upperLayerIn will be forwarded to the correct module for the protocol and message class.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple AVBEthernetInterfaceConnection extends CTApplicationBase
{
    parameters:
        @class(SDN4CoRE::AVBEthernetInterfaceConnection);
        @display("i=block/join");

    gates:
        //Connection to the upper layer    
        output upperLayerOut @labels(EtherFrame);
        input upperLayerIn @labels(EtherFrame);

        // Gate for incoming AVB frames
        input AVBin @directIn @label(AVBFrame);

        //Input gate for the incoming best-effort messages
        input in @directIn @labels(EtherFrame);

        // encapsulate SRP to mirror messages to controller.        
        //Gate for incoming SRP messages from encap
        input encapSrpIn @labels(EtherFrame);
        //Gate for outgoing SRP messages to encap
        output encapSrpOut @labels(EtherFrame);

}
