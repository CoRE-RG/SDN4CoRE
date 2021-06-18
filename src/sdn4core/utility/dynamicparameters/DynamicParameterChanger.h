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

#ifndef __SDN4CORE_DYNAMICPARAMETERCHANGER_H_
#define __SDN4CORE_DYNAMICPARAMETERCHANGER_H_

#include <omnetpp.h>
#include <map>
#include <vector>
#include <string>
using namespace omnetpp;

namespace SDN4CoRE{

/**
 * Module that changes a parameter in one or multiple components to a new value
 * at the specified time, and resets the value later if enabled
 */
class DynamicParameterChanger : public cSimpleModule
{
protected:
    /**
     * Caches the components to be changed and the initial state of the parameters
     */
    std::map<cComponent*, std::string> _componentsToChange;

    /**
     * Caches the parameter to be changed for the componentes
     */
    std::string _parToChange;

    /**
     * Caches the value to be set for the parameter
     */
    std::string _newValue;

protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override;
    virtual void handleMessage(cMessage *msg) override;

    virtual void fillComponentToChange(std::vector<std::string>& paths);

    virtual void changePars();
    virtual void resetPars();

};

} // namespace SDN4CoRE

#endif //__SDN4CORE_DYNAMICPARAMETERCHANGER_H_
