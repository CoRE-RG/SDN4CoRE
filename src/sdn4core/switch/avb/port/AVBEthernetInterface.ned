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


package sdn4core.switch.avb.port;

//inet modules
import inet.linklayer.contract.IWiredNic;
import inet.networklayer.common.InterfaceTable;

//core4inet modules
import core4inet.linklayer.port.TTEAVBPHYPort;
import sdn4core.switch.avb.incoming.avb.OF_AVBIncoming;
import core4inet.buffer.avb.AVBQueueBuffer;
import core4inet.linklayer.ethernet.avb.SRPEtherEncap;
import core4inet.synchronisation.base.ISync;
import core4inet.scheduler.ITTEScheduler;
import core4inet.buffer.base.BGQueueBuffer;

//
// The AVBEthernetInterface abstracts the complexity of an 
// realtime capable port and provides the same interface as a standard ethernet wired nic.
//
// @author Timo Haeckel, for HAW Hamburg
//
module AVBEthernetInterface like IWiredNic
{
    parameters:
        @display("i=device/port");

        // Forwardingdelay of the device hardware
        double hardware_delay @unit(s) = default(0us);
        // Promiscuous mode for best-efford traffic handling
        bool be_promiscuous = default(true);

        *.interfaceTableModule = default(absPath(".interfaceTable"));

        **.srpTable = default("^.^.srpTable");

    gates:
        input upperLayerIn;
        output upperLayerOut;
        inout phys @labels(EtherFrame);

    submodules:

        //Application for sdn connection gateway
        avbportGatewayApp: AVBEthernetInterfaceConnection {
            @display("p=275,42");
        }

        // Physical connection of the port
        phy: TTEAVBPHYPort {
            @display("p=439,258,c,50");
            promiscuous = be_promiscuous;
        }

		// AVB critical traffic control
        avbCTC: OF_AVBIncoming {
            parameters:
                hardware_delay = hardware_delay;
                @display("p=429,123");
            gates:
                AVBAout[1];
                AVBBout[1];
        }

		// AVB class A buffer
        avbABuffer: AVBQueueBuffer {
            parameters:
                srClass = "A";
                srpModule = "^";
                @display("p=361,185");
        }

        // AVB class B buffer
        avbBBuffer: AVBQueueBuffer {
            parameters:
                srClass = "B";
                srpModule = "^";
                @display("p=499,185");
        }

		// Stream Reservation Protocol ethernet encapsulation
        encap: SRPEtherEncap {
            parameters:
                @display("p=275,256");
        }

        // Sync module for synchronisation of the scheduler
        sync: <default("DummySync")> like ISync {
            @display("p=52,256");
        }

        // Scheduler for the device
        scheduler: <default("Scheduler")> like ITTEScheduler {
            @display("p=52,194");
        }

        // Best-efford buffer for incoming traffic 
        bgIn: BGQueueBuffer {
            @display("p=150,123");
        }

		// Best-efford buffer for outgoing traffic
        bgOut: BGQueueBuffer {
            @display("p=222,123");
        }
        
        // Interface Table module for all Ethernet interfaces
        interfaceTable: InterfaceTable {
            @display("p=70,47");
        }

    connections allowunconnected:

        avbportGatewayApp.upperLayerOut --> upperLayerOut;
        avbportGatewayApp.upperLayerIn <-- upperLayerIn;

        avbportGatewayApp.AVBin <-- avbCTC.toGateway;

        phy.phys <--> phys;
        encap.lowerLayerOut --> phy.upperLayerIn;
        phy.upperLayerOut --> encap.lowerLayerIn;

        encap.bgOut --> bgIn.in;
        bgOut.out --> encap.bgIn;
        bgIn.out --> avbportGatewayApp.in;

        avbCTC.AVBAout[0] --> avbABuffer.in;
        avbCTC.AVBBout[0] --> avbBBuffer.in;
        avbABuffer.out --> phy.AVBAin;
        avbBBuffer.out --> phy.AVBBin;

        avbportGatewayApp.encapSrpOut --> encap.srpIn;
        avbportGatewayApp.encapSrpIn <-- encap.srpOut;
}

