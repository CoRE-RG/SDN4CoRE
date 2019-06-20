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

#ifndef SDN4CORE_NETCONF_SERVER_TCP_NETCONFSESSIONINFOTCP_H_
#define SDN4CORE_NETCONF_SERVER_TCP_NETCONFSESSIONINFOTCP_H_

#include <sdn4core/netconf/datastructures/base/NetConfServerSessionInfo.h>

#include "inet/transportlayer/contract/tcp/TCPSocket.h"

namespace SDN4CoRE {

/**
 * TCP specific server session information.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfServerSessionInfoTCP: public NetConfServerSessionInfo {
public:
    NetConfServerSessionInfoTCP(){

    }
    virtual ~NetConfServerSessionInfoTCP(){

    }

    int getConnId() const {
        return connID;
    }

    void setConnId(int connId) {
        connID = connId;
    }

    inet::TCPSocket* getSocket() {
        return socket;
    }

    void setSocket(inet::TCPSocket* socket) {
        this->socket = socket;
    }

private:
    /**
     * TCP socket for session.
     */
    inet::TCPSocket *socket;

    /**
     * TCP Connection ID
     */
    int connID;


};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_NETCONF_SERVER_TCP_NETCONFSESSIONINFOTCP_H_ */
