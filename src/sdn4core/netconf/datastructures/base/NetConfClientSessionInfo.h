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
#ifndef SDN4CORE_NETCONF_CLIENT_BASE_NETCONFSESSIONINFO_H_
#define SDN4CORE_NETCONF_CLIENT_BASE_NETCONFSESSIONINFO_H_

namespace SDN4CoRE {

/**
 * Base class for protocol specific session information.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfClientSessionInfo {
public:
    NetConfClientSessionInfo(){

    }
    virtual ~NetConfClientSessionInfo(){

    }

    /**
     * get the current scessioId
     * @return session id
     */
    int getSessionId() {
        return _sessionId;
    }

    /**
     * set the sessionId
     * @param _sessionId
     */
    void setSessionId(int sessionId) {
        _sessionId = sessionId;
    }

    /**
     * get the application index
     * @return _applicationIndex
     */
    int getApplicationIndex() const {
        return _applicationIndex;
    }

    /**
     * set the application index
     * @param applicationIndex
     */
    void setApplicationIndex(int applicationIndex) {
        _applicationIndex = applicationIndex;
    }

private:
    /**
     * Session ID.
     */
    int _sessionId;

    /**
     * Application connection gate index
     */
    int _applicationIndex;

    // TODO save capabilities transmitted in NetConf hello message
};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_NETCONF_CLIENT_BASE_NETCONFSESSIONINFO_H_ */
