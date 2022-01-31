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

package sdn4core.controllerState.hosts;

//
// Host Table for controller state holding entries for all hosts in the network 
// 
// @author Timo Haeckel, for HAW Hamburg
//
simple HostTable
{
    parameters:
        @class(SDN4CoRE::HostTable);
        @display("i=block/table2,green");
        double agingTime @unit("s") = default(0s); // default never forget entries
}
