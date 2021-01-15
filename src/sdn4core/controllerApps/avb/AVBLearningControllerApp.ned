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

package sdn4core.controllerApps.avb;

import openflow.controllerApps.AbstractControllerApp;

//
// AVBLearningControllerApp is an SDN controller application that handles 
// avb real time traffic as well as best effort MAC switching.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple AVBLearningControllerApp like AbstractControllerApp
{
    parameters:
        @class(SDN4CoRE::AVBLearningControllerApp);
        @display("i=block/app");
		//hard timeout for flow entries
        int flowModHardTimeOut = default(0);
        //idle timeout for flow entries
        int flowModIdleTimeOut = default(10);
        //path to the srp table module.
        string srpTable = default("^.srpTable");
        //offline configuration containing mac and srp information.
        xml configXML = default(xml("<root/>"));
        int priority = default(1);
}
