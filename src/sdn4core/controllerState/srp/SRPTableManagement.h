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

#ifndef OPENFLOW_REALTIME_CONTROLLERAPPS_SRPTABLEMANAGEMENT_H_
#define OPENFLOW_REALTIME_CONTROLLERAPPS_SRPTABLEMANAGEMENT_H_

#include <omnetpp.h>
#include <sdn4core/controllerState/base/ControllerStateManagementBase.h>
//STD
#include <vector>
//inet
#include "inet/linklayer/common/MACAddress.h"
//CoRE4INET
#include "core4inet/services/avb/SRP/SRPTable.h"
//AUTO_GENERATED MESSAGES
#include "core4inet/linklayer/ethernet/avb/SRPFrame_m.h"
//openflow
#include "openflow/openflow/controller/Switch_Info.h"
//SDN4CoRe

namespace SDN4CoRE {

// TODO register listeners for SRP events such as aging, etc.

/**
 * SRPTableManagement manages the SRPTable operations for the controller.
 * It holds one SRP table per switch.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class SRPTableManagement: public ControllerStateManagementBase<
        CoRE4INET::SRPTable> {
public:

    /**
     * Information how to forward AVB messages.
     */
    class SRPForwardingInfo_t {
    public:
        int inPort;
        inet::MACAddress dest;
        uint16_t vlanID;
        uint8_t pcp;
        uint8_t srClass;
        uint64_t streamID;
        std::vector<int> outports;
    };

    /**
     * Register a talker for a switch and inport.
     * @param swinfo            The switch recieving the talker advertise.
     * @param arrivalPort       The ingress port at the receiving switch.
     * @param talkerAdvertise   The original talker advertise message recieved in the switch.
     * @return                  true if the talker table has been updated.
     */
    virtual bool registerTalker(openflow::Switch_Info* swinfo, int arrivalPort,
            CoRE4INET::TalkerAdvertise* talkerAdvertise);

    /**
     * Register a talker for a switch and inport.
     * @param swMacAddr the openflow mac address of the switch to configure
     * @param talkerPort the port of the talker at the switch
     * @param streamId the stream id to register
     * @param destination the destination MAC of the stream
     * @param vlanId the vlan identifier of the stream
     * @param pcp the vlan priority of the stream
     * @param srClass the srClass of the stream
     * @param maxFrameSize the maximum frame size the stream sends
     * @param maxIntervalFrames the maximum frames per interval send by the stream
     * @return true if the talker table has been updated.
     */
    virtual bool registerTalker(std::string swMacAddr, int talkerPort,
            uint64_t streamId, inet::MACAddress destination, uint16_t vlanId, uint8_t pcp, CoRE4INET::SR_CLASS srClass,
            uint16_t maxFrameSize, uint16_t maxIntervalFrames);

    /**
     * Register a listener for a switch and inport.
     * @param swinfo            The switch recieving the listener ready.
     * @param arrivalPort       The ingress port at the receiving switch.
     * @param listenerReady     The original listener ready message recieved in the switch.
     * @return                  true if the listener table has been updated.
     */
    virtual bool registerListener(openflow::Switch_Info* swinfo,
            int arrivalPort, CoRE4INET::ListenerReady* listenerReady);

    /**
     * Register a listener for a switch and inport.
     * @param swMacAddr the switch to configure
     * @param listenerPort the port of the listener at the switch
     * @param streamId the stream id to listen to
     * @param vlanId the vlan id of the stream
     * @return
     */
    virtual bool registerListener(std::string swMacAddr, int listenerPort,
            uint64_t streamId, uint16_t vlanId);

    /**
     * Retrieve the reserved bandwidth from srp tables for the switch, port, and pcp
     * @param swMacAddr The switch address
     * @param port the port at the switch
     * @param pcp the pcp of the queue
     */
    virtual unsigned long getReservedBandwidthForSwitchPortAndPcp(std::string swMacAddr, int port, uint8_t pcp);

