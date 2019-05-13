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

#ifndef OPENFLOW_REALTIME_CONTROLLERAPPS_SRPTABLEMANAGEMENT_H_
#define OPENFLOW_REALTIME_CONTROLLERAPPS_SRPTABLEMANAGEMENT_H_

#include <bits/stdint-uintn.h>
#include <omnetpp/cmodule.h>
#include <unordered_map>
#include <vector>

#include "inet/linklayer/common/MACAddress.h"
#include "openflow/openflow/controller/Switch_Info.h"
#include <openflow/tsn/controller/core4inet/services/avb/SRP/OF_CTRL_SRPTable.h>

namespace CoRE4INET {
    class ListenerReady;
    class TalkerAdvertise;
    class SRPFrame;
} /* namespace CoRE4INET */

namespace ofp{

/**
 * Information how to forward AVB messages.
 */
typedef struct SRPForwardingInfo {
    int inPort;
    inet::MACAddress dest;
    uint16_t vlanID;
    uint8_t srClass;
    uint64_t streamID;
    std::vector<int> outports;
}SRPForwardingInfo_t;

/**
 * SRPTableManagement manages the SRPTable operations for the controller.
 */
class SRPTableManagement {
public:
    SRPTableManagement(){

    }
    virtual ~SRPTableManagement(){

    }

    /**
     * Register a talker for a switch and inport.
     * @param talkerAdvertise   The original talker advertise message recieved in the switch.
     * @param swinfo            The switch recieving the talker advertise.
     * @param arrivalPort       The ingress port at the receiving switch.
     * @return                  true if the talker table has been updated.
     */
    virtual bool registerTalker(CoRE4INET::TalkerAdvertise* talkerAdvertise, Switch_Info* swinfo, int arrivalPort);

    /**
     * Register a listener for a switch and inport.
     * @param listenerReady     The original listener ready message recieved in the switch.
     * @param swinfo            The switch recieving the listener ready.
     * @param arrivalPort       The ingress port at the receiving switch.
     * @return                  true if the listener table has been updated.
     */
    virtual bool registerListener(CoRE4INET::ListenerReady* listenerReady, Switch_Info* swinfo, int arrivalPort);

    /**
     * Provides a forwarding information for AVBFrames according to the SRPTable of a switch and a stream.
     * @param swinfo        The switch handling the frame
     * @param streamID      The stream to be forwarded.
     * @param vlan_id       The VLAN ID of the frame
     * @return              SRPForwardingInfo_t containing all information to create a match.
     */
    virtual SRPForwardingInfo_t* getForwardingInfoForStreamID(Switch_Info* swinfo, uint64_t streamID, uint16_t vlan_id);


    /**
     * @brief creates an XML string with the contents of the SRP Table.
     * This string can be used to fill the SRP Table with importFromXML.
     */
    std::string exportToXML();

    /**
     * @brief Imports entries from an XMLdocument.
     * The root element needs to be <srpTable>
     */
    bool importFromXML(cXMLElement* xml,Switch_Info* swinfo);

    /**
     * @brief Module representing the srpTable
     */
    std::unordered_map<Switch_Info*,OF_CTRL_SRPTable*> _srpTable;
private:
    /**
     * Checks if a table exists for the switch or creates a new one.
     * @param swinfo    The switch to create a table for.
     * @return          The table of the switch for convenience.
     */
    OF_CTRL_SRPTable* checkOrCreateTable(Switch_Info* swinfo);
    /**
     * checks if a table for the switch exists.
     * @param swinfo    The switch to check the table for.
     * @return          true if a table already exists.
     */
    bool tableExistsForSwitch(Switch_Info* swinfo);
};

} /*end namespace ofp*/

#endif /* OPENFLOW_REALTIME_CONTROLLERAPPS_SRPTABLEMANAGEMENT_H_ */
