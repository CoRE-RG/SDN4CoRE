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

#include <sdn4core/controllerApps/SRPTableManagement.h>

#include "core4inet/base/avb/AVBDefs.h"
#include "inet/linklayer/common/MACAddress.h"
#include <sstream>
#include <algorithm>

using namespace std;
using namespace ofp;
using namespace CoRE4INET;

namespace SDN4CoRE{

bool SRPTableManagement::registerTalker(TalkerAdvertise* talkerAdvertise,
        Switch_Info* swinfo, int arrivalPort) {

    //check if we need to create a table for this switch.
    checkOrCreateTable(swinfo);

    //check if this talker is already known
    if (_srpTable[swinfo]->getTalkerForStreamId(talkerAdvertise->getStreamID(),
        talkerAdvertise->getVlan_identifier())) {
        //talker is already known to us.
        return false;
    }

    SR_CLASS srClass;

    if (talkerAdvertise->getPriorityAndRank() == PRIOANDRANK_SRCLASSA) {
        srClass = SR_CLASS::A;
    } else if (talkerAdvertise->getPriorityAndRank() == PRIOANDRANK_SRCLASSB) {
        srClass = SR_CLASS::B;
    } else {
        srClass = SR_CLASS::A;
    }

    return _srpTable[swinfo]->updateTalkerWithStreamId(talkerAdvertise->getStreamID(),
            swinfo, arrivalPort, talkerAdvertise->getDestination_address(),
            srClass, talkerAdvertise->getMaxFrameSize(),
            talkerAdvertise->getMaxIntervalFrames(),
            talkerAdvertise->getVlan_identifier(), simTime());
}

bool SRPTableManagement::registerListener(ListenerReady* listenerReady,
        Switch_Info* swinfo, int arrivalPort) {
    //check if we need to create a table for this switch.
    if(!tableExistsForSwitch(swinfo)){
        return false;
    }
    _srpTable[swinfo]->updateListenerWithStreamId(listenerReady->getStreamID(),
                swinfo, arrivalPort, listenerReady->getVlan_identifier(), simTime());
    return true;
}

SRPForwardingInfo_t* SRPTableManagement::getForwardingInfoForStreamID(
        Switch_Info* swinfo, uint64_t streamID, uint16_t vlan_id) {
    SRPForwardingInfo_t* fwd = new SRPForwardingInfo_t();
    if(!tableExistsForSwitch(swinfo)){
        throw cRuntimeError("Forwarding info for switch requested, but there is no srp table for it.");
    }

    //gather all needed information
    fwd->streamID = streamID;
    fwd->vlanID = vlan_id;
    //get talker
    auto talker = _srpTable[swinfo]->getTalkerForStreamId(streamID, vlan_id);
    if(talker){
        fwd->srClass = (uint8_t)talker->srClass;
        fwd->dest = talker->address;
        fwd->inPort = talker->port;
    } else {
        throw cRuntimeError("Forwarding info for stream requested, but there is no talker entry in srp table.");
    }

    //get listerners
    OF_CTRL_SRPTable::OF_CTRL_ListenerList listeners = _srpTable[swinfo]->getListenersForStreamId(streamID, vlan_id);
    //fill the output info for each listener.
    for (OF_CTRL_SRPTable::OF_CTRL_ListenerEntry* listener : listeners){
        if(std::find(fwd->outports.begin(), fwd->outports.end(), listener->port) != fwd->outports.end()){
            //already outputting to this port
        } else {
            fwd->outports.push_back(listener->port);
        }
    }

    return fwd;
}

OF_CTRL_SRPTable* SRPTableManagement::checkOrCreateTable(Switch_Info* swinfo) {

    if(!tableExistsForSwitch(swinfo)){
        // create a new srp table for the switch
        _srpTable[swinfo] = new OF_CTRL_SRPTable(); //TODO implement aging
    }
    return _srpTable[swinfo];
}

bool SRPTableManagement::tableExistsForSwitch(Switch_Info* swinfo) {
    auto it = _srpTable.find(swinfo);
    if(it == _srpTable.end()){
        return false;
    }
    return true;
}


std::string SRPTableManagement::exportToXML() {
    ostringstream oss;

    for (auto iter = _srpTable.begin(); iter != _srpTable.end(); ++iter){
        // start srp table
        oss << "<srpTable switch_id=\"" << iter->first->getMacAddress() << "\">" << endl;

        oss << iter->second->exportToXML();

        //end srp table
        oss << "</srpTable>" << endl;
    }

    return oss.str();
}

bool SRPTableManagement::importFromXML(cXMLElement* xml, Switch_Info* swinfo) {
    return checkOrCreateTable(swinfo)->importFromXML(xml, swinfo);
}

} /*end namespace SDN4CoRE*/

