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

#ifndef SDN4CORE_NETCONF_CLIENT_TCP_NETCONFSESSIONINFOTCP_H_
#define SDN4CORE_NETCONF_CLIENT_TCP_NETCONFSESSIONINFOTCP_H_

//SDN4CoRE
#include <sdn4core/netconf/datastructures/base/NetConfClientSessionInfo.h>
//INET
#include "inet/transportlayer/contract/tcp/TCPSocket.h"


namespace SDN4CoRE {

/**
 * TCP specific server session information.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfClientSessionInfoTCP: public NetConfClientSessionInfo {
public:
    NetConfClientSessionInfoTCP(){

    }
    virtual ~NetConfClientSessionInfoTCP(){

    }

    /**
     * returns the connection
     * @return connID
     */
    int getConnId() const {
        return connID;
    }

    /**
     * sets the connection id
     * @param connId
     */
    void setConnId(int connId) {
        connID = connId;
    }

    /**
     * returns the tcp socket
     * @return socket
     */
    inet::TCPSocket* getSocket() {
        return socket;
    }

    /**
     * sets a tcp socket
     * @param socket
     */
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

#endif /* SDN4CORE_NETCONF_CLIENT_TCP_NETCONFSESSIONINFOTCP_H_ */
