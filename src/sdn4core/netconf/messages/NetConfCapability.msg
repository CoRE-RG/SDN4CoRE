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

// 
// TODO implement actual capabilities. For now only the Hello message is implemented 
//

namespace SDN4CoRE;

//
// Capabilities Exchange
//
// Capabilities are advertised in messages sent by each peer during
// session establishment.  When the NETCONF session is opened, each peer
// (both client and server) MUST send a <hello> element containing a
// list of that peer's capabilities.
//
// A server sending the <hello> element MUST include a <session-id>
// element containing the session ID for this NETCONF session.  A client
// sending the <hello> element MUST NOT include a <session-id> element.
//
// A server receiving a <hello> message with a <session-id> element MUST
// terminate the NETCONF session.  Similarly, a client that does not
// receive a <session-id> element in the server's <hello> message MUST
// terminate the NETCONF session (without first sending a
// <close-session>).
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConfHello {
    int session_id;
    byteLength = 40;//<hello><session-id>1</session-id></hello>
}
   
   
   