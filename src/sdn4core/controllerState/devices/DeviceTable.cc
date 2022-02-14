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

#include <sdn4core/controllerState/devices/DeviceTable.h>

using namespace inet;
using namespace std;
using namespace openflow;

namespace SDN4CoRE {

Define_Module(DeviceTable);

bool DeviceTable::addNetworkDevice(Switch_Info* sw_info) {
    bool updated = false;
    string swMacAddr = sw_info->getMacAddress();
    cModule* switchModule = getSwitch(swMacAddr);
    if (!switchModule) {
        switchModule = createSwitch(swMacAddr);
        updated = true;
    }
    for (int i = 0; i < sw_info->getNumOfPorts(); i++) {
        if (!getSwitchPort(swMacAddr, i, switchModule)) {
            createSwitchPort(swMacAddr, i, switchModule);
            updated = true;
        }
    }
    return updated;
}

int DeviceTable::getDeviceCount() {
    return cachedSwitches.size();
}

bool DeviceTable::linkNetworkDevices(std::string& swMacFirst,
        int portFirst, std::string& swMacSecond, int portSecond) {
    bool updated = false;
    SwitchPort first (swMacFirst, portFirst);
    SwitchPort second (swMacSecond, portSecond);
    if(links.find(first) != links.end() || links.find(second) != links.end()) {
        updated = true;
    }
    links[first] = second;
    links[second] = first;
    return updated;
}

bool DeviceTable::isLinkedToNetworkDevice(std::string& swMac,
        int port) {
    return links.find(SwitchPort(swMac,port)) != links.end();
}

SwitchPort DeviceTable::getLinkedSwitchPort(std::string& swMac, int port) {
    auto iter = links.find(SwitchPort(swMac,port));
    if (iter != links.end()) {
        return iter->second;
    }
    return SwitchPort();
}

vector<DeviceLink_t> DeviceTable::getDeviceLinksForSwitch(
        std::string& swMac) {
    vector<DeviceLink_t> knownLinks;
    for (auto link : links) {
        if(link.first.switchId == swMac) {
            DeviceLink_t deviceLink (link.first, link.second);
            knownLinks.push_back(deviceLink);
        }
    }
    return knownLinks;
}

bool DeviceTable::loadConfig(cXMLElement* configuration) {
    Enter_Method
    ("loadConfig");
    bool changed = false;
    if (configuration) {
        cXMLElement* deviceTableXML;
        if (configuration->isName("deviceTable")) {
            deviceTableXML = configuration;
        } else {
            deviceTableXML = configuration->getFirstChildWithTag(
                    "deviceTable");
        }
        if (deviceTableXML) {
            cXMLElementList linksXML = deviceTableXML->getChildrenByTagName(
                    "deviceLink");
            for (cXMLElement* linkXML : linksXML) {
                if (const char * firstSwMac = linkXML->getAttribute(
                        "firstSwMac")) {
                    if (const char * firstSwPort = linkXML->getAttribute(
                            "firstSwPort")) {
                        if (const char * secondSwMac = linkXML->getAttribute(
                                "secondSwMac")) {
                            if (const char * secondSwPort =
                                    linkXML->getAttribute("secondSwPort")) {
                                int firstPort = atoi(firstSwPort);
                                int secondPort = atoi(secondSwPort);
                                string firstMac = firstSwMac;
                                string secondMac = secondSwMac;
                                cModule* swModule = getOrCreateSwitch(firstSwMac);
                                getOrCreateSwitchPort(firstSwMac,firstPort,swModule);
                                swModule = getOrCreateSwitch(secondSwMac);
                                getOrCreateSwitchPort(secondSwMac,secondPort,swModule);
                                changed = true;
                                linkNetworkDevices(firstMac, firstPort, secondMac, secondPort);
                            }
                        }
                    }
                }
            }
        }
    }
    return changed;
}

bool DeviceTable::loadConfigForSwitch(const std::string& swMacAddr,
        cXMLElement* configuration) {
    Enter_Method
    ("loadConfig");
    bool changed = false;
    if (configuration) {
        cXMLElement* deviceTableXML;
        if (configuration->isName("deviceTable")) {
            deviceTableXML = configuration;
        } else {
            deviceTableXML = configuration->getFirstChildWithTag(
                    "deviceTable");
        }
        if (deviceTableXML) {
            cXMLElementList linksXML = deviceTableXML->getChildrenByTagName(
                    "deviceLink");
            for (cXMLElement* linkXML : linksXML) {
                if (const char * firstSwMac = linkXML->getAttribute(
                        "firstSwMac")) {
                    if (const char * secondSwMac = linkXML->getAttribute(
                            "secondSwMac")) {
                        if (strcmp(firstSwMac, swMacAddr.c_str()) == 0
                                || strcmp(secondSwMac, swMacAddr.c_str())
                                        == 0) {
                            if (const char * firstSwPort =
                                    linkXML->getAttribute("firstSwPort")) {
                                if (const char * secondSwPort =
                                        linkXML->getAttribute("secondSwPort")) {
                                    int firstPort = atoi(firstSwPort);
                                    int secondPort = atoi(secondSwPort);
                                    string firstMac = firstSwMac;
                                    string secondMac = secondSwMac;
                                    cModule* swModule = getOrCreateSwitch(firstSwMac);
                                    getOrCreateSwitchPort(firstSwMac,firstPort,swModule);
                                    swModule = getOrCreateSwitch(secondSwMac);
                                    getOrCreateSwitchPort(secondSwMac,secondPort,swModule);
                                    changed = true;
                                    linkNetworkDevices(firstMac, firstPort, secondMac, secondPort);
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

void DeviceTable::dumpConfigToStream(std::ostream& stream,
        int indentTabs) {
    Enter_Method
    ("dumpConfigToStream");
    string indent = string(indentTabs, '\t');
    stream << indent << "<deviceTable>" << endl;
    vector<DeviceLink_t> links = getAllDeviceLinks();
    for (auto link : links) {
        stream << string(indentTabs + 2, '\t') << "<deviceLink ";
        stream << "firstSwMac=\"" << link.first.switchId << "\" ";
        stream << "firstSwPort=\"" << link.first.port << "\" ";
        stream << "secondSwMac=\"" << link.second.switchId << "\" ";
        stream << "secondSwPort=\"" << link.second.port << "\" ";
        stream << "/>" << endl;
    }
    stream << indent << "</deviceTable>" << endl;
}

vector<DeviceLink_t> DeviceTable::getAllDeviceLinks() {
    vector<DeviceLink_t> knownLinks;
    auto linksCopy = links; // copied known links
    for (auto link : linksCopy) {
        DeviceLink_t deviceLink (link.first, link.second);
        linksCopy.erase(link.second); // ignore other direction
        knownLinks.push_back(deviceLink);
    }
    return knownLinks;
}

void DeviceTable::initialize() {
    ControllerStateManagementBase::initialize();
    WATCH_MAP(links);
    WATCH_PTRMAP(cachedSwitches);
}

} /*end namespace SDN4CoRE*/
