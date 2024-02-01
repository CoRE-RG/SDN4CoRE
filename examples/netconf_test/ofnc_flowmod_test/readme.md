# NetConf OpenFlow FlowMod Test  
This scenario test the OpenFlow table modification via NetConf in a concurrent OpenFlow and NetConf configuration.

## Nodes 
The network consists of 3 Nodes, 2 OpenFlow and NetConf capable switches and an SDN controller that is connected to both switches via a traditianal Layer 2 Ethernet switch.

## Traffic
All traffic originates at Node 1.
1. IEEE8021QTrafficSourceApp sends full size frames to node 2 in a TDMA fashion with GCLs configured at Node 1 and both Switches.
2. BGTrafficSourceApp sends low priority full size frames to node 2

## Reconfiguration and Network Control 
The traffic is controlled via the OpenFlow controller application. 

At 0.25 s simulation time a NetConf application at the controller reconfigures the flow table at switch 2 to forward the low priority background traffic to node 3.
Node 3 is set to promiscous to make the frames visible in the app statistics.


  