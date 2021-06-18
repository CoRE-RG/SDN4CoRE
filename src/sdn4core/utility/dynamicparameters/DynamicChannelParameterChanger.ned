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

package sdn4core.utility.dynamicparameters;

//
// Changes a parameter in one or multiple channels to a new value 
// at the specified time, and resets the value later if enabled
//
simple DynamicChannelParameterChanger extends DynamicParameterChanger 
{
    parameters:
        @class(SDN4CoRE::DynamicChannelParameterChanger);
        //gate name of the channel connected to the component $i and $o will also be accepted
        //if not specified both directions will be updated
        string gateAtComponent = default(""); 
        int gateIdx = default(-1);//set if gate is a vector and only a channel at a specific gate idx should be changed
        bool fullVector = default(false); // if true all channels connected to the gate vector will be changed
}
