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

import sdn4core.controllerApps.base.LearningControllerApp;

//
// AVBLearningControllerApp is an SDN controller application that handles 
// avb real time traffic as well as best effort MAC switching.
//
// @warning This uses the simplified implementation of the Stream Reservation Protocol 
// from core4inet that does not use the original message format. 
//
// @author Timo Haeckel, for HAW Hamburg
//
simple AVBLearningControllerApp extends LearningControllerApp
{
    parameters:
        @class(SDN4CoRE::AVBLearningControllerApp);
        //path to the srp table module.
        string srpTable = default("^.srpTable");
}
