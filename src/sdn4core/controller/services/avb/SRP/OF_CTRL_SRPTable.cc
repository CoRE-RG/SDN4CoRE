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

#include <omnetpp/cexception.h>
#include <omnetpp/clog.h>
#include <omnetpp/simtime.h>
#include <omnetpp/simtime_t.h>
#include <sdn4core/controller/services/avb/SRP/OF_CTRL_SRPTable.h>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

#include "core4inet/utilities/HelperFunctions.h"

using namespace std;

using namespace CoRE4INET;

namespace ofp{

OF_CTRL_SRPTable::OF_CTRL_TalkerEntry::OF_CTRL_TalkerEntry() :
        streamId(0), srClass(SR_CLASS::A), swinfo(nullptr), port(-1), framesize(0), intervalFrames(0), vlan_id(VLAN_ID_DEFAULT){

}

OF_CTRL_SRPTable::OF_CTRL_TalkerEntry::OF_CTRL_TalkerEntry(uint64_t new_streamId, SR_CLASS new_srClass, inet::MACAddress new_address,
        Switch_Info *new_swinfo, int new_port, size_t new_framesize, unsigned short new_intervalFrames,
        unsigned short new_vlan_id, simtime_t new_insertionTime) :
                streamId(new_streamId), srClass(new_srClass), address(new_address), swinfo(new_swinfo), port(new_port),
                framesize(new_framesize), intervalFrames(new_intervalFrames), vlan_id(new_vlan_id), insertionTime(new_insertionTime) {

}

OF_CTRL_SRPTable::OF_CTRL_TalkerEntry::~OF_CTRL_TalkerEntry(){

}

OF_CTRL_SRPTable::OF_CTRL_ListenerEntry::OF_CTRL_ListenerEntry() :
        streamId(0), swinfo(nullptr), port(-1), vlan_id(VLAN_ID_DEFAULT){

}

OF_CTRL_SRPTable::OF_CTRL_ListenerEntry::OF_CTRL_ListenerEntry(uint64_t new_streamId, Switch_Info *new_swinfo, int new_port, unsigned short new_vlan_id,
        simtime_t new_insertionTime) :
                streamId(new_streamId), swinfo(new_swinfo), port(new_port), vlan_id(new_vlan_id), insertionTime(new_insertionTime){

};

OF_CTRL_SRPTable::OF_CTRL_ListenerEntry::~OF_CTRL_ListenerEntry() {
}




uint64_t OF_CTRL_SRPTable::getStreamIdForTalkerAddress(const inet::MACAddress &talkerAddress, uint16_t vid)
{
    OF_CTRL_TalkerTable talkerTable = talkerTables[vid];
    for (OF_CTRL_TalkerTable::const_iterator talkerEntry = talkerTable.begin(); talkerEntry != talkerTable.end(); ++talkerEntry)
    {
        if ((*talkerEntry).second->address == talkerAddress)
        {
            return (*talkerEntry).first;
        }
    }
    throw std::invalid_argument("no stream for this talker address registered");
}

SR_CLASS OF_CTRL_SRPTable::getSrClassForTalkerAddress(const inet::MACAddress &talkerAddress, uint16_t vid)
{
    OF_CTRL_TalkerTable talkerTable = talkerTables[vid];
    for (OF_CTRL_TalkerTable::const_iterator talkerEntry = talkerTable.begin(); talkerEntry != talkerTable.end(); ++talkerEntry)
    {
        if ((*talkerEntry).second->address == talkerAddress)
        {
            return (*talkerEntry).second->srClass;
        }
    }
    throw std::invalid_argument("no stream for this talker address registered");
}

OF_CTRL_SRPTable::OF_CTRL_ListenerList OF_CTRL_SRPTable::getListenersForStreamId(uint64_t streamId, uint16_t vid)
{
    OF_CTRL_ListenerList llist;

    OF_CTRL_ListenerTable listenerTable = listenerTables[vid];

    OF_CTRL_ListenerTable::const_iterator iter = listenerTable.find(streamId);

    if (iter != listenerTable.end())
    {
        for (OF_CTRL_ListenerPortList::const_iterator entry = (*iter).second.begin(); entry != (*iter).second.end(); ++entry)
        {
            llist.push_back(entry->second);
        }
    }
    return llist;
}

OF_CTRL_SRPTable::OF_CTRL_ListenerList OF_CTRL_SRPTable::getListenersForTalkerAddress(const inet::MACAddress &talkerAddress, uint16_t vid)
{
    return getListenersForStreamId(getStreamIdForTalkerAddress(talkerAddress, vid), vid);
}

OF_CTRL_SRPTable::OF_CTRL_TalkerEntry* OF_CTRL_SRPTable::getTalkerForStreamId(uint64_t streamId, uint16_t vid)
{
    OF_CTRL_TalkerTable talkerTable = talkerTables[vid];
    OF_CTRL_TalkerTable::const_iterator entry = talkerTable.find(streamId);
    if (entry != talkerTable.end())
    {
        return (*entry).second;
    }
    return nullptr;
}

unsigned long OF_CTRL_SRPTable::getBandwidthForPort(const int port)
{
    unsigned long bandwidth = 0;

    for (std::unordered_map<unsigned int, OF_CTRL_ListenerTable>::iterator i = listenerTables.begin();
            i != listenerTables.end(); ++i)
    {
        OF_CTRL_ListenerTable table = i->second;
        for (OF_CTRL_ListenerTable::const_iterator j = table.begin(); j != table.end(); ++j)
        {
            OF_CTRL_ListenerPortList llist = (*j).second;
            for (OF_CTRL_ListenerPortList::const_iterator k = llist.begin(); k != llist.end(); ++k)
            {
                if ((*k).second->port == port)
                {
                    //get Talkers for this VLAN
                    OF_CTRL_TalkerTable ttable = talkerTables[(*i).first];
                    OF_CTRL_TalkerEntry *tentry = ttable[(*j).first];
                    bandwidth += bandwidthFromSizeAndInterval(tentry->framesize + static_cast<size_t>(SRP_SAFETYBYTE),
                            tentry->intervalFrames, getIntervalForClass(tentry->srClass));
                }
            }
        }
    }

    return bandwidth;
}

unsigned long OF_CTRL_SRPTable::getBandwidthForPortAndSRClass(const int port, SR_CLASS srClass)
{
    unsigned long bandwidth = 0;

    for (std::unordered_map<unsigned int, OF_CTRL_ListenerTable>::iterator i = listenerTables.begin();
            i != listenerTables.end(); ++i)
    {
        OF_CTRL_ListenerTable table = i->second;
        for (OF_CTRL_ListenerTable::const_iterator j = table.begin(); j != table.end(); ++j)
        {
            OF_CTRL_ListenerPortList llist = (*j).second;
            for (OF_CTRL_ListenerPortList::const_iterator k = llist.begin(); k != llist.end(); ++k)
            {
                if ((*k).second->port == port)
                {
                    //get Talkers for this VLAN
                    OF_CTRL_TalkerTable ttable = talkerTables[(*i).first];
                    OF_CTRL_TalkerEntry *tentry = ttable[(*j).first];
                    if (tentry->srClass == srClass)
                    {
                        bandwidth += bandwidthFromSizeAndInterval(
                                tentry->framesize + static_cast<size_t>(SRP_SAFETYBYTE), tentry->intervalFrames,
                                getIntervalForClass(tentry->srClass));
                    }
                }
            }
        }
    }

    return bandwidth;
}

unsigned long OF_CTRL_SRPTable::getBandwidthForStream(uint64_t streamId, uint16_t vid)
{
    //get Talkers for this VLAN
    OF_CTRL_TalkerTable ttable = talkerTables[vid];
    OF_CTRL_TalkerEntry *tentry = ttable[streamId];

    if (!tentry)
    {
        throw cRuntimeError("talkerTable entry not found");
    }

    return bandwidthFromSizeAndInterval(tentry->framesize + static_cast<size_t>(SRP_SAFETYBYTE), tentry->intervalFrames,
            getIntervalForClass(tentry->srClass));
}

bool OF_CTRL_SRPTable::updateTalkerWithStreamId(uint64_t streamId, Switch_Info* swinfo, int port, const inet::MACAddress address,
        SR_CLASS srClass, size_t framesize, uint16_t intervalFrames, uint16_t vid, simtime_t simtime)
{
    bool updated = true;
    OF_CTRL_TalkerTable &talkerTable = talkerTables[vid];

    if (talkerTable.find(streamId) == talkerTable.end())
    {
        if (framesize == 0)
        {
            throw std::invalid_argument("cannot register talker with zero framesize");
        }
        if (intervalFrames == 0)
        {
            throw std::invalid_argument("cannot register talker with zero frameInterval");
        }
        if (swinfo == nullptr)
        {
            throw std::invalid_argument("cannot register talker without swinfo");
        }
        if (port < 0)
        {
            throw std::invalid_argument("cannot register talker without port");
        }

        updated = false;

        if (talkerTable[streamId]){
            throw cRuntimeError("talkerTable already contained entry");
        }

        talkerTable[streamId] = new OF_CTRL_SRPTable::OF_CTRL_TalkerEntry();
    }
    else
    {
        if (talkerTable[streamId]->port != port)
        {
            throw std::invalid_argument("trying to update talker from wrong port");
        }
    }
    talkerTable[streamId]->streamId = streamId;
    talkerTable[streamId]->swinfo = swinfo;
    talkerTable[streamId]->port = port;
    talkerTable[streamId]->srClass = srClass;
    if (framesize > 0)
    {
        talkerTable[streamId]->framesize = framesize;
    }
    if (intervalFrames > 0)
    {
        talkerTable[streamId]->intervalFrames = intervalFrames;
    }
    talkerTable[streamId]->address = address;
    talkerTable[streamId]->vlan_id = vid;
    talkerTable[streamId]->insertionTime = simtime;

    return updated;
}

bool OF_CTRL_SRPTable::removeTalkerWithStreamId(uint64_t streamId, __attribute__((unused)) Switch_Info* swinfo, int port,
        __attribute__((unused))  const inet::MACAddress address, uint16_t vid)
{

    OF_CTRL_TalkerTable &talkerTable = talkerTables[vid];

    OF_CTRL_TalkerTable::const_iterator talker = talkerTable.find(streamId);

    if (talker != talkerTable.end())
    {
        if (talkerTable[streamId]->port != port)
        {
            throw std::invalid_argument("trying to unregister talker from wrong port");
        }
        talkerTable.erase(talker);
        return true;
    }
    return false;
}

bool OF_CTRL_SRPTable::updateListenerWithStreamId(uint64_t streamId, Switch_Info* swinfo, int port, uint16_t vid, simtime_t simtime)
{
    OF_CTRL_TalkerTable ttable = talkerTables[vid];
    if (ttable.find(streamId) == ttable.end())
    {
        std::ostringstream oss;
        oss << "no talker for stream with id " << streamId << " in vlan " << vid;
        throw std::invalid_argument(oss.str());
    }

    bool updated = true;

    OF_CTRL_ListenerTable &listenerTable = listenerTables[vid];
    OF_CTRL_ListenerPortList &llist = listenerTable[streamId];
    OF_CTRL_ListenerPortList::const_iterator listener = llist.find(port);
    if (listener == llist.end())
    {
        if (swinfo == nullptr)
        {
            throw std::invalid_argument("cannot register listener without swinfo");
        }
        if (port < 0)
        {
            throw std::invalid_argument("cannot register listener without port");
        }
        updated = false;
        llist.insert(std::pair<int, OF_CTRL_ListenerEntry*>(port, new OF_CTRL_SRPTable::OF_CTRL_ListenerEntry()));
    }
    llist[port]->streamId = streamId;
    llist[port]->port = port;
    llist[port]->swinfo = swinfo;
    llist[port]->vlan_id = vid;
    llist[port]->insertionTime = simtime;

    return updated;
}

bool OF_CTRL_SRPTable::removeListenerWithStreamId(uint64_t streamId, Switch_Info* swinfo, int port, uint16_t vid)
{
    OF_CTRL_ListenerTable &listenerTable = listenerTables[vid];

    OF_CTRL_ListenerTable::iterator listeners = listenerTable.find(streamId);

    if (listeners != listenerTable.end())
    {
        OF_CTRL_ListenerPortList::iterator listener = (*listeners).second.find(port);
        if (listener != (*listeners).second.end())
        {
            (*listeners).second.erase(listener);
            if ((*listeners).second.size() == 0)
            {
                listenerTable.erase(listeners);
            }
            return true;
        }
    }
    return false;
}

void OF_CTRL_SRPTable::printState()
{
    EV_DETAIL << "Talker Table" << endl;
    EV_DETAIL << "VLAN ID    StreamID    Port    Address    SRClass    Bandwidth(Mbps)    Inserted" << endl;
    for (std::unordered_map<unsigned int, OF_CTRL_TalkerTable>::const_iterator i = talkerTables.begin();
            i != talkerTables.end(); ++i)
    {
        OF_CTRL_TalkerTable table = i->second;
        for (OF_CTRL_TalkerTable::const_iterator j = table.begin(); j != table.end(); ++j)
        {
            EV_DETAIL << (*i).first << "   " << (*j).first << "   " << (*j).second->port << "   "
                    << (*j).second->address.str() << "   "
                    << SR_CLASStoString[(*j).second->srClass] << "    "
                    << static_cast<double>(bandwidthFromSizeAndInterval(
                            (*j).second->framesize + static_cast<size_t>(SRP_SAFETYBYTE), (*j).second->intervalFrames,
                            getIntervalForClass((*j).second->srClass))) / static_cast<double>(1000000) << "   "
                    << (*j).second->insertionTime << endl;
        }
    }

    EV_DETAIL << "Listener Table" << endl;
    EV_DETAIL << "VLAN ID    StreamID    Port    Inserted" << endl;
    for (std::unordered_map<unsigned int, OF_CTRL_ListenerTable>::const_iterator i = listenerTables.begin();
            i != listenerTables.end(); ++i)
    {
        OF_CTRL_ListenerTable table = i->second;
        for (OF_CTRL_ListenerTable::const_iterator j = table.begin(); j != table.end(); ++j)
        {
            OF_CTRL_ListenerPortList llist = (*j).second;
            for (OF_CTRL_ListenerPortList::const_iterator k = llist.begin(); k != llist.end(); ++k)
            {
                EV_DETAIL << (*i).first << "   " << (*j).first << "   " << (*k).first << "   "
                        << (*k).second->insertionTime << endl;
            }
        }
    }

}

void OF_CTRL_SRPTable::clear()
{
    for (std::unordered_map<unsigned int, OF_CTRL_TalkerTable>::iterator iter = talkerTables.begin();
            iter != talkerTables.end(); ++iter)
    {
        OF_CTRL_TalkerTable table = (*iter).second;
        for (OF_CTRL_TalkerTable::const_iterator j = table.begin(); j != table.end(); ++j)
        {
            OF_CTRL_TalkerEntry *entry = (*j).second;
            delete entry;
        }
        table.clear();
    }
    for (std::unordered_map<unsigned int, OF_CTRL_ListenerTable>::iterator iter = listenerTables.begin();
            iter != listenerTables.end(); ++iter)
    {
        OF_CTRL_ListenerTable table = (*iter).second;
        for (OF_CTRL_ListenerTable::const_iterator j = table.begin(); j != table.end(); ++j)
        {
            OF_CTRL_ListenerPortList llist = (*j).second;
            for (OF_CTRL_ListenerPortList::const_iterator k = llist.begin(); k != llist.end(); ++k)
            {
                OF_CTRL_ListenerEntry *entry = (*k).second;
                delete entry;
            }
            llist.clear();
        }
        table.clear();
    }
}

void OF_CTRL_SRPTable::removeAgedEntriesIfNeeded(simtime_t now)
{
    removeAgedEntries(now);
}

void OF_CTRL_SRPTable::removeAgedEntries(simtime_t now)
{
    if(agingTime == 0) {
        return;
    }
    for (std::unordered_map<unsigned int, OF_CTRL_ListenerTable>::iterator listenerTable = listenerTables.begin();
            listenerTable != listenerTables.end(); ++listenerTable)
    {
        for (OF_CTRL_ListenerTable::iterator listenerList = (*listenerTable).second.begin();
                listenerList != (*listenerTable).second.end();)
        {
            for (OF_CTRL_ListenerPortList::iterator listenerEntry = (*listenerList).second.begin();
                    listenerEntry != (*listenerList).second.end();)
            {
                simtime_t entryAging = ((*listenerEntry).second->insertionTime + agingTime);
                if (now >= entryAging)
                {
                    OF_CTRL_ListenerEntry *lentry = (*listenerEntry).second;
                    (*listenerList).second.erase(listenerEntry++);
                    delete lentry;
                }
                else
                {
                    ++listenerEntry;
                }
            }
            if ((*listenerList).second.size() == 0)
            {
                (*listenerTable).second.erase(listenerList++);
            }
            else
            {
                ++listenerList;
            }
        }
    }
}

size_t OF_CTRL_SRPTable::getNumTalkerEntries()
{
    size_t entries = 0;
    for (std::unordered_map<unsigned int, OF_CTRL_TalkerTable>::const_iterator i = talkerTables.begin();
            i != talkerTables.end(); ++i)
    {
        entries += (*i).second.size();
    }
    return entries;
}
size_t OF_CTRL_SRPTable::getNumListenerEntries()
{
    size_t entries = 0;
    for (std::unordered_map<unsigned int, OF_CTRL_ListenerTable>::const_iterator i = listenerTables.begin();
            i != listenerTables.end(); ++i)
    {
        for (OF_CTRL_ListenerTable::const_iterator j = (*i).second.begin(); j != (*i).second.end(); ++j)
        {
            entries += (*j).second.size();
        }
    }
    return entries;
}



OF_CTRL_SRPTable::~OF_CTRL_SRPTable()
{
    clear();
}

string OF_CTRL_SRPTable::exportToXML() {
    ostringstream oss;
    string tab = "    ";
    //export talkerTables:
    for(auto talkerTableIter =talkerTables.begin();talkerTableIter != talkerTables.end();++talkerTableIter){
        //one table / vlan
        oss << tab << "<talkerTable vlan_id=\"" << (*talkerTableIter).first << "\">" << endl;
        for(auto talkerEntryIter = talkerTableIter->second.begin();talkerEntryIter != talkerTableIter->second.end();++talkerEntryIter){
            oss << tab << tab << "<talkerEntry";
            oss << " stream_id=\"" << (*talkerEntryIter).first << "\"";
            OF_CTRL_TalkerEntry* talker = talkerEntryIter->second;
            oss << " srClass=\"" << SR_CLASStoString[talker->srClass] << "\"";
            oss << " address=\"" << talker->address.str() << "\"";
            oss << " port=\"" << talker->port << "\"";
            oss << " framesize=\"" << talker->framesize << "\"";
            oss << " intervalFrames=\"" << talker->intervalFrames << "\"";
            oss << " />" << endl;
        }
        oss << tab << "</talkerTable>" << endl;
    }

    //export listenerTables:
    for(auto listenerTableIter =listenerTables.begin();listenerTableIter != listenerTables.end();++listenerTableIter){
        //one table / vlan
        oss << tab << "<listenerTable vlan_id=\"" << (*listenerTableIter).first << "\">" << endl;
        for(auto listenersIter = listenerTableIter->second.begin();listenersIter != listenerTableIter->second.end();++listenersIter){
            oss << tab << tab << "<listeners stream_id=\"" << (*listenersIter).first << "\">" << endl;
            for(auto listenerEntryIter = listenersIter->second.begin();listenerEntryIter != listenersIter->second.end();++listenerEntryIter){
                oss << tab << tab << tab << "<listenerEntry ";
                oss << " port=\"" << (*listenerEntryIter).first << "\" ";
                oss << " />" << endl;
            }
            oss << tab << tab << "</listeners>" << endl;
        }
        oss << tab << "</listenerTable>" << endl;
    }

    //end srp table
    return oss.str();
}

bool OF_CTRL_SRPTable::importFromXML(cXMLElement* xml, Switch_Info* swinfo) {
    bool updated = false;

    //get talker tables
    omnetpp::cXMLElementList talkerTablesXML = xml->getChildrenByTagName(
            "talkerTable");
    for(auto talkerTableIter =talkerTablesXML.begin();talkerTableIter != talkerTablesXML.end();++talkerTableIter){
        if(const char* value = (*talkerTableIter)->getAttribute("vlan_id")){
            uint16_t vlan_id = atoi(value);
            //get talker entries
            omnetpp::cXMLElementList talkerEntriesXML = (*talkerTableIter)->getChildrenByTagName("talkerEntry");
            for(auto talkerEntryIter = talkerEntriesXML.begin();talkerEntryIter != talkerEntriesXML.end();++talkerEntryIter){
                //check if all values are set and get them step by step.
                if(const char* value = (*talkerEntryIter)->getAttribute("stream_id")){
                    uint64_t stream_id = atoi(value);

                    if(const char* value = (*talkerEntryIter)->getAttribute("srClass")){
                        SR_CLASS srClass;
                        if (strcmp(value, "A")){
                            srClass = SR_CLASS::A;
                        } else if (strcmp(value, "B")){
                            srClass = SR_CLASS::B;
                        } else {
                            break;
                        }

                        if(const char* value = (*talkerEntryIter)->getAttribute("address")){
                            inet::MACAddress address = inet::MACAddress(value);
                            if(address.isUnspecified()){
                                break;
                            }

                            if(const char* value = (*talkerEntryIter)->getAttribute("port")){
                                int port = atoi(value);

                                if(const char* value = (*talkerEntryIter)->getAttribute("framesize")){
                                    size_t framesize = atoi(value);

                                    if(const char* value = (*talkerEntryIter)->getAttribute("intervalFrames")){
                                        uint16_t intervalFrames = atoi(value);

                                        //all values are set correctly --> insert talker.
                                        updateTalkerWithStreamId(stream_id, swinfo, port, address, srClass, framesize, intervalFrames, vlan_id);
                                        updated = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    //get talker tables
    omnetpp::cXMLElementList listenerTablesXML = xml->getChildrenByTagName(
            "listenerTable");
    for(auto listenerTableIter =listenerTablesXML.begin();listenerTableIter != listenerTablesXML.end();++listenerTableIter){
        if(const char* value = (*listenerTableIter)->getAttribute("vlan_id")){
            uint16_t vlan_id = atoi(value);
            //get listeners streamid
            omnetpp::cXMLElementList listenersXML = (*listenerTableIter)->getChildrenByTagName("listeners");
            for(auto listenersIter =listenersXML.begin();listenersIter != listenersXML.end();++listenersIter){
                if(const char* value = (*listenersIter)->getAttribute("stream_id")){
                    uint64_t stream_id = atoi(value);

                    //get listener entries
                    omnetpp::cXMLElementList listenerEntriesXML = (*listenersIter)->getChildrenByTagName("listenerEntry");
                    for(auto listenerEntryIter = listenerEntriesXML.begin();listenerEntryIter != listenerEntriesXML.end();++listenerEntryIter){
                        if(const char* value = (*listenerEntryIter)->getAttribute("port")){
                            int port = atoi(value);

                            //all values are set correctly --> insert listener.
                            updateListenerWithStreamId(stream_id, swinfo, port, vlan_id);
                            updated = true;
                        }
                    }
                }
            }
        }
    }

    return updated;
}

} /*end namespace ofp*/
