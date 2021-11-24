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

#ifndef __OPENFLOW_AVB_AVBLEARNINGCONTROLLERAPP_H_
#define __OPENFLOW_AVB_AVBLEARNINGCONTROLLERAPP_H_

#include "sdn4core/controllerState/mac/MACTableManagement.h"
//STD
#include <vector>
#include <string>
//openflow
#include <openflow/openflow/protocol/OpenFlow.h>
#include "openflow/openflow/controller/Switch_Info.h"
#include "openflow/controllerApps/AbstractControllerApp.h"

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * LearningControllerApp is an SDN controller application that handles
 * best effort MAC switching. It uses the @see~MACTableManagement for
 * L2 Address learning.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class LearningControllerApp: public openflow::AbstractControllerApp {
public:
    int getHardTimeout() const {
        return _hardTimeout;
    }

    int getIdleTimeout() const {
        return _idleTimeout;
    }

    LearningControllerApp();
    ~LearningControllerApp();

protected:
    void setHardTimeout(int hardTimeout) {
        this->_hardTimeout = hardTimeout;
    }

    void setIdleTimeout(int idleTimeout) {
        this->_idleTimeout = idleTimeout;
    }

    void receiveSignal(cComponent *src, simsignal_t id,
            cObject *obj, cObject *details) override;
    virtual void initialize();
    virtual void handleParameterChange(const char* parname) override;
    virtual void finish() override;

    /**
     * Implements the main switching engine for best effort packets.
     * @param packet_in_msg Packet in the be switched.
     */
    virtual void doSwitching(openflow::OFP_Packet_In *packet_in_msg);

    /**
     * Loads an offline Configuration for the controller app regarding a connected switch
     * containing MAC and SRP Table.
     * @param info  The switch to load the offline config for.
     * @return      true if a config was loaded.
     */
    bool loadOfflineConfigFromXML(openflow::Switch_Info* info);

    /**
     * Exports the current state of the MAC and SRP table and creates an XML formatted string.
     * @return      The current state as an XML formatted string
     */
    std::string stateToXML();

    /**
     *  Creates a match from an packet in message.
     * @param packetIn  The packet in message to create a match for.
     * @return          The match created.
     */
    virtual openflow::oxm_basic_match createMatchFromPacketIn(
            openflow::OFP_Packet_In* packetIn);

    /**
     * A management module handling all MAC operations.
     */
    MACTableManagement* _macManager;

private:
    /**
     * The cached flow rule IdleTimeOut parameter.
     */
    int _idleTimeout;
    /**
     * The cached flow rule HardTimeOut parameter.
     */
    int _hardTimeout;
};

} /*end namespace SDN4CoRE*/

#endif /* __OPENFLOW_AVB_AVBLEARNINGCONTROLLERAPP_H_ */
