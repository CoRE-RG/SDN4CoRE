# SDN4CoRE

SDN4CoRE (Software-Defined Networking for Communication over Realtime Ethernet) is an open-source extension for the event-based simulation of programmable (software-defined) real-time Ethernet networks in the [OMNEST/OMNeT++](https://omnetpp.org/) simulation system. It is based on the [INET-Framework](https://inet.omnetpp.org/), providing internet technologies, the [CoRE4INET Framework](https://github.com/CoRE-RG/CoRE4INET), providing real-time Ethernet protocols such as AS6802, AVB and TSN, and the [OpenFlow Framework](https://github.com/CoRE-RG/OpenFlow), originally developed at the University of Würzburg, Germany, providing a programmability option via the OpenFlow protocol.
Recently we added a SOME/IP controller application which depends on the [SOA4CoRE Framework](https://github.com/CoRE-RG/SOA4CoRE).
SDN4CoRE provides programmable network devices and controllers for different Ethernet extensions such as IEEE802.1Qbv and AVB (including SRP) and various management protocols such as NetConf and OpenFlow. It was created by the [CoRE (Communication over Realtime Ethernet)](https://core-researchgroup.de/) and the [INET (Internet Technologies)](https://inet.haw-hamburg.de/) research group at the [HAW-Hamburg (Hamburg University of Applied Sciences)](https://www.haw-hamburg.de/english.html).

<img src="/doc/images/sdn4core.png" alt="SDN4CoRE Environment" width="75%">


## Features
* Programmable devices and controllers for IEEE802.1Q, IEEE802.1Qbv, AVB/SRP via OpenFlow and NetConf
* Netconf transaction model including time synchronous and non time synchronous transactions
* SOME/IP Service Discovery Controller Application added (depends on SOA4CoRE Framework)
* More SOME/IP integrations and service added, including QoS negotiation and reservation via TSN

## References
To reference this project please use the following [publication](https://doi.org/10.29007/w71t):

 >Timo Häckel, Philipp Meyer, Franz Korf, and Thomas C. Schmidt. SDN4CoRE: A Simulation Model for Software-Defined Networking for Communication over Real-Time Ethernet. In: Proceedings of the 6th International OMNeT++ Community Summit 2019. Pages 24—31, Dec. 2019, EasyChair.
 ```bibtex
 @InProceedings{hmks-smsdn-19,
  author     = {Timo H{\"a}ckel and Philipp Meyer and Franz Korf and Thomas C. Schmidt},
  booktitle  = {6th International OMNeT++ Community Summit},
  title      = {{SDN4CoRE: A Simulation Model for Software-Defined Networking for Communication over Real-Time Ethernet}},
  editor    = {Meyo Zongo and Antonio Virdis and Vladimir Vesely and Zeynep Vatandas and Asanga Udugama and Koojana Kuladinithi and Michael Kirsche and Anna F{\"o}rster},
  year       = {2019},
  month      = sep,
  pages      = {24--31},
  series    = {EPiC Series in Computing},
  volume    = {66},
  publisher = {EasyChair},
  doi        = {10.29007/w71t}
}
```

To reference the TSN and SDN integration / TSSDN) methodology please add the following [reference](https://doi.org/10.1109/TVT.2022.3202368):
> T. Häckel, P. Meyer, F. Korf and T. C. Schmidt, "Secure Time-Sensitive Software-Defined Networking in Vehicles," in IEEE Transactions on Vehicular Technology, vol. 72, no. 1, pp. 35-51, Jan. 2023, IEEE. 
```bibtex
@Article{hmks-stsnv-23,
  author    = {Timo H{\"a}ckel and Philipp Meyer and Franz Korf and Thomas C. Schmidt},
  journal   = {IEEE Transactions on Vehicular Technology},
  title     = {{Secure Time-Sensitive Software-Defined Networking in Vehicles}},
  year      = {2023},
  month     = jan,
  number    = {1},
  pages     = {35--51},
  volume    = {72},
  doi       = {10.1109/TVT.2022.3202368},
  publisher = {IEEE}
}
```

For the TSN and SOA integrations with deterministic latency please add the following [reference](https://doi.org/10.1016/j.vehcom.2025.100985)
> Timo Salomon, Lisa Maile, Philipp Meyer, Franz Korf, Thomas C. Schmidt, "Negotiating Strict Latency Limits for Dynamic Real-Time Services in Vehicular Time-Sensitive Networks," Vehicular Communications, Elsevier, 2025. (in press)
```bibtex
@Article{smmks-nslld-25,
  author = {Timo Salomon and Lisa Maile and Philipp Meyer and Franz Korf and Thomas C. Schmidt},
  title  = {{Negotiating Strict Latency Limits for Dynamic Real-Time Services in Vehicular Time-Sensitive Networks}},
  journal = {Vehicular Communications},
  pages = {},
  volume = {},
  number = {},
  year = {2025},
  month = {},
  nope= "In Press",
  publisher = {Elsevier},
  doi   = {10.1016/j.vehcom.2025.100985},
}
```

## Quick Start
1. Download OMNeT++ 6.0.2
    * [https://omnetpp.org/download](https://omnetpp.org/download)
2. Install OMNeT++
    * [https://doc.omnetpp.org/omnetpp/InstallGuide.pdf](https://doc.omnetpp.org/omnetpp/InstallGuide.pdf)
3. Get INET framework 3.8.5
    * [https://inet.omnetpp.org/Download.html](https://inet.omnetpp.org/Download.html)
    * Disable the feature 'visualization' and all dependent features (causes build issues)
4. Get CoRE framework
    * GitHub: Clone [CoRE4INET](https://github.com/CoRE-RG/CoRE4INET), [FiCo4OMNeT](https://github.com/CoRE-RG/FiCo4OMNeT), [SignalsAndGateways](https://github.com/CoRE-RG/SignalsAndGateways), [SOA4CoRE](https://github.com/CoRE-RG/SOA4CoRE), our original fork of [OpenFlow](https://github.com/CoRE-RG/OpenFlow), and this repository and import them in OMNEST/OMNeT++
5. Working with the framework
    * See the documentation in [doc/](/doc)
    * Start the examples in the framework


## Status
The project has been tested on Ubuntu 22.04 (+WSL) and Windows 11. 


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
