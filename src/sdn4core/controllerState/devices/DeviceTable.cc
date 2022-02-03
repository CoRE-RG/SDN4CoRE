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

bool DeviceTable::linkNetworkDevices(std::string& swMacFirst,
        int portFirst, std::string& swMacSecond, int portSecond) {
    bool updated = false;
    cModule* firstSwitchModule = getOrCreateSwitch(swMacFirst);
    cModule* secondSwitchModule = getOrCreateSwitch(swMacSecond);
    PortModule* firstPortModule = getOrCreateSwitchPort(swMacFirst, portFirst,
            firstSwitchModule);
    PortModule* secondPortModule = getOrCreateSwitchPort(swMacSecond,
            portSecond, secondSwitchModule);
    updated |= firstPortModule->setDeviceLink(secondPortModule);
    updated |= secondPortModule->setDeviceLink(firstPortModule);
    return updated;
}

bool DeviceTable::isLinkedToNetworkDevice(std::string& swMac,
        int port) {
    if (PortModule* portModule = getOrCreateSwitchPort(swMac, port)) {
        return portModule->isDeviceLink();
    }
    return false;
}

std::vector<DeviceLink_t> DeviceTable::getAllDeviceLinks() {
    std::vector<DeviceLink_t> links;
    std::map<SwitchPort_t, PortModule*> switchPorts = getAllSwitchPorts();
    for (auto switchPort : switchPorts) {
        if (switchPort.second->isDeviceLink()) {
            // first remove linked port from map to prevent duplicates.
            PortModule* linkedPort = switchPort.second->getDeviceLink();
            string linkedDevice = linkedPort->getParentModule()->par(
                    "switchName").stdstringValue();
            SwitchPort_t nextDevicePort(linkedDevice, linkedPort->getPort());
            switchPorts.erase(nextDevicePort);
            // than add the link.
            DeviceLink_t link(switchPort.first, nextDevicePort);
            links.push_back(link);
        }
    }
    return links;
}

vector<DeviceLink_t> DeviceTable::getDeviceLinksForSwitch(
        std::string& swMac) {
    std::vector<DeviceLink_t> links;
    map<SwitchPort_t, PortModule*> switchPorts = getAllSwitchPorts();
    for (auto switchPort : switchPorts) {
        if (switchPort.first.first == swMac
                && switchPort.second->isDeviceLink()) {
            PortModule* linkedPort = switchPort.second->getDeviceLink();
            string linkedDevice = linkedPort->getParentModule()->par(
                    "switchName").stdstringValue();
            SwitchPort_t nextDevicePort(linkedDevice, linkedPort->getPort());
            DeviceLink_t link(switchPort.first, nextDevicePort);
            links.push_back(link);
        }
    }
    return links;
}

bool DeviceTable::loadConfig(cXMLElement* configuration) {
    Enter_Method
    ("loadConfig");
    bool changed = false;
    if (configuration) {
        cXMLElement* deviceManagerXML;
        if (configuration->isName("deviceManager")) {
            deviceManagerXML = configuration;
        } else {
            deviceManagerXML = configuration->getFirstChildWithTag(
                    "deviceManager");
        }
        if (deviceManagerXML) {
            cXMLElementList linksXML = deviceManagerXML->getChildrenByTagName(
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
                                changed = linkNetworkDevices(firstMac,
                                        firstPort, secondMac, secondPort);
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
        cXMLElement* deviceManagerXML;
        if (configuration->isName("deviceManager")) {
            deviceManagerXML = configuration;
        } else {
            deviceManagerXML = configuration->getFirstChildWithTag(
                    "deviceManager");
        }
        if (deviceManagerXML) {
            cXMLElementList linksXML = deviceManagerXML->getChildrenByTagName(
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
                                    changed = linkNetworkDevices(firstMac,
                                            firstPort, secondMac, secondPort);
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
    stream << indent << "<deviceManager>" << endl;
    vector<DeviceLink_t> links = getAllDeviceLinks();
    for (auto link : links) {
        stream << string(indentTabs + 2, '\t') << "<deviceLink ";
        stream << "firstSwMac=\"" << link.first.first << "\" ";
        stream << "firstSwPort=\"" << link.first.second << "\" ";
        stream << "secondSwMac=\"" << link.second.first << "\" ";
        stream << "secondSwPort=\"" << link.second.second << "\" ";
        stream << "/>" << endl;
    }
    stream << indent << "</deviceManager>" << endl;
}

} /*end namespace SDN4CoRE*/
