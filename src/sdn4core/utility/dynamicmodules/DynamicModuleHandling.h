//
// c Timo Haeckel, for HAW Hamburg
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

#ifndef SDN4CORE_UTILITY_DYNAMICMODULES_DYNAMICMODULEHANDLING_H_
#define SDN4CORE_UTILITY_DYNAMICMODULES_DYNAMICMODULEHANDLING_H_

#include <omnetpp.h>

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Creates a module by calling createDynamicModule and finalizes it if the
 * creation was successful by calling finalizeModuleAndSchedule.
 *
 * @param nedModulePath     The path to the ned file.
 * @param name              The name of the submodule to create in the parent module.
 * @param parentModule      The instance of the parent module.
 * @param isVector          True if the dynamic module is a vector element.
 * @param at                The SimTime to schedule the module creation, default now.
 * @return
 */
cModule* createFinalizeAndScheduleDynamicModule(const char* nedModulePath,
        const char* name, cModule* parentModule, bool isVector, SimTime at = simTime());

/**
 * Creates a new submodule which can be a vector with the given name in the parent
 * module of module type specified in nedModulePath.
 *
 * @param nedModulePath     The path to the ned file.
 * @param name              The name of the submodule to create in the parent module.
 * @param parentModule      The instance of the parent module.
 * @param isVector          True if the dynamic module is a vector element.
 * @return
 */
cModule* createDynamicModule(const char* nedModulePath,
        const char* name, cModule* parentModule, bool isVector);

/**
 * Calls finalizeParameters();buildInside();callInitialize();scheduleStart(at);
 *
 * for the given module.
 * @param module    the module to finalize.
 * @param at        the SimTime to schedule default now.
 */
void finalizeModuleAndSchedule(cModule* module, SimTime at = simTime());

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_UTILITY_DYNAMICMODULES_DYNAMICMODULEHANDLING_H_ */
