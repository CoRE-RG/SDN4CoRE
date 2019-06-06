

package sdn4core.switch.base.engine;

//OPENFLOW
import openflow.openflow.switch.engine.IOpenFlowRelayUnit;

//
// The OF_RelayUnit implements the switching engine of an OpenFlow Switch.
// It is directly connected to the TCP module to communicate with the OF Controller.
// It handles the forwarding of incoming packets by matching them with the OpenFlowTable 
// (@see~IOpenFlowFlowTable) entries.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple OF_RelayUnit like IOpenFlowRelayUnit
{
    parameters:
        @class(SDN4CoRE::OF_RelayUnit);
        @signal[cpPingPacketHash](type="unsigned long");
        @statistic[cpPingPacketHash](title="CpPingPacketHash"; record=vector?,stats; interpolationmode=none);
        @signal[dpPingPacketHash](type="unsigned long");
        @statistic[dpPingPacketHash](title="DpPingPacketHash"; record=vector?,stats; interpolationmode=none);
        @signal[queueSize](type="unsigned long");
        @statistic[queueSize](title="QueueSize"; record=vector?,stats; interpolationmode=none);
        @signal[bufferSize](type="long");
        @statistic[bufferSize](title="BufferSize"; record=vector?,stats; interpolationmode=none);
        @signal[waitingTime](type="simtime_t");
        @statistic[waitingTime](title="WaitingTime"; record=vector?,stats?; interpolationmode=none);
        @display("i=block/app");
        
        // paths to other modules
        string interfaceTableModule;   // The path to the InterfaceTable module
        
        string localAddress = default("");
        int localPort = default(-1);
        string connectAddress = default(""); // controller address
        int connectPort = default(6633);// controller port
        
        // Modelling a realistic environment
		double flowTimeoutPollInterval @unit("s") = default(1s);
		double connectAt @unit("s") = default(1s);  // Simtime at which the switch connects to the controller.
		double serviceTime @unit("s") = default(0s);		// The relay units service time, models finite processing power 
		int bufferCapacity = default(0); 	// Max. number of frames in Buffer, infinity if <= 0

		bool sendCompletePacket = default(true);
		bool highlightActivePorts = default(false);
		
		//Path of the switch configuration xml file
    	xml configXML = default(xml("<root/>"));

    gates:
        input controlPlaneIn @labels(TCPCommand/up);
        output controlPlaneOut @labels(TCPCommand/down);
        
        input  dataPlaneIn[];
        output dataPlaneOut[];

}
