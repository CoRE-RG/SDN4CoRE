----- Start of pre-configuration ----
----- Pre-configuration finished ----
----- Start Online Admission ----
---------------------- Start Initialization ------------------------
Edge (sw_fl,sw_c,0): Delay: 0.0002
Edge (sw_fl,sw_c,1): Delay: 0.0002
Edge (sw_fl,lidar_fl,0): Delay: 0.0002
Edge (sw_fl,lidar_fl,1): Delay: 0.0002
Edge (sw_fl,connectivity_gw,0): Delay: 0.0002
Edge (sw_fl,connectivity_gw,1): Delay: 0.0002
Edge (sw_fl,zc_fl,0): Delay: 0.0002
Edge (sw_fl,zc_fl,1): Delay: 0.0002
Edge (sw_fl,infotainment,0): Delay: 0.0002
Edge (sw_fl,infotainment,1): Delay: 0.0002
Edge (sw_c,sw_fl,0): Delay: 0.0002
Edge (sw_c,sw_fl,1): Delay: 0.0002
Edge (sw_c,sw_fr,0): Delay: 0.0002
Edge (sw_c,sw_fr,1): Delay: 0.0002
Edge (sw_c,sw_rl,0): Delay: 0.0002
Edge (sw_c,sw_rl,1): Delay: 0.0002
Edge (sw_c,sw_rr,0): Delay: 0.0002
Edge (sw_c,sw_rr,1): Delay: 0.0002
Edge (sw_fr,sw_c,0): Delay: 0.0002
Edge (sw_fr,sw_c,1): Delay: 0.0002
Edge (sw_fr,camera_front,0): Delay: 0.0002
Edge (sw_fr,camera_front,1): Delay: 0.0002
Edge (sw_fr,lidar_fr,0): Delay: 0.0002
Edge (sw_fr,lidar_fr,1): Delay: 0.0002
Edge (sw_fr,zc_fr,0): Delay: 0.0002
Edge (sw_fr,zc_fr,1): Delay: 0.0002
Edge (sw_rl,sw_c,0): Delay: 0.0002
Edge (sw_rl,sw_c,1): Delay: 0.0002
Edge (sw_rl,camera_rear,0): Delay: 0.0002
Edge (sw_rl,camera_rear,1): Delay: 0.0002
Edge (sw_rl,lidar_rl,0): Delay: 0.0002
Edge (sw_rl,lidar_rl,1): Delay: 0.0002
Edge (sw_rl,zc_rl,0): Delay: 0.0002
Edge (sw_rl,zc_rl,1): Delay: 0.0002
Edge (sw_rr,sw_c,0): Delay: 0.0002
Edge (sw_rr,sw_c,1): Delay: 0.0002
Edge (sw_rr,adas,0): Delay: 0.0002
Edge (sw_rr,adas,1): Delay: 0.0002
Edge (sw_rr,zc_rr,0): Delay: 0.0002
Edge (sw_rr,zc_rr,1): Delay: 0.0002
Edge (sw_rr,lidar_rr,0): Delay: 0.0002
Edge (sw_rr,lidar_rr,1): Delay: 0.0002
Edge (lidar_fl,sw_fl,0): Delay: 0.0002
Edge (lidar_fl,sw_fl,1): Delay: 0.0002
Edge (connectivity_gw,sw_fl,0): Delay: 0.0002
Edge (connectivity_gw,sw_fl,1): Delay: 0.0002
Edge (zc_fl,sw_fl,0): Delay: 0.0002
Edge (zc_fl,sw_fl,1): Delay: 0.0002
Edge (infotainment,sw_fl,0): Delay: 0.0002
Edge (infotainment,sw_fl,1): Delay: 0.0002
Edge (camera_front,sw_fr,0): Delay: 0.0002
Edge (camera_front,sw_fr,1): Delay: 0.0002
Edge (lidar_fr,sw_fr,0): Delay: 0.0002
Edge (lidar_fr,sw_fr,1): Delay: 0.0002
Edge (zc_fr,sw_fr,0): Delay: 0.0002
Edge (zc_fr,sw_fr,1): Delay: 0.0002
Edge (camera_rear,sw_rl,0): Delay: 0.0002
Edge (camera_rear,sw_rl,1): Delay: 0.0002
Edge (lidar_rl,sw_rl,0): Delay: 0.0002
Edge (lidar_rl,sw_rl,1): Delay: 0.0002
Edge (zc_rl,sw_rl,0): Delay: 0.0002
Edge (zc_rl,sw_rl,1): Delay: 0.0002
Edge (adas,sw_rr,0): Delay: 0.0002
Edge (adas,sw_rr,1): Delay: 0.0002
Edge (zc_rr,sw_rr,0): Delay: 0.0002
Edge (zc_rr,sw_rr,1): Delay: 0.0002
Edge (lidar_rr,sw_rr,0): Delay: 0.0002
Edge (lidar_rr,sw_rr,1): Delay: 0.0002
---------------------- End Initialization ------------------------
------------------- Find Path(s) ----------------------
Flow(id=4049, source=zc_fr, sink=['infotainment'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 1. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 3850196.54
(sw_fr, sw_c) in bit/s: None, 3459567.31
------------------- Find Path(s) ----------------------
Flow(id=4021, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 2. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 3850196.54
(sw_c, sw_rr) in bit/s: None, 3850191.56
(sw_fr, sw_c) in bit/s: None, 6895338.83
(sw_rr, zc_rr) in bit/s: None, 4185344.27
------------------- Remove Resources ----------------------
----- 3. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 3850196.54
(sw_c, sw_rr) in bit/s: None, 3850191.56
(sw_fr, sw_c) in bit/s: None, 6895338.83
(sw_rr, zc_rr) in bit/s: None, 4185344.27
------------------- Find Path(s) ----------------------
Flow(id=4021, source=zc_fr, sink=['zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 4. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, zc_fl) in bit/s: None, 4099255.59
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 7697481.42
(sw_c, sw_rr) in bit/s: None, 3850191.56
(sw_fr, sw_c) in bit/s: None, 6895338.83
(sw_rr, zc_rr) in bit/s: None, 4185344.27
------------------- Find Path(s) ----------------------
Flow(id=6077, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 5. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, zc_fl) in bit/s: None, 4099255.59
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 7697481.42
(sw_c, sw_fr) in bit/s: None, 3952893.43
(sw_c, sw_rr) in bit/s: None, 3850191.56
(sw_fr, sw_c) in bit/s: None, 6895338.83
(sw_fr, zc_fr) in bit/s: None, 4185333.43
(sw_rr, sw_c) in bit/s: None, 3848369.10
(sw_rr, zc_rr) in bit/s: None, 4185344.27
------------------- Remove Resources ----------------------
----- 6. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, zc_fl) in bit/s: None, 4099255.59
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 7697481.42
(sw_c, sw_fr) in bit/s: None, 3952893.43
(sw_c, sw_rr) in bit/s: None, 3850191.56
(sw_fr, sw_c) in bit/s: None, 6895338.83
(sw_fr, zc_fr) in bit/s: None, 4185333.43
(sw_rr, sw_c) in bit/s: None, 3848369.10
(sw_rr, zc_rr) in bit/s: None, 4185344.27
------------------- Find Path(s) ----------------------
Flow(id=6077, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 7. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, zc_fl) in bit/s: None, 8195217.98
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 11546219.59
(sw_c, sw_fr) in bit/s: None, 3952893.43
(sw_c, sw_rr) in bit/s: None, 3850191.56
(sw_fr, sw_c) in bit/s: None, 6895338.83
(sw_fr, zc_fr) in bit/s: None, 4185333.43
(sw_rr, sw_c) in bit/s: None, 3848369.10
(sw_rr, zc_rr) in bit/s: None, 4185344.27
------------------- Find Path(s) ----------------------
Flow(id=4022, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 8. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, zc_fl) in bit/s: None, 8195217.98
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 11546219.59
(sw_c, sw_fr) in bit/s: None, 3952893.43
(sw_c, sw_rr) in bit/s: None, 7697478.38
(sw_fr, sw_c) in bit/s: None, 10307734.70
(sw_fr, zc_fr) in bit/s: None, 4185333.43
(sw_rr, sw_c) in bit/s: None, 3848369.10
(sw_rr, zc_rr) in bit/s: None, 8367265.90
------------------- Find Path(s) ----------------------
Flow(id=3026, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 9. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 8195217.98
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 11546219.59
(sw_c, sw_fr) in bit/s: None, 7905802.22
(sw_c, sw_rr) in bit/s: None, 7697478.38
(sw_fr, sw_c) in bit/s: None, 10307734.70
(sw_fr, zc_fr) in bit/s: None, 8367267.00
(sw_rr, sw_c) in bit/s: None, 3848369.10
(sw_rr, zc_rr) in bit/s: None, 8367265.90
------------------- Remove Resources ----------------------
----- 10. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 8195217.98
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 11546219.59
(sw_c, sw_fr) in bit/s: None, 7905802.22
(sw_c, sw_rr) in bit/s: None, 7697478.38
(sw_fr, sw_c) in bit/s: None, 10307734.70
(sw_fr, zc_fr) in bit/s: None, 8367267.00
(sw_rr, sw_c) in bit/s: None, 3848369.10
(sw_rr, zc_rr) in bit/s: None, 8367265.90
------------------- Find Path(s) ----------------------
Flow(id=3026, source=zc_fl, sink=['zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 11. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 8195217.98
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 11546219.59
(sw_c, sw_fr) in bit/s: None, 7905802.22
(sw_c, sw_rr) in bit/s: None, 11546219.60
(sw_fr, sw_c) in bit/s: None, 10307734.70
(sw_fr, zc_fr) in bit/s: None, 8367267.00
(sw_rr, sw_c) in bit/s: None, 3848369.10
(sw_rr, zc_rr) in bit/s: None, 12545778.90
------------------- Find Path(s) ----------------------
Flow(id=4011, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 12. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 8195217.98
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 11546219.59
(sw_c, sw_fr) in bit/s: None, 7905802.22
(sw_c, sw_rr) in bit/s: None, 15389159.77
(sw_fr, sw_c) in bit/s: None, 13696678.95
(sw_fr, zc_fr) in bit/s: None, 8367267.00
(sw_rr, sw_c) in bit/s: None, 3848369.10
(sw_rr, zc_rr) in bit/s: None, 16720871.21
------------------- Find Path(s) ----------------------
Flow(id=6045, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 13. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 8195217.98
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 11546219.59
(sw_c, sw_fr) in bit/s: None, 11854140.12
(sw_c, sw_rr) in bit/s: None, 15389159.77
(sw_fr, sw_c) in bit/s: None, 13696678.95
(sw_fr, zc_fr) in bit/s: None, 12545775.05
(sw_rr, sw_c) in bit/s: None, 7667867.72
(sw_rr, zc_rr) in bit/s: None, 16720871.21
------------------- Remove Resources ----------------------
----- 14. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 8195217.98
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 11546219.59
(sw_c, sw_fr) in bit/s: None, 11854140.12
(sw_c, sw_rr) in bit/s: None, 15389159.77
(sw_fr, sw_c) in bit/s: None, 13696678.95
(sw_fr, zc_fr) in bit/s: None, 12545775.05
(sw_rr, sw_c) in bit/s: None, 7667867.72
(sw_rr, zc_rr) in bit/s: None, 16720871.21
------------------- Find Path(s) ----------------------
Flow(id=6045, source=zc_rr, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 15. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 8195217.98
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 11546219.59
(sw_c, sw_fr) in bit/s: None, 11854140.12
(sw_c, sw_rl) in bit/s: None, 3952909.82
(sw_c, sw_rr) in bit/s: None, 15389159.77
(sw_fr, sw_c) in bit/s: None, 13696678.95
(sw_fr, zc_fr) in bit/s: None, 12545775.05
(sw_rl, zc_rl) in bit/s: None, 4185350.78
(sw_rr, sw_c) in bit/s: None, 7667867.72
(sw_rr, zc_rr) in bit/s: None, 16720871.21
------------------- Remove Resources ----------------------
----- 16. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 8195217.98
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 11546219.59
(sw_c, sw_fr) in bit/s: None, 11854140.12
(sw_c, sw_rl) in bit/s: None, 3952909.82
(sw_c, sw_rr) in bit/s: None, 15389159.77
(sw_fr, sw_c) in bit/s: None, 13696678.95
(sw_fr, zc_fr) in bit/s: None, 12545775.05
(sw_rl, zc_rl) in bit/s: None, 4185350.78
(sw_rr, sw_c) in bit/s: None, 7667867.72
(sw_rr, zc_rr) in bit/s: None, 16720871.21
------------------- Find Path(s) ----------------------
Flow(id=6045, source=zc_rr, sink=['zc_fr', 'zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 17. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 12287900.11
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 15394961.01
(sw_c, sw_fr) in bit/s: None, 11854140.12
(sw_c, sw_rl) in bit/s: None, 3952909.82
(sw_c, sw_rr) in bit/s: None, 15389159.77
(sw_fr, sw_c) in bit/s: None, 13696678.95
(sw_fr, zc_fr) in bit/s: None, 12545775.05
(sw_rl, zc_rl) in bit/s: None, 4185350.78
(sw_rr, sw_c) in bit/s: None, 7667867.72
(sw_rr, zc_rr) in bit/s: None, 16720871.21
------------------- Find Path(s) ----------------------
Flow(id=6078, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 18. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 12287900.11
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 15394961.01
(sw_c, sw_fr) in bit/s: None, 15799429.13
(sw_c, sw_rl) in bit/s: None, 3952909.82
(sw_c, sw_rr) in bit/s: None, 15389159.77
(sw_fr, sw_c) in bit/s: None, 13696678.95
(sw_fr, zc_fr) in bit/s: None, 16720869.70
(sw_rl, zc_rl) in bit/s: None, 4185350.78
(sw_rr, sw_c) in bit/s: None, 11458788.32
(sw_rr, zc_rr) in bit/s: None, 16720871.21
------------------- Remove Resources ----------------------
----- 19. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 12287900.11
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 15394961.01
(sw_c, sw_fr) in bit/s: None, 15799429.13
(sw_c, sw_rl) in bit/s: None, 3952909.82
(sw_c, sw_rr) in bit/s: None, 15389159.77
(sw_fr, sw_c) in bit/s: None, 13696678.95
(sw_fr, zc_fr) in bit/s: None, 16720869.70
(sw_rl, zc_rl) in bit/s: None, 4185350.78
(sw_rr, sw_c) in bit/s: None, 11458788.32
(sw_rr, zc_rr) in bit/s: None, 16720871.21
------------------- Find Path(s) ----------------------
Flow(id=6078, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 20. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 16377297.81
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 19236449.12
(sw_c, sw_fr) in bit/s: None, 15799429.13
(sw_c, sw_rl) in bit/s: None, 3952909.82
(sw_c, sw_rr) in bit/s: None, 15389159.77
(sw_fr, sw_c) in bit/s: None, 13696678.95
(sw_fr, zc_fr) in bit/s: None, 16720869.70
(sw_rl, zc_rl) in bit/s: None, 4185350.78
(sw_rr, sw_c) in bit/s: None, 11458788.32
(sw_rr, zc_rr) in bit/s: None, 16720871.21
------------------- Find Path(s) ----------------------
Flow(id=4005, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 21. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 16377297.81
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 19236449.12
(sw_c, sw_fr) in bit/s: None, 15799429.13
(sw_c, sw_rl) in bit/s: None, 3952909.82
(sw_c, sw_rr) in bit/s: None, 19229200.41
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 16720869.70
(sw_rl, zc_rl) in bit/s: None, 4185350.78
(sw_rr, sw_c) in bit/s: None, 11458788.32
(sw_rr, zc_rr) in bit/s: None, 20892552.93
------------------- Remove Resources ----------------------
----- 22. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 16377297.81
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 19236449.12
(sw_c, sw_fr) in bit/s: None, 15799429.13
(sw_c, sw_rl) in bit/s: None, 3952909.82
(sw_c, sw_rr) in bit/s: None, 19229200.41
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 16720869.70
(sw_rl, zc_rl) in bit/s: None, 4185350.78
(sw_rr, sw_c) in bit/s: None, 11458788.32
(sw_rr, zc_rr) in bit/s: None, 20892552.93
------------------- Find Path(s) ----------------------
Flow(id=4005, source=zc_fr, sink=['zc_rr', 'zc_rl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 23. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 16377297.81
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 19236449.12
(sw_c, sw_fr) in bit/s: None, 15799429.13
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 19229200.41
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 16720869.70
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 11458788.32
(sw_rr, zc_rr) in bit/s: None, 20892552.93
------------------- Remove Resources ----------------------
----- 24. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 16377297.81
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 19236449.12
(sw_c, sw_fr) in bit/s: None, 15799429.13
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 19229200.41
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 16720869.70
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 11458788.32
(sw_rr, zc_rr) in bit/s: None, 20892552.93
------------------- Find Path(s) ----------------------
Flow(id=4005, source=zc_fr, sink=['zc_rr', 'zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 25. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 20463410.54
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 23083737.59
(sw_c, sw_fr) in bit/s: None, 15799429.13
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 19229200.41
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 16720869.70
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 11458788.32
(sw_rr, zc_rr) in bit/s: None, 20892552.93
------------------- Find Path(s) ----------------------
Flow(id=6033, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 26. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 24546232.78
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 26920872.29
(sw_c, sw_fr) in bit/s: None, 15799429.13
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 19229200.41
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 16720869.70
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 15221311.20
(sw_rr, zc_rr) in bit/s: None, 20892552.93
------------------- Find Path(s) ----------------------
Flow(id=6065, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 27. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 24546232.78
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 26920872.29
(sw_c, sw_fr) in bit/s: None, 19741671.86
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 19229200.41
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 20892544.66
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 20892552.93
------------------- Remove Resources ----------------------
----- 28. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 24546232.78
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 26920872.29
(sw_c, sw_fr) in bit/s: None, 19741671.86
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 19229200.41
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 20892544.66
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 20892552.93
------------------- Find Path(s) ----------------------
Flow(id=6065, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 29. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 28625777.65
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 30755110.07
(sw_c, sw_fr) in bit/s: None, 19741671.86
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 19229200.41
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 20892544.66
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 20892552.93
------------------- Remove Resources ----------------------
----- 30. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 28625777.65
(sw_fl, infotainment) in bit/s: None, 3664687.86
(sw_c, sw_fl) in bit/s: None, 30755110.07
(sw_c, sw_fr) in bit/s: None, 19741671.86
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 19229200.41
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 20892544.66
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 20892552.93
------------------- Find Path(s) ----------------------
Flow(id=6065, source=zc_rr, sink=['zc_fr', 'zc_fl', 'infotainment'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 31. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 28625777.65
(sw_fl, infotainment) in bit/s: None, 7326693.23
(sw_c, sw_fl) in bit/s: None, 30755110.07
(sw_c, sw_fr) in bit/s: None, 19741671.86
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 19229200.41
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 20892544.66
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 20892552.93
------------------- Find Path(s) ----------------------
Flow(id=5004, source=zc_rl, sink=['zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 32. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 28625777.65
(sw_fl, infotainment) in bit/s: None, 7326693.23
(sw_c, sw_fl) in bit/s: None, 30755110.07
(sw_c, sw_fr) in bit/s: None, 19741671.86
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 23075034.26
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 20892544.66
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 25060818.60
------------------- Remove Resources ----------------------
----- 33. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 28625777.65
(sw_fl, infotainment) in bit/s: None, 7326693.23
(sw_c, sw_fl) in bit/s: None, 30755110.07
(sw_c, sw_fr) in bit/s: None, 19741671.86
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 23075034.26
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 20892544.66
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 25060818.60
------------------- Find Path(s) ----------------------
Flow(id=5004, source=zc_rl, sink=['zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 34. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 32702046.76
(sw_fl, infotainment) in bit/s: None, 7326693.23
(sw_c, sw_fl) in bit/s: None, 34599491.89
(sw_c, sw_fr) in bit/s: None, 19741671.86
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 23075034.26
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 20892544.66
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 25060818.60
------------------- Remove Resources ----------------------
----- 35. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 32702046.76
(sw_fl, infotainment) in bit/s: None, 7326693.23
(sw_c, sw_fl) in bit/s: None, 34599491.89
(sw_c, sw_fr) in bit/s: None, 19741671.86
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 23075034.26
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 20892544.66
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 25060818.60
------------------- Find Path(s) ----------------------
Flow(id=5004, source=zc_rl, sink=['zc_rr', 'zc_fl', 'infotainment'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 36. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 32702046.76
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 34599491.89
(sw_c, sw_fr) in bit/s: None, 19741671.86
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 23075034.26
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 20892544.66
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 25060818.60
------------------- Remove Resources ----------------------
----- 37. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 32702046.76
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 34599491.89
(sw_c, sw_fr) in bit/s: None, 19741671.86
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 23075034.26
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 20892544.66
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 25060818.60
------------------- Find Path(s) ----------------------
Flow(id=5004, source=zc_rl, sink=['zc_rr', 'zc_fl', 'infotainment', 'zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 38. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr', 'zc_fl', 'infotainment', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3848369.10
(sw_fl, zc_fl) in bit/s: None, 32702046.76
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 34599491.89
(sw_c, sw_fr) in bit/s: None, 23690000.83
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 23075034.26
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 25060807.33
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 25060818.60
------------------- Find Path(s) ----------------------
Flow(id=3008, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 39. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7667797.03
(sw_fl, zc_fl) in bit/s: None, 32702046.76
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 34599491.89
(sw_c, sw_fr) in bit/s: None, 27638336.90
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 23075034.26
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 29225682.26
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 25060818.60
------------------- Remove Resources ----------------------
----- 40. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7667797.03
(sw_fl, zc_fl) in bit/s: None, 32702046.76
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 34599491.89
(sw_c, sw_fr) in bit/s: None, 27638336.90
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 23075034.26
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 29225682.26
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 25060818.60
------------------- Find Path(s) ----------------------
Flow(id=3008, source=zc_fl, sink=['zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 41. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7667797.03
(sw_fl, zc_fl) in bit/s: None, 32702046.76
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 34599491.89
(sw_c, sw_fr) in bit/s: None, 27638336.90
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 26920875.04
(sw_fr, sw_c) in bit/s: None, 17062585.61
(sw_fr, zc_fr) in bit/s: None, 29225682.26
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 29225696.53
------------------- Find Path(s) ----------------------
Flow(id=4014, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 42. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7667797.03
(sw_fl, zc_fl) in bit/s: None, 32702046.76
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 34599491.89
(sw_c, sw_fr) in bit/s: None, 27638336.90
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 30789924.37
(sw_fr, sw_c) in bit/s: None, 20405534.04
(sw_fr, zc_fr) in bit/s: None, 29225682.26
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 33387149.49
------------------- Remove Resources ----------------------
----- 43. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7667797.03
(sw_fl, zc_fl) in bit/s: None, 32702046.76
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 34599491.89
(sw_c, sw_fr) in bit/s: None, 27638336.90
(sw_c, sw_rl) in bit/s: None, 7905816.05
(sw_c, sw_rr) in bit/s: None, 30789924.37
(sw_fr, sw_c) in bit/s: None, 20405534.04
(sw_fr, zc_fr) in bit/s: None, 29225682.26
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 8367269.98
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 33387149.49
------------------- Find Path(s) ----------------------
Flow(id=4014, source=zc_fr, sink=['zc_rr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 44. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7667797.03
(sw_fl, zc_fl) in bit/s: None, 32702046.76
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 34599491.89
(sw_c, sw_fr) in bit/s: None, 27638336.90
(sw_c, sw_rl) in bit/s: None, 11854142.93
(sw_c, sw_rr) in bit/s: None, 30789924.37
(sw_fr, sw_c) in bit/s: None, 20405534.04
(sw_fr, zc_fr) in bit/s: None, 29225682.26
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 12545766.39
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 33387149.49
------------------- Remove Resources ----------------------
----- 45. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7667797.03
(sw_fl, zc_fl) in bit/s: None, 32702046.76
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 34599491.89
(sw_c, sw_fr) in bit/s: None, 27638336.90
(sw_c, sw_rl) in bit/s: None, 11854142.93
(sw_c, sw_rr) in bit/s: None, 30789924.37
(sw_fr, sw_c) in bit/s: None, 20405534.04
(sw_fr, zc_fr) in bit/s: None, 29225682.26
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 12545766.39
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 33387149.49
------------------- Find Path(s) ----------------------
Flow(id=4014, source=zc_fr, sink=['zc_rr', 'zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 46. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7667797.03
(sw_fl, zc_fl) in bit/s: None, 36775038.41
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 38443871.53
(sw_c, sw_fr) in bit/s: None, 27638336.90
(sw_c, sw_rl) in bit/s: None, 11854142.93
(sw_c, sw_rr) in bit/s: None, 30789924.37
(sw_fr, sw_c) in bit/s: None, 20405534.04
(sw_fr, zc_fr) in bit/s: None, 29225682.26
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 12545766.39
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 33387149.49
------------------- Find Path(s) ----------------------
Flow(id=3020, source=zc_fl, sink=['zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 47. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 36775038.41
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 38443871.53
(sw_c, sw_fr) in bit/s: None, 27638336.90
(sw_c, sw_rl) in bit/s: None, 11854142.93
(sw_c, sw_rr) in bit/s: None, 34599491.87
(sw_fr, sw_c) in bit/s: None, 20405534.04
(sw_fr, zc_fr) in bit/s: None, 29225682.26
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 12545766.39
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 37545200.96
------------------- Remove Resources ----------------------
----- 48. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 36775038.41
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 38443871.53
(sw_c, sw_fr) in bit/s: None, 27638336.90
(sw_c, sw_rl) in bit/s: None, 11854142.93
(sw_c, sw_rr) in bit/s: None, 34599491.87
(sw_fr, sw_c) in bit/s: None, 20405534.04
(sw_fr, zc_fr) in bit/s: None, 29225682.26
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 12545766.39
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 37545200.96
------------------- Find Path(s) ----------------------
Flow(id=3020, source=zc_fl, sink=['zc_rr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 49. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 36775038.41
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 38443871.53
(sw_c, sw_fr) in bit/s: None, 27638336.90
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 34599491.87
(sw_fr, sw_c) in bit/s: None, 20405534.04
(sw_fr, zc_fr) in bit/s: None, 29225682.26
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 37545200.96
------------------- Remove Resources ----------------------
----- 50. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 36775038.41
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 38443871.53
(sw_c, sw_fr) in bit/s: None, 27638336.90
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 34599491.87
(sw_fr, sw_c) in bit/s: None, 20405534.04
(sw_fr, zc_fr) in bit/s: None, 29225682.26
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 37545200.96
------------------- Find Path(s) ----------------------
Flow(id=3020, source=zc_fl, sink=['zc_rr', 'zc_rl', 'zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 51. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_rl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 36775038.41
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 38443871.53
(sw_c, sw_fr) in bit/s: None, 31586664.45
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 34599491.87
(sw_fr, sw_c) in bit/s: None, 20405534.04
(sw_fr, zc_fr) in bit/s: None, 33387132.23
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 37545200.96
------------------- Find Path(s) ----------------------
Flow(id=7002, source=infotainment, sink=['zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 52. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.209ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 40861138.31
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 38443871.53
(sw_c, sw_fr) in bit/s: None, 31586664.45
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 34599491.87
(sw_fr, sw_c) in bit/s: None, 20405534.04
(sw_fr, zc_fr) in bit/s: None, 33387132.23
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 18955831.03
(sw_rr, zc_rr) in bit/s: None, 37545200.96
------------------- Find Path(s) ----------------------
Flow(id=6053, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 53. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 44929221.24
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 42304205.00
(sw_c, sw_fr) in bit/s: None, 31586664.45
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 34599491.87
(sw_fr, sw_c) in bit/s: None, 20405534.04
(sw_fr, zc_fr) in bit/s: None, 33387132.23
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 37545200.96
------------------- Find Path(s) ----------------------
Flow(id=4001, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 54. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 48994059.44
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 46115245.30
(sw_c, sw_fr) in bit/s: None, 31586664.45
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 34599491.87
(sw_fr, sw_c) in bit/s: None, 23725939.35
(sw_fr, zc_fr) in bit/s: None, 33387132.23
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 37545200.96
------------------- Find Path(s) ----------------------
Flow(id=4046, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 55. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.630ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 48994059.44
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 46115245.30
(sw_c, sw_fr) in bit/s: None, 31586664.45
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 38472884.98
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 33387132.23
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 41699861.77
------------------- Remove Resources ----------------------
----- 56. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 48994059.44
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 46115245.30
(sw_c, sw_fr) in bit/s: None, 31586664.45
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 38472884.98
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 33387132.23
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 41699861.77
------------------- Find Path(s) ----------------------
Flow(id=4046, source=zc_fr, sink=['zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 57. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.630ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.630ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 31586664.45
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 38472884.98
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 33387132.23
(sw_rl, sw_c) in bit/s: None, 3459567.31
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 41699861.77
------------------- Find Path(s) ----------------------
Flow(id=5002, source=zc_rl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 58. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 35534995.79
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 38472884.98
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 37545196.14
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 41699861.77
------------------- Remove Resources ----------------------
----- 59. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 35534995.79
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 38472884.98
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 37545196.14
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 41699861.77
------------------- Find Path(s) ----------------------
Flow(id=5002, source=zc_rl, sink=['zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 60. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 35534995.79
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 42272320.30
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 37545196.14
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 45851143.60
------------------- Remove Resources ----------------------
----- 61. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 35534995.79
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 42272320.30
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 37545196.14
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 45851143.60
------------------- Find Path(s) ----------------------
Flow(id=4001, source=zc_fr, sink=['zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 62. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.630ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.630ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11458554.47
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 35534995.79
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 46167460.93
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 37545196.14
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 49999040.97
------------------- Find Path(s) ----------------------
Flow(id=3038, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 63. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 15221024.93
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 39483327.13
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 46167460.93
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 41699867.30
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 49999040.97
------------------- Remove Resources ----------------------
----- 64. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 15221024.93
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 39483327.13
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 46167460.93
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 41699867.30
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 49999040.97
------------------- Find Path(s) ----------------------
Flow(id=3038, source=zc_fl, sink=['zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 65. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 15221024.93
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 39483327.13
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 49939368.07
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 41699867.30
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 54143558.01
------------------- Find Path(s) ----------------------
Flow(id=3011, source=zc_fl, sink=['zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 66. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 18955452.18
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 39483327.13
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 53780849.09
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 41699867.30
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 58284682.13
------------------- Remove Resources ----------------------
----- 67. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 18955452.18
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 39483327.13
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 53780849.09
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 41699867.30
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 58284682.13
------------------- Find Path(s) ----------------------
Flow(id=3011, source=zc_fl, sink=['zc_rr', 'zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 68. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 18955452.18
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 10986019.06
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 43431656.10
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 53780849.09
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 45851137.36
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 58284682.13
------------------- Find Path(s) ----------------------
Flow(id=3031, source=zc_fl, sink=['infotainment'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 69. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.212ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 18955452.18
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 43431656.10
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 53780849.09
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 45851137.36
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 58284682.13
------------------- Remove Resources ----------------------
----- 70. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 18955452.18
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 43431656.10
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 53780849.09
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 45851137.36
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 58284682.13
------------------- Find Path(s) ----------------------
Flow(id=6053, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 71. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 18955452.18
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 47361713.37
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 53780849.09
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 49999011.78
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 58284682.13
------------------- Remove Resources ----------------------
----- 72. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 18955452.18
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 47361713.37
(sw_c, sw_rl) in bit/s: None, 15805524.15
(sw_c, sw_rr) in bit/s: None, 53780849.09
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 49999011.78
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 16720840.41
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 58284682.13
------------------- Find Path(s) ----------------------
Flow(id=6053, source=zc_rr, sink=['zc_fl', 'zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 73. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 18955452.18
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 47361713.37
(sw_c, sw_rl) in bit/s: None, 19756905.37
(sw_c, sw_rr) in bit/s: None, 53780849.09
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 49999011.78
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 20892496.25
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 58284682.13
------------------- Remove Resources ----------------------
----- 74. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 18955452.18
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 47361713.37
(sw_c, sw_rl) in bit/s: None, 19756905.37
(sw_c, sw_rr) in bit/s: None, 53780849.09
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 49999011.78
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 20892496.25
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 58284682.13
------------------- Find Path(s) ----------------------
Flow(id=7002, source=infotainment, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 75. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.209ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 22746507.14
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 51308517.95
(sw_c, sw_rl) in bit/s: None, 19756905.37
(sw_c, sw_rr) in bit/s: None, 53780849.09
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 54143510.54
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 20892496.25
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 58284682.13
------------------- Remove Resources ----------------------
----- 76. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 22746507.14
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 51308517.95
(sw_c, sw_rl) in bit/s: None, 19756905.37
(sw_c, sw_rr) in bit/s: None, 53780849.09
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 54143510.54
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 20892496.25
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 58284682.13
------------------- Find Path(s) ----------------------
Flow(id=7002, source=infotainment, sink=['zc_fl', 'zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 77. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.209ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 22746507.14
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 51308517.95
(sw_c, sw_rl) in bit/s: None, 19756905.37
(sw_c, sw_rr) in bit/s: None, 57622330.12
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 54143510.54
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 20892496.25
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 62422431.36
------------------- Remove Resources ----------------------
----- 78. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 22746507.14
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 51308517.95
(sw_c, sw_rl) in bit/s: None, 19756905.37
(sw_c, sw_rr) in bit/s: None, 57622330.12
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 54143510.54
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 20892496.25
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 62422431.36
------------------- Find Path(s) ----------------------
Flow(id=7002, source=infotainment, sink=['zc_fl', 'zc_fr', 'zc_rr', 'zc_rl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 79. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr', 'zc_rr', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.209ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.625ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 22746507.14
(sw_fl, zc_fl) in bit/s: None, 53055628.12
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 51308517.95
(sw_c, sw_rl) in bit/s: None, 23708286.38
(sw_c, sw_rr) in bit/s: None, 57622330.12
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 54143510.54
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 25060741.32
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 62422431.36
------------------- Find Path(s) ----------------------
Flow(id=7012, source=infotainment, sink=['zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 80. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.210ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 22746507.14
(sw_fl, zc_fl) in bit/s: None, 57130962.15
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 51308517.95
(sw_c, sw_rl) in bit/s: None, 23708286.38
(sw_c, sw_rr) in bit/s: None, 57622330.12
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 54143510.54
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 25060741.32
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 62422431.36
------------------- Find Path(s) ----------------------
Flow(id=3041, source=zc_fl, sink=['zc_rl'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 81. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 57130962.15
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 51308517.95
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 57622330.12
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 54143510.54
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 62422431.36
------------------- Remove Resources ----------------------
----- 82. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 57130962.15
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 51308517.95
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 57622330.12
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 54143510.54
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 62422431.36
------------------- Find Path(s) ----------------------
Flow(id=3041, source=zc_fl, sink=['zc_rl', 'zc_fr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 83. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 57130962.15
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 55255319.69
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 57622330.12
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 58284616.91
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 62422431.36
------------------- Remove Resources ----------------------
----- 84. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 57130962.15
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 55255319.69
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 57622330.12
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 58284616.91
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 62422431.36
------------------- Find Path(s) ----------------------
Flow(id=3041, source=zc_fl, sink=['zc_rl', 'zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 85. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 57130962.15
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 49958176.18
(sw_c, sw_fr) in bit/s: None, 55255319.69
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 61463806.13
(sw_fr, sw_c) in bit/s: None, 27023877.28
(sw_fr, zc_fr) in bit/s: None, 58284616.91
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 66556794.19
------------------- Find Path(s) ----------------------
Flow(id=4051, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 86. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 61193508.03
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 53801112.01
(sw_c, sw_fr) in bit/s: None, 55255319.69
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 61463806.13
(sw_fr, sw_c) in bit/s: None, 30299721.11
(sw_fr, zc_fr) in bit/s: None, 58284616.91
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 66556794.19
------------------- Remove Resources ----------------------
----- 87. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 61193508.03
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 53801112.01
(sw_c, sw_fr) in bit/s: None, 55255319.69
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 61463806.13
(sw_fr, sw_c) in bit/s: None, 30299721.11
(sw_fr, zc_fr) in bit/s: None, 58284616.91
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 66556794.19
------------------- Find Path(s) ----------------------
Flow(id=4051, source=zc_fr, sink=['zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 88. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 61193508.03
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 53801112.01
(sw_c, sw_fr) in bit/s: None, 55255319.69
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 65305293.88
(sw_fr, sw_c) in bit/s: None, 30299721.11
(sw_fr, zc_fr) in bit/s: None, 58284616.91
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 22662605.93
(sw_rr, zc_rr) in bit/s: None, 70687825.81
------------------- Find Path(s) ----------------------
Flow(id=6058, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 89. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 65246938.51
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 57622316.61
(sw_c, sw_fr) in bit/s: None, 55255319.69
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 65305293.88
(sw_fr, sw_c) in bit/s: None, 30299721.11
(sw_fr, zc_fr) in bit/s: None, 58284616.91
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 70687825.81
------------------- Remove Resources ----------------------
----- 90. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 65246938.51
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 57622316.61
(sw_c, sw_fr) in bit/s: None, 55255319.69
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 65305293.88
(sw_fr, sw_c) in bit/s: None, 30299721.11
(sw_fr, zc_fr) in bit/s: None, 58284616.91
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 70687825.81
------------------- Find Path(s) ----------------------
Flow(id=6058, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 91. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 65246938.51
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 57622316.61
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 65305293.88
(sw_fr, sw_c) in bit/s: None, 30299721.11
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 70687825.81
------------------- Find Path(s) ----------------------
Flow(id=4006, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 92. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 65246938.51
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 57622316.61
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 69146769.92
(sw_fr, sw_c) in bit/s: None, 33553444.43
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 74815457.49
------------------- Remove Resources ----------------------
----- 93. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 65246938.51
(sw_fl, infotainment) in bit/s: None, 14648024.66
(sw_c, sw_fl) in bit/s: None, 57622316.61
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 69146769.92
(sw_fr, sw_c) in bit/s: None, 33553444.43
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 74815457.49
------------------- Find Path(s) ----------------------
Flow(id=4006, source=zc_fr, sink=['zc_rr', 'infotainment'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 94. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 65246938.51
(sw_fl, infotainment) in bit/s: None, 18303331.85
(sw_c, sw_fl) in bit/s: None, 61463792.48
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 69146769.92
(sw_fr, sw_c) in bit/s: None, 33553444.43
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 74815457.49
------------------- Find Path(s) ----------------------
Flow(id=4035, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 95. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 65246938.51
(sw_fl, infotainment) in bit/s: None, 18303331.85
(sw_c, sw_fl) in bit/s: None, 61463792.48
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 72988247.21
(sw_fr, sw_c) in bit/s: None, 36785432.35
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 78939733.23
------------------- Remove Resources ----------------------
----- 96. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 65246938.51
(sw_fl, infotainment) in bit/s: None, 18303331.85
(sw_c, sw_fl) in bit/s: None, 61463792.48
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 72988247.21
(sw_fr, sw_c) in bit/s: None, 36785432.35
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 78939733.23
------------------- Find Path(s) ----------------------
Flow(id=4035, source=zc_fr, sink=['zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 97. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 69297112.68
(sw_fl, infotainment) in bit/s: None, 18303331.85
(sw_c, sw_fl) in bit/s: None, 65305269.75
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 72988247.21
(sw_fr, sw_c) in bit/s: None, 36785432.35
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 78939733.23
------------------- Remove Resources ----------------------
----- 98. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 69297112.68
(sw_fl, infotainment) in bit/s: None, 18303331.85
(sw_c, sw_fl) in bit/s: None, 65305269.75
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 72988247.21
(sw_fr, sw_c) in bit/s: None, 36785432.35
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 78939733.23
------------------- Find Path(s) ----------------------
Flow(id=4035, source=zc_fr, sink=['zc_rr', 'zc_fl', 'infotainment'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 99. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 69297112.68
(sw_fl, infotainment) in bit/s: None, 21955965.03
(sw_c, sw_fl) in bit/s: None, 65305269.75
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 72988247.21
(sw_fr, sw_c) in bit/s: None, 36785432.35
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 78939733.23
------------------- Find Path(s) ----------------------
Flow(id=4029, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 100. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 69297112.68
(sw_fl, infotainment) in bit/s: None, 21955965.03
(sw_c, sw_fl) in bit/s: None, 65305269.75
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 76829724.50
(sw_fr, sw_c) in bit/s: None, 39995884.31
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 83060652.96
------------------- Remove Resources ----------------------
----- 101. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 69297112.68
(sw_fl, infotainment) in bit/s: None, 21955965.03
(sw_c, sw_fl) in bit/s: None, 65305269.75
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 76829724.50
(sw_fr, sw_c) in bit/s: None, 39995884.31
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 83060652.96
------------------- Find Path(s) ----------------------
Flow(id=4029, source=zc_fr, sink=['zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 102. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 73344043.44
(sw_fl, infotainment) in bit/s: None, 21955965.03
(sw_c, sw_fl) in bit/s: None, 69146747.02
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 76829724.50
(sw_fr, sw_c) in bit/s: None, 39995884.31
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 83060652.96
------------------- Find Path(s) ----------------------
Flow(id=4048, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 103. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 73344043.44
(sw_fl, infotainment) in bit/s: None, 21955965.03
(sw_c, sw_fl) in bit/s: None, 69146747.02
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 80671205.55
(sw_fr, sw_c) in bit/s: None, 43185093.59
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 87178236.69
------------------- Remove Resources ----------------------
----- 104. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 73344043.44
(sw_fl, infotainment) in bit/s: None, 21955965.03
(sw_c, sw_fl) in bit/s: None, 69146747.02
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 80671205.55
(sw_fr, sw_c) in bit/s: None, 43185093.59
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 87178236.69
------------------- Find Path(s) ----------------------
Flow(id=4048, source=zc_fr, sink=['zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 105. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 77387746.99
(sw_fl, infotainment) in bit/s: None, 21955965.03
(sw_c, sw_fl) in bit/s: None, 72988228.06
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 80671205.55
(sw_fr, sw_c) in bit/s: None, 43185093.59
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 26342012.04
(sw_rr, zc_rr) in bit/s: None, 87178236.69
------------------- Find Path(s) ----------------------
Flow(id=6004, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 106. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.630ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 81428238.43
(sw_fl, infotainment) in bit/s: None, 21955965.03
(sw_c, sw_fl) in bit/s: None, 76714026.34
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 80671205.55
(sw_fr, sw_c) in bit/s: None, 43185093.59
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 87178236.69
------------------- Remove Resources ----------------------
----- 107. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 81428238.43
(sw_fl, infotainment) in bit/s: None, 21955965.03
(sw_c, sw_fl) in bit/s: None, 76714026.34
(sw_c, sw_fr) in bit/s: None, 59156489.06
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 80671205.55
(sw_fr, sw_c) in bit/s: None, 43185093.59
(sw_fr, zc_fr) in bit/s: None, 62422360.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 87178236.69
------------------- Find Path(s) ----------------------
Flow(id=6004, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 108. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.630ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.630ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 81428238.43
(sw_fl, infotainment) in bit/s: None, 21955965.03
(sw_c, sw_fl) in bit/s: None, 76714026.34
(sw_c, sw_fr) in bit/s: None, 63100255.25
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 80671205.55
(sw_fr, sw_c) in bit/s: None, 43185093.59
(sw_fr, zc_fr) in bit/s: None, 66556753.15
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 87178236.69
------------------- Find Path(s) ----------------------
Flow(id=3010, source=zc_fl, sink=['infotainment'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 109. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.214ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 81428238.43
(sw_fl, infotainment) in bit/s: None, 25547495.35
(sw_c, sw_fl) in bit/s: None, 76714026.34
(sw_c, sw_fr) in bit/s: None, 63100255.25
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 80671205.55
(sw_fr, sw_c) in bit/s: None, 43185093.59
(sw_fr, zc_fr) in bit/s: None, 66556753.15
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 87178236.69
------------------- Remove Resources ----------------------
----- 110. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 81428238.43
(sw_fl, infotainment) in bit/s: None, 25547495.35
(sw_c, sw_fl) in bit/s: None, 76714026.34
(sw_c, sw_fr) in bit/s: None, 63100255.25
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 80671205.55
(sw_fr, sw_c) in bit/s: None, 43185093.59
(sw_fr, zc_fr) in bit/s: None, 66556753.15
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 87178236.69
------------------- Find Path(s) ----------------------
Flow(id=6004, source=zc_rr, sink=['zc_fl', 'zc_fr', 'infotainment'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 111. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.630ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.630ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.630ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 81428238.43
(sw_fl, infotainment) in bit/s: None, 29197155.47
(sw_c, sw_fl) in bit/s: None, 76714026.34
(sw_c, sw_fr) in bit/s: None, 63100255.25
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 80671205.55
(sw_fr, sw_c) in bit/s: None, 43185093.59
(sw_fr, zc_fr) in bit/s: None, 66556753.15
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 87178236.69
------------------- Find Path(s) ----------------------
Flow(id=4009, source=zc_fr, sink=['infotainment'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 112. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 81428238.43
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 80640800.06
(sw_c, sw_fr) in bit/s: None, 63100255.25
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 80671205.55
(sw_fr, sw_c) in bit/s: None, 46353346.37
(sw_fr, zc_fr) in bit/s: None, 66556753.15
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 87178236.69
------------------- Remove Resources ----------------------
----- 113. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 81428238.43
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 80640800.06
(sw_c, sw_fr) in bit/s: None, 63100255.25
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 80671205.55
(sw_fr, sw_c) in bit/s: None, 46353346.37
(sw_fr, zc_fr) in bit/s: None, 66556753.15
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 87178236.69
------------------- Find Path(s) ----------------------
Flow(id=4009, source=zc_fr, sink=['infotainment', 'zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 114. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 85465502.51
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 80640800.06
(sw_c, sw_fr) in bit/s: None, 63100255.25
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 80671205.55
(sw_fr, sw_c) in bit/s: None, 46353346.37
(sw_fr, zc_fr) in bit/s: None, 66556753.15
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 87178236.69
------------------- Remove Resources ----------------------
----- 115. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 85465502.51
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 80640800.06
(sw_c, sw_fr) in bit/s: None, 63100255.25
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 80671205.55
(sw_fr, sw_c) in bit/s: None, 46353346.37
(sw_fr, zc_fr) in bit/s: None, 66556753.15
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 87178236.69
------------------- Find Path(s) ----------------------
Flow(id=4009, source=zc_fr, sink=['infotainment', 'zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 116. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment', 'zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 85465502.51
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 80640800.06
(sw_c, sw_fr) in bit/s: None, 63100255.25
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 84512692.87
(sw_fr, sw_c) in bit/s: None, 46353346.37
(sw_fr, zc_fr) in bit/s: None, 66556753.15
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 91292502.19
------------------- Find Path(s) ----------------------
Flow(id=4041, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 117. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.635ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 85465502.51
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 80640800.06
(sw_c, sw_fr) in bit/s: None, 63100255.25
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 88354180.19
(sw_fr, sw_c) in bit/s: None, 49500729.81
(sw_fr, zc_fr) in bit/s: None, 66556753.15
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 95403428.39
------------------- Remove Resources ----------------------
----- 118. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 26439115.54
(sw_fl, zc_fl) in bit/s: None, 85465502.51
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 80640800.06
(sw_c, sw_fr) in bit/s: None, 63100255.25
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 88354180.19
(sw_fr, sw_c) in bit/s: None, 49500729.81
(sw_fr, zc_fr) in bit/s: None, 66556753.15
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 95403428.39
------------------- Find Path(s) ----------------------
Flow(id=7012, source=infotainment, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 119. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.210ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 30216107.92
(sw_fl, zc_fl) in bit/s: None, 85465502.51
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 80640800.06
(sw_c, sw_fr) in bit/s: None, 67044014.62
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 88354180.19
(sw_fr, sw_c) in bit/s: None, 49500729.81
(sw_fr, zc_fr) in bit/s: None, 70687760.89
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 95403428.39
------------------- Remove Resources ----------------------
----- 120. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 30216107.92
(sw_fl, zc_fl) in bit/s: None, 85465502.51
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 80640800.06
(sw_c, sw_fr) in bit/s: None, 67044014.62
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 88354180.19
(sw_fr, sw_c) in bit/s: None, 49500729.81
(sw_fr, zc_fr) in bit/s: None, 70687760.89
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 95403428.39
------------------- Find Path(s) ----------------------
Flow(id=7012, source=infotainment, sink=['zc_fl', 'zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 121. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.210ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 30216107.92
(sw_fl, zc_fl) in bit/s: None, 85465502.51
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 80640800.06
(sw_c, sw_fr) in bit/s: None, 67044014.62
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 91952989.81
(sw_fr, sw_c) in bit/s: None, 49500729.81
(sw_fr, zc_fr) in bit/s: None, 70687760.89
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 99510988.65
------------------- Find Path(s) ----------------------
Flow(id=3027, source=zc_fl, sink=['zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 122. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 85465502.51
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 80640800.06
(sw_c, sw_fr) in bit/s: None, 67044014.62
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 95784352.46
(sw_fr, sw_c) in bit/s: None, 49500729.81
(sw_fr, zc_fr) in bit/s: None, 70687760.89
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 103615214.94
------------------- Remove Resources ----------------------
----- 123. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 85465502.51
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 80640800.06
(sw_c, sw_fr) in bit/s: None, 67044014.62
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 95784352.46
(sw_fr, sw_c) in bit/s: None, 49500729.81
(sw_fr, zc_fr) in bit/s: None, 70687760.89
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 103615214.94
------------------- Find Path(s) ----------------------
Flow(id=3027, source=zc_fl, sink=['zc_rr', 'zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 124. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 85465502.51
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 80640800.06
(sw_c, sw_fr) in bit/s: None, 70987774.36
(sw_c, sw_rl) in bit/s: None, 27659667.67
(sw_c, sw_rr) in bit/s: None, 95784352.46
(sw_fr, sw_c) in bit/s: None, 49500729.81
(sw_fr, zc_fr) in bit/s: None, 74815406.09
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 29225572.88
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 103615214.94
------------------- Find Path(s) ----------------------
Flow(id=4017, source=zc_fr, sink=['zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 125. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.635ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 85465502.51
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 80640800.06
(sw_c, sw_fr) in bit/s: None, 70987774.36
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 95784352.46
(sw_fr, sw_c) in bit/s: None, 52627192.14
(sw_fr, zc_fr) in bit/s: None, 74815406.09
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 103615214.94
------------------- Remove Resources ----------------------
----- 126. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 85465502.51
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 80640800.06
(sw_c, sw_fr) in bit/s: None, 70987774.36
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 95784352.46
(sw_fr, sw_c) in bit/s: None, 52627192.14
(sw_fr, zc_fr) in bit/s: None, 74815406.09
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 103615214.94
------------------- Find Path(s) ----------------------
Flow(id=4017, source=zc_fr, sink=['zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 127. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.635ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.635ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 89499503.71
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 84480827.79
(sw_c, sw_fr) in bit/s: None, 70987774.36
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 95784352.46
(sw_fr, sw_c) in bit/s: None, 52627192.14
(sw_fr, zc_fr) in bit/s: None, 74815406.09
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 103615214.94
------------------- Remove Resources ----------------------
----- 128. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 89499503.71
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 84480827.79
(sw_c, sw_fr) in bit/s: None, 70987774.36
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 95784352.46
(sw_fr, sw_c) in bit/s: None, 52627192.14
(sw_fr, zc_fr) in bit/s: None, 74815406.09
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 103615214.94
------------------- Find Path(s) ----------------------
Flow(id=4017, source=zc_fr, sink=['zc_rl', 'zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 129. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.635ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.635ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.635ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 89499503.71
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 84480827.79
(sw_c, sw_fr) in bit/s: None, 70987774.36
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 99803360.31
(sw_fr, sw_c) in bit/s: None, 52627192.14
(sw_fr, zc_fr) in bit/s: None, 74815406.09
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 107716091.25
------------------- Find Path(s) ----------------------
Flow(id=4042, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 130. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.636ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 93530275.70
(sw_fl, infotainment) in bit/s: None, 32846815.60
(sw_c, sw_fl) in bit/s: None, 88320854.00
(sw_c, sw_fr) in bit/s: None, 70987774.36
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 99803360.31
(sw_fr, sw_c) in bit/s: None, 55733128.69
(sw_fr, zc_fr) in bit/s: None, 74815406.09
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 107716091.25
------------------- Find Path(s) ----------------------
Flow(id=3004, source=zc_fl, sink=['infotainment'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 131. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.215ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 93530275.70
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 88320854.00
(sw_c, sw_fr) in bit/s: None, 70987774.36
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 99803360.31
(sw_fr, sw_c) in bit/s: None, 55733128.69
(sw_fr, zc_fr) in bit/s: None, 74815406.09
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 107716091.25
------------------- Find Path(s) ----------------------
Flow(id=4038, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 132. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 97557930.91
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 92160909.04
(sw_c, sw_fr) in bit/s: None, 70987774.36
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 99803360.31
(sw_fr, sw_c) in bit/s: None, 58819454.11
(sw_fr, zc_fr) in bit/s: None, 74815406.09
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 29994408.93
(sw_rr, zc_rr) in bit/s: None, 107716091.25
------------------- Find Path(s) ----------------------
Flow(id=6061, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 133. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 97557930.91
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 92160909.04
(sw_c, sw_fr) in bit/s: None, 74873810.96
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 99803360.31
(sw_fr, sw_c) in bit/s: None, 58819454.11
(sw_fr, zc_fr) in bit/s: None, 78939692.86
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 33619931.39
(sw_rr, zc_rr) in bit/s: None, 107716091.25
------------------- Find Path(s) ----------------------
Flow(id=4054, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 134. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 97557930.91
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 92160909.04
(sw_c, sw_fr) in bit/s: None, 74873810.96
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 103641953.86
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 78939692.86
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 33619931.39
(sw_rr, zc_rr) in bit/s: None, 111813695.85
------------------- Remove Resources ----------------------
----- 135. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 97557930.91
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 92160909.04
(sw_c, sw_fr) in bit/s: None, 74873810.96
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 103641953.86
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 78939692.86
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 33619931.39
(sw_rr, zc_rr) in bit/s: None, 111813695.85
------------------- Find Path(s) ----------------------
Flow(id=6061, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 136. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 101582293.52
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 95748336.29
(sw_c, sw_fr) in bit/s: None, 74873810.96
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 103641953.86
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 78939692.86
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 33619931.39
(sw_rr, zc_rr) in bit/s: None, 111813695.85
------------------- Remove Resources ----------------------
----- 137. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 101582293.52
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 95748336.29
(sw_c, sw_fr) in bit/s: None, 74873810.96
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 103641953.86
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 78939692.86
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 33619931.39
(sw_rr, zc_rr) in bit/s: None, 111813695.85
------------------- Find Path(s) ----------------------
Flow(id=4054, source=zc_fr, sink=['zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 138. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 105603475.39
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 99803366.68
(sw_c, sw_fr) in bit/s: None, 74873810.96
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 103641953.86
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 78939692.86
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 33619931.39
(sw_rr, zc_rr) in bit/s: None, 111813695.85
------------------- Remove Resources ----------------------
----- 139. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 33867504.15
(sw_fl, zc_fl) in bit/s: None, 105603475.39
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 99803366.68
(sw_c, sw_fr) in bit/s: None, 74873810.96
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 103641953.86
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 78939692.86
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 33619931.39
(sw_rr, zc_rr) in bit/s: None, 111813695.85
------------------- Find Path(s) ----------------------
Flow(id=3010, source=zc_fl, sink=['infotainment', 'zc_fr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 140. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.215ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 37491940.95
(sw_fl, zc_fl) in bit/s: None, 105603475.39
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 99803366.68
(sw_c, sw_fr) in bit/s: None, 78844893.87
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 103641953.86
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 83060605.18
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 33619931.39
(sw_rr, zc_rr) in bit/s: None, 111813695.85
------------------- Remove Resources ----------------------
----- 141. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 37491940.95
(sw_fl, zc_fl) in bit/s: None, 105603475.39
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 99803366.68
(sw_c, sw_fr) in bit/s: None, 78844893.87
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 103641953.86
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 83060605.18
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 33619931.39
(sw_rr, zc_rr) in bit/s: None, 111813695.85
------------------- Find Path(s) ----------------------
Flow(id=3010, source=zc_fl, sink=['infotainment', 'zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 142. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.215ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 37491940.95
(sw_fl, zc_fl) in bit/s: None, 105603475.39
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 99803366.68
(sw_c, sw_fr) in bit/s: None, 78844893.87
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 107197808.47
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 83060605.18
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 33619931.39
(sw_rr, zc_rr) in bit/s: None, 115907916.16
------------------- Find Path(s) ----------------------
Flow(id=6034, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 143. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 37491940.95
(sw_fl, zc_fl) in bit/s: None, 109621402.71
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 103369328.45
(sw_c, sw_fr) in bit/s: None, 78844893.87
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 107197808.47
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 83060605.18
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 37218882.32
(sw_rr, zc_rr) in bit/s: None, 115907916.16
------------------- Find Path(s) ----------------------
Flow(id=6036, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 144. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 37491940.95
(sw_fl, zc_fl) in bit/s: None, 113636177.72
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 107197828.06
(sw_c, sw_fr) in bit/s: None, 78844893.87
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 107197808.47
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 83060605.18
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 40791800.15
(sw_rr, zc_rr) in bit/s: None, 115907916.16
------------------- Remove Resources ----------------------
----- 145. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 37491940.95
(sw_fl, zc_fl) in bit/s: None, 113636177.72
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 107197828.06
(sw_c, sw_fr) in bit/s: None, 78844893.87
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 107197808.47
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 83060605.18
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 40791800.15
(sw_rr, zc_rr) in bit/s: None, 115907916.16
------------------- Find Path(s) ----------------------
Flow(id=6036, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 146. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 37491940.95
(sw_fl, zc_fl) in bit/s: None, 113636177.72
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 107197828.06
(sw_c, sw_fr) in bit/s: None, 82723386.91
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 107197808.47
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 87178212.80
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 40791800.15
(sw_rr, zc_rr) in bit/s: None, 115907916.16
------------------- Remove Resources ----------------------
----- 147. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 37491940.95
(sw_fl, zc_fl) in bit/s: None, 113636177.72
(sw_fl, infotainment) in bit/s: None, 36364318.36
(sw_c, sw_fl) in bit/s: None, 107197828.06
(sw_c, sw_fr) in bit/s: None, 82723386.91
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 107197808.47
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 87178212.80
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 40791800.15
(sw_rr, zc_rr) in bit/s: None, 115907916.16
------------------- Find Path(s) ----------------------
Flow(id=6036, source=zc_rr, sink=['zc_fl', 'zc_fr', 'infotainment'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 148. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 37491940.95
(sw_fl, zc_fl) in bit/s: None, 113636177.72
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 107197828.06
(sw_c, sw_fr) in bit/s: None, 82723386.91
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 107197808.47
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 87178212.80
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 40791800.15
(sw_rr, zc_rr) in bit/s: None, 115907916.16
------------------- Remove Resources ----------------------
----- 149. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 37491940.95
(sw_fl, zc_fl) in bit/s: None, 113636177.72
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 107197828.06
(sw_c, sw_fr) in bit/s: None, 82723386.91
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 107197808.47
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 87178212.80
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 40791800.15
(sw_rr, zc_rr) in bit/s: None, 115907916.16
------------------- Find Path(s) ----------------------
Flow(id=6034, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 150. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 37491940.95
(sw_fl, zc_fl) in bit/s: None, 113636177.72
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 107197828.06
(sw_c, sw_fr) in bit/s: None, 86662581.72
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 107197808.47
(sw_fr, sw_c) in bit/s: None, 61885375.68
(sw_fr, zc_fr) in bit/s: None, 91292432.36
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 40791800.15
(sw_rr, zc_rr) in bit/s: None, 115907916.16
------------------- Find Path(s) ----------------------
Flow(id=4020, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 151. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 37491940.95
(sw_fl, zc_fl) in bit/s: None, 117647756.13
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 111235316.51
(sw_c, sw_fr) in bit/s: None, 86662581.72
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 107197808.47
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 91292432.36
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 40791800.15
(sw_rr, zc_rr) in bit/s: None, 115907916.16
------------------- Remove Resources ----------------------
----- 152. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 37491940.95
(sw_fl, zc_fl) in bit/s: None, 117647756.13
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 111235316.51
(sw_c, sw_fr) in bit/s: None, 86662581.72
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 107197808.47
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 91292432.36
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 40791800.15
(sw_rr, zc_rr) in bit/s: None, 115907916.16
------------------- Find Path(s) ----------------------
Flow(id=4020, source=zc_fr, sink=['zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 153. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 37491940.95
(sw_fl, zc_fl) in bit/s: None, 117647756.13
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 111235316.51
(sw_c, sw_fr) in bit/s: None, 86662581.72
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 111277199.82
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 91292432.36
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 40791800.15
(sw_rr, zc_rr) in bit/s: None, 119998884.22
------------------- Find Path(s) ----------------------
Flow(id=7009, source=infotainment, sink=['zc_fr'], data_per_interval=688, sending_interval=0.45, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 154. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr'] , Bits:  688 , Interval:  450.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 41241068.64
(sw_fl, zc_fl) in bit/s: None, 117647756.13
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 111235316.51
(sw_c, sw_fr) in bit/s: None, 90601776.03
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 111277199.82
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 95403309.47
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 40791800.15
(sw_rr, zc_rr) in bit/s: None, 119998884.22
------------------- Find Path(s) ----------------------
Flow(id=7001, source=infotainment, sink=['zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 155. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.211ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 41241068.64
(sw_fl, zc_fl) in bit/s: None, 121704529.70
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 111235316.51
(sw_c, sw_fr) in bit/s: None, 90601776.03
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 111277199.82
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 95403309.47
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 40791800.15
(sw_rr, zc_rr) in bit/s: None, 119998884.22
------------------- Find Path(s) ----------------------
Flow(id=6060, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 156. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 41241068.64
(sw_fl, zc_fl) in bit/s: None, 125711263.24
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 114811666.39
(sw_c, sw_fr) in bit/s: None, 90601776.03
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 111277199.82
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 95403309.47
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 44338676.96
(sw_rr, zc_rr) in bit/s: None, 119998884.22
------------------- Remove Resources ----------------------
----- 157. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 41241068.64
(sw_fl, zc_fl) in bit/s: None, 125711263.24
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 114811666.39
(sw_c, sw_fr) in bit/s: None, 90601776.03
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 111277199.82
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 95403309.47
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 44338676.96
(sw_rr, zc_rr) in bit/s: None, 119998884.22
------------------- Find Path(s) ----------------------
Flow(id=6060, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 158. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 41241068.64
(sw_fl, zc_fl) in bit/s: None, 125711263.24
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 114811666.39
(sw_c, sw_fr) in bit/s: None, 94504584.62
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 111277199.82
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 99510864.09
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 44338676.96
(sw_rr, zc_rr) in bit/s: None, 119998884.22
------------------- Remove Resources ----------------------
----- 159. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 41241068.64
(sw_fl, zc_fl) in bit/s: None, 125711263.24
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 114811666.39
(sw_c, sw_fr) in bit/s: None, 94504584.62
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 111277199.82
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 99510864.09
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 44338676.96
(sw_rr, zc_rr) in bit/s: None, 119998884.22
------------------- Find Path(s) ----------------------
Flow(id=3004, source=zc_fl, sink=['infotainment', 'zc_rr'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 160. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.215ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 44827077.80
(sw_fl, zc_fl) in bit/s: None, 125711263.24
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 114811666.39
(sw_c, sw_fr) in bit/s: None, 94504584.62
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 114812014.08
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 99510864.09
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 44338676.96
(sw_rr, zc_rr) in bit/s: None, 124087243.25
------------------- Remove Resources ----------------------
----- 161. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 44827077.80
(sw_fl, zc_fl) in bit/s: None, 125711263.24
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 114811666.39
(sw_c, sw_fr) in bit/s: None, 94504584.62
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 114812014.08
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 99510864.09
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 44338676.96
(sw_rr, zc_rr) in bit/s: None, 124087243.25
------------------- Find Path(s) ----------------------
Flow(id=3004, source=zc_fl, sink=['infotainment', 'zc_rr', 'zc_fr'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 162. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_rr', 'zc_fr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.215ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 44827077.80
(sw_fl, zc_fl) in bit/s: None, 125711263.24
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 114811666.39
(sw_c, sw_fr) in bit/s: None, 98442492.31
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 114812014.08
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 103615694.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 44338676.96
(sw_rr, zc_rr) in bit/s: None, 124087243.25
------------------- Find Path(s) ----------------------
Flow(id=6070, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 163. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 44827077.80
(sw_fl, zc_fl) in bit/s: None, 129714806.39
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 118638708.93
(sw_c, sw_fr) in bit/s: None, 98442492.31
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 114812014.08
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 103615694.64
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 47859905.05
(sw_rr, zc_rr) in bit/s: None, 124087243.25
------------------- Find Path(s) ----------------------
Flow(id=6057, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 164. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 44827077.80
(sw_fl, zc_fl) in bit/s: None, 129714806.39
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 118638708.93
(sw_c, sw_fr) in bit/s: None, 102340792.43
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 114812014.08
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 107716584.94
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 51355637.00
(sw_rr, zc_rr) in bit/s: None, 124087243.25
------------------- Remove Resources ----------------------
----- 165. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 44827077.80
(sw_fl, zc_fl) in bit/s: None, 129714806.39
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 118638708.93
(sw_c, sw_fr) in bit/s: None, 102340792.43
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 114812014.08
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 107716584.94
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 51355637.00
(sw_rr, zc_rr) in bit/s: None, 124087243.25
------------------- Find Path(s) ----------------------
Flow(id=6057, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 166. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 44827077.80
(sw_fl, zc_fl) in bit/s: None, 133715132.44
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 122465735.95
(sw_c, sw_fr) in bit/s: None, 102340792.43
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 114812014.08
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 107716584.94
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 51355637.00
(sw_rr, zc_rr) in bit/s: None, 124087243.25
------------------- Find Path(s) ----------------------
Flow(id=6035, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 167. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.635ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 44827077.80
(sw_fl, zc_fl) in bit/s: None, 133715132.44
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 122465735.95
(sw_c, sw_fr) in bit/s: None, 106276960.19
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: None, 114812014.08
(sw_fr, sw_c) in bit/s: None, 64931429.23
(sw_fr, zc_fr) in bit/s: None, 111814175.04
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 54826386.66
(sw_rr, zc_rr) in bit/s: None, 124087243.25
------------------- Find Path(s) ----------------------
Flow(id=1111, source=camera_front, sink=['adas'], data_per_interval=11520, sending_interval=0.000065, deadline=0.001, max_frame_size=11424, priority=0, redundancy=False)
Path found: [[('camera_front', 'sw_fr', 0), ('sw_fr', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]]
------------------- Reserve Resources ----------------------
----- 168. Flow Operation -- add -----
Flow Details: Source:  camera_front , Destination:  ['adas'] , Bits:  11520 , Interval:  0.065 ms , Deadline:  1.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('camera_front', 'sw_fr', 0), ('sw_fr', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.636ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 44827077.80
(sw_fl, zc_fl) in bit/s: None, 133715132.44
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 122465735.95
(sw_c, sw_fr) in bit/s: None, 106276960.19
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: 450390563.34, 115570513.61
(sw_fr, sw_c) in bit/s: 225672462.41, 65292091.47
(sw_fr, zc_fr) in bit/s: None, 111814175.04
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 54826386.66
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 124087243.25
------------------- Find Path(s) ----------------------
Flow(id=3034, source=zc_fl, sink=['zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 169. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 133715132.44
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 122465735.95
(sw_c, sw_fr) in bit/s: None, 106276960.19
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: 450390563.34, 119422839.25
(sw_fr, sw_c) in bit/s: 225672462.41, 65292091.47
(sw_fr, zc_fr) in bit/s: None, 111814175.04
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 54826386.66
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 128171577.71
------------------- Remove Resources ----------------------
----- 170. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 133715132.44
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 122465735.95
(sw_c, sw_fr) in bit/s: None, 106276960.19
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: 450390563.34, 119422839.25
(sw_fr, sw_c) in bit/s: 225672462.41, 65292091.47
(sw_fr, zc_fr) in bit/s: None, 111814175.04
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 54826386.66
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 128171577.71
------------------- Find Path(s) ----------------------
Flow(id=6070, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 171. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.635ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.635ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 133715132.44
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 122465735.95
(sw_c, sw_fr) in bit/s: None, 110213127.95
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: 450390563.34, 119422839.25
(sw_fr, sw_c) in bit/s: 225672462.41, 65292091.47
(sw_fr, zc_fr) in bit/s: None, 115908443.31
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 54826386.66
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 128171577.71
------------------- Find Path(s) ----------------------
Flow(id=4034, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 172. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.639ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 133715132.44
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 122465735.95
(sw_c, sw_fr) in bit/s: None, 110213127.95
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 115908443.31
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 54826386.66
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Find Path(s) ----------------------
Flow(id=6023, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 173. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.636ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 133715132.44
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 122465735.95
(sw_c, sw_fr) in bit/s: None, 114149308.90
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 119999431.41
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 58272484.66
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Remove Resources ----------------------
----- 174. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 133715132.44
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 122465735.95
(sw_c, sw_fr) in bit/s: None, 114149308.90
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 119999431.41
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 58272484.66
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Find Path(s) ----------------------
Flow(id=6023, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 175. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.635ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.636ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 137712344.67
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 126292797.90
(sw_c, sw_fr) in bit/s: None, 114149308.90
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 119999431.41
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 58272484.66
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Remove Resources ----------------------
----- 176. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 137712344.67
(sw_fl, infotainment) in bit/s: None, 40000730.18
(sw_c, sw_fl) in bit/s: None, 126292797.90
(sw_c, sw_fr) in bit/s: None, 114149308.90
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 119999431.41
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 58272484.66
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Find Path(s) ----------------------
Flow(id=6023, source=zc_rr, sink=['zc_fr', 'zc_fl', 'infotainment'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 177. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.635ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.635ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.636ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 137712344.67
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 126292797.90
(sw_c, sw_fr) in bit/s: None, 114149308.90
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 119999431.41
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 58272484.66
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Find Path(s) ----------------------
Flow(id=6014, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 178. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.636ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 137712344.67
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 126292797.90
(sw_c, sw_fr) in bit/s: None, 118085595.41
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 124087420.47
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 61695541.48
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Remove Resources ----------------------
----- 179. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 137712344.67
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 126292797.90
(sw_c, sw_fr) in bit/s: None, 118085595.41
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 124087420.47
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 61695541.48
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Find Path(s) ----------------------
Flow(id=6014, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 180. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.636ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.636ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 141706707.42
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 130120015.14
(sw_c, sw_fr) in bit/s: None, 118085595.41
(sw_c, sw_rl) in bit/s: None, 31598832.93
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 124087420.47
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 33386999.89
(sw_rr, sw_c) in bit/s: None, 61695541.48
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Find Path(s) ----------------------
Flow(id=6041, source=zc_rr, sink=['zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 181. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 141706707.42
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 130120015.14
(sw_c, sw_fr) in bit/s: None, 118085595.41
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 124087420.47
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 65092581.64
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Remove Resources ----------------------
----- 182. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 141706707.42
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 130120015.14
(sw_c, sw_fr) in bit/s: None, 118085595.41
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 124087420.47
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 65092581.64
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Find Path(s) ----------------------
Flow(id=6041, source=zc_rr, sink=['zc_rl', 'zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 183. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 141706707.42
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 130120015.14
(sw_c, sw_fr) in bit/s: None, 122021755.25
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 128171736.95
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 65092581.64
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Remove Resources ----------------------
----- 184. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 141706707.42
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 130120015.14
(sw_c, sw_fr) in bit/s: None, 122021755.25
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 128171736.95
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 65092581.64
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Find Path(s) ----------------------
Flow(id=6041, source=zc_rr, sink=['zc_rl', 'zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 185. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fr', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 145697514.06
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 133947046.03
(sw_c, sw_fr) in bit/s: None, 122021755.25
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 128171736.95
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 65092581.64
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Remove Resources ----------------------
----- 186. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 48385236.14
(sw_fl, zc_fl) in bit/s: None, 145697514.06
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 133947046.03
(sw_c, sw_fr) in bit/s: None, 122021755.25
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 128171736.95
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 65092581.64
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Find Path(s) ----------------------
Flow(id=7001, source=infotainment, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 187. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.211ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 52106928.79
(sw_fl, zc_fl) in bit/s: None, 145697514.06
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 133947046.03
(sw_c, sw_fr) in bit/s: None, 125716184.91
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 123508594.11
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 132252746.03
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 65092581.64
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 132252731.66
------------------- Find Path(s) ----------------------
Flow(id=3006, source=zc_fl, sink=['zc_rr'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 188. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 145697514.06
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 133947046.03
(sw_c, sw_fr) in bit/s: None, 125716184.91
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 127079919.33
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 132252746.03
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 65092581.64
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 136331281.85
------------------- Find Path(s) ----------------------
Flow(id=7003, source=infotainment, sink=['zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 189. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.212ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 149744632.87
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 133947046.03
(sw_c, sw_fr) in bit/s: None, 125716184.91
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 127079919.33
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 132252746.03
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 65092581.64
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 136331281.85
------------------- Remove Resources ----------------------
----- 190. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 149744632.87
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 133947046.03
(sw_c, sw_fr) in bit/s: None, 125716184.91
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 127079919.33
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 132252746.03
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 65092581.64
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 136331281.85
------------------- Find Path(s) ----------------------
Flow(id=6035, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 191. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 153730684.53
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 137774088.57
(sw_c, sw_fr) in bit/s: None, 125716184.91
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 127079919.33
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 132252746.03
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 65092581.64
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 136331281.85
------------------- Find Path(s) ----------------------
Flow(id=6018, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 192. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 153730684.53
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 137774088.57
(sw_c, sw_fr) in bit/s: None, 129844423.95
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 127079919.33
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 136331296.70
(sw_rl, sw_c) in bit/s: None, 6895315.28
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 68469644.22
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 136331281.85
------------------- Find Path(s) ----------------------
Flow(id=5006, source=zc_rl, sink=['zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 193. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 157713569.83
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 141547963.65
(sw_c, sw_fr) in bit/s: None, 129844423.95
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 127079919.33
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 136331296.70
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 68469644.22
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 136331281.85
------------------- Remove Resources ----------------------
----- 194. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 157713569.83
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 141547963.65
(sw_c, sw_fr) in bit/s: None, 129844423.95
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 127079919.33
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 136331296.70
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 68469644.22
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 136331281.85
------------------- Find Path(s) ----------------------
Flow(id=5006, source=zc_rl, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 195. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 157713569.83
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 141547963.65
(sw_c, sw_fr) in bit/s: None, 133522540.97
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 127079919.33
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 140405756.52
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 68469644.22
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 136331281.85
------------------- Remove Resources ----------------------
----- 196. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 157713569.83
(sw_fl, infotainment) in bit/s: None, 43637142.00
(sw_c, sw_fl) in bit/s: None, 141547963.65
(sw_c, sw_fr) in bit/s: None, 133522540.97
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 127079919.33
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 140405756.52
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 68469644.22
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 136331281.85
------------------- Find Path(s) ----------------------
Flow(id=5006, source=zc_rl, sink=['zc_fl', 'zc_fr', 'infotainment'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 197. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl', 'zc_fr', 'infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 157713569.83
(sw_fl, infotainment) in bit/s: None, 47273528.80
(sw_c, sw_fl) in bit/s: None, 141547963.65
(sw_c, sw_fr) in bit/s: None, 133522540.97
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 127079919.33
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 140405756.52
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 68469644.22
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 136331281.85
------------------- Remove Resources ----------------------
----- 198. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl', 'zc_fr', 'infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 157713569.83
(sw_fl, infotainment) in bit/s: None, 47273528.80
(sw_c, sw_fl) in bit/s: None, 141547963.65
(sw_c, sw_fr) in bit/s: None, 133522540.97
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 127079919.33
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 140405756.52
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 68469644.22
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 136331281.85
------------------- Find Path(s) ----------------------
Flow(id=5006, source=zc_rl, sink=['zc_fl', 'zc_fr', 'infotainment', 'zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 199. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl', 'zc_fr', 'infotainment', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.626ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 157713569.83
(sw_fl, infotainment) in bit/s: None, 47273528.80
(sw_c, sw_fl) in bit/s: None, 141547963.65
(sw_c, sw_fr) in bit/s: None, 133522540.97
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 130930788.00
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 140405756.52
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 68469644.22
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 140405741.20
------------------- Find Path(s) ----------------------
Flow(id=6020, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 200. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 157713569.83
(sw_fl, infotainment) in bit/s: None, 47273528.80
(sw_c, sw_fl) in bit/s: None, 141547963.65
(sw_c, sw_fr) in bit/s: None, 137713718.07
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 130930788.00
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 144476885.89
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 140405741.20
------------------- Remove Resources ----------------------
----- 201. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 157713569.83
(sw_fl, infotainment) in bit/s: None, 47273528.80
(sw_c, sw_fl) in bit/s: None, 141547963.65
(sw_c, sw_fr) in bit/s: None, 137713718.07
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 130930788.00
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 144476885.89
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 140405741.20
------------------- Find Path(s) ----------------------
Flow(id=6020, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 202. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 47273528.80
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 137713718.07
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 130930788.00
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 144476885.89
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 140405741.20
------------------- Remove Resources ----------------------
----- 203. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 47273528.80
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 137713718.07
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 130930788.00
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 144476885.89
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 140405741.20
------------------- Find Path(s) ----------------------
Flow(id=6020, source=zc_rr, sink=['zc_fr', 'zc_fl', 'infotainment'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 204. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 55627897.83
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 137713718.07
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 130930788.00
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 144476885.89
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 140405741.20
------------------- Find Path(s) ----------------------
Flow(id=3015, source=zc_fl, sink=['zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 205. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 59121169.09
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 137713718.07
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 134781644.15
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 144476885.89
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 144476879.27
------------------- Remove Resources ----------------------
----- 206. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 59121169.09
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 137713718.07
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 134781644.15
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 144476885.89
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 144476879.27
------------------- Find Path(s) ----------------------
Flow(id=3015, source=zc_fl, sink=['zc_rr', 'zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 207. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 59121169.09
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 141322497.01
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 134781644.15
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 148544732.76
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 144476879.27
------------------- Remove Resources ----------------------
----- 208. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 59121169.09
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 141322497.01
(sw_c, sw_rl) in bit/s: None, 35548686.72
(sw_c, sw_rr) in bit/s: 450390563.34, 134781644.15
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 148544732.76
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 37545025.47
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 144476879.27
------------------- Find Path(s) ----------------------
Flow(id=3015, source=zc_fl, sink=['zc_rr', 'zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 209. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 59121169.09
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 141322497.01
(sw_c, sw_rl) in bit/s: None, 39498540.52
(sw_c, sw_rr) in bit/s: 450390563.34, 134781644.15
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 148544732.76
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 41699653.77
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 144476879.27
------------------- Find Path(s) ----------------------
Flow(id=3003, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 210. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 62590532.83
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 145248288.35
(sw_c, sw_rl) in bit/s: None, 39498540.52
(sw_c, sw_rr) in bit/s: 450390563.34, 134781644.15
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 152609758.40
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 41699653.77
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 144476879.27
------------------- Remove Resources ----------------------
----- 211. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 62590532.83
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 145248288.35
(sw_c, sw_rl) in bit/s: None, 39498540.52
(sw_c, sw_rr) in bit/s: 450390563.34, 134781644.15
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 152609758.40
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 41699653.77
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 144476879.27
------------------- Find Path(s) ----------------------
Flow(id=3003, source=zc_fl, sink=['zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 212. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 62590532.83
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 145248288.35
(sw_c, sw_rl) in bit/s: None, 39498540.52
(sw_c, sw_rr) in bit/s: 450390563.34, 138632700.52
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 152609758.40
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 41699653.77
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 148545179.08
------------------- Remove Resources ----------------------
----- 213. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 62590532.83
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 145248288.35
(sw_c, sw_rl) in bit/s: None, 39498540.52
(sw_c, sw_rr) in bit/s: 450390563.34, 138632700.52
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 152609758.40
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 41699653.77
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 148545179.08
------------------- Find Path(s) ----------------------
Flow(id=7003, source=infotainment, sink=['zc_fl', 'zc_rl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 214. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.212ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 66271908.27
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 145248288.35
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 138632700.52
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 152609758.40
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 148545179.08
------------------- Remove Resources ----------------------
----- 215. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 66271908.27
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 145248288.35
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 138632700.52
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 152609758.40
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 148545179.08
------------------- Find Path(s) ----------------------
Flow(id=7003, source=infotainment, sink=['zc_fl', 'zc_rl', 'zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 216. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.212ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 66271908.27
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 149173876.18
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 138632700.52
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 156671077.39
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 148545179.08
------------------- Remove Resources ----------------------
----- 217. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 66271908.27
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 149173876.18
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 138632700.52
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 156671077.39
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 148545179.08
------------------- Find Path(s) ----------------------
Flow(id=7003, source=infotainment, sink=['zc_fl', 'zc_rl', 'zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 218. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.212ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 66271908.27
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 149173876.18
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 142483569.18
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 156671077.39
(sw_rl, sw_c) in bit/s: None, 10307477.34
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 152609780.52
------------------- Find Path(s) ----------------------
Flow(id=5000, source=zc_rl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.06, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 219. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  60.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 66271908.27
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 50909895.59
(sw_c, sw_fl) in bit/s: None, 145428158.13
(sw_c, sw_fr) in bit/s: None, 153099516.77
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 142483569.18
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 160729238.17
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 71818977.02
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 152609780.52
------------------- Find Path(s) ----------------------
Flow(id=6010, source=zc_rr, sink=['infotainment'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 220. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.639ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 66271908.27
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 54546282.39
(sw_c, sw_fl) in bit/s: None, 149255200.67
(sw_c, sw_fr) in bit/s: None, 153099516.77
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 142483569.18
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 160729238.17
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 75144933.82
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 152609780.52
------------------- Remove Resources ----------------------
----- 221. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  60.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 66271908.27
(sw_fl, zc_fl) in bit/s: None, 161693255.58
(sw_fl, infotainment) in bit/s: None, 54546282.39
(sw_c, sw_fl) in bit/s: None, 149255200.67
(sw_c, sw_fr) in bit/s: None, 153099516.77
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 142483569.18
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 160729238.17
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 75144933.82
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 152609780.52
------------------- Find Path(s) ----------------------
Flow(id=5000, source=zc_rl, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.06, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 222. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  60.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.627ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 66271908.27
(sw_fl, zc_fl) in bit/s: None, 165669929.25
(sw_fl, infotainment) in bit/s: None, 54546282.39
(sw_c, sw_fl) in bit/s: None, 152909986.95
(sw_c, sw_fr) in bit/s: None, 153099516.77
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 142483569.18
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 160729238.17
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 75144933.82
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 152609780.52
------------------- Find Path(s) ----------------------
Flow(id=3009, source=zc_fl, sink=['zc_rr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 223. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.635ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 165669929.25
(sw_fl, infotainment) in bit/s: None, 54546282.39
(sw_c, sw_fl) in bit/s: None, 152909986.95
(sw_c, sw_fr) in bit/s: None, 153099516.77
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 146334421.16
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 160729238.17
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 75144933.82
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 156671060.19
------------------- Find Path(s) ----------------------
Flow(id=6017, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 224. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 165669929.25
(sw_fl, infotainment) in bit/s: None, 54546282.39
(sw_c, sw_fl) in bit/s: None, 152909986.95
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 146334421.16
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 78447595.45
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 156671060.19
------------------- Remove Resources ----------------------
----- 225. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 165669929.25
(sw_fl, infotainment) in bit/s: None, 54546282.39
(sw_c, sw_fl) in bit/s: None, 152909986.95
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 146334421.16
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 78447595.45
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 156671060.19
------------------- Find Path(s) ----------------------
Flow(id=6017, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 226. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 169643340.09
(sw_fl, infotainment) in bit/s: None, 54546282.39
(sw_c, sw_fl) in bit/s: None, 156909331.04
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 146334421.16
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 78447595.45
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 156671060.19
------------------- Remove Resources ----------------------
----- 227. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 169643340.09
(sw_fl, infotainment) in bit/s: None, 54546282.39
(sw_c, sw_fl) in bit/s: None, 156909331.04
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 146334421.16
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 78447595.45
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 156671060.19
------------------- Find Path(s) ----------------------
Flow(id=6017, source=zc_rr, sink=['zc_fr', 'zc_fl', 'infotainment'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 228. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.639ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 169643340.09
(sw_fl, infotainment) in bit/s: None, 58182669.19
(sw_c, sw_fl) in bit/s: None, 156909331.04
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 146334421.16
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 78447595.45
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 156671060.19
------------------- Remove Resources ----------------------
----- 229. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 169643340.09
(sw_fl, infotainment) in bit/s: None, 58182669.19
(sw_c, sw_fl) in bit/s: None, 156909331.04
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 146334421.16
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 78447595.45
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 156671060.19
------------------- Find Path(s) ----------------------
Flow(id=6010, source=zc_rr, sink=['infotainment', 'zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 230. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['infotainment', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.639ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 173613599.62
(sw_fl, infotainment) in bit/s: None, 58182669.19
(sw_c, sw_fl) in bit/s: None, 156909331.04
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 146334421.16
(sw_fr, sw_c) in bit/s: 225672462.41, 68334468.32
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 78447595.45
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 156671060.19
------------------- Find Path(s) ----------------------
Flow(id=4033, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 231. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 173613599.62
(sw_fl, infotainment) in bit/s: None, 58182669.19
(sw_c, sw_fl) in bit/s: None, 156909331.04
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 150242002.04
(sw_fr, sw_c) in bit/s: 225672462.41, 71356403.67
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 78447595.45
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 160729070.10
------------------- Remove Resources ----------------------
----- 232. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 173613599.62
(sw_fl, infotainment) in bit/s: None, 58182669.19
(sw_c, sw_fl) in bit/s: None, 156909331.04
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 150242002.04
(sw_fr, sw_c) in bit/s: 225672462.41, 71356403.67
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 78447595.45
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 160729070.10
------------------- Find Path(s) ----------------------
Flow(id=4033, source=zc_fr, sink=['zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 233. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 177580680.68
(sw_fl, infotainment) in bit/s: None, 58182669.19
(sw_c, sw_fl) in bit/s: None, 160495220.37
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 150242002.04
(sw_fr, sw_c) in bit/s: 225672462.41, 71356403.67
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 78447595.45
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 160729070.10
------------------- Find Path(s) ----------------------
Flow(id=4057, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 234. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 177580680.68
(sw_fl, infotainment) in bit/s: None, 58182669.19
(sw_c, sw_fl) in bit/s: None, 160495220.37
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 154094346.99
(sw_fr, sw_c) in bit/s: 225672462.41, 74359169.25
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 78447595.45
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 164783888.71
------------------- Find Path(s) ----------------------
Flow(id=3021, source=zc_fl, sink=['infotainment'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 235. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.219ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 177580680.68
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 160495220.37
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 154094346.99
(sw_fr, sw_c) in bit/s: 225672462.41, 74359169.25
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 78447595.45
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 164783888.71
------------------- Find Path(s) ----------------------
Flow(id=4044, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 236. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.641ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 177580680.68
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 160495220.37
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 78447595.45
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Remove Resources ----------------------
----- 237. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 177580680.68
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 160495220.37
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 78447595.45
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Find Path(s) ----------------------
Flow(id=4044, source=zc_fr, sink=['zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 238. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.641ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.641ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 181544648.01
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 164316517.75
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 78447595.45
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Find Path(s) ----------------------
Flow(id=6062, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 239. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 185505475.25
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 168264038.63
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 81727205.79
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Remove Resources ----------------------
----- 240. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 185505475.25
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 168264038.63
(sw_c, sw_fr) in bit/s: None, 157205913.78
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 164784008.58
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 81727205.79
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Find Path(s) ----------------------
Flow(id=6062, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 241. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 185505475.25
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 168264038.63
(sw_c, sw_fr) in bit/s: None, 161136028.93
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 168835509.06
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 81727205.79
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Find Path(s) ----------------------
Flow(id=6042, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 242. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.641ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 189463166.13
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 172088206.49
(sw_c, sw_fr) in bit/s: None, 161136028.93
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 168835509.06
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 84984005.32
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Remove Resources ----------------------
----- 243. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 189463166.13
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 172088206.49
(sw_c, sw_fr) in bit/s: None, 161136028.93
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 168835509.06
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 84984005.32
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Find Path(s) ----------------------
Flow(id=6042, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 244. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.641ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.641ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 189463166.13
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 172088206.49
(sw_c, sw_fr) in bit/s: None, 165066144.08
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 172883743.56
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 84984005.32
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Find Path(s) ----------------------
Flow(id=6049, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 245. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 189463166.13
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 172088206.49
(sw_c, sw_fr) in bit/s: None, 168996248.08
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 176928682.03
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Remove Resources ----------------------
----- 246. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 189463166.13
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 172088206.49
(sw_c, sw_fr) in bit/s: None, 168996248.08
(sw_c, sw_rl) in bit/s: None, 43448394.93
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 176928682.03
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 45850896.46
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Find Path(s) ----------------------
Flow(id=6049, source=zc_rr, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 247. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 189463166.13
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 172088206.49
(sw_c, sw_fr) in bit/s: None, 168996248.08
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 176928682.03
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Remove Resources ----------------------
----- 248. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 189463166.13
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 172088206.49
(sw_c, sw_fr) in bit/s: None, 168996248.08
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 176928682.03
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Find Path(s) ----------------------
Flow(id=6049, source=zc_rr, sink=['zc_fr', 'zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 249. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 193417690.31
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 175912361.14
(sw_c, sw_fr) in bit/s: None, 168996248.08
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 176928682.03
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Remove Resources ----------------------
----- 250. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 69701707.57
(sw_fl, zc_fl) in bit/s: None, 193417690.31
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 175912361.14
(sw_c, sw_fr) in bit/s: None, 168996248.08
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 176928682.03
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Find Path(s) ----------------------
Flow(id=3021, source=zc_fl, sink=['infotainment', 'zc_fr'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 251. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.219ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.636ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 73107483.15
(sw_fl, zc_fl) in bit/s: None, 193417690.31
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 175912361.14
(sw_c, sw_fr) in bit/s: None, 172463015.10
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 180970569.66
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Remove Resources ----------------------
----- 252. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 73107483.15
(sw_fl, zc_fl) in bit/s: None, 193417690.31
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 175912361.14
(sw_c, sw_fr) in bit/s: None, 172463015.10
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 157946672.40
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 180970569.66
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 168835386.11
------------------- Find Path(s) ----------------------
Flow(id=3021, source=zc_fl, sink=['infotainment', 'zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 253. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.219ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.636ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.636ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 73107483.15
(sw_fl, zc_fl) in bit/s: None, 193417690.31
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 175912361.14
(sw_c, sw_fr) in bit/s: None, 172463015.10
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 161554948.27
(sw_fr, sw_c) in bit/s: 225672462.41, 77342384.19
(sw_fr, zc_fr) in bit/s: None, 180970569.66
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 172883783.52
------------------- Find Path(s) ----------------------
Flow(id=4060, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 254. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 73107483.15
(sw_fl, zc_fl) in bit/s: None, 193417690.31
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 175912361.14
(sw_c, sw_fr) in bit/s: None, 172463015.10
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 165588845.70
(sw_fr, sw_c) in bit/s: 225672462.41, 80306696.20
(sw_fr, zc_fr) in bit/s: None, 180970569.66
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 176928813.64
------------------- Find Path(s) ----------------------
Flow(id=7011, source=infotainment, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 255. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.212ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 73107483.15
(sw_fl, zc_fl) in bit/s: None, 197447248.15
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 175912361.14
(sw_c, sw_fr) in bit/s: None, 172463015.10
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 165588845.70
(sw_fr, sw_c) in bit/s: 225672462.41, 80306696.20
(sw_fr, zc_fr) in bit/s: None, 180970569.66
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 176928813.64
------------------- Remove Resources ----------------------
----- 256. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 73107483.15
(sw_fl, zc_fl) in bit/s: None, 197447248.15
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 175912361.14
(sw_c, sw_fr) in bit/s: None, 172463015.10
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 165588845.70
(sw_fr, sw_c) in bit/s: 225672462.41, 80306696.20
(sw_fr, zc_fr) in bit/s: None, 180970569.66
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 176928813.64
------------------- Find Path(s) ----------------------
Flow(id=4060, source=zc_fr, sink=['zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 257. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 73107483.15
(sw_fl, zc_fl) in bit/s: None, 201397141.99
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 179399852.43
(sw_c, sw_fr) in bit/s: None, 172463015.10
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 165588845.70
(sw_fr, sw_c) in bit/s: 225672462.41, 80306696.20
(sw_fr, zc_fr) in bit/s: None, 180970569.66
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 176928813.64
------------------- Remove Resources ----------------------
----- 258. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 73107483.15
(sw_fl, zc_fl) in bit/s: None, 201397141.99
(sw_fl, infotainment) in bit/s: None, 61595612.56
(sw_c, sw_fl) in bit/s: None, 179399852.43
(sw_c, sw_fr) in bit/s: None, 172463015.10
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 165588845.70
(sw_fr, sw_c) in bit/s: 225672462.41, 80306696.20
(sw_fr, zc_fr) in bit/s: None, 180970569.66
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 176928813.64
------------------- Find Path(s) ----------------------
Flow(id=4060, source=zc_fr, sink=['zc_rr', 'zc_fl', 'infotainment'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 259. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.641ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 73107483.15
(sw_fl, zc_fl) in bit/s: None, 201397141.99
(sw_fl, infotainment) in bit/s: None, 65218872.45
(sw_c, sw_fl) in bit/s: None, 179399852.43
(sw_c, sw_fr) in bit/s: None, 172463015.10
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 165588845.70
(sw_fr, sw_c) in bit/s: 225672462.41, 80306696.20
(sw_fr, zc_fr) in bit/s: None, 180970569.66
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 176928813.64
------------------- Find Path(s) ----------------------
Flow(id=4061, source=zc_fr, sink=['infotainment'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 260. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 73107483.15
(sw_fl, zc_fl) in bit/s: None, 201397141.99
(sw_fl, infotainment) in bit/s: None, 68842094.94
(sw_c, sw_fl) in bit/s: None, 183216852.32
(sw_c, sw_fr) in bit/s: None, 172463015.10
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 165588845.70
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 180970569.66
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 88218071.54
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 176928813.64
------------------- Find Path(s) ----------------------
Flow(id=6015, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 261. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 73107483.15
(sw_fl, zc_fl) in bit/s: None, 205343914.50
(sw_fl, infotainment) in bit/s: None, 68842094.94
(sw_c, sw_fl) in bit/s: None, 187244341.32
(sw_c, sw_fr) in bit/s: None, 172463015.10
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 165588845.70
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 180970569.66
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 91430227.48
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 176928813.64
------------------- Remove Resources ----------------------
----- 262. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 73107483.15
(sw_fl, zc_fl) in bit/s: None, 205343914.50
(sw_fl, infotainment) in bit/s: None, 68842094.94
(sw_c, sw_fl) in bit/s: None, 187244341.32
(sw_c, sw_fr) in bit/s: None, 172463015.10
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 165588845.70
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 180970569.66
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 91430227.48
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 176928813.64
------------------- Find Path(s) ----------------------
Flow(id=6015, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 263. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 73107483.15
(sw_fl, zc_fl) in bit/s: None, 205343914.50
(sw_fl, infotainment) in bit/s: None, 68842094.94
(sw_c, sw_fl) in bit/s: None, 187244341.32
(sw_c, sw_fr) in bit/s: None, 176788690.30
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 165588845.70
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 185009092.47
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 91430227.48
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 176928813.64
------------------- Find Path(s) ----------------------
Flow(id=3022, source=zc_fl, sink=['infotainment'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 264. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.220ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 73107483.15
(sw_fl, zc_fl) in bit/s: None, 205343914.50
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 187244341.32
(sw_c, sw_fr) in bit/s: None, 176788690.30
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 165588845.70
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 185009092.47
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 91430227.48
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 176928813.64
------------------- Find Path(s) ----------------------
Flow(id=7010, source=infotainment, sink=['zc_fr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 265. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 205343914.50
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 187244341.32
(sw_c, sw_fr) in bit/s: None, 180233154.45
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 165588845.70
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 189044258.47
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 91430227.48
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 176928813.64
------------------- Remove Resources ----------------------
----- 266. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 205343914.50
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 187244341.32
(sw_c, sw_fr) in bit/s: None, 180233154.45
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 165588845.70
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 189044258.47
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 91430227.48
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 176928813.64
------------------- Find Path(s) ----------------------
Flow(id=7010, source=infotainment, sink=['zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 267. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 205343914.50
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 187244341.32
(sw_c, sw_fr) in bit/s: None, 180233154.45
(sw_c, sw_rl) in bit/s: None, 47361641.55
(sw_c, sw_rr) in bit/s: 450390563.34, 169184142.80
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 189044258.47
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 49998743.55
(sw_rr, sw_c) in bit/s: None, 91430227.48
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 180970483.92
------------------- Find Path(s) ----------------------
Flow(id=6032, source=zc_rr, sink=['zc_rl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 268. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 205343914.50
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 187244341.32
(sw_c, sw_fr) in bit/s: None, 180233154.45
(sw_c, sw_rl) in bit/s: None, 51308446.29
(sw_c, sw_rr) in bit/s: 450390563.34, 169184142.80
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 189044258.47
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 54143215.03
(sw_rr, sw_c) in bit/s: None, 94620008.15
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 180970483.92
------------------- Remove Resources ----------------------
----- 269. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 205343914.50
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 187244341.32
(sw_c, sw_fr) in bit/s: None, 180233154.45
(sw_c, sw_rl) in bit/s: None, 51308446.29
(sw_c, sw_rr) in bit/s: 450390563.34, 169184142.80
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 189044258.47
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 54143215.03
(sw_rr, sw_c) in bit/s: None, 94620008.15
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 180970483.92
------------------- Find Path(s) ----------------------
Flow(id=6032, source=zc_rr, sink=['zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 270. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 209287508.71
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 191065638.80
(sw_c, sw_fr) in bit/s: None, 180233154.45
(sw_c, sw_rl) in bit/s: None, 51308446.29
(sw_c, sw_rr) in bit/s: 450390563.34, 169184142.80
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 189044258.47
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 54143215.03
(sw_rr, sw_c) in bit/s: None, 94620008.15
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 180970483.92
------------------- Remove Resources ----------------------
----- 271. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 209287508.71
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 191065638.80
(sw_c, sw_fr) in bit/s: None, 180233154.45
(sw_c, sw_rl) in bit/s: None, 51308446.29
(sw_c, sw_rr) in bit/s: 450390563.34, 169184142.80
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 189044258.47
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 54143215.03
(sw_rr, sw_c) in bit/s: None, 94620008.15
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 180970483.92
------------------- Find Path(s) ----------------------
Flow(id=6032, source=zc_rr, sink=['zc_rl', 'zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 272. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 209287508.71
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 191065638.80
(sw_c, sw_fr) in bit/s: None, 184575055.91
(sw_c, sw_rl) in bit/s: None, 51308446.29
(sw_c, sw_rr) in bit/s: 450390563.34, 169184142.80
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 193076225.65
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 54143215.03
(sw_rr, sw_c) in bit/s: None, 94620008.15
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 180970483.92
------------------- Find Path(s) ----------------------
Flow(id=6012, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 273. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 213228172.33
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 194887010.21
(sw_c, sw_fr) in bit/s: None, 184575055.91
(sw_c, sw_rl) in bit/s: None, 51308446.29
(sw_c, sw_rr) in bit/s: 450390563.34, 169184142.80
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 193076225.65
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 54143215.03
(sw_rr, sw_c) in bit/s: None, 97788786.99
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 180970483.92
------------------- Find Path(s) ----------------------
Flow(id=6052, source=zc_rr, sink=['zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 274. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 213228172.33
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 194887010.21
(sw_c, sw_fr) in bit/s: None, 184575055.91
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 169184142.80
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 193076225.65
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 180970483.92
------------------- Remove Resources ----------------------
----- 275. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 213228172.33
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 194887010.21
(sw_c, sw_fr) in bit/s: None, 184575055.91
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 169184142.80
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 193076225.65
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 180970483.92
------------------- Find Path(s) ----------------------
Flow(id=6052, source=zc_rr, sink=['zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 276. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 217165503.08
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 198708292.91
(sw_c, sw_fr) in bit/s: None, 184575055.91
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 169184142.80
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 193076225.65
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 180970483.92
------------------- Remove Resources ----------------------
----- 277. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 217165503.08
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 198708292.91
(sw_c, sw_fr) in bit/s: None, 184575055.91
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 169184142.80
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 193076225.65
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 180970483.92
------------------- Find Path(s) ----------------------
Flow(id=6052, source=zc_rr, sink=['zc_rl', 'zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 278. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 217165503.08
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 198708292.91
(sw_c, sw_fr) in bit/s: None, 188502138.97
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 169184142.80
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 197104912.41
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 180970483.92
------------------- Remove Resources ----------------------
----- 279. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 217165503.08
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 198708292.91
(sw_c, sw_fr) in bit/s: None, 188502138.97
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 169184142.80
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 197104912.41
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 180970483.92
------------------- Find Path(s) ----------------------
Flow(id=4061, source=zc_fr, sink=['infotainment', 'zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 280. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 221099761.84
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 198708292.91
(sw_c, sw_fr) in bit/s: None, 188502138.97
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 169184142.80
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 197104912.41
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 180970483.92
------------------- Remove Resources ----------------------
----- 281. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 221099761.84
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 198708292.91
(sw_c, sw_fr) in bit/s: None, 188502138.97
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 169184142.80
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 197104912.41
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 180970483.92
------------------- Find Path(s) ----------------------
Flow(id=4061, source=zc_fr, sink=['infotainment', 'zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 282. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment', 'zc_fl', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 76762282.98
(sw_fl, zc_fl) in bit/s: None, 221099761.84
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 198708292.91
(sw_c, sw_fr) in bit/s: None, 188502138.97
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 173225145.95
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 197104912.41
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 185008945.39
------------------- Find Path(s) ----------------------
Flow(id=3028, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 283. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 80130151.64
(sw_fl, zc_fl) in bit/s: None, 221099761.84
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 198708292.91
(sw_c, sw_fr) in bit/s: None, 191840485.97
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 173225145.95
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 201130397.92
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 185008945.39
------------------- Remove Resources ----------------------
----- 284. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 80130151.64
(sw_fl, zc_fl) in bit/s: None, 221099761.84
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 198708292.91
(sw_c, sw_fr) in bit/s: None, 191840485.97
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 173225145.95
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 201130397.92
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 185008945.39
------------------- Find Path(s) ----------------------
Flow(id=3028, source=zc_fl, sink=['zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 285. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 80130151.64
(sw_fl, zc_fl) in bit/s: None, 221099761.84
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 198708292.91
(sw_c, sw_fr) in bit/s: None, 191840485.97
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 176807572.91
(sw_fr, sw_c) in bit/s: 225672462.41, 83251809.64
(sw_fr, zc_fr) in bit/s: None, 201130397.92
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 189044156.63
------------------- Find Path(s) ----------------------
Flow(id=4007, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 286. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 80130151.64
(sw_fl, zc_fl) in bit/s: None, 221099761.84
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 198708292.91
(sw_c, sw_fr) in bit/s: None, 191840485.97
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 180855761.24
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 201130397.92
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 193076307.68
------------------- Remove Resources ----------------------
----- 287. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 80130151.64
(sw_fl, zc_fl) in bit/s: None, 221099761.84
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 198708292.91
(sw_c, sw_fr) in bit/s: None, 191840485.97
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 180855761.24
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 201130397.92
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 193076307.68
------------------- Find Path(s) ----------------------
Flow(id=4007, source=zc_fr, sink=['zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 288. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 80130151.64
(sw_fl, zc_fl) in bit/s: None, 225031112.79
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 201999327.53
(sw_c, sw_fr) in bit/s: None, 191840485.97
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 180855761.24
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 201130397.92
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 193076307.68
------------------- Remove Resources ----------------------
----- 289. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 80130151.64
(sw_fl, zc_fl) in bit/s: None, 225031112.79
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 201999327.53
(sw_c, sw_fr) in bit/s: None, 191840485.97
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 180855761.24
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 201130397.92
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 193076307.68
------------------- Find Path(s) ----------------------
Flow(id=7011, source=infotainment, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 290. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.213ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 83772205.34
(sw_fl, zc_fl) in bit/s: None, 225031112.79
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 201999327.53
(sw_c, sw_fr) in bit/s: None, 195755582.67
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 180855761.24
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 205152714.88
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 193076307.68
------------------- Remove Resources ----------------------
----- 291. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 83772205.34
(sw_fl, zc_fl) in bit/s: None, 225031112.79
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 201999327.53
(sw_c, sw_fr) in bit/s: None, 195755582.67
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 180855761.24
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 205152714.88
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 193076307.68
------------------- Find Path(s) ----------------------
Flow(id=7011, source=infotainment, sink=['zc_fl', 'zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 292. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.213ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 83772205.34
(sw_fl, zc_fl) in bit/s: None, 225031112.79
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 201999327.53
(sw_c, sw_fr) in bit/s: None, 195755582.67
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 184425363.09
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 205152714.88
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 197105097.60
------------------- Remove Resources ----------------------
----- 293. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 83772205.34
(sw_fl, zc_fl) in bit/s: None, 225031112.79
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 201999327.53
(sw_c, sw_fr) in bit/s: None, 195755582.67
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 184425363.09
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 205152714.88
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 197105097.60
------------------- Find Path(s) ----------------------
Flow(id=3022, source=zc_fl, sink=['infotainment', 'zc_fr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 294. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.220ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 225031112.79
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 201999327.53
(sw_c, sw_fr) in bit/s: None, 199670621.81
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 184425363.09
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 209171682.56
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 197105097.60
------------------- Remove Resources ----------------------
----- 295. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 225031112.79
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 201999327.53
(sw_c, sw_fr) in bit/s: None, 199670621.81
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 184425363.09
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 209171682.56
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 197105097.60
------------------- Find Path(s) ----------------------
Flow(id=3022, source=zc_fl, sink=['infotainment', 'zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 296. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.220ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 225031112.79
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 201999327.53
(sw_c, sw_fr) in bit/s: None, 199670621.81
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 209171682.56
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 100934873.89
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6044, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 297. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.645ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 225031112.79
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 201999327.53
(sw_c, sw_fr) in bit/s: None, 203975763.96
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 213187476.28
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 104059700.53
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Remove Resources ----------------------
----- 298. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 225031112.79
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 201999327.53
(sw_c, sw_fr) in bit/s: None, 203975763.96
(sw_c, sw_rl) in bit/s: None, 55255248.79
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 213187476.28
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 58284297.49
(sw_rr, sw_c) in bit/s: None, 104059700.53
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6044, source=zc_rr, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 299. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.645ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.645ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 225031112.79
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 201999327.53
(sw_c, sw_fr) in bit/s: None, 203975763.96
(sw_c, sw_rl) in bit/s: None, 59202053.52
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 213187476.28
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 62422014.31
(sw_rr, sw_c) in bit/s: None, 104059700.53
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Remove Resources ----------------------
----- 300. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 225031112.79
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 201999327.53
(sw_c, sw_fr) in bit/s: None, 203975763.96
(sw_c, sw_rl) in bit/s: None, 59202053.52
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 213187476.28
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 62422014.31
(sw_rr, sw_c) in bit/s: None, 104059700.53
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6044, source=zc_rr, sink=['zc_fr', 'zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 301. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.645ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.645ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.645ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 228959168.14
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 206273594.99
(sw_c, sw_fr) in bit/s: None, 203975763.96
(sw_c, sw_rl) in bit/s: None, 59202053.52
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 213187476.28
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 62422014.31
(sw_rr, sw_c) in bit/s: None, 104059700.53
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6013, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 302. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 228959168.14
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 206273594.99
(sw_c, sw_fr) in bit/s: None, 207898364.79
(sw_c, sw_rl) in bit/s: None, 59202053.52
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 217200117.11
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 62422014.31
(sw_rr, sw_c) in bit/s: None, 107163628.52
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Remove Resources ----------------------
----- 303. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 228959168.14
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 206273594.99
(sw_c, sw_fr) in bit/s: None, 207898364.79
(sw_c, sw_rl) in bit/s: None, 59202053.52
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 217200117.11
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 62422014.31
(sw_rr, sw_c) in bit/s: None, 107163628.52
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6013, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 304. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 232884193.83
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 210093484.82
(sw_c, sw_fr) in bit/s: None, 207898364.79
(sw_c, sw_rl) in bit/s: None, 59202053.52
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 217200117.11
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 62422014.31
(sw_rr, sw_c) in bit/s: None, 107163628.52
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Remove Resources ----------------------
----- 305. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 232884193.83
(sw_fl, infotainment) in bit/s: None, 72204184.23
(sw_c, sw_fl) in bit/s: None, 210093484.82
(sw_c, sw_fr) in bit/s: None, 207898364.79
(sw_c, sw_rl) in bit/s: None, 59202053.52
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 217200117.11
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 62422014.31
(sw_rr, sw_c) in bit/s: None, 107163628.52
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6013, source=zc_rr, sink=['zc_fr', 'zc_fl', 'infotainment'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 306. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 232884193.83
(sw_fl, infotainment) in bit/s: None, 75814387.48
(sw_c, sw_fl) in bit/s: None, 210093484.82
(sw_c, sw_fr) in bit/s: None, 207898364.79
(sw_c, sw_rl) in bit/s: None, 59202053.52
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 86178923.99
(sw_fr, zc_fr) in bit/s: None, 217200117.11
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 62422014.31
(sw_rr, sw_c) in bit/s: None, 107163628.52
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=4040, source=zc_fr, sink=['infotainment'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 307. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 232884193.83
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 213273978.73
(sw_c, sw_fr) in bit/s: None, 207898364.79
(sw_c, sw_rl) in bit/s: None, 59202053.52
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 89089100.97
(sw_fr, zc_fr) in bit/s: None, 217200117.11
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 62422014.31
(sw_rr, sw_c) in bit/s: None, 107163628.52
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6048, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 308. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 232884193.83
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 213273978.73
(sw_c, sw_fr) in bit/s: None, 211820925.16
(sw_c, sw_rl) in bit/s: None, 59202053.52
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 89089100.97
(sw_fr, zc_fr) in bit/s: None, 221209427.41
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 62422014.31
(sw_rr, sw_c) in bit/s: None, 110246046.57
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Remove Resources ----------------------
----- 309. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 232884193.83
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 213273978.73
(sw_c, sw_fr) in bit/s: None, 211820925.16
(sw_c, sw_rl) in bit/s: None, 59202053.52
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 89089100.97
(sw_fr, zc_fr) in bit/s: None, 221209427.41
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 62422014.31
(sw_rr, sw_c) in bit/s: None, 110246046.57
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6048, source=zc_rr, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 310. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 232884193.83
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 213273978.73
(sw_c, sw_fr) in bit/s: None, 211820925.16
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 89089100.97
(sw_fr, zc_fr) in bit/s: None, 221209427.41
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 110246046.57
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Remove Resources ----------------------
----- 311. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 232884193.83
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 213273978.73
(sw_c, sw_fr) in bit/s: None, 211820925.16
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 89089100.97
(sw_fr, zc_fr) in bit/s: None, 221209427.41
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 110246046.57
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6048, source=zc_rr, sink=['zc_fr', 'zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 312. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 236806015.97
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 217651832.77
(sw_c, sw_fr) in bit/s: None, 211820925.16
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 89089100.97
(sw_fr, zc_fr) in bit/s: None, 221209427.41
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 110246046.57
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6031, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 313. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 240724745.72
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 221470247.72
(sw_c, sw_fr) in bit/s: None, 211820925.16
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 89089100.97
(sw_fr, zc_fr) in bit/s: None, 221209427.41
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 113307664.50
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Remove Resources ----------------------
----- 314. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 240724745.72
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 221470247.72
(sw_c, sw_fr) in bit/s: None, 211820925.16
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 89089100.97
(sw_fr, zc_fr) in bit/s: None, 221209427.41
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 113307664.50
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6031, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 315. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 240724745.72
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 221470247.72
(sw_c, sw_fr) in bit/s: None, 215743485.53
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 450390563.34, 188267490.08
(sw_fr, sw_c) in bit/s: 225672462.41, 89089100.97
(sw_fr, zc_fr) in bit/s: None, 225215520.97
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 113307664.50
(sw_rr, adas) in bit/s: 571363444.41, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=2112, source=lidar_fr, sink=['adas'], data_per_interval=12336, sending_interval=0.00015, deadline=0.001, max_frame_size=12240, priority=0, redundancy=False)
Path found: [[('lidar_fr', 'sw_fr', 0), ('sw_fr', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]]
------------------- Reserve Resources ----------------------
----- 316. Flow Operation -- add -----
Flow Details: Source:  lidar_fr , Destination:  ['adas'] , Bits:  12336 , Interval:  0.150 ms , Deadline:  1.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('lidar_fr', 'sw_fr', 0), ('sw_fr', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 240724745.72
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 221470247.72
(sw_c, sw_fr) in bit/s: None, 215743485.53
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 686677095.22, 188385593.70
(sw_fr, sw_c) in bit/s: 359282634.55, 89129899.80
(sw_fr, zc_fr) in bit/s: None, 225215520.97
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 113307664.50
(sw_rr, adas) in bit/s: 851924314.76, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=12112, source=lidar_fr, sink=['adas'], data_per_interval=3536, sending_interval=0.00015, deadline=0.001, max_frame_size=3440, priority=0, redundancy=False)
Path found: [[('lidar_fr', 'sw_fr', 0), ('sw_fr', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]]
------------------- Reserve Resources ----------------------
----- 317. Flow Operation -- add -----
Flow Details: Source:  lidar_fr , Destination:  ['adas'] , Bits:  3536 , Interval:  0.150 ms , Deadline:  1.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('lidar_fr', 'sw_fr', 0), ('sw_fr', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 240724745.72
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 221470247.72
(sw_c, sw_fr) in bit/s: None, 215743485.53
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 752980586.34, 188395371.11
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 225215520.97
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 113307664.50
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6024, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 318. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.648ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 240724745.72
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 221470247.72
(sw_c, sw_fr) in bit/s: None, 219666040.83
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 752980586.34, 188395371.11
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 229218386.86
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 116348623.31
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6075, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.16, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 319. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  160.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 240724745.72
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 221470247.72
(sw_c, sw_fr) in bit/s: None, 223588622.70
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 752980586.34, 188395371.11
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 233218122.27
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 119369565.44
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Remove Resources ----------------------
----- 320. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  160.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 240724745.72
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 221470247.72
(sw_c, sw_fr) in bit/s: None, 223588622.70
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 752980586.34, 188395371.11
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 233218122.27
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 119369565.44
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6075, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.16, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 321. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  160.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 244640448.25
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 225288685.82
(sw_c, sw_fr) in bit/s: None, 223588622.70
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 752980586.34, 188395371.11
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 233218122.27
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 119369565.44
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Remove Resources ----------------------
----- 322. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  160.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 244640448.25
(sw_fl, infotainment) in bit/s: None, 79424988.16
(sw_c, sw_fl) in bit/s: None, 225288685.82
(sw_c, sw_fr) in bit/s: None, 223588622.70
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 752980586.34, 188395371.11
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 233218122.27
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 119369565.44
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6075, source=zc_rr, sink=['zc_fr', 'zc_fl', 'infotainment'], data_per_interval=688, sending_interval=0.16, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 323. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  160.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.648ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 244640448.25
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 225288685.82
(sw_c, sw_fr) in bit/s: None, 223588622.70
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 752980586.34, 188395371.11
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 233218122.27
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 119369565.44
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6021, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 324. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 244640448.25
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 225288685.82
(sw_c, sw_fr) in bit/s: None, 227511274.12
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 752980586.34, 188395371.11
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 237214865.44
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 122371332.43
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6046, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 325. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.650ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 244640448.25
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 225288685.82
(sw_c, sw_fr) in bit/s: None, 231433834.49
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 752980586.34, 188395371.11
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 241208136.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Remove Resources ----------------------
----- 326. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 244640448.25
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 225288685.82
(sw_c, sw_fr) in bit/s: None, 231433834.49
(sw_c, sw_rl) in bit/s: None, 63148856.02
(sw_c, sw_rr) in bit/s: 752980586.34, 188395371.11
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 241208136.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 66556348.69
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=6046, source=zc_rr, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 327. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.650ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.650ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 87102947.85
(sw_fl, zc_fl) in bit/s: None, 244640448.25
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 225288685.82
(sw_c, sw_fr) in bit/s: None, 231433834.49
(sw_c, sw_rl) in bit/s: None, 67095658.52
(sw_c, sw_rr) in bit/s: 752980586.34, 188395371.11
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 241208136.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 70687314.78
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=3014, source=zc_fl, sink=['zc_rl'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 328. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 90411901.23
(sw_fl, zc_fl) in bit/s: None, 244640448.25
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 225288685.82
(sw_c, sw_fr) in bit/s: None, 231433834.49
(sw_c, sw_rl) in bit/s: None, 70932979.46
(sw_c, sw_rr) in bit/s: 752980586.34, 188395371.11
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 241208136.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 74815131.23
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Remove Resources ----------------------
----- 329. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 90411901.23
(sw_fl, zc_fl) in bit/s: None, 244640448.25
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 225288685.82
(sw_c, sw_fr) in bit/s: None, 231433834.49
(sw_c, sw_rl) in bit/s: None, 70932979.46
(sw_c, sw_rr) in bit/s: 752980586.34, 188395371.11
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 241208136.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 74815131.23
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=3014, source=zc_fl, sink=['zc_rl', 'zc_fr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 330. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 90411901.23
(sw_fl, zc_fl) in bit/s: None, 244640448.25
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 225288685.82
(sw_c, sw_fr) in bit/s: None, 234189976.77
(sw_c, sw_rl) in bit/s: None, 70932979.46
(sw_c, sw_rr) in bit/s: 752980586.34, 188395371.11
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 245198970.18
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 74815131.23
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Remove Resources ----------------------
----- 331. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 90411901.23
(sw_fl, zc_fl) in bit/s: None, 244640448.25
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 225288685.82
(sw_c, sw_fr) in bit/s: None, 234189976.77
(sw_c, sw_rl) in bit/s: None, 70932979.46
(sw_c, sw_rr) in bit/s: 752980586.34, 188395371.11
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 245198970.18
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 74815131.23
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 201130535.24
------------------- Find Path(s) ----------------------
Flow(id=3014, source=zc_fl, sink=['zc_rl', 'zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 332. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 90411901.23
(sw_fl, zc_fl) in bit/s: None, 244640448.25
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 225288685.82
(sw_c, sw_fr) in bit/s: None, 234189976.77
(sw_c, sw_rl) in bit/s: None, 70932979.46
(sw_c, sw_rr) in bit/s: 752980586.34, 192240389.71
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 245198970.18
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 74815131.23
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 205153383.32
------------------- Remove Resources ----------------------
----- 333. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 90411901.23
(sw_fl, zc_fl) in bit/s: None, 244640448.25
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 225288685.82
(sw_c, sw_fr) in bit/s: None, 234189976.77
(sw_c, sw_rl) in bit/s: None, 70932979.46
(sw_c, sw_rr) in bit/s: 752980586.34, 192240389.71
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 245198970.18
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 74815131.23
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 205153383.32
------------------- Find Path(s) ----------------------
Flow(id=6046, source=zc_rr, sink=['zc_fr', 'zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 334. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.650ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.650ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.650ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 90411901.23
(sw_fl, zc_fl) in bit/s: None, 248553005.29
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 229107100.77
(sw_c, sw_fr) in bit/s: None, 234189976.77
(sw_c, sw_rl) in bit/s: None, 70932979.46
(sw_c, sw_rr) in bit/s: 752980586.34, 192240389.71
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 245198970.18
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 74815131.23
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 930084983.29, None
(sw_rr, zc_rr) in bit/s: None, 205153383.32
------------------- Find Path(s) ----------------------
Flow(id=2111, source=lidar_fl, sink=['adas'], data_per_interval=12336, sending_interval=0.00015, deadline=0.001, max_frame_size=12240, priority=0, redundancy=False)
Path found: [[('lidar_fl', 'sw_fl', 0), ('sw_fl', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]]
------------------- Reserve Resources ----------------------
----- 335. Flow Operation -- add -----
Flow Details: Source:  lidar_fl , Destination:  ['adas'] , Bits:  12336 , Interval:  0.150 ms , Deadline:  1.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('lidar_fl', 'sw_fl', 0), ('sw_fl', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 154067117.70, 90996331.40
(sw_fl, zc_fl) in bit/s: None, 248553005.29
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 229107100.77
(sw_c, sw_fr) in bit/s: None, 234189976.77
(sw_c, sw_rl) in bit/s: None, 70932979.46
(sw_c, sw_rr) in bit/s: 994600308.74, 192277999.73
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 245198970.18
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 74815131.23
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1195407152.50, None
(sw_rr, zc_rr) in bit/s: None, 205153383.32
------------------- Find Path(s) ----------------------
Flow(id=12111, source=lidar_fl, sink=['adas'], data_per_interval=3536, sending_interval=0.00015, deadline=0.001, max_frame_size=3440, priority=0, redundancy=False)
Path found: [[('lidar_fl', 'sw_fl', 0), ('sw_fl', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]]
------------------- Reserve Resources ----------------------
----- 336. Flow Operation -- add -----
Flow Details: Source:  lidar_fl , Destination:  ['adas'] , Bits:  3536 , Interval:  0.150 ms , Deadline:  1.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('lidar_fl', 'sw_fl', 0), ('sw_fl', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 90998735.09
(sw_fl, zc_fl) in bit/s: None, 248553005.29
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 229107100.77
(sw_c, sw_fr) in bit/s: None, 234189976.77
(sw_c, sw_rl) in bit/s: None, 70932979.46
(sw_c, sw_rr) in bit/s: 1063858361.46, 192289158.17
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 245198970.18
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 74815131.23
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 205153383.32
------------------- Find Path(s) ----------------------
Flow(id=7006, source=infotainment, sink=['zc_fr'], data_per_interval=688, sending_interval=0.15, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 337. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr'] , Bits:  688 , Interval:  150.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.630ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 94638264.60
(sw_fl, zc_fl) in bit/s: None, 248553005.29
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 229107100.77
(sw_c, sw_fr) in bit/s: None, 238093098.14
(sw_c, sw_rl) in bit/s: None, 70932979.46
(sw_c, sw_rr) in bit/s: 1063858361.46, 192289158.17
(sw_fr, sw_c) in bit/s: 397580751.34, 89131993.06
(sw_fr, zc_fr) in bit/s: None, 249185937.61
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 74815131.23
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 205153383.32
------------------- Find Path(s) ----------------------
Flow(id=4004, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 338. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 94638264.60
(sw_fl, zc_fl) in bit/s: None, 252462638.27
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 231969334.57
(sw_c, sw_fr) in bit/s: None, 238093098.14
(sw_c, sw_rl) in bit/s: None, 70932979.46
(sw_c, sw_rr) in bit/s: 1063858361.46, 192289158.17
(sw_fr, sw_c) in bit/s: 397580751.34, 92023061.35
(sw_fr, zc_fr) in bit/s: None, 249185937.61
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 74815131.23
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 205153383.32
------------------- Find Path(s) ----------------------
Flow(id=3005, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 339. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 97928346.53
(sw_fl, zc_fl) in bit/s: None, 252462638.27
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 231969334.57
(sw_c, sw_fr) in bit/s: None, 241996205.29
(sw_c, sw_rl) in bit/s: None, 70932979.46
(sw_c, sw_rr) in bit/s: 1063858361.46, 192289158.17
(sw_fr, sw_c) in bit/s: 397580751.34, 92023061.35
(sw_fr, zc_fr) in bit/s: None, 253169690.38
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 74815131.23
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 205153383.32
------------------- Remove Resources ----------------------
----- 340. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 97928346.53
(sw_fl, zc_fl) in bit/s: None, 252462638.27
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 231969334.57
(sw_c, sw_fr) in bit/s: None, 241996205.29
(sw_c, sw_rl) in bit/s: None, 70932979.46
(sw_c, sw_rr) in bit/s: 1063858361.46, 192289158.17
(sw_fr, sw_c) in bit/s: 397580751.34, 92023061.35
(sw_fr, zc_fr) in bit/s: None, 253169690.38
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 74815131.23
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 205153383.32
------------------- Find Path(s) ----------------------
Flow(id=4004, source=zc_fr, sink=['zc_fl', 'zc_rl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 341. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 97928346.53
(sw_fl, zc_fl) in bit/s: None, 252462638.27
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 231969334.57
(sw_c, sw_fr) in bit/s: None, 241996205.29
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 192289158.17
(sw_fr, sw_c) in bit/s: 397580751.34, 92023061.35
(sw_fr, zc_fr) in bit/s: None, 253169690.38
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 205153383.32
------------------- Remove Resources ----------------------
----- 342. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 97928346.53
(sw_fl, zc_fl) in bit/s: None, 252462638.27
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 231969334.57
(sw_c, sw_fr) in bit/s: None, 241996205.29
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 192289158.17
(sw_fr, sw_c) in bit/s: 397580751.34, 92023061.35
(sw_fr, zc_fr) in bit/s: None, 253169690.38
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 205153383.32
------------------- Find Path(s) ----------------------
Flow(id=3005, source=zc_fl, sink=['zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 343. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.638ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 97928346.53
(sw_fl, zc_fl) in bit/s: None, 252462638.27
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 231969334.57
(sw_c, sw_fr) in bit/s: None, 241996205.29
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 196134893.29
(sw_fr, sw_c) in bit/s: 397580751.34, 92023061.35
(sw_fr, zc_fr) in bit/s: None, 253169690.38
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 209172418.34
------------------- Remove Resources ----------------------
----- 344. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 97928346.53
(sw_fl, zc_fl) in bit/s: None, 252462638.27
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 231969334.57
(sw_c, sw_fr) in bit/s: None, 241996205.29
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 196134893.29
(sw_fr, sw_c) in bit/s: 397580751.34, 92023061.35
(sw_fr, zc_fr) in bit/s: None, 253169690.38
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 209172418.34
------------------- Find Path(s) ----------------------
Flow(id=4004, source=zc_fr, sink=['zc_fl', 'zc_rl', 'zc_rr'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 345. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl', 'zc_rr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 97928346.53
(sw_fl, zc_fl) in bit/s: None, 252462638.27
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 231969334.57
(sw_c, sw_fr) in bit/s: None, 241996205.29
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 199980651.76
(sw_fr, sw_c) in bit/s: 397580751.34, 92023061.35
(sw_fr, zc_fr) in bit/s: None, 253169690.38
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 213188329.59
------------------- Find Path(s) ----------------------
Flow(id=7005, source=infotainment, sink=['zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 346. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 101554840.04
(sw_fl, zc_fl) in bit/s: None, 252462638.27
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 231969334.57
(sw_c, sw_fr) in bit/s: None, 245899312.45
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 199980651.76
(sw_fr, sw_c) in bit/s: 397580751.34, 92023061.35
(sw_fr, zc_fr) in bit/s: None, 257150258.72
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 213188329.59
------------------- Find Path(s) ----------------------
Flow(id=4012, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 347. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.645ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 101554840.04
(sw_fl, zc_fl) in bit/s: None, 252462638.27
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 231969334.57
(sw_c, sw_fr) in bit/s: None, 245899312.45
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 203826415.27
(sw_fr, sw_c) in bit/s: 397580751.34, 94895741.79
(sw_fr, zc_fr) in bit/s: None, 257150258.72
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 217200986.88
------------------- Find Path(s) ----------------------
Flow(id=4047, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 348. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 101554840.04
(sw_fl, zc_fl) in bit/s: None, 252462638.27
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 231969334.57
(sw_c, sw_fr) in bit/s: None, 245899312.45
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 207672150.02
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 257150258.72
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 221210356.41
------------------- Remove Resources ----------------------
----- 349. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 101554840.04
(sw_fl, zc_fl) in bit/s: None, 252462638.27
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 231969334.57
(sw_c, sw_fr) in bit/s: None, 245899312.45
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 207672150.02
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 257150258.72
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 221210356.41
------------------- Find Path(s) ----------------------
Flow(id=4047, source=zc_fr, sink=['zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 350. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 101554840.04
(sw_fl, zc_fl) in bit/s: None, 256369084.51
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 235772078.97
(sw_c, sw_fr) in bit/s: None, 245899312.45
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 207672150.02
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 257150258.72
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 125351853.57
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 221210356.41
------------------- Find Path(s) ----------------------
Flow(id=6066, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 351. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 101554840.04
(sw_fl, zc_fl) in bit/s: None, 256369084.51
(sw_fl, infotainment) in bit/s: None, 83035154.15
(sw_c, sw_fl) in bit/s: None, 235772078.97
(sw_c, sw_fr) in bit/s: None, 250662968.08
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 207672150.02
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 261128406.49
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 128316202.21
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 221210356.41
------------------- Find Path(s) ----------------------
Flow(id=3023, source=zc_fl, sink=['infotainment'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 352. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.223ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 101554840.04
(sw_fl, zc_fl) in bit/s: None, 256369084.51
(sw_fl, infotainment) in bit/s: None, 86334258.53
(sw_c, sw_fl) in bit/s: None, 235772078.97
(sw_c, sw_fr) in bit/s: None, 250662968.08
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 207672150.02
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 261128406.49
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 128316202.21
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 221210356.41
------------------- Find Path(s) ----------------------
Flow(id=3001, source=zc_fl, sink=['zc_rr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 353. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 256369084.51
(sw_fl, infotainment) in bit/s: None, 86334258.53
(sw_c, sw_fl) in bit/s: None, 235772078.97
(sw_c, sw_fr) in bit/s: None, 250662968.08
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 261128406.49
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 128316202.21
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Remove Resources ----------------------
----- 354. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 256369084.51
(sw_fl, infotainment) in bit/s: None, 86334258.53
(sw_c, sw_fl) in bit/s: None, 235772078.97
(sw_c, sw_fr) in bit/s: None, 250662968.08
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 261128406.49
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 128316202.21
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Find Path(s) ----------------------
Flow(id=3001, source=zc_fl, sink=['zc_rr', 'zc_fr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 355. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 256369084.51
(sw_fl, infotainment) in bit/s: None, 86334258.53
(sw_c, sw_fl) in bit/s: None, 235772078.97
(sw_c, sw_fr) in bit/s: None, 253609597.47
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 265103400.86
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 128316202.21
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Find Path(s) ----------------------
Flow(id=3012, source=zc_fl, sink=['infotainment'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 356. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.224ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 256369084.51
(sw_fl, infotainment) in bit/s: None, 89609971.88
(sw_c, sw_fl) in bit/s: None, 235772078.97
(sw_c, sw_fr) in bit/s: None, 253609597.47
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 265103400.86
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 128316202.21
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Find Path(s) ----------------------
Flow(id=3042, source=zc_fl, sink=['infotainment'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 357. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.225ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 256369084.51
(sw_fl, infotainment) in bit/s: None, 92862138.48
(sw_c, sw_fl) in bit/s: None, 235772078.97
(sw_c, sw_fr) in bit/s: None, 253609597.47
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 265103400.86
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 128316202.21
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Remove Resources ----------------------
----- 358. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 256369084.51
(sw_fl, infotainment) in bit/s: None, 92862138.48
(sw_c, sw_fl) in bit/s: None, 235772078.97
(sw_c, sw_fr) in bit/s: None, 253609597.47
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 265103400.86
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 128316202.21
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Find Path(s) ----------------------
Flow(id=6021, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 359. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 260272690.65
(sw_fl, infotainment) in bit/s: None, 92862138.48
(sw_c, sw_fl) in bit/s: None, 240382352.72
(sw_c, sw_fr) in bit/s: None, 253609597.47
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 265103400.86
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 128316202.21
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Remove Resources ----------------------
----- 360. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 260272690.65
(sw_fl, infotainment) in bit/s: None, 92862138.48
(sw_c, sw_fl) in bit/s: None, 240382352.72
(sw_c, sw_fr) in bit/s: None, 253609597.47
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 265103400.86
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 128316202.21
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Find Path(s) ----------------------
Flow(id=6021, source=zc_rr, sink=['zc_fr', 'zc_fl', 'infotainment'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 361. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.650ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 260272690.65
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 240382352.72
(sw_c, sw_fr) in bit/s: None, 253609597.47
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 265103400.86
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 128316202.21
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Find Path(s) ----------------------
Flow(id=6000, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 362. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 264173117.28
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 244197967.00
(sw_c, sw_fr) in bit/s: None, 253609597.47
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 265103400.86
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 131258239.34
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Remove Resources ----------------------
----- 363. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 264173117.28
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 244197967.00
(sw_c, sw_fr) in bit/s: None, 253609597.47
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 265103400.86
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 131258239.34
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Find Path(s) ----------------------
Flow(id=6000, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 364. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 264173117.28
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 244197967.00
(sw_c, sw_fr) in bit/s: None, 258397559.42
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 269074592.72
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 131258239.34
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Remove Resources ----------------------
----- 365. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 264173117.28
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 244197967.00
(sw_c, sw_fr) in bit/s: None, 258397559.42
(sw_c, sw_rl) in bit/s: None, 74873712.68
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 269074592.72
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 78939436.40
(sw_rr, sw_c) in bit/s: None, 131258239.34
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Find Path(s) ----------------------
Flow(id=6000, source=zc_rr, sink=['zc_fl', 'zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 366. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 264173117.28
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 244197967.00
(sw_c, sw_fr) in bit/s: None, 258397559.42
(sw_c, sw_rl) in bit/s: None, 78905663.95
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 269074592.72
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 83060391.46
(sw_rr, sw_c) in bit/s: None, 131258239.34
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Find Path(s) ----------------------
Flow(id=6003, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 367. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.652ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 264173117.28
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 244197967.00
(sw_c, sw_fr) in bit/s: None, 262312671.99
(sw_c, sw_rl) in bit/s: None, 78905663.95
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 273042619.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 83060391.46
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Remove Resources ----------------------
----- 368. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 264173117.28
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 244197967.00
(sw_c, sw_fr) in bit/s: None, 262312671.99
(sw_c, sw_rl) in bit/s: None, 78905663.95
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 273042619.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 83060391.46
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Find Path(s) ----------------------
Flow(id=6003, source=zc_rr, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 369. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.652ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.652ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 264173117.28
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 244197967.00
(sw_c, sw_fr) in bit/s: None, 262312671.99
(sw_c, sw_rl) in bit/s: None, 82850953.22
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 273042619.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 87178000.49
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Remove Resources ----------------------
----- 370. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 264173117.28
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 244197967.00
(sw_c, sw_fr) in bit/s: None, 262312671.99
(sw_c, sw_rl) in bit/s: None, 82850953.22
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 273042619.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 87178000.49
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Find Path(s) ----------------------
Flow(id=6003, source=zc_rr, sink=['zc_fr', 'zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 371. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.652ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.652ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.652ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 268070482.35
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 248013581.28
(sw_c, sw_fr) in bit/s: None, 262312671.99
(sw_c, sw_rl) in bit/s: None, 82850953.22
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 273042619.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 87178000.49
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Remove Resources ----------------------
----- 372. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 104810599.01
(sw_fl, zc_fl) in bit/s: None, 268070482.35
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 248013581.28
(sw_c, sw_fr) in bit/s: None, 262312671.99
(sw_c, sw_rl) in bit/s: None, 82850953.22
(sw_c, sw_rr) in bit/s: 1063858361.46, 211279140.84
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 273042619.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 87178000.49
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 225217164.71
------------------- Find Path(s) ----------------------
Flow(id=3042, source=zc_fl, sink=['infotainment', 'zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 373. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.225ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.641ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 108041517.77
(sw_fl, zc_fl) in bit/s: None, 268070482.35
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 248013581.28
(sw_c, sw_fr) in bit/s: None, 262312671.99
(sw_c, sw_rl) in bit/s: None, 82850953.22
(sw_c, sw_rr) in bit/s: 1063858361.46, 215120523.29
(sw_fr, sw_c) in bit/s: 397580751.34, 97750047.74
(sw_fr, zc_fr) in bit/s: None, 273042619.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 87178000.49
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 229220119.61
------------------- Find Path(s) ----------------------
Flow(id=4027, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 374. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 108041517.77
(sw_fl, zc_fl) in bit/s: None, 268070482.35
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 248013581.28
(sw_c, sw_fr) in bit/s: None, 262312671.99
(sw_c, sw_rl) in bit/s: None, 82850953.22
(sw_c, sw_rr) in bit/s: 1063858361.46, 219044673.71
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 273042619.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 87178000.49
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 233220544.68
------------------- Remove Resources ----------------------
----- 375. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 108041517.77
(sw_fl, zc_fl) in bit/s: None, 268070482.35
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 248013581.28
(sw_c, sw_fr) in bit/s: None, 262312671.99
(sw_c, sw_rl) in bit/s: None, 82850953.22
(sw_c, sw_rr) in bit/s: 1063858361.46, 219044673.71
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 273042619.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 87178000.49
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 233220544.68
------------------- Find Path(s) ----------------------
Flow(id=4027, source=zc_fr, sink=['zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 376. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 108041517.77
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 262312671.99
(sw_c, sw_rl) in bit/s: None, 82850953.22
(sw_c, sw_rr) in bit/s: 1063858361.46, 219044673.71
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 273042619.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 87178000.49
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 233220544.68
------------------- Remove Resources ----------------------
----- 377. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 108041517.77
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 96433901.93
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 262312671.99
(sw_c, sw_rl) in bit/s: None, 82850953.22
(sw_c, sw_rr) in bit/s: 1063858361.46, 219044673.71
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 273042619.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 87178000.49
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 233220544.68
------------------- Find Path(s) ----------------------
Flow(id=4027, source=zc_fr, sink=['zc_rr', 'zc_fl', 'infotainment'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 378. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 108041517.77
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 100006181.44
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 262312671.99
(sw_c, sw_rl) in bit/s: None, 82850953.22
(sw_c, sw_rr) in bit/s: 1063858361.46, 219044673.71
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 273042619.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 87178000.49
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 233220544.68
------------------- Find Path(s) ----------------------
Flow(id=3035, source=zc_fl, sink=['infotainment'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 379. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.225ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 108041517.77
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 262312671.99
(sw_c, sw_rl) in bit/s: None, 82850953.22
(sw_c, sw_rr) in bit/s: 1063858361.46, 219044673.71
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 273042619.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 87178000.49
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 233220544.68
------------------- Remove Resources ----------------------
----- 380. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 108041517.77
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 262312671.99
(sw_c, sw_rl) in bit/s: None, 82850953.22
(sw_c, sw_rr) in bit/s: 1063858361.46, 219044673.71
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 273042619.23
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 87178000.49
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 233220544.68
------------------- Find Path(s) ----------------------
Flow(id=3023, source=zc_fl, sink=['infotainment', 'zc_fr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 381. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.225ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 111249475.14
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 265112468.78
(sw_c, sw_rl) in bit/s: None, 82850953.22
(sw_c, sw_rr) in bit/s: 1063858361.46, 219044673.71
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 277007278.02
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 87178000.49
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 233220544.68
------------------- Find Path(s) ----------------------
Flow(id=3018, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 382. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 114434929.08
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 269011082.49
(sw_c, sw_rl) in bit/s: None, 82850953.22
(sw_c, sw_rr) in bit/s: 1063858361.46, 219044673.71
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 280968791.27
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 87178000.49
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 233220544.68
------------------- Remove Resources ----------------------
----- 383. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 114434929.08
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 269011082.49
(sw_c, sw_rl) in bit/s: None, 82850953.22
(sw_c, sw_rr) in bit/s: 1063858361.46, 219044673.71
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 280968791.27
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 87178000.49
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 233220544.68
------------------- Find Path(s) ----------------------
Flow(id=3018, source=zc_fl, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 384. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 114434929.08
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 269011082.49
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 219044673.71
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 280968791.27
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 233220544.68
------------------- Remove Resources ----------------------
----- 385. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 114434929.08
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 269011082.49
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 219044673.71
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 280968791.27
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 233220544.68
------------------- Find Path(s) ----------------------
Flow(id=3023, source=zc_fl, sink=['infotainment', 'zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 386. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.226ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 114434929.08
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 269011082.49
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 222719660.37
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 280968791.27
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 237217039.01
------------------- Remove Resources ----------------------
----- 387. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 114434929.08
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 269011082.49
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 222719660.37
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 280968791.27
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 237217039.01
------------------- Find Path(s) ----------------------
Flow(id=3018, source=zc_fl, sink=['zc_fr', 'zc_rl', 'zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 388. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.642ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 114434929.08
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 269011082.49
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 226559573.60
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 280968791.27
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 241210347.03
------------------- Find Path(s) ----------------------
Flow(id=3040, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 389. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 117598471.32
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 272909770.76
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 226559573.60
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 284927292.64
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 241210347.03
------------------- Remove Resources ----------------------
----- 390. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 117598471.32
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 272909770.76
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 226559573.60
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 284927292.64
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 241210347.03
------------------- Find Path(s) ----------------------
Flow(id=3040, source=zc_fl, sink=['zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 391. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 117598471.32
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 272909770.76
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 230399541.24
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 284927292.64
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 245200584.29
------------------- Remove Resources ----------------------
----- 392. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 117598471.32
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 272909770.76
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 230399541.24
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 284927292.64
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 245200584.29
------------------- Find Path(s) ----------------------
Flow(id=3012, source=zc_fl, sink=['infotainment', 'zc_fr'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 393. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.227ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 120740482.19
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 276808552.23
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 230399541.24
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 288882829.48
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 245200584.29
------------------- Remove Resources ----------------------
----- 394. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 120740482.19
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 276808552.23
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 230399541.24
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 288882829.48
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 245200584.29
------------------- Find Path(s) ----------------------
Flow(id=3012, source=zc_fl, sink=['infotainment', 'zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 395. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.227ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.643ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 120740482.19
(sw_fl, zc_fl) in bit/s: None, 271965399.54
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 276808552.23
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 234239576.90
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 288882829.48
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 249187793.13
------------------- Find Path(s) ----------------------
Flow(id=7004, source=infotainment, sink=['zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 396. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.215ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 120740482.19
(sw_fl, zc_fl) in bit/s: None, 275964824.86
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 276808552.23
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 234239576.90
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 288882829.48
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 249187793.13
------------------- Find Path(s) ----------------------
Flow(id=3029, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 397. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 275964824.86
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 280707193.90
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 234239576.90
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 292834939.33
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 249187793.13
------------------- Remove Resources ----------------------
----- 398. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 275964824.86
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 280707193.90
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 234239576.90
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 292834939.33
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 249187793.13
------------------- Find Path(s) ----------------------
Flow(id=3029, source=zc_fl, sink=['zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 399. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 275964824.86
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 280707193.90
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 238079510.53
(sw_fr, sw_c) in bit/s: 397580751.34, 100589141.38
(sw_fr, zc_fr) in bit/s: None, 292834939.33
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 253171575.98
------------------- Find Path(s) ----------------------
Flow(id=4023, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 400. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 275964824.86
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 280707193.90
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 241647159.43
(sw_fr, sw_c) in bit/s: 397580751.34, 103413711.05
(sw_fr, zc_fr) in bit/s: None, 292834939.33
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 257153754.18
------------------- Remove Resources ----------------------
----- 401. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 275964824.86
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 250703021.29
(sw_c, sw_fr) in bit/s: None, 280707193.90
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 241647159.43
(sw_fr, sw_c) in bit/s: 397580751.34, 103413711.05
(sw_fr, zc_fr) in bit/s: None, 292834939.33
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 257153754.18
------------------- Find Path(s) ----------------------
Flow(id=4023, source=zc_fr, sink=['zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 402. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 279855961.93
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 254502372.29
(sw_c, sw_fr) in bit/s: None, 280707193.90
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 241647159.43
(sw_fr, sw_c) in bit/s: 397580751.34, 103413711.05
(sw_fr, zc_fr) in bit/s: None, 292834939.33
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 134180917.72
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 257153754.18
------------------- Find Path(s) ----------------------
Flow(id=6038, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 403. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  2000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 279855961.93
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 254502372.29
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 241647159.43
(sw_fr, sw_c) in bit/s: 397580751.34, 103413711.05
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 137083472.08
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 257153754.18
------------------- Remove Resources ----------------------
----- 404. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  2000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 279855961.93
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 254502372.29
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 86629128.89
(sw_c, sw_rr) in bit/s: 1063858361.46, 241647159.43
(sw_fr, sw_c) in bit/s: 397580751.34, 103413711.05
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 91292208.90
(sw_rr, sw_c) in bit/s: None, 137083472.08
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 257153754.18
------------------- Find Path(s) ----------------------
Flow(id=6038, source=zc_rr, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 405. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  2000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 279855961.93
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 254502372.29
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 90706513.49
(sw_c, sw_rr) in bit/s: 1063858361.46, 241647159.43
(sw_fr, sw_c) in bit/s: 397580751.34, 103413711.05
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 95403064.78
(sw_rr, sw_c) in bit/s: None, 137083472.08
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 257153754.18
------------------- Remove Resources ----------------------
----- 406. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  2000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 279855961.93
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 254502372.29
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 90706513.49
(sw_c, sw_rr) in bit/s: 1063858361.46, 241647159.43
(sw_fr, sw_c) in bit/s: 397580751.34, 103413711.05
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 95403064.78
(sw_rr, sw_c) in bit/s: None, 137083472.08
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 257153754.18
------------------- Find Path(s) ----------------------
Flow(id=6038, source=zc_rr, sink=['zc_fr', 'zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 407. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  2000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 283742425.23
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 259266972.75
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 90706513.49
(sw_c, sw_rr) in bit/s: 1063858361.46, 241647159.43
(sw_fr, sw_c) in bit/s: 397580751.34, 103413711.05
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 95403064.78
(sw_rr, sw_c) in bit/s: None, 137083472.08
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 257153754.18
------------------- Find Path(s) ----------------------
Flow(id=4000, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 408. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.648ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 287625913.05
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 262001671.95
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 90706513.49
(sw_c, sw_rr) in bit/s: 1063858361.46, 241647159.43
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 95403064.78
(sw_rr, sw_c) in bit/s: None, 137083472.08
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 257153754.18
------------------- Remove Resources ----------------------
----- 409. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 287625913.05
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 262001671.95
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 90706513.49
(sw_c, sw_rr) in bit/s: 1063858361.46, 241647159.43
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 95403064.78
(sw_rr, sw_c) in bit/s: None, 137083472.08
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 257153754.18
------------------- Find Path(s) ----------------------
Flow(id=4000, source=zc_fr, sink=['zc_fl', 'zc_rl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 410. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.648ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.648ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 287625913.05
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 262001671.95
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 94468109.41
(sw_c, sw_rr) in bit/s: 1063858361.46, 241647159.43
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 99510607.81
(sw_rr, sw_c) in bit/s: None, 137083472.08
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 257153754.18
------------------- Remove Resources ----------------------
----- 411. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 287625913.05
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 262001671.95
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 94468109.41
(sw_c, sw_rr) in bit/s: 1063858361.46, 241647159.43
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 99510607.81
(sw_rr, sw_c) in bit/s: None, 137083472.08
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 257153754.18
------------------- Find Path(s) ----------------------
Flow(id=4000, source=zc_fr, sink=['zc_fl', 'zc_rl', 'zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 412. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.648ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.648ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.648ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 287625913.05
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 262001671.95
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 94468109.41
(sw_c, sw_rr) in bit/s: 1063858361.46, 245482753.01
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 99510607.81
(sw_rr, sw_c) in bit/s: None, 137083472.08
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 261131196.63
------------------- Find Path(s) ----------------------
Flow(id=6068, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 413. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 291506441.04
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 266792632.12
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 94468109.41
(sw_c, sw_rr) in bit/s: 1063858361.46, 245482753.01
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 99510607.81
(sw_rr, sw_c) in bit/s: None, 139967781.53
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 261131196.63
------------------- Find Path(s) ----------------------
Flow(id=6064, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 414. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.654ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 295383928.94
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 270603950.39
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 94468109.41
(sw_c, sw_rr) in bit/s: 1063858361.46, 245482753.01
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 99510607.81
(sw_rr, sw_c) in bit/s: None, 142833289.19
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 261131196.63
------------------- Remove Resources ----------------------
----- 415. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 123859907.82
(sw_fl, zc_fl) in bit/s: None, 295383928.94
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 270603950.39
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 94468109.41
(sw_c, sw_rr) in bit/s: 1063858361.46, 245482753.01
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 99510607.81
(sw_rr, sw_c) in bit/s: None, 142833289.19
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 261131196.63
------------------- Find Path(s) ----------------------
Flow(id=3035, source=zc_fl, sink=['infotainment', 'zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 416. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.227ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.644ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 126957999.67
(sw_fl, zc_fl) in bit/s: None, 295383928.94
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 270603950.39
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 94468109.41
(sw_c, sw_rr) in bit/s: 1063858361.46, 249412187.54
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 99510607.81
(sw_rr, sw_c) in bit/s: None, 142833289.19
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 265105547.93
------------------- Remove Resources ----------------------
----- 417. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 126957999.67
(sw_fl, zc_fl) in bit/s: None, 295383928.94
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 270603950.39
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 94468109.41
(sw_c, sw_rr) in bit/s: 1063858361.46, 249412187.54
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 99510607.81
(sw_rr, sw_c) in bit/s: None, 142833289.19
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 265105547.93
------------------- Find Path(s) ----------------------
Flow(id=7004, source=infotainment, sink=['zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 418. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.215ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 295383928.94
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 270603950.39
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 94468109.41
(sw_c, sw_rr) in bit/s: 1063858361.46, 253249226.79
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 99510607.81
(sw_rr, sw_c) in bit/s: None, 142833289.19
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 269076641.70
------------------- Find Path(s) ----------------------
Flow(id=6072, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 419. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.655ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 299258558.14
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 274415336.15
(sw_c, sw_fr) in bit/s: None, 285257628.71
(sw_c, sw_rl) in bit/s: None, 94468109.41
(sw_c, sw_rr) in bit/s: 1063858361.46, 253249226.79
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 296783816.14
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 99510607.81
(sw_rr, sw_c) in bit/s: None, 145681017.85
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 269076641.70
------------------- Find Path(s) ----------------------
Flow(id=6026, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 420. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.655ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 299258558.14
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 274415336.15
(sw_c, sw_fr) in bit/s: None, 289165945.36
(sw_c, sw_rl) in bit/s: None, 94468109.41
(sw_c, sw_rr) in bit/s: 1063858361.46, 253249226.79
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 300731485.06
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 99510607.81
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 269076641.70
------------------- Remove Resources ----------------------
----- 421. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 299258558.14
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 274415336.15
(sw_c, sw_fr) in bit/s: None, 289165945.36
(sw_c, sw_rl) in bit/s: None, 94468109.41
(sw_c, sw_rr) in bit/s: 1063858361.46, 253249226.79
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 300731485.06
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 99510607.81
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 269076641.70
------------------- Find Path(s) ----------------------
Flow(id=7004, source=infotainment, sink=['zc_fl', 'zc_rr', 'zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 422. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rr', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.215ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 299258558.14
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 274415336.15
(sw_c, sw_fr) in bit/s: None, 292181429.16
(sw_c, sw_rl) in bit/s: None, 94468109.41
(sw_c, sw_rr) in bit/s: 1063858361.46, 253249226.79
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 304674189.57
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 99510607.81
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 269076641.70
------------------- Remove Resources ----------------------
----- 423. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rr', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 299258558.14
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 274415336.15
(sw_c, sw_fr) in bit/s: None, 292181429.16
(sw_c, sw_rl) in bit/s: None, 94468109.41
(sw_c, sw_rr) in bit/s: 1063858361.46, 253249226.79
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 304674189.57
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 99510607.81
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 269076641.70
------------------- Find Path(s) ----------------------
Flow(id=7004, source=infotainment, sink=['zc_fl', 'zc_rr', 'zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 424. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rr', 'zc_fr', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.215ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.631ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 299258558.14
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 274415336.15
(sw_c, sw_fr) in bit/s: None, 292181429.16
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1063858361.46, 253249226.79
(sw_fr, sw_c) in bit/s: 397580751.34, 106214955.67
(sw_fr, zc_fr) in bit/s: None, 304674189.57
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 269076641.70
------------------- Find Path(s) ----------------------
Flow(id=4039, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 425. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 303129979.06
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 276880807.54
(sw_c, sw_fr) in bit/s: None, 292181429.16
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1063858361.46, 253249226.79
(sw_fr, sw_c) in bit/s: 397580751.34, 108999094.47
(sw_fr, zc_fr) in bit/s: None, 304674189.57
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 269076641.70
------------------- Remove Resources ----------------------
----- 426. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 303129979.06
(sw_fl, infotainment) in bit/s: None, 103210052.71
(sw_c, sw_fl) in bit/s: None, 276880807.54
(sw_c, sw_fr) in bit/s: None, 292181429.16
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1063858361.46, 253249226.79
(sw_fr, sw_c) in bit/s: 397580751.34, 108999094.47
(sw_fr, zc_fr) in bit/s: None, 304674189.57
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 269076641.70
------------------- Find Path(s) ----------------------
Flow(id=4039, source=zc_fr, sink=['zc_fl', 'infotainment'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 427. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.648ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 303129979.06
(sw_fl, infotainment) in bit/s: None, 106768956.38
(sw_c, sw_fl) in bit/s: None, 276880807.54
(sw_c, sw_fr) in bit/s: None, 292181429.16
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1063858361.46, 253249226.79
(sw_fr, sw_c) in bit/s: 397580751.34, 108999094.47
(sw_fr, zc_fr) in bit/s: None, 304674189.57
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 269076641.70
------------------- Remove Resources ----------------------
----- 428. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 303129979.06
(sw_fl, infotainment) in bit/s: None, 106768956.38
(sw_c, sw_fl) in bit/s: None, 276880807.54
(sw_c, sw_fr) in bit/s: None, 292181429.16
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1063858361.46, 253249226.79
(sw_fr, sw_c) in bit/s: 397580751.34, 108999094.47
(sw_fr, zc_fr) in bit/s: None, 304674189.57
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 269076641.70
------------------- Find Path(s) ----------------------
Flow(id=4039, source=zc_fr, sink=['zc_fl', 'infotainment', 'zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 429. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'infotainment', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.648ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 303129979.06
(sw_fl, infotainment) in bit/s: None, 106768956.38
(sw_c, sw_fl) in bit/s: None, 276880807.54
(sw_c, sw_fr) in bit/s: None, 292181429.16
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1063858361.46, 256796470.76
(sw_fr, sw_c) in bit/s: 397580751.34, 108999094.47
(sw_fr, zc_fr) in bit/s: None, 304674189.57
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 273044654.53
------------------- Find Path(s) ----------------------
Flow(id=4050, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 430. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 306998279.11
(sw_fl, infotainment) in bit/s: None, 106768956.38
(sw_c, sw_fl) in bit/s: None, 280673636.12
(sw_c, sw_fr) in bit/s: None, 292181429.16
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1063858361.46, 256796470.76
(sw_fr, sw_c) in bit/s: 397580751.34, 111765647.78
(sw_fr, zc_fr) in bit/s: None, 304674189.57
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 273044654.53
------------------- Remove Resources ----------------------
----- 431. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 306998279.11
(sw_fl, infotainment) in bit/s: None, 106768956.38
(sw_c, sw_fl) in bit/s: None, 280673636.12
(sw_c, sw_fr) in bit/s: None, 292181429.16
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1063858361.46, 256796470.76
(sw_fr, sw_c) in bit/s: 397580751.34, 111765647.78
(sw_fr, zc_fr) in bit/s: None, 304674189.57
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 273044654.53
------------------- Find Path(s) ----------------------
Flow(id=4050, source=zc_fr, sink=['zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 432. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 306998279.11
(sw_fl, infotainment) in bit/s: None, 106768956.38
(sw_c, sw_fl) in bit/s: None, 280673636.12
(sw_c, sw_fr) in bit/s: None, 292181429.16
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1063858361.46, 260629176.71
(sw_fr, sw_c) in bit/s: 397580751.34, 111765647.78
(sw_fr, zc_fr) in bit/s: None, 304674189.57
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 277009414.81
------------------- Remove Resources ----------------------
----- 433. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 306998279.11
(sw_fl, infotainment) in bit/s: None, 106768956.38
(sw_c, sw_fl) in bit/s: None, 280673636.12
(sw_c, sw_fr) in bit/s: None, 292181429.16
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1063858361.46, 260629176.71
(sw_fr, sw_c) in bit/s: 397580751.34, 111765647.78
(sw_fr, zc_fr) in bit/s: None, 304674189.57
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 277009414.81
------------------- Find Path(s) ----------------------
Flow(id=6072, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 434. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.655ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.655ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 306998279.11
(sw_fl, infotainment) in bit/s: None, 106768956.38
(sw_c, sw_fl) in bit/s: None, 280673636.12
(sw_c, sw_fr) in bit/s: None, 296867930.09
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1063858361.46, 260629176.71
(sw_fr, sw_c) in bit/s: 397580751.34, 111765647.78
(sw_fr, zc_fr) in bit/s: None, 308614058.43
(sw_rl, sw_c) in bit/s: None, 13696376.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1269419900.72, None
(sw_rr, zc_rr) in bit/s: None, 277009414.81
------------------- Find Path(s) ----------------------
Flow(id=1112, source=camera_rear, sink=['adas'], data_per_interval=11520, sending_interval=0.000065, deadline=0.001, max_frame_size=11424, priority=0, redundancy=False)
Path found: [[('camera_rear', 'sw_rl', 0), ('sw_rl', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]]
------------------- Reserve Resources ----------------------
----- 435. Flow Operation -- add -----
Flow Details: Source:  camera_rear , Destination:  ['adas'] , Bits:  11520 , Interval:  0.065 ms , Deadline:  1.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('camera_rear', 'sw_rl', 0), ('sw_rl', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.636ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 306998279.11
(sw_fl, infotainment) in bit/s: None, 106768956.38
(sw_c, sw_fl) in bit/s: None, 280673636.12
(sw_c, sw_fr) in bit/s: None, 296867930.09
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1505961172.68, 260731231.49
(sw_fr, sw_c) in bit/s: 397580751.34, 111765647.78
(sw_fr, zc_fr) in bit/s: None, 308614058.43
(sw_rl, sw_c) in bit/s: 225672462.41, 13776646.42
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 148517165.26
(sw_rr, adas) in bit/s: 1744036582.98, None
(sw_rr, zc_rr) in bit/s: None, 277009414.81
------------------- Find Path(s) ----------------------
Flow(id=6069, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 436. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.656ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 310863495.18
(sw_fl, infotainment) in bit/s: None, 106768956.38
(sw_c, sw_fl) in bit/s: None, 285635589.16
(sw_c, sw_fr) in bit/s: None, 296867930.09
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1505961172.68, 260731231.49
(sw_fr, sw_c) in bit/s: 397580751.34, 111765647.78
(sw_fr, zc_fr) in bit/s: None, 308614058.43
(sw_rl, sw_c) in bit/s: 225672462.41, 13776646.42
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 151326801.40
(sw_rr, adas) in bit/s: 1744036582.98, None
(sw_rr, zc_rr) in bit/s: None, 277009414.81
------------------- Find Path(s) ----------------------
Flow(id=6006, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 437. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.657ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 314726023.17
(sw_fl, infotainment) in bit/s: None, 106768956.38
(sw_c, sw_fl) in bit/s: None, 289444131.59
(sw_c, sw_fr) in bit/s: None, 296867930.09
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1505961172.68, 260731231.49
(sw_fr, sw_c) in bit/s: 397580751.34, 111765647.78
(sw_fr, zc_fr) in bit/s: None, 308614058.43
(sw_rl, sw_c) in bit/s: 225672462.41, 13776646.42
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 154119916.68
(sw_rr, adas) in bit/s: 1744036582.98, None
(sw_rr, zc_rr) in bit/s: None, 277009414.81
------------------- Remove Resources ----------------------
----- 438. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 314726023.17
(sw_fl, infotainment) in bit/s: None, 106768956.38
(sw_c, sw_fl) in bit/s: None, 289444131.59
(sw_c, sw_fr) in bit/s: None, 296867930.09
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1505961172.68, 260731231.49
(sw_fr, sw_c) in bit/s: 397580751.34, 111765647.78
(sw_fr, zc_fr) in bit/s: None, 308614058.43
(sw_rl, sw_c) in bit/s: 225672462.41, 13776646.42
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 154119916.68
(sw_rr, adas) in bit/s: 1744036582.98, None
(sw_rr, zc_rr) in bit/s: None, 277009414.81
------------------- Find Path(s) ----------------------
Flow(id=6006, source=zc_rr, sink=['zc_fl', 'infotainment'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 439. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.657ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.657ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 314726023.17
(sw_fl, infotainment) in bit/s: None, 110328055.94
(sw_c, sw_fl) in bit/s: None, 289444131.59
(sw_c, sw_fr) in bit/s: None, 296867930.09
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1505961172.68, 260731231.49
(sw_fr, sw_c) in bit/s: 397580751.34, 111765647.78
(sw_fr, zc_fr) in bit/s: None, 308614058.43
(sw_rl, sw_c) in bit/s: 225672462.41, 13776646.42
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 154119916.68
(sw_rr, adas) in bit/s: 1744036582.98, None
(sw_rr, zc_rr) in bit/s: None, 277009414.81
------------------- Remove Resources ----------------------
----- 440. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 314726023.17
(sw_fl, infotainment) in bit/s: None, 110328055.94
(sw_c, sw_fl) in bit/s: None, 289444131.59
(sw_c, sw_fr) in bit/s: None, 296867930.09
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1505961172.68, 260731231.49
(sw_fr, sw_c) in bit/s: 397580751.34, 111765647.78
(sw_fr, zc_fr) in bit/s: None, 308614058.43
(sw_rl, sw_c) in bit/s: 225672462.41, 13776646.42
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 154119916.68
(sw_rr, adas) in bit/s: 1744036582.98, None
(sw_rr, zc_rr) in bit/s: None, 277009414.81
------------------- Find Path(s) ----------------------
Flow(id=6006, source=zc_rr, sink=['zc_fl', 'infotainment', 'zc_fr'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 441. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'infotainment', 'zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.657ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.657ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.657ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 314726023.17
(sw_fl, infotainment) in bit/s: None, 110328055.94
(sw_c, sw_fl) in bit/s: None, 289444131.59
(sw_c, sw_fr) in bit/s: None, 300774139.51
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1505961172.68, 260731231.49
(sw_fr, sw_c) in bit/s: 397580751.34, 111765647.78
(sw_fr, zc_fr) in bit/s: None, 312550803.31
(sw_rl, sw_c) in bit/s: 225672462.41, 13776646.42
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 154119916.68
(sw_rr, adas) in bit/s: 1744036582.98, None
(sw_rr, zc_rr) in bit/s: None, 277009414.81
------------------- Find Path(s) ----------------------
Flow(id=4028, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 442. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.650ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 318585194.65
(sw_fl, infotainment) in bit/s: None, 110328055.94
(sw_c, sw_fl) in bit/s: None, 291835019.65
(sw_c, sw_fr) in bit/s: None, 300774139.51
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1505961172.68, 260731231.49
(sw_fr, sw_c) in bit/s: 397580751.34, 114514889.16
(sw_fr, zc_fr) in bit/s: None, 312550803.31
(sw_rl, sw_c) in bit/s: 225672462.41, 13776646.42
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 154119916.68
(sw_rr, adas) in bit/s: 1744036582.98, None
(sw_rr, zc_rr) in bit/s: None, 277009414.81
------------------- Remove Resources ----------------------
----- 443. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 318585194.65
(sw_fl, infotainment) in bit/s: None, 110328055.94
(sw_c, sw_fl) in bit/s: None, 291835019.65
(sw_c, sw_fr) in bit/s: None, 300774139.51
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1505961172.68, 260731231.49
(sw_fr, sw_c) in bit/s: 397580751.34, 114514889.16
(sw_fr, zc_fr) in bit/s: None, 312550803.31
(sw_rl, sw_c) in bit/s: 225672462.41, 13776646.42
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 154119916.68
(sw_rr, adas) in bit/s: 1744036582.98, None
(sw_rr, zc_rr) in bit/s: None, 277009414.81
------------------- Find Path(s) ----------------------
Flow(id=4028, source=zc_fr, sink=['zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 444. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.650ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.650ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 318585194.65
(sw_fl, infotainment) in bit/s: None, 110328055.94
(sw_c, sw_fl) in bit/s: None, 291835019.65
(sw_c, sw_fr) in bit/s: None, 300774139.51
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1505961172.68, 264565413.89
(sw_fr, sw_c) in bit/s: 397580751.34, 114514889.16
(sw_fr, zc_fr) in bit/s: None, 312550803.31
(sw_rl, sw_c) in bit/s: 225672462.41, 13776646.42
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 154119916.68
(sw_rr, adas) in bit/s: 1744036582.98, None
(sw_rr, zc_rr) in bit/s: None, 280970958.83
------------------- Find Path(s) ----------------------
Flow(id=6019, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 445. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.657ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 322443237.58
(sw_fl, infotainment) in bit/s: None, 110328055.94
(sw_c, sw_fl) in bit/s: None, 296950736.96
(sw_c, sw_fr) in bit/s: None, 300774139.51
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1505961172.68, 264565413.89
(sw_fr, sw_c) in bit/s: 397580751.34, 114514889.16
(sw_fr, zc_fr) in bit/s: None, 312550803.31
(sw_rl, sw_c) in bit/s: 225672462.41, 13776646.42
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 156902303.21
(sw_rr, adas) in bit/s: 1744036582.98, None
(sw_rr, zc_rr) in bit/s: None, 280970958.83
------------------- Remove Resources ----------------------
----- 446. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 322443237.58
(sw_fl, infotainment) in bit/s: None, 110328055.94
(sw_c, sw_fl) in bit/s: None, 296950736.96
(sw_c, sw_fr) in bit/s: None, 300774139.51
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1505961172.68, 264565413.89
(sw_fr, sw_c) in bit/s: 397580751.34, 114514889.16
(sw_fr, zc_fr) in bit/s: None, 312550803.31
(sw_rl, sw_c) in bit/s: 225672462.41, 13776646.42
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 156902303.21
(sw_rr, adas) in bit/s: 1744036582.98, None
(sw_rr, zc_rr) in bit/s: None, 280970958.83
------------------- Find Path(s) ----------------------
Flow(id=6019, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 447. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.657ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.658ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 322443237.58
(sw_fl, infotainment) in bit/s: None, 110328055.94
(sw_c, sw_fl) in bit/s: None, 296950736.96
(sw_c, sw_fr) in bit/s: None, 304680988.43
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1505961172.68, 264565413.89
(sw_fr, sw_c) in bit/s: 397580751.34, 114514889.16
(sw_fr, zc_fr) in bit/s: None, 316486067.14
(sw_rl, sw_c) in bit/s: 225672462.41, 13776646.42
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 156902303.21
(sw_rr, adas) in bit/s: 1744036582.98, None
(sw_rr, zc_rr) in bit/s: None, 280970958.83
------------------- Find Path(s) ----------------------
Flow(id=2113, source=lidar_rl, sink=['adas'], data_per_interval=12336, sending_interval=0.00015, deadline=0.001, max_frame_size=12240, priority=0, redundancy=False)
Path found: [[('lidar_rl', 'sw_rl', 0), ('sw_rl', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]]
------------------- Reserve Resources ----------------------
----- 448. Flow Operation -- add -----
Flow Details: Source:  lidar_rl , Destination:  ['adas'] , Bits:  12336 , Interval:  0.150 ms , Deadline:  1.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('lidar_rl', 'sw_rl', 0), ('sw_rl', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.637ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 322443237.58
(sw_fl, infotainment) in bit/s: None, 110328055.94
(sw_c, sw_fl) in bit/s: None, 296950736.96
(sw_c, sw_fr) in bit/s: None, 304680988.43
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1747580895.08, 264626736.68
(sw_fr, sw_c) in bit/s: 397580751.34, 114514889.16
(sw_fr, zc_fr) in bit/s: None, 316486067.14
(sw_rl, sw_c) in bit/s: 359282634.55, 13783477.39
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 156902303.21
(sw_rr, adas) in bit/s: 1977098766.99, None
(sw_rr, zc_rr) in bit/s: None, 280970958.83
------------------- Find Path(s) ----------------------
Flow(id=12113, source=lidar_rl, sink=['adas'], data_per_interval=3536, sending_interval=0.00015, deadline=0.001, max_frame_size=3440, priority=0, redundancy=False)
Path found: [[('lidar_rl', 'sw_rl', 0), ('sw_rl', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]]
------------------- Reserve Resources ----------------------
----- 449. Flow Operation -- add -----
Flow Details: Source:  lidar_rl , Destination:  ['adas'] , Bits:  3536 , Interval:  0.150 ms , Deadline:  1.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('lidar_rl', 'sw_rl', 0), ('sw_rl', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.640ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 322443237.58
(sw_fl, infotainment) in bit/s: None, 110328055.94
(sw_c, sw_fl) in bit/s: None, 296950736.96
(sw_c, sw_fr) in bit/s: None, 304680988.43
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1816838947.80, 264644987.55
(sw_fr, sw_c) in bit/s: 397580751.34, 114514889.16
(sw_fr, zc_fr) in bit/s: None, 316486067.14
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 156902303.21
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 280970958.83
------------------- Find Path(s) ----------------------
Flow(id=3037, source=zc_fl, sink=['infotainment'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 450. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.228ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 130483992.35
(sw_fl, zc_fl) in bit/s: None, 322443237.58
(sw_fl, infotainment) in bit/s: None, 113483897.40
(sw_c, sw_fl) in bit/s: None, 296950736.96
(sw_c, sw_fr) in bit/s: None, 304680988.43
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1816838947.80, 264644987.55
(sw_fr, sw_c) in bit/s: 397580751.34, 114514889.16
(sw_fr, zc_fr) in bit/s: None, 316486067.14
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 156902303.21
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 280970958.83
------------------- Find Path(s) ----------------------
Flow(id=3030, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 451. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.645ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 133548089.18
(sw_fl, zc_fl) in bit/s: None, 322443237.58
(sw_fl, infotainment) in bit/s: None, 113483897.40
(sw_c, sw_fl) in bit/s: None, 296950736.96
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1816838947.80, 264644987.55
(sw_fr, sw_c) in bit/s: 397580751.34, 114514889.16
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 156902303.21
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 280970958.83
------------------- Find Path(s) ----------------------
Flow(id=4019, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 452. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 133548089.18
(sw_fl, zc_fl) in bit/s: None, 326296398.64
(sw_fl, infotainment) in bit/s: None, 113483897.40
(sw_c, sw_fl) in bit/s: None, 299304706.26
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1816838947.80, 264644987.55
(sw_fr, sw_c) in bit/s: 397580751.34, 117247171.78
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 156902303.21
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 280970958.83
------------------- Remove Resources ----------------------
----- 453. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 133548089.18
(sw_fl, zc_fl) in bit/s: None, 326296398.64
(sw_fl, infotainment) in bit/s: None, 113483897.40
(sw_c, sw_fl) in bit/s: None, 299304706.26
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1816838947.80, 264644987.55
(sw_fr, sw_c) in bit/s: 397580751.34, 117247171.78
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 156902303.21
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 280970958.83
------------------- Find Path(s) ----------------------
Flow(id=4019, source=zc_fr, sink=['zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 454. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 133548089.18
(sw_fl, zc_fl) in bit/s: None, 326296398.64
(sw_fl, infotainment) in bit/s: None, 113483897.40
(sw_c, sw_fl) in bit/s: None, 299304706.26
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1816838947.80, 268480323.15
(sw_fr, sw_c) in bit/s: 397580751.34, 117247171.78
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 156902303.21
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 284929343.38
------------------- Remove Resources ----------------------
----- 455. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 133548089.18
(sw_fl, zc_fl) in bit/s: None, 326296398.64
(sw_fl, infotainment) in bit/s: None, 113483897.40
(sw_c, sw_fl) in bit/s: None, 299304706.26
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 98404277.28
(sw_c, sw_rr) in bit/s: 1816838947.80, 268480323.15
(sw_fr, sw_c) in bit/s: 397580751.34, 117247171.78
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 103614816.92
(sw_rr, sw_c) in bit/s: None, 156902303.21
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 284929343.38
------------------- Find Path(s) ----------------------
Flow(id=4019, source=zc_fr, sink=['zc_fl', 'zc_rr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 456. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 133548089.18
(sw_fl, zc_fl) in bit/s: None, 326296398.64
(sw_fl, infotainment) in bit/s: None, 113483897.40
(sw_c, sw_fl) in bit/s: None, 299304706.26
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 102340437.24
(sw_c, sw_rr) in bit/s: 1816838947.80, 268480323.15
(sw_fr, sw_c) in bit/s: 397580751.34, 117247171.78
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 107715676.07
(sw_rr, sw_c) in bit/s: None, 156902303.21
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 284929343.38
------------------- Find Path(s) ----------------------
Flow(id=6025, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 457. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.658ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 133548089.18
(sw_fl, zc_fl) in bit/s: None, 330146903.76
(sw_fl, infotainment) in bit/s: None, 113483897.40
(sw_c, sw_fl) in bit/s: None, 304451156.28
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 102340437.24
(sw_c, sw_rr) in bit/s: 1816838947.80, 268480323.15
(sw_fr, sw_c) in bit/s: 397580751.34, 117247171.78
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 107715676.07
(sw_rr, sw_c) in bit/s: None, 159659927.58
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 284929343.38
------------------- Remove Resources ----------------------
----- 458. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 133548089.18
(sw_fl, zc_fl) in bit/s: None, 330146903.76
(sw_fl, infotainment) in bit/s: None, 113483897.40
(sw_c, sw_fl) in bit/s: None, 304451156.28
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 102340437.24
(sw_c, sw_rr) in bit/s: 1816838947.80, 268480323.15
(sw_fr, sw_c) in bit/s: 397580751.34, 117247171.78
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 107715676.07
(sw_rr, sw_c) in bit/s: None, 159659927.58
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 284929343.38
------------------- Find Path(s) ----------------------
Flow(id=6025, source=zc_rr, sink=['zc_fl', 'infotainment'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 459. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.658ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.658ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 133548089.18
(sw_fl, zc_fl) in bit/s: None, 330146903.76
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 304451156.28
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 102340437.24
(sw_c, sw_rr) in bit/s: 1816838947.80, 268480323.15
(sw_fr, sw_c) in bit/s: 397580751.34, 117247171.78
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 107715676.07
(sw_rr, sw_c) in bit/s: None, 159659927.58
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 284929343.38
------------------- Find Path(s) ----------------------
Flow(id=4015, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 460. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 133548089.18
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 102340437.24
(sw_c, sw_rr) in bit/s: 1816838947.80, 268480323.15
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 107715676.07
(sw_rr, sw_c) in bit/s: None, 159659927.58
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 284929343.38
------------------- Remove Resources ----------------------
----- 461. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 133548089.18
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 102340437.24
(sw_c, sw_rr) in bit/s: 1816838947.80, 268480323.15
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 107715676.07
(sw_rr, sw_c) in bit/s: None, 159659927.58
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 284929343.38
------------------- Find Path(s) ----------------------
Flow(id=4015, source=zc_fr, sink=['zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 462. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 133548089.18
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 102340437.24
(sw_c, sw_rr) in bit/s: 1816838947.80, 272315658.76
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 107715676.07
(sw_rr, sw_c) in bit/s: None, 159659927.58
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 288884572.23
------------------- Remove Resources ----------------------
----- 463. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 133548089.18
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 102340437.24
(sw_c, sw_rr) in bit/s: 1816838947.80, 272315658.76
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 107715676.07
(sw_rr, sw_c) in bit/s: None, 159659927.58
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 288884572.23
------------------- Find Path(s) ----------------------
Flow(id=4015, source=zc_fr, sink=['zc_fl', 'zc_rr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 464. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 133548089.18
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 106276597.19
(sw_c, sw_rr) in bit/s: 1816838947.80, 272315658.76
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 111813207.74
(sw_rr, sw_c) in bit/s: None, 159659927.58
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 288884572.23
------------------- Find Path(s) ----------------------
Flow(id=3002, source=zc_fl, sink=['zc_rr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 465. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 136593899.00
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 106276597.19
(sw_c, sw_rr) in bit/s: 1816838947.80, 275943872.46
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 111813207.74
(sw_rr, sw_c) in bit/s: None, 159659927.58
(sw_rr, adas) in bit/s: 2042221480.04, None
(sw_rr, zc_rr) in bit/s: None, 292837559.10
------------------- Find Path(s) ----------------------
Flow(id=2114, source=lidar_rr, sink=['adas'], data_per_interval=12336, sending_interval=0.00015, deadline=0.001, max_frame_size=12240, priority=0, redundancy=False)
Path found: [[('lidar_rr', 'sw_rr', 0), ('sw_rr', 'adas', 0)]]
------------------- Reserve Resources ----------------------
----- 466. Flow Operation -- add -----
Flow Details: Source:  lidar_rr , Destination:  ['adas'] , Bits:  12336 , Interval:  0.150 ms , Deadline:  1.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('lidar_rr', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.220ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 136593899.00
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 106276597.19
(sw_c, sw_rr) in bit/s: 1816838947.80, 275943872.46
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 111813207.74
(sw_rr, sw_c) in bit/s: None, 159659927.58
(sw_rr, adas) in bit/s: 2174528839.12, None
(sw_rr, zc_rr) in bit/s: None, 292837559.10
------------------- Find Path(s) ----------------------
Flow(id=12114, source=lidar_rr, sink=['adas'], data_per_interval=3536, sending_interval=0.00015, deadline=0.001, max_frame_size=3440, priority=0, redundancy=False)
Path found: [[('lidar_rr', 'sw_rr', 0), ('sw_rr', 'adas', 0)]]
------------------- Reserve Resources ----------------------
----- 467. Flow Operation -- add -----
Flow Details: Source:  lidar_rr , Destination:  ['adas'] , Bits:  3536 , Interval:  0.150 ms , Deadline:  1.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('lidar_rr', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.224ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 136593899.00
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 106276597.19
(sw_c, sw_rr) in bit/s: 1816838947.80, 275943872.46
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 111813207.74
(sw_rr, sw_c) in bit/s: None, 159659927.58
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 292837559.10
------------------- Remove Resources ----------------------
----- 468. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 136593899.00
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 307414446.20
(sw_c, sw_rl) in bit/s: None, 106276597.19
(sw_c, sw_rr) in bit/s: 1816838947.80, 275943872.46
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 320416222.12
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 111813207.74
(sw_rr, sw_c) in bit/s: None, 159659927.58
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 292837559.10
------------------- Find Path(s) ----------------------
Flow(id=3037, source=zc_fl, sink=['infotainment', 'zc_fr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 469. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.229ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 139616048.96
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 311305624.96
(sw_c, sw_rl) in bit/s: None, 106276597.19
(sw_c, sw_rr) in bit/s: 1816838947.80, 275943872.46
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 324343234.08
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 111813207.74
(sw_rr, sw_c) in bit/s: None, 159659927.58
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 292837559.10
------------------- Find Path(s) ----------------------
Flow(id=6051, source=zc_rr, sink=['zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 470. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.659ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 139616048.96
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 311305624.96
(sw_c, sw_rl) in bit/s: None, 110382726.14
(sw_c, sw_rr) in bit/s: 1816838947.80, 275943872.46
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 324343234.08
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 115907415.99
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 292837559.10
------------------- Remove Resources ----------------------
----- 471. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 139616048.96
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 311305624.96
(sw_c, sw_rl) in bit/s: None, 110382726.14
(sw_c, sw_rr) in bit/s: 1816838947.80, 275943872.46
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 324343234.08
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 115907415.99
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 292837559.10
------------------- Find Path(s) ----------------------
Flow(id=3037, source=zc_fl, sink=['infotainment', 'zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 472. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.229ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.646ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 139616048.96
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 311305624.96
(sw_c, sw_rl) in bit/s: None, 110382726.14
(sw_c, sw_rr) in bit/s: 1816838947.80, 279776310.89
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 324343234.08
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 115907415.99
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 296786480.97
------------------- Remove Resources ----------------------
----- 473. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 139616048.96
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 311305624.96
(sw_c, sw_rl) in bit/s: None, 110382726.14
(sw_c, sw_rr) in bit/s: 1816838947.80, 279776310.89
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 324343234.08
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 115907415.99
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 296786480.97
------------------- Find Path(s) ----------------------
Flow(id=6051, source=zc_rr, sink=['zc_rl', 'zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 474. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.659ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.659ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 139616048.96
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 316157986.41
(sw_c, sw_rl) in bit/s: None, 110382726.14
(sw_c, sw_rr) in bit/s: 1816838947.80, 279776310.89
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 328267148.48
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 115907415.99
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 296786480.97
------------------- Remove Resources ----------------------
----- 475. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 139616048.96
(sw_fl, zc_fl) in bit/s: None, 333994048.44
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 306768016.97
(sw_c, sw_fr) in bit/s: None, 316157986.41
(sw_c, sw_rl) in bit/s: None, 110382726.14
(sw_c, sw_rr) in bit/s: 1816838947.80, 279776310.89
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 328267148.48
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 115907415.99
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 296786480.97
------------------- Find Path(s) ----------------------
Flow(id=6051, source=zc_rr, sink=['zc_rl', 'zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 476. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fr', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.659ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.659ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.659ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 139616048.96
(sw_fl, zc_fl) in bit/s: None, 337838187.99
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 311945832.57
(sw_c, sw_fr) in bit/s: None, 316157986.41
(sw_c, sw_rl) in bit/s: None, 110382726.14
(sw_c, sw_rr) in bit/s: 1816838947.80, 279776310.89
(sw_fr, sw_c) in bit/s: 397580751.34, 119962652.07
(sw_fr, zc_fr) in bit/s: None, 328267148.48
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 115907415.99
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 296786480.97
------------------- Find Path(s) ----------------------
Flow(id=4025, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 477. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.652ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 139616048.96
(sw_fl, zc_fl) in bit/s: None, 341679490.21
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 314225675.95
(sw_c, sw_fr) in bit/s: None, 316157986.41
(sw_c, sw_rl) in bit/s: None, 110382726.14
(sw_c, sw_rr) in bit/s: 1816838947.80, 279776310.89
(sw_fr, sw_c) in bit/s: 397580751.34, 122662062.28
(sw_fr, zc_fr) in bit/s: None, 328267148.48
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 115907415.99
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 296786480.97
------------------- Find Path(s) ----------------------
Flow(id=4013, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 478. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 139616048.96
(sw_fl, zc_fl) in bit/s: None, 345517850.26
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 318011538.46
(sw_c, sw_fr) in bit/s: None, 316157986.41
(sw_c, sw_rl) in bit/s: None, 110382726.14
(sw_c, sw_rr) in bit/s: 1816838947.80, 279776310.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 328267148.48
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 115907415.99
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 296786480.97
------------------- Remove Resources ----------------------
----- 479. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 139616048.96
(sw_fl, zc_fl) in bit/s: None, 345517850.26
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 318011538.46
(sw_c, sw_fr) in bit/s: None, 316157986.41
(sw_c, sw_rl) in bit/s: None, 110382726.14
(sw_c, sw_rr) in bit/s: 1816838947.80, 279776310.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 328267148.48
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 115907415.99
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 296786480.97
------------------- Find Path(s) ----------------------
Flow(id=4025, source=zc_fr, sink=['zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 480. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 139616048.96
(sw_fl, zc_fl) in bit/s: None, 345517850.26
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 318011538.46
(sw_c, sw_fr) in bit/s: None, 316157986.41
(sw_c, sw_rl) in bit/s: None, 110382726.14
(sw_c, sw_rr) in bit/s: 1816838947.80, 283608795.56
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 328267148.48
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 115907415.99
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 300732433.13
------------------- Find Path(s) ----------------------
Flow(id=7007, source=infotainment, sink=['zc_fr'], data_per_interval=688, sending_interval=0.15, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 481. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr'] , Bits:  688 , Interval:  150.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.632ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 143105885.67
(sw_fl, zc_fl) in bit/s: None, 345517850.26
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 318011538.46
(sw_c, sw_fr) in bit/s: None, 318966846.71
(sw_c, sw_rl) in bit/s: None, 110382726.14
(sw_c, sw_rr) in bit/s: 1816838947.80, 283608795.56
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 332188048.64
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 115907415.99
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 300732433.13
------------------- Find Path(s) ----------------------
Flow(id=3019, source=zc_fl, sink=['zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 482. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 345517850.26
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 318011538.46
(sw_c, sw_fr) in bit/s: None, 318966846.71
(sw_c, sw_rl) in bit/s: None, 114104990.86
(sw_c, sw_rr) in bit/s: 1816838947.80, 283608795.56
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 332188048.64
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 119998304.85
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 300732433.13
------------------- Remove Resources ----------------------
----- 483. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 345517850.26
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 318011538.46
(sw_c, sw_fr) in bit/s: None, 318966846.71
(sw_c, sw_rl) in bit/s: None, 114104990.86
(sw_c, sw_rr) in bit/s: 1816838947.80, 283608795.56
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 332188048.64
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 119998304.85
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 300732433.13
------------------- Find Path(s) ----------------------
Flow(id=3019, source=zc_fl, sink=['zc_rl', 'zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 484. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 345517850.26
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 318011538.46
(sw_c, sw_fr) in bit/s: None, 322856554.79
(sw_c, sw_rl) in bit/s: None, 114104990.86
(sw_c, sw_rr) in bit/s: 1816838947.80, 283608795.56
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 336105738.75
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 119998304.85
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 300732433.13
------------------- Remove Resources ----------------------
----- 485. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 345517850.26
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 318011538.46
(sw_c, sw_fr) in bit/s: None, 322856554.79
(sw_c, sw_rl) in bit/s: None, 114104990.86
(sw_c, sw_rr) in bit/s: 1816838947.80, 283608795.56
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 336105738.75
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 119998304.85
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 300732433.13
------------------- Find Path(s) ----------------------
Flow(id=3019, source=zc_fl, sink=['zc_rl', 'zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 486. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 345517850.26
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 318011538.46
(sw_c, sw_fr) in bit/s: None, 322856554.79
(sw_c, sw_rl) in bit/s: None, 114104990.86
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 336105738.75
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 119998304.85
(sw_rr, sw_c) in bit/s: None, 162398349.62
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Find Path(s) ----------------------
Flow(id=6039, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 487. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.660ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 345517850.26
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 318011538.46
(sw_c, sw_fr) in bit/s: None, 327617582.69
(sw_c, sw_rl) in bit/s: None, 114104990.86
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 340020497.74
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 119998304.85
(sw_rr, sw_c) in bit/s: None, 165120094.04
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Find Path(s) ----------------------
Flow(id=6028, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 488. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.660ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 345517850.26
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 318011538.46
(sw_c, sw_fr) in bit/s: None, 331517756.98
(sw_c, sw_rl) in bit/s: None, 114104990.86
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 343932157.27
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 119998304.85
(sw_rr, sw_c) in bit/s: None, 167824600.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Remove Resources ----------------------
----- 489. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 345517850.26
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 318011538.46
(sw_c, sw_fr) in bit/s: None, 331517756.98
(sw_c, sw_rl) in bit/s: None, 114104990.86
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 343932157.27
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 119998304.85
(sw_rr, sw_c) in bit/s: None, 167824600.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Find Path(s) ----------------------
Flow(id=6028, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 490. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.660ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.660ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 349353168.32
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 323117311.07
(sw_c, sw_fr) in bit/s: None, 331517756.98
(sw_c, sw_rl) in bit/s: None, 114104990.86
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 343932157.27
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 119998304.85
(sw_rr, sw_c) in bit/s: None, 167824600.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Find Path(s) ----------------------
Flow(id=6067, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 491. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.661ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 349353168.32
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 323117311.07
(sw_c, sw_fr) in bit/s: None, 335418293.46
(sw_c, sw_rl) in bit/s: None, 114104990.86
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 347841621.47
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 119998304.85
(sw_rr, sw_c) in bit/s: None, 170515865.39
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Remove Resources ----------------------
----- 492. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 349353168.32
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 323117311.07
(sw_c, sw_fr) in bit/s: None, 335418293.46
(sw_c, sw_rl) in bit/s: None, 114104990.86
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 347841621.47
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 119998304.85
(sw_rr, sw_c) in bit/s: None, 170515865.39
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Find Path(s) ----------------------
Flow(id=6067, source=zc_rr, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 493. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.661ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.661ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 349353168.32
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 323117311.07
(sw_c, sw_fr) in bit/s: None, 335418293.46
(sw_c, sw_rl) in bit/s: None, 118221700.25
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 347841621.47
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 124086252.73
(sw_rr, sw_c) in bit/s: None, 170515865.39
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Remove Resources ----------------------
----- 494. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 349353168.32
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 323117311.07
(sw_c, sw_fr) in bit/s: None, 335418293.46
(sw_c, sw_rl) in bit/s: None, 118221700.25
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 347841621.47
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 124086252.73
(sw_rr, sw_c) in bit/s: None, 170515865.39
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Find Path(s) ----------------------
Flow(id=6067, source=zc_rr, sink=['zc_fr', 'zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 495. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.661ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.661ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.661ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 353186350.49
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 326919020.66
(sw_c, sw_fr) in bit/s: None, 335418293.46
(sw_c, sw_rl) in bit/s: None, 118221700.25
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 347841621.47
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 124086252.73
(sw_rr, sw_c) in bit/s: None, 170515865.39
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Find Path(s) ----------------------
Flow(id=6001, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 496. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.662ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 353186350.49
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 326919020.66
(sw_c, sw_fr) in bit/s: None, 339318490.38
(sw_c, sw_rl) in bit/s: None, 118221700.25
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 351747160.04
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 124086252.73
(sw_rr, sw_c) in bit/s: None, 173186674.22
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Remove Resources ----------------------
----- 497. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 353186350.49
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 326919020.66
(sw_c, sw_fr) in bit/s: None, 339318490.38
(sw_c, sw_rl) in bit/s: None, 118221700.25
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 351747160.04
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 124086252.73
(sw_rr, sw_c) in bit/s: None, 173186674.22
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Find Path(s) ----------------------
Flow(id=6001, source=zc_rr, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 498. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.662ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.662ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 353186350.49
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 326919020.66
(sw_c, sw_fr) in bit/s: None, 339318490.38
(sw_c, sw_rl) in bit/s: None, 122162433.43
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 351747160.04
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 128170612.87
(sw_rr, sw_c) in bit/s: None, 173186674.22
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Remove Resources ----------------------
----- 499. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 353186350.49
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 326919020.66
(sw_c, sw_fr) in bit/s: None, 339318490.38
(sw_c, sw_rl) in bit/s: None, 122162433.43
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 351747160.04
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 128170612.87
(sw_rr, sw_c) in bit/s: None, 173186674.22
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Find Path(s) ----------------------
Flow(id=6001, source=zc_rr, sink=['zc_fr', 'zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 500. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.662ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.662ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.662ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 146095513.61
(sw_fl, zc_fl) in bit/s: None, 357015761.43
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 330720409.11
(sw_c, sw_fr) in bit/s: None, 339318490.38
(sw_c, sw_rl) in bit/s: None, 122162433.43
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 351747160.04
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 128170612.87
(sw_rr, sw_c) in bit/s: None, 173186674.22
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Find Path(s) ----------------------
Flow(id=3032, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 501. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 357015761.43
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 330720409.11
(sw_c, sw_fr) in bit/s: None, 341786555.09
(sw_c, sw_rl) in bit/s: None, 122162433.43
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 355649346.76
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 128170612.87
(sw_rr, sw_c) in bit/s: None, 173186674.22
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Remove Resources ----------------------
----- 502. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 357015761.43
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 330720409.11
(sw_c, sw_fr) in bit/s: None, 341786555.09
(sw_c, sw_rl) in bit/s: None, 122162433.43
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 355649346.76
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 128170612.87
(sw_rr, sw_c) in bit/s: None, 173186674.22
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Find Path(s) ----------------------
Flow(id=3032, source=zc_fl, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 503. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 357015761.43
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 330720409.11
(sw_c, sw_fr) in bit/s: None, 341786555.09
(sw_c, sw_rl) in bit/s: None, 125812284.77
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 355649346.76
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 132251575.45
(sw_rr, sw_c) in bit/s: None, 173186674.22
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Remove Resources ----------------------
----- 504. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 357015761.43
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 330720409.11
(sw_c, sw_fr) in bit/s: None, 341786555.09
(sw_c, sw_rl) in bit/s: None, 125812284.77
(sw_c, sw_rr) in bit/s: 1816838947.80, 287333297.89
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 355649346.76
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 132251575.45
(sw_rr, sw_c) in bit/s: None, 173186674.22
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 304675090.92
------------------- Find Path(s) ----------------------
Flow(id=3032, source=zc_fl, sink=['zc_fr', 'zc_rl', 'zc_rr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 505. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.647ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 357015761.43
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 330720409.11
(sw_c, sw_fr) in bit/s: None, 341786555.09
(sw_c, sw_rl) in bit/s: None, 125812284.77
(sw_c, sw_rr) in bit/s: 1816838947.80, 291164293.26
(sw_fr, sw_c) in bit/s: 397580751.34, 125345183.75
(sw_fr, zc_fr) in bit/s: None, 355649346.76
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 132251575.45
(sw_rr, sw_c) in bit/s: None, 173186674.22
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 308614591.81
------------------- Find Path(s) ----------------------
Flow(id=4053, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 506. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 360842138.97
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 332784615.68
(sw_c, sw_fr) in bit/s: None, 341786555.09
(sw_c, sw_rl) in bit/s: None, 125812284.77
(sw_c, sw_rr) in bit/s: 1816838947.80, 291164293.26
(sw_fr, sw_c) in bit/s: 397580751.34, 128011802.17
(sw_fr, zc_fr) in bit/s: None, 355649346.76
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 132251575.45
(sw_rr, sw_c) in bit/s: None, 173186674.22
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 308614591.81
------------------- Remove Resources ----------------------
----- 507. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 360842138.97
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 332784615.68
(sw_c, sw_fr) in bit/s: None, 341786555.09
(sw_c, sw_rl) in bit/s: None, 125812284.77
(sw_c, sw_rr) in bit/s: 1816838947.80, 291164293.26
(sw_fr, sw_c) in bit/s: 397580751.34, 128011802.17
(sw_fr, zc_fr) in bit/s: None, 355649346.76
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 132251575.45
(sw_rr, sw_c) in bit/s: None, 173186674.22
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 308614591.81
------------------- Find Path(s) ----------------------
Flow(id=4053, source=zc_fr, sink=['zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 508. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 360842138.97
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 332784615.68
(sw_c, sw_fr) in bit/s: None, 341786555.09
(sw_c, sw_rl) in bit/s: None, 125812284.77
(sw_c, sw_rr) in bit/s: 1816838947.80, 294884561.87
(sw_fr, sw_c) in bit/s: 397580751.34, 128011802.17
(sw_fr, zc_fr) in bit/s: None, 355649346.76
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 132251575.45
(sw_rr, sw_c) in bit/s: None, 173186674.22
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 312551141.14
------------------- Find Path(s) ----------------------
Flow(id=6008, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 509. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.662ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 364665341.62
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 338196962.22
(sw_c, sw_fr) in bit/s: None, 341786555.09
(sw_c, sw_rl) in bit/s: None, 125812284.77
(sw_c, sw_rr) in bit/s: 1816838947.80, 294884561.87
(sw_fr, sw_c) in bit/s: 397580751.34, 128011802.17
(sw_fr, zc_fr) in bit/s: None, 355649346.76
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 132251575.45
(sw_rr, sw_c) in bit/s: None, 175839603.13
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 312551141.14
------------------- Find Path(s) ----------------------
Flow(id=6011, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 510. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.663ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 364665341.62
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 338196962.22
(sw_c, sw_fr) in bit/s: None, 346986975.23
(sw_c, sw_rl) in bit/s: None, 125812284.77
(sw_c, sw_rr) in bit/s: 1816838947.80, 294884561.87
(sw_fr, sw_c) in bit/s: 397580751.34, 128011802.17
(sw_fr, zc_fr) in bit/s: None, 359549584.05
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 132251575.45
(sw_rr, sw_c) in bit/s: None, 178480787.83
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 312551141.14
------------------- Remove Resources ----------------------
----- 511. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 364665341.62
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 338196962.22
(sw_c, sw_fr) in bit/s: None, 346986975.23
(sw_c, sw_rl) in bit/s: None, 125812284.77
(sw_c, sw_rr) in bit/s: 1816838947.80, 294884561.87
(sw_fr, sw_c) in bit/s: 397580751.34, 128011802.17
(sw_fr, zc_fr) in bit/s: None, 359549584.05
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 132251575.45
(sw_rr, sw_c) in bit/s: None, 178480787.83
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 312551141.14
------------------- Find Path(s) ----------------------
Flow(id=6011, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 512. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.663ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.663ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 368486657.64
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 341997264.77
(sw_c, sw_fr) in bit/s: None, 346986975.23
(sw_c, sw_rl) in bit/s: None, 125812284.77
(sw_c, sw_rr) in bit/s: 1816838947.80, 294884561.87
(sw_fr, sw_c) in bit/s: 397580751.34, 128011802.17
(sw_fr, zc_fr) in bit/s: None, 359549584.05
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 132251575.45
(sw_rr, sw_c) in bit/s: None, 178480787.83
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 312551141.14
------------------- Find Path(s) ----------------------
Flow(id=6055, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 513. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 368486657.64
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 341997264.77
(sw_c, sw_fr) in bit/s: None, 350885663.56
(sw_c, sw_rl) in bit/s: None, 125812284.77
(sw_c, sw_rr) in bit/s: 1816838947.80, 294884561.87
(sw_fr, sw_c) in bit/s: 397580751.34, 128011802.17
(sw_fr, zc_fr) in bit/s: None, 363445819.69
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 132251575.45
(sw_rr, sw_c) in bit/s: None, 181101596.63
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 312551141.14
------------------- Remove Resources ----------------------
----- 514. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 368486657.64
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 341997264.77
(sw_c, sw_fr) in bit/s: None, 350885663.56
(sw_c, sw_rl) in bit/s: None, 125812284.77
(sw_c, sw_rr) in bit/s: 1816838947.80, 294884561.87
(sw_fr, sw_c) in bit/s: 397580751.34, 128011802.17
(sw_fr, zc_fr) in bit/s: None, 363445819.69
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 132251575.45
(sw_rr, sw_c) in bit/s: None, 181101596.63
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 312551141.14
------------------- Find Path(s) ----------------------
Flow(id=6055, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 515. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 372304123.05
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 345797214.44
(sw_c, sw_fr) in bit/s: None, 350885663.56
(sw_c, sw_rl) in bit/s: None, 125812284.77
(sw_c, sw_rr) in bit/s: 1816838947.80, 294884561.87
(sw_fr, sw_c) in bit/s: 397580751.34, 128011802.17
(sw_fr, zc_fr) in bit/s: None, 363445819.69
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 132251575.45
(sw_rr, sw_c) in bit/s: None, 181101596.63
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 312551141.14
------------------- Find Path(s) ----------------------
Flow(id=6043, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 516. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 372304123.05
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 345797214.44
(sw_c, sw_fr) in bit/s: None, 354784277.34
(sw_c, sw_rl) in bit/s: None, 125812284.77
(sw_c, sw_rr) in bit/s: 1816838947.80, 294884561.87
(sw_fr, sw_c) in bit/s: 397580751.34, 128011802.17
(sw_fr, zc_fr) in bit/s: None, 367338787.73
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 132251575.45
(sw_rr, sw_c) in bit/s: None, 183705300.40
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 312551141.14
------------------- Remove Resources ----------------------
----- 517. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 372304123.05
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 345797214.44
(sw_c, sw_fr) in bit/s: None, 354784277.34
(sw_c, sw_rl) in bit/s: None, 125812284.77
(sw_c, sw_rr) in bit/s: 1816838947.80, 294884561.87
(sw_fr, sw_c) in bit/s: 397580751.34, 128011802.17
(sw_fr, zc_fr) in bit/s: None, 367338787.73
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 132251575.45
(sw_rr, sw_c) in bit/s: None, 183705300.40
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 312551141.14
------------------- Find Path(s) ----------------------
Flow(id=6043, source=zc_rr, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 518. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 372304123.05
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 345797214.44
(sw_c, sw_fr) in bit/s: None, 354784277.34
(sw_c, sw_rl) in bit/s: None, 129993770.37
(sw_c, sw_rr) in bit/s: 1816838947.80, 294884561.87
(sw_fr, sw_c) in bit/s: 397580751.34, 128011802.17
(sw_fr, zc_fr) in bit/s: None, 367338787.73
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 136329242.79
(sw_rr, sw_c) in bit/s: None, 183705300.40
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 312551141.14
------------------- Remove Resources ----------------------
----- 519. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 372304123.05
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 345797214.44
(sw_c, sw_fr) in bit/s: None, 354784277.34
(sw_c, sw_rl) in bit/s: None, 129993770.37
(sw_c, sw_rr) in bit/s: 1816838947.80, 294884561.87
(sw_fr, sw_c) in bit/s: 397580751.34, 128011802.17
(sw_fr, zc_fr) in bit/s: None, 367338787.73
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 136329242.79
(sw_rr, sw_c) in bit/s: None, 183705300.40
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 312551141.14
------------------- Find Path(s) ----------------------
Flow(id=6043, source=zc_rr, sink=['zc_fr', 'zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 520. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 376118440.07
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 349597093.53
(sw_c, sw_fr) in bit/s: None, 354784277.34
(sw_c, sw_rl) in bit/s: None, 129993770.37
(sw_c, sw_rr) in bit/s: 1816838947.80, 294884561.87
(sw_fr, sw_c) in bit/s: 397580751.34, 128011802.17
(sw_fr, zc_fr) in bit/s: None, 367338787.73
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 136329242.79
(sw_rr, sw_c) in bit/s: None, 183705300.40
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 312551141.14
------------------- Find Path(s) ----------------------
Flow(id=4058, source=zc_fr, sink=['zc_rl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 521. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.654ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 376118440.07
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 349597093.53
(sw_c, sw_fr) in bit/s: None, 354784277.34
(sw_c, sw_rl) in bit/s: None, 133624185.91
(sw_c, sw_rr) in bit/s: 1816838947.80, 294884561.87
(sw_fr, sw_c) in bit/s: 397580751.34, 130662437.50
(sw_fr, zc_fr) in bit/s: None, 367338787.73
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 140403704.22
(sw_rr, sw_c) in bit/s: None, 183705300.40
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 312551141.14
------------------- Remove Resources ----------------------
----- 522. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 376118440.07
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 349597093.53
(sw_c, sw_fr) in bit/s: None, 354784277.34
(sw_c, sw_rl) in bit/s: None, 133624185.91
(sw_c, sw_rr) in bit/s: 1816838947.80, 294884561.87
(sw_fr, sw_c) in bit/s: 397580751.34, 130662437.50
(sw_fr, zc_fr) in bit/s: None, 367338787.73
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 140403704.22
(sw_rr, sw_c) in bit/s: None, 183705300.40
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 312551141.14
------------------- Find Path(s) ----------------------
Flow(id=4058, source=zc_fr, sink=['zc_rl', 'zc_rr'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 523. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_rr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.654ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.654ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 376118440.07
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 349597093.53
(sw_c, sw_fr) in bit/s: None, 354784277.34
(sw_c, sw_rl) in bit/s: None, 133624185.91
(sw_c, sw_rr) in bit/s: 1816838947.80, 298714220.15
(sw_fr, sw_c) in bit/s: 397580751.34, 130662437.50
(sw_fr, zc_fr) in bit/s: None, 367338787.73
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 140403704.22
(sw_rr, sw_c) in bit/s: None, 183705300.40
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 316484616.32
------------------- Remove Resources ----------------------
----- 524. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_rr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 376118440.07
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 349597093.53
(sw_c, sw_fr) in bit/s: None, 354784277.34
(sw_c, sw_rl) in bit/s: None, 133624185.91
(sw_c, sw_rr) in bit/s: 1816838947.80, 298714220.15
(sw_fr, sw_c) in bit/s: 397580751.34, 130662437.50
(sw_fr, zc_fr) in bit/s: None, 367338787.73
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 140403704.22
(sw_rr, sw_c) in bit/s: None, 183705300.40
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 316484616.32
------------------- Find Path(s) ----------------------
Flow(id=4058, source=zc_fr, sink=['zc_rl', 'zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 525. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_rr', 'zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.654ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.654ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.654ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 379930031.83
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 351171995.44
(sw_c, sw_fr) in bit/s: None, 354784277.34
(sw_c, sw_rl) in bit/s: None, 133624185.91
(sw_c, sw_rr) in bit/s: 1816838947.80, 298714220.15
(sw_fr, sw_c) in bit/s: 397580751.34, 130662437.50
(sw_fr, zc_fr) in bit/s: None, 367338787.73
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 140403704.22
(sw_rr, sw_c) in bit/s: None, 183705300.40
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 316484616.32
------------------- Find Path(s) ----------------------
Flow(id=6073, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 526. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.665ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 383738607.27
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 357063931.55
(sw_c, sw_fr) in bit/s: None, 354784277.34
(sw_c, sw_rl) in bit/s: None, 133624185.91
(sw_c, sw_rr) in bit/s: 1816838947.80, 298714220.15
(sw_fr, sw_c) in bit/s: 397580751.34, 130662437.50
(sw_fr, zc_fr) in bit/s: None, 367338787.73
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 140403704.22
(sw_rr, sw_c) in bit/s: None, 186293670.89
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 316484616.32
------------------- Find Path(s) ----------------------
Flow(id=4026, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 527. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.655ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 383738607.27
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 357063931.55
(sw_c, sw_fr) in bit/s: None, 354784277.34
(sw_c, sw_rl) in bit/s: None, 133624185.91
(sw_c, sw_rr) in bit/s: 1816838947.80, 302543773.15
(sw_fr, sw_c) in bit/s: 397580751.34, 133296158.63
(sw_fr, zc_fr) in bit/s: None, 367338787.73
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 140403704.22
(sw_rr, sw_c) in bit/s: None, 186293670.89
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 320414732.57
------------------- Find Path(s) ----------------------
Flow(id=4056, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.05, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 528. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.655ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 387544461.62
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 358591349.18
(sw_c, sw_fr) in bit/s: None, 354784277.34
(sw_c, sw_rl) in bit/s: None, 133624185.91
(sw_c, sw_rr) in bit/s: 1816838947.80, 302543773.15
(sw_fr, sw_c) in bit/s: 397580751.34, 135915475.13
(sw_fr, zc_fr) in bit/s: None, 367338787.73
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 140403704.22
(sw_rr, sw_c) in bit/s: None, 186293670.89
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 320414732.57
------------------- Find Path(s) ----------------------
Flow(id=4052, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 529. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.656ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 391346917.40
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 362365844.61
(sw_c, sw_fr) in bit/s: None, 354784277.34
(sw_c, sw_rl) in bit/s: None, 133624185.91
(sw_c, sw_rr) in bit/s: 1816838947.80, 302543773.15
(sw_fr, sw_c) in bit/s: 397580751.34, 138517552.21
(sw_fr, zc_fr) in bit/s: None, 367338787.73
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 140403704.22
(sw_rr, sw_c) in bit/s: None, 186293670.89
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 320414732.57
------------------- Find Path(s) ----------------------
Flow(id=6059, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 530. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 391346917.40
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 362365844.61
(sw_c, sw_fr) in bit/s: None, 358682919.08
(sw_c, sw_rl) in bit/s: None, 133624185.91
(sw_c, sw_rr) in bit/s: 1816838947.80, 302543773.15
(sw_fr, sw_c) in bit/s: 397580751.34, 138517552.21
(sw_fr, zc_fr) in bit/s: None, 371228749.96
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 140403704.22
(sw_rr, sw_c) in bit/s: None, 188865531.59
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 320414732.57
------------------- Remove Resources ----------------------
----- 531. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 391346917.40
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 362365844.61
(sw_c, sw_fr) in bit/s: None, 358682919.08
(sw_c, sw_rl) in bit/s: None, 133624185.91
(sw_c, sw_rr) in bit/s: 1816838947.80, 302543773.15
(sw_fr, sw_c) in bit/s: 397580751.34, 138517552.21
(sw_fr, zc_fr) in bit/s: None, 371228749.96
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 140403704.22
(sw_rr, sw_c) in bit/s: None, 188865531.59
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 320414732.57
------------------- Find Path(s) ----------------------
Flow(id=6059, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 532. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 395146515.61
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 368185136.67
(sw_c, sw_fr) in bit/s: None, 358682919.08
(sw_c, sw_rl) in bit/s: None, 133624185.91
(sw_c, sw_rr) in bit/s: 1816838947.80, 302543773.15
(sw_fr, sw_c) in bit/s: 397580751.34, 138517552.21
(sw_fr, zc_fr) in bit/s: None, 371228749.96
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 140403704.22
(sw_rr, sw_c) in bit/s: None, 188865531.59
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 320414732.57
------------------- Find Path(s) ----------------------
Flow(id=4018, source=zc_fr, sink=['zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 533. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.657ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 395146515.61
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 368185136.67
(sw_c, sw_fr) in bit/s: None, 358682919.08
(sw_c, sw_rl) in bit/s: None, 137554290.06
(sw_c, sw_rr) in bit/s: 1816838947.80, 302543773.15
(sw_fr, sw_c) in bit/s: 397580751.34, 141104089.89
(sw_fr, zc_fr) in bit/s: None, 371228749.96
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 144474779.83
(sw_rr, sw_c) in bit/s: None, 188865531.59
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 320414732.57
------------------- Remove Resources ----------------------
----- 534. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 395146515.61
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 368185136.67
(sw_c, sw_fr) in bit/s: None, 358682919.08
(sw_c, sw_rl) in bit/s: None, 137554290.06
(sw_c, sw_rr) in bit/s: 1816838947.80, 302543773.15
(sw_fr, sw_c) in bit/s: 397580751.34, 141104089.89
(sw_fr, zc_fr) in bit/s: None, 371228749.96
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 144474779.83
(sw_rr, sw_c) in bit/s: None, 188865531.59
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 320414732.57
------------------- Find Path(s) ----------------------
Flow(id=4018, source=zc_fr, sink=['zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 535. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.657ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.657ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 398943093.06
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 369777997.48
(sw_c, sw_fr) in bit/s: None, 358682919.08
(sw_c, sw_rl) in bit/s: None, 137554290.06
(sw_c, sw_rr) in bit/s: 1816838947.80, 302543773.15
(sw_fr, sw_c) in bit/s: 397580751.34, 141104089.89
(sw_fr, zc_fr) in bit/s: None, 371228749.96
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 144474779.83
(sw_rr, sw_c) in bit/s: None, 188865531.59
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 320414732.57
------------------- Remove Resources ----------------------
----- 536. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 398943093.06
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 369777997.48
(sw_c, sw_fr) in bit/s: None, 358682919.08
(sw_c, sw_rl) in bit/s: None, 137554290.06
(sw_c, sw_rr) in bit/s: 1816838947.80, 302543773.15
(sw_fr, sw_c) in bit/s: 397580751.34, 141104089.89
(sw_fr, zc_fr) in bit/s: None, 371228749.96
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 144474779.83
(sw_rr, sw_c) in bit/s: None, 188865531.59
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 320414732.57
------------------- Find Path(s) ----------------------
Flow(id=4018, source=zc_fr, sink=['zc_rl', 'zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 537. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.657ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.657ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.657ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 398943093.06
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 369777997.48
(sw_c, sw_fr) in bit/s: None, 358682919.08
(sw_c, sw_rl) in bit/s: None, 137554290.06
(sw_c, sw_rr) in bit/s: 1816838947.80, 306373335.31
(sw_fr, sw_c) in bit/s: 397580751.34, 141104089.89
(sw_fr, zc_fr) in bit/s: None, 371228749.96
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 144474779.83
(sw_rr, sw_c) in bit/s: None, 188865531.59
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 324341747.31
------------------- Find Path(s) ----------------------
Flow(id=4059, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 538. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  2000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.657ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 402736687.71
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 373551086.30
(sw_c, sw_fr) in bit/s: None, 358682919.08
(sw_c, sw_rl) in bit/s: None, 137554290.06
(sw_c, sw_rr) in bit/s: 1816838947.80, 306373335.31
(sw_fr, sw_c) in bit/s: 397580751.34, 143675024.98
(sw_fr, zc_fr) in bit/s: None, 371228749.96
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 144474779.83
(sw_rr, sw_c) in bit/s: None, 188865531.59
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 324341747.31
------------------- Find Path(s) ----------------------
Flow(id=6007, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 539. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 402736687.71
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 373551086.30
(sw_c, sw_fr) in bit/s: None, 362581607.41
(sw_c, sw_rl) in bit/s: None, 137554290.06
(sw_c, sw_rr) in bit/s: 1816838947.80, 306373335.31
(sw_fr, sw_c) in bit/s: 397580751.34, 143675024.98
(sw_fr, zc_fr) in bit/s: None, 375115760.79
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 144474779.83
(sw_rr, sw_c) in bit/s: None, 191422065.81
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 324341747.31
------------------- Remove Resources ----------------------
----- 540. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 402736687.71
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 373551086.30
(sw_c, sw_fr) in bit/s: None, 362581607.41
(sw_c, sw_rl) in bit/s: None, 137554290.06
(sw_c, sw_rr) in bit/s: 1816838947.80, 306373335.31
(sw_fr, sw_c) in bit/s: 397580751.34, 143675024.98
(sw_fr, zc_fr) in bit/s: None, 375115760.79
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 144474779.83
(sw_rr, sw_c) in bit/s: None, 191422065.81
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 324341747.31
------------------- Find Path(s) ----------------------
Flow(id=6007, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 541. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 406527573.60
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 379289652.33
(sw_c, sw_fr) in bit/s: None, 362581607.41
(sw_c, sw_rl) in bit/s: None, 137554290.06
(sw_c, sw_rr) in bit/s: 1816838947.80, 306373335.31
(sw_fr, sw_c) in bit/s: 397580751.34, 143675024.98
(sw_fr, zc_fr) in bit/s: None, 375115760.79
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 144474779.83
(sw_rr, sw_c) in bit/s: None, 191422065.81
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 324341747.31
------------------- Remove Resources ----------------------
----- 542. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 406527573.60
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 379289652.33
(sw_c, sw_fr) in bit/s: None, 362581607.41
(sw_c, sw_rl) in bit/s: None, 137554290.06
(sw_c, sw_rr) in bit/s: 1816838947.80, 306373335.31
(sw_fr, sw_c) in bit/s: 397580751.34, 143675024.98
(sw_fr, zc_fr) in bit/s: None, 375115760.79
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 144474779.83
(sw_rr, sw_c) in bit/s: None, 191422065.81
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 324341747.31
------------------- Find Path(s) ----------------------
Flow(id=6007, source=zc_rr, sink=['zc_fr', 'zc_fl', 'zc_rl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 543. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'zc_rl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 406527573.60
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 379289652.33
(sw_c, sw_fr) in bit/s: None, 362581607.41
(sw_c, sw_rl) in bit/s: None, 141811393.58
(sw_c, sw_rr) in bit/s: 1816838947.80, 306373335.31
(sw_fr, sw_c) in bit/s: 397580751.34, 143675024.98
(sw_fr, zc_fr) in bit/s: None, 375115760.79
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 148542639.65
(sw_rr, sw_c) in bit/s: None, 191422065.81
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 324341747.31
------------------- Find Path(s) ----------------------
Flow(id=6029, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 544. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.667ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 406527573.60
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 379289652.33
(sw_c, sw_fr) in bit/s: None, 366480295.74
(sw_c, sw_rl) in bit/s: None, 141811393.58
(sw_c, sw_rr) in bit/s: 1816838947.80, 306373335.31
(sw_fr, sw_c) in bit/s: 397580751.34, 143675024.98
(sw_fr, zc_fr) in bit/s: None, 378999705.04
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 148542639.65
(sw_rr, sw_c) in bit/s: None, 193962904.51
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 324341747.31
------------------- Find Path(s) ----------------------
Flow(id=6037, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 545. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.668ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 410315524.09
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 383082531.02
(sw_c, sw_fr) in bit/s: None, 366480295.74
(sw_c, sw_rl) in bit/s: None, 141811393.58
(sw_c, sw_rr) in bit/s: 1816838947.80, 306373335.31
(sw_fr, sw_c) in bit/s: 397580751.34, 143675024.98
(sw_fr, zc_fr) in bit/s: None, 378999705.04
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 148542639.65
(sw_rr, sw_c) in bit/s: None, 196488191.77
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 324341747.31
------------------- Remove Resources ----------------------
----- 546. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 410315524.09
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 383082531.02
(sw_c, sw_fr) in bit/s: None, 366480295.74
(sw_c, sw_rl) in bit/s: None, 141811393.58
(sw_c, sw_rr) in bit/s: 1816838947.80, 306373335.31
(sw_fr, sw_c) in bit/s: 397580751.34, 143675024.98
(sw_fr, zc_fr) in bit/s: None, 378999705.04
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 148542639.65
(sw_rr, sw_c) in bit/s: None, 196488191.77
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 324341747.31
------------------- Find Path(s) ----------------------
Flow(id=6037, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 547. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.668ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.668ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 410315524.09
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 383082531.02
(sw_c, sw_fr) in bit/s: None, 370378984.08
(sw_c, sw_rl) in bit/s: None, 141811393.58
(sw_c, sw_rr) in bit/s: 1816838947.80, 306373335.31
(sw_fr, sw_c) in bit/s: 397580751.34, 143675024.98
(sw_fr, zc_fr) in bit/s: None, 382880586.33
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 148542639.65
(sw_rr, sw_c) in bit/s: None, 196488191.77
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 324341747.31
------------------- Find Path(s) ----------------------
Flow(id=4031, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 548. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.658ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 414102809.12
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 384587337.33
(sw_c, sw_fr) in bit/s: None, 370378984.08
(sw_c, sw_rl) in bit/s: None, 141811393.58
(sw_c, sw_rr) in bit/s: 1816838947.80, 306373335.31
(sw_fr, sw_c) in bit/s: 397580751.34, 146238992.65
(sw_fr, zc_fr) in bit/s: None, 382880586.33
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 148542639.65
(sw_rr, sw_c) in bit/s: None, 196488191.77
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 324341747.31
------------------- Remove Resources ----------------------
----- 549. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 414102809.12
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 384587337.33
(sw_c, sw_fr) in bit/s: None, 370378984.08
(sw_c, sw_rl) in bit/s: None, 141811393.58
(sw_c, sw_rr) in bit/s: 1816838947.80, 306373335.31
(sw_fr, sw_c) in bit/s: 397580751.34, 146238992.65
(sw_fr, zc_fr) in bit/s: None, 382880586.33
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 148542639.65
(sw_rr, sw_c) in bit/s: None, 196488191.77
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 324341747.31
------------------- Find Path(s) ----------------------
Flow(id=4031, source=zc_fr, sink=['zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 550. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.658ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.658ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 414102809.12
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 384587337.33
(sw_c, sw_fr) in bit/s: None, 370378984.08
(sw_c, sw_rl) in bit/s: None, 141811393.58
(sw_c, sw_rr) in bit/s: 1816838947.80, 310203794.61
(sw_fr, sw_c) in bit/s: 397580751.34, 146238992.65
(sw_fr, zc_fr) in bit/s: None, 382880586.33
(sw_rl, sw_c) in bit/s: 397580751.34, 13783827.88
(sw_rl, zc_rl) in bit/s: None, 148542639.65
(sw_rr, sw_c) in bit/s: None, 196488191.77
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 328267726.40
------------------- Find Path(s) ----------------------
Flow(id=5001, source=zc_rl, sink=['zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 551. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.628ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 149064708.73
(sw_fl, zc_fl) in bit/s: None, 414102809.12
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 384587337.33
(sw_c, sw_fr) in bit/s: None, 370378984.08
(sw_c, sw_rl) in bit/s: None, 141811393.58
(sw_c, sw_rr) in bit/s: 1816838947.80, 313562503.06
(sw_fr, sw_c) in bit/s: 397580751.34, 146238992.65
(sw_fr, zc_fr) in bit/s: None, 382880586.33
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 148542639.65
(sw_rr, sw_c) in bit/s: None, 196488191.77
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 332188705.12
------------------- Find Path(s) ----------------------
Flow(id=3039, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 552. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.648ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 152014321.00
(sw_fl, zc_fl) in bit/s: None, 414102809.12
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 384587337.33
(sw_c, sw_fr) in bit/s: None, 371870657.30
(sw_c, sw_rl) in bit/s: None, 141811393.58
(sw_c, sw_rr) in bit/s: 1816838947.80, 313562503.06
(sw_fr, sw_c) in bit/s: 397580751.34, 146238992.65
(sw_fr, zc_fr) in bit/s: None, 386758408.29
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 148542639.65
(sw_rr, sw_c) in bit/s: None, 196488191.77
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 332188705.12
------------------- Remove Resources ----------------------
----- 553. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 152014321.00
(sw_fl, zc_fl) in bit/s: None, 414102809.12
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 384587337.33
(sw_c, sw_fr) in bit/s: None, 371870657.30
(sw_c, sw_rl) in bit/s: None, 141811393.58
(sw_c, sw_rr) in bit/s: 1816838947.80, 313562503.06
(sw_fr, sw_c) in bit/s: 397580751.34, 146238992.65
(sw_fr, zc_fr) in bit/s: None, 386758408.29
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 148542639.65
(sw_rr, sw_c) in bit/s: None, 196488191.77
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 332188705.12
------------------- Find Path(s) ----------------------
Flow(id=3039, source=zc_fl, sink=['zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 554. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.648ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.648ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 152014321.00
(sw_fl, zc_fl) in bit/s: None, 414102809.12
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 384587337.33
(sw_c, sw_fr) in bit/s: None, 371870657.30
(sw_c, sw_rl) in bit/s: None, 141811393.58
(sw_c, sw_rr) in bit/s: 1816838947.80, 317386390.84
(sw_fr, sw_c) in bit/s: 397580751.34, 146238992.65
(sw_fr, zc_fr) in bit/s: None, 386758408.29
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 148542639.65
(sw_rr, sw_c) in bit/s: None, 196488191.77
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 336106576.98
------------------- Find Path(s) ----------------------
Flow(id=4037, source=zc_fr, sink=['zc_rl'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 555. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.659ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 152014321.00
(sw_fl, zc_fl) in bit/s: None, 414102809.12
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 384587337.33
(sw_c, sw_fr) in bit/s: None, 371870657.30
(sw_c, sw_rl) in bit/s: None, 145358664.49
(sw_c, sw_rr) in bit/s: 1816838947.80, 317386390.84
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 386758408.29
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 152607129.10
(sw_rr, sw_c) in bit/s: None, 196488191.77
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 336106576.98
------------------- Remove Resources ----------------------
----- 556. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 152014321.00
(sw_fl, zc_fl) in bit/s: None, 414102809.12
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 384587337.33
(sw_c, sw_fr) in bit/s: None, 371870657.30
(sw_c, sw_rl) in bit/s: None, 145358664.49
(sw_c, sw_rr) in bit/s: 1816838947.80, 317386390.84
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 386758408.29
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 152607129.10
(sw_rr, sw_c) in bit/s: None, 196488191.77
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 336106576.98
------------------- Find Path(s) ----------------------
Flow(id=4037, source=zc_fr, sink=['zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 557. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.659ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.659ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 152014321.00
(sw_fl, zc_fl) in bit/s: None, 417884691.85
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 388357636.52
(sw_c, sw_fr) in bit/s: None, 371870657.30
(sw_c, sw_rl) in bit/s: None, 145358664.49
(sw_c, sw_rr) in bit/s: 1816838947.80, 317386390.84
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 386758408.29
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 152607129.10
(sw_rr, sw_c) in bit/s: None, 196488191.77
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 336106576.98
------------------- Remove Resources ----------------------
----- 558. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 152014321.00
(sw_fl, zc_fl) in bit/s: None, 417884691.85
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 388357636.52
(sw_c, sw_fr) in bit/s: None, 371870657.30
(sw_c, sw_rl) in bit/s: None, 145358664.49
(sw_c, sw_rr) in bit/s: 1816838947.80, 317386390.84
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 386758408.29
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 152607129.10
(sw_rr, sw_c) in bit/s: None, 196488191.77
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 336106576.98
------------------- Find Path(s) ----------------------
Flow(id=4037, source=zc_fr, sink=['zc_rl', 'zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 559. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.659ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.659ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.659ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 152014321.00
(sw_fl, zc_fl) in bit/s: None, 417884691.85
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 388357636.52
(sw_c, sw_fr) in bit/s: None, 371870657.30
(sw_c, sw_rl) in bit/s: None, 145358664.49
(sw_c, sw_rr) in bit/s: 1816838947.80, 321571871.51
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 386758408.29
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 152607129.10
(sw_rr, sw_c) in bit/s: None, 196488191.77
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 340021147.60
------------------- Find Path(s) ----------------------
Flow(id=6054, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 560. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.669ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 152014321.00
(sw_fl, zc_fl) in bit/s: None, 417884691.85
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 388357636.52
(sw_c, sw_fr) in bit/s: None, 378032355.28
(sw_c, sw_rl) in bit/s: None, 145358664.49
(sw_c, sw_rr) in bit/s: 1816838947.80, 321571871.51
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 390632972.56
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 152607129.10
(sw_rr, sw_c) in bit/s: None, 198997202.09
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 340021147.60
------------------- Remove Resources ----------------------
----- 561. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 152014321.00
(sw_fl, zc_fl) in bit/s: None, 417884691.85
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 388357636.52
(sw_c, sw_fr) in bit/s: None, 378032355.28
(sw_c, sw_rl) in bit/s: None, 145358664.49
(sw_c, sw_rr) in bit/s: 1816838947.80, 321571871.51
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 390632972.56
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 152607129.10
(sw_rr, sw_c) in bit/s: None, 198997202.09
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 340021147.60
------------------- Find Path(s) ----------------------
Flow(id=6054, source=zc_rr, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 562. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.669ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.669ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 152014321.00
(sw_fl, zc_fl) in bit/s: None, 417884691.85
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 388357636.52
(sw_c, sw_fr) in bit/s: None, 378032355.28
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 321571871.51
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 390632972.56
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 198997202.09
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 340021147.60
------------------- Remove Resources ----------------------
----- 563. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 152014321.00
(sw_fl, zc_fl) in bit/s: None, 417884691.85
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 388357636.52
(sw_c, sw_fr) in bit/s: None, 378032355.28
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 321571871.51
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 390632972.56
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 198997202.09
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 340021147.60
------------------- Find Path(s) ----------------------
Flow(id=6054, source=zc_rr, sink=['zc_fr', 'zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 564. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.668ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.669ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.669ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 152014321.00
(sw_fl, zc_fl) in bit/s: None, 421663670.69
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 394168611.04
(sw_c, sw_fr) in bit/s: None, 378032355.28
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 321571871.51
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 390632972.56
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 198997202.09
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 340021147.60
------------------- Find Path(s) ----------------------
Flow(id=3025, source=zc_fl, sink=['zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 565. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 421663670.69
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 394168611.04
(sw_c, sw_fr) in bit/s: None, 378032355.28
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 390632972.56
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 198997202.09
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Find Path(s) ----------------------
Flow(id=6063, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 566. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.669ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 421663670.69
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 394168611.04
(sw_c, sw_fr) in bit/s: None, 381929510.84
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 394504557.26
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 201491255.69
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Remove Resources ----------------------
----- 567. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 421663670.69
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 394168611.04
(sw_c, sw_fr) in bit/s: None, 381929510.84
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 394504557.26
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 201491255.69
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Find Path(s) ----------------------
Flow(id=6063, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 568. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.669ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.669ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 425439801.57
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 397958615.24
(sw_c, sw_fr) in bit/s: None, 381929510.84
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 394504557.26
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 201491255.69
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Find Path(s) ----------------------
Flow(id=6002, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 569. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.670ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 425439801.57
(sw_fl, infotainment) in bit/s: None, 117030423.43
(sw_c, sw_fl) in bit/s: None, 397958615.24
(sw_c, sw_fr) in bit/s: None, 385826738.28
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 398373284.06
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 203970998.72
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Find Path(s) ----------------------
Flow(id=6040, source=zc_rr, sink=['infotainment'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 570. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.670ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 425439801.57
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 401748672.56
(sw_c, sw_fr) in bit/s: None, 385826738.28
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 398373284.06
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 206435475.72
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Remove Resources ----------------------
----- 571. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 425439801.57
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 401748672.56
(sw_c, sw_fr) in bit/s: None, 385826738.28
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 398373284.06
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 206435475.72
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Find Path(s) ----------------------
Flow(id=6040, source=zc_rr, sink=['infotainment', 'zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 572. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.670ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.671ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 425439801.57
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 401748672.56
(sw_c, sw_fr) in bit/s: None, 389723941.76
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 148779544.12
(sw_fr, zc_fr) in bit/s: None, 402238902.22
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 206435475.72
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Find Path(s) ----------------------
Flow(id=4010, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 573. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.660ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 429213142.33
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 402992082.25
(sw_c, sw_fr) in bit/s: None, 389723941.76
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 151305803.91
(sw_fr, zc_fr) in bit/s: None, 402238902.22
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 206435475.72
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Find Path(s) ----------------------
Flow(id=6022, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 574. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.671ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 432983436.12
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 409176627.99
(sw_c, sw_fr) in bit/s: None, 389723941.76
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 151305803.91
(sw_fr, zc_fr) in bit/s: None, 402238902.22
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 208884533.06
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Remove Resources ----------------------
----- 575. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 432983436.12
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 409176627.99
(sw_c, sw_fr) in bit/s: None, 389723941.76
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 151305803.91
(sw_fr, zc_fr) in bit/s: None, 402238902.22
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 208884533.06
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Find Path(s) ----------------------
Flow(id=6022, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 576. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.671ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.671ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 432983436.12
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 409176627.99
(sw_c, sw_fr) in bit/s: None, 393621097.32
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 151305803.91
(sw_fr, zc_fr) in bit/s: None, 406101347.93
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 208884533.06
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Find Path(s) ----------------------
Flow(id=4002, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 577. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.660ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 436751015.50
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 410372950.48
(sw_c, sw_fr) in bit/s: None, 393621097.32
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 406101347.93
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 208884533.06
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Remove Resources ----------------------
----- 578. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 436751015.50
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 410372950.48
(sw_c, sw_fr) in bit/s: None, 393621097.32
(sw_c, sw_rl) in bit/s: None, 149689781.07
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 406101347.93
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 156668344.65
(sw_rr, sw_c) in bit/s: None, 208884533.06
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Find Path(s) ----------------------
Flow(id=4002, source=zc_fr, sink=['zc_fl', 'zc_rl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 579. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.660ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.660ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 436751015.50
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 410372950.48
(sw_c, sw_fr) in bit/s: None, 393621097.32
(sw_c, sw_rl) in bit/s: None, 153157059.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 406101347.93
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 160726388.51
(sw_rr, sw_c) in bit/s: None, 208884533.06
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Remove Resources ----------------------
----- 580. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 436751015.50
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 410372950.48
(sw_c, sw_fr) in bit/s: None, 393621097.32
(sw_c, sw_rl) in bit/s: None, 153157059.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 324912258.94
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 406101347.93
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 160726388.51
(sw_rr, sw_c) in bit/s: None, 208884533.06
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 343932814.56
------------------- Find Path(s) ----------------------
Flow(id=4002, source=zc_fr, sink=['zc_fl', 'zc_rl', 'zc_rr'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 581. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl', 'zc_rr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.660ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.660ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.660ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 436751015.50
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 410372950.48
(sw_c, sw_fr) in bit/s: None, 393621097.32
(sw_c, sw_rl) in bit/s: None, 153157059.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 329104758.20
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 406101347.93
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 160726388.51
(sw_rr, sw_c) in bit/s: None, 208884533.06
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 347841442.00
------------------- Find Path(s) ----------------------
Flow(id=6071, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 582. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.672ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 440515620.60
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 416599142.57
(sw_c, sw_fr) in bit/s: None, 393621097.32
(sw_c, sw_rl) in bit/s: None, 153157059.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 329104758.20
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 406101347.93
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 160726388.51
(sw_rr, sw_c) in bit/s: None, 211319425.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 347841442.00
------------------- Remove Resources ----------------------
----- 583. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 440515620.60
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 416599142.57
(sw_c, sw_fr) in bit/s: None, 393621097.32
(sw_c, sw_rl) in bit/s: None, 153157059.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 329104758.20
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 406101347.93
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 160726388.51
(sw_rr, sw_c) in bit/s: None, 211319425.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 347841442.00
------------------- Find Path(s) ----------------------
Flow(id=6071, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 584. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.672ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.672ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 440515620.60
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 416599142.57
(sw_c, sw_fr) in bit/s: None, 397518300.80
(sw_c, sw_rl) in bit/s: None, 153157059.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 329104758.20
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 409960885.85
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 160726388.51
(sw_rr, sw_c) in bit/s: None, 211319425.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 347841442.00
------------------- Find Path(s) ----------------------
Flow(id=7013, source=infotainment, sink=['zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 585. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.217ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 154944000.90
(sw_fl, zc_fl) in bit/s: None, 444448524.10
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 416599142.57
(sw_c, sw_fr) in bit/s: None, 397518300.80
(sw_c, sw_rl) in bit/s: None, 153157059.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 329104758.20
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 409960885.85
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 160726388.51
(sw_rr, sw_c) in bit/s: None, 211319425.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 347841442.00
------------------- Find Path(s) ----------------------
Flow(id=3024, source=zc_fl, sink=['zc_rl'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 586. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 157853339.12
(sw_fl, zc_fl) in bit/s: None, 444448524.10
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 416599142.57
(sw_c, sw_fr) in bit/s: None, 397518300.80
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 329104758.20
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 409960885.85
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 211319425.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 347841442.00
------------------- Remove Resources ----------------------
----- 587. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 157853339.12
(sw_fl, zc_fl) in bit/s: None, 444448524.10
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 416599142.57
(sw_c, sw_fr) in bit/s: None, 397518300.80
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 329104758.20
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 409960885.85
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 211319425.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 347841442.00
------------------- Find Path(s) ----------------------
Flow(id=3024, source=zc_fl, sink=['zc_rl', 'zc_fr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 588. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 157853339.12
(sw_fl, zc_fl) in bit/s: None, 444448524.10
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 416599142.57
(sw_c, sw_fr) in bit/s: None, 398081900.22
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 329104758.20
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 413817149.16
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 211319425.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 347841442.00
------------------- Remove Resources ----------------------
----- 589. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 157853339.12
(sw_fl, zc_fl) in bit/s: None, 444448524.10
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 416599142.57
(sw_c, sw_fr) in bit/s: None, 398081900.22
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 329104758.20
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 413817149.16
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 211319425.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 347841442.00
------------------- Find Path(s) ----------------------
Flow(id=3024, source=zc_fl, sink=['zc_rl', 'zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 590. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.649ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 157853339.12
(sw_fl, zc_fl) in bit/s: None, 444448524.10
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 416599142.57
(sw_c, sw_fr) in bit/s: None, 398081900.22
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 332432501.97
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 413817149.16
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 211319425.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 351746716.81
------------------- Find Path(s) ----------------------
Flow(id=6005, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 591. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.673ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 157853339.12
(sw_fl, zc_fl) in bit/s: None, 444448524.10
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 416599142.57
(sw_c, sw_fr) in bit/s: None, 405158413.27
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 332432501.97
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 417670620.20
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 213739728.12
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 351746716.81
------------------- Remove Resources ----------------------
----- 592. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 157853339.12
(sw_fl, zc_fl) in bit/s: None, 444448524.10
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 416599142.57
(sw_c, sw_fr) in bit/s: None, 405158413.27
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 332432501.97
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 417670620.20
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 213739728.12
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 351746716.81
------------------- Find Path(s) ----------------------
Flow(id=6005, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 593. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.673ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.673ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 157853339.12
(sw_fl, zc_fl) in bit/s: None, 448208704.69
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 420386383.01
(sw_c, sw_fr) in bit/s: None, 405158413.27
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 332432501.97
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 417670620.20
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 213739728.12
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 351746716.81
------------------- Remove Resources ----------------------
----- 594. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 157853339.12
(sw_fl, zc_fl) in bit/s: None, 448208704.69
(sw_fl, infotainment) in bit/s: None, 120576729.86
(sw_c, sw_fl) in bit/s: None, 420386383.01
(sw_c, sw_fr) in bit/s: None, 405158413.27
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 332432501.97
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 417670620.20
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 213739728.12
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 351746716.81
------------------- Find Path(s) ----------------------
Flow(id=6005, source=zc_rr, sink=['zc_fr', 'zc_fl', 'infotainment'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 595. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.672ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.673ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.673ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 157853339.12
(sw_fl, zc_fl) in bit/s: None, 448208704.69
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 420386383.01
(sw_c, sw_fr) in bit/s: None, 405158413.27
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 332432501.97
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 417670620.20
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 213739728.12
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 351746716.81
------------------- Find Path(s) ----------------------
Flow(id=3007, source=zc_fl, sink=['zc_rr'], data_per_interval=688, sending_interval=0.06, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 596. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  60.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.650ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 160744204.44
(sw_fl, zc_fl) in bit/s: None, 448208704.69
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 420386383.01
(sw_c, sw_fr) in bit/s: None, 405158413.27
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 336253593.77
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 417670620.20
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 213739728.12
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 355649259.19
------------------- Find Path(s) ----------------------
Flow(id=3013, source=zc_fl, sink=['zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 597. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 163615281.11
(sw_fl, zc_fl) in bit/s: None, 448208704.69
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 420386383.01
(sw_c, sw_fr) in bit/s: None, 405158413.27
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 340074614.17
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 417670620.20
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 213739728.12
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 359548565.02
------------------- Find Path(s) ----------------------
Flow(id=6076, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 598. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.673ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 163615281.11
(sw_fl, zc_fl) in bit/s: None, 451965738.94
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 405158413.27
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 340074614.17
(sw_fr, sw_c) in bit/s: 397580751.34, 153817367.30
(sw_fr, zc_fr) in bit/s: None, 417670620.20
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 359548565.02
------------------- Find Path(s) ----------------------
Flow(id=4030, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 599. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.661ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 163615281.11
(sw_fl, zc_fl) in bit/s: None, 451965738.94
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 405158413.27
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 344025453.32
(sw_fr, sw_c) in bit/s: 397580751.34, 156321946.05
(sw_fr, zc_fr) in bit/s: None, 417670620.20
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 363446905.82
------------------- Find Path(s) ----------------------
Flow(id=7000, source=infotainment, sink=['zc_fl'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 600. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.217ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 163615281.11
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 405158413.27
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 344025453.32
(sw_fr, sw_c) in bit/s: 397580751.34, 156321946.05
(sw_fr, zc_fr) in bit/s: None, 417670620.20
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 363446905.82
------------------- Remove Resources ----------------------
----- 601. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 163615281.11
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 405158413.27
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 344025453.32
(sw_fr, sw_c) in bit/s: 397580751.34, 156321946.05
(sw_fr, zc_fr) in bit/s: None, 417670620.20
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 363446905.82
------------------- Find Path(s) ----------------------
Flow(id=6076, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 602. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.673ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.673ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 163615281.11
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 409054044.42
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 344025453.32
(sw_fr, sw_c) in bit/s: 397580751.34, 156321946.05
(sw_fr, zc_fr) in bit/s: None, 421520819.39
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 363446905.82
------------------- Find Path(s) ----------------------
Flow(id=3016, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 603. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 166466635.93
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 409367047.74
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 344025453.32
(sw_fr, sw_c) in bit/s: 397580751.34, 156321946.05
(sw_fr, zc_fr) in bit/s: None, 425368018.24
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 363446905.82
------------------- Remove Resources ----------------------
----- 604. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 166466635.93
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 409367047.74
(sw_c, sw_rl) in bit/s: None, 157084138.12
(sw_c, sw_rr) in bit/s: 1816838947.80, 344025453.32
(sw_fr, sw_c) in bit/s: 397580751.34, 156321946.05
(sw_fr, zc_fr) in bit/s: None, 425368018.24
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 164781041.63
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 363446905.82
------------------- Find Path(s) ----------------------
Flow(id=3016, source=zc_fl, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 605. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 166466635.93
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 409367047.74
(sw_c, sw_rl) in bit/s: None, 161011221.36
(sw_c, sw_rr) in bit/s: 1816838947.80, 344025453.32
(sw_fr, sw_c) in bit/s: 397580751.34, 156321946.05
(sw_fr, zc_fr) in bit/s: None, 425368018.24
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 168832433.57
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 363446905.82
------------------- Remove Resources ----------------------
----- 606. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 166466635.93
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 409367047.74
(sw_c, sw_rl) in bit/s: None, 161011221.36
(sw_c, sw_rr) in bit/s: 1816838947.80, 344025453.32
(sw_fr, sw_c) in bit/s: 397580751.34, 156321946.05
(sw_fr, zc_fr) in bit/s: None, 425368018.24
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 168832433.57
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 363446905.82
------------------- Find Path(s) ----------------------
Flow(id=3016, source=zc_fl, sink=['zc_fr', 'zc_rl', 'zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 607. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.651ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 166466635.93
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 409367047.74
(sw_c, sw_rl) in bit/s: None, 161011221.36
(sw_c, sw_rr) in bit/s: 1816838947.80, 347587292.28
(sw_fr, sw_c) in bit/s: 397580751.34, 156321946.05
(sw_fr, zc_fr) in bit/s: None, 425368018.24
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 168832433.57
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 367339885.37
------------------- Find Path(s) ----------------------
Flow(id=4008, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 608. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.662ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 166466635.93
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 409367047.74
(sw_c, sw_rl) in bit/s: None, 161011221.36
(sw_c, sw_rr) in bit/s: 1816838947.80, 351538444.48
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 425368018.24
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 168832433.57
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 371229763.06
------------------- Remove Resources ----------------------
----- 609. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 166466635.93
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 409367047.74
(sw_c, sw_rl) in bit/s: None, 161011221.36
(sw_c, sw_rr) in bit/s: 1816838947.80, 351538444.48
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 425368018.24
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 168832433.57
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 371229763.06
------------------- Find Path(s) ----------------------
Flow(id=7013, source=infotainment, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 610. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.217ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.633ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 169862939.51
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 413228822.51
(sw_c, sw_rl) in bit/s: None, 161011221.36
(sw_c, sw_rr) in bit/s: 1816838947.80, 351538444.48
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 429212193.35
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 168832433.57
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 371229763.06
------------------- Find Path(s) ----------------------
Flow(id=3033, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 611. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.652ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 172684606.09
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 417090724.28
(sw_c, sw_rl) in bit/s: None, 161011221.36
(sw_c, sw_rr) in bit/s: 1816838947.80, 351538444.48
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 433053571.78
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 168832433.57
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 371229763.06
------------------- Remove Resources ----------------------
----- 612. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 172684606.09
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 417090724.28
(sw_c, sw_rl) in bit/s: None, 161011221.36
(sw_c, sw_rr) in bit/s: 1816838947.80, 351538444.48
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 433053571.78
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 168832433.57
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 371229763.06
------------------- Find Path(s) ----------------------
Flow(id=3033, source=zc_fl, sink=['zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 613. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.652ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.652ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 172684606.09
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 417090724.28
(sw_c, sw_rl) in bit/s: None, 161011221.36
(sw_c, sw_rr) in bit/s: 1816838947.80, 355093397.98
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 433053571.78
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 168832433.57
(sw_rr, sw_c) in bit/s: None, 216144531.05
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 375116784.37
------------------- Find Path(s) ----------------------
Flow(id=6047, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 614. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.674ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 172684606.09
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 424152514.95
(sw_c, sw_rl) in bit/s: None, 161011221.36
(sw_c, sw_rr) in bit/s: 1816838947.80, 355093397.98
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 436891712.03
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 168832433.57
(sw_rr, sw_c) in bit/s: None, 218535102.96
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 375116784.37
------------------- Remove Resources ----------------------
----- 615. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 172684606.09
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 424152514.95
(sw_c, sw_rl) in bit/s: None, 161011221.36
(sw_c, sw_rr) in bit/s: 1816838947.80, 355093397.98
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 436891712.03
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 168832433.57
(sw_rr, sw_c) in bit/s: None, 218535102.96
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 375116784.37
------------------- Find Path(s) ----------------------
Flow(id=6047, source=zc_rr, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 616. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.674ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.674ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 172684606.09
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 424152514.95
(sw_c, sw_rl) in bit/s: None, 165319218.29
(sw_c, sw_rr) in bit/s: 1816838947.80, 355093397.98
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 436891712.03
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 172880558.04
(sw_rr, sw_c) in bit/s: None, 218535102.96
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 375116784.37
------------------- Remove Resources ----------------------
----- 617. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 172684606.09
(sw_fl, zc_fl) in bit/s: None, 455896977.01
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 424173523.21
(sw_c, sw_fr) in bit/s: None, 424152514.95
(sw_c, sw_rl) in bit/s: None, 165319218.29
(sw_c, sw_rr) in bit/s: 1816838947.80, 355093397.98
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 436891712.03
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 172880558.04
(sw_rr, sw_c) in bit/s: None, 218535102.96
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 375116784.37
------------------- Find Path(s) ----------------------
Flow(id=6047, source=zc_rr, sink=['zc_fr', 'zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 618. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.674ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.674ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.674ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 172684606.09
(sw_fl, zc_fl) in bit/s: None, 459649632.81
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 427960674.54
(sw_c, sw_fr) in bit/s: None, 424152514.95
(sw_c, sw_rl) in bit/s: None, 165319218.29
(sw_c, sw_rr) in bit/s: 1816838947.80, 355093397.98
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 436891712.03
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 172880558.04
(sw_rr, sw_c) in bit/s: None, 218535102.96
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 375116784.37
------------------- Find Path(s) ----------------------
Flow(id=7008, source=infotainment, sink=['zc_fr'], data_per_interval=688, sending_interval=0.15, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 619. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr'] , Bits:  688 , Interval:  150.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 176070019.42
(sw_fl, zc_fl) in bit/s: None, 459649632.81
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 427960674.54
(sw_c, sw_fr) in bit/s: None, 424654168.16
(sw_c, sw_rl) in bit/s: None, 165319218.29
(sw_c, sw_rr) in bit/s: 1816838947.80, 355093397.98
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 440726971.85
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 172880558.04
(sw_rr, sw_c) in bit/s: None, 218535102.96
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 375116784.37
------------------- Remove Resources ----------------------
----- 620. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 176070019.42
(sw_fl, zc_fl) in bit/s: None, 459649632.81
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 427960674.54
(sw_c, sw_fr) in bit/s: None, 424654168.16
(sw_c, sw_rl) in bit/s: None, 165319218.29
(sw_c, sw_rr) in bit/s: 1816838947.80, 355093397.98
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 440726971.85
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 172880558.04
(sw_rr, sw_c) in bit/s: None, 218535102.96
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 375116784.37
------------------- Find Path(s) ----------------------
Flow(id=7000, source=infotainment, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 621. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.218ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 179459269.04
(sw_fl, zc_fl) in bit/s: None, 459649632.81
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 427960674.54
(sw_c, sw_fr) in bit/s: None, 428515258.34
(sw_c, sw_rl) in bit/s: None, 165319218.29
(sw_c, sw_rr) in bit/s: 1816838947.80, 355093397.98
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 444560466.40
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 172880558.04
(sw_rr, sw_c) in bit/s: None, 218535102.96
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 375116784.37
------------------- Remove Resources ----------------------
----- 622. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 179459269.04
(sw_fl, zc_fl) in bit/s: None, 459649632.81
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 427960674.54
(sw_c, sw_fr) in bit/s: None, 428515258.34
(sw_c, sw_rl) in bit/s: None, 165319218.29
(sw_c, sw_rr) in bit/s: 1816838947.80, 355093397.98
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 444560466.40
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 172880558.04
(sw_rr, sw_c) in bit/s: None, 218535102.96
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 375116784.37
------------------- Find Path(s) ----------------------
Flow(id=7000, source=infotainment, sink=['zc_fl', 'zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 623. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.218ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.634ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 179459269.04
(sw_fl, zc_fl) in bit/s: None, 459649632.81
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 427960674.54
(sw_c, sw_fr) in bit/s: None, 428515258.34
(sw_c, sw_rl) in bit/s: None, 165319218.29
(sw_c, sw_rr) in bit/s: 1816838947.80, 358912004.08
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 444560466.40
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 172880558.04
(sw_rr, sw_c) in bit/s: None, 218535102.96
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 379001719.34
------------------- Find Path(s) ----------------------
Flow(id=3017, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 624. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 459649632.81
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 427960674.54
(sw_c, sw_fr) in bit/s: None, 432375574.09
(sw_c, sw_rl) in bit/s: None, 165319218.29
(sw_c, sw_rr) in bit/s: 1816838947.80, 358912004.08
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 448389590.77
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 172880558.04
(sw_rr, sw_c) in bit/s: None, 218535102.96
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 379001719.34
------------------- Remove Resources ----------------------
----- 625. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 459649632.81
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 427960674.54
(sw_c, sw_fr) in bit/s: None, 432375574.09
(sw_c, sw_rl) in bit/s: None, 165319218.29
(sw_c, sw_rr) in bit/s: 1816838947.80, 358912004.08
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 448389590.77
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 172880558.04
(sw_rr, sw_c) in bit/s: None, 218535102.96
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 379001719.34
------------------- Find Path(s) ----------------------
Flow(id=3017, source=zc_fl, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 626. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 459649632.81
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 427960674.54
(sw_c, sw_fr) in bit/s: None, 432375574.09
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 358912004.08
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 448389590.77
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 218535102.96
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 379001719.34
------------------- Remove Resources ----------------------
----- 627. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 459649632.81
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 427960674.54
(sw_c, sw_fr) in bit/s: None, 432375574.09
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 358912004.08
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 448389590.77
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 218535102.96
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 379001719.34
------------------- Find Path(s) ----------------------
Flow(id=3017, source=zc_fl, sink=['zc_fr', 'zc_rl', 'zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 628. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 459649632.81
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 427960674.54
(sw_c, sw_fr) in bit/s: None, 432375574.09
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 362730071.19
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 448389590.77
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 218535102.96
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 382882422.95
------------------- Find Path(s) ----------------------
Flow(id=6056, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 629. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.675ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 463399614.57
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 431747914.98
(sw_c, sw_fr) in bit/s: None, 432375574.09
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 362730071.19
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 448389590.77
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 382882422.95
------------------- Remove Resources ----------------------
----- 630. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 463399614.57
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 431747914.98
(sw_c, sw_fr) in bit/s: None, 432375574.09
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 362730071.19
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 448389590.77
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 382882422.95
------------------- Find Path(s) ----------------------
Flow(id=6056, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 631. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.675ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.675ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 463399614.57
(sw_fl, infotainment) in bit/s: None, 124123036.29
(sw_c, sw_fl) in bit/s: None, 431747914.98
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 362730071.19
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 382882422.95
------------------- Find Path(s) ----------------------
Flow(id=3000, source=zc_fl, sink=['infotainment'], data_per_interval=688, sending_interval=0.06, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 632. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  60.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.237ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 463399614.57
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 431747914.98
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 362730071.19
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 17170729.82
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 382882422.95
------------------- Find Path(s) ----------------------
Flow(id=5005, source=zc_rl, sink=['zc_fl'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 633. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 467146454.92
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 432163741.41
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 362730071.19
(sw_fr, sw_c) in bit/s: 397580751.34, 158803148.14
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 382882422.95
------------------- Find Path(s) ----------------------
Flow(id=4045, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 634. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.662ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 470890518.20
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 435921573.64
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 362730071.19
(sw_fr, sw_c) in bit/s: 397580751.34, 161270167.99
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 382882422.95
------------------- Remove Resources ----------------------
----- 635. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 470890518.20
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 435921573.64
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 362730071.19
(sw_fr, sw_c) in bit/s: 397580751.34, 161270167.99
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 382882422.95
------------------- Find Path(s) ----------------------
Flow(id=4045, source=zc_fr, sink=['zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 636. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.662ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.662ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 470890518.20
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 435921573.64
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 366411019.75
(sw_fr, sw_c) in bit/s: 397580751.34, 161270167.99
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 386760138.25
------------------- Find Path(s) ----------------------
Flow(id=4055, source=zc_fr, sink=['zc_rr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 637. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.663ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 470890518.20
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 435921573.64
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 370228206.28
(sw_fr, sw_c) in bit/s: 397580751.34, 163726942.46
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 390635931.51
------------------- Remove Resources ----------------------
----- 638. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 470890518.20
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 435921573.64
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 370228206.28
(sw_fr, sw_c) in bit/s: 397580751.34, 163726942.46
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 390635931.51
------------------- Find Path(s) ----------------------
Flow(id=4055, source=zc_fr, sink=['zc_rr', 'zc_fl'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 639. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.663ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.663ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 474632978.89
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 439680147.51
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 370228206.28
(sw_fr, sw_c) in bit/s: 397580751.34, 163726942.46
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 390635931.51
------------------- Find Path(s) ----------------------
Flow(id=4024, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 640. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 478374015.75
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 443439545.41
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 370228206.28
(sw_fr, sw_c) in bit/s: 397580751.34, 166174219.94
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 390635931.51
------------------- Remove Resources ----------------------
----- 641. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 478374015.75
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 443439545.41
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 370228206.28
(sw_fr, sw_c) in bit/s: 397580751.34, 166174219.94
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 390635931.51
------------------- Find Path(s) ----------------------
Flow(id=4024, source=zc_fr, sink=['zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 642. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 478374015.75
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 443439545.41
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 168800564.54
(sw_c, sw_rr) in bit/s: 1816838947.80, 374045967.17
(sw_fr, sw_c) in bit/s: 397580751.34, 166174219.94
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 176925418.99
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 394509967.10
------------------- Find Path(s) ----------------------
Flow(id=4016, source=zc_fr, sink=['zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 643. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 478374015.75
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 443439545.41
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 374045967.17
(sw_fr, sw_c) in bit/s: 397580751.34, 168598254.89
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 394509967.10
------------------- Remove Resources ----------------------
----- 644. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 478374015.75
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 443439545.41
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 374045967.17
(sw_fr, sw_c) in bit/s: 397580751.34, 168598254.89
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 394509967.10
------------------- Find Path(s) ----------------------
Flow(id=4016, source=zc_fr, sink=['zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 645. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 482109380.36
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 447197328.20
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 374045967.17
(sw_fr, sw_c) in bit/s: 397580751.34, 168598254.89
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 394509967.10
------------------- Remove Resources ----------------------
----- 646. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 482109380.36
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 447197328.20
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 374045967.17
(sw_fr, sw_c) in bit/s: 397580751.34, 168598254.89
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 394509967.10
------------------- Find Path(s) ----------------------
Flow(id=4016, source=zc_fr, sink=['zc_rl', 'zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 647. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.664ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 482109380.36
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 447197328.20
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 377862602.32
(sw_fr, sw_c) in bit/s: 397580751.34, 168598254.89
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 220912396.74
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 398378475.82
------------------- Find Path(s) ----------------------
Flow(id=6016, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 648. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.675ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 485843270.22
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 453798780.77
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 377862602.32
(sw_fr, sw_c) in bit/s: 397580751.34, 168598254.89
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 223280348.81
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 398378475.82
------------------- Remove Resources ----------------------
----- 649. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 485843270.22
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 453798780.77
(sw_c, sw_fr) in bit/s: None, 439217118.05
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 377862602.32
(sw_fr, sw_c) in bit/s: 397580751.34, 168598254.89
(sw_fr, zc_fr) in bit/s: None, 452215945.83
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 223280348.81
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 398378475.82
------------------- Find Path(s) ----------------------
Flow(id=6016, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 650. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.675ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.675ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 485843270.22
(sw_fl, infotainment) in bit/s: None, 127219408.24
(sw_c, sw_fl) in bit/s: None, 453798780.77
(sw_c, sw_fr) in bit/s: None, 443104416.34
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 377862602.32
(sw_fr, sw_c) in bit/s: 397580751.34, 168598254.89
(sw_fr, zc_fr) in bit/s: None, 456040481.13
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 223280348.81
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 398378475.82
------------------- Find Path(s) ----------------------
Flow(id=4043, source=zc_fr, sink=['infotainment'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]]
------------------- Reserve Resources ----------------------
----- 651. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.665ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 485843270.22
(sw_fl, infotainment) in bit/s: None, 130752986.28
(sw_c, sw_fl) in bit/s: None, 454546126.18
(sw_c, sw_fr) in bit/s: None, 443104416.34
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 377862602.32
(sw_fr, sw_c) in bit/s: 397580751.34, 171008147.43
(sw_fr, zc_fr) in bit/s: None, 456040481.13
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 223280348.81
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 398378475.82
------------------- Find Path(s) ----------------------
Flow(id=4036, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 652. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 489574309.52
(sw_fl, infotainment) in bit/s: None, 130752986.28
(sw_c, sw_fl) in bit/s: None, 458303324.74
(sw_c, sw_fr) in bit/s: None, 443104416.34
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 377862602.32
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 456040481.13
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 223280348.81
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 398378475.82
------------------- Find Path(s) ----------------------
Flow(id=6030, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.03, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 653. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  30.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.676ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 493302007.06
(sw_fl, infotainment) in bit/s: None, 130752986.28
(sw_c, sw_fl) in bit/s: None, 464799560.80
(sw_c, sw_fr) in bit/s: None, 443104416.34
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 377862602.32
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 456040481.13
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 225632434.42
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 398378475.82
------------------- Remove Resources ----------------------
----- 654. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  30.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 493302007.06
(sw_fl, infotainment) in bit/s: None, 130752986.28
(sw_c, sw_fl) in bit/s: None, 464799560.80
(sw_c, sw_fr) in bit/s: None, 443104416.34
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 377862602.32
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 456040481.13
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 225632434.42
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 398378475.82
------------------- Find Path(s) ----------------------
Flow(id=6030, source=zc_rr, sink=['zc_fl', 'zc_fr'], data_per_interval=688, sending_interval=0.03, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 655. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  30.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.676ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.676ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 493302007.06
(sw_fl, infotainment) in bit/s: None, 130752986.28
(sw_c, sw_fl) in bit/s: None, 464799560.80
(sw_c, sw_fr) in bit/s: None, 446991524.13
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 377862602.32
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 459861550.31
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 225632434.42
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 398378475.82
------------------- Find Path(s) ----------------------
Flow(id=6009, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 656. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.677ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 493302007.06
(sw_fl, infotainment) in bit/s: None, 130752986.28
(sw_c, sw_fl) in bit/s: None, 464799560.80
(sw_c, sw_fr) in bit/s: None, 450878262.33
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 377862602.32
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 463678677.03
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 227966847.11
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 398378475.82
------------------- Remove Resources ----------------------
----- 657. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 493302007.06
(sw_fl, infotainment) in bit/s: None, 130752986.28
(sw_c, sw_fl) in bit/s: None, 464799560.80
(sw_c, sw_fr) in bit/s: None, 450878262.33
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 377862602.32
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 463678677.03
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 227966847.11
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 398378475.82
------------------- Find Path(s) ----------------------
Flow(id=6009, source=zc_rr, sink=['zc_fr', 'zc_fl'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 658. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.677ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.677ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 497025885.95
(sw_fl, infotainment) in bit/s: None, 130752986.28
(sw_c, sw_fl) in bit/s: None, 468578260.94
(sw_c, sw_fr) in bit/s: None, 450878262.33
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 377862602.32
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 463678677.03
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 227966847.11
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 398378475.82
------------------- Remove Resources ----------------------
----- 659. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 497025885.95
(sw_fl, infotainment) in bit/s: None, 130752986.28
(sw_c, sw_fl) in bit/s: None, 468578260.94
(sw_c, sw_fr) in bit/s: None, 450878262.33
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 377862602.32
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 463678677.03
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 227966847.11
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 398378475.82
------------------- Find Path(s) ----------------------
Flow(id=6009, source=zc_rr, sink=['zc_fr', 'zc_fl', 'infotainment'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 660. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.677ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.677ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.677ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 497025885.95
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 468578260.94
(sw_c, sw_fr) in bit/s: None, 450878262.33
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 377862602.32
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 463678677.03
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 227966847.11
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 398378475.82
------------------- Remove Resources ----------------------
----- 661. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 497025885.95
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 468578260.94
(sw_c, sw_fr) in bit/s: None, 450878262.33
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 377862602.32
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 463678677.03
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 227966847.11
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 398378475.82
------------------- Find Path(s) ----------------------
Flow(id=4043, source=zc_fr, sink=['infotainment', 'zc_rr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 662. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 497025885.95
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 468578260.94
(sw_c, sw_fr) in bit/s: None, 450878262.33
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 381679225.99
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 463678677.03
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 227966847.11
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 402243909.64
------------------- Remove Resources ----------------------
----- 663. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 497025885.95
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 468578260.94
(sw_c, sw_fr) in bit/s: None, 450878262.33
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 381679225.99
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 463678677.03
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 227966847.11
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 402243909.64
------------------- Find Path(s) ----------------------
Flow(id=4036, source=zc_fr, sink=['zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 664. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 497025885.95
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 468578260.94
(sw_c, sw_fr) in bit/s: None, 450878262.33
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 385496412.52
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 463678677.03
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 227966847.11
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 406107583.03
------------------- Find Path(s) ----------------------
Flow(id=6027, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.02, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 665. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.677ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 497025885.95
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 468578260.94
(sw_c, sw_fr) in bit/s: None, 454765560.62
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 385496412.52
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 467494289.84
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 230293468.98
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 406107583.03
------------------- Remove Resources ----------------------
----- 666. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  60.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 182239301.64
(sw_fl, zc_fl) in bit/s: None, 497025885.95
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 468578260.94
(sw_c, sw_fr) in bit/s: None, 454765560.62
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 385496412.52
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 467494289.84
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 230293468.98
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 406107583.03
------------------- Find Path(s) ----------------------
Flow(id=3000, source=zc_fl, sink=['infotainment', 'zc_fr'], data_per_interval=688, sending_interval=0.06, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 667. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  60.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.408ms
Reservation Dependent Flow Delay: 0.237ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.653ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 185002067.03
(sw_fl, zc_fl) in bit/s: None, 497025885.95
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 468578260.94
(sw_c, sw_fr) in bit/s: None, 454682708.24
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 385496412.52
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 471305929.31
(sw_rl, sw_c) in bit/s: 397580751.34, 20534390.86
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 230293468.98
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 406107583.03
------------------- Find Path(s) ----------------------
Flow(id=5003, source=zc_rl, sink=['zc_rr'], data_per_interval=688, sending_interval=0.2, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 668. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.629ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 185002067.03
(sw_fl, zc_fl) in bit/s: None, 497025885.95
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 468578260.94
(sw_c, sw_fr) in bit/s: None, 454682708.24
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 388586139.56
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 471305929.31
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 230293468.98
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 409967046.76
------------------- Find Path(s) ----------------------
Flow(id=6074, source=zc_rr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.01, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 669. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.678ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 185002067.03
(sw_fl, zc_fl) in bit/s: None, 500749884.58
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 472358215.70
(sw_c, sw_fr) in bit/s: None, 454682708.24
(sw_c, sw_rl) in bit/s: None, 172726139.08
(sw_c, sw_rr) in bit/s: 1816838947.80, 388586139.56
(sw_fr, sw_c) in bit/s: 397580751.34, 173408868.00
(sw_fr, zc_fr) in bit/s: None, 471305929.31
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 180967020.37
(sw_rr, sw_c) in bit/s: None, 232612672.26
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 409967046.76
------------------- Find Path(s) ----------------------
Flow(id=4003, source=zc_fr, sink=['zc_rl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 670. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 185002067.03
(sw_fl, zc_fl) in bit/s: None, 500749884.58
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 472358215.70
(sw_c, sw_fr) in bit/s: None, 454682708.24
(sw_c, sw_rl) in bit/s: None, 176651761.11
(sw_c, sw_rr) in bit/s: 1816838947.80, 388586139.56
(sw_fr, sw_c) in bit/s: 397580751.34, 175792208.24
(sw_fr, zc_fr) in bit/s: None, 471305929.31
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 185005490.76
(sw_rr, sw_c) in bit/s: None, 232612672.26
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 409967046.76
------------------- Remove Resources ----------------------
----- 671. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 185002067.03
(sw_fl, zc_fl) in bit/s: None, 500749884.58
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 472358215.70
(sw_c, sw_fr) in bit/s: None, 454682708.24
(sw_c, sw_rl) in bit/s: None, 176651761.11
(sw_c, sw_rr) in bit/s: 1816838947.80, 388586139.56
(sw_fr, sw_c) in bit/s: 397580751.34, 175792208.24
(sw_fr, zc_fr) in bit/s: None, 471305929.31
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 185005490.76
(sw_rr, sw_c) in bit/s: None, 232612672.26
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 409967046.76
------------------- Find Path(s) ----------------------
Flow(id=4003, source=zc_fr, sink=['zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 672. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 185002067.03
(sw_fl, zc_fl) in bit/s: None, 504468411.80
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 472808710.65
(sw_c, sw_fr) in bit/s: None, 454682708.24
(sw_c, sw_rl) in bit/s: None, 176651761.11
(sw_c, sw_rr) in bit/s: 1816838947.80, 388586139.56
(sw_fr, sw_c) in bit/s: 397580751.34, 175792208.24
(sw_fr, zc_fr) in bit/s: None, 471305929.31
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 185005490.76
(sw_rr, sw_c) in bit/s: None, 232612672.26
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 409967046.76
------------------- Remove Resources ----------------------
----- 673. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 185002067.03
(sw_fl, zc_fl) in bit/s: None, 504468411.80
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 472808710.65
(sw_c, sw_fr) in bit/s: None, 454682708.24
(sw_c, sw_rl) in bit/s: None, 176651761.11
(sw_c, sw_rr) in bit/s: 1816838947.80, 388586139.56
(sw_fr, sw_c) in bit/s: 397580751.34, 175792208.24
(sw_fr, zc_fr) in bit/s: None, 471305929.31
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 185005490.76
(sw_rr, sw_c) in bit/s: None, 232612672.26
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 409967046.76
------------------- Find Path(s) ----------------------
Flow(id=4003, source=zc_fr, sink=['zc_rl', 'zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.08, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 674. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl', 'zc_rr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.666ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 185002067.03
(sw_fl, zc_fl) in bit/s: None, 504468411.80
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 472808710.65
(sw_c, sw_fr) in bit/s: None, 454682708.24
(sw_c, sw_rl) in bit/s: None, 176651761.11
(sw_c, sw_rr) in bit/s: 1816838947.80, 393129837.91
(sw_fr, sw_c) in bit/s: 397580751.34, 175792208.24
(sw_fr, zc_fr) in bit/s: None, 471305929.31
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 185005490.76
(sw_rr, sw_c) in bit/s: None, 232612672.26
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 413823674.24
------------------- Find Path(s) ----------------------
Flow(id=6050, source=zc_rr, sink=['zc_fr'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 675. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.679ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 185002067.03
(sw_fl, zc_fl) in bit/s: None, 504468411.80
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 472808710.65
(sw_c, sw_fr) in bit/s: None, 462363716.71
(sw_c, sw_rl) in bit/s: None, 176651761.11
(sw_c, sw_rr) in bit/s: 1816838947.80, 393129837.91
(sw_fr, sw_c) in bit/s: 397580751.34, 175792208.24
(sw_fr, zc_fr) in bit/s: None, 475114145.86
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 185005490.76
(sw_rr, sw_c) in bit/s: None, 234906525.43
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 413823674.24
------------------- Remove Resources ----------------------
----- 676. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 185002067.03
(sw_fl, zc_fl) in bit/s: None, 504468411.80
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 472808710.65
(sw_c, sw_fr) in bit/s: None, 462363716.71
(sw_c, sw_rl) in bit/s: None, 176651761.11
(sw_c, sw_rr) in bit/s: 1816838947.80, 393129837.91
(sw_fr, sw_c) in bit/s: 397580751.34, 175792208.24
(sw_fr, zc_fr) in bit/s: None, 475114145.86
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 185005490.76
(sw_rr, sw_c) in bit/s: None, 234906525.43
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 413823674.24
------------------- Find Path(s) ----------------------
Flow(id=6050, source=zc_rr, sink=['zc_fr', 'zc_rl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 677. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.679ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.679ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 185002067.03
(sw_fl, zc_fl) in bit/s: None, 504468411.80
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 472808710.65
(sw_c, sw_fr) in bit/s: None, 462363716.71
(sw_c, sw_rl) in bit/s: None, 180994218.37
(sw_c, sw_rr) in bit/s: 1816838947.80, 393129837.91
(sw_fr, sw_c) in bit/s: 397580751.34, 175792208.24
(sw_fr, zc_fr) in bit/s: None, 475114145.86
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 189040587.60
(sw_rr, sw_c) in bit/s: None, 234906525.43
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 413823674.24
------------------- Find Path(s) ----------------------
Flow(id=3036, source=zc_fl, sink=['zc_fr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]]
------------------- Reserve Resources ----------------------
----- 678. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.654ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 187745467.15
(sw_fl, zc_fl) in bit/s: None, 504468411.80
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 472808710.65
(sw_c, sw_fr) in bit/s: None, 462214832.31
(sw_c, sw_rl) in bit/s: None, 180994218.37
(sw_c, sw_rr) in bit/s: 1816838947.80, 393129837.91
(sw_fr, sw_c) in bit/s: 397580751.34, 175792208.24
(sw_fr, zc_fr) in bit/s: None, 478919353.67
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 189040587.60
(sw_rr, sw_c) in bit/s: None, 234906525.43
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 413823674.24
------------------- Remove Resources ----------------------
----- 679. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 187745467.15
(sw_fl, zc_fl) in bit/s: None, 504468411.80
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 472808710.65
(sw_c, sw_fr) in bit/s: None, 462214832.31
(sw_c, sw_rl) in bit/s: None, 180994218.37
(sw_c, sw_rr) in bit/s: 1816838947.80, 393129837.91
(sw_fr, sw_c) in bit/s: 397580751.34, 175792208.24
(sw_fr, zc_fr) in bit/s: None, 478919353.67
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 189040587.60
(sw_rr, sw_c) in bit/s: None, 234906525.43
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 413823674.24
------------------- Find Path(s) ----------------------
Flow(id=6050, source=zc_rr, sink=['zc_fr', 'zc_rl', 'zc_fl'], data_per_interval=688, sending_interval=0.5, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]]
------------------- Reserve Resources ----------------------
----- 680. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.679ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.679ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.679ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 187745467.15
(sw_fl, zc_fl) in bit/s: None, 508183766.00
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 479738021.44
(sw_c, sw_fr) in bit/s: None, 462214832.31
(sw_c, sw_rl) in bit/s: None, 180994218.37
(sw_c, sw_rr) in bit/s: 1816838947.80, 393129837.91
(sw_fr, sw_c) in bit/s: 397580751.34, 175792208.24
(sw_fr, zc_fr) in bit/s: None, 478919353.67
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 189040587.60
(sw_rr, sw_c) in bit/s: None, 234906525.43
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 413823674.24
------------------- Remove Resources ----------------------
----- 681. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 187745467.15
(sw_fl, zc_fl) in bit/s: None, 508183766.00
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 479738021.44
(sw_c, sw_fr) in bit/s: None, 462214832.31
(sw_c, sw_rl) in bit/s: None, 180994218.37
(sw_c, sw_rr) in bit/s: 1816838947.80, 393129837.91
(sw_fr, sw_c) in bit/s: 397580751.34, 175792208.24
(sw_fr, zc_fr) in bit/s: None, 478919353.67
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 189040587.60
(sw_rr, sw_c) in bit/s: None, 234906525.43
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 413823674.24
------------------- Find Path(s) ----------------------
Flow(id=3036, source=zc_fl, sink=['zc_fr', 'zc_rr'], data_per_interval=688, sending_interval=1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)], [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 682. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.654ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.654ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 187745467.15
(sw_fl, zc_fl) in bit/s: None, 508183766.00
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 479738021.44
(sw_c, sw_fr) in bit/s: None, 462214832.31
(sw_c, sw_rl) in bit/s: None, 180994218.37
(sw_c, sw_rr) in bit/s: 1816838947.80, 396057343.20
(sw_fr, sw_c) in bit/s: 397580751.34, 175792208.24
(sw_fr, zc_fr) in bit/s: None, 478919353.67
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 189040587.60
(sw_rr, sw_c) in bit/s: None, 234906525.43
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 417676962.18
------------------- Find Path(s) ----------------------
Flow(id=4032, source=zc_fr, sink=['zc_fl'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]]
------------------- Reserve Resources ----------------------
----- 683. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.667ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 187745467.15
(sw_fl, zc_fl) in bit/s: None, 511896513.56
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 480136682.09
(sw_c, sw_fr) in bit/s: None, 462214832.31
(sw_c, sw_rl) in bit/s: None, 180994218.37
(sw_c, sw_rr) in bit/s: 1816838947.80, 396057343.20
(sw_fr, sw_c) in bit/s: 397580751.34, 178161636.76
(sw_fr, zc_fr) in bit/s: None, 478919353.67
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 189040587.60
(sw_rr, sw_c) in bit/s: None, 234906525.43
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 417676962.18
------------------- Remove Resources ----------------------
----- 684. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 187745467.15
(sw_fl, zc_fl) in bit/s: None, 511896513.56
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 480136682.09
(sw_c, sw_fr) in bit/s: None, 462214832.31
(sw_c, sw_rl) in bit/s: None, 180994218.37
(sw_c, sw_rr) in bit/s: 1816838947.80, 396057343.20
(sw_fr, sw_c) in bit/s: 397580751.34, 178161636.76
(sw_fr, zc_fr) in bit/s: None, 478919353.67
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 189040587.60
(sw_rr, sw_c) in bit/s: None, 234906525.43
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 417676962.18
------------------- Find Path(s) ----------------------
Flow(id=4032, source=zc_fr, sink=['zc_fl', 'zc_rr'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 685. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.667ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.667ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 187745467.15
(sw_fl, zc_fl) in bit/s: None, 511896513.56
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 480136682.09
(sw_c, sw_fr) in bit/s: None, 462214832.31
(sw_c, sw_rl) in bit/s: None, 180994218.37
(sw_c, sw_rr) in bit/s: 1816838947.80, 400613314.04
(sw_fr, sw_c) in bit/s: 397580751.34, 178161636.76
(sw_fr, zc_fr) in bit/s: None, 478919353.67
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 189040587.60
(sw_rr, sw_c) in bit/s: None, 234906525.43
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 421527463.55
------------------- Remove Resources ----------------------
----- 686. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 187745467.15
(sw_fl, zc_fl) in bit/s: None, 511896513.56
(sw_fl, infotainment) in bit/s: None, 134286564.32
(sw_c, sw_fl) in bit/s: None, 480136682.09
(sw_c, sw_fr) in bit/s: None, 462214832.31
(sw_c, sw_rl) in bit/s: None, 180994218.37
(sw_c, sw_rr) in bit/s: 1816838947.80, 400613314.04
(sw_fr, sw_c) in bit/s: 397580751.34, 178161636.76
(sw_fr, zc_fr) in bit/s: None, 478919353.67
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 189040587.60
(sw_rr, sw_c) in bit/s: None, 234906525.43
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 421527463.55
------------------- Find Path(s) ----------------------
Flow(id=4032, source=zc_fr, sink=['zc_fl', 'zc_rr', 'infotainment'], data_per_interval=688, sending_interval=0.1, deadline=0.001, max_frame_size=592, priority=1, redundancy=False)
Path found: [[('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)], [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]]
------------------- Reserve Resources ----------------------
----- 687. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  1.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.667ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.667ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 0.824ms
Reservation Dependent Flow Delay: 0.667ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 194034870.97, 187745467.15
(sw_fl, zc_fl) in bit/s: None, 511896513.56
(sw_fl, infotainment) in bit/s: None, 137820361.18
(sw_c, sw_fl) in bit/s: None, 480136682.09
(sw_c, sw_fr) in bit/s: None, 462214832.31
(sw_c, sw_rl) in bit/s: None, 180994218.37
(sw_c, sw_rr) in bit/s: 1816838947.80, 400613314.04
(sw_fr, sw_c) in bit/s: 397580751.34, 178161636.76
(sw_fr, zc_fr) in bit/s: None, 478919353.67
(sw_rl, sw_c) in bit/s: 397580751.34, 23875166.22
(sw_rl, zc_rl) in bit/s: None, 189040587.60
(sw_rr, sw_c) in bit/s: None, 234906525.43
(sw_rr, adas) in bit/s: 2212453516.63, None
(sw_rr, zc_rr) in bit/s: None, 421527463.55
--------------------------------
Successfully reserved flows:  451  of  215
Unsuccessful reservations:  0
Total flow operations: 687
------- Finished -------
Min. Calculation Time:  7.200241088867188e-05
Max. Calculation Time:  0.0013070106506347656
Avg. Calculation Time:  0.00042752719862492323
----- End Online Admission ----
