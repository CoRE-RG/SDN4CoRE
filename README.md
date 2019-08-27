# SDN4CoRE

# SDN4CoRE

SDN4CoRE (Software-Defined Networking for Communication over Realtime Ethernet) is an open-source extension for the event-based simulation of programmable (software-defined) real-time Ethernet networks in the [OMNEST/OMNeT++](https://omnetpp.org/) simulation system. It is based on the [INET-Framework](https://inet.omnetpp.org/), providing internet technologies, the [CoRE4INET Framework](https://github.com/CoRE-RG/CoRE4INET), providing real-time Ethernet protocols such as AS6802, AVB and TSN, and the [OpenFlow Framework](https://github.com/CoRE-RG/OpenFlow), originally developed at the University of Würzburg, Germany, providing a programmability option via the OpenFlow protocol.
SDN4CoRE provides programmable network devices and controllers for different Ethernet extensions such as IEEE802.1Qbv and AVB (including SRP) and various management protocols such as NetConf and OpenFlow. It was created by the [CoRE (Communication over Realtime Ethernet)](https://core-researchgroup.de/) and the [INET (Internet Technologies)](https://inet.haw-hamburg.de/) research group at the [HAW-Hamburg (Hamburg University of Applied Sciences)](https://www.haw-hamburg.de/english.html).

<img src="/doc/images/sdn4core.png" alt="SDN4CoRE Environment" width="35%">


## News
Model release including programmable devices and controllers for IEEE802.1Q, IEEE802.1Qbv, AVB/SRP via OpenFlow and NetConf.


## Quick Start
1. Download OMNeT++ 5.1.1
    * [https://omnetpp.org/download/old](https://omnetpp.org/download/old)
2. Install OMNeT++
    * [https://doc.omnetpp.org/omnetpp/InstallGuide.pdf](https://doc.omnetpp.org/omnetpp/InstallGuide.pdf)
3. Get INET framework 3.5
    * [https://inet.omnetpp.org/Download.html](https://inet.omnetpp.org/Download.html)
4. Install CoRE plugins (optional)
    * OMNEST/OMNeT++ -> Help -> Install New Software...
    * URL `http://sim.core-rg.de/updates/`
    * Check [Abstract Network Description Language] | [CoRE Simulation Model Installer] | [Gantt Chart Timing Analyzer]
5. Get CoRE framework (GitHub or CoRE Simulation Model Installer)
    * GitHub: Clone framework and import it in OMNEST/OMNeT++
    * CoRE Simulation Model Installer: OMNEST/OMNeT++ -> Help -> Install CoRE Simulation Models...
6. Get our original fork of the OpenFlow framework (GitHub)
    * GitHub: Clone framework and import it in OMNEST/OMNeT++
7. Get SDN4CoRE framework (GitHub)
	* GitHub: Clone framework and import it in OMNEST/OMNeT++
8. Working with the framework
    * See the documentation in [doc/](/doc)
    * Start the examples in the framework


## Continuous Integration

The build state of the master branch is monitored:
* Building:
<a href="https://jenkins.core-rg.de/job/SDN4CoRE/job/SDN4CoRE/lastBuild/"><img src="https://jenkins.core-rg.de/buildStatus/icon?job=SDN4CoRE/SDN4CoRE"></a>
* Tests:
<a href="https://jenkins.core-rg.de/job/SDN4CoRE/job/SDN4CoRE_tests/lastBuild/"><img src="https://jenkins.core-rg.de/buildStatus/icon?job=SDN4CoRE/SDN4CoRE_tests"></a>

<table>
  <tr>
    <th></th>
    <th>Ubuntu 18.04</th>
    <th>Windows 10</th>
  </tr>
  <tr>
    <td>Building</td>
    <td><a href="https://jenkins.core-rg.de/job/SDN4CoRE/job/SDN4CoRE/Nodes=Ubuntu_18.04/lastBuild/"><img src="https://jenkins.core-rg.de/buildStatus/icon?job=SDN4CoRE/SDN4CoRE/Nodes=Ubuntu_18.04"></a></td>
    <td><a href="https://jenkins.core-rg.de/job/SDN4CoRE/job/SDN4CoRE/Nodes=Windows_10/lastBuild/"><img src="https://jenkins.core-rg.de/buildStatus/icon?job=SDN4CoRE/SDN4CoRE/Nodes=Windows_10"></a></td>
  </tr>
  <tr>
    <td>Tests</td>
    <td><a href="https://jenkins.core-rg.de/job/SDN4CoRE/job/SDN4CoRE_tests/Nodes=Ubuntu_18.04/lastBuild/"><img src="https://jenkins.core-rg.de/buildStatus/icon?job=SDN4CoRE/SDN4CoRE_tests/Nodes=Ubuntu_18.04"></a></td>
    <td><a href="https://jenkins.core-rg.de/job/SDN4CoRE/job/SDN4CoRE_tests/Nodes=Windows_10/lastBuild/"><img src="https://jenkins.core-rg.de/buildStatus/icon?job=SDN4CoRE/SDN4CoRE_tests/Nodes=Windows_10"></a></td>
  </tr>
</table>


## Further Information

### Installation
Please see [INSTALL](/INSTALL)

### Documentation
Please see [doc/](/doc)

### Changelog
Please see [WHATSNEW](/WHATSNEW)

## IMPORTANT
The SDN4CoRE model is under continuous development: new parts are added, bugs are corrected, and so on. We cannot assert that the implementation will work fully according to the specifications. YOU ARE RESPONSIBLE YOURSELF TO MAKE SURE THAT THE MODELS YOU USE IN YOUR SIMULATIONS WORK CORRECTLY, AND YOU'RE GETTING VALID RESULTS. 