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

#ifndef __SDN4CORE_CONTROLLERSTATEMANAGEMENTBASE_H_
#define __SDN4CORE_CONTROLLERSTATEMANAGEMENTBASE_H_

#include <omnetpp.h>

#include <sdn4core/controllerState/base/PortModule.h>

//openflow
#include "openflow/openflow/controller/Switch_Info.h"

using namespace omnetpp;

namespace SDN4CoRE{

/**
 * SimpleModule to manage controller state @see~ControllerState
 */
class ControllerStateManagementBase: public cSimpleModule {
protected:

    /**
     * Checks weather a given switch is already present else create
     * the compound module.
     *
     * @param swinfo The info of the switch to look for.
     * @return the compound module that was created.
     */
    cModule* checkOrCreateSwitch(openflow::Switch_Info* swinfo);

    /**
     * Checks weather a portmodule for the given switch port is already present
     * if not the module will be dynamically created.
     *
     * @param swinfo The info of the switch to look for.
     * @return the compound module that was created.
     */
    PortModule* checkOrCreateSwitchPort(openflow::Switch_Info* swinfo, int port);

    /**
     * Checks weather the state module already exists for a
     * given switch if not the module will be dynamically created.
     *
     * @param swinfo The info of the switch to look for.
     * @return the managed state module that was found/created
     */
    cModule* checkOrCreateManagedPerSwitchState(openflow::Switch_Info* swinfo);

    /**
     * Checks weather the manged state module already exists for a
     * given switch if not the module will be dynamically created.
     *
     * @param swinfo The info of the switch to look for.
     * @paran stateName The name of the switch state to look for
     * @return the managed state module that was found/created
     */
    cModule* checkOrCreatePerSwitchState(openflow::Switch_Info* swinfo, const char* stateModulePath, const char* stateName);

    /**
     * Finds switch state compound module containing all switch state modules.
     *
     * @param swinfo The info of the switch to look for.
     * @return the switch state compound module if found, else nullptr;
     */
    cModule* findSwitchState(openflow::Switch_Info* swinfo);

    /**
     * Finds the managed switch state for the given switch.
     *
     * @param swinfo The info of the switch to look for.
     * @return the switch port module if found, else nullptr
     */
    PortModule* findSwitchPort(openflow::Switch_Info* swinfo, int port);

    /**
     * Finds the managed switch state for the given switch.
     *
     * @param swinfo The info of the switch to look for.
     * @return the managed state module if found, else nullptr
     */
    cModule* findManagedPerSwitchState(openflow::Switch_Info* swinfo);

    /**
     * Finds the managed switch state for the given switch.
     *
     * @param swinfo The info of the switch to look for.
     * @paran stateName The name of the switch state to look for
     * @return the state module if found, else nullptr
     */
    cModule* findPerSwitchState(openflow::Switch_Info* swinfo, const char* stateName, int index=-1);


};

} // End namespace SDN4CoRE

#endif
