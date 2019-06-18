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

package sdn4core.netconf.server.base;

import sdn4core.netconf.server.INetConfConfigDataStore;

//
// TODO auto-generated module
//
simple NetConfConfigDataStoreBase like INetConfConfigDataStore
{
    parameters:
        // the name of this configuration
        // one store must be named running other meaningful names are candidate or startup
        string name = default("");
        
        // if true the running config will be marked green, candidate configs yellow and inactive red.
        bool displayStatus = default(true);
        
    gates:
        // input for netconf requests
        input requestIn @directIn;
}
