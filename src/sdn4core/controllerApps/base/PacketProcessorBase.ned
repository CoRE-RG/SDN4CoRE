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

package sdn4core.controllerApps.base;

import openflow.controllerApps.AbstractControllerApp;

//
// Base controller application for packet processors.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple PacketProcessorBase like AbstractControllerApp
{
    parameters:
		//hard timeout for flow entries in seconds
        int flowModHardTimeOut = default(0);
        //idle timeout for flow entries in seconds
        int flowModIdleTimeOut = default(10);
        //offline configuration containing mac and srp information.
        xml configXML = default(xml("<root/>"));
        // write configuration into the given config file that can be fed back
        string dumpConfig = default("");
        // priority of a flow created by this application
        int priority = default(1);
}
