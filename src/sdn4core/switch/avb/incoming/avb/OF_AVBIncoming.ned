//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
// c Timo Haeckel, for HAW Hamburg
// 

package sdn4core.switch.avb.incoming.avb;

import core4inet.incoming.base.Incoming;

//
// Module for the conformance checks of incoming audio-video bridging traffic.
// Routes AVBFrames to the correct buffers.
// Updated for usage in Openflow Switches.
//
// @see ~Incoming
//
// @author Philipp Meyer, Timo Haeckel
//
simple OF_AVBIncoming extends Incoming
{
    parameters:
        //AVBIncoming is implemented by the AVBIncoming C++ Class
        @class(SDN4CoRE::OF_AVBIncoming);
        @display("i=block/arrival,blue");
        
		//SRP Table module, default name is srpTable
        string srpTable = default("^.srpTable");
    gates:
        //forwarding to switch gateway
        output toGateway @labels(AVBFrame);       
        
        //outputs for AVB Class A Frames
        output AVBAout[] @labels(AVBFrame);
        //outputs for AVB Class B Frames
        output AVBBout[] @labels(AVBFrame);
}
