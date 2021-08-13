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
#ifndef SDN4CORE_NETCONF_SERVER_BASE_NETCONFSESSIONINFO_H_
#define SDN4CORE_NETCONF_SERVER_BASE_NETCONFSESSIONINFO_H_

namespace SDN4CoRE {

/**
 * Base class for protocol specific session information.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfServerSessionInfo {
public:
    NetConfServerSessionInfo(){

    }
    virtual ~NetConfServerSessionInfo(){

    }


    /**
     * get the current scessioId
     * @return session id
     */
    int getSessionId() {
        return session_id;
    }

    /**
     * set the sessionId
     * @param _sessionId
     */
    void setSessionId(int sessionId) {
        session_id = sessionId;
    }

private:
    /**
     * Session ID.
     */
    int session_id;

    // TODO save capabilities transmitted in NetConf hello message
};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_NETCONF_SERVER_BASE_NETCONFSESSIONINFO_H_ */
