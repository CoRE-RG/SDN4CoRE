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

#ifndef __SDN4CORE_LLDPCONTROLLERAPP_H_
#define __SDN4CORE_LLDPCONTROLLERAPP_H_

#include "sdn4core/controllerApps/base/LearningControllerApp.h"
//STD
#include <vector>
//inet
#include "inet/linklayer/ethernet/EtherFrame_m.h"

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * LLDPControllerApp is an SDN controller application that handles link layer discovery.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class LLDPControllerApp: public PacketProcessorBase {
public:

protected:
    virtual void initialize() override;
    virtual void handleParameterChange(const char* parname) override;
    virtual void handleMessage(cMessage *msg) override;

    virtual void processPacketIn(openflow::OFP_Packet_In *packet_in_msg)
            override;

    virtual void processSwitchConnection(openflow::Switch_Info* swInfo)
            override;

    /**
     * Schedule the next LLDP cycle.
     */
    virtual void scheduleNextCycle();

    /**
     * Install a flow that forwards the LLDP messages to the controller on a switch.
     * @param swInfo info about the switch
     */
    virtual void installLLDPFLow(openflow::Switch_Info* swInfo);

    /**
     * Send LLDP packages to all connected network devices.
     */
    virtual void sendLLDP();

    /**
     * Create an lldp frame for the given switch port.
     * @param switchId The switch id
     * @param port The port number
     * @return An Ethernet frame containing the lldp message.
     */
    virtual inet::EthernetIIFrame* createLLDPPacket(std::string switchId,
            int port);

protected:
    /**
     * Cached parameter for the lldp execution cycle.
     */
    simtime_t cycle;

    /**
     * Cached parameter indicating if lldp shall be triggered on new connection.
     */
    bool lldpOnNewConnection;
    /**
     * Self message used to trigger the cyclic LLDP messages.
     */
    cMessage* trigger;

    /**
     * Reference to the deviceTable module.
     */
    DeviceTable* deviceTable;
};

} /*end namespace SDN4CoRE*/

#endif /* __SDN4CORE_LLDPCONTROLLERAPP_H_ */
