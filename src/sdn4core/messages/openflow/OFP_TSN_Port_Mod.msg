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

import openflow.messages.Open_Flow_Message;
import openflow.messages.OFP_Port_Mod;

namespace SDN4CoRE;

packet OFP_TSN_Port_Mod_CBS extends openflow::OFP_Port_Mod {
    // uint32_t port_no; from OFP_Port_Mod!
    uint8_t pcp;
    unsigned long idleSlope;
    
    byteLength = 52; // header 8 Byte, OFP_Port_Mod = 32 (including 10 bytes padding), TSN_Port_Mod_CBS = 1 + 8 + 3 pad
}
 
