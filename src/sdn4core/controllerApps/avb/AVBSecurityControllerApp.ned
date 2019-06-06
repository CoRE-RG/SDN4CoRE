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

//
// AVBSecurityControllerApp is an SDN controller application that handles 
// realtime traffic as well as best effort mac switching.
// It extends the functionality of the AVBLearningControllerApp and enables security counter measures.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple AVBSecurityControllerApp extends AVBLearningControllerApp
{
    parameters:
        @class(SDN4CoRE::AVBSecurityControllerApp);
        int NADSPort = default(-1); // NADSPort == -1 deactivates NADS connection.
		//The MAC address of the controller specified in NADS messages. Does not need to be the actuall mac address of the controller.
        string controllerMAC = default("auto");
        //The traffic light displays the security status of the network and can be connected.
        string pathToTrafficLight = default("");
        //Allow new flows to be inserted
        bool allowNewFlows = default(true);
        //specifically allow or denie ARP messages.
        bool allowARP = default(true);
        //specifically allow or denie SRP messages.
        bool allowSRP = default(true);
}
