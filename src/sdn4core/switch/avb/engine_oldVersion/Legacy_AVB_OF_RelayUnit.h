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

#ifndef __SDN4CORE_AVB_OF_RELAYUNIT_H_
#define __SDN4CORE_AVB_OF_RELAYUNIT_H_

#include <omnetpp.h>
#include <sdn4core/switch/base/engine_oldVersion/LegacyOF_RelayUnit.h>
#include "core4inet/services/avb/SRP/SRPTable.h"

namespace SDN4CoRE{


/**
 * The AVBOpenFlowRelay is the switching engine of the AVB capable OpenFlow switch.
 * It is directly connected to the TCP module to communicate with the controller (@see~OF_Controller).
 * It handles the forwarding of incoming packets by matching them with the OpenFlowTable
 * (@see~IOpenFlowFlowTable) entries.
 * It adds the capability of handling the SRP protocol to the @see~OF_RelayUnit module.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class LegacyAVB_OF_RelayUnit : public LegacyOF_RelayUnit
{
public:
    LegacyAVB_OF_RelayUnit();
    ~LegacyAVB_OF_RelayUnit();
    virtual void finish() override;

protected:
    //omnetpp module funcitons
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    virtual void handleMessage(omnetpp::cMessage *msg) override;


    /**
     * Processes an OpenFlow packet arriving on controlPlane interface.
     */
    virtual void processControlPlanePacket(omnetpp::cMessage* msg) override;

    /**
     * Processes a data frame arriving on a dataPlane interface.
     */
    virtual void processDataPlanePacket(omnetpp::cMessage* msg) override;

    /**
     * Extracts the information from an incoming frame to be matched against the openflow table.
     * @param frame     the frame to create a match for
     * @return          the match for the frame
     */
    virtual openflow::oxm_basic_match extractMatch(inet::EthernetIIFrame* frame) override;

    /**
     * Handles an SRP message coming from the controller and forwards it to the right modules.
     * @param srp the message to handle
     */
    virtual void handleSRPFromController(omnetpp::cMessage* srp);

    /**
     * Handles an SRP message coming from the srp protocol module and forwards it to the right modules.
     * @param srp the message to handle
     */
    virtual void handleSRPFromProtocol(omnetpp::cMessage* srp);

    /**
     * Forwards an SRP message to the OpenFlow controller.
     * @param msg srp the message to forward
     */
    virtual void forwardSRPtoController(omnetpp::cPacket* msg);

    /**
     * Checks whether the given message is an SRP message.
     * @param msg the messag to check
     * @return  true if the message is an SRP message.
     */
    virtual bool isSRPMessage(omnetpp::cMessage* msg);

protected:
    /**
     * Reference to the SRP Table module.
     */
    CoRE4INET::SRPTable* _srpTable;
};

} /*end namespace SDN4CoRE*/

#endif /*  __SDN4CORE_AVB_OF_RELAYUNIT_H_ */
