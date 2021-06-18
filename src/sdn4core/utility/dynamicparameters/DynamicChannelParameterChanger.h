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

#ifndef __SDN4CORE_DYNAMICCHANNELPARAMETERCHANGER_H_
#define __SDN4CORE_DYNAMICCHANNELPARAMETERCHANGER_H_

#include <sdn4core/utility/dynamicparameters/DynamicParameterChanger.h>

namespace SDN4CoRE{

/**
 * Module that changes a parameter of the channel to a new value
 * at the specified time, and resets the value later if enabled
 */
class DynamicChannelParameterChanger : public DynamicParameterChanger
{
private:

protected:
    virtual void fillComponentToChange(std::vector<std::string>& paths) override;
    virtual cComponent* getChannelForGate(cGate* gate);

public:

};

} // namespace SDN4CoRE

#endif //__SDN4CORE_DYNAMICCHANNELPARAMETERCHANGER_H_
