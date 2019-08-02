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
// c Timo Haeckel, for HAW Hamburg
// 

package sdn4core.utility.visual;

//
// The Color changing Node provides functions to set the Color and Opacity during runtime. 
// It either can be used as a simple Node to Display Colors in the Network or extended to 
// inherit color changing functionality.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple ColorChangingNode
{
    parameters:
        @class(SDN4CoRE::ColorChangingNode);
        //
        // The color loaded on startup. 
        // An empty string will not update the color.
        //
        string initColor = default("");
        //
        // The opacity loaded on startup. 
        // An empty string will not update the opacity.
        //
        string initOpacity = default("");
}
