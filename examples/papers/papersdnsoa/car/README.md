# Car

Network file: Car.ned

## Traffic

 - VLAN 0 - Shortest path
 - VLAN 1 - Clockwise
 - VLAN 2 - Counterclockwise

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