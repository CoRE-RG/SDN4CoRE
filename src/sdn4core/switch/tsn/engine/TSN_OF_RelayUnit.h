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

#ifndef __SDN4CORE_TSN_OF_RELAYUNIT_H_
#define __SDN4CORE_TSN_OF_RELAYUNIT_H_

//Oment
#include <omnetpp.h>
//SDN4CoRE
#include <sdn4core/switch/avb/engine/AVB_OF_RelayUnit.h>


using namespace omnetpp;

namespace SDN4CoRE{

/**
 * The TSN_OF_RelayUnit is part of the TSN capable switching engine of an OpenFlow switch.
 * It handles the forwarding of incoming packets by matching them with the OpenFlowTable
 * (@see~IOpenFlowFlowTable) entries. Additionally it may send packets to the OF_SwitchAgent
 * for further handling.
 * It adds the capability of handling the SRP protocol to the @see~OF_RelayUnit module.
 *
 * @author Timo Haeckel, Tobias Haugg, for HAW Hamburg
 */
class TSN_OF_RelayUnit : public AVB_OF_RelayUnit
{
protected:


    /**
     * Processes a data frame arriving on a dataPlane interface.
     */
    virtual void processDataPlanePacket(omnetpp::cMessage* msg) override;

    /**
     * Checks whether the given message is an SRP message.
     * @param msg the messag to check
     * @return  true if the message is an SRP message.
     */
    virtual bool isSRPMessage(omnetpp::cMessage* msg) override;

    /**
     * Handles an SRP message coming from the srp protocol module and forwards it to the right modules.
     * @param srp the message to handle
     */
    virtual void handleSRPFromProtocol(omnetpp::cMessage* srp) override;


};

} /*end namespace SDN4CoRE*/

#endif /* __SDN4CORE_TSN_OF_RELAYUNIT_H_ */
