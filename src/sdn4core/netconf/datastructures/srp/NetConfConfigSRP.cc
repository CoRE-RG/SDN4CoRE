//
// c Tobias Haugg, for HAW Hamburg
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

#include <sdn4core/netconf/datastructures/srp/NetConfConfigSRP.h>


namespace SDN4CoRE {

SDN4CoRE::NetConfConfigSRP::NetConfConfigSRP(const NetConfConfigSRP& old_obj) {
   for( auto listener : old_obj._listeners){
       CoRE4INET::SRPTable::ListenerEntry newListener = *dynamic_cast<CoRE4INET::SRPTable::ListenerEntry*>(listener.dup());
       _listeners.push_back(newListener);
   }
   for( auto talker : old_obj._talkers){
           CoRE4INET::SRPTable::TalkerEntry newTalker = *dynamic_cast<CoRE4INET::SRPTable::TalkerEntry*>(talker.dup());
       _talkers.push_back(newTalker);
   }
}

unsigned int SDN4CoRE::NetConfConfigSRP::getByteSize() {
    return ( sizeof(CoRE4INET::SRPTable::TalkerEntry) * _talkers.size()) + ( sizeof(CoRE4INET::SRPTable::ListenerEntry) * _listeners.size());
}

NetConfConfig_Base* SDN4CoRE::NetConfConfigSRP::dup() const {
    return new NetConfConfigSRP(*this);
}

void SDN4CoRE::NetConfConfigSRP::setTalkerEntries(
        std::vector<CoRE4INET::SRPTable::TalkerEntry> talkers) {
    _talkers = talkers;
}

void SDN4CoRE::NetConfConfigSRP::setListenerEntries(
        std::vector<CoRE4INET::SRPTable::ListenerEntry> listeners) {
    _listeners = listeners;
}

std::vector<CoRE4INET::SRPTable::TalkerEntry> SDN4CoRE::NetConfConfigSRP::getTalkerEntries() {
    return _talkers;
}

std::vector<CoRE4INET::SRPTable::ListenerEntry> SDN4CoRE::NetConfConfigSRP::getListenerEntries() {
    return _listeners;
}

void SDN4CoRE::NetConfConfigSRP::addTalkerEntry(
        CoRE4INET::SRPTable::TalkerEntry talker) {
    _talkers.push_back(talker);
}

void SDN4CoRE::NetConfConfigSRP::addListenerEntry(
        CoRE4INET::SRPTable::ListenerEntry listener) {
    _listeners.push_back(listener);
}

} /* namespace SDN4CoRE */
