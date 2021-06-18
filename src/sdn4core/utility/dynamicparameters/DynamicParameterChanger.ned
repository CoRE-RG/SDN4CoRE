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
// Changes a parameter in one or multiple components to a new value 
// at the specified time, and resets the value later if enabled
//
simple DynamicParameterChanger
{
    parameters:
        @class(SDN4CoRE::DynamicParameterChanger);
        @display("i=block/cogwheel_s");
        string parToChange = default("");
        //The new value as a string that will be parsed as within ned and ini files.
        string newValue = default("");
        //Path to the components to be changed separated with ";"
        string pathToComponentsToChange = default("");
        double changeAt @unit(s) = default (0s);
        double resetAt @unit(s) = default (0s);
        bool enableReset = default(resetAt>0s);
}
