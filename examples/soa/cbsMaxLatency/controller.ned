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

package sdn4core.examples.soa.cbsMaxLatency;

import sdn4core.controller.tsn.TSN_NC_OF_Controller;

module Controller extends TSN_NC_OF_Controller
{
    parameters:
        serviceTime = 100us;
        OF_Controller.parallelProcessing = true;
        numControllerApps = 3;
        controllerApps[0].typename = "LearningControllerApp";
        controllerApps[0].packetFilterBlacklist = "etherType=0x88CC;udpSrc=30490;ipProto=17";
        controllerApps[0].matchL2Src = false;
        controllerApps[0].matchL2Type = true;
//        controllerApps[0].configXML = xmldoc("controllerconfig.xml");
        controllerApps[0].matchAll = false;
        controllerApps[1].typename = "LLDPControllerApp";
		controllerApps[2].typename = "SomeipSDControllerApp";       
        controllerApps[2].streamIntervalAsCMI = false;
        controllerApps[2].pcpCMI = {7:125us};
}
