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

package sdn4core.examples.IEEE8021Qbv.small_network_ofnc;

import sdn4core.switch.ieee8021qbv.IEEE8021QbvOFNCSwitch;

//
// Switch1: configuration in switch1.ini
//
module Switch1 extends IEEE8021QbvOFNCSwitch
{
    @display("i=device/switch;i2=OpenFlow-Logo-small");
}
