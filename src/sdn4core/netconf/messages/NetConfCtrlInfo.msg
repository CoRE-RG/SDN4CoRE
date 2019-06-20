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

cplusplus {{
#include "NetConfMessage_m.h"
}}

namespace SDN4CoRE;

enum NetConfMessageType;

//
// Control info which is attached to a request by the NetConfServer, 
// when forwarded to a data store, or the other way around. 
// It is used to map a response to the request.
//
// @author Timo Haeckel, for HAW Hamburg
//
class NetConfCtrlInfo {
    int messageType@enum(NetConfMessageType);
    string message_id;
    int session_id;
}

class NetConfClientCtrlInfo_Connection {
    int localPort;
    string connectAddress;
    int connectPort;
}
