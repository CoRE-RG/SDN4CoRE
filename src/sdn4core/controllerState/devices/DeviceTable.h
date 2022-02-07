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

#ifndef __SDN4CORE_DEVICEMANAGER_H_
#define __SDN4CORE_DEVICEMANAGER_H_

#include <omnetpp.h>
#include <sdn4core/controllerState/base/ControllerStateManagementBase.h>
//openflow
#include "openflow/openflow/controller/Switch_Info.h"

using namespace omnetpp;

namespace SDN4CoRE {

typedef std::pair<SwitchPort_t, SwitchPort_t> DeviceLink_t;

/**
 * DeviceTable stores and manages devices and links for a controller application.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class DeviceTable: public ControllerStateManagementBase<cModule> {
public:
    /**
     * Adds a network device (switch) to the controller state and creates state modules.
     * @param sw_info       the switch to be added
     * @return True if refreshed. False if its new.
     */
    virtual bool addNetworkDevice(openflow::Switch_Info* sw_info);

    /**
     * Adds a direct link between two network devices (e.g., discovered with LLDP).
     * @param swMacFirst the first switch mac address
     * @param portFirst the port of the first switch
     * @param swMacSecond the second switch mac address
     * @param portSecond the port of the second switch
     * @return True if refreshed. False if its new.
     */
    virtual bool linkNetworkDevices(std::string& swMacFirst, int portFirst,
            std::string& swMacSecond, int portSecond);

    /**
     * Checks whether a given switch port is linked to another network
     * device or is an host access port.
     * @param swMac the switch mac address
     * @param port the port of the switch
     * @return True if linked to another network device.
     */
    virtual bool isLinkedToNetworkDevice(std::string& swMac, int port);

    /**
     * Get the linked switch port for a switch port.
     * @param swMac The switch
     * @param port The port at the switch
     * @return The linked switch port.
     */
    virtual SwitchPort_t getLinkedSwitchPort(std::string& swMac, int port);

    /**
     * Collects all known direct links between devices
     * @return
     */
    virtual std::vector<DeviceLink_t> getAllDeviceLinks();

    /**
     * Collects all known ports of the switch that are linked to other network devices.
     * @param swMac the switch mac address
     * @return A vector containing all ports linked to other network devices.
     */
    virtual std::vector<DeviceLink_t> getDeviceLinksForSwitch(std::string& swMac);

    virtual bool loadConfig(cXMLElement* configuration) override;

    virtual bool loadConfigForSwitch(const std::string& swMacAddr,
            cXMLElement* configuration) override;

    virtual void dumpConfigToStream(std::ostream& stream, int indentTabs = 0)
            override;
};

} /*end namespace SDN4CoRE*/

#endif
