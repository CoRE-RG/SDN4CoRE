# Car Network
Originally published in 
> Philipp Meyer, Timo Häckel, Teresa Lübeck, Franz Korf, Thomas C. Schmidt, A Framework for the Systematic Assessment of Anomaly Detectors in Time-Sensitive Automotive Networks, In: Proc. of the 15th IEEE Vehicular Networking Conference (VNC), pp. 57-64, IEEE, May 2024.
```Bibtex
@inproceedings{mhlks-fsaad-24,
  author = {Philipp Meyer and Timo H{\"a}ckel and Teresa L{\"u}beck and Franz Korf and Thomas C. Schmidt},
  title = {{A Framework for the Systematic Assessment of Anomaly Detectors in Time-Sensitive Automotive Networks}},
  booktitle = {Proc. of the 15th IEEE Vehicular Networking Conference (VNC)},
  pages = {57-64},
  location = {Kobe, Japan},
  month = {May},
  year = {2024},
  publisher = {IEEE},
  doi = {10.1109/VNC61989.2024.10576017},
}
```

Network file: Car.ned

Original network can be found under ./orignals/ 

anonymize.ipynb shows how the car network has been anonymized before

MigrateToSDN4CoRE.ipynb automatically performs the required changes from these originals used for our study.

## Traffic

| Traffic                            | Source                        | Destination                   | VLAN  | Priority | Shaping           | Redundancy          | Layer 3+ |
|------------------------------------|-------------------------------|-------------------------------|:-----:|:--------:|-------------------|---------------------|----------|
| gPTP Sync                          | (masterClock)                 | -                             | 0     | 7        | -                 | 2 gPTP Domains      | -        |
| Manual Throttle / Brake / Steer    | zonalControllerFrontLeft      | zonalController*              | 0/1/2 | 6        | 802.1Q GCL Window | 802.1CB in Backbone | IP/UDP   |
| Automatic Throttle / Brake / Steer | adas                          | zonalController*              | 0/1/2 | 6        | 802.1Q GCL Window | 802.1CB in Backbone | IP/UDP   |
| Video (2 Source Apps)              | camera*                       | adas                          | 0/1/2 | 5        | 802.1Q CBS        | 802.1CB in Backbone | IP/UDP   |
| LIDAR (4 Source Apps)              | lidar*                        | adas                          | 0/1/2 | 5        | 802.1Q CBS        | 802.1CB in Backbone | IP/UDP   |
| Control (201 Source Apps)          | zonalController*/infotainment | zonalController*/infotainment | 0     | 4        | -                 | -                   | IP/UDP   |
| V2X                                | connectivityGateway/adas      | connectivityGateway/adas      | 0     | 2        | -                 | -                   | IP/TCP   |
| Background                         | *                             | *                             | 0     | 0        | -                 | -                   | *        |

## Dyrectsn scenarios
When running a configuration a json will be created such as "flowUpdatesStreamCMI.json" which contains all flow installations during this run. 
This can be fed into DYRECTsn to run a worst-case analysis and to identify Idle Slopes that meet the deadlines. 
With the dyrectsnToOmnet.ipynb notebook, you can parse the DYRECTsn output to create a configuration for our SDN Controller (e.g., controllerDyrectsn10GigConfig.xml). 

## Study
Our study runs stream interval, CMI and NC scenarios from the paper. 
