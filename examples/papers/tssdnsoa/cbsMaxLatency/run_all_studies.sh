#!/bin/bash
export PATH=/home/timo/omnet/omnetpp-6.0.2/bin:$PATH
opp_cmd="opp_run -m -u Cmdenv"
nedpath="../../..;../../../../simulations;../../../../src;../../../../../CoRE4INET/examples;../../../../../CoRE4INET/simulations;../../../../../CoRE4INET/src;../../../../../inet/src;../../../../../inet/examples;../../../../../inet/tutorials;../../../../../inet/showcases;../../../../../OpenFlow/src;../../../../../OpenFlow/scenarios;../../../../../SOA4CoRE/examples;../../../../../SOA4CoRE/simulations;../../../../../SOA4CoRE/src/soa4core;../../../../../FiCo4OMNeT/examples;../../../../../FiCo4OMNeT/examples_andl;../../../../../FiCo4OMNeT/simulations;../../../../../FiCo4OMNeT/src;../../../../../SignalsAndGateways/examples;../../../../../SignalsAndGateways/simulations;../../../../../SignalsAndGateways/src"
excludes="core4inet.api.AS6802;core4inet.applications.api.AS6802;core4inet.examples.AS6802.rt_tictoc;core4inet.examples.AS6802.synchronization;core4inet.synchronisation.AS6802;inet.visualizer.environment;inet.visualizer.linklayer;inet.showcases.wireless;inet.visualizer.util;inet.examples.visualization;inet.linklayer.ext;inet.tutorials.visualization;inet.visualizer.common;inet.visualizer.transportlayer;inet.examples.voipstream;inet.visualizer.power;inet.visualizer.mobility;inet.visualizer.scene;inet.visualizer.base;inet.examples.emulation;inet.visualizer.networklayer;inet.transportlayer.tcp_lwip;inet.applications.voipstream;inet.tutorials.configurator;inet.visualizer.integrated;inet.visualizer.physicallayer;inet.showcases.visualizer;inet.transportlayer.tcp_nsc"
imagepath="../../../../images;../../../../../CoRE4INET/images;../../../../../inet/images;../../../../../OpenFlow/images"
libs="-l ../../../../src/SDN4CoRE -l ../../../../../CoRE4INET/src/CoRE4INET -l ../../../../../inet/src/INET -l ../../../../../OpenFlow/src/OpenFlow -l ../../../../../SOA4CoRE/src/SOA4CoRE -l ../../../../../FiCo4OMNeT/src/FiCo4OMNeT -l ../../../../../SignalsAndGateways/src/SignalsAndGateways"

inifile="omnetpp.ini"
length="--sim-time-limit=0.4s"

configbase="Study_"
# array of config extensions
isSchmes=("CMI" "SI" "NC")
ctSchemes=("NoCT" "BECT" "PCT")

for IL in {2..13} ; do
    for S in {1..20} ; do
        for isScheme in "${isSchmes[@]}" ; do
            # iterate over ct schemes
            for ctScheme in "${ctSchemes[@]}" ; do
                config=$configbase$isScheme"_"$ctScheme
                # check if isScheme is "NC"
                if [ "$isScheme" == "NC" ]; then
                    config=$configbase$isScheme"_"$ctScheme"_IL-"$IL"_S-"$S
                fi
                run="\$IL=$IL && \$S=$S"
                $opp_cmd -n $nedpath -x $excludes --image-path=$imagepath $libs $inifile $length -c $config -r "$run" &
            done
            wait
        done
    done    
done

# execute a dedicated study
# opp_cmd="opp_run -m -u Qtenv"
# config=$configbase"Static_BECT"
# run="\$IL=10 && \$S=1"
# $opp_cmd -n $nedpath -x $excludes --image-path=$imagepath $libs $inifile $length -c $config -r "$run" 
