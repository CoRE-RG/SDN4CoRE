package sdn4core.examples.papers.vtc2019.withoutSDN;

import core4inet.nodes.ethernet.avb_AS6802.TTEAVBEtherHost;
import inet.node.ethernet.EtherLink;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.common.misc.ThruputMeteringChannel;

network vtc2019_without_sdn
{
    parameters:
        @display("bgb=,,white");
        double measure_interval @unit(s) = default(1s);

    types:
        channel ETH100M extends ThruputMeteringChannel
        {
            delay = 1us;
            datarate = 100Mbps;
            thruputDisplayFormat = "u";
        }

    submodules:
        configurator: IPv4NetworkConfigurator {
            parameters:
                @display("p=198,190");
        }
        client0: client0 {
            parameters:
        }

        client1: client1 {
            parameters:
        }

        switch0: switch0 {
            parameters:
            gates:
                ethg[2];
        }

        switch1: switch1 {
            parameters:
            gates:
                ethg[2];
        }

    connections:
        client0.ethg <--> ETH100M <--> switch0.ethg[0];
        switch0.ethg[1] <--> ETH100M <--> switch1.ethg[0];
        switch1.ethg[1] <--> ETH100M <--> client1.ethg;

}
