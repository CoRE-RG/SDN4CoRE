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
        // priority of a flow created by this application
        int priority = default(1);
        
        //offline configuration containing mac and srp information.
        xml configXML = default(xml("<root/>"));
        // write configuration into the given config file that can be fed back
        string dumpConfig = default("");
        
        // packet filters:
        // Syntax: "<key1>=<value11>,<value12>; ...; <keyK>=<valueK1>,...,<valueKV>"
        // A list of filters separated by semicolon ";". Each filter contains 
        // exactly one key followed by "=" and a list of values separated with a comma ",".
        // accepted values keys are:
        // 		key: "ethSrc" values: MAC address, e.g., AA-AA-AA-AA-AA-AA
        // 		key: "ethDst" values: MAC address, e.g., AA-AA-AA-AA-AA-AA
        // 		key: "etherType" values: etherType number, e.g., 0x0800 or 2048
        //		key: "vlanId" values: VLAN identifier, e.g., 42
        //		key: "vlanPcp" values: VLAN priority code points (0-7), e.g., 3
        // 		key: "ipSrc" values: IP address with optional prefix length, e.g., 192.168.178.42 or 192.168.178.1/24 
        // 		key: "ipDst" values: IP address with optional prefix length, e.g., 192.168.178.42 or 192.168.178.1/24 
        // 		key: "ipProto" values: IP protocol, e.g. 0x11 or 17
        // 		key: "udpSrc" values: UDP port, e.g., 1234
        // 		key: "udpDst" values: UDP port, e.g., 1234
        // 		key: "tcpSrc" values: TCP port, e.g., 1234
        // 		key: "tcpDst" values: TCP port, e.g., 1234
        //
        // whitelist filter for packets that shall be processed by the application        
        string packetFilterWhitelist = default(""); // an empty whilelist means only blacklisted packets are filtered
        // blacklist filter for packets that shall be processed by the application
        string packetFilterBlacklist = default(""); // an empty blacklist means only non whitelisted packets are filtered
        
        @signal[packetFiltered](type=cPacket);
        @signal[packetProcessed](type=cPacket);
        
}
