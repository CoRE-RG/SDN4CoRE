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
// c Mohammad Fazel Soltani, for HAW Hamburg
// 

#ifndef __SDN4CORE_TSNLEARNINGCONTROLLERAPP_H_
#define __SDN4CORE_TSNLEARNINGCONTROLLERAPP_H_

#include <omnetpp.h>
#include "sdn4core/controllerApps/avb/AVBLearningControllerApp.h"

namespace SDN4CoRE{

/**
 * TSNLearningControllerApp is an SDN controller application that handles
 * tsn real time traffic as well as best effort MAC switching.
 *
 * @author Mohammad Fazel Soltani, for HAW Hamburg
 */
class TSNLearningControllerApp : public virtual AVBLearningControllerApp
{
  protected:
    virtual void initialize() override;

    /**
     * @brief Indicates a parameter has changed.
     *
     * @param parname Name of the changed parameter or nullptr if multiple parameter changed.
     */
    virtual void handleParameterChange(const char* parname) override;

    /**
     *  Creates a match from an packet in message, setting as many match fields as possible.
     * @param packetIn  The packet in message to create a match for.
     * @return          The match created.
     */
    virtual openflow::oxm_basic_match createMatchFromPacketIn(openflow::OFP_Packet_In* packetIn) override;

    /**
     * Implements the main switching engine for best effort packets.
     * @param packet_in_msg Packet in the be switched.
     */
    virtual void doSwitching(openflow::OFP_Packet_In *packet_in_msg) override;

    /**
     * priorities that should not be dynamically forwarded, e.g., if they are scheduled
     */
    std::vector<int> _staticPriorities;
};
} /*end namespace SDN4CoRE*/
#endif
