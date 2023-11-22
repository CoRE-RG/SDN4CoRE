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

#include "sdn4core/controllerState/services/SomeipServiceTable.h"

#include <algorithm>

using namespace std;
using namespace inet;
using namespace openflow;
using namespace CoRE4INET;

namespace SDN4CoRE {

Define_Module(SomeipServiceTable);


SomeipServiceTable::SomeipServiceTable() {
}

SomeipServiceTable::~SomeipServiceTable() {
    clearTable();
}

bool SomeipServiceTable::loadConfig(cXMLElement* configuration) {
    return loadConfigForSwitch("", configuration);
}

bool SomeipServiceTable::loadConfigForSwitch(const std::string& swMacAddr,
        cXMLElement* configuration) {
    Enter_Method
    ("loadConfig");
    bool changed = false;
    return changed;
}

void SomeipServiceTable::dumpConfigToStream(std::ostream& stream, int indentTabs) {
    Enter_Method
    ("dumpConfigToStream");
    string indent = string(indentTabs, '\t');
    stream << indent << "<serviceTable>" << endl;
    stream << indent << "</serviceTable>" << endl;
}

void SomeipServiceTable::clearTable() {
    
}

void SomeipServiceTable::initialize() {
    agingTime = par("agingTime");
    lastPurge = SIMTIME_ZERO;
    WATCH_PTRMAP(hostsByMac);
}

void SomeipServiceTable::handleMessage(cMessage* msg) {
    throw cRuntimeError("This module doesn't process messages");
}

void SomeipServiceTable::refreshDisplay() const {
    char buf[50];
    sprintf(buf, "Hosts: %d", getHostCount());
    getDisplayString().setTagArg("t", 0, buf);
}

} /*end namespace SDN4CoRE*/

