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
#include "core4inet/utilities/HelperFunctions.h"

using namespace std;
using namespace openflow;
using namespace CoRE4INET;

namespace SDN4CoRE {

Define_Module(SRPTableManagement);

bool SRPTableManagement::registerTalker(Switch_Info* swinfo, int arrivalPort,
        TalkerAdvertise* talkerAdvertise) {
    SR_CLASS srClass = SR_CLASS::A;
    if (talkerAdvertise->getPriorityAndRank() == PRIOANDRANK_SRCLASSB) {
        srClass = SR_CLASS::B;
    }
    //only take first 3 bit and shift them to fit the uint8_t
    uint8_t pcp = (talkerAdvertise->getPriorityAndRank() & 0xE0) >> 5;
    return registerTalker(swinfo->getMacAddress(), arrivalPort,
            talkerAdvertise->getStreamID(),
            talkerAdvertise->getDestination_address(),
            talkerAdvertise->getVlan_identifier(),
            pcp, srClass, talkerAdvertise->getMaxFrameSize(),
            talkerAdvertise->getMaxIntervalFrames());
}


bool SRPTableManagement::registerTalker(string swMacAddr, int talkerPort,
        uint64_t streamId, inet::MACAddress destination, uint16_t vlanId, uint8_t pcp, SR_CLASS srClass,
        uint16_t maxFrameSize, uint16_t maxIntervalFrames) {
    Enter_Method ("registerTalker");
    //check if we need to create a table for this switch.
    SRPTable* srpTable = getOrCreateManagedState(swMacAddr);
    //check if this talker is already known
    PortModule* module = dynamic_cast<PortModule*>(srpTable->getTalkerForStreamId(streamId, vlanId));
    if (module && module->getPort() != talkerPort) {
        //talker is already known to us but with a different port.
        throw std::invalid_argument("Talker already exists on another port");
    } else {
        module = getOrCreateSwitchPort(swMacAddr, talkerPort);
    }
    return srpTable->updateTalkerWithStreamId(streamId, module, destination, srClass,
            maxFrameSize, maxIntervalFrames, vlanId, pcp, false);
}

bool SRPTableManagement::registerListener(openflow::Switch_Info* swinfo,
        int arrivalPort, CoRE4INET::ListenerReady* listenerReady) {
    return registerListener(swinfo->getMacAddress(), arrivalPort,
            listenerReady->getStreamID(), listenerReady->getVlan_identifier());
}

bool SRPTableManagement::registerListener(string swMacAddr, int listenerPort,
        uint64_t streamId, uint16_t vlanId) {
    Enter_Method ("registerListener");
    //check if there is a table for this switch
    SRPTable* srpTable = getOrCreateManagedState(swMacAddr);
    if (!srpTable) {
        return false;
    }
    //check if this listener is already known
    PortModule* module = nullptr;
    std::list<cModule*> listeners = srpTable->getListenersForStreamId(
            streamId, vlanId);
    for (auto listener : listeners) {
        PortModule* port = dynamic_cast<PortModule*>(listener);
        if (port->getPort() == listenerPort) {
            module = port;
            break;
        }
    }
    if (!module) {
        module = getOrCreateSwitchPort(swMacAddr, listenerPort);
    }
    srpTable->updateListenerWithStreamId(streamId, module, vlanId);
    return true;
}


unsigned long SRPTableManagement::getReservedBandwidthForSwitchPortAndPcp(
        string swMacAddr, int port, uint8_t pcp) {
    Enter_Method("getReservedBandwidthForSwitchPortAndPcp()");
    SRPTable* srpTable = getOrCreateManagedState(swMacAddr);
    if (!srpTable) {
       throw cRuntimeError("There is no srp table for this switch!");
    }
    PortModule* module = getSwitchPort(swMacAddr, port);
    return srpTable->getBandwidthForModuleAndPcp(module, pcp);
}

unsigned long SRPTableManagement::getIncomingIdleSlopeForSwitchPortAndPcp(std::string swMacAddr, int port, uint8_t pcp)
{
    Enter_Method("getIncomingHostIdleSlopeForSwitchPortAndPcp()");
    SRPTable* srpTable = getOrCreateManagedState(swMacAddr);
    if (!srpTable) {
        throw cRuntimeError("There is no srp table for this switch!");
    }
    PortModule* module = getSwitchPort(swMacAddr, port);
    auto talkers = srpTable->getTalkerEntries();
    if (talkers.empty())
    {
        return 0;
    }
    auto listeners = srpTable->getListenerEntries();
    if (listeners.empty())
    {
        return 0;
    }
    unsigned long inputBandwidth = 0;
    for (auto& talker : talkers)
    {
        if (talker.pcp == pcp && talker.module == module)
        {
            for (auto& listener: listeners)
            {
                if (listener.streamId == talker.streamId && listener.vlan_id == talker.vlan_id)
                {
                    inputBandwidth += bandwidthFromSizeAndInterval(talker.framesize + static_cast<size_t>(SRP_SAFETYBYTE), talker.intervalFrames, getIntervalForClass(talker.srClass));
                    break;
                }
            }
        }
    }
    return inputBandwidth;
}

int SRPTableManagement::getTalkerPort(openflow::Switch_Info* switchInfo, uint64_t streamId, uint16_t vid) {
    Enter_Method("getTalkerPort");
    SRPTable* srpTable = getOrCreateManagedState(switchInfo->getMacAddress());
    if (!srpTable) {
       throw cRuntimeError("There is no srp table for this switch!");
    }
    if(PortModule* module = dynamic_cast<PortModule*>(srpTable->getTalkerForStreamId(streamId,vid))){
       return module->getPort();
    }
    return -1;
}

double SRPTableManagement::calculateMaxQueueingDelay(double idleSlope, double classMaxFrame, double ctMaxFrame, const std::vector<unsigned long>& inputPortIdleSlopes, double portTransmitRate, double sumHigherClassMaxFrames, double sumHigherClassIdleSlope)
{
    // we use the formulas from the 802.1Q-2022 standard (see annex L 3.1)
    // L.3.1.1 Queuing delay
    // W<X = R0 - sum[k<X](Rk) 
    // qDelayX = (M0 + sum[k<X](MK)) / W<X
    double queueingDelay = (ctMaxFrame + sumHigherClassMaxFrames) / (portTransmitRate - sumHigherClassIdleSlope);
    //L.3.1.2 Fan-in delay
    double fanInData = 0;
    // a) Determine BO, the maximum possible bandwidth for class X on the output port.
    double b0 = idleSlope;
    // b) For each possible input port i, determine the maximum possible bandwidth Bi for Class X [provided as a parameter]
    // c) For input port i, calculate maxBurstX,i using max(BO, Bi) for the bandwidth. 
    for (double bi : inputPortIdleSlopes)
    {
        if (b0 > 0)
        {
            // c) [...](In the maxBurst formula, use WX = R0 – max(BO, Bi).)
            double w = portTransmitRate - max(b0, bi);
            // d) Add max(maxBurstX,i) to the total fan-in data.
            fanInData += (ctMaxFrame * idleSlope / w) + (classMaxFrame * portTransmitRate / w);
            // e) set BO = BO – Bi and repeat from step c) until BO = 0.
            b0 -= bi;
        }
        else
        {
            // f) For each remaining port, add MX,i to the total fan-in data.
            fanInData += classMaxFrame;
        }
    }
    double fanInDelay = fanInData / portTransmitRate;
    // L.3.1.3 Permanent delay
    // permanent buffer occupancy occurs when bridges are starved and then a burst occurs due to queueing delay
    // Since this kind of event could happen on multiple input ports at the same time, the “permanently buffered” data equals the worst-case fan-in data.
    double permanentBufferDelay = fanInDelay;
    double maxDelay = queueingDelay + fanInDelay + permanentBufferDelay;
    return maxDelay;
}

SRPTableManagement::SRPForwardingInfo_t* SRPTableManagement::getForwardingInfoForStreamID(
        Switch_Info* swinfo, uint64_t streamID, uint16_t vlan_id) {
    Enter_Method ("getForwardingInfoForStreamID");
    SRPForwardingInfo_t* fwd = new SRPForwardingInfo_t();
    SRPTable* srpTable = getOrCreateManagedState(swinfo->getMacAddress());
    if (!srpTable) {
        throw cRuntimeError(
                "Forwarding info for switch requested, but there is no srp table for it.");
    }

    //gather all needed information
    fwd->streamID = streamID;
    fwd->vlanID = vlan_id;
    //get talker
    SRPTable::TalkerEntry* talker = srpTable->getTalkerEntryForStreamId(
            streamID, vlan_id);
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
    std::list<cModule*> listeners = srpTable->getListenersForStreamId(streamID,
            vlan_id);
    //fill the output info for each listener.
    for (auto listener : listeners) {
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

void SRPTableManagement::dumpConfigToStream(std::ostream& stream,
        int indentTabs) {
    Enter_Method_Silent ("dumpConfigToStream");
    ostringstream oss;
    stream << string(indentTabs, '\t') << "<srpManager>" << endl;
    const map<string, SRPTable*>& managedStates = getAllManagedStates();
    for (auto table : managedStates) {
        stream << exportSRPTableToXML(table.second, table.first, indentTabs + 1);
    }
    stream << string(indentTabs, '\t') << "</srpManager>" << endl;
}

bool SRPTableManagement::loadConfig(cXMLElement* configuration) {
    Enter_Method_Silent ("loadConfig");
    bool changed = false;
    if (cXMLElement* srpManagerXML = locateSrpManagerInXML(configuration)) {
        for (cXMLElement* table : srpManagerXML->getChildrenByTagName("srpTable")) {
            if (const char* swMac = table->getAttribute("switch_id")) {
                changed |= readSRPTableFromXML(table, swMac);
            }
        }
    }
    return changed;
}

bool SRPTableManagement::loadConfigForSwitch(const string& swMacAddr,
        cXMLElement* configuration) {
    Enter_Method_Silent ("loadConfigForSwitch");
    if (cXMLElement* srpManagerXML = locateSrpManagerInXML(configuration)) {
        for (cXMLElement* table : srpManagerXML->getChildrenByTagName("srpTable")) {
            if (const char* swMac = table->getAttribute("switch_id")) {
                if (strcmp(swMac, swMacAddr.c_str()) == 0) {
                    return readSRPTableFromXML(table, swMac);
                }
            }
        }
    }
    return false;
}

void SRPTableManagement::onCreateManagedState(SRPTable* managedState,
        std::string& swMacAddr) {
    ControllerStateManagementBase<SRPTable>::onCreateManagedState(managedState,
            swMacAddr);
    managedState->par("agingTime").setDoubleValue(
            this->par("agingTime").doubleValue());
}

cXMLElement* SRPTableManagement::locateSrpManagerInXML(cXMLElement* configuration) {
    if (!configuration) {
        return nullptr;
    }
    if (configuration->isName("srpManager")) {
        return configuration;
    } else {
        return configuration->getFirstChildWithTag("srpManager");
    }
}

bool SRPTableManagement::readSRPTableFromXML(cXMLElement* srp, const string& swMac) {
    bool changed = false;
    SRPTable* srpTable = getOrCreateManagedState(swMac);
    if(cXMLElement* talkerTable = srp->getFirstChildWithTag("talkerTable")) {
        for(auto talkerEntry : talkerTable->getChildrenByTagName("talkerEntry")){
            if(const char* value = talkerEntry->getAttribute("vlan_id")){
                uint16_t vlan_id = atoi(value);
                if(const char* value = talkerEntry->getAttribute("stream_id")){
                    uint64_t stream_id = atoi(value);
                    if(const char* value = talkerEntry->getAttribute("srClass")){
                        SR_CLASS srClass = SR_CLASS::A;
                        if (!strcmp(value, "B")){
                            srClass = SR_CLASS::B;
                        }
                        if(const char* value = talkerEntry->getAttribute("address")){
                            inet::MACAddress address = inet::MACAddress(value);
                            if(const char* value = talkerEntry->getAttribute("framesize")){
                                size_t framesize = atoi(value);
                                if(const char* value = talkerEntry->getAttribute("intervalFrames")){
                                    uint16_t intervalFrames = atoi(value);
                                        if(const char* value = talkerEntry->getAttribute("pcp")){
                                        uint8_t pcp = atoi(value);
                                        if(const char* value = talkerEntry->getAttribute("port")){
                                            int port = atoi(value);
                                            PortModule* module = getOrCreateSwitchPort(swMac, port);
                                            //all values are set correctly --> insert talker.
                                            changed |= srpTable->updateTalkerWithStreamId(stream_id, module, address, srClass, framesize, intervalFrames, vlan_id, pcp, true);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(cXMLElement* listenerTable = srp->getFirstChildWithTag("listenerTable")){
        for(auto listenerEntry : listenerTable->getChildrenByTagName("listenerEntry")){
            if(const char* value = listenerEntry->getAttribute("vlan_id")){
                uint16_t vlan_id = atoi(value);
                if(const char* value = listenerEntry->getAttribute("stream_id")){
                    uint64_t stream_id = atoi(value);
                    if(const char* value = listenerEntry->getAttribute("port")){
                        int port = atoi(value);
                        PortModule* module = getOrCreateSwitchPort(swMac, port);
                        //all values are set correctly --> insert listener.
                        changed |= srpTable->updateListenerWithStreamId(stream_id, module, vlan_id,true);
                    }
                }
            }
        }
    }
    return changed;
}

string SRPTableManagement::exportSRPTableToXML (SRPTable* table, const string& swMac, int indentTabs) {
    ostringstream oss;
    oss << string(indentTabs, '\t') << "<srpTable switch_id=\""
                << swMac << "\" >" << endl;
    oss << string(indentTabs+1, '\t') << "<talkerTable>" << endl;
    for(auto& talkerEntry : table->getTalkerEntries()){
        oss << string(indentTabs+2, '\t') << "<talkerEntry";
        oss << " stream_id=\"" << talkerEntry.streamId << "\"";
        oss << " vlan_id=\"" << talkerEntry.vlan_id << "\"";
        oss << " srClass=\"" << SR_CLASStoString[talkerEntry.srClass] << "\"";
        oss << " address=\"" << talkerEntry.address.str() << "\"";
        oss << " port=\"" << dynamic_cast<PortModule*>(talkerEntry.module)->getPort() << "\"";
        oss << " framesize=\"" << talkerEntry.framesize << "\"";
        oss << " intervalFrames=\"" << talkerEntry.intervalFrames << "\"";
        oss << " pcp=\"" << static_cast<int>(talkerEntry.pcp) << "\"";
        oss << " />" << endl;
    }
    oss << string(indentTabs+1, '\t') << "</talkerTable>" << endl;
    oss << string(indentTabs+1, '\t') << "<listenerTable>" << endl;
    for(auto& listenerEntry : table->getListenerEntries()){
        oss << string(indentTabs+2, '\t') << "<listenerEntry";
        oss << " stream_id=\"" << listenerEntry.streamId << "\"";
        oss << " vlan_id=\"" << listenerEntry.vlan_id << "\"";
        oss << " port=\"" << dynamic_cast<PortModule*>(listenerEntry.module)->getPort() << "\"";
        oss << " />" << endl;
    }
    oss << string(indentTabs+1, '\t') << "</listenerTable>" << endl;
    oss << string(indentTabs, '\t') << "</srpTable>" << endl;
    return oss.str();
}

string SRPTableManagement::dumpAllIdleSlopesToJson() 
{
    stringstream dump;
    dump << "\"switchIdleSlopes\": [ ";
    bool first = true;
    auto switchPorts = getAllSwitchPorts();
    for (auto& switchPort : switchPorts)
    {
        string swMac = switchPort.first.switchId;
        int port = switchPort.first.port;
        for (int pcp = 0; pcp < 8; pcp++)
        {
            auto idleSlope = getReservedBandwidthForSwitchPortAndPcp(swMac, port, pcp);
            if (idleSlope > 0) {
                if (!first)
                {
                    dump << ", ";
                }
                first = false;
                dump << "{ \"switch\": \"" << swMac << "\"";
                dump << ", \"port\": " << port;
                dump << ", \"pcp\": " << pcp;
                dump << ", \"idleSlope\": " << idleSlope;
                dump << " }";
            }
        }
    }
    dump << " ]";
    return dump.str();
}

} /*end namespace SDN4CoRE*/