    /**
     * Calculate the incoming idle slope from srp tables for the switch, port, and pcp
     * @param swMacAddr The switch address
     * @param port the port at the switch
     * @param pcp the pcp of the queue
     */
    virtual unsigned long getIncomingIdleSlopeForSwitchPortAndPcp(std::string swMacAddr, int port, uint8_t pcp);

    /**
     * Get the out port for a certain talker at a switch.
     * @param switchInfo        The switch to find the outport for.
     * @param streamId          The stream ID of the talker.
     * @param vid               The vlan id of the talker.
     * @return The outport for the talker.
     */
    virtual int getTalkerPort(openflow::Switch_Info* switchInfo, uint64_t streamId, uint16_t vid);

    /**
     * Calculate the worst-case queuing latency in seconds for a port according to the 802.1Q-2022 standard.
     *       802.1Q-2022 https://ieeexplore.ieee.org/document/10004498
     *       See Annex L.3
     * @note for now only valid for highest priority class.
     * @param idleSlope         The idle slope of the port.
     * @param classMaxFrame     The maximum frame size of the class (in bits including IFG).
     * @param ctMaxFrame        The maximum frame size of the cross traffic (in bits including IFG).
     * @param inputPortIdleSlopes The maximum possible bandwidth for the class for each possible input port i.
     * @param portTransmitRate  The transmit rate of the port.
     * @param sumHigherClassMaxFrames The sum of the maximum frame sizes of higher classes (in bits including IFG for all classes).
     * @param sumHigherClassIdleSlope The sum of the idle slopes of higher classes.
     * @return The maximum port queuing delay in seconds.
     */
    virtual double calculateMaxQueueingDelay(double idleSlope, double classMaxFrame, double ctMaxFrame, const std::vector<unsigned long>& inputPortIdleSlopes, double portTransmitRate, double sumHigherClassMaxFrames, double sumHigherClassIdleSlope);

    /**
     * Provides a forwarding information for AVBFrames according to the SRPTable of a
     * switch and a stream.
     * @param swinfo        The switch handling the frame
     * @param streamID      The stream to be forwarded.
     * @param vlan_id       The VLAN ID of the frame
     * @return              SRPForwardingInfo_t containing all information to create a match.
     */
    virtual SRPForwardingInfo_t* getForwardingInfoForStreamID(
            openflow::Switch_Info* swinfo, uint64_t streamID, uint16_t vlan_id);

    virtual bool loadConfig(cXMLElement* configuration) override;

    virtual bool loadConfigForSwitch(const std::string& swMacAddr,
            cXMLElement* configuration) override;

    virtual void dumpConfigToStream(std::ostream& stream, int indentTabs = 0)
            override;

    /**
     * Helper function to dump all idle slopes to json.
     * @return the json string
     */
    std::string dumpAllIdleSlopesToJson();

protected:

    /**
     * override method from ControllerStateManagementBase to react to srpTable creation
     */
    virtual void onCreateManagedState(CoRE4INET::SRPTable* managedState,
            std::string& swMacAddr) override;

private:

    /** Helper function to locate the srpManager tag in the XML configuration.
     *
     * @param configuration the xml configuration
     * @return the srpManager xml element if found, else nullptr
     */
    cXMLElement* locateSrpManagerInXML(cXMLElement* configuration);

    /**
     * Helper function to parse the xml of one srp table.
     * This is needed as the SRPTable class importFromXML function requires
     * valid ports which have not yet been created from the manager.
     * @param srp the SRPTable xml to read
     * @param swMac the switch mac the table belongs to
     * @return true if the table has been updated, else false
     */
    bool readSRPTableFromXML(cXMLElement* srp, const std::string& swMac);

    /**
     * Helper function to export one srp table to xml.
     * This is needed as the SRPTable class exportToXML function uses
     * the port modules dynamically created. @see~readSRPTableFromXML()
     * @param table the SRP table to export
     * @param indentTabs optional additional indentation for each line.
     * @return the created XML string
     */
    std::string exportSRPTableToXML(CoRE4INET::SRPTable* table, const std::string& swMac, int indentTabs=0);

};

} /*end namespace SDN4CoRE*/

#endif /* OPENFLOW_REALTIME_CONTROLLERAPPS_SRPTABLEMANAGEMENT_H_ */
