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

#include <sdn4core/controllerState/srp/SRPTableManagement.h>

//STD
#include <string>
#include <sstream>
#include <algorithm>
//inet
#include "inet/linklayer/common/MACAddress.h"
//CoRE4INET
#include "core4inet/base/avb/AVBDefs.h"


using namespace std;
using namespace openflow;
using namespace CoRE4INET;

namespace SDN4CoRE {

Define_Module(SRPTableManagement);

bool SRPTableManagement::registerTalker(Switch_Info* swinfo, int arrivalPort,
        TalkerAdvertise* talkerAdvertise) {
    Enter_Method("registerTalker");
    //check if we need to create a table for this switch.
    SRPTable* srpTable = getOrCreateManagedState(swinfo->getMacAddress());

    //check if this talker is already known
    PortModule* module = dynamic_cast<PortModule*>(srpTable->getTalkerForStreamId(talkerAdvertise->getStreamID(),
            talkerAdvertise->getVlan_identifier()));
    if (module && module->getPort() != arrivalPort) {
        //talker is already known to us but with a different port.
        throw std::invalid_argument("Talker already exists on another port");
    } else {
        module = getOrCreateSwitchPort(swinfo->getMacAddress(), arrivalPort);
    }

    SR_CLASS srClass;

    if (talkerAdvertise->getPriorityAndRank() == PRIOANDRANK_SRCLASSA) {
        srClass = SR_CLASS::A;
    } else if (talkerAdvertise->getPriorityAndRank() == PRIOANDRANK_SRCLASSB) {
        srClass = SR_CLASS::B;
    } else {
        srClass = SR_CLASS::A;
    }
    //only take first 3 bit and shift them to fit the uint8_t
    uint8_t pcp = (talkerAdvertise->getPriorityAndRank() & 0xE0) >> 5;

    return srpTable->updateTalkerWithStreamId(talkerAdvertise->getStreamID(), module,
            talkerAdvertise->getDestination_address(), srClass, talkerAdvertise->getMaxFrameSize(),
            talkerAdvertise->getMaxIntervalFrames(), talkerAdvertise->getVlan_identifier(), pcp, false);
}

bool SRPTableManagement::registerListener(openflow::Switch_Info* swinfo, int arrivalPort,
        CoRE4INET::ListenerReady* listenerReady) {
    Enter_Method("registerListener");
    //check if there is a table for this switch
    SRPTable* srpTable = getManagedState(swinfo->getMacAddress());
    if (!srpTable) {
        return false;
    }
    //check if this listener is already known
    PortModule* module = nullptr;
    std::list<cModule*> listeners = srpTable->getListenersForStreamId(listenerReady->getStreamID(),
            listenerReady->getVlan_identifier());
    for(auto listener : listeners){
        PortModule* port = dynamic_cast<PortModule*>(listener);
        if(port->getPort() == arrivalPort) {
            module = port;
            break;
        }
    }
    if (!module) {
        module = getOrCreateSwitchPort(swinfo->getMacAddress(), arrivalPort);
    }

    srpTable->updateListenerWithStreamId(listenerReady->getStreamID(),
            module, listenerReady->getVlan_identifier());
    return true;
}

SRPTableManagement::SRPForwardingInfo_t* SRPTableManagement::getForwardingInfoForStreamID(
        Switch_Info* swinfo, uint64_t streamID, uint16_t vlan_id) {
    Enter_Method("getForwardingInfoForStreamID");
    SRPForwardingInfo_t* fwd = new SRPForwardingInfo_t();
    SRPTable* srpTable = getManagedState(swinfo->getMacAddress());
    if (!srpTable) {
        throw cRuntimeError(
                "Forwarding info for switch requested, but there is no srp table for it.");
    }

    //gather all needed information
    fwd->streamID = streamID;
    fwd->vlanID = vlan_id;
    //get talker
    SRPTable::TalkerEntry* talker = srpTable->getTalkerEntryForStreamId(streamID, vlan_id);
    if (talker) {
        fwd->srClass = (uint8_t) talker->srClass;
        fwd->dest = talker->address;
        fwd->inPort = dynamic_cast<PortModule*>(talker->module)->getPort();
        fwd->pcp = talker->pcp;
    } else {
        throw cRuntimeError(
                "Forwarding info for stream requested, but there is no talker entry in srp table.");
    }

    //get listerners
    std::list<cModule*>  listeners = srpTable->getListenersForStreamId(streamID, vlan_id);
    //fill the output info for each listener.
    for(auto listener : listeners){
        PortModule* port = dynamic_cast<PortModule*>(listener);
        if (std::find(fwd->outports.begin(), fwd->outports.end(),
                port->getPort()) != fwd->outports.end()) {
            //already outputting to this port
        } else {
            fwd->outports.push_back(port->getPort());
        }
    }

    return fwd;
}

std::string SRPTableManagement::exportToXML() {
    ostringstream oss;
    oss << "<srpManager>" << endl;

    for (auto iter = cachedManagedStates.begin(); iter != cachedManagedStates.end(); ++iter) {
        // start srp table
        oss << "<table switch_id=\"" << iter->first << ">" << endl;

        oss << iter->second->exportToXML();

        oss << "</table>" << endl;
    }

    oss << "</srpManager>" << endl;

    return oss.str();
}

bool SRPTableManagement::importFromXML(Switch_Info* swinfo, cXMLElement* xml) {

    if(xml && (strcmp(xml->getName(), "srpManager")== 0)){
        cXMLElementList tables = xml->getChildrenByTagName("table");
        for(cXMLElement* table : tables){
            if(strcmp(table->getAttribute("switch_id"),swinfo->getMacAddress().c_str()) == 0) {
                cXMLElement* srp = table->getFirstChildWithTag("srpTable");
                if(srp){
                    return getOrCreateManagedState(swinfo->getMacAddress())->importFromXML(srp);
                }
            }
        }
    }

    return false;
}

void SRPTableManagement::onCreateManagedState(SRPTable* managedState,
        std::string& swMacAddr) {
    ControllerStateManagementBase<SRPTable>::onCreateManagedState(managedState, swMacAddr);
    managedState->par("agingTime").setDoubleValue(this->par("agingTime").doubleValue());
}

} /*end namespace SDN4CoRE*/

