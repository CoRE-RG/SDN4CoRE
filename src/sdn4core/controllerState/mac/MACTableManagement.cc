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

#include <sdn4core/controllerState/mac/MACTableManagement.h>

using namespace inet;
using namespace std;
using namespace openflow;

namespace SDN4CoRE {

Define_Module(FriendMACAddressTable);

Define_Module(MACTableManagement);

bool MACTableManagement::update(openflow::Switch_Info* sw_info,
        inet::MACAddress source, uint32_t in_port, int vlan_id) {
    Enter_Method ("update");
    FriendMACAddressTable* lookupTable = getOrCreateManagedState(
            sw_info->getMacAddress());
    return lookupTable->updateTableWithAddress(in_port, source, vlan_id);
}

int MACTableManagement::lookup(openflow::Switch_Info* sw_info,
        inet::MACAddress destination, int vlan_id) {
    Enter_Method ("lookup");
    if (FriendMACAddressTable* lookupTable = getManagedState(
            sw_info->getMacAddress())) {
        return lookupTable->getPortForAddress(destination, vlan_id);
    }
    return MAC_MANAGER_OUTPORT_FLOOD;
}

bool MACTableManagement::loadConfig(cXMLElement* configuration) {
    Enter_Method ("loadConfig");
    bool changed = false;
    if (configuration) {
        cXMLElement* macManagerXML;
        if (configuration->isName("macManager")) {
            macManagerXML = configuration;
        } else {
            macManagerXML = configuration->getFirstChildWithTag("macManager");
        }
        if (macManagerXML) {
            cXMLElementList switchesXML = macManagerXML->getChildrenByTagName(
                    "mactable");
            for (cXMLElement* switchXML : switchesXML) {
                if (const char * swMacAddr = switchXML->getAttribute(
                        "switch_id")) {
                    cXMLElementList macTableXML =
                            switchXML->getChildrenByTagName("entry");
                    if (!macTableXML.empty()) {
                        for (size_t i = 0; i < macTableXML.size(); i++) {
                            MACAddress mac = MACAddress(
                                    macTableXML[i]->getAttribute("mac"));
                            if (!mac.isUnspecified()) {
                                if (const char * portC =
                                        macTableXML[i]->getAttribute("port")) {
                                    int port = atoi(portC);
                                    int vlanId = 0;
                                    if (const char * vlanIdC =
                                            macTableXML[i]->getAttribute(
                                                    "vlan_id")) {
                                        vlanId = atoi(vlanIdC);
                                    }
                                    FriendMACAddressTable* lookupTable =
                                            this->getOrCreateManagedState(
                                                    string(swMacAddr));
                                    changed |=
                                            lookupTable->updateTableWithAddress(
                                                    port, mac, vlanId);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return changed;
}

void MACTableManagement::dumpConfigToStream(std::ostream& stream,
        int indentTabs) {
    Enter_Method ("dumpConfigToStream");
    string indent = string(indentTabs, '\t');
    stream << indent << "<macManager>" << endl;
    const map<string, FriendMACAddressTable*>& managedStates =
            getAllManagedStates();
    for (auto managedTableEntry : managedStates) {
        stream << string(indentTabs + 1, '\t') << "<mactable switch_id=\""
                << managedTableEntry.first << "\">" << endl;
        FriendMACAddressTable* managedTable = managedTableEntry.second;
        for (auto vlanTables : managedTable->vlanAddressTable) {
            for (auto entry : *(vlanTables.second)) {
                stream << string(indentTabs + 2, '\t') << "<entry ";
                stream << "vlan_id=\"" << vlanTables.first << "\" ";
                stream << "mac=\"" << entry.first.str() << "\" ";
                stream << "port=\"" << entry.second.portno << "\" ";
                stream << "/>" << endl;
            }
        }
        stream << string(indentTabs + 1, '\t') << "</mactable>" << endl;
    }
    stream << indent << "</macManager>" << endl;
}

void MACTableManagement::onCreateManagedState(
        FriendMACAddressTable* managedState, string& swMacAddr) {
    ControllerStateManagementBase<FriendMACAddressTable>::onCreateManagedState(
            managedState, swMacAddr);
    managedState->setAgingTime(this->par("agingTime").doubleValue());
}

} /*end namespace SDN4CoRE*/
