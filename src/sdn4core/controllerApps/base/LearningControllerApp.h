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

#ifndef __SDN4CORE_LEARNINGCONTROLLERAPP_H_
#define __SDN4CORE_LEARNINGCONTROLLERAPP_H_

#include "sdn4core/controllerApps/base/PacketProcessorBase.h"
#include "sdn4core/controllerState/mac/MACTableManagement.h"

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * LearningControllerApp is an SDN controller application that handles
 * best effort MAC switching. It uses the @see~MACTableManagement for
 * L2 Address learning.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class LearningControllerApp: public PacketProcessorBase {

protected:
    virtual void initialize() override;

    /**
     * Implements the main switching engine for best effort packets.
     * @param packet_in_msg Packet in the be switched.
     */
    virtual void processPacketIn(openflow::OFP_Packet_In *packet_in_msg)
            override;

    /**
     *  Creates a match from an packet in message.
     * @param packetIn  The packet in message to create a match for.
     * @return          The match created.
     */
    virtual openflow::oxm_basic_match createMatchFromPacketIn(
            openflow::OFP_Packet_In* packetIn);

    /**
     * Loads an offline Configuration for the controller app regarding a connected switch
     * containing MAC and SRP Table.
     * @param info  The switch to load the offline config for.
     * @return      true if a config was loaded.
     */
    virtual bool loadOfflineConfigFromXML(openflow::Switch_Info* info) override;

    /**
     * Exports the current state of the MAC and SRP table and creates an XML formatted string.
     * @return      The current state as an XML formatted string
     */
    virtual std::string stateToXML() override;

protected:
    /**
     * A management module handling all MAC operations.
     */
    MACTableManagement* _macManager;

private:
    /**
     * NED path to the mac table manager for creation during runtime.
     */
    static const char MACTABLEMANAGERMODULEPATH[];
};

} /*end namespace SDN4CoRE*/

#endif /* __SDN4CORE_LEARNINGCONTROLLERAPP_H_ */
