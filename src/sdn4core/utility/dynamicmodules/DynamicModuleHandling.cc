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

#include <sdn4core/utility/dynamicmodules/DynamicModuleHandling.h>

#include <string>

using namespace std;

namespace SDN4CoRE {

cRuntimeError createErrorMessage(const char* name, const char* nedModulePath, const char* reason) {
    string msg = "Cannot create dynamic module \"";
    msg += name;
    msg += "\" of type  \"";
    msg += nedModulePath;
    msg += ": ";
    msg += reason;
    return cRuntimeError("%s",msg.c_str());
}

cModule* createFinalizeAndScheduleDynamicModule(const char* nedModulePath,
        const char* name, cModule* parentModule, bool isVector, SimTime at){
    cModule* module = createDynamicModule(nedModulePath, name, parentModule, isVector);
    if(module){
        finalizeModuleAndSchedule(module,at);
    } else {
        throw createErrorMessage(name, nedModulePath, "Module creation failed.");
    }

    return module;
}

void finalizeModuleAndSchedule(cModule* module, SimTime at) {
    // 3. Set up its parameters and gate sizes as needed;
    module->finalizeParameters();
    // 4. Tell the (possibly compound) module to recursively create its internal submodules and connections;
    module->buildInside();
    module->callInitialize();
    // 5. Schedule activation message(s) for the new simple module(s).
    module->scheduleStart(at);
}

cModule* createDynamicModule(const char* nedModulePath,
        const char* name, cModule* parentModule, bool isVector) {
    // 0. check parameters
    if(!nedModulePath || !name || !parentModule)
    {
        throw cRuntimeError("Cannot create dynamic module: Missing Parameters.");
    }
    // 1. Find the factory object;
    cModuleType * moduleType = cModuleType::get(nedModulePath);
    if(!moduleType)
    {
        throw createErrorMessage(name, nedModulePath, "Can't find module type at given path.");
    }
    // check whether the module exists already
    bool existsAsVector = parentModule->hasSubmoduleVector(name);
    bool existsAsModule = parentModule->hasSubmodule(name);
    if (existsAsModule && isVector)
    {
        throw createErrorMessage(name, nedModulePath, "Should be vector but already exists as non vector type.");
    }
    else if (existsAsModule && !isVector)
    {
        throw createErrorMessage(name, nedModulePath, "SubModule already exists in ParentModule.");
    }
    else if(existsAsVector && !isVector)
    {
        throw createErrorMessage(name, nedModulePath, "Should be non vector but already exists as vector type.");
    }
    // 2. Create the module;
    cModule* module = nullptr;
    if(isVector){
        if(existsAsVector)
        {
            int size = getDynamicModuleVectorSize(name, parentModule);
            parentModule->setSubmoduleVectorSize(name, size + 1);
            module = moduleType->create(name, parentModule, size);
        }
        else
        {
            parentModule->addSubmoduleVector(name,1);
            module = moduleType->create(name, parentModule, 0);
        }
    }
    else
    {
        module = moduleType->create(name, parentModule);
    }
    return module;
}

int getDynamicModuleVectorSize(const char* name,
        cModule* parentModule) {
//    no longer required as this is checked beforehand
//    if(parentModule->getSubmodule(name)){
//        return -1;
//    }
    int size = 0;
    for (; parentModule->getSubmodule(name,size); size++){};
    return size;
}

} /* namespace SDN4CoRE */
