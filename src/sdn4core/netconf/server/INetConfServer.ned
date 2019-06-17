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

package sdn4core.netconf.server;

//
// Contains the common interface of a netconf server.
// This module can be connected to any Transport protocol that should be of 
// "Connection-Oriented Operation" and should provide "Authentication, 
// Integrity, and Confidentiality" as specified in Network Configuration 
// Protocol (NETCONF) RFC6241.
//
// A NetConf Server must be connected to device specific config and state datastores.
//
// @author Timo Haeckel, for HAW Hamburg
//
moduleinterface INetConfServer
{
    parameters:
        @display("i=block/server");
        // name of the configuration to be launched on startup
        string launchConfigName;
        // the number of config strores in this host.
        int numConfigStores;
        // the path to the NetConfConfigDataStore module(s) array.
        string pathToConfigDataStores;
        // the path to the NetConfStateDataStore module
        string pathToStateDataStore;
        
    gates:
        input responseIn @directIn;
        
        // connection to transport protocols
        input transportIn;
        output transportOut;    
}
