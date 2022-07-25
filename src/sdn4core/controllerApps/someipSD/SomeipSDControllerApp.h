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

#ifndef __SDN4CORE_SOMEIPSDCONTROLLERAPP_H_
#define __SDN4CORE_SOMEIPSDCONTROLLERAPP_H_

#include <omnetpp.h>
#include "sdn4core/controllerApps/base/PacketProcessorBase.h"
#include "soa4core/messages/someip/SomeIpSDHeader.h"
//AUTO-GENERATED MESSAGES
#include "soa4core/messages/someip/SomeIpSDEntry_m.h"
// STD
#include <map>

using namespace omnetpp;


namespace SDN4CoRE {

/**
 * TODO - Generated class
 */
class SomeipSDControllerApp: public PacketProcessorBase
{
  protected:
    virtual void initialize() override;

    /**
      * Interface function for the main processing engine of packet_in messages.
      *
      * This default implementation does nothing
      *
      * @param packet_in_msg The packet in message
      */
     virtual void processPacketIn(openflow::OFP_Packet_In *packet_in_msg) override;

    // ServiceTable* serviceTable;
     void processSomeIpSDHeader(SOA4CoRE::SomeIpSDHeader* someIpSDHeader);

};

} /*end namespace SDN4CoRE*/

#endif
