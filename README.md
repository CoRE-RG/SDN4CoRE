# SDN4CoRE

SDN4CoRE (Software-Defined Networking for Communication over Realtime Ethernet) is an open-source extension for the event-based simulation of programmable (software-defined) real-time Ethernet networks in the [OMNEST/OMNeT++](https://omnetpp.org/) simulation system. It is based on the [INET-Framework](https://inet.omnetpp.org/), providing internet technologies, the [CoRE4INET Framework](https://github.com/CoRE-RG/CoRE4INET), providing real-time Ethernet protocols such as AS6802, AVB and TSN, and the [OpenFlow Framework](https://github.com/CoRE-RG/OpenFlow), originally developed at the University of Würzburg, Germany, providing a programmability option via the OpenFlow protocol.
Recently we added a SOME/IP controller application which depends on the [SOA4CoRE Framework](https://github.com/CoRE-RG/SOA4CoRE).
SDN4CoRE provides programmable network devices and controllers for different Ethernet extensions such as IEEE802.1Qbv and AVB (including SRP) and various management protocols such as NetConf and OpenFlow. It was created by the [CoRE (Communication over Realtime Ethernet)](https://core-researchgroup.de/) and the [INET (Internet Technologies)](https://inet.haw-hamburg.de/) research group at the [HAW-Hamburg (Hamburg University of Applied Sciences)](https://www.haw-hamburg.de/english.html).

<img src="/doc/images/sdn4core.png" alt="SDN4CoRE Environment" width="75%">


## News
IMPORTANT: We recently had to perform a rebase for the published NETCONF transactions to clean up the history and change the commit authors.
We apologize for the inconvenience, but it was important to us that all student contributors are listed.
If you have trouble pulling changes, try rebasing your changes to the current Github master branch, or open an issue and ask for help.

Release of Netconf transaction model including time synchronous and non time synchronous transactions. As well as chnages to many netconf moudules.

Model release including programmable devices and controllers for IEEE802.1Q, IEEE802.1Qbv, AVB/SRP via OpenFlow and NetConf.

SOME/IP Service Discovery Controller Application added, depends on SOA4CoRE Framework.

## References
If you would like to reference this project please use the following [publication](https://doi.org/10.29007/w71t):

 >Timo Häckel, Philipp Meyer, Franz Korf, and Thomas C. Schmidt. SDN4CoRE: A Simulation Model for Software-Defined Networking for Communication over Real-Time Ethernet. In: Proceedings of the 6th International OMNeT++ Community Summit 2019. Pages 24—31, Dec. 2019, EasyChair

## Quick Start
1. Download OMNeT++ 6.0.2
    * [https://omnetpp.org/download](https://omnetpp.org/download)
2. Install OMNeT++
    * [https://doc.omnetpp.org/omnetpp/InstallGuide.pdf](https://doc.omnetpp.org/omnetpp/InstallGuide.pdf)
3. Get INET framework 3.8.3
    * [https://inet.omnetpp.org/Download.html](https://inet.omnetpp.org/Download.html)
    * Disable the feature 'visualization' and all dependent features (causes build issues)
4. Get CoRE framework
    * GitHub: Clone [CoRE4INET](https://github.com/CoRE-RG/CoRE4INET), [FiCo4OMNeT](https://github.com/CoRE-RG/FiCo4OMNeT), [SignalsAndGateways](https://github.com/CoRE-RG/SignalsAndGateways), [SOA4CoRE](https://github.com/CoRE-RG/SOA4CoRE), our original fork of [OpenFlow](https://github.com/CoRE-RG/OpenFlow), and this repository and import them in OMNEST/OMNeT++
5. Working with the framework
    * See the documentation in [doc/](/doc)
    * Start the examples in the framework


## Continuous Integration

The build state of the master branch is monitored:
* Building: 
<a><img src="https://jenkins.core-rg.de/buildStatus/icon?job=SDN4CoRE/SDN4CoRE"></a>
* Tests: 
<a><img src="https://jenkins.core-rg.de/buildStatus/icon?job=SDN4CoRE/SDN4CoRE_tests"></a>


<table>
  <tr>
    <th></th>
    <th>Ubuntu 22.04</th>
    <th>Windows 11</th>
  </tr>
  <tr>
    <td>Building</td>
    <td><img src="https://jenkins.core-rg.de/buildStatus/icon?job=SDN4CoRE/SDN4CoRE/Nodes=Ubuntu_22.04"></td>
    <td><img src="https://jenkins.core-rg.de/buildStatus/icon?job=SDN4CoRE/SDN4CoRE/Nodes=Windows_11"></td>
  </tr>
  <tr>
    <td>Tests</td>
    <td><img src="https://jenkins.core-rg.de/buildStatus/icon?job=SDN4CoRE/SDN4CoRE_tests/Nodes=Ubuntu_22.04"></td>
    <td><img src="https://jenkins.core-rg.de/buildStatus/icon?job=SDN4CoRE/SDN4CoRE_tests/Nodes=Windows_11"></td>
  </tr>
</table>


## Further Information
* [CoRE simulation models overview](https://core-researchgroup.de/projects/simulation.html)

### Installation
Please see [INSTALL](/INSTALL)

### Documentation
Please see [doc/](/doc)

### Changelog
Please see [WHATSNEW](/WHATSNEW)

## IMPORTANT
The SDN4CoRE model is under continuous development: new parts are added, bugs are corrected, and so on. We cannot assert that the implementation will work fully according to the specifications. YOU ARE RESPONSIBLE YOURSELF TO MAKE SURE THAT THE MODELS YOU USE IN YOUR SIMULATIONS WORK CORRECTLY, AND YOU'RE GETTING VALID RESULTS. 
