----- Start of pre-configuration ----
----- Pre-configuration finished ----
----- Start Online Admission ----
----- 1. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.475ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 624449.75
(sw_fr, sw_c) in bit/s: None, 604662.94
----- 2. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 624449.75
(sw_c, sw_rr) in bit/s: None, 624449.75
(sw_fr, sw_c) in bit/s: None, 1208605.46
(sw_rr, zc_rr) in bit/s: None, 628042.35
----- 3. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 624449.75
(sw_c, sw_rr) in bit/s: None, 624449.75
(sw_fr, sw_c) in bit/s: None, 1208605.46
(sw_rr, zc_rr) in bit/s: None, 628042.35
----- 4. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, zc_fl) in bit/s: None, 624449.75
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 1248144.08
(sw_c, sw_rr) in bit/s: None, 624449.75
(sw_fr, sw_c) in bit/s: None, 1208605.46
(sw_rr, zc_rr) in bit/s: None, 628042.35
----- 5. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, zc_fl) in bit/s: None, 624449.75
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 1248144.08
(sw_c, sw_fr) in bit/s: None, 629246.79
(sw_c, sw_rr) in bit/s: None, 624449.75
(sw_fr, sw_c) in bit/s: None, 1208605.46
(sw_fr, zc_fr) in bit/s: None, 628042.35
(sw_rr, sw_c) in bit/s: None, 624449.75
(sw_rr, zc_rr) in bit/s: None, 628042.35
----- 6. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, zc_fl) in bit/s: None, 624449.75
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 1248144.08
(sw_c, sw_fr) in bit/s: None, 629246.79
(sw_c, sw_rr) in bit/s: None, 624449.75
(sw_fr, sw_c) in bit/s: None, 1208605.46
(sw_fr, zc_fr) in bit/s: None, 628042.35
(sw_rr, sw_c) in bit/s: None, 624449.75
(sw_rr, zc_rr) in bit/s: None, 628042.35
----- 7. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, zc_fl) in bit/s: None, 1248163.38
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 1872232.22
(sw_c, sw_fr) in bit/s: None, 629246.79
(sw_c, sw_rr) in bit/s: None, 624449.75
(sw_fr, sw_c) in bit/s: None, 1208605.46
(sw_fr, zc_fr) in bit/s: None, 628042.35
(sw_rr, sw_c) in bit/s: None, 624449.75
(sw_rr, zc_rr) in bit/s: None, 628042.35
----- 8. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, zc_fl) in bit/s: None, 1248163.38
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 1872232.22
(sw_c, sw_fr) in bit/s: None, 629246.79
(sw_c, sw_rr) in bit/s: None, 1248163.38
(sw_fr, sw_c) in bit/s: None, 1811859.97
(sw_fr, zc_fr) in bit/s: None, 628042.35
(sw_rr, sw_c) in bit/s: None, 624449.75
(sw_rr, zc_rr) in bit/s: None, 1255342.28
----- 9. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 1248163.38
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 1872232.22
(sw_c, sw_fr) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 1248163.38
(sw_fr, sw_c) in bit/s: None, 1811859.97
(sw_fr, zc_fr) in bit/s: None, 1255335.81
(sw_rr, sw_c) in bit/s: None, 624449.75
(sw_rr, zc_rr) in bit/s: None, 1255342.28
----- 10. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 1248163.38
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 1872232.22
(sw_c, sw_fr) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 1248163.38
(sw_fr, sw_c) in bit/s: None, 1811859.97
(sw_fr, zc_fr) in bit/s: None, 1255335.81
(sw_rr, sw_c) in bit/s: None, 624449.75
(sw_rr, zc_rr) in bit/s: None, 1255342.28
----- 11. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 1248163.38
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 1872232.22
(sw_c, sw_fr) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 1872232.19
(sw_fr, sw_c) in bit/s: None, 1811859.97
(sw_fr, zc_fr) in bit/s: None, 1255335.81
(sw_rr, sw_c) in bit/s: None, 624449.75
(sw_rr, zc_rr) in bit/s: None, 1881875.24
----- 12. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 1248163.38
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 1872232.22
(sw_c, sw_fr) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 2494804.81
(sw_fr, sw_c) in bit/s: None, 2414371.71
(sw_fr, zc_fr) in bit/s: None, 1255335.81
(sw_rr, sw_c) in bit/s: None, 624449.75
(sw_rr, zc_rr) in bit/s: None, 2507642.65
----- 13. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 1248163.38
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 1872232.22
(sw_c, sw_fr) in bit/s: None, 1886602.79
(sw_c, sw_rr) in bit/s: None, 2494804.81
(sw_fr, sw_c) in bit/s: None, 2414371.71
(sw_fr, zc_fr) in bit/s: None, 1881859.73
(sw_rr, sw_c) in bit/s: None, 1248155.66
(sw_rr, zc_rr) in bit/s: None, 2507642.65
----- 14. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 1248163.38
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 1872232.22
(sw_c, sw_fr) in bit/s: None, 1886602.79
(sw_c, sw_rr) in bit/s: None, 2494804.81
(sw_fr, sw_c) in bit/s: None, 2414371.71
(sw_fr, zc_fr) in bit/s: None, 1881859.73
(sw_rr, sw_c) in bit/s: None, 1248155.66
(sw_rr, zc_rr) in bit/s: None, 2507642.65
----- 15. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 1248163.38
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 1872232.22
(sw_c, sw_fr) in bit/s: None, 1886602.79
(sw_c, sw_rl) in bit/s: None, 629246.79
(sw_c, sw_rr) in bit/s: None, 2494804.81
(sw_fr, sw_c) in bit/s: None, 2414371.71
(sw_fr, zc_fr) in bit/s: None, 1881859.73
(sw_rl, zc_rl) in bit/s: None, 628042.35
(sw_rr, sw_c) in bit/s: None, 1248155.66
(sw_rr, zc_rr) in bit/s: None, 2507642.65
----- 16. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 1248163.38
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 1872232.22
(sw_c, sw_fr) in bit/s: None, 1886602.79
(sw_c, sw_rl) in bit/s: None, 629246.79
(sw_c, sw_rr) in bit/s: None, 2494804.81
(sw_fr, sw_c) in bit/s: None, 2414371.71
(sw_fr, zc_fr) in bit/s: None, 1881859.73
(sw_rl, zc_rl) in bit/s: None, 628042.35
(sw_rr, sw_c) in bit/s: None, 1248155.66
(sw_rr, zc_rr) in bit/s: None, 2507642.65
----- 17. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 1871113.91
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 2496299.73
(sw_c, sw_fr) in bit/s: None, 1886602.79
(sw_c, sw_rl) in bit/s: None, 629246.79
(sw_c, sw_rr) in bit/s: None, 2494804.81
(sw_fr, sw_c) in bit/s: None, 2414371.71
(sw_fr, zc_fr) in bit/s: None, 1881859.73
(sw_rl, zc_rl) in bit/s: None, 628042.35
(sw_rr, sw_c) in bit/s: None, 1248155.66
(sw_rr, zc_rr) in bit/s: None, 2507642.65
----- 18. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 1871113.91
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 2496299.73
(sw_c, sw_fr) in bit/s: None, 2513956.32
(sw_c, sw_rl) in bit/s: None, 629246.79
(sw_c, sw_rr) in bit/s: None, 2494804.81
(sw_fr, sw_c) in bit/s: None, 2414371.71
(sw_fr, zc_fr) in bit/s: None, 2507638.77
(sw_rl, zc_rl) in bit/s: None, 628042.35
(sw_rr, sw_c) in bit/s: None, 1871113.91
(sw_rr, zc_rr) in bit/s: None, 2507642.65
----- 19. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 1871113.91
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 2496299.73
(sw_c, sw_fr) in bit/s: None, 2513956.32
(sw_c, sw_rl) in bit/s: None, 629246.79
(sw_c, sw_rr) in bit/s: None, 2494804.81
(sw_fr, sw_c) in bit/s: None, 2414371.71
(sw_fr, zc_fr) in bit/s: None, 2507638.77
(sw_rl, zc_rl) in bit/s: None, 628042.35
(sw_rr, sw_c) in bit/s: None, 1871113.91
(sw_rr, zc_rr) in bit/s: None, 2507642.65
----- 20. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 2493325.84
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 3118503.44
(sw_c, sw_fr) in bit/s: None, 2513956.32
(sw_c, sw_rl) in bit/s: None, 629246.79
(sw_c, sw_rr) in bit/s: None, 2494804.81
(sw_fr, sw_c) in bit/s: None, 2414371.71
(sw_fr, zc_fr) in bit/s: None, 2507638.77
(sw_rl, zc_rl) in bit/s: None, 628042.35
(sw_rr, sw_c) in bit/s: None, 1871113.91
(sw_rr, zc_rr) in bit/s: None, 2507642.65
----- 21. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 2493325.84
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 3118503.44
(sw_c, sw_fr) in bit/s: None, 2513956.32
(sw_c, sw_rl) in bit/s: None, 629246.79
(sw_c, sw_rr) in bit/s: None, 3116628.37
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 2507638.77
(sw_rl, zc_rl) in bit/s: None, 628042.35
(sw_rr, sw_c) in bit/s: None, 1871113.91
(sw_rr, zc_rr) in bit/s: None, 3132658.79
----- 22. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 2493325.84
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 3118503.44
(sw_c, sw_fr) in bit/s: None, 2513956.32
(sw_c, sw_rl) in bit/s: None, 629246.79
(sw_c, sw_rr) in bit/s: None, 3116628.37
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 2507638.77
(sw_rl, zc_rl) in bit/s: None, 628042.35
(sw_rr, sw_c) in bit/s: None, 1871113.91
(sw_rr, zc_rr) in bit/s: None, 3132658.79
----- 23. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 2493325.84
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 3118503.44
(sw_c, sw_fr) in bit/s: None, 2513956.32
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3116628.37
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 2507638.77
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 1871113.91
(sw_rr, zc_rr) in bit/s: None, 3132658.79
----- 24. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 2493325.84
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 3118503.44
(sw_c, sw_fr) in bit/s: None, 2513956.32
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3116628.37
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 2507638.77
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 1871113.91
(sw_rr, zc_rr) in bit/s: None, 3132658.79
----- 25. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 3114779.98
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 3742198.21
(sw_c, sw_fr) in bit/s: None, 2513956.32
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3116628.37
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 2507638.77
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 1871113.91
(sw_rr, zc_rr) in bit/s: None, 3132658.79
----- 26. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 3735461.70
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 4363256.63
(sw_c, sw_fr) in bit/s: None, 2513956.32
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3116628.37
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 2507638.77
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 2493302.74
(sw_rr, zc_rr) in bit/s: None, 3132658.79
----- 27. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 3735461.70
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 4363256.63
(sw_c, sw_fr) in bit/s: None, 3140536.13
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3116628.37
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 3132640.74
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 3132658.79
----- 28. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 3735461.70
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 4363256.63
(sw_c, sw_fr) in bit/s: None, 3140536.13
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3116628.37
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 3132640.74
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 3132658.79
----- 29. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 4355393.55
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 4983561.26
(sw_c, sw_fr) in bit/s: None, 3140536.13
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3116628.37
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 3132640.74
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 3132658.79
----- 30. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 4355393.55
(sw_fl, infotainment) in bit/s: None, 604662.94
(sw_c, sw_fl) in bit/s: None, 4983561.26
(sw_c, sw_fr) in bit/s: None, 3140536.13
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3116628.37
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 3132640.74
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 3132658.79
----- 31. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 4355393.55
(sw_fl, infotainment) in bit/s: None, 1208599.23
(sw_c, sw_fl) in bit/s: None, 4983561.26
(sw_c, sw_fr) in bit/s: None, 3140536.13
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3116628.37
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 3132640.74
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 3132658.79
----- 32. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.475ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 4355393.55
(sw_fl, infotainment) in bit/s: None, 1208599.23
(sw_c, sw_fl) in bit/s: None, 4983561.26
(sw_c, sw_fr) in bit/s: None, 3140536.13
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3739936.68
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 3132640.74
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 3756902.49
----- 33. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 4355393.55
(sw_fl, infotainment) in bit/s: None, 1208599.23
(sw_c, sw_fl) in bit/s: None, 4983561.26
(sw_c, sw_fr) in bit/s: None, 3140536.13
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3739936.68
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 3132640.74
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 3756902.49
----- 34. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.475ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.475ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 4974571.77
(sw_fl, infotainment) in bit/s: None, 1208599.23
(sw_c, sw_fl) in bit/s: None, 5606490.02
(sw_c, sw_fr) in bit/s: None, 3140536.13
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3739936.68
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 3132640.74
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 3756902.49
----- 35. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 4974571.77
(sw_fl, infotainment) in bit/s: None, 1208599.23
(sw_c, sw_fl) in bit/s: None, 5606490.02
(sw_c, sw_fr) in bit/s: None, 3140536.13
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3739936.68
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 3132640.74
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 3756902.49
----- 36. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.475ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.475ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.475ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 4974571.77
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 5606490.02
(sw_c, sw_fr) in bit/s: None, 3140536.13
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3739936.68
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 3132640.74
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 3756902.49
----- 37. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 4974571.77
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 5606490.02
(sw_c, sw_fr) in bit/s: None, 3140536.13
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3739936.68
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 3132640.74
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 3756902.49
----- 38. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr', 'zc_fl', 'infotainment', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.475ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.475ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.475ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.475ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 624449.75
(sw_fl, zc_fl) in bit/s: None, 4974571.77
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 5606490.02
(sw_c, sw_fr) in bit/s: None, 3768628.57
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3739936.68
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 3756879.95
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 3756902.49
----- 39. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1248144.08
(sw_fl, zc_fl) in bit/s: None, 4974571.77
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 5606490.02
(sw_c, sw_fr) in bit/s: None, 4396740.46
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3739936.68
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 4380396.39
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 3756902.49
----- 40. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1248144.08
(sw_fl, zc_fl) in bit/s: None, 4974571.77
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 5606490.02
(sw_c, sw_fr) in bit/s: None, 4396740.46
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 3739936.68
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 4380396.39
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 3756902.49
----- 41. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1248144.08
(sw_fl, zc_fl) in bit/s: None, 4974571.77
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 5606490.02
(sw_c, sw_fr) in bit/s: None, 4396740.46
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 4363264.28
(sw_fr, sw_c) in bit/s: None, 3016173.07
(sw_fr, zc_fr) in bit/s: None, 4380396.39
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 4380423.40
----- 42. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.479ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1248144.08
(sw_fl, zc_fl) in bit/s: None, 4974571.77
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 5606490.02
(sw_c, sw_fr) in bit/s: None, 4396740.46
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 4992584.70
(sw_fr, sw_c) in bit/s: None, 3617237.43
(sw_fr, zc_fr) in bit/s: None, 4380396.39
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 5003143.14
----- 43. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1248144.08
(sw_fl, zc_fl) in bit/s: None, 4974571.77
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 5606490.02
(sw_c, sw_fr) in bit/s: None, 4396740.46
(sw_c, sw_rl) in bit/s: None, 1258493.58
(sw_c, sw_rr) in bit/s: None, 4992584.70
(sw_fr, sw_c) in bit/s: None, 3617237.43
(sw_fr, zc_fr) in bit/s: None, 4380396.39
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1255318.34
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 5003143.14
----- 44. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.479ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.479ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1248144.08
(sw_fl, zc_fl) in bit/s: None, 4974571.77
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 5606490.02
(sw_c, sw_fr) in bit/s: None, 4396740.46
(sw_c, sw_rl) in bit/s: None, 1886585.30
(sw_c, sw_rr) in bit/s: None, 4992584.70
(sw_fr, sw_c) in bit/s: None, 3617237.43
(sw_fr, zc_fr) in bit/s: None, 4380396.39
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1881824.84
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 5003143.14
----- 45. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1248144.08
(sw_fl, zc_fl) in bit/s: None, 4974571.77
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 5606490.02
(sw_c, sw_fr) in bit/s: None, 4396740.46
(sw_c, sw_rl) in bit/s: None, 1886585.30
(sw_c, sw_rr) in bit/s: None, 4992584.70
(sw_fr, sw_c) in bit/s: None, 3617237.43
(sw_fr, zc_fr) in bit/s: None, 4380396.39
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1881824.84
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 5003143.14
----- 46. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.479ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.479ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.479ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1248144.08
(sw_fl, zc_fl) in bit/s: None, 5592987.53
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 6229413.64
(sw_c, sw_fr) in bit/s: None, 4396740.46
(sw_c, sw_rl) in bit/s: None, 1886585.30
(sw_c, sw_rr) in bit/s: None, 4992584.70
(sw_fr, sw_c) in bit/s: None, 3617237.43
(sw_fr, zc_fr) in bit/s: None, 4380396.39
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1881824.84
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 5003143.14
----- 47. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 5592987.53
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 6229413.64
(sw_c, sw_fr) in bit/s: None, 4396740.46
(sw_c, sw_rl) in bit/s: None, 1886585.30
(sw_c, sw_rr) in bit/s: None, 5606489.92
(sw_fr, sw_c) in bit/s: None, 3617237.43
(sw_fr, zc_fr) in bit/s: None, 4380396.39
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1881824.84
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 5625101.73
----- 48. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 5592987.53
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 6229413.64
(sw_c, sw_fr) in bit/s: None, 4396740.46
(sw_c, sw_rl) in bit/s: None, 1886585.30
(sw_c, sw_rr) in bit/s: None, 5606489.92
(sw_fr, sw_c) in bit/s: None, 3617237.43
(sw_fr, zc_fr) in bit/s: None, 4380396.39
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 1881824.84
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 5625101.73
----- 49. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 5592987.53
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 6229413.64
(sw_c, sw_fr) in bit/s: None, 4396740.46
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 5606489.92
(sw_fr, sw_c) in bit/s: None, 3617237.43
(sw_fr, zc_fr) in bit/s: None, 4380396.39
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 5625101.73
----- 50. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 5592987.53
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 6229413.64
(sw_c, sw_fr) in bit/s: None, 4396740.46
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 5606489.92
(sw_fr, sw_c) in bit/s: None, 3617237.43
(sw_fr, zc_fr) in bit/s: None, 4380396.39
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 5625101.73
----- 51. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_rl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 5592987.53
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 6229413.64
(sw_c, sw_fr) in bit/s: None, 5024829.02
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 5606489.92
(sw_fr, sw_c) in bit/s: None, 3617237.43
(sw_fr, zc_fr) in bit/s: None, 5003111.67
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 5625101.73
----- 52. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.159ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 6214402.65
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 6229413.64
(sw_c, sw_fr) in bit/s: None, 5024829.02
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 5606489.92
(sw_fr, sw_c) in bit/s: None, 3617237.43
(sw_fr, zc_fr) in bit/s: None, 5003111.67
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3114736.39
(sw_rr, zc_rr) in bit/s: None, 5625101.73
----- 53. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.479ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 6831687.75
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 6856482.47
(sw_c, sw_fr) in bit/s: None, 5024829.02
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 5606489.92
(sw_fr, sw_c) in bit/s: None, 3617237.43
(sw_fr, zc_fr) in bit/s: None, 5003111.67
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 5625101.73
----- 54. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.479ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 7448255.20
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 7470757.82
(sw_c, sw_fr) in bit/s: None, 5024829.02
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 5606489.92
(sw_fr, sw_c) in bit/s: None, 4217598.95
(sw_fr, zc_fr) in bit/s: None, 5003111.67
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 5625101.73
----- 55. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 7448255.20
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 7470757.82
(sw_c, sw_fr) in bit/s: None, 5024829.02
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 6236949.19
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 5003111.67
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 6246312.10
----- 56. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 7448255.20
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 7470757.82
(sw_c, sw_fr) in bit/s: None, 5024829.02
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 6236949.19
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 5003111.67
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 6246312.10
----- 57. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 5024829.02
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 6236949.19
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 5003111.67
(sw_rl, sw_c) in bit/s: None, 604662.94
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 6246312.10
----- 58. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 5652927.95
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 6236949.19
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 5625093.18
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 6246312.10
----- 59. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 5652927.95
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 6236949.19
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 5625093.18
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 6246312.10
----- 60. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 5652927.95
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 6848220.80
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 5625093.18
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 6866787.98
----- 61. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 5652927.95
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 6848220.80
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 5625093.18
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 6866787.98
----- 62. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 1871075.36
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 5652927.95
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 7484334.47
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 5625093.18
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 7486513.61
----- 63. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 2493255.25
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 6281026.88
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 7484334.47
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 6246321.71
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 7486513.61
----- 64. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 2493255.25
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 6281026.88
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 7484334.47
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 6246321.71
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 7486513.61
----- 65. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 2493255.25
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 6281026.88
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 8088458.27
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 6246321.71
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 8105490.36
----- 66. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3114673.15
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 6281026.88
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 8710629.29
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 6246321.71
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 8723691.96
----- 67. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3114673.15
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 6281026.88
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 8710629.29
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 6246321.71
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 8723691.96
----- 68. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3114673.15
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 1811810.20
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 6909119.32
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 8710629.29
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 6866777.31
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 8723691.96
----- 69. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.162ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3114673.15
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 6909119.32
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 8710629.29
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 6866777.31
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 8723691.96
----- 70. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3114673.15
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 6909119.32
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 8710629.29
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 6866777.31
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 8723691.96
----- 71. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.479ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.479ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3114673.15
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 7532635.06
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 8710629.29
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 7486464.39
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 8723691.96
----- 72. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3114673.15
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 7532635.06
(sw_c, sw_rl) in bit/s: None, 2515445.55
(sw_c, sw_rr) in bit/s: None, 8710629.29
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 7486464.39
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 2507563.26
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 8723691.96
----- 73. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.479ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.479ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.479ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3114673.15
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 7532635.06
(sw_c, sw_rl) in bit/s: None, 3144305.81
(sw_c, sw_rr) in bit/s: None, 8710629.29
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 7486464.39
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 3132535.02
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 8723691.96
----- 74. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3114673.15
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 7532635.06
(sw_c, sw_rl) in bit/s: None, 3144305.81
(sw_c, sw_rr) in bit/s: None, 8710629.29
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 7486464.39
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 3132535.02
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 8723691.96
----- 75. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.159ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3737601.96
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 8160343.20
(sw_c, sw_rl) in bit/s: None, 3144305.81
(sw_c, sw_rr) in bit/s: None, 8710629.29
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 8105411.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 3132535.02
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 8723691.96
----- 76. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3737601.96
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 8160343.20
(sw_c, sw_rl) in bit/s: None, 3144305.81
(sw_c, sw_rr) in bit/s: None, 8710629.29
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 8105411.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 3132535.02
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 8723691.96
----- 77. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.159ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3737601.96
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 8160343.20
(sw_c, sw_rl) in bit/s: None, 3144305.81
(sw_c, sw_rr) in bit/s: None, 9332800.31
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 8105411.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 3132535.02
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 9341143.20
----- 78. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3737601.96
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 8160343.20
(sw_c, sw_rl) in bit/s: None, 3144305.81
(sw_c, sw_rr) in bit/s: None, 9332800.31
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 8105411.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 3132535.02
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 9341143.20
----- 79. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr', 'zc_rr', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.159ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3737601.96
(sw_fl, zc_fl) in bit/s: None, 8064055.84
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 8160343.20
(sw_c, sw_rl) in bit/s: None, 3773167.36
(sw_c, sw_rr) in bit/s: None, 9332800.31
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 8105411.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 3756747.97
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 9341143.20
----- 80. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.160ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 3737601.96
(sw_fl, zc_fl) in bit/s: None, 8684340.57
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 8160343.20
(sw_c, sw_rl) in bit/s: None, 3773167.36
(sw_c, sw_rr) in bit/s: None, 9332800.31
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 8105411.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 3756747.97
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 9341143.20
----- 81. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 8684340.57
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 8160343.20
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 9332800.31
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 8105411.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 9341143.20
----- 82. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 8684340.57
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 8160343.20
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 9332800.31
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 8105411.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 9341143.20
----- 83. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 8684340.57
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 8788044.90
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 9332800.31
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 8723584.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 9341143.20
----- 84. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 8684340.57
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 8788044.90
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 9332800.31
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 8723584.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 9341143.20
----- 85. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 8684340.57
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8093307.50
(sw_c, sw_fr) in bit/s: None, 8788044.90
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 9954961.05
(sw_fr, sw_c) in bit/s: None, 4817231.23
(sw_fr, zc_fr) in bit/s: None, 8723584.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 9957820.02
----- 86. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.481ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 9299044.35
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8715867.88
(sw_c, sw_fr) in bit/s: None, 8788044.90
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 9954961.05
(sw_fr, sw_c) in bit/s: None, 5416162.38
(sw_fr, zc_fr) in bit/s: None, 8723584.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 9957820.02
----- 87. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 9299044.35
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8715867.88
(sw_c, sw_fr) in bit/s: None, 8788044.90
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 9954961.05
(sw_fr, sw_c) in bit/s: None, 5416162.38
(sw_fr, zc_fr) in bit/s: None, 8723584.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 9957820.02
----- 88. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.481ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.481ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 9299044.35
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 8715867.88
(sw_c, sw_fr) in bit/s: None, 8788044.90
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 10577146.41
(sw_fr, sw_c) in bit/s: None, 5416162.38
(sw_fr, zc_fr) in bit/s: None, 8723584.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 3735407.29
(sw_rr, zc_rr) in bit/s: None, 10573806.87
----- 89. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 9912980.33
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 9332772.99
(sw_c, sw_fr) in bit/s: None, 8788044.90
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 10577146.41
(sw_fr, sw_c) in bit/s: None, 5416162.38
(sw_fr, zc_fr) in bit/s: None, 8723584.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 10573806.87
----- 90. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 9912980.33
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 9332772.99
(sw_c, sw_fr) in bit/s: None, 8788044.90
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 10577146.41
(sw_fr, sw_c) in bit/s: None, 5416162.38
(sw_fr, zc_fr) in bit/s: None, 8723584.20
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 10573806.87
----- 91. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 9912980.33
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 9332772.99
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 10577146.41
(sw_fr, sw_c) in bit/s: None, 5416162.38
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 10573806.87
----- 92. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 9912980.33
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 9332772.99
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 11199307.24
(sw_fr, sw_c) in bit/s: None, 6014347.96
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 11188986.89
----- 93. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 9912980.33
(sw_fl, infotainment) in bit/s: None, 2415743.60
(sw_c, sw_fl) in bit/s: None, 9332772.99
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 11199307.24
(sw_fr, sw_c) in bit/s: None, 6014347.96
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 11188986.89
----- 94. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.481ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 9912980.33
(sw_fl, infotainment) in bit/s: None, 3017861.47
(sw_c, sw_fl) in bit/s: None, 9954933.26
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 11199307.24
(sw_fr, sw_c) in bit/s: None, 6014347.96
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 11188986.89
----- 95. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 9912980.33
(sw_fl, infotainment) in bit/s: None, 3017861.47
(sw_c, sw_fl) in bit/s: None, 9954933.26
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 11821470.64
(sw_fr, sw_c) in bit/s: None, 6611819.35
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 11803426.30
----- 96. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 9912980.33
(sw_fl, infotainment) in bit/s: None, 3017861.47
(sw_c, sw_fl) in bit/s: None, 9954933.26
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 11821470.64
(sw_fr, sw_c) in bit/s: None, 6611819.35
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 11803426.30
----- 97. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 10526155.43
(sw_fl, infotainment) in bit/s: None, 3017861.47
(sw_c, sw_fl) in bit/s: None, 10577096.60
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 11821470.64
(sw_fr, sw_c) in bit/s: None, 6611819.35
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 11803426.30
----- 98. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 10526155.43
(sw_fl, infotainment) in bit/s: None, 3017861.47
(sw_c, sw_fl) in bit/s: None, 10577096.60
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 11821470.64
(sw_fr, sw_c) in bit/s: None, 6611819.35
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 11803426.30
----- 99. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 10526155.43
(sw_fl, infotainment) in bit/s: None, 3619255.40
(sw_c, sw_fl) in bit/s: None, 10577096.60
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 11821470.64
(sw_fr, sw_c) in bit/s: None, 6611819.35
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 11803426.30
----- 100. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.483ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 10526155.43
(sw_fl, infotainment) in bit/s: None, 3619255.40
(sw_c, sw_fl) in bit/s: None, 10577096.60
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 12443634.05
(sw_fr, sw_c) in bit/s: None, 7208574.56
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 12417119.67
----- 101. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 10526155.43
(sw_fl, infotainment) in bit/s: None, 3619255.40
(sw_c, sw_fl) in bit/s: None, 10577096.60
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 12443634.05
(sw_fr, sw_c) in bit/s: None, 7208574.56
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 12417119.67
----- 102. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.483ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.483ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 11138586.20
(sw_fl, infotainment) in bit/s: None, 3619255.40
(sw_c, sw_fl) in bit/s: None, 11199259.95
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 12443634.05
(sw_fr, sw_c) in bit/s: None, 7208574.56
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 12417119.67
----- 103. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 11138586.20
(sw_fl, infotainment) in bit/s: None, 3619255.40
(sw_c, sw_fl) in bit/s: None, 11199259.95
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 13065805.15
(sw_fr, sw_c) in bit/s: None, 7804629.61
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 13030093.67
----- 104. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 11138586.20
(sw_fl, infotainment) in bit/s: None, 3619255.40
(sw_c, sw_fl) in bit/s: None, 11199259.95
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 13065805.15
(sw_fr, sw_c) in bit/s: None, 7804629.61
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 13030093.67
----- 105. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 11750294.21
(sw_fl, infotainment) in bit/s: None, 3619255.40
(sw_c, sw_fl) in bit/s: None, 11821431.00
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 13065805.15
(sw_fr, sw_c) in bit/s: None, 7804629.61
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4355328.33
(sw_rr, zc_rr) in bit/s: None, 13030093.67
----- 106. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 12361298.79
(sw_fl, infotainment) in bit/s: None, 3619255.40
(sw_c, sw_fl) in bit/s: None, 12413546.61
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 13065805.15
(sw_fr, sw_c) in bit/s: None, 7804629.61
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 13030093.67
----- 107. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 12361298.79
(sw_fl, infotainment) in bit/s: None, 3619255.40
(sw_c, sw_fl) in bit/s: None, 12413546.61
(sw_c, sw_fr) in bit/s: None, 9404322.33
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 13065805.15
(sw_fr, sw_c) in bit/s: None, 7804629.61
(sw_fr, zc_fr) in bit/s: None, 9341027.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 13030093.67
----- 108. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 12361298.79
(sw_fl, infotainment) in bit/s: None, 3619255.40
(sw_c, sw_fl) in bit/s: None, 12413546.61
(sw_c, sw_fr) in bit/s: None, 10031277.67
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 13065805.15
(sw_fr, sw_c) in bit/s: None, 7804629.61
(sw_fr, zc_fr) in bit/s: None, 9957753.23
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 13030093.67
----- 109. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.164ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 12361298.79
(sw_fl, infotainment) in bit/s: None, 4222461.04
(sw_c, sw_fl) in bit/s: None, 12413546.61
(sw_c, sw_fr) in bit/s: None, 10031277.67
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 13065805.15
(sw_fr, sw_c) in bit/s: None, 7804629.61
(sw_fr, zc_fr) in bit/s: None, 9957753.23
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 13030093.67
----- 110. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 12361298.79
(sw_fl, infotainment) in bit/s: None, 4222461.04
(sw_c, sw_fl) in bit/s: None, 12413546.61
(sw_c, sw_fr) in bit/s: None, 10031277.67
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 13065805.15
(sw_fr, sw_c) in bit/s: None, 7804629.61
(sw_fr, zc_fr) in bit/s: None, 9957753.23
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 13030093.67
----- 111. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 12361298.79
(sw_fl, infotainment) in bit/s: None, 4822784.81
(sw_c, sw_fl) in bit/s: None, 12413546.61
(sw_c, sw_fr) in bit/s: None, 10031277.67
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 13065805.15
(sw_fr, sw_c) in bit/s: None, 7804629.61
(sw_fr, zc_fr) in bit/s: None, 9957753.23
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 13030093.67
----- 112. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 12361298.79
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13057891.37
(sw_c, sw_fr) in bit/s: None, 10031277.67
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 13065805.15
(sw_fr, sw_c) in bit/s: None, 8400000.07
(sw_fr, zc_fr) in bit/s: None, 9957753.23
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 13030093.67
----- 113. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 12361298.79
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13057891.37
(sw_c, sw_fr) in bit/s: None, 10031277.67
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 13065805.15
(sw_fr, sw_c) in bit/s: None, 8400000.07
(sw_fr, zc_fr) in bit/s: None, 9957753.23
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 13030093.67
----- 114. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 12971569.69
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13057891.37
(sw_c, sw_fr) in bit/s: None, 10031277.67
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 13065805.15
(sw_fr, sw_c) in bit/s: None, 8400000.07
(sw_fr, zc_fr) in bit/s: None, 9957753.23
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 13030093.67
----- 115. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 12971569.69
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13057891.37
(sw_c, sw_fr) in bit/s: None, 10031277.67
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 13065805.15
(sw_fr, sw_c) in bit/s: None, 8400000.07
(sw_fr, zc_fr) in bit/s: None, 9957753.23
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 13030093.67
----- 116. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment', 'zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 12971569.69
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13057891.37
(sw_c, sw_fr) in bit/s: None, 10031277.67
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 13687989.10
(sw_fr, sw_c) in bit/s: None, 8400000.07
(sw_fr, zc_fr) in bit/s: None, 9957753.23
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 13642371.01
----- 117. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.485ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 12971569.69
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13057891.37
(sw_c, sw_fr) in bit/s: None, 10031277.67
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 14310173.05
(sw_fr, sw_c) in bit/s: None, 8994664.63
(sw_fr, zc_fr) in bit/s: None, 9957753.23
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 14253912.94
----- 118. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4357875.93
(sw_fl, zc_fl) in bit/s: None, 12971569.69
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13057891.37
(sw_c, sw_fr) in bit/s: None, 10031277.67
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 14310173.05
(sw_fr, sw_c) in bit/s: None, 8994664.63
(sw_fr, zc_fr) in bit/s: None, 9957753.23
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 14253912.94
----- 119. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.160ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4980425.65
(sw_fl, zc_fl) in bit/s: None, 12971569.69
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13057891.37
(sw_c, sw_fr) in bit/s: None, 10658218.84
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 14310173.05
(sw_fr, sw_c) in bit/s: None, 8994664.63
(sw_fr, zc_fr) in bit/s: None, 10573701.83
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 14253912.94
----- 120. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4980425.65
(sw_fl, zc_fl) in bit/s: None, 12971569.69
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13057891.37
(sw_c, sw_fr) in bit/s: None, 10658218.84
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 14310173.05
(sw_fr, sw_c) in bit/s: None, 8994664.63
(sw_fr, zc_fr) in bit/s: None, 10573701.83
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 14253912.94
----- 121. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.160ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 4980425.65
(sw_fl, zc_fl) in bit/s: None, 12971569.69
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13057891.37
(sw_c, sw_fr) in bit/s: None, 10658218.84
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 14869314.43
(sw_fr, sw_c) in bit/s: None, 8994664.63
(sw_fr, zc_fr) in bit/s: None, 10573701.83
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 14864672.48
----- 122. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.481ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 12971569.69
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13057891.37
(sw_c, sw_fr) in bit/s: None, 10658218.84
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 15488847.85
(sw_fr, sw_c) in bit/s: None, 8994664.63
(sw_fr, zc_fr) in bit/s: None, 10573701.83
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 15474695.17
----- 123. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 12971569.69
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13057891.37
(sw_c, sw_fr) in bit/s: None, 10658218.84
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 15488847.85
(sw_fr, sw_c) in bit/s: None, 8994664.63
(sw_fr, zc_fr) in bit/s: None, 10573701.83
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 15474695.17
----- 124. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.481ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.481ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 12971569.69
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13057891.37
(sw_c, sw_fr) in bit/s: None, 11285161.16
(sw_c, sw_rl) in bit/s: None, 4402027.18
(sw_c, sw_rr) in bit/s: None, 15488847.85
(sw_fr, sw_c) in bit/s: None, 8994664.63
(sw_fr, zc_fr) in bit/s: None, 11188904.19
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 4380189.33
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 15474695.17
----- 125. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 12971569.69
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13057891.37
(sw_c, sw_fr) in bit/s: None, 11285161.16
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 15488847.85
(sw_fr, sw_c) in bit/s: None, 9588575.54
(sw_fr, zc_fr) in bit/s: None, 11188904.19
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 15474695.17
----- 126. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 12971569.69
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13057891.37
(sw_c, sw_fr) in bit/s: None, 11285161.16
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 15488847.85
(sw_fr, sw_c) in bit/s: None, 9588575.54
(sw_fr, zc_fr) in bit/s: None, 11188904.19
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 15474695.17
----- 127. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 13581044.51
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13679675.25
(sw_c, sw_fr) in bit/s: None, 11285161.16
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 15488847.85
(sw_fr, sw_c) in bit/s: None, 9588575.54
(sw_fr, zc_fr) in bit/s: None, 11188904.19
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 15474695.17
----- 128. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 13581044.51
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13679675.25
(sw_c, sw_fr) in bit/s: None, 11285161.16
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 15488847.85
(sw_fr, sw_c) in bit/s: None, 9588575.54
(sw_fr, zc_fr) in bit/s: None, 11188904.19
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 15474695.17
----- 129. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 13581044.51
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 13679675.25
(sw_c, sw_fr) in bit/s: None, 11285161.16
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 16157102.63
(sw_fr, sw_c) in bit/s: None, 9588575.54
(sw_fr, zc_fr) in bit/s: None, 11188904.19
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 16083950.93
----- 130. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 14189773.37
(sw_fl, infotainment) in bit/s: None, 5422393.43
(sw_c, sw_fl) in bit/s: None, 14301456.15
(sw_c, sw_fr) in bit/s: None, 11285161.16
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 16157102.63
(sw_fr, sw_c) in bit/s: None, 10181770.11
(sw_fr, zc_fr) in bit/s: None, 11188904.19
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 16083950.93
----- 131. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.165ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 14189773.37
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 14301456.15
(sw_c, sw_fr) in bit/s: None, 11285161.16
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 16157102.63
(sw_fr, sw_c) in bit/s: None, 10181770.11
(sw_fr, zc_fr) in bit/s: None, 11188904.19
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 16083950.93
----- 132. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 14797931.98
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 14923293.94
(sw_c, sw_fr) in bit/s: None, 11285161.16
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 16157102.63
(sw_fr, sw_c) in bit/s: None, 10774386.95
(sw_fr, zc_fr) in bit/s: None, 11188904.19
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 4974510.67
(sw_rr, zc_rr) in bit/s: None, 16083950.93
----- 133. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.481ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 14797931.98
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 14923293.94
(sw_c, sw_fr) in bit/s: None, 11897647.67
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 16157102.63
(sw_fr, sw_c) in bit/s: None, 10774386.95
(sw_fr, zc_fr) in bit/s: None, 11803361.65
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 5592927.99
(sw_rr, zc_rr) in bit/s: None, 16083950.93
----- 134. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 14797931.98
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 14923293.94
(sw_c, sw_fr) in bit/s: None, 11897647.67
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 16778534.98
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 11803361.65
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 5592927.99
(sw_rr, zc_rr) in bit/s: None, 16692557.12
----- 135. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 14797931.98
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 14923293.94
(sw_c, sw_fr) in bit/s: None, 11897647.67
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 16778534.98
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 11803361.65
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 5592927.99
(sw_rr, zc_rr) in bit/s: None, 16692557.12
----- 136. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.481ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.481ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 15405232.51
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 15479492.47
(sw_c, sw_fr) in bit/s: None, 11897647.67
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 16778534.98
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 11803361.65
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 5592927.99
(sw_rr, zc_rr) in bit/s: None, 16692557.12
----- 137. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 15405232.51
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 15479492.47
(sw_c, sw_fr) in bit/s: None, 11897647.67
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 16778534.98
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 11803361.65
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 5592927.99
(sw_rr, zc_rr) in bit/s: None, 16692557.12
----- 138. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 16011849.84
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 16157113.99
(sw_c, sw_fr) in bit/s: None, 11897647.67
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 16778534.98
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 11803361.65
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 5592927.99
(sw_rr, zc_rr) in bit/s: None, 16692557.12
----- 139. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 5599573.36
(sw_fl, zc_fl) in bit/s: None, 16011849.84
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 16157113.99
(sw_c, sw_fr) in bit/s: None, 11897647.67
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 16778534.98
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 11803361.65
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 5592927.99
(sw_rr, zc_rr) in bit/s: None, 16692557.12
----- 140. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.165ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6217956.52
(sw_fl, zc_fl) in bit/s: None, 16011849.84
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 16157113.99
(sw_c, sw_fr) in bit/s: None, 12531418.07
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 16778534.98
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 12417043.50
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 5592927.99
(sw_rr, zc_rr) in bit/s: None, 16692557.12
----- 141. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6217956.52
(sw_fl, zc_fl) in bit/s: None, 16011849.84
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 16157113.99
(sw_c, sw_fr) in bit/s: None, 12531418.07
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 16778534.98
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 12417043.50
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 5592927.99
(sw_rr, zc_rr) in bit/s: None, 16692557.12
----- 142. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.165ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6217956.52
(sw_fl, zc_fl) in bit/s: None, 16011849.84
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 16157113.99
(sw_c, sw_fr) in bit/s: None, 12531418.07
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 17326527.30
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 12417043.50
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 5592927.99
(sw_rr, zc_rr) in bit/s: None, 17300332.93
----- 143. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6217956.52
(sw_fl, zc_fl) in bit/s: None, 16617661.39
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 16707747.44
(sw_c, sw_fr) in bit/s: None, 12531418.07
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 17326527.30
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 12417043.50
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 6210582.98
(sw_rr, zc_rr) in bit/s: None, 17300332.93
----- 144. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6217956.52
(sw_fl, zc_fl) in bit/s: None, 17222825.19
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 17326563.43
(sw_c, sw_fr) in bit/s: None, 12531418.07
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 17326527.30
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 12417043.50
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 6827519.89
(sw_rr, zc_rr) in bit/s: None, 17300332.93
----- 145. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6217956.52
(sw_fl, zc_fl) in bit/s: None, 17222825.19
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 17326563.43
(sw_c, sw_fr) in bit/s: None, 12531418.07
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 17326527.30
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 12417043.50
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 6827519.89
(sw_rr, zc_rr) in bit/s: None, 17300332.93
----- 146. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6217956.52
(sw_fl, zc_fl) in bit/s: None, 17222825.19
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 17326563.43
(sw_c, sw_fr) in bit/s: None, 13142029.40
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 17326527.30
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 13030055.73
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 6827519.89
(sw_rr, zc_rr) in bit/s: None, 17300332.93
----- 147. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6217956.52
(sw_fl, zc_fl) in bit/s: None, 17222825.19
(sw_fl, infotainment) in bit/s: None, 6025119.24
(sw_c, sw_fl) in bit/s: None, 17326563.43
(sw_c, sw_fr) in bit/s: None, 13142029.40
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 17326527.30
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 13030055.73
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 6827519.89
(sw_rr, zc_rr) in bit/s: None, 17300332.93
----- 148. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6217956.52
(sw_fl, zc_fl) in bit/s: None, 17222825.19
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 17326563.43
(sw_c, sw_fr) in bit/s: None, 13142029.40
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 17326527.30
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 13030055.73
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 6827519.89
(sw_rr, zc_rr) in bit/s: None, 17300332.93
----- 149. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6217956.52
(sw_fl, zc_fl) in bit/s: None, 17222825.19
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 17326563.43
(sw_c, sw_fr) in bit/s: None, 13142029.40
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 17326527.30
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 13030055.73
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 6827519.89
(sw_rr, zc_rr) in bit/s: None, 17300332.93
----- 150. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6217956.52
(sw_fl, zc_fl) in bit/s: None, 17222825.19
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 17326563.43
(sw_c, sw_fr) in bit/s: None, 13767814.31
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 17326527.30
(sw_fr, sw_c) in bit/s: None, 11366237.63
(sw_fr, zc_fr) in bit/s: None, 13642260.50
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 6827519.89
(sw_rr, zc_rr) in bit/s: None, 17300332.93
----- 151. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6217956.52
(sw_fl, zc_fl) in bit/s: None, 17827265.80
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 17999601.37
(sw_c, sw_fr) in bit/s: None, 13767814.31
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 17326527.30
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 13642260.50
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 6827519.89
(sw_rr, zc_rr) in bit/s: None, 17300332.93
----- 152. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6217956.52
(sw_fl, zc_fl) in bit/s: None, 17827265.80
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 17999601.37
(sw_c, sw_fr) in bit/s: None, 13767814.31
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 17326527.30
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 13642260.50
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 6827519.89
(sw_rr, zc_rr) in bit/s: None, 17300332.93
----- 153. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6217956.52
(sw_fl, zc_fl) in bit/s: None, 17827265.80
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 17999601.37
(sw_c, sw_fr) in bit/s: None, 13767814.31
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 18010469.80
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 13642260.50
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 6827519.89
(sw_rr, zc_rr) in bit/s: None, 17907479.17
----- 154. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr'] , Bits:  688 , Interval:  450.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6839741.16
(sw_fl, zc_fl) in bit/s: None, 17827265.80
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 17999601.37
(sw_c, sw_fr) in bit/s: None, 14393597.26
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 18010469.80
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 14253725.36
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 6827519.89
(sw_rr, zc_rr) in bit/s: None, 17907479.17
----- 155. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.161ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6839741.16
(sw_fl, zc_fl) in bit/s: None, 18441926.49
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 17999601.37
(sw_c, sw_fr) in bit/s: None, 14393597.26
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 18010469.80
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 14253725.36
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 6827519.89
(sw_rr, zc_rr) in bit/s: None, 17907479.17
----- 156. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.483ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6839741.16
(sw_fl, zc_fl) in bit/s: None, 19045218.77
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 18552983.43
(sw_c, sw_fr) in bit/s: None, 14393597.26
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 18010469.80
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 14253725.36
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 7443689.56
(sw_rr, zc_rr) in bit/s: None, 17907479.17
----- 157. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6839741.16
(sw_fl, zc_fl) in bit/s: None, 19045218.77
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 18552983.43
(sw_c, sw_fr) in bit/s: None, 14393597.26
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 18010469.80
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 14253725.36
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 7443689.56
(sw_rr, zc_rr) in bit/s: None, 17907479.17
----- 158. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.483ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.483ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6839741.16
(sw_fl, zc_fl) in bit/s: None, 19045218.77
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 18552983.43
(sw_c, sw_fr) in bit/s: None, 15010283.02
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 18010469.80
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 14864476.61
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 7443689.56
(sw_rr, zc_rr) in bit/s: None, 17907479.17
----- 159. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 6839741.16
(sw_fl, zc_fl) in bit/s: None, 19045218.77
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 18552983.43
(sw_c, sw_fr) in bit/s: None, 15010283.02
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 18010469.80
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 14864476.61
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 7443689.56
(sw_rr, zc_rr) in bit/s: None, 17907479.17
----- 160. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.165ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7457326.97
(sw_fl, zc_fl) in bit/s: None, 19045218.77
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 18552983.43
(sw_c, sw_fr) in bit/s: None, 15010283.02
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 18553591.34
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 14864476.61
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 7443689.56
(sw_rr, zc_rr) in bit/s: None, 18514987.55
----- 161. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7457326.97
(sw_fl, zc_fl) in bit/s: None, 19045218.77
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 18552983.43
(sw_c, sw_fr) in bit/s: None, 15010283.02
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 18553591.34
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 14864476.61
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 7443689.56
(sw_rr, zc_rr) in bit/s: None, 18514987.55
----- 162. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_rr', 'zc_fr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.165ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7457326.97
(sw_fl, zc_fl) in bit/s: None, 19045218.77
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 18552983.43
(sw_c, sw_fr) in bit/s: None, 15636103.74
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 18553591.34
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 15475447.46
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 7443689.56
(sw_rr, zc_rr) in bit/s: None, 18514987.55
----- 163. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7457326.97
(sw_fl, zc_fl) in bit/s: None, 19647786.88
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 19171393.41
(sw_c, sw_fr) in bit/s: None, 15636103.74
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 18553591.34
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 15475447.46
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 8059112.45
(sw_rr, zc_rr) in bit/s: None, 18514987.55
----- 164. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.485ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7457326.97
(sw_fl, zc_fl) in bit/s: None, 19647786.88
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 19171393.41
(sw_c, sw_fr) in bit/s: None, 16251673.66
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 18553591.34
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 16084723.15
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 8673767.94
(sw_rr, zc_rr) in bit/s: None, 18514987.55
----- 165. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7457326.97
(sw_fl, zc_fl) in bit/s: None, 19647786.88
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 19171393.41
(sw_c, sw_fr) in bit/s: None, 16251673.66
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 18553591.34
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 16084723.15
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 8673767.94
(sw_rr, zc_rr) in bit/s: None, 18514987.55
----- 166. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.485ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7457326.97
(sw_fl, zc_fl) in bit/s: None, 20249584.11
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 19789776.15
(sw_c, sw_fr) in bit/s: None, 16251673.66
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 18553591.34
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 16084723.15
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 8673767.94
(sw_rr, zc_rr) in bit/s: None, 18514987.55
----- 167. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.485ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7457326.97
(sw_fl, zc_fl) in bit/s: None, 20249584.11
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 19789776.15
(sw_c, sw_fr) in bit/s: None, 16876708.33
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: None, 18553591.34
(sw_fr, sw_c) in bit/s: None, 11957388.66
(sw_fr, zc_fr) in bit/s: None, 16693304.85
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 9287699.69
(sw_rr, zc_rr) in bit/s: None, 18514987.55
----- 168. Flow Operation -- add -----
Flow Details: Source:  camera_front , Destination:  ['adas'] , Bits:  11520 , Interval:  0.065 ms , Deadline:  10.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('camera_front', 'sw_fr', 0), ('sw_fr', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 5.304ms
Reservation Dependent Flow Delay: 3.996ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 7457326.97
(sw_fl, zc_fl) in bit/s: None, 20249584.11
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 19789776.15
(sw_c, sw_fr) in bit/s: None, 16876708.33
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: 317413286.83, 18838721.58
(sw_fr, sw_c) in bit/s: 185821579.24, 12107029.09
(sw_fr, zc_fr) in bit/s: None, 16693304.85
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 9287699.69
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 18514987.55
----- 169. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.483ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 20249584.11
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 19789776.15
(sw_c, sw_fr) in bit/s: None, 16876708.33
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: 317413286.83, 19466635.07
(sw_fr, sw_c) in bit/s: 185821579.24, 12107029.09
(sw_fr, zc_fr) in bit/s: None, 16693304.85
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 9287699.69
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19120656.43
----- 170. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 20249584.11
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 19789776.15
(sw_c, sw_fr) in bit/s: None, 16876708.33
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: 317413286.83, 19466635.07
(sw_fr, sw_c) in bit/s: 185821579.24, 12107029.09
(sw_fr, zc_fr) in bit/s: None, 16693304.85
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 9287699.69
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19120656.43
----- 171. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.485ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.485ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 20249584.11
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 19789776.15
(sw_c, sw_fr) in bit/s: None, 17501743.00
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: 317413286.83, 19466635.07
(sw_fr, sw_c) in bit/s: 185821579.24, 12107029.09
(sw_fr, zc_fr) in bit/s: None, 17301153.62
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 9287699.69
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19120656.43
----- 172. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.489ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 20249584.11
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 19789776.15
(sw_c, sw_fr) in bit/s: None, 17501743.00
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 17301153.62
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 9287699.69
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 173. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 20249584.11
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 19789776.15
(sw_c, sw_fr) in bit/s: None, 18126801.33
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 17908329.24
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 9900920.35
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 174. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 20249584.11
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 19789776.15
(sw_c, sw_fr) in bit/s: None, 18126801.33
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 17908329.24
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 9900920.35
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 175. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 20850768.20
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 20408220.16
(sw_c, sw_fr) in bit/s: None, 18126801.33
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 17908329.24
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 9900920.35
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 176. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 20850768.20
(sw_fl, infotainment) in bit/s: None, 6623692.48
(sw_c, sw_fl) in bit/s: None, 20408220.16
(sw_c, sw_fr) in bit/s: None, 18126801.33
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 17908329.24
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 9900920.35
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 177. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 20850768.20
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 20408220.16
(sw_c, sw_fr) in bit/s: None, 18126801.33
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 17908329.24
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 9900920.35
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 178. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 20850768.20
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 20408220.16
(sw_c, sw_fr) in bit/s: None, 18752048.88
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 18515262.34
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 10513673.31
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 179. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 20850768.20
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 20408220.16
(sw_c, sw_fr) in bit/s: None, 18752048.88
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 18515262.34
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 10513673.31
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 180. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 21451747.96
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 21026936.49
(sw_c, sw_fr) in bit/s: None, 18752048.88
(sw_c, sw_rl) in bit/s: None, 5027804.37
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 18515262.34
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5002870.39
(sw_rr, sw_c) in bit/s: None, 10513673.31
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 181. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 21451747.96
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 21026936.49
(sw_c, sw_fr) in bit/s: None, 18752048.88
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 18515262.34
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11125380.13
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 182. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 21451747.96
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 21026936.49
(sw_c, sw_fr) in bit/s: None, 18752048.88
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 18515262.34
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11125380.13
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 183. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 21451747.96
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 21026936.49
(sw_c, sw_fr) in bit/s: None, 19377069.36
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 19120902.87
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11125380.13
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 184. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 21451747.96
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 21026936.49
(sw_c, sw_fr) in bit/s: None, 19377069.36
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 19120902.87
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11125380.13
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 185. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fr', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 22051411.07
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 21645326.04
(sw_c, sw_fr) in bit/s: None, 19377069.36
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 19120902.87
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11125380.13
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 186. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8073880.64
(sw_fl, zc_fl) in bit/s: None, 22051411.07
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 21645326.04
(sw_c, sw_fr) in bit/s: None, 19377069.36
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 19120902.87
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11125380.13
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 187. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.161ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 8694906.90
(sw_fl, zc_fl) in bit/s: None, 22051411.07
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 21645326.04
(sw_c, sw_fr) in bit/s: None, 19941858.32
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20156072.22
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 19725813.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11125380.13
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 19725791.08
----- 188. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.483ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 22051411.07
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 21645326.04
(sw_c, sw_fr) in bit/s: None, 19941858.32
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20710636.42
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 19725813.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11125380.13
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20331275.15
----- 189. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.162ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 22663896.13
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 21645326.04
(sw_c, sw_fr) in bit/s: None, 19941858.32
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20710636.42
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 19725813.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11125380.13
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20331275.15
----- 190. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 22663896.13
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 21645326.04
(sw_c, sw_fr) in bit/s: None, 19941858.32
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20710636.42
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 19725813.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11125380.13
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20331275.15
----- 191. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 23262513.40
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 22263736.01
(sw_c, sw_fr) in bit/s: None, 19941858.32
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20710636.42
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 19725813.29
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11125380.13
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20331275.15
----- 192. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 23262513.40
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 22263736.01
(sw_c, sw_fr) in bit/s: None, 20615159.13
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20710636.42
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 20331298.06
(sw_rl, sw_c) in bit/s: None, 1208601.31
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11737086.92
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20331275.15
----- 193. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 23860414.66
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 22868373.47
(sw_c, sw_fr) in bit/s: None, 20615159.13
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20710636.42
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 20331298.06
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11737086.92
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20331275.15
----- 194. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 23860414.66
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 22868373.47
(sw_c, sw_fr) in bit/s: None, 20615159.13
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20710636.42
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 20331298.06
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11737086.92
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20331275.15
----- 195. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 23860414.66
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 22868373.47
(sw_c, sw_fr) in bit/s: None, 21176055.43
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20710636.42
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 20934832.41
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11737086.92
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20331275.15
----- 196. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 23860414.66
(sw_fl, infotainment) in bit/s: None, 7221553.50
(sw_c, sw_fl) in bit/s: None, 22868373.47
(sw_c, sw_fr) in bit/s: None, 21176055.43
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20710636.42
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 20934832.41
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11737086.92
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20331275.15
----- 197. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl', 'zc_fr', 'infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 23860414.66
(sw_fl, infotainment) in bit/s: None, 7818685.10
(sw_c, sw_fl) in bit/s: None, 22868373.47
(sw_c, sw_fr) in bit/s: None, 21176055.43
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20710636.42
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 20934832.41
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11737086.92
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20331275.15
----- 198. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl', 'zc_fr', 'infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 23860414.66
(sw_fl, infotainment) in bit/s: None, 7818685.10
(sw_c, sw_fl) in bit/s: None, 22868373.47
(sw_c, sw_fr) in bit/s: None, 21176055.43
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 20710636.42
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 20934832.41
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11737086.92
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20331275.15
----- 199. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl', 'zc_fr', 'infotainment', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.476ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 23860414.66
(sw_fl, infotainment) in bit/s: None, 7818685.10
(sw_c, sw_fl) in bit/s: None, 22868373.47
(sw_c, sw_fr) in bit/s: None, 21176055.43
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 21338164.63
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 20934832.41
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 11737086.92
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20934808.82
----- 200. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.489ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 23860414.66
(sw_fl, infotainment) in bit/s: None, 7818685.10
(sw_c, sw_fl) in bit/s: None, 22868373.47
(sw_c, sw_fr) in bit/s: None, 21864447.62
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 21338164.63
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 21537586.52
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20934808.82
----- 201. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 23860414.66
(sw_fl, infotainment) in bit/s: None, 7818685.10
(sw_c, sw_fl) in bit/s: None, 22868373.47
(sw_c, sw_fr) in bit/s: None, 21864447.62
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 21338164.63
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 21537586.52
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20934808.82
----- 202. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.489ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.489ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 7818685.10
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 21864447.62
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 21338164.63
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 21537586.52
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20934808.82
----- 203. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 7818685.10
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 21864447.62
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 21338164.63
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 21537586.52
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20934808.82
----- 204. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.489ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.489ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9310736.38
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 21864447.62
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 21338164.63
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 21537586.52
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 20934808.82
----- 205. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9925443.17
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 21864447.62
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 21965670.81
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 21537586.52
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 21537576.34
----- 206. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9925443.17
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 21864447.62
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 21965670.81
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 21537586.52
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 21537576.34
----- 207. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9925443.17
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 22408065.01
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 21965670.81
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 22139629.38
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 21537576.34
----- 208. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9925443.17
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 22408065.01
(sw_c, sw_rl) in bit/s: None, 5656278.53
(sw_c, sw_rr) in bit/s: 317413286.83, 21965670.81
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 22139629.38
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 5624790.40
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 21537576.34
----- 209. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 9925443.17
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 22408065.01
(sw_c, sw_rl) in bit/s: None, 6284752.72
(sw_c, sw_rr) in bit/s: 317413286.83, 21965670.81
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 22139629.38
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 6245950.75
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 21537576.34
----- 210. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.485ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 10539645.58
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 23030794.93
(sw_c, sw_rl) in bit/s: None, 6284752.72
(sw_c, sw_rr) in bit/s: 317413286.83, 21965670.81
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 22741663.28
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 6245950.75
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 21537576.34
----- 211. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 10539645.58
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 23030794.93
(sw_c, sw_rl) in bit/s: None, 6284752.72
(sw_c, sw_rr) in bit/s: 317413286.83, 21965670.81
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 22741663.28
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 6245950.75
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 21537576.34
----- 212. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.485ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.485ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 10539645.58
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 23030794.93
(sw_c, sw_rl) in bit/s: None, 6284752.72
(sw_c, sw_rr) in bit/s: 317413286.83, 22593529.32
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 22741663.28
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 6245950.75
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 22140314.58
----- 213. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 10539645.58
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 23030794.93
(sw_c, sw_rl) in bit/s: None, 6284752.72
(sw_c, sw_rr) in bit/s: 317413286.83, 22593529.32
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 22741663.28
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 6245950.75
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 22140314.58
----- 214. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.162ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11159553.90
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 23030794.93
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 22593529.32
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 22741663.28
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 22140314.58
----- 215. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11159553.90
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 23030794.93
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 22593529.32
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 22741663.28
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 22140314.58
----- 216. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.162ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11159553.90
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 23653177.96
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 22593529.32
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 23342324.99
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 22140314.58
----- 217. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11159553.90
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 23653177.96
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 22593529.32
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 23342324.99
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 22140314.58
----- 218. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.162ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.478ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.479ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11159553.90
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 23653177.96
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 23221057.52
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 23342324.99
(sw_rl, sw_c) in bit/s: None, 1811814.34
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 22741697.20
----- 219. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  60.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11159553.90
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 8415086.55
(sw_c, sw_fl) in bit/s: None, 23500528.73
(sw_c, sw_fr) in bit/s: None, 24275650.93
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 23221057.52
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 23942450.92
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 12347344.95
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 22741697.20
----- 220. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.489ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11159553.90
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 9010790.34
(sw_c, sw_fl) in bit/s: None, 24118938.71
(sw_c, sw_fr) in bit/s: None, 24275650.93
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 23221057.52
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 23942450.92
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 12956897.08
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 22741697.20
----- 221. Flow Operation -- remove -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  60.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11159553.90
(sw_fl, zc_fl) in bit/s: None, 24457543.71
(sw_fl, infotainment) in bit/s: None, 9010790.34
(sw_c, sw_fl) in bit/s: None, 24118938.71
(sw_c, sw_fr) in bit/s: None, 24275650.93
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 23221057.52
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 23942450.92
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 12956897.08
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 22741697.20
----- 222. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  60.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.477ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11159553.90
(sw_fl, zc_fl) in bit/s: None, 25054187.52
(sw_fl, infotainment) in bit/s: None, 9010790.34
(sw_c, sw_fl) in bit/s: None, 24692829.28
(sw_c, sw_fr) in bit/s: None, 24275650.93
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 23221057.52
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 23942450.92
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 12956897.08
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 22741697.20
----- 223. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.485ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 25054187.52
(sw_fl, infotainment) in bit/s: None, 9010790.34
(sw_c, sw_fl) in bit/s: None, 24692829.28
(sw_c, sw_fr) in bit/s: None, 24275650.93
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 23848556.36
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 23942450.92
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 12956897.08
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 23342298.67
----- 224. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.490ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 25054187.52
(sw_fl, infotainment) in bit/s: None, 9010790.34
(sw_c, sw_fl) in bit/s: None, 24692829.28
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 23848556.36
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 13565714.40
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 23342298.67
----- 225. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 25054187.52
(sw_fl, infotainment) in bit/s: None, 9010790.34
(sw_c, sw_fl) in bit/s: None, 24692829.28
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 23848556.36
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 13565714.40
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 23342298.67
----- 226. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.490ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.490ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 25649951.48
(sw_fl, infotainment) in bit/s: None, 9010790.34
(sw_c, sw_fl) in bit/s: None, 25355838.08
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 23848556.36
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 13565714.40
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 23342298.67
----- 227. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 25649951.48
(sw_fl, infotainment) in bit/s: None, 9010790.34
(sw_c, sw_fl) in bit/s: None, 25355838.08
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 23848556.36
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 13565714.40
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 23342298.67
----- 228. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.490ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.490ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.490ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 25649951.48
(sw_fl, infotainment) in bit/s: None, 9605782.94
(sw_c, sw_fl) in bit/s: None, 25355838.08
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 23848556.36
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 13565714.40
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 23342298.67
----- 229. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 25649951.48
(sw_fl, infotainment) in bit/s: None, 9605782.94
(sw_c, sw_fl) in bit/s: None, 25355838.08
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 23848556.36
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 13565714.40
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 23342298.67
----- 230. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['infotainment', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.490ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.490ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 26245004.55
(sw_fl, infotainment) in bit/s: None, 9605782.94
(sw_c, sw_fl) in bit/s: None, 25355838.08
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 23848556.36
(sw_fr, sw_c) in bit/s: 185821579.24, 12704858.10
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 13565714.40
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 23342298.67
----- 231. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.490ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 26245004.55
(sw_fl, infotainment) in bit/s: None, 9605782.94
(sw_c, sw_fl) in bit/s: None, 25355838.08
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 24490919.83
(sw_fr, sw_c) in bit/s: 185821579.24, 13301825.24
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 13565714.40
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 23942193.95
----- 232. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 26245004.55
(sw_fl, infotainment) in bit/s: None, 9605782.94
(sw_c, sw_fl) in bit/s: None, 25355838.08
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 24490919.83
(sw_fr, sw_c) in bit/s: 185821579.24, 13301825.24
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 13565714.40
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 23942193.95
----- 233. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.490ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.490ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 26839300.18
(sw_fl, infotainment) in bit/s: None, 9605782.94
(sw_c, sw_fl) in bit/s: None, 25911812.30
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 24490919.83
(sw_fr, sw_c) in bit/s: 185821579.24, 13301825.24
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 13565714.40
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 23942193.95
----- 234. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.491ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 26839300.18
(sw_fl, infotainment) in bit/s: None, 9605782.94
(sw_c, sw_fl) in bit/s: None, 25911812.30
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 25118867.22
(sw_fr, sw_c) in bit/s: 185821579.24, 13898144.70
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 13565714.40
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 24541498.02
----- 235. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.169ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 26839300.18
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 25911812.30
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 25118867.22
(sw_fr, sw_c) in bit/s: 185821579.24, 13898144.70
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 13565714.40
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 24541498.02
----- 236. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.491ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 26839300.18
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 25911812.30
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 13565714.40
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 237. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 26839300.18
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 25911812.30
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 13565714.40
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 238. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.491ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.491ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 27432934.11
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 26528730.26
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 13565714.40
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 239. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.491ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 28025860.96
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 27178315.15
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 14173798.23
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 240. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 28025860.96
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 27178315.15
(sw_c, sw_fr) in bit/s: None, 24942936.13
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 24541681.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 14173798.23
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 241. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.491ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.491ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 28025860.96
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 27178315.15
(sw_c, sw_fr) in bit/s: None, 25566452.92
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 25140195.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 14173798.23
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 242. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.491ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 28618081.98
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 27795978.37
(sw_c, sw_fr) in bit/s: None, 25566452.92
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 25140195.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 14781149.91
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 243. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 28618081.98
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 27795978.37
(sw_c, sw_fr) in bit/s: None, 25566452.92
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 25140195.08
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 14781149.91
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 244. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.491ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.491ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 28618081.98
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 27795978.37
(sw_c, sw_fr) in bit/s: None, 26189969.71
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 25737994.22
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 14781149.91
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 245. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 28618081.98
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 27795978.37
(sw_c, sw_fr) in bit/s: None, 26813467.20
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 26335028.04
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 246. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 28618081.98
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 27795978.37
(sw_c, sw_fr) in bit/s: None, 26813467.20
(sw_c, sw_rl) in bit/s: None, 6913229.51
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 26335028.04
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 6866365.63
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 247. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 28618081.98
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 27795978.37
(sw_c, sw_fr) in bit/s: None, 26813467.20
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 26335028.04
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 248. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 28618081.98
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 27795978.37
(sw_c, sw_fr) in bit/s: None, 26813467.20
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 26335028.04
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 249. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 29209545.98
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 28413618.64
(sw_c, sw_fr) in bit/s: None, 26813467.20
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 26335028.04
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 250. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 11772405.88
(sw_fl, zc_fl) in bit/s: None, 29209545.98
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 28413618.64
(sw_c, sw_fr) in bit/s: None, 26813467.20
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 26335028.04
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 251. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.169ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 12384624.54
(sw_fl, zc_fl) in bit/s: None, 29209545.98
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 28413618.64
(sw_c, sw_fr) in bit/s: None, 27322054.71
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 26931664.66
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 252. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 12384624.54
(sw_fl, zc_fl) in bit/s: None, 29209545.98
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 28413618.64
(sw_c, sw_fr) in bit/s: None, 27322054.71
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 25746780.05
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 26931664.66
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25140007.56
----- 253. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.169ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 12384624.54
(sw_fl, zc_fl) in bit/s: None, 29209545.98
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 28413618.64
(sw_c, sw_fr) in bit/s: None, 27322054.71
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 26310829.01
(sw_fr, sw_c) in bit/s: 185821579.24, 14493704.92
(sw_fr, zc_fr) in bit/s: None, 26931664.66
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 25738055.10
----- 254. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 12384624.54
(sw_fl, zc_fl) in bit/s: None, 29209545.98
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 28413618.64
(sw_c, sw_fr) in bit/s: None, 27322054.71
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 26986329.03
(sw_fr, sw_c) in bit/s: 185821579.24, 15088599.36
(sw_fr, zc_fr) in bit/s: None, 26931664.66
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26335228.30
----- 255. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.162ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 12384624.54
(sw_fl, zc_fl) in bit/s: None, 29818113.38
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 28413618.64
(sw_c, sw_fr) in bit/s: None, 27322054.71
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 26986329.03
(sw_fr, sw_c) in bit/s: 185821579.24, 15088599.36
(sw_fr, zc_fr) in bit/s: None, 26931664.66
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26335228.30
----- 256. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 12384624.54
(sw_fl, zc_fl) in bit/s: None, 29818113.38
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 28413618.64
(sw_c, sw_fr) in bit/s: None, 27322054.71
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 26986329.03
(sw_fr, sw_c) in bit/s: 185821579.24, 15088599.36
(sw_fr, zc_fr) in bit/s: None, 26931664.66
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26335228.30
----- 257. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 12384624.54
(sw_fl, zc_fl) in bit/s: None, 30408655.02
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 28944244.56
(sw_c, sw_fr) in bit/s: None, 27322054.71
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 26986329.03
(sw_fr, sw_c) in bit/s: 185821579.24, 15088599.36
(sw_fr, zc_fr) in bit/s: None, 26931664.66
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26335228.30
----- 258. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 12384624.54
(sw_fl, zc_fl) in bit/s: None, 30408655.02
(sw_fl, infotainment) in bit/s: None, 10206188.98
(sw_c, sw_fl) in bit/s: None, 28944244.56
(sw_c, sw_fr) in bit/s: None, 27322054.71
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 26986329.03
(sw_fr, sw_c) in bit/s: 185821579.24, 15088599.36
(sw_fr, zc_fr) in bit/s: None, 26931664.66
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26335228.30
----- 259. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 12384624.54
(sw_fl, zc_fl) in bit/s: None, 30408655.02
(sw_fl, infotainment) in bit/s: None, 10800146.24
(sw_c, sw_fl) in bit/s: None, 28944244.56
(sw_c, sw_fr) in bit/s: None, 27322054.71
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 26986329.03
(sw_fr, sw_c) in bit/s: 185821579.24, 15088599.36
(sw_fr, zc_fr) in bit/s: None, 26931664.66
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26335228.30
----- 260. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 12384624.54
(sw_fl, zc_fl) in bit/s: None, 30408655.02
(sw_fl, infotainment) in bit/s: None, 11393370.75
(sw_c, sw_fl) in bit/s: None, 29560048.42
(sw_c, sw_fr) in bit/s: None, 27322054.71
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 26986329.03
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 26931664.66
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15387740.70
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26335228.30
----- 261. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 12384624.54
(sw_fl, zc_fl) in bit/s: None, 30998498.89
(sw_fl, infotainment) in bit/s: None, 11393370.75
(sw_c, sw_fl) in bit/s: None, 30230310.59
(sw_c, sw_fr) in bit/s: None, 27322054.71
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 26986329.03
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 26931664.66
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15993682.88
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26335228.30
----- 262. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 12384624.54
(sw_fl, zc_fl) in bit/s: None, 30998498.89
(sw_fl, infotainment) in bit/s: None, 11393370.75
(sw_c, sw_fl) in bit/s: None, 30230310.59
(sw_c, sw_fr) in bit/s: None, 27322054.71
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 26986329.03
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 26931664.66
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15993682.88
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26335228.30
----- 263. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 12384624.54
(sw_fl, zc_fl) in bit/s: None, 30998498.89
(sw_fl, infotainment) in bit/s: None, 11393370.75
(sw_c, sw_fl) in bit/s: None, 30230310.59
(sw_c, sw_fr) in bit/s: None, 28043760.30
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 26986329.03
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 27527421.66
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15993682.88
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26335228.30
----- 264. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.170ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 12384624.54
(sw_fl, zc_fl) in bit/s: None, 30998498.89
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 30230310.59
(sw_c, sw_fr) in bit/s: None, 28043760.30
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 26986329.03
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 27527421.66
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15993682.88
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26335228.30
----- 265. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 30998498.89
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 30230310.59
(sw_c, sw_fr) in bit/s: None, 28546717.49
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 26986329.03
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 28122307.04
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15993682.88
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26335228.30
----- 266. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 30998498.89
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 30230310.59
(sw_c, sw_fr) in bit/s: None, 28546717.49
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 26986329.03
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 28122307.04
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15993682.88
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26335228.30
----- 267. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 30998498.89
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 30230310.59
(sw_c, sw_fr) in bit/s: None, 28546717.49
(sw_c, sw_rl) in bit/s: None, 7532468.70
(sw_c, sw_rr) in bit/s: 317413286.83, 27546871.81
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 28122307.04
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 7486012.10
(sw_rr, sw_c) in bit/s: None, 15993682.88
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26931534.35
----- 268. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 30998498.89
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 30230310.59
(sw_c, sw_fr) in bit/s: None, 28546717.49
(sw_c, sw_rl) in bit/s: None, 8160177.37
(sw_c, sw_rr) in bit/s: 317413286.83, 27546871.81
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 28122307.04
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8104918.39
(sw_rr, sw_c) in bit/s: None, 16598846.79
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26931534.35
----- 269. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 30998498.89
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 30230310.59
(sw_c, sw_fr) in bit/s: None, 28546717.49
(sw_c, sw_rl) in bit/s: None, 8160177.37
(sw_c, sw_rr) in bit/s: 317413286.83, 27546871.81
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 28122307.04
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8104918.39
(sw_rr, sw_c) in bit/s: None, 16598846.79
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26931534.35
----- 270. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 31587553.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 30847228.82
(sw_c, sw_fr) in bit/s: None, 28546717.49
(sw_c, sw_rl) in bit/s: None, 8160177.37
(sw_c, sw_rr) in bit/s: 317413286.83, 27546871.81
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 28122307.04
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8104918.39
(sw_rr, sw_c) in bit/s: None, 16598846.79
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26931534.35
----- 271. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 31587553.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 30847228.82
(sw_c, sw_fr) in bit/s: None, 28546717.49
(sw_c, sw_rl) in bit/s: None, 8160177.37
(sw_c, sw_rr) in bit/s: 317413286.83, 27546871.81
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 28122307.04
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8104918.39
(sw_rr, sw_c) in bit/s: None, 16598846.79
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26931534.35
----- 272. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 31587553.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 30847228.82
(sw_c, sw_fr) in bit/s: None, 29272407.06
(sw_c, sw_rl) in bit/s: None, 8160177.37
(sw_c, sw_rr) in bit/s: 317413286.83, 27546871.81
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 28716556.01
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8104918.39
(sw_rr, sw_c) in bit/s: None, 16598846.79
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26931534.35
----- 273. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 32176193.31
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 31464274.39
(sw_c, sw_fr) in bit/s: None, 29272407.06
(sw_c, sw_rl) in bit/s: None, 8160177.37
(sw_c, sw_rr) in bit/s: 317413286.83, 27546871.81
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 28716556.01
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8104918.39
(sw_rr, sw_c) in bit/s: None, 17203452.14
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26931534.35
----- 274. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.495ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 32176193.31
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 31464274.39
(sw_c, sw_fr) in bit/s: None, 29272407.06
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 27546871.81
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 28716556.01
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26931534.35
----- 275. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 32176193.31
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 31464274.39
(sw_c, sw_fr) in bit/s: None, 29272407.06
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 27546871.81
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 28716556.01
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26931534.35
----- 276. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.495ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.495ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 32763797.97
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32081167.16
(sw_c, sw_fr) in bit/s: None, 29272407.06
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 27546871.81
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 28716556.01
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26931534.35
----- 277. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 32763797.97
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32081167.16
(sw_c, sw_fr) in bit/s: None, 29272407.06
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 27546871.81
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 28716556.01
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26931534.35
----- 278. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.495ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.495ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.495ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 32763797.97
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32081167.16
(sw_c, sw_fr) in bit/s: None, 29895145.82
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 27546871.81
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 29310040.17
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26931534.35
----- 279. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 32763797.97
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32081167.16
(sw_c, sw_fr) in bit/s: None, 29895145.82
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 27546871.81
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 29310040.17
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26931534.35
----- 280. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 33350763.03
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32081167.16
(sw_c, sw_fr) in bit/s: None, 29895145.82
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 27546871.81
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 29310040.17
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26931534.35
----- 281. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 33350763.03
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32081167.16
(sw_c, sw_fr) in bit/s: None, 29895145.82
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 27546871.81
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 29310040.17
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 26931534.35
----- 282. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment', 'zc_fl', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13003758.48
(sw_fl, zc_fl) in bit/s: None, 33350763.03
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32081167.16
(sw_c, sw_fr) in bit/s: None, 29895145.82
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 28224192.12
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 29310040.17
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 27527198.34
----- 283. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13614778.06
(sw_fl, zc_fl) in bit/s: None, 33350763.03
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32081167.16
(sw_c, sw_fr) in bit/s: None, 30371807.64
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 28224192.12
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 29902874.76
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 27527198.34
----- 284. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13614778.06
(sw_fl, zc_fl) in bit/s: None, 33350763.03
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32081167.16
(sw_c, sw_fr) in bit/s: None, 30371807.64
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 28224192.12
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 29902874.76
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 27527198.34
----- 285. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13614778.06
(sw_fl, zc_fl) in bit/s: None, 33350763.03
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32081167.16
(sw_c, sw_fr) in bit/s: None, 30371807.64
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 28781395.11
(sw_fr, sw_c) in bit/s: 185821579.24, 15682733.13
(sw_fr, zc_fr) in bit/s: None, 29902874.76
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 28122152.57
----- 286. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13614778.06
(sw_fl, zc_fl) in bit/s: None, 33350763.03
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32081167.16
(sw_c, sw_fr) in bit/s: None, 30371807.64
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 29460689.54
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 29902874.76
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 28716680.30
----- 287. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13614778.06
(sw_fl, zc_fl) in bit/s: None, 33350763.03
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32081167.16
(sw_c, sw_fr) in bit/s: None, 30371807.64
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 29460689.54
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 29902874.76
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 28716680.30
----- 288. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13614778.06
(sw_fl, zc_fl) in bit/s: None, 33937335.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32561276.66
(sw_c, sw_fr) in bit/s: None, 30371807.64
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 29460689.54
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 29902874.76
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 28716680.30
----- 289. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 13614778.06
(sw_fl, zc_fl) in bit/s: None, 33937335.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32561276.66
(sw_c, sw_fr) in bit/s: None, 30371807.64
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 29460689.54
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 29902874.76
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 28716680.30
----- 290. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.163ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14233593.22
(sw_fl, zc_fl) in bit/s: None, 33937335.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32561276.66
(sw_c, sw_fr) in bit/s: None, 30991615.02
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 29460689.54
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 30495104.40
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 28716680.30
----- 291. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14233593.22
(sw_fl, zc_fl) in bit/s: None, 33937335.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32561276.66
(sw_c, sw_fr) in bit/s: None, 30991615.02
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 29460689.54
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 30495104.40
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 28716680.30
----- 292. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.163ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14233593.22
(sw_fl, zc_fl) in bit/s: None, 33937335.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32561276.66
(sw_c, sw_fr) in bit/s: None, 30991615.02
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 30014602.78
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 30495104.40
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29310320.51
----- 293. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14233593.22
(sw_fl, zc_fl) in bit/s: None, 33937335.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32561276.66
(sw_c, sw_fr) in bit/s: None, 30991615.02
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 30014602.78
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 30495104.40
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29310320.51
----- 294. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.170ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 33937335.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32561276.66
(sw_c, sw_fr) in bit/s: None, 31611326.44
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 30014602.78
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 31086451.36
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29310320.51
----- 295. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 33937335.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32561276.66
(sw_c, sw_fr) in bit/s: None, 31611326.44
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 30014602.78
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 31086451.36
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29310320.51
----- 296. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.170ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.487ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 33937335.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32561276.66
(sw_c, sw_fr) in bit/s: None, 31611326.44
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 31086451.36
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 17807134.72
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 297. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 33937335.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32561276.66
(sw_c, sw_fr) in bit/s: None, 32327856.47
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 31677175.92
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 18410126.67
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 298. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 33937335.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32561276.66
(sw_c, sw_fr) in bit/s: None, 32327856.47
(sw_c, sw_rl) in bit/s: None, 8787880.87
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 31677175.92
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 8723056.49
(sw_rr, sw_c) in bit/s: None, 18410126.67
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 299. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 33937335.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32561276.66
(sw_c, sw_fr) in bit/s: None, 32327856.47
(sw_c, sw_rl) in bit/s: None, 9415589.54
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 31677175.92
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9340459.69
(sw_rr, sw_c) in bit/s: None, 18410126.67
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 300. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 33937335.04
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 32561276.66
(sw_c, sw_fr) in bit/s: None, 32327856.47
(sw_c, sw_rl) in bit/s: None, 9415589.54
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 31677175.92
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9340459.69
(sw_rr, sw_c) in bit/s: None, 18410126.67
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 301. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.495ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 34522916.18
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 33295125.23
(sw_c, sw_fr) in bit/s: None, 32327856.47
(sw_c, sw_rl) in bit/s: None, 9415589.54
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 31677175.92
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9340459.69
(sw_rr, sw_c) in bit/s: None, 18410126.67
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 302. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 34522916.18
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 33295125.23
(sw_c, sw_fr) in bit/s: None, 32949529.09
(sw_c, sw_rl) in bit/s: None, 9415589.54
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 32267305.03
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9340459.69
(sw_rr, sw_c) in bit/s: None, 19012457.76
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 303. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 34522916.18
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 33295125.23
(sw_c, sw_fr) in bit/s: None, 32949529.09
(sw_c, sw_rl) in bit/s: None, 9415589.54
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 32267305.03
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9340459.69
(sw_rr, sw_c) in bit/s: None, 19012457.76
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 304. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 35107908.92
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 33911716.11
(sw_c, sw_fr) in bit/s: None, 32949529.09
(sw_c, sw_rl) in bit/s: None, 9415589.54
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 32267305.03
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9340459.69
(sw_rr, sw_c) in bit/s: None, 19012457.76
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 305. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 35107908.92
(sw_fl, infotainment) in bit/s: None, 11992963.48
(sw_c, sw_fl) in bit/s: None, 33911716.11
(sw_c, sw_fr) in bit/s: None, 32949529.09
(sw_c, sw_rl) in bit/s: None, 9415589.54
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 32267305.03
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9340459.69
(sw_rr, sw_c) in bit/s: None, 19012457.76
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 306. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 35107908.92
(sw_fl, infotainment) in bit/s: None, 12585152.64
(sw_c, sw_fl) in bit/s: None, 33911716.11
(sw_c, sw_fr) in bit/s: None, 32949529.09
(sw_c, sw_rl) in bit/s: None, 9415589.54
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16276313.76
(sw_fr, zc_fr) in bit/s: None, 32267305.03
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9340459.69
(sw_rr, sw_c) in bit/s: None, 19012457.76
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 307. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 35107908.92
(sw_fl, infotainment) in bit/s: None, 13176900.83
(sw_c, sw_fl) in bit/s: None, 34363741.04
(sw_c, sw_fr) in bit/s: None, 32949529.09
(sw_c, sw_rl) in bit/s: None, 9415589.54
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16869525.37
(sw_fr, zc_fr) in bit/s: None, 32267305.03
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9340459.69
(sw_rr, sw_c) in bit/s: None, 19012457.76
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 308. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 35107908.92
(sw_fl, infotainment) in bit/s: None, 13176900.83
(sw_c, sw_fl) in bit/s: None, 34363741.04
(sw_c, sw_fr) in bit/s: None, 33571133.28
(sw_c, sw_rl) in bit/s: None, 9415589.54
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16869525.37
(sw_fr, zc_fr) in bit/s: None, 32856566.37
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9340459.69
(sw_rr, sw_c) in bit/s: None, 19613968.55
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 309. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 35107908.92
(sw_fl, infotainment) in bit/s: None, 13176900.83
(sw_c, sw_fl) in bit/s: None, 34363741.04
(sw_c, sw_fr) in bit/s: None, 33571133.28
(sw_c, sw_rl) in bit/s: None, 9415589.54
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16869525.37
(sw_fr, zc_fr) in bit/s: None, 32856566.37
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9340459.69
(sw_rr, sw_c) in bit/s: None, 19613968.55
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 310. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 35107908.92
(sw_fl, infotainment) in bit/s: None, 13176900.83
(sw_c, sw_fl) in bit/s: None, 34363741.04
(sw_c, sw_fr) in bit/s: None, 33571133.28
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16869525.37
(sw_fr, zc_fr) in bit/s: None, 32856566.37
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 19613968.55
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 311. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 35107908.92
(sw_fl, infotainment) in bit/s: None, 13176900.83
(sw_c, sw_fl) in bit/s: None, 34363741.04
(sw_c, sw_fr) in bit/s: None, 33571133.28
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16869525.37
(sw_fr, zc_fr) in bit/s: None, 32856566.37
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 19613968.55
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 312. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 35692043.36
(sw_fl, infotainment) in bit/s: None, 13176900.83
(sw_c, sw_fl) in bit/s: None, 35124096.67
(sw_c, sw_fr) in bit/s: None, 33571133.28
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16869525.37
(sw_fr, zc_fr) in bit/s: None, 32856566.37
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 19613968.55
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 313. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 36275485.02
(sw_fl, infotainment) in bit/s: None, 13176900.83
(sw_c, sw_fl) in bit/s: None, 35740243.41
(sw_c, sw_fr) in bit/s: None, 33571133.28
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16869525.37
(sw_fr, zc_fr) in bit/s: None, 32856566.37
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 20214756.55
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 314. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 36275485.02
(sw_fl, infotainment) in bit/s: None, 13176900.83
(sw_c, sw_fl) in bit/s: None, 35740243.41
(sw_c, sw_fr) in bit/s: None, 33571133.28
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16869525.37
(sw_fr, zc_fr) in bit/s: None, 32856566.37
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 20214756.55
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 315. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 36275485.02
(sw_fl, infotainment) in bit/s: None, 13176900.83
(sw_c, sw_fl) in bit/s: None, 35740243.41
(sw_c, sw_fr) in bit/s: None, 34192737.46
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 317413286.83, 30639789.81
(sw_fr, sw_c) in bit/s: 185821579.24, 16869525.37
(sw_fr, zc_fr) in bit/s: None, 33445126.96
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 20214756.55
(sw_rr, adas) in bit/s: 400092059.90, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 316. Flow Operation -- add -----
Flow Details: Source:  lidar_fr , Destination:  ['adas'] , Bits:  7968 , Interval:  0.150 ms , Deadline:  10.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('lidar_fr', 'sw_fr', 0), ('sw_fr', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 5.304ms
Reservation Dependent Flow Delay: 3.978ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 36275485.02
(sw_fl, infotainment) in bit/s: None, 13176900.83
(sw_c, sw_fl) in bit/s: None, 35740243.41
(sw_c, sw_fr) in bit/s: None, 34192737.46
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 394991327.21, 30703014.10
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 33445126.96
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 20214756.55
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 317. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 36275485.02
(sw_fl, infotainment) in bit/s: None, 13176900.83
(sw_c, sw_fl) in bit/s: None, 35740243.41
(sw_c, sw_fr) in bit/s: None, 34814333.09
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 394991327.21, 30703014.10
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 34032965.80
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 20814809.45
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 318. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  160.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.499ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 36275485.02
(sw_fl, infotainment) in bit/s: None, 13176900.83
(sw_c, sw_fl) in bit/s: None, 35740243.41
(sw_c, sw_fr) in bit/s: None, 35435973.63
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 394991327.21, 30703014.10
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 34620224.37
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 21414214.95
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 319. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  160.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 36275485.02
(sw_fl, infotainment) in bit/s: None, 13176900.83
(sw_c, sw_fl) in bit/s: None, 35740243.41
(sw_c, sw_fr) in bit/s: None, 35435973.63
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 394991327.21, 30703014.10
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 34620224.37
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 21414214.95
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 320. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  160.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.499ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.499ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 36858328.83
(sw_fl, infotainment) in bit/s: None, 13176900.83
(sw_c, sw_fl) in bit/s: None, 36356429.80
(sw_c, sw_fr) in bit/s: None, 35435973.63
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 394991327.21, 30703014.10
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 34620224.37
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 21414214.95
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 321. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  160.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 36858328.83
(sw_fl, infotainment) in bit/s: None, 13176900.83
(sw_c, sw_fl) in bit/s: None, 36356429.80
(sw_c, sw_fr) in bit/s: None, 35435973.63
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 394991327.21, 30703014.10
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 34620224.37
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 21414214.95
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 322. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  160.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.499ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.499ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.499ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 36858328.83
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 36356429.80
(sw_c, sw_fr) in bit/s: None, 35435973.63
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 394991327.21, 30703014.10
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 34620224.37
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 21414214.95
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 323. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 36858328.83
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 36356429.80
(sw_c, sw_fr) in bit/s: None, 36057731.80
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 394991327.21, 30703014.10
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 35207105.29
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 22013103.05
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 324. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 36858328.83
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 36356429.80
(sw_c, sw_fr) in bit/s: None, 36679335.98
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 394991327.21, 30703014.10
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 35792883.31
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 325. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 36858328.83
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 36356429.80
(sw_c, sw_fr) in bit/s: None, 36679335.98
(sw_c, sw_rl) in bit/s: None, 10043293.04
(sw_c, sw_rr) in bit/s: 394991327.21, 30703014.10
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 35792883.31
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 9957094.93
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 326. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 14843475.12
(sw_fl, zc_fl) in bit/s: None, 36858328.83
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 36356429.80
(sw_c, sw_fr) in bit/s: None, 36679335.98
(sw_c, sw_rl) in bit/s: None, 10670996.53
(sw_c, sw_rr) in bit/s: 394991327.21, 30703014.10
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 35792883.31
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 10572980.18
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 327. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 15452965.65
(sw_fl, zc_fl) in bit/s: None, 36858328.83
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 36356429.80
(sw_c, sw_fr) in bit/s: None, 36679335.98
(sw_c, sw_rl) in bit/s: None, 11271258.98
(sw_c, sw_rr) in bit/s: 394991327.21, 30703014.10
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 35792883.31
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11188461.94
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 328. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 15452965.65
(sw_fl, zc_fl) in bit/s: None, 36858328.83
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 36356429.80
(sw_c, sw_fr) in bit/s: None, 36679335.98
(sw_c, sw_rl) in bit/s: None, 11271258.98
(sw_c, sw_rr) in bit/s: 394991327.21, 30703014.10
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 35792883.31
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11188461.94
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 329. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 15452965.65
(sw_fl, zc_fl) in bit/s: None, 36858328.83
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 36356429.80
(sw_c, sw_fr) in bit/s: None, 37012419.99
(sw_c, sw_rl) in bit/s: None, 11271258.98
(sw_c, sw_rr) in bit/s: 394991327.21, 30703014.10
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 36379106.55
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11188461.94
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 330. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 15452965.65
(sw_fl, zc_fl) in bit/s: None, 36858328.83
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 36356429.80
(sw_c, sw_fr) in bit/s: None, 37012419.99
(sw_c, sw_rl) in bit/s: None, 11271258.98
(sw_c, sw_rr) in bit/s: 394991327.21, 30703014.10
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 36379106.55
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11188461.94
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 29903082.43
----- 331. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.488ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 15452965.65
(sw_fl, zc_fl) in bit/s: None, 36858328.83
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 36356429.80
(sw_c, sw_fr) in bit/s: None, 37012419.99
(sw_c, sw_rl) in bit/s: None, 11271258.98
(sw_c, sw_rr) in bit/s: 394991327.21, 31329977.02
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 36379106.55
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11188461.94
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 30496114.39
----- 332. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 15452965.65
(sw_fl, zc_fl) in bit/s: None, 36858328.83
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 36356429.80
(sw_c, sw_fr) in bit/s: None, 37012419.99
(sw_c, sw_rl) in bit/s: None, 11271258.98
(sw_c, sw_rr) in bit/s: 394991327.21, 31329977.02
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 36379106.55
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11188461.94
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 30496114.39
----- 333. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: None, 15452965.65
(sw_fl, zc_fl) in bit/s: None, 37440390.24
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 36972576.54
(sw_c, sw_fr) in bit/s: None, 37012419.99
(sw_c, sw_rl) in bit/s: None, 11271258.98
(sw_c, sw_rr) in bit/s: 394991327.21, 31329977.02
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 36379106.55
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11188461.94
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 482178035.21, None
(sw_rr, zc_rr) in bit/s: None, 30496114.39
----- 334. Flow Operation -- add -----
Flow Details: Source:  lidar_fl , Destination:  ['adas'] , Bits:  7968 , Interval:  0.150 ms , Deadline:  10.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('lidar_fl', 'sw_fl', 0), ('sw_fl', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 5.304ms
Reservation Dependent Flow Delay: 3.993ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 15572192.86
(sw_fl, zc_fl) in bit/s: None, 37440390.24
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 36972576.54
(sw_c, sw_fr) in bit/s: None, 37012419.99
(sw_c, sw_rl) in bit/s: None, 11271258.98
(sw_c, sw_rr) in bit/s: 487768109.23, 31433343.66
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 36379106.55
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11188461.94
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 30496114.39
----- 335. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr'] , Bits:  688 , Interval:  150.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.481ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 16195008.72
(sw_fl, zc_fl) in bit/s: None, 37440390.24
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 36972576.54
(sw_c, sw_fr) in bit/s: None, 37629219.86
(sw_c, sw_rl) in bit/s: None, 11271258.98
(sw_c, sw_rr) in bit/s: 487768109.23, 31433343.66
(sw_fr, sw_c) in bit/s: 246526917.67, 16887480.38
(sw_fr, zc_fr) in bit/s: None, 36963627.19
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11188461.94
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 30496114.39
----- 336. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.495ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 16195008.72
(sw_fl, zc_fl) in bit/s: None, 38022001.86
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 37342474.93
(sw_c, sw_fr) in bit/s: None, 37629219.86
(sw_c, sw_rl) in bit/s: None, 11271258.98
(sw_c, sw_rr) in bit/s: 487768109.23, 31433343.66
(sw_fr, sw_c) in bit/s: 246526917.67, 17480209.24
(sw_fr, zc_fr) in bit/s: None, 36963627.19
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11188461.94
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 30496114.39
----- 337. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.489ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 16807701.85
(sw_fl, zc_fl) in bit/s: None, 38022001.86
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 37342474.93
(sw_c, sw_fr) in bit/s: None, 38245996.39
(sw_c, sw_rl) in bit/s: None, 11271258.98
(sw_c, sw_rr) in bit/s: 487768109.23, 31433343.66
(sw_fr, sw_c) in bit/s: 246526917.67, 17480209.24
(sw_fr, zc_fr) in bit/s: None, 37547418.36
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11188461.94
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 30496114.39
----- 338. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 16807701.85
(sw_fl, zc_fl) in bit/s: None, 38022001.86
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 37342474.93
(sw_c, sw_fr) in bit/s: None, 38245996.39
(sw_c, sw_rl) in bit/s: None, 11271258.98
(sw_c, sw_rr) in bit/s: 487768109.23, 31433343.66
(sw_fr, sw_c) in bit/s: 246526917.67, 17480209.24
(sw_fr, zc_fr) in bit/s: None, 37547418.36
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11188461.94
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 30496114.39
----- 339. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.495ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.495ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 16807701.85
(sw_fl, zc_fl) in bit/s: None, 38022001.86
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 37342474.93
(sw_c, sw_fr) in bit/s: None, 38245996.39
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 31433343.66
(sw_fr, sw_c) in bit/s: 246526917.67, 17480209.24
(sw_fr, zc_fr) in bit/s: None, 37547418.36
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 30496114.39
----- 340. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 16807701.85
(sw_fl, zc_fl) in bit/s: None, 38022001.86
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 37342474.93
(sw_c, sw_fr) in bit/s: None, 38245996.39
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 31433343.66
(sw_fr, sw_c) in bit/s: 246526917.67, 17480209.24
(sw_fr, zc_fr) in bit/s: None, 37547418.36
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 30496114.39
----- 341. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.489ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.489ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 16807701.85
(sw_fl, zc_fl) in bit/s: None, 38022001.86
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 37342474.93
(sw_c, sw_fr) in bit/s: None, 38245996.39
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 32061927.47
(sw_fr, sw_c) in bit/s: 246526917.67, 17480209.24
(sw_fr, zc_fr) in bit/s: None, 37547418.36
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 31087562.09
----- 342. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 16807701.85
(sw_fl, zc_fl) in bit/s: None, 38022001.86
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 37342474.93
(sw_c, sw_fr) in bit/s: None, 38245996.39
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 32061927.47
(sw_fr, sw_c) in bit/s: 246526917.67, 17480209.24
(sw_fr, zc_fr) in bit/s: None, 37547418.36
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 31087562.09
----- 343. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl', 'zc_rr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.495ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.495ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.495ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 16807701.85
(sw_fl, zc_fl) in bit/s: None, 38022001.86
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 37342474.93
(sw_c, sw_fr) in bit/s: None, 38245996.39
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 32690530.60
(sw_fr, sw_c) in bit/s: 246526917.67, 17480209.24
(sw_fr, zc_fr) in bit/s: None, 37547418.36
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 31678462.94
----- 344. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.481ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 17430126.55
(sw_fl, zc_fl) in bit/s: None, 38022001.86
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 37342474.93
(sw_c, sw_fr) in bit/s: None, 38862772.92
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 32690530.60
(sw_fr, sw_c) in bit/s: 246526917.67, 17480209.24
(sw_fr, zc_fr) in bit/s: None, 38130520.85
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 31678462.94
----- 345. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 17430126.55
(sw_fl, zc_fl) in bit/s: None, 38022001.86
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 37342474.93
(sw_c, sw_fr) in bit/s: None, 38862772.92
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 33319163.08
(sw_fr, sw_c) in bit/s: 246526917.67, 18072204.48
(sw_fr, zc_fr) in bit/s: None, 38130520.85
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 32268615.73
----- 346. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 17430126.55
(sw_fl, zc_fl) in bit/s: None, 38022001.86
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 37342474.93
(sw_c, sw_fr) in bit/s: None, 38862772.92
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 33947745.82
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 38130520.85
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 32857965.14
----- 347. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 17430126.55
(sw_fl, zc_fl) in bit/s: None, 38022001.86
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 37342474.93
(sw_c, sw_fr) in bit/s: None, 38862772.92
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 33947745.82
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 38130520.85
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 32857965.14
----- 348. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 17430126.55
(sw_fl, zc_fl) in bit/s: None, 38602759.72
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 37954593.81
(sw_c, sw_fr) in bit/s: None, 38862772.92
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 33947745.82
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 38130520.85
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 22611021.26
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 32857965.14
----- 349. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.501ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 17430126.55
(sw_fl, zc_fl) in bit/s: None, 38602759.72
(sw_fl, infotainment) in bit/s: None, 13767678.75
(sw_c, sw_fl) in bit/s: None, 37954593.81
(sw_c, sw_fr) in bit/s: None, 39692947.38
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 33947745.82
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 38714071.57
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 23208952.62
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 32857965.14
----- 350. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.173ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 17430126.55
(sw_fl, zc_fl) in bit/s: None, 38602759.72
(sw_fl, infotainment) in bit/s: None, 14366195.78
(sw_c, sw_fl) in bit/s: None, 37954593.81
(sw_c, sw_fr) in bit/s: None, 39692947.38
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 33947745.82
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 38714071.57
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 23208952.62
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 32857965.14
----- 351. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.491ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 38602759.72
(sw_fl, infotainment) in bit/s: None, 14366195.78
(sw_c, sw_fl) in bit/s: None, 37954593.81
(sw_c, sw_fr) in bit/s: None, 39692947.38
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 38714071.57
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 23208952.62
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 352. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 38602759.72
(sw_fl, infotainment) in bit/s: None, 14366195.78
(sw_c, sw_fl) in bit/s: None, 37954593.81
(sw_c, sw_fr) in bit/s: None, 39692947.38
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 38714071.57
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 23208952.62
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 353. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr', 'zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.490ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.491ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 38602759.72
(sw_fl, infotainment) in bit/s: None, 14366195.78
(sw_c, sw_fl) in bit/s: None, 37954593.81
(sw_c, sw_fr) in bit/s: None, 40073711.08
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 39296969.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 23208952.62
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 354. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.174ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 38602759.72
(sw_fl, infotainment) in bit/s: None, 14964845.83
(sw_c, sw_fl) in bit/s: None, 37954593.81
(sw_c, sw_fr) in bit/s: None, 40073711.08
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 39296969.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 23208952.62
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 355. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.175ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 38602759.72
(sw_fl, infotainment) in bit/s: None, 15563390.87
(sw_c, sw_fl) in bit/s: None, 37954593.81
(sw_c, sw_fr) in bit/s: None, 40073711.08
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 39296969.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 23208952.62
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 356. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 38602759.72
(sw_fl, infotainment) in bit/s: None, 15563390.87
(sw_c, sw_fl) in bit/s: None, 37954593.81
(sw_c, sw_fr) in bit/s: None, 40073711.08
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 39296969.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 23208952.62
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 357. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.501ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.501ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 39183186.18
(sw_fl, infotainment) in bit/s: None, 15563390.87
(sw_c, sw_fl) in bit/s: None, 38774804.99
(sw_c, sw_fr) in bit/s: None, 40073711.08
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 39296969.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 23208952.62
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 358. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 39183186.18
(sw_fl, infotainment) in bit/s: None, 15563390.87
(sw_c, sw_fl) in bit/s: None, 38774804.99
(sw_c, sw_fr) in bit/s: None, 40073711.08
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 39296969.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 23208952.62
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 359. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.501ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.501ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.501ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 39183186.18
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 38774804.99
(sw_c, sw_fr) in bit/s: None, 40073711.08
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 39296969.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 23208952.62
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 360. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 39762761.25
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 39390314.47
(sw_c, sw_fr) in bit/s: None, 40073711.08
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 39296969.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 23805621.97
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 361. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 39762761.25
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 39390314.47
(sw_c, sw_fr) in bit/s: None, 40073711.08
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 39296969.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 23805621.97
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 362. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 39762761.25
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 39390314.47
(sw_c, sw_fr) in bit/s: None, 40909241.45
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 39878241.31
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 23805621.97
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 363. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 39762761.25
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 39390314.47
(sw_c, sw_fr) in bit/s: None, 40909241.45
(sw_c, sw_rl) in bit/s: None, 11897462.91
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 39878241.31
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 11802950.98
(sw_rr, sw_c) in bit/s: None, 23805621.97
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 364. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 39762761.25
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 39390314.47
(sw_c, sw_fr) in bit/s: None, 40909241.45
(sw_c, sw_rl) in bit/s: None, 12546571.07
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 39878241.31
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 12416702.75
(sw_rr, sw_c) in bit/s: None, 23805621.97
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 365. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 39762761.25
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 39390314.47
(sw_c, sw_fr) in bit/s: None, 41529075.17
(sw_c, sw_rl) in bit/s: None, 12546571.07
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 40458834.80
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 12416702.75
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 366. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 39762761.25
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 39390314.47
(sw_c, sw_fr) in bit/s: None, 41529075.17
(sw_c, sw_rl) in bit/s: None, 12546571.07
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 40458834.80
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 12416702.75
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 367. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 39762761.25
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 39390314.47
(sw_c, sw_fr) in bit/s: None, 41529075.17
(sw_c, sw_rl) in bit/s: None, 13173912.52
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 40458834.80
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13029718.54
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 368. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 39762761.25
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 39390314.47
(sw_c, sw_fr) in bit/s: None, 41529075.17
(sw_c, sw_rl) in bit/s: None, 13173912.52
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 40458834.80
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13029718.54
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 369. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 40341659.85
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 40005823.96
(sw_c, sw_fr) in bit/s: None, 41529075.17
(sw_c, sw_rl) in bit/s: None, 13173912.52
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 40458834.80
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13029718.54
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 370. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18042055.47
(sw_fl, zc_fl) in bit/s: None, 40341659.85
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 40005823.96
(sw_c, sw_fr) in bit/s: None, 41529075.17
(sw_c, sw_rl) in bit/s: None, 13173912.52
(sw_c, sw_rr) in bit/s: 487768109.23, 34513814.02
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 40458834.80
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13029718.54
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 33447599.89
----- 371. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.175ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18652899.78
(sw_fl, zc_fl) in bit/s: None, 40341659.85
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 40005823.96
(sw_c, sw_fr) in bit/s: None, 41529075.17
(sw_c, sw_rl) in bit/s: None, 13173912.52
(sw_c, sw_rr) in bit/s: 487768109.23, 35141240.97
(sw_fr, sw_c) in bit/s: 246526917.67, 18663433.91
(sw_fr, zc_fr) in bit/s: None, 40458834.80
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13029718.54
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 34035570.50
----- 372. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18652899.78
(sw_fl, zc_fl) in bit/s: None, 40341659.85
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 40005823.96
(sw_c, sw_fr) in bit/s: None, 41529075.17
(sw_c, sw_rl) in bit/s: None, 13173912.52
(sw_c, sw_rr) in bit/s: 487768109.23, 35790826.05
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 40458834.80
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13029718.54
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 34623862.97
----- 373. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18652899.78
(sw_fl, zc_fl) in bit/s: None, 40341659.85
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 40005823.96
(sw_c, sw_fr) in bit/s: None, 41529075.17
(sw_c, sw_rl) in bit/s: None, 13173912.52
(sw_c, sw_rr) in bit/s: 487768109.23, 35790826.05
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 40458834.80
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13029718.54
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 34623862.97
----- 374. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18652899.78
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 41529075.17
(sw_c, sw_rl) in bit/s: None, 13173912.52
(sw_c, sw_rr) in bit/s: 487768109.23, 35790826.05
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 40458834.80
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13029718.54
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 34623862.97
----- 375. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18652899.78
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 16152503.62
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 41529075.17
(sw_c, sw_rl) in bit/s: None, 13173912.52
(sw_c, sw_rr) in bit/s: 487768109.23, 35790826.05
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 40458834.80
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13029718.54
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 34623862.97
----- 376. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18652899.78
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 16741158.57
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 41529075.17
(sw_c, sw_rl) in bit/s: None, 13173912.52
(sw_c, sw_rr) in bit/s: 487768109.23, 35790826.05
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 40458834.80
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13029718.54
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 34623862.97
----- 377. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.175ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18652899.78
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 41529075.17
(sw_c, sw_rl) in bit/s: None, 13173912.52
(sw_c, sw_rr) in bit/s: 487768109.23, 35790826.05
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 40458834.80
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13029718.54
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 34623862.97
----- 378. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 18652899.78
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 41529075.17
(sw_c, sw_rl) in bit/s: None, 13173912.52
(sw_c, sw_rr) in bit/s: 487768109.23, 35790826.05
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 40458834.80
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13029718.54
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 34623862.97
----- 379. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.175ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.492ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 19262966.70
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 41873254.16
(sw_c, sw_rl) in bit/s: None, 13173912.52
(sw_c, sw_rr) in bit/s: 487768109.23, 35790826.05
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 41038443.87
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13029718.54
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 34623862.97
----- 380. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 19872298.79
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 42488875.20
(sw_c, sw_rl) in bit/s: None, 13173912.52
(sw_c, sw_rr) in bit/s: 487768109.23, 35790826.05
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 41617395.58
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13029718.54
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 34623862.97
----- 381. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 19872298.79
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 42488875.20
(sw_c, sw_rl) in bit/s: None, 13173912.52
(sw_c, sw_rr) in bit/s: 487768109.23, 35790826.05
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 41617395.58
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13029718.54
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 34623862.97
----- 382. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 19872298.79
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 42488875.20
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 35790826.05
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 41617395.58
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 34623862.97
----- 383. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 19872298.79
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 42488875.20
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 35790826.05
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 41617395.58
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 34623862.97
----- 384. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.176ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 19872298.79
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 42488875.20
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 36374446.09
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 41617395.58
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 35210367.58
----- 385. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 19872298.79
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 42488875.20
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 36374446.09
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 41617395.58
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 35210367.58
----- 386. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.493ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 19872298.79
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 42488875.20
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 37001453.13
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 41617395.58
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 35796198.90
----- 387. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 20480966.00
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 43104618.24
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 37001453.13
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 42195884.40
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 35796198.90
----- 388. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 20480966.00
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 43104618.24
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 37001453.13
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 42195884.40
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 35796198.90
----- 389. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 20480966.00
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 43104618.24
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 37628553.36
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 42195884.40
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 36381525.52
----- 390. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 20480966.00
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 43104618.24
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 37628553.36
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 42195884.40
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 36381525.52
----- 391. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.177ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21088999.52
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 43720513.80
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 37628553.36
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 42773975.91
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 36381525.52
----- 392. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21088999.52
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 43720513.80
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 37628553.36
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 42773975.91
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 36381525.52
----- 393. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.177ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21088999.52
(sw_fl, zc_fl) in bit/s: None, 40920807.42
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 43720513.80
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 38255770.08
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 42773975.91
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 36966405.91
----- 394. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.165ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21088999.52
(sw_fl, zc_fl) in bit/s: None, 41522482.86
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 43720513.80
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 38255770.08
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 42773975.91
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 36966405.91
----- 395. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 41522482.86
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 44336180.59
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 38255770.08
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 43350977.76
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 36966405.91
----- 396. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 41522482.86
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 44336180.59
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 38255770.08
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 43350977.76
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 36966405.91
----- 397. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.494ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.495ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 41522482.86
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 44336180.59
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 38882812.07
(sw_fr, sw_c) in bit/s: 246526917.67, 19254522.37
(sw_fr, zc_fr) in bit/s: None, 43350977.76
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 37550240.05
----- 398. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 41522482.86
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 44336180.59
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 39439149.20
(sw_fr, sw_c) in bit/s: 246526917.67, 19845588.87
(sw_fr, zc_fr) in bit/s: None, 43350977.76
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38135748.14
----- 399. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 41522482.86
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40332079.05
(sw_c, sw_fr) in bit/s: None, 44336180.59
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 39439149.20
(sw_fr, sw_c) in bit/s: 246526917.67, 19845588.87
(sw_fr, zc_fr) in bit/s: None, 43350977.76
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38135748.14
----- 400. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 42101879.71
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40944538.63
(sw_c, sw_fr) in bit/s: None, 44336180.59
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 39439149.20
(sw_fr, sw_c) in bit/s: 246526917.67, 19845588.87
(sw_fr, zc_fr) in bit/s: None, 43350977.76
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24401585.74
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38135748.14
----- 401. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  2000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 42101879.71
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40944538.63
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 39439149.20
(sw_fr, sw_c) in bit/s: 246526917.67, 19845588.87
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24996648.72
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38135748.14
----- 402. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  2000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 42101879.71
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40944538.63
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 13759292.54
(sw_c, sw_rr) in bit/s: 487768109.23, 39439149.20
(sw_fr, sw_c) in bit/s: 246526917.67, 19845588.87
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 13641906.88
(sw_rr, sw_c) in bit/s: None, 24996648.72
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38135748.14
----- 403. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  2000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 42101879.71
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40944538.63
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 14419753.43
(sw_c, sw_rr) in bit/s: 487768109.23, 39439149.20
(sw_fr, sw_c) in bit/s: 246526917.67, 19845588.87
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14253339.42
(sw_rr, sw_c) in bit/s: None, 24996648.72
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38135748.14
----- 404. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  2000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 42101879.71
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 40944538.63
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 14419753.43
(sw_c, sw_rr) in bit/s: 487768109.23, 39439149.20
(sw_fr, sw_c) in bit/s: 246526917.67, 19845588.87
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14253339.42
(sw_rr, sw_c) in bit/s: None, 24996648.72
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38135748.14
----- 405. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  2000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 42678144.02
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 41803474.45
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 14419753.43
(sw_c, sw_rr) in bit/s: 487768109.23, 39439149.20
(sw_fr, sw_c) in bit/s: 246526917.67, 19845588.87
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14253339.42
(sw_rr, sw_c) in bit/s: None, 24996648.72
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38135748.14
----- 406. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 43253843.90
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 42141511.64
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 14419753.43
(sw_c, sw_rr) in bit/s: 487768109.23, 39439149.20
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14253339.42
(sw_rr, sw_c) in bit/s: None, 24996648.72
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38135748.14
----- 407. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 43253843.90
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 42141511.64
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 14419753.43
(sw_c, sw_rr) in bit/s: 487768109.23, 39439149.20
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14253339.42
(sw_rr, sw_c) in bit/s: None, 24996648.72
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38135748.14
----- 408. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 43253843.90
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 42141511.64
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 15000984.16
(sw_c, sw_rr) in bit/s: 487768109.23, 39439149.20
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14864073.62
(sw_rr, sw_c) in bit/s: None, 24996648.72
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38135748.14
----- 409. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 43253843.90
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 42141511.64
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 15000984.16
(sw_c, sw_rr) in bit/s: 487768109.23, 39439149.20
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14864073.62
(sw_rr, sw_c) in bit/s: None, 24996648.72
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38135748.14
----- 410. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 43253843.90
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 42141511.64
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 15000984.16
(sw_c, sw_rr) in bit/s: 487768109.23, 40065038.64
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14864073.62
(sw_rr, sw_c) in bit/s: None, 24996648.72
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38718241.23
----- 411. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.504ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 43828998.54
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 43007239.31
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 15000984.16
(sw_c, sw_rr) in bit/s: 487768109.23, 40065038.64
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14864073.62
(sw_rr, sw_c) in bit/s: None, 25591158.48
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38718241.23
----- 412. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.504ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 44403482.26
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 43621619.89
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 15000984.16
(sw_c, sw_rr) in bit/s: 487768109.23, 40065038.64
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14864073.62
(sw_rr, sw_c) in bit/s: None, 26184964.48
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38718241.23
----- 413. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 21696151.86
(sw_fl, zc_fl) in bit/s: None, 44403482.26
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 43621619.89
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 15000984.16
(sw_c, sw_rr) in bit/s: 487768109.23, 40065038.64
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14864073.62
(sw_rr, sw_c) in bit/s: None, 26184964.48
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 38718241.23
----- 414. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.177ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.495ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22302622.98
(sw_fl, zc_fl) in bit/s: None, 44403482.26
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 43621619.89
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 15000984.16
(sw_c, sw_rr) in bit/s: 487768109.23, 40715678.80
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14864073.62
(sw_rr, sw_c) in bit/s: None, 26184964.48
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 39300175.95
----- 415. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22302622.98
(sw_fl, zc_fl) in bit/s: None, 44403482.26
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 43621619.89
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 15000984.16
(sw_c, sw_rr) in bit/s: 487768109.23, 40715678.80
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14864073.62
(sw_rr, sw_c) in bit/s: None, 26184964.48
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 39300175.95
----- 416. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.165ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 44403482.26
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 43621619.89
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 15000984.16
(sw_c, sw_rr) in bit/s: 487768109.23, 41341952.15
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14864073.62
(sw_rr, sw_c) in bit/s: None, 26184964.48
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 39881299.23
----- 417. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.505ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 44977564.54
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 44236114.61
(sw_c, sw_fr) in bit/s: None, 45112696.73
(sw_c, sw_rl) in bit/s: None, 15000984.16
(sw_c, sw_rr) in bit/s: 487768109.23, 41341952.15
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 43927174.44
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14864073.62
(sw_rr, sw_c) in bit/s: None, 26778243.31
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 39881299.23
----- 418. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.506ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 44977564.54
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 44236114.61
(sw_c, sw_fr) in bit/s: None, 45731797.82
(sw_c, sw_rl) in bit/s: None, 15000984.16
(sw_c, sw_rr) in bit/s: 487768109.23, 41341952.15
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 44505568.54
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14864073.62
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 39881299.23
----- 419. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 44977564.54
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 44236114.61
(sw_c, sw_fr) in bit/s: None, 45731797.82
(sw_c, sw_rl) in bit/s: None, 15000984.16
(sw_c, sw_rr) in bit/s: 487768109.23, 41341952.15
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 44505568.54
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14864073.62
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 39881299.23
----- 420. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rr', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.165ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 44977564.54
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 44236114.61
(sw_c, sw_fr) in bit/s: None, 46129719.19
(sw_c, sw_rl) in bit/s: None, 15000984.16
(sw_c, sw_rr) in bit/s: 487768109.23, 41341952.15
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 45080576.50
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14864073.62
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 39881299.23
----- 421. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rr', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 44977564.54
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 44236114.61
(sw_c, sw_fr) in bit/s: None, 46129719.19
(sw_c, sw_rl) in bit/s: None, 15000984.16
(sw_c, sw_rr) in bit/s: 487768109.23, 41341952.15
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 45080576.50
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 14864073.62
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 39881299.23
----- 422. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_rr', 'zc_fr', 'zc_rl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.165ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.482ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 44977564.54
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 44236114.61
(sw_c, sw_fr) in bit/s: None, 46129719.19
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 487768109.23, 41341952.15
(sw_fr, sw_c) in bit/s: 246526917.67, 20434754.21
(sw_fr, zc_fr) in bit/s: None, 45080576.50
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 39881299.23
----- 423. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.499ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 45550713.56
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 44505421.61
(sw_c, sw_fr) in bit/s: None, 46129719.19
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 487768109.23, 41341952.15
(sw_fr, sw_c) in bit/s: 246526917.67, 21023284.53
(sw_fr, zc_fr) in bit/s: None, 45080576.50
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 39881299.23
----- 424. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 45550713.56
(sw_fl, infotainment) in bit/s: None, 17339030.78
(sw_c, sw_fl) in bit/s: None, 44505421.61
(sw_c, sw_fr) in bit/s: None, 46129719.19
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 487768109.23, 41341952.15
(sw_fr, sw_c) in bit/s: 246526917.67, 21023284.53
(sw_fr, zc_fr) in bit/s: None, 45080576.50
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 39881299.23
----- 425. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.499ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 45550713.56
(sw_fl, infotainment) in bit/s: None, 17926345.79
(sw_c, sw_fl) in bit/s: None, 44505421.61
(sw_c, sw_fr) in bit/s: None, 46129719.19
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 487768109.23, 41341952.15
(sw_fr, sw_c) in bit/s: 246526917.67, 21023284.53
(sw_fr, zc_fr) in bit/s: None, 45080576.50
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 39881299.23
----- 426. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 45550713.56
(sw_fl, infotainment) in bit/s: None, 17926345.79
(sw_c, sw_fl) in bit/s: None, 44505421.61
(sw_c, sw_fr) in bit/s: None, 46129719.19
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 487768109.23, 41341952.15
(sw_fr, sw_c) in bit/s: 246526917.67, 21023284.53
(sw_fr, zc_fr) in bit/s: None, 45080576.50
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 39881299.23
----- 427. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'infotainment', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.499ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.499ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 45550713.56
(sw_fl, infotainment) in bit/s: None, 17926345.79
(sw_c, sw_fl) in bit/s: None, 44505421.61
(sw_c, sw_fr) in bit/s: None, 46129719.19
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 487768109.23, 41892105.12
(sw_fr, sw_c) in bit/s: 246526917.67, 21023284.53
(sw_fr, zc_fr) in bit/s: None, 45080576.50
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 40461870.27
----- 428. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.499ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 46123057.40
(sw_fl, infotainment) in bit/s: None, 17926345.79
(sw_c, sw_fl) in bit/s: None, 45114986.69
(sw_c, sw_fr) in bit/s: None, 46129719.19
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 487768109.23, 41892105.12
(sw_fr, sw_c) in bit/s: 246526917.67, 21611045.44
(sw_fr, zc_fr) in bit/s: None, 45080576.50
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 40461870.27
----- 429. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 46123057.40
(sw_fl, infotainment) in bit/s: None, 17926345.79
(sw_c, sw_fl) in bit/s: None, 45114986.69
(sw_c, sw_fr) in bit/s: None, 46129719.19
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 487768109.23, 41892105.12
(sw_fr, sw_c) in bit/s: 246526917.67, 21611045.44
(sw_fr, zc_fr) in bit/s: None, 45080576.50
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 40461870.27
----- 430. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.499ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 46123057.40
(sw_fl, infotainment) in bit/s: None, 17926345.79
(sw_c, sw_fl) in bit/s: None, 45114986.69
(sw_c, sw_fr) in bit/s: None, 46129719.19
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 487768109.23, 42517229.33
(sw_fr, sw_c) in bit/s: 246526917.67, 21611045.44
(sw_fr, zc_fr) in bit/s: None, 45080576.50
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 41041628.57
----- 431. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 46123057.40
(sw_fl, infotainment) in bit/s: None, 17926345.79
(sw_c, sw_fl) in bit/s: None, 45114986.69
(sw_c, sw_fr) in bit/s: None, 46129719.19
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 487768109.23, 42517229.33
(sw_fr, sw_c) in bit/s: 246526917.67, 21611045.44
(sw_fr, zc_fr) in bit/s: None, 45080576.50
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 41041628.57
----- 432. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.506ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.506ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 46123057.40
(sw_fl, infotainment) in bit/s: None, 17926345.79
(sw_c, sw_fl) in bit/s: None, 45114986.69
(sw_c, sw_fr) in bit/s: None, 46939799.39
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 487768109.23, 42517229.33
(sw_fr, sw_c) in bit/s: 246526917.67, 21611045.44
(sw_fr, zc_fr) in bit/s: None, 45655355.68
(sw_rl, sw_c) in bit/s: None, 2414317.85
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 552490278.83, None
(sw_rr, zc_rr) in bit/s: None, 41041628.57
----- 433. Flow Operation -- add -----
Flow Details: Source:  camera_rear , Destination:  ['adas'] , Bits:  11520 , Interval:  0.065 ms , Deadline:  10.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('camera_rear', 'sw_rl', 0), ('sw_rl', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 5.304ms
Reservation Dependent Flow Delay: 3.996ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 46123057.40
(sw_fl, infotainment) in bit/s: None, 17926345.79
(sw_c, sw_fl) in bit/s: None, 45114986.69
(sw_c, sw_fr) in bit/s: None, 46939799.39
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 789982654.43, 43867867.54
(sw_fr, sw_c) in bit/s: 246526917.67, 21611045.44
(sw_fr, zc_fr) in bit/s: None, 45655355.68
(sw_rl, sw_c) in bit/s: 185821579.24, 2444827.28
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 27372262.60
(sw_rr, adas) in bit/s: 726610852.18, None
(sw_rr, zc_rr) in bit/s: None, 41041628.57
----- 434. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.506ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 46694647.62
(sw_fl, infotainment) in bit/s: None, 17926345.79
(sw_c, sw_fl) in bit/s: None, 46024179.65
(sw_c, sw_fr) in bit/s: None, 46939799.39
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 789982654.43, 43867867.54
(sw_fr, sw_c) in bit/s: 246526917.67, 21611045.44
(sw_fr, zc_fr) in bit/s: None, 45655355.68
(sw_rl, sw_c) in bit/s: 185821579.24, 2444827.28
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 27963856.82
(sw_rr, adas) in bit/s: 726610852.18, None
(sw_rr, zc_rr) in bit/s: None, 41041628.57
----- 435. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.507ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 47266075.98
(sw_fl, infotainment) in bit/s: None, 17926345.79
(sw_c, sw_fl) in bit/s: None, 46637949.76
(sw_c, sw_fr) in bit/s: None, 46939799.39
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 789982654.43, 43867867.54
(sw_fr, sw_c) in bit/s: 246526917.67, 21611045.44
(sw_fr, zc_fr) in bit/s: None, 45655355.68
(sw_rl, sw_c) in bit/s: 185821579.24, 2444827.28
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 28555082.54
(sw_rr, adas) in bit/s: 726610852.18, None
(sw_rr, zc_rr) in bit/s: None, 41041628.57
----- 436. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 47266075.98
(sw_fl, infotainment) in bit/s: None, 17926345.79
(sw_c, sw_fl) in bit/s: None, 46637949.76
(sw_c, sw_fr) in bit/s: None, 46939799.39
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 789982654.43, 43867867.54
(sw_fr, sw_c) in bit/s: 246526917.67, 21611045.44
(sw_fr, zc_fr) in bit/s: None, 45655355.68
(sw_rl, sw_c) in bit/s: 185821579.24, 2444827.28
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 28555082.54
(sw_rr, adas) in bit/s: 726610852.18, None
(sw_rr, zc_rr) in bit/s: None, 41041628.57
----- 437. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.507ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.507ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 47266075.98
(sw_fl, infotainment) in bit/s: None, 18513052.02
(sw_c, sw_fl) in bit/s: None, 46637949.76
(sw_c, sw_fr) in bit/s: None, 46939799.39
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 789982654.43, 43867867.54
(sw_fr, sw_c) in bit/s: 246526917.67, 21611045.44
(sw_fr, zc_fr) in bit/s: None, 45655355.68
(sw_rl, sw_c) in bit/s: 185821579.24, 2444827.28
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 28555082.54
(sw_rr, adas) in bit/s: 726610852.18, None
(sw_rr, zc_rr) in bit/s: None, 41041628.57
----- 438. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 47266075.98
(sw_fl, infotainment) in bit/s: None, 18513052.02
(sw_c, sw_fl) in bit/s: None, 46637949.76
(sw_c, sw_fr) in bit/s: None, 46939799.39
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 789982654.43, 43867867.54
(sw_fr, sw_c) in bit/s: 246526917.67, 21611045.44
(sw_fr, zc_fr) in bit/s: None, 45655355.68
(sw_rl, sw_c) in bit/s: 185821579.24, 2444827.28
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 28555082.54
(sw_rr, adas) in bit/s: 726610852.18, None
(sw_rr, zc_rr) in bit/s: None, 41041628.57
----- 439. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'infotainment', 'zc_fr'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.507ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.507ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.507ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 47266075.98
(sw_fl, infotainment) in bit/s: None, 18513052.02
(sw_c, sw_fl) in bit/s: None, 46637949.76
(sw_c, sw_fr) in bit/s: None, 47557514.77
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 789982654.43, 43867867.54
(sw_fr, sw_c) in bit/s: 246526917.67, 21611045.44
(sw_fr, zc_fr) in bit/s: None, 46229473.61
(sw_rl, sw_c) in bit/s: 185821579.24, 2444827.28
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 28555082.54
(sw_rr, adas) in bit/s: 726610852.18, None
(sw_rr, zc_rr) in bit/s: None, 41041628.57
----- 440. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 47836332.16
(sw_fl, infotainment) in bit/s: None, 18513052.02
(sw_c, sw_fl) in bit/s: None, 46888306.82
(sw_c, sw_fr) in bit/s: None, 47557514.77
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 789982654.43, 43867867.54
(sw_fr, sw_c) in bit/s: 246526917.67, 22198061.44
(sw_fr, zc_fr) in bit/s: None, 46229473.61
(sw_rl, sw_c) in bit/s: 185821579.24, 2444827.28
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 28555082.54
(sw_rr, adas) in bit/s: 726610852.18, None
(sw_rr, zc_rr) in bit/s: None, 41041628.57
----- 441. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 47836332.16
(sw_fl, infotainment) in bit/s: None, 18513052.02
(sw_c, sw_fl) in bit/s: None, 46888306.82
(sw_c, sw_fr) in bit/s: None, 47557514.77
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 789982654.43, 43867867.54
(sw_fr, sw_c) in bit/s: 246526917.67, 22198061.44
(sw_fr, zc_fr) in bit/s: None, 46229473.61
(sw_rl, sw_c) in bit/s: 185821579.24, 2444827.28
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 28555082.54
(sw_rr, adas) in bit/s: 726610852.18, None
(sw_rr, zc_rr) in bit/s: None, 41041628.57
----- 442. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.501ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 47836332.16
(sw_fl, infotainment) in bit/s: None, 18513052.02
(sw_c, sw_fl) in bit/s: None, 46888306.82
(sw_c, sw_fr) in bit/s: None, 47557514.77
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 789982654.43, 44512807.37
(sw_fr, sw_c) in bit/s: 246526917.67, 22198061.44
(sw_fr, zc_fr) in bit/s: None, 46229473.61
(sw_rl, sw_c) in bit/s: 185821579.24, 2444827.28
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 28555082.54
(sw_rr, adas) in bit/s: 726610852.18, None
(sw_rr, zc_rr) in bit/s: None, 41620624.01
----- 443. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.508ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 48408761.45
(sw_fl, infotainment) in bit/s: None, 18513052.02
(sw_c, sw_fl) in bit/s: None, 47837778.18
(sw_c, sw_fr) in bit/s: None, 47557514.77
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 789982654.43, 44512807.37
(sw_fr, sw_c) in bit/s: 246526917.67, 22198061.44
(sw_fr, zc_fr) in bit/s: None, 46229473.61
(sw_rl, sw_c) in bit/s: 185821579.24, 2444827.28
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 29147144.82
(sw_rr, adas) in bit/s: 726610852.18, None
(sw_rr, zc_rr) in bit/s: None, 41620624.01
----- 444. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 48408761.45
(sw_fl, infotainment) in bit/s: None, 18513052.02
(sw_c, sw_fl) in bit/s: None, 47837778.18
(sw_c, sw_fr) in bit/s: None, 47557514.77
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 789982654.43, 44512807.37
(sw_fr, sw_c) in bit/s: 246526917.67, 22198061.44
(sw_fr, zc_fr) in bit/s: None, 46229473.61
(sw_rl, sw_c) in bit/s: 185821579.24, 2444827.28
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 29147144.82
(sw_rr, adas) in bit/s: 726610852.18, None
(sw_rr, zc_rr) in bit/s: None, 41620624.01
----- 445. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.508ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.508ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 48408761.45
(sw_fl, infotainment) in bit/s: None, 18513052.02
(sw_c, sw_fl) in bit/s: None, 47837778.18
(sw_c, sw_fr) in bit/s: None, 48176283.97
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 789982654.43, 44512807.37
(sw_fr, sw_c) in bit/s: 246526917.67, 22198061.44
(sw_fr, zc_fr) in bit/s: None, 46805359.72
(sw_rl, sw_c) in bit/s: 185821579.24, 2444827.28
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 29147144.82
(sw_rr, adas) in bit/s: 726610852.18, None
(sw_rr, zc_rr) in bit/s: None, 41620624.01
----- 446. Flow Operation -- add -----
Flow Details: Source:  lidar_rl , Destination:  ['adas'] , Bits:  7968 , Interval:  0.150 ms , Deadline:  10.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('lidar_rl', 'sw_rl', 0), ('sw_rl', 'sw_c', 0), ('sw_c', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 5.304ms
Reservation Dependent Flow Delay: 3.978ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 48408761.45
(sw_fl, infotainment) in bit/s: None, 18513052.02
(sw_c, sw_fl) in bit/s: None, 47837778.18
(sw_c, sw_fr) in bit/s: None, 48176283.97
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 882759436.45, 46493794.85
(sw_fr, sw_c) in bit/s: 246526917.67, 22198061.44
(sw_fr, zc_fr) in bit/s: None, 46805359.72
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 29147144.82
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 41620624.01
----- 447. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.178ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 22922031.65
(sw_fl, zc_fl) in bit/s: None, 48408761.45
(sw_fl, infotainment) in bit/s: None, 19110140.58
(sw_c, sw_fl) in bit/s: None, 47837778.18
(sw_c, sw_fr) in bit/s: None, 48176283.97
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 882759436.45, 46493794.85
(sw_fr, sw_c) in bit/s: 246526917.67, 22198061.44
(sw_fr, zc_fr) in bit/s: None, 46805359.72
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 29147144.82
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 41620624.01
----- 448. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 23527307.84
(sw_fl, zc_fl) in bit/s: None, 48408761.45
(sw_fl, infotainment) in bit/s: None, 19110140.58
(sw_c, sw_fl) in bit/s: None, 47837778.18
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 882759436.45, 46493794.85
(sw_fr, sw_c) in bit/s: 246526917.67, 22198061.44
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 29147144.82
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 41620624.01
----- 449. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.501ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 23527307.84
(sw_fl, zc_fl) in bit/s: None, 48977716.83
(sw_fl, infotainment) in bit/s: None, 19110140.58
(sw_c, sw_fl) in bit/s: None, 48079128.74
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 882759436.45, 46493794.85
(sw_fr, sw_c) in bit/s: 246526917.67, 22784375.08
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 29147144.82
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 41620624.01
----- 450. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 23527307.84
(sw_fl, zc_fl) in bit/s: None, 48977716.83
(sw_fl, infotainment) in bit/s: None, 19110140.58
(sw_c, sw_fl) in bit/s: None, 48079128.74
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 882759436.45, 46493794.85
(sw_fr, sw_c) in bit/s: 246526917.67, 22784375.08
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 29147144.82
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 41620624.01
----- 451. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.501ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 23527307.84
(sw_fl, zc_fl) in bit/s: None, 48977716.83
(sw_fl, infotainment) in bit/s: None, 19110140.58
(sw_c, sw_fl) in bit/s: None, 48079128.74
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 882759436.45, 47167436.93
(sw_fr, sw_c) in bit/s: 246526917.67, 22784375.08
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 29147144.82
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 42198936.84
----- 452. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 23527307.84
(sw_fl, zc_fl) in bit/s: None, 48977716.83
(sw_fl, infotainment) in bit/s: None, 19110140.58
(sw_c, sw_fl) in bit/s: None, 48079128.74
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 15626019.15
(sw_c, sw_rr) in bit/s: 882759436.45, 47167436.93
(sw_fr, sw_c) in bit/s: 246526917.67, 22784375.08
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 15474071.03
(sw_rr, sw_c) in bit/s: None, 29147144.82
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 42198936.84
----- 453. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.501ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.501ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 23527307.84
(sw_fl, zc_fl) in bit/s: None, 48977716.83
(sw_fl, infotainment) in bit/s: None, 19110140.58
(sw_c, sw_fl) in bit/s: None, 48079128.74
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 16251039.96
(sw_c, sw_rr) in bit/s: 882759436.45, 47167436.93
(sw_fr, sw_c) in bit/s: 246526917.67, 22784375.08
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 16083301.57
(sw_rr, sw_c) in bit/s: None, 29147144.82
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 42198936.84
----- 454. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.509ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 23527307.84
(sw_fl, zc_fl) in bit/s: None, 49546540.78
(sw_fl, infotainment) in bit/s: None, 19110140.58
(sw_c, sw_fl) in bit/s: None, 49035200.75
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 16251039.96
(sw_c, sw_rr) in bit/s: 882759436.45, 47167436.93
(sw_fr, sw_c) in bit/s: 246526917.67, 22784375.08
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 16083301.57
(sw_rr, sw_c) in bit/s: None, 29737022.48
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 42198936.84
----- 455. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 23527307.84
(sw_fl, zc_fl) in bit/s: None, 49546540.78
(sw_fl, infotainment) in bit/s: None, 19110140.58
(sw_c, sw_fl) in bit/s: None, 49035200.75
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 16251039.96
(sw_c, sw_rr) in bit/s: 882759436.45, 47167436.93
(sw_fr, sw_c) in bit/s: 246526917.67, 22784375.08
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 16083301.57
(sw_rr, sw_c) in bit/s: None, 29737022.48
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 42198936.84
----- 456. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'infotainment'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.508ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.509ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 23527307.84
(sw_fl, zc_fl) in bit/s: None, 49546540.78
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49035200.75
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 16251039.96
(sw_c, sw_rr) in bit/s: 882759436.45, 47167436.93
(sw_fr, sw_c) in bit/s: 246526917.67, 22784375.08
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 16083301.57
(sw_rr, sw_c) in bit/s: None, 29737022.48
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 42198936.84
----- 457. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.501ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 23527307.84
(sw_fl, zc_fl) in bit/s: None, 50114171.25
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49267201.53
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 16251039.96
(sw_c, sw_rr) in bit/s: 882759436.45, 47167436.93
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 16083301.57
(sw_rr, sw_c) in bit/s: None, 29737022.48
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 42198936.84
----- 458. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 23527307.84
(sw_fl, zc_fl) in bit/s: None, 50114171.25
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49267201.53
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 16251039.96
(sw_c, sw_rr) in bit/s: 882759436.45, 47167436.93
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 16083301.57
(sw_rr, sw_c) in bit/s: None, 29737022.48
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 42198936.84
----- 459. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.501ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 23527307.84
(sw_fl, zc_fl) in bit/s: None, 50114171.25
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49267201.53
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 16251039.96
(sw_c, sw_rr) in bit/s: 882759436.45, 47841079.01
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 16083301.57
(sw_rr, sw_c) in bit/s: None, 29737022.48
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 42776568.28
----- 460. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 23527307.84
(sw_fl, zc_fl) in bit/s: None, 50114171.25
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49267201.53
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 16251039.96
(sw_c, sw_rr) in bit/s: 882759436.45, 47841079.01
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 16083301.57
(sw_rr, sw_c) in bit/s: None, 29737022.48
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 42776568.28
----- 461. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.501ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 23527307.84
(sw_fl, zc_fl) in bit/s: None, 50114171.25
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49267201.53
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 16876060.76
(sw_c, sw_rr) in bit/s: 882759436.45, 47841079.01
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 16691795.55
(sw_rr, sw_c) in bit/s: None, 29737022.48
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 42776568.28
----- 462. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 24132408.15
(sw_fl, zc_fl) in bit/s: None, 50114171.25
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49267201.53
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 16876060.76
(sw_c, sw_rr) in bit/s: 882759436.45, 48452261.67
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 16691795.55
(sw_rr, sw_c) in bit/s: None, 29737022.48
(sw_rr, adas) in bit/s: 767096570.88, None
(sw_rr, zc_rr) in bit/s: None, 43354872.34
----- 463. Flow Operation -- add -----
Flow Details: Source:  lidar_rr , Destination:  ['adas'] , Bits:  7968 , Interval:  0.150 ms , Deadline:  10.000 ms , User-Defined-Priority:  0 , Redundant Transm.: False
Path (from, to, prio):  [('lidar_rr', 'sw_rr', 0), ('sw_rr', 'adas', 0)]
Reservation Independent Flow Delay: 2.648ms
Reservation Dependent Flow Delay: 1.336ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 24132408.15
(sw_fl, zc_fl) in bit/s: None, 50114171.25
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49267201.53
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 16876060.76
(sw_c, sw_rr) in bit/s: 882759436.45, 48452261.67
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 16691795.55
(sw_rr, sw_c) in bit/s: None, 29737022.48
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 43354872.34
----- 464. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 24132408.15
(sw_fl, zc_fl) in bit/s: None, 50114171.25
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49267201.53
(sw_c, sw_fr) in bit/s: None, 48505109.55
(sw_c, sw_rl) in bit/s: None, 16876060.76
(sw_c, sw_rr) in bit/s: 882759436.45, 48452261.67
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 47377634.42
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 16691795.55
(sw_rr, sw_c) in bit/s: None, 29737022.48
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 43354872.34
----- 465. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.179ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 24736223.43
(sw_fl, zc_fl) in bit/s: None, 50114171.25
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49267201.53
(sw_c, sw_fr) in bit/s: None, 49118864.93
(sw_c, sw_rl) in bit/s: None, 16876060.76
(sw_c, sw_rr) in bit/s: 882759436.45, 48452261.67
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 47949207.26
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 16691795.55
(sw_rr, sw_c) in bit/s: None, 29737022.48
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 43354872.34
----- 466. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.509ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 24736223.43
(sw_fl, zc_fl) in bit/s: None, 50114171.25
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49267201.53
(sw_c, sw_fr) in bit/s: None, 49118864.93
(sw_c, sw_rl) in bit/s: None, 17543743.17
(sw_c, sw_rr) in bit/s: 882759436.45, 48452261.67
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 47949207.26
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17299554.31
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 43354872.34
----- 467. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 24736223.43
(sw_fl, zc_fl) in bit/s: None, 50114171.25
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49267201.53
(sw_c, sw_fr) in bit/s: None, 49118864.93
(sw_c, sw_rl) in bit/s: None, 17543743.17
(sw_c, sw_rr) in bit/s: 882759436.45, 48452261.67
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 47949207.26
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17299554.31
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 43354872.34
----- 468. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.179ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.496ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 24736223.43
(sw_fl, zc_fl) in bit/s: None, 50114171.25
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49267201.53
(sw_c, sw_fr) in bit/s: None, 49118864.93
(sw_c, sw_rl) in bit/s: None, 17543743.17
(sw_c, sw_rr) in bit/s: 882759436.45, 49124999.43
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 47949207.26
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17299554.31
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 43931133.49
----- 469. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 24736223.43
(sw_fl, zc_fl) in bit/s: None, 50114171.25
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49267201.53
(sw_c, sw_fr) in bit/s: None, 49118864.93
(sw_c, sw_rl) in bit/s: None, 17543743.17
(sw_c, sw_rr) in bit/s: 882759436.45, 49124999.43
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 47949207.26
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17299554.31
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 43931133.49
----- 470. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.509ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.509ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 24736223.43
(sw_fl, zc_fl) in bit/s: None, 50114171.25
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49267201.53
(sw_c, sw_fr) in bit/s: None, 49969249.07
(sw_c, sw_rl) in bit/s: None, 17543743.17
(sw_c, sw_rr) in bit/s: 882759436.45, 49124999.43
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 48520141.20
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17299554.31
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 43931133.49
----- 471. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 24736223.43
(sw_fl, zc_fl) in bit/s: None, 50114171.25
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 49267201.53
(sw_c, sw_fr) in bit/s: None, 49969249.07
(sw_c, sw_rl) in bit/s: None, 17543743.17
(sw_c, sw_rr) in bit/s: 882759436.45, 49124999.43
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 48520141.20
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17299554.31
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 43931133.49
----- 472. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_rl', 'zc_fr', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.509ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.509ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.509ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 24736223.43
(sw_fl, zc_fl) in bit/s: None, 50681137.80
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 50230956.85
(sw_c, sw_fr) in bit/s: None, 49969249.07
(sw_c, sw_rl) in bit/s: None, 17543743.17
(sw_c, sw_rr) in bit/s: 882759436.45, 49124999.43
(sw_fr, sw_c) in bit/s: 246526917.67, 23369987.62
(sw_fr, zc_fr) in bit/s: None, 48520141.20
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17299554.31
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 43931133.49
----- 473. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 24736223.43
(sw_fl, zc_fl) in bit/s: None, 51247687.81
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 50453699.62
(sw_c, sw_fr) in bit/s: None, 49969249.07
(sw_c, sw_rl) in bit/s: None, 17543743.17
(sw_c, sw_rr) in bit/s: 882759436.45, 49124999.43
(sw_fr, sw_c) in bit/s: 246526917.67, 23955025.82
(sw_fr, zc_fr) in bit/s: None, 48520141.20
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17299554.31
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 43931133.49
----- 474. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 24736223.43
(sw_fl, zc_fl) in bit/s: None, 51813659.71
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 51061593.68
(sw_c, sw_fr) in bit/s: None, 49969249.07
(sw_c, sw_rl) in bit/s: None, 17543743.17
(sw_c, sw_rr) in bit/s: 882759436.45, 49124999.43
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 48520141.20
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17299554.31
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 43931133.49
----- 475. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 24736223.43
(sw_fl, zc_fl) in bit/s: None, 51813659.71
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 51061593.68
(sw_c, sw_fr) in bit/s: None, 49969249.07
(sw_c, sw_rl) in bit/s: None, 17543743.17
(sw_c, sw_rr) in bit/s: 882759436.45, 49124999.43
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 48520141.20
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17299554.31
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 43931133.49
----- 476. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.505ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 24736223.43
(sw_fl, zc_fl) in bit/s: None, 51813659.71
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 51061593.68
(sw_c, sw_fr) in bit/s: None, 49969249.07
(sw_c, sw_rl) in bit/s: None, 17543743.17
(sw_c, sw_rr) in bit/s: 882759436.45, 49797779.37
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 48520141.20
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17299554.31
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 44506976.27
----- 477. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr'] , Bits:  688 , Interval:  150.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.483ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25354529.00
(sw_fl, zc_fl) in bit/s: None, 51813659.71
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 51061593.68
(sw_c, sw_fr) in bit/s: None, 50316729.42
(sw_c, sw_rl) in bit/s: None, 17543743.17
(sw_c, sw_rr) in bit/s: 882759436.45, 49797779.37
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 49090555.04
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17299554.31
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 44506976.27
----- 478. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 51813659.71
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 51061593.68
(sw_c, sw_fr) in bit/s: None, 50316729.42
(sw_c, sw_rl) in bit/s: None, 18115087.75
(sw_c, sw_rr) in bit/s: 882759436.45, 49797779.37
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 49090555.04
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17906579.18
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 44506976.27
----- 479. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 51813659.71
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 51061593.68
(sw_c, sw_fr) in bit/s: None, 50316729.42
(sw_c, sw_rl) in bit/s: None, 18115087.75
(sw_c, sw_rr) in bit/s: 882759436.45, 49797779.37
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 49090555.04
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17906579.18
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 44506976.27
----- 480. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 51813659.71
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 51061593.68
(sw_c, sw_fr) in bit/s: None, 50930134.21
(sw_c, sw_rl) in bit/s: None, 18115087.75
(sw_c, sw_rr) in bit/s: 882759436.45, 49797779.37
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 49660154.95
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17906579.18
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 44506976.27
----- 481. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 51813659.71
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 51061593.68
(sw_c, sw_fr) in bit/s: None, 50930134.21
(sw_c, sw_rl) in bit/s: None, 18115087.75
(sw_c, sw_rr) in bit/s: 882759436.45, 49797779.37
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 49660154.95
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17906579.18
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 44506976.27
----- 482. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.497ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.499ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 51813659.71
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 51061593.68
(sw_c, sw_fr) in bit/s: None, 50930134.21
(sw_c, sw_rl) in bit/s: None, 18115087.75
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 49660154.95
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17906579.18
(sw_rr, sw_c) in bit/s: None, 30325855.24
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 483. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.510ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 51813659.71
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 51061593.68
(sw_c, sw_fr) in bit/s: None, 51758094.75
(sw_c, sw_rl) in bit/s: None, 18115087.75
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 50229348.70
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17906579.18
(sw_rr, sw_c) in bit/s: None, 30914149.68
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 484. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.511ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 51813659.71
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 51061593.68
(sw_c, sw_fr) in bit/s: None, 52374205.14
(sw_c, sw_rl) in bit/s: None, 18115087.75
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 50797883.19
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17906579.18
(sw_rr, sw_c) in bit/s: None, 31501751.31
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 485. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 51813659.71
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 51061593.68
(sw_c, sw_fr) in bit/s: None, 52374205.14
(sw_c, sw_rl) in bit/s: None, 18115087.75
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 50797883.19
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17906579.18
(sw_rr, sw_c) in bit/s: None, 31501751.31
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 486. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.511ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.511ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 52378899.87
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 52006820.75
(sw_c, sw_fr) in bit/s: None, 52374205.14
(sw_c, sw_rl) in bit/s: None, 18115087.75
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 50797883.19
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17906579.18
(sw_rr, sw_c) in bit/s: None, 31501751.31
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 487. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.511ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 52378899.87
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 52006820.75
(sw_c, sw_fr) in bit/s: None, 52990909.01
(sw_c, sw_rl) in bit/s: None, 18115087.75
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 51367087.49
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17906579.18
(sw_rr, sw_c) in bit/s: None, 32089500.91
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 488. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 52378899.87
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 52006820.75
(sw_c, sw_fr) in bit/s: None, 52990909.01
(sw_c, sw_rl) in bit/s: None, 18115087.75
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 51367087.49
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 17906579.18
(sw_rr, sw_c) in bit/s: None, 32089500.91
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 489. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.511ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.511ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 52378899.87
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 52006820.75
(sw_c, sw_fr) in bit/s: None, 52990909.01
(sw_c, sw_rl) in bit/s: None, 18785558.30
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 51367087.49
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 18513451.84
(sw_rr, sw_c) in bit/s: None, 32089500.91
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 490. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 52378899.87
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 52006820.75
(sw_c, sw_fr) in bit/s: None, 52990909.01
(sw_c, sw_rl) in bit/s: None, 18785558.30
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 51367087.49
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 18513451.84
(sw_rr, sw_c) in bit/s: None, 32089500.91
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 491. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.511ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.511ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.511ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 52944759.82
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 52619216.33
(sw_c, sw_fr) in bit/s: None, 52990909.01
(sw_c, sw_rl) in bit/s: None, 18785558.30
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 51367087.49
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 18513451.84
(sw_rr, sw_c) in bit/s: None, 32089500.91
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 492. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.512ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 52944759.82
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 52619216.33
(sw_c, sw_fr) in bit/s: None, 53607056.50
(sw_c, sw_rl) in bit/s: None, 18785558.30
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 51934404.80
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 18513451.84
(sw_rr, sw_c) in bit/s: None, 32675789.13
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 493. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 52944759.82
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 52619216.33
(sw_c, sw_fr) in bit/s: None, 53607056.50
(sw_c, sw_rl) in bit/s: None, 18785558.30
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 51934404.80
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 18513451.84
(sw_rr, sw_c) in bit/s: None, 32675789.13
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 494. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.512ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.512ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 52944759.82
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 52619216.33
(sw_c, sw_fr) in bit/s: None, 53607056.50
(sw_c, sw_rl) in bit/s: None, 19411762.13
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 51934404.80
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19119163.38
(sw_rr, sw_c) in bit/s: None, 32675789.13
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 495. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 52944759.82
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 52619216.33
(sw_c, sw_fr) in bit/s: None, 53607056.50
(sw_c, sw_rl) in bit/s: None, 19411762.13
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 51934404.80
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19119163.38
(sw_rr, sw_c) in bit/s: None, 32675789.13
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 496. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.512ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.512ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.512ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 25957250.98
(sw_fl, zc_fl) in bit/s: None, 53508788.28
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 53231075.19
(sw_c, sw_fr) in bit/s: None, 53607056.50
(sw_c, sw_rl) in bit/s: None, 19411762.13
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 51934404.80
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19119163.38
(sw_rr, sw_c) in bit/s: None, 32675789.13
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 497. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 53508788.28
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 53231075.19
(sw_c, sw_fr) in bit/s: None, 53871012.68
(sw_c, sw_rl) in bit/s: None, 19411762.13
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 52500678.12
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19119163.38
(sw_rr, sw_c) in bit/s: None, 32675789.13
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 498. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 53508788.28
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 53231075.19
(sw_c, sw_fr) in bit/s: None, 53871012.68
(sw_c, sw_rl) in bit/s: None, 19411762.13
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 52500678.12
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19119163.38
(sw_rr, sw_c) in bit/s: None, 32675789.13
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 499. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 53508788.28
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 53231075.19
(sw_c, sw_fr) in bit/s: None, 53871012.68
(sw_c, sw_rl) in bit/s: None, 19965071.79
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 52500678.12
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19724005.09
(sw_rr, sw_c) in bit/s: None, 32675789.13
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 500. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 53508788.28
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 53231075.19
(sw_c, sw_fr) in bit/s: None, 53871012.68
(sw_c, sw_rl) in bit/s: None, 19965071.79
(sw_c, sw_rr) in bit/s: 882759436.45, 50437745.27
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 52500678.12
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19724005.09
(sw_rr, sw_c) in bit/s: None, 32675789.13
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45081914.03
----- 501. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 53508788.28
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 53231075.19
(sw_c, sw_fr) in bit/s: None, 53871012.68
(sw_c, sw_rl) in bit/s: None, 19965071.79
(sw_c, sw_rr) in bit/s: 882759436.45, 51110038.67
(sw_fr, sw_c) in bit/s: 246526917.67, 24539411.75
(sw_fr, zc_fr) in bit/s: None, 52500678.12
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19724005.09
(sw_rr, sw_c) in bit/s: None, 32675789.13
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45656146.70
----- 502. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.504ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 54072085.71
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 53399302.35
(sw_c, sw_fr) in bit/s: None, 53871012.68
(sw_c, sw_rl) in bit/s: None, 19965071.79
(sw_c, sw_rr) in bit/s: 882759436.45, 51110038.67
(sw_fr, sw_c) in bit/s: 246526917.67, 25123067.22
(sw_fr, zc_fr) in bit/s: None, 52500678.12
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19724005.09
(sw_rr, sw_c) in bit/s: None, 32675789.13
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45656146.70
----- 503. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 54072085.71
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 53399302.35
(sw_c, sw_fr) in bit/s: None, 53871012.68
(sw_c, sw_rl) in bit/s: None, 19965071.79
(sw_c, sw_rr) in bit/s: 882759436.45, 51110038.67
(sw_fr, sw_c) in bit/s: 246526917.67, 25123067.22
(sw_fr, zc_fr) in bit/s: None, 52500678.12
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19724005.09
(sw_rr, sw_c) in bit/s: None, 32675789.13
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 45656146.70
----- 504. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.504ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.505ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 54072085.71
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 53399302.35
(sw_c, sw_fr) in bit/s: None, 53871012.68
(sw_c, sw_rl) in bit/s: None, 19965071.79
(sw_c, sw_rr) in bit/s: 882759436.45, 51748655.06
(sw_fr, sw_c) in bit/s: 246526917.67, 25123067.22
(sw_fr, zc_fr) in bit/s: None, 52500678.12
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19724005.09
(sw_rr, sw_c) in bit/s: None, 32675789.13
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46229974.32
----- 505. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.513ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 54634436.84
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 54422295.27
(sw_c, sw_fr) in bit/s: None, 53871012.68
(sw_c, sw_rl) in bit/s: None, 19965071.79
(sw_c, sw_rr) in bit/s: 882759436.45, 51748655.06
(sw_fr, sw_c) in bit/s: 246526917.67, 25123067.22
(sw_fr, zc_fr) in bit/s: None, 52500678.12
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19724005.09
(sw_rr, sw_c) in bit/s: None, 33261139.97
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46229974.32
----- 506. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.513ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 54634436.84
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 54422295.27
(sw_c, sw_fr) in bit/s: None, 54807222.64
(sw_c, sw_rl) in bit/s: None, 19965071.79
(sw_c, sw_rr) in bit/s: 882759436.45, 51748655.06
(sw_fr, sw_c) in bit/s: 246526917.67, 25123067.22
(sw_fr, zc_fr) in bit/s: None, 53067968.77
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19724005.09
(sw_rr, sw_c) in bit/s: None, 33846880.07
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46229974.32
----- 507. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 54634436.84
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 54422295.27
(sw_c, sw_fr) in bit/s: None, 54807222.64
(sw_c, sw_rl) in bit/s: None, 19965071.79
(sw_c, sw_rr) in bit/s: 882759436.45, 51748655.06
(sw_fr, sw_c) in bit/s: 246526917.67, 25123067.22
(sw_fr, zc_fr) in bit/s: None, 53067968.77
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19724005.09
(sw_rr, sw_c) in bit/s: None, 33846880.07
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46229974.32
----- 508. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.513ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.513ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 55197761.12
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 55034343.69
(sw_c, sw_fr) in bit/s: None, 54807222.64
(sw_c, sw_rl) in bit/s: None, 19965071.79
(sw_c, sw_rr) in bit/s: 882759436.45, 51748655.06
(sw_fr, sw_c) in bit/s: 246526917.67, 25123067.22
(sw_fr, zc_fr) in bit/s: None, 53067968.77
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19724005.09
(sw_rr, sw_c) in bit/s: None, 33846880.07
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46229974.32
----- 509. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.514ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 55197761.12
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 55034343.69
(sw_c, sw_fr) in bit/s: None, 55422965.85
(sw_c, sw_rl) in bit/s: None, 19965071.79
(sw_c, sw_rr) in bit/s: 882759436.45, 51748655.06
(sw_fr, sw_c) in bit/s: 246526917.67, 25123067.22
(sw_fr, zc_fr) in bit/s: None, 53633249.68
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19724005.09
(sw_rr, sw_c) in bit/s: None, 34431063.52
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46229974.32
----- 510. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 55197761.12
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 55034343.69
(sw_c, sw_fr) in bit/s: None, 55422965.85
(sw_c, sw_rl) in bit/s: None, 19965071.79
(sw_c, sw_rr) in bit/s: 882759436.45, 51748655.06
(sw_fr, sw_c) in bit/s: 246526917.67, 25123067.22
(sw_fr, zc_fr) in bit/s: None, 53633249.68
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19724005.09
(sw_rr, sw_c) in bit/s: None, 34431063.52
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46229974.32
----- 511. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.514ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.514ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 55759121.77
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 55645803.12
(sw_c, sw_fr) in bit/s: None, 55422965.85
(sw_c, sw_rl) in bit/s: None, 19965071.79
(sw_c, sw_rr) in bit/s: 882759436.45, 51748655.06
(sw_fr, sw_c) in bit/s: 246526917.67, 25123067.22
(sw_fr, zc_fr) in bit/s: None, 53633249.68
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19724005.09
(sw_rr, sw_c) in bit/s: None, 34431063.52
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46229974.32
----- 512. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.515ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 55759121.77
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 55645803.12
(sw_c, sw_fr) in bit/s: None, 56038587.04
(sw_c, sw_rl) in bit/s: None, 19965071.79
(sw_c, sw_rr) in bit/s: 882759436.45, 51748655.06
(sw_fr, sw_c) in bit/s: 246526917.67, 25123067.22
(sw_fr, zc_fr) in bit/s: None, 54197598.47
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19724005.09
(sw_rr, sw_c) in bit/s: None, 35014378.38
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46229974.32
----- 513. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 55759121.77
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 55645803.12
(sw_c, sw_fr) in bit/s: None, 56038587.04
(sw_c, sw_rl) in bit/s: None, 19965071.79
(sw_c, sw_rr) in bit/s: 882759436.45, 51748655.06
(sw_fr, sw_c) in bit/s: 246526917.67, 25123067.22
(sw_fr, zc_fr) in bit/s: None, 54197598.47
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 19724005.09
(sw_rr, sw_c) in bit/s: None, 35014378.38
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46229974.32
----- 514. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.515ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.515ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 55759121.77
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 55645803.12
(sw_c, sw_fr) in bit/s: None, 56038587.04
(sw_c, sw_rl) in bit/s: None, 20651532.28
(sw_c, sw_rr) in bit/s: 882759436.45, 51748655.06
(sw_fr, sw_c) in bit/s: 246526917.67, 25123067.22
(sw_fr, zc_fr) in bit/s: None, 54197598.47
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 20328130.64
(sw_rr, sw_c) in bit/s: None, 35014378.38
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46229974.32
----- 515. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 55759121.77
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 55645803.12
(sw_c, sw_fr) in bit/s: None, 56038587.04
(sw_c, sw_rl) in bit/s: None, 20651532.28
(sw_c, sw_rr) in bit/s: 882759436.45, 51748655.06
(sw_fr, sw_c) in bit/s: 246526917.67, 25123067.22
(sw_fr, zc_fr) in bit/s: None, 54197598.47
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 20328130.64
(sw_rr, sw_c) in bit/s: None, 35014378.38
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46229974.32
----- 516. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.515ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.515ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.515ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 56319564.00
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 56257144.75
(sw_c, sw_fr) in bit/s: None, 56038587.04
(sw_c, sw_rl) in bit/s: None, 20651532.28
(sw_c, sw_rr) in bit/s: 882759436.45, 51748655.06
(sw_fr, sw_c) in bit/s: 246526917.67, 25123067.22
(sw_fr, zc_fr) in bit/s: None, 54197598.47
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 20328130.64
(sw_rr, sw_c) in bit/s: None, 35014378.38
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46229974.32
----- 517. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.504ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 56319564.00
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 56257144.75
(sw_c, sw_fr) in bit/s: None, 56038587.04
(sw_c, sw_rl) in bit/s: None, 21200044.80
(sw_c, sw_rr) in bit/s: 882759436.45, 51748655.06
(sw_fr, sw_c) in bit/s: 246526917.67, 25706074.77
(sw_fr, zc_fr) in bit/s: None, 54197598.47
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 20931672.63
(sw_rr, sw_c) in bit/s: None, 35014378.38
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46229974.32
----- 518. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 56319564.00
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 56257144.75
(sw_c, sw_fr) in bit/s: None, 56038587.04
(sw_c, sw_rl) in bit/s: None, 21200044.80
(sw_c, sw_rr) in bit/s: 882759436.45, 51748655.06
(sw_fr, sw_c) in bit/s: 246526917.67, 25706074.77
(sw_fr, zc_fr) in bit/s: None, 54197598.47
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 20931672.63
(sw_rr, sw_c) in bit/s: None, 35014378.38
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46229974.32
----- 519. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_rr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.504ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.506ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 56319564.00
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 56257144.75
(sw_c, sw_fr) in bit/s: None, 56038587.04
(sw_c, sw_rl) in bit/s: None, 21200044.80
(sw_c, sw_rr) in bit/s: 882759436.45, 52420694.87
(sw_fr, sw_c) in bit/s: 246526917.67, 25706074.77
(sw_fr, zc_fr) in bit/s: None, 54197598.47
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 20931672.63
(sw_rr, sw_c) in bit/s: None, 35014378.38
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46803210.50
----- 520. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_rr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 56319564.00
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 56257144.75
(sw_c, sw_fr) in bit/s: None, 56038587.04
(sw_c, sw_rl) in bit/s: None, 21200044.80
(sw_c, sw_rr) in bit/s: 882759436.45, 52420694.87
(sw_fr, sw_c) in bit/s: 246526917.67, 25706074.77
(sw_fr, zc_fr) in bit/s: None, 54197598.47
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 20931672.63
(sw_rr, sw_c) in bit/s: None, 35014378.38
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46803210.50
----- 521. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_rr', 'zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.504ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.504ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.506ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 56879714.76
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 56301143.35
(sw_c, sw_fr) in bit/s: None, 56038587.04
(sw_c, sw_rl) in bit/s: None, 21200044.80
(sw_c, sw_rr) in bit/s: 882759436.45, 52420694.87
(sw_fr, sw_c) in bit/s: 246526917.67, 25706074.77
(sw_fr, zc_fr) in bit/s: None, 54197598.47
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 20931672.63
(sw_rr, sw_c) in bit/s: None, 35014378.38
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46803210.50
----- 522. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.515ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 57439135.95
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 57446037.55
(sw_c, sw_fr) in bit/s: None, 56038587.04
(sw_c, sw_rl) in bit/s: None, 21200044.80
(sw_c, sw_rr) in bit/s: 882759436.45, 52420694.87
(sw_fr, sw_c) in bit/s: 246526917.67, 25706074.77
(sw_fr, zc_fr) in bit/s: None, 54197598.47
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 20931672.63
(sw_rr, sw_c) in bit/s: None, 35597188.87
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 46803210.50
----- 523. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.507ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 57439135.95
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 57446037.55
(sw_c, sw_fr) in bit/s: None, 56038587.04
(sw_c, sw_rl) in bit/s: None, 21200044.80
(sw_c, sw_rr) in bit/s: 882759436.45, 53092543.25
(sw_fr, sw_c) in bit/s: 246526917.67, 26288197.44
(sw_fr, zc_fr) in bit/s: None, 54197598.47
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 20931672.63
(sw_rr, sw_c) in bit/s: None, 35597188.87
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47375429.13
----- 524. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  50.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.506ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 57998263.22
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 57478309.55
(sw_c, sw_fr) in bit/s: None, 56038587.04
(sw_c, sw_rl) in bit/s: None, 21200044.80
(sw_c, sw_rr) in bit/s: 882759436.45, 53092543.25
(sw_fr, sw_c) in bit/s: 246526917.67, 26869960.05
(sw_fr, zc_fr) in bit/s: None, 54197598.47
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 20931672.63
(sw_rr, sw_c) in bit/s: None, 35597188.87
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47375429.13
----- 525. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.506ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 58556083.92
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 58083097.54
(sw_c, sw_fr) in bit/s: None, 56038587.04
(sw_c, sw_rl) in bit/s: None, 21200044.80
(sw_c, sw_rr) in bit/s: 882759436.45, 53092543.25
(sw_fr, sw_c) in bit/s: 246526917.67, 27450702.35
(sw_fr, zc_fr) in bit/s: None, 54197598.47
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 20931672.63
(sw_rr, sw_c) in bit/s: None, 35597188.87
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47375429.13
----- 526. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.516ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 58556083.92
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 58083097.54
(sw_c, sw_fr) in bit/s: None, 56654253.99
(sw_c, sw_rl) in bit/s: None, 21200044.80
(sw_c, sw_rr) in bit/s: 882759436.45, 53092543.25
(sw_fr, sw_c) in bit/s: 246526917.67, 27450702.35
(sw_fr, zc_fr) in bit/s: None, 54761396.22
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 20931672.63
(sw_rr, sw_c) in bit/s: None, 36179198.08
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47375429.13
----- 527. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 58556083.92
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 58083097.54
(sw_c, sw_fr) in bit/s: None, 56654253.99
(sw_c, sw_rl) in bit/s: None, 21200044.80
(sw_c, sw_rr) in bit/s: 882759436.45, 53092543.25
(sw_fr, sw_c) in bit/s: 246526917.67, 27450702.35
(sw_fr, zc_fr) in bit/s: None, 54761396.22
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 20931672.63
(sw_rr, sw_c) in bit/s: None, 36179198.08
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47375429.13
----- 528. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.516ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.516ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 59113399.66
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 59209085.59
(sw_c, sw_fr) in bit/s: None, 56654253.99
(sw_c, sw_rl) in bit/s: None, 21200044.80
(sw_c, sw_rr) in bit/s: 882759436.45, 53092543.25
(sw_fr, sw_c) in bit/s: 246526917.67, 27450702.35
(sw_fr, zc_fr) in bit/s: None, 54761396.22
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 20931672.63
(sw_rr, sw_c) in bit/s: None, 36179198.08
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47375429.13
----- 529. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.507ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 59113399.66
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 59209085.59
(sw_c, sw_fr) in bit/s: None, 56654253.99
(sw_c, sw_rl) in bit/s: None, 21823542.70
(sw_c, sw_rr) in bit/s: 882759436.45, 53092543.25
(sw_fr, sw_c) in bit/s: 246526917.67, 28030771.07
(sw_fr, zc_fr) in bit/s: None, 54761396.22
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 21534349.00
(sw_rr, sw_c) in bit/s: None, 36179198.08
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47375429.13
----- 530. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 59113399.66
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 59209085.59
(sw_c, sw_fr) in bit/s: None, 56654253.99
(sw_c, sw_rl) in bit/s: None, 21823542.70
(sw_c, sw_rr) in bit/s: 882759436.45, 53092543.25
(sw_fr, sw_c) in bit/s: 246526917.67, 28030771.07
(sw_fr, zc_fr) in bit/s: None, 54761396.22
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 21534349.00
(sw_rr, sw_c) in bit/s: None, 36179198.08
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47375429.13
----- 531. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.507ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.507ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 59669963.70
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 59258018.87
(sw_c, sw_fr) in bit/s: None, 56654253.99
(sw_c, sw_rl) in bit/s: None, 21823542.70
(sw_c, sw_rr) in bit/s: 882759436.45, 53092543.25
(sw_fr, sw_c) in bit/s: 246526917.67, 28030771.07
(sw_fr, zc_fr) in bit/s: None, 54761396.22
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 21534349.00
(sw_rr, sw_c) in bit/s: None, 36179198.08
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47375429.13
----- 532. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 59669963.70
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 59258018.87
(sw_c, sw_fr) in bit/s: None, 56654253.99
(sw_c, sw_rl) in bit/s: None, 21823542.70
(sw_c, sw_rr) in bit/s: 882759436.45, 53092543.25
(sw_fr, sw_c) in bit/s: 246526917.67, 28030771.07
(sw_fr, zc_fr) in bit/s: None, 54761396.22
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 21534349.00
(sw_rr, sw_c) in bit/s: None, 36179198.08
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47375429.13
----- 533. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.507ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.507ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.509ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 59669963.70
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 59258018.87
(sw_c, sw_fr) in bit/s: None, 56654253.99
(sw_c, sw_rl) in bit/s: None, 21823542.70
(sw_c, sw_rr) in bit/s: 882759436.45, 53764408.27
(sw_fr, sw_c) in bit/s: 246526917.67, 28030771.07
(sw_fr, zc_fr) in bit/s: None, 54761396.22
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 21534349.00
(sw_rr, sw_c) in bit/s: None, 36179198.08
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47947007.38
----- 534. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  2000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.508ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 60225828.59
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 59862436.50
(sw_c, sw_fr) in bit/s: None, 56654253.99
(sw_c, sw_rl) in bit/s: None, 21823542.70
(sw_c, sw_rr) in bit/s: 882759436.45, 53764408.27
(sw_fr, sw_c) in bit/s: 246526917.67, 28610121.74
(sw_fr, zc_fr) in bit/s: None, 54761396.22
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 21534349.00
(sw_rr, sw_c) in bit/s: None, 36179198.08
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47947007.38
----- 535. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.517ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 60225828.59
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 59862436.50
(sw_c, sw_fr) in bit/s: None, 57269997.20
(sw_c, sw_rl) in bit/s: None, 21823542.70
(sw_c, sw_rr) in bit/s: 882759436.45, 53764408.27
(sw_fr, sw_c) in bit/s: 246526917.67, 28610121.74
(sw_fr, zc_fr) in bit/s: None, 55324718.49
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 21534349.00
(sw_rr, sw_c) in bit/s: None, 36760641.57
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47947007.38
----- 536. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 60225828.59
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 59862436.50
(sw_c, sw_fr) in bit/s: None, 57269997.20
(sw_c, sw_rl) in bit/s: None, 21823542.70
(sw_c, sw_rr) in bit/s: 882759436.45, 53764408.27
(sw_fr, sw_c) in bit/s: 246526917.67, 28610121.74
(sw_fr, zc_fr) in bit/s: None, 55324718.49
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 21534349.00
(sw_rr, sw_c) in bit/s: None, 36760641.57
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47947007.38
----- 537. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.517ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.517ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 60781397.36
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 60967739.43
(sw_c, sw_fr) in bit/s: None, 57269997.20
(sw_c, sw_rl) in bit/s: None, 21823542.70
(sw_c, sw_rr) in bit/s: 882759436.45, 53764408.27
(sw_fr, sw_c) in bit/s: 246526917.67, 28610121.74
(sw_fr, zc_fr) in bit/s: None, 55324718.49
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 21534349.00
(sw_rr, sw_c) in bit/s: None, 36760641.57
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47947007.38
----- 538. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 60781397.36
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 60967739.43
(sw_c, sw_fr) in bit/s: None, 57269997.20
(sw_c, sw_rl) in bit/s: None, 21823542.70
(sw_c, sw_rr) in bit/s: 882759436.45, 53764408.27
(sw_fr, sw_c) in bit/s: 246526917.67, 28610121.74
(sw_fr, zc_fr) in bit/s: None, 55324718.49
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 21534349.00
(sw_rr, sw_c) in bit/s: None, 36760641.57
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47947007.38
----- 539. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'zc_rl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.517ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.517ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.517ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 60781397.36
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 60967739.43
(sw_c, sw_fr) in bit/s: None, 57269997.20
(sw_c, sw_rl) in bit/s: None, 22528958.57
(sw_c, sw_rr) in bit/s: 882759436.45, 53764408.27
(sw_fr, sw_c) in bit/s: 246526917.67, 28610121.74
(sw_fr, zc_fr) in bit/s: None, 55324718.49
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 22136416.55
(sw_rr, sw_c) in bit/s: None, 36760641.57
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47947007.38
----- 540. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.518ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 60781397.36
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 60967739.43
(sw_c, sw_fr) in bit/s: None, 57885740.40
(sw_c, sw_rl) in bit/s: None, 22528958.57
(sw_c, sw_rr) in bit/s: 882759436.45, 53764408.27
(sw_fr, sw_c) in bit/s: 246526917.67, 28610121.74
(sw_fr, zc_fr) in bit/s: None, 55887391.64
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 22136416.55
(sw_rr, sw_c) in bit/s: None, 37341404.28
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47947007.38
----- 541. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.518ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 61336329.16
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 61577387.22
(sw_c, sw_fr) in bit/s: None, 57885740.40
(sw_c, sw_rl) in bit/s: None, 22528958.57
(sw_c, sw_rr) in bit/s: 882759436.45, 53764408.27
(sw_fr, sw_c) in bit/s: 246526917.67, 28610121.74
(sw_fr, zc_fr) in bit/s: None, 55887391.64
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 22136416.55
(sw_rr, sw_c) in bit/s: None, 37921487.43
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47947007.38
----- 542. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 61336329.16
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 61577387.22
(sw_c, sw_fr) in bit/s: None, 57885740.40
(sw_c, sw_rl) in bit/s: None, 22528958.57
(sw_c, sw_rr) in bit/s: 882759436.45, 53764408.27
(sw_fr, sw_c) in bit/s: 246526917.67, 28610121.74
(sw_fr, zc_fr) in bit/s: None, 55887391.64
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 22136416.55
(sw_rr, sw_c) in bit/s: None, 37921487.43
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47947007.38
----- 543. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.518ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.518ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 61336329.16
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 61577387.22
(sw_c, sw_fr) in bit/s: None, 58501483.61
(sw_c, sw_rl) in bit/s: None, 22528958.57
(sw_c, sw_rr) in bit/s: 882759436.45, 53764408.27
(sw_fr, sw_c) in bit/s: 246526917.67, 28610121.74
(sw_fr, zc_fr) in bit/s: None, 56449416.80
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 22136416.55
(sw_rr, sw_c) in bit/s: None, 37921487.43
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47947007.38
----- 544. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.508ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 61893987.27
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 61606156.53
(sw_c, sw_fr) in bit/s: None, 58501483.61
(sw_c, sw_rl) in bit/s: None, 22528958.57
(sw_c, sw_rr) in bit/s: 882759436.45, 53764408.27
(sw_fr, sw_c) in bit/s: 246526917.67, 29190683.72
(sw_fr, zc_fr) in bit/s: None, 56449416.80
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 22136416.55
(sw_rr, sw_c) in bit/s: None, 37921487.43
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47947007.38
----- 545. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 61893987.27
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 61606156.53
(sw_c, sw_fr) in bit/s: None, 58501483.61
(sw_c, sw_rl) in bit/s: None, 22528958.57
(sw_c, sw_rr) in bit/s: 882759436.45, 53764408.27
(sw_fr, sw_c) in bit/s: 246526917.67, 29190683.72
(sw_fr, zc_fr) in bit/s: None, 56449416.80
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 22136416.55
(sw_rr, sw_c) in bit/s: None, 37921487.43
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 47947007.38
----- 546. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.508ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.510ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 61893987.27
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 61606156.53
(sw_c, sw_fr) in bit/s: None, 58501483.61
(sw_c, sw_rl) in bit/s: None, 22528958.57
(sw_c, sw_rr) in bit/s: 882759436.45, 54437904.65
(sw_fr, sw_c) in bit/s: 246526917.67, 29190683.72
(sw_fr, zc_fr) in bit/s: None, 56449416.80
(sw_rl, sw_c) in bit/s: 246526917.67, 2447467.64
(sw_rl, zc_rl) in bit/s: None, 22136416.55
(sw_rr, sw_c) in bit/s: None, 37921487.43
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 48520995.86
----- 547. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.480ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 26559229.79
(sw_fl, zc_fl) in bit/s: None, 61893987.27
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 61606156.53
(sw_c, sw_fr) in bit/s: None, 58501483.61
(sw_c, sw_rl) in bit/s: None, 22528958.57
(sw_c, sw_rr) in bit/s: 882759436.45, 54966830.11
(sw_fr, sw_c) in bit/s: 246526917.67, 29190683.72
(sw_fr, zc_fr) in bit/s: None, 56449416.80
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 22136416.55
(sw_rr, sw_c) in bit/s: None, 37921487.43
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 49091525.32
----- 548. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27160597.92
(sw_fl, zc_fl) in bit/s: None, 61893987.27
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 61606156.53
(sw_c, sw_fr) in bit/s: None, 58526562.10
(sw_c, sw_rl) in bit/s: None, 22528958.57
(sw_c, sw_rr) in bit/s: 882759436.45, 54966830.11
(sw_fr, sw_c) in bit/s: 246526917.67, 29190683.72
(sw_fr, zc_fr) in bit/s: None, 57010795.09
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 22136416.55
(sw_rr, sw_c) in bit/s: None, 37921487.43
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 49091525.32
----- 549. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27160597.92
(sw_fl, zc_fl) in bit/s: None, 61893987.27
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 61606156.53
(sw_c, sw_fr) in bit/s: None, 58526562.10
(sw_c, sw_rl) in bit/s: None, 22528958.57
(sw_c, sw_rr) in bit/s: 882759436.45, 54966830.11
(sw_fr, sw_c) in bit/s: 246526917.67, 29190683.72
(sw_fr, zc_fr) in bit/s: None, 57010795.09
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 22136416.55
(sw_rr, sw_c) in bit/s: None, 37921487.43
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 49091525.32
----- 550. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.498ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27160597.92
(sw_fl, zc_fl) in bit/s: None, 61893987.27
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 61606156.53
(sw_c, sw_fr) in bit/s: None, 58526562.10
(sw_c, sw_rl) in bit/s: None, 22528958.57
(sw_c, sw_rr) in bit/s: 882759436.45, 55637075.53
(sw_fr, sw_c) in bit/s: 246526917.67, 29190683.72
(sw_fr, zc_fr) in bit/s: None, 57010795.09
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 22136416.55
(sw_rr, sw_c) in bit/s: None, 37921487.43
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 49661393.17
----- 551. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.509ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27160597.92
(sw_fl, zc_fl) in bit/s: None, 61893987.27
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 61606156.53
(sw_c, sw_fr) in bit/s: None, 58526562.10
(sw_c, sw_rl) in bit/s: None, 23056616.47
(sw_c, sw_rr) in bit/s: 882759436.45, 55637075.53
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 57010795.09
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 22737633.06
(sw_rr, sw_c) in bit/s: None, 37921487.43
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 49661393.17
----- 552. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27160597.92
(sw_fl, zc_fl) in bit/s: None, 61893987.27
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 61606156.53
(sw_c, sw_fr) in bit/s: None, 58526562.10
(sw_c, sw_rl) in bit/s: None, 23056616.47
(sw_c, sw_rr) in bit/s: 882759436.45, 55637075.53
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 57010795.09
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 22737633.06
(sw_rr, sw_c) in bit/s: None, 37921487.43
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 49661393.17
----- 553. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.509ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.509ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27160597.92
(sw_fl, zc_fl) in bit/s: None, 62447339.53
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 62209868.25
(sw_c, sw_fr) in bit/s: None, 58526562.10
(sw_c, sw_rl) in bit/s: None, 23056616.47
(sw_c, sw_rr) in bit/s: 882759436.45, 55637075.53
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 57010795.09
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 22737633.06
(sw_rr, sw_c) in bit/s: None, 37921487.43
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 49661393.17
----- 554. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27160597.92
(sw_fl, zc_fl) in bit/s: None, 62447339.53
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 62209868.25
(sw_c, sw_fr) in bit/s: None, 58526562.10
(sw_c, sw_rl) in bit/s: None, 23056616.47
(sw_c, sw_rr) in bit/s: 882759436.45, 55637075.53
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 57010795.09
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 22737633.06
(sw_rr, sw_c) in bit/s: None, 37921487.43
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 49661393.17
----- 555. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.509ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.509ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.511ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27160597.92
(sw_fl, zc_fl) in bit/s: None, 62447339.53
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 62209868.25
(sw_c, sw_fr) in bit/s: None, 58526562.10
(sw_c, sw_rl) in bit/s: None, 23056616.47
(sw_c, sw_rr) in bit/s: 882759436.45, 56417019.23
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 57010795.09
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 22737633.06
(sw_rr, sw_c) in bit/s: None, 37921487.43
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50230308.14
----- 556. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.519ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27160597.92
(sw_fl, zc_fl) in bit/s: None, 62447339.53
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 62209868.25
(sw_c, sw_fr) in bit/s: None, 59697421.77
(sw_c, sw_rl) in bit/s: None, 23056616.47
(sw_c, sw_rr) in bit/s: 882759436.45, 56417019.23
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 57571231.43
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 22737633.06
(sw_rr, sw_c) in bit/s: None, 38500691.35
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50230308.14
----- 557. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27160597.92
(sw_fl, zc_fl) in bit/s: None, 62447339.53
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 62209868.25
(sw_c, sw_fr) in bit/s: None, 59697421.77
(sw_c, sw_rl) in bit/s: None, 23056616.47
(sw_c, sw_rr) in bit/s: 882759436.45, 56417019.23
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 57571231.43
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 22737633.06
(sw_rr, sw_c) in bit/s: None, 38500691.35
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50230308.14
----- 558. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.519ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.519ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27160597.92
(sw_fl, zc_fl) in bit/s: None, 62447339.53
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 62209868.25
(sw_c, sw_fr) in bit/s: None, 59697421.77
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56417019.23
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 57571231.43
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 38500691.35
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50230308.14
----- 559. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27160597.92
(sw_fl, zc_fl) in bit/s: None, 62447339.53
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 62209868.25
(sw_c, sw_fr) in bit/s: None, 59697421.77
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56417019.23
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 57571231.43
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 38500691.35
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50230308.14
----- 560. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.519ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.519ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.519ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27160597.92
(sw_fl, zc_fl) in bit/s: None, 63000089.99
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 63332615.23
(sw_c, sw_fr) in bit/s: None, 59697421.77
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56417019.23
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 57571231.43
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 38500691.35
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50230308.14
----- 561. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.501ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 63000089.99
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 63332615.23
(sw_c, sw_fr) in bit/s: None, 59697421.77
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 57571231.43
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 38500691.35
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 562. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.520ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 63000089.99
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 63332615.23
(sw_c, sw_fr) in bit/s: None, 60312719.82
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 58131129.74
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 39079288.60
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 563. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 63000089.99
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 63332615.23
(sw_c, sw_fr) in bit/s: None, 60312719.82
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 58131129.74
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 39079288.60
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 564. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.520ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.520ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 63552317.50
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 63941452.50
(sw_c, sw_fr) in bit/s: None, 60312719.82
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 58131129.74
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 39079288.60
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 565. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.520ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 63552317.50
(sw_fl, infotainment) in bit/s: None, 19695806.36
(sw_c, sw_fl) in bit/s: None, 63941452.50
(sw_c, sw_fr) in bit/s: None, 60928135.36
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 58690663.92
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 39657399.99
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 566. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.521ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 63552317.50
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 64550377.75
(sw_c, sw_fr) in bit/s: None, 60928135.36
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 58690663.92
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 40234772.88
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 567. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 63552317.50
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 64550377.75
(sw_c, sw_fr) in bit/s: None, 60928135.36
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 58690663.92
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 40234772.88
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 568. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.521ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.521ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 63552317.50
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 64550377.75
(sw_c, sw_fr) in bit/s: None, 61543511.73
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 29768702.97
(sw_fr, zc_fr) in bit/s: None, 59249462.26
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 40234772.88
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 569. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.510ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 64104103.60
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 64511960.03
(sw_c, sw_fr) in bit/s: None, 61543511.73
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 30346213.85
(sw_fr, zc_fr) in bit/s: None, 59249462.26
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 40234772.88
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 570. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.522ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 64655064.00
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 65729333.36
(sw_c, sw_fr) in bit/s: None, 61543511.73
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 30346213.85
(sw_fr, zc_fr) in bit/s: None, 59249462.26
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 40811339.27
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 571. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 64655064.00
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 65729333.36
(sw_c, sw_fr) in bit/s: None, 61543511.73
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 30346213.85
(sw_fr, zc_fr) in bit/s: None, 59249462.26
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 40811339.27
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 572. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.522ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.522ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 64655064.00
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 65729333.36
(sw_c, sw_fr) in bit/s: None, 62158809.78
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 30346213.85
(sw_fr, zc_fr) in bit/s: None, 59807427.35
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 40811339.27
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 573. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.510ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 65205686.94
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 65679237.56
(sw_c, sw_fr) in bit/s: None, 62158809.78
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 59807427.35
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 40811339.27
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 574. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 65205686.94
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 65679237.56
(sw_c, sw_fr) in bit/s: None, 62158809.78
(sw_c, sw_rl) in bit/s: None, 23780524.44
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 59807427.35
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23338141.94
(sw_rr, sw_c) in bit/s: None, 40811339.27
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 575. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.510ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.510ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 65205686.94
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 65679237.56
(sw_c, sw_fr) in bit/s: None, 62158809.78
(sw_c, sw_rl) in bit/s: None, 24288222.58
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 59807427.35
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23938094.57
(sw_rr, sw_c) in bit/s: None, 40811339.27
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 576. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 65205686.94
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 65679237.56
(sw_c, sw_fr) in bit/s: None, 62158809.78
(sw_c, sw_rl) in bit/s: None, 24288222.58
(sw_c, sw_rr) in bit/s: 882759436.45, 56940434.94
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 59807427.35
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23938094.57
(sw_rr, sw_c) in bit/s: None, 40811339.27
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 50798853.05
----- 577. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rl', 'zc_rr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.510ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.510ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.512ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 65205686.94
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 65679237.56
(sw_c, sw_fr) in bit/s: None, 62158809.78
(sw_c, sw_rl) in bit/s: None, 24288222.58
(sw_c, sw_rr) in bit/s: 882759436.45, 57722621.76
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 59807427.35
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23938094.57
(sw_rr, sw_c) in bit/s: None, 40811339.27
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 51366822.81
----- 578. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.522ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 65755583.95
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 66907025.84
(sw_c, sw_fr) in bit/s: None, 62158809.78
(sw_c, sw_rl) in bit/s: None, 24288222.58
(sw_c, sw_rr) in bit/s: 882759436.45, 57722621.76
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 59807427.35
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23938094.57
(sw_rr, sw_c) in bit/s: None, 41387364.25
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 51366822.81
----- 579. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 65755583.95
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 66907025.84
(sw_c, sw_fr) in bit/s: None, 62158809.78
(sw_c, sw_rl) in bit/s: None, 24288222.58
(sw_c, sw_rr) in bit/s: 882759436.45, 57722621.76
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 59807427.35
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23938094.57
(sw_rr, sw_c) in bit/s: None, 41387364.25
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 51366822.81
----- 580. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.522ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.522ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 65755583.95
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 66907025.84
(sw_c, sw_fr) in bit/s: None, 62774186.15
(sw_c, sw_rl) in bit/s: None, 24288222.58
(sw_c, sw_rr) in bit/s: 882759436.45, 57722621.76
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 60364942.48
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23938094.57
(sw_rr, sw_c) in bit/s: None, 41387364.25
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 51366822.81
----- 581. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.167ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 27761244.73
(sw_fl, zc_fl) in bit/s: None, 66342276.90
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 66907025.84
(sw_c, sw_fr) in bit/s: None, 62774186.15
(sw_c, sw_rl) in bit/s: None, 24288222.58
(sw_c, sw_rr) in bit/s: 882759436.45, 57722621.76
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 60364942.48
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 23938094.57
(sw_rr, sw_c) in bit/s: None, 41387364.25
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 51366822.81
----- 582. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 28361045.27
(sw_fl, zc_fl) in bit/s: None, 66342276.90
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 66907025.84
(sw_c, sw_fr) in bit/s: None, 62774186.15
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 57722621.76
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 60364942.48
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 41387364.25
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 51366822.81
----- 583. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 28361045.27
(sw_fl, zc_fl) in bit/s: None, 66342276.90
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 66907025.84
(sw_c, sw_fr) in bit/s: None, 62774186.15
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 57722621.76
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 60364942.48
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 41387364.25
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 51366822.81
----- 584. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 28361045.27
(sw_fl, zc_fl) in bit/s: None, 66342276.90
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 66907025.84
(sw_c, sw_fr) in bit/s: None, 62572292.01
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 57722621.76
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 60921466.90
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 41387364.25
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 51366822.81
----- 585. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 28361045.27
(sw_fl, zc_fl) in bit/s: None, 66342276.90
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 66907025.84
(sw_c, sw_fr) in bit/s: None, 62572292.01
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 57722621.76
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 60921466.90
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 41387364.25
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 51366822.81
----- 586. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.500ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 28361045.27
(sw_fl, zc_fl) in bit/s: None, 66342276.90
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 66907025.84
(sw_c, sw_fr) in bit/s: None, 62572292.01
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 58242124.80
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 60921466.90
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 41387364.25
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 51933751.49
----- 587. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.523ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 28361045.27
(sw_fl, zc_fl) in bit/s: None, 66342276.90
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 66907025.84
(sw_c, sw_fr) in bit/s: None, 63966851.19
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 58242124.80
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 61477701.88
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 41962717.95
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 51933751.49
----- 588. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 28361045.27
(sw_fl, zc_fl) in bit/s: None, 66342276.90
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 66907025.84
(sw_c, sw_fr) in bit/s: None, 63966851.19
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 58242124.80
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 61477701.88
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 41962717.95
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 51933751.49
----- 589. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.523ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.523ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 28361045.27
(sw_fl, zc_fl) in bit/s: None, 66891208.79
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 67515231.03
(sw_c, sw_fr) in bit/s: None, 63966851.19
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 58242124.80
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 61477701.88
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 41962717.95
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 51933751.49
----- 590. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 28361045.27
(sw_fl, zc_fl) in bit/s: None, 66891208.79
(sw_fl, infotainment) in bit/s: None, 20280696.85
(sw_c, sw_fl) in bit/s: None, 67515231.03
(sw_c, sw_fr) in bit/s: None, 63966851.19
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 58242124.80
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 61477701.88
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 41962717.95
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 51933751.49
----- 591. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.523ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.523ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.523ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 28361045.27
(sw_fl, zc_fl) in bit/s: None, 66891208.79
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 67515231.03
(sw_c, sw_fr) in bit/s: None, 63966851.19
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 58242124.80
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 61477701.88
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 41962717.95
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 51933751.49
----- 592. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  60.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 28960345.93
(sw_fl, zc_fl) in bit/s: None, 66891208.79
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 67515231.03
(sw_c, sw_fr) in bit/s: None, 63966851.19
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 58911626.10
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 61477701.88
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 41962717.95
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 52500549.10
----- 593. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 29558835.63
(sw_fl, zc_fl) in bit/s: None, 66891208.79
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 67515231.03
(sw_c, sw_fr) in bit/s: None, 63966851.19
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 59580998.43
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 61477701.88
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 41962717.95
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 53066468.31
----- 594. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.524ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 29558835.63
(sw_fl, zc_fl) in bit/s: None, 67439151.75
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 63966851.19
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 59580998.43
(sw_fr, sw_c) in bit/s: 246526917.67, 30923096.14
(sw_fr, zc_fr) in bit/s: None, 61477701.88
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 53066468.31
----- 595. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.513ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 29558835.63
(sw_fl, zc_fl) in bit/s: None, 67439151.75
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 63966851.19
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 60291132.24
(sw_fr, sw_c) in bit/s: 246526917.67, 31501105.22
(sw_fr, zc_fr) in bit/s: None, 61477701.88
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 53634848.19
----- 596. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.167ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 29558835.63
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 63966851.19
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 60291132.24
(sw_fr, sw_c) in bit/s: 246526917.67, 31501105.22
(sw_fr, zc_fr) in bit/s: None, 61477701.88
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 53634848.19
----- 597. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 29558835.63
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 63966851.19
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 60291132.24
(sw_fr, sw_c) in bit/s: 246526917.67, 31501105.22
(sw_fr, zc_fr) in bit/s: None, 61477701.88
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 53634848.19
----- 598. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.524ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.524ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 29558835.63
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 64581716.54
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 60291132.24
(sw_fr, sw_c) in bit/s: 246526917.67, 31501105.22
(sw_fr, zc_fr) in bit/s: None, 62032942.29
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 53634848.19
----- 599. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 30156487.51
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 64318751.63
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 60291132.24
(sw_fr, sw_c) in bit/s: 246526917.67, 31501105.22
(sw_fr, zc_fr) in bit/s: None, 62587580.93
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 53634848.19
----- 600. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 30156487.51
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 64318751.63
(sw_c, sw_rl) in bit/s: None, 24910954.56
(sw_c, sw_rr) in bit/s: 882759436.45, 60291132.24
(sw_fr, sw_c) in bit/s: 246526917.67, 31501105.22
(sw_fr, zc_fr) in bit/s: None, 62587580.93
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 24537151.17
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 53634848.19
----- 601. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 30156487.51
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 64318751.63
(sw_c, sw_rl) in bit/s: None, 25533693.82
(sw_c, sw_rr) in bit/s: 882759436.45, 60291132.24
(sw_fr, sw_c) in bit/s: 246526917.67, 31501105.22
(sw_fr, zc_fr) in bit/s: None, 62587580.93
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25135505.20
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 53634848.19
----- 602. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 30156487.51
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 64318751.63
(sw_c, sw_rl) in bit/s: None, 25533693.82
(sw_c, sw_rr) in bit/s: 882759436.45, 60291132.24
(sw_fr, sw_c) in bit/s: 246526917.67, 31501105.22
(sw_fr, zc_fr) in bit/s: None, 62587580.93
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25135505.20
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 53634848.19
----- 603. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.502ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.504ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 30156487.51
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 64318751.63
(sw_c, sw_rl) in bit/s: None, 25533693.82
(sw_c, sw_rr) in bit/s: 882759436.45, 60881768.35
(sw_fr, sw_c) in bit/s: 246526917.67, 31501105.22
(sw_fr, zc_fr) in bit/s: None, 62587580.93
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25135505.20
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 54199213.06
----- 604. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.514ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 30156487.51
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 64318751.63
(sw_c, sw_rl) in bit/s: None, 25533693.82
(sw_c, sw_rr) in bit/s: 882759436.45, 61590487.58
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 62587580.93
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25135505.20
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 54762885.66
----- 605. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 30156487.51
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 64318751.63
(sw_c, sw_rl) in bit/s: None, 25533693.82
(sw_c, sw_rr) in bit/s: 882759436.45, 61590487.58
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 62587580.93
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25135505.20
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 54762885.66
----- 606. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.167ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.484ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 30771749.46
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 64925245.92
(sw_c, sw_rl) in bit/s: None, 25533693.82
(sw_c, sw_rr) in bit/s: 882759436.45, 61590487.58
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 63141579.48
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25135505.20
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 54762885.66
----- 607. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 31368433.74
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 65531943.96
(sw_c, sw_rl) in bit/s: None, 25533693.82
(sw_c, sw_rr) in bit/s: 882759436.45, 61590487.58
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 63695265.05
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25135505.20
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 54762885.66
----- 608. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 31368433.74
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 65531943.96
(sw_c, sw_rl) in bit/s: None, 25533693.82
(sw_c, sw_rr) in bit/s: 882759436.45, 61590487.58
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 63695265.05
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25135505.20
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 54762885.66
----- 609. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.504ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 31368433.74
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 65531943.96
(sw_c, sw_rl) in bit/s: None, 25533693.82
(sw_c, sw_rr) in bit/s: 882759436.45, 62179190.71
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 63695265.05
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25135505.20
(sw_rr, sw_c) in bit/s: None, 42537152.56
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 55326222.56
----- 610. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.524ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 31368433.74
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 66922269.54
(sw_c, sw_rl) in bit/s: None, 25533693.82
(sw_c, sw_rr) in bit/s: 882759436.45, 62179190.71
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 64247989.44
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25135505.20
(sw_rr, sw_c) in bit/s: None, 43110939.74
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 55326222.56
----- 611. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 31368433.74
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 66922269.54
(sw_c, sw_rl) in bit/s: None, 25533693.82
(sw_c, sw_rr) in bit/s: 882759436.45, 62179190.71
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 64247989.44
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25135505.20
(sw_rr, sw_c) in bit/s: None, 43110939.74
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 55326222.56
----- 612. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.524ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.524ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 31368433.74
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 66922269.54
(sw_c, sw_rl) in bit/s: None, 26251769.10
(sw_c, sw_rr) in bit/s: 882759436.45, 62179190.71
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 64247989.44
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25733142.28
(sw_rr, sw_c) in bit/s: None, 43110939.74
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 55326222.56
----- 613. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 31368433.74
(sw_fl, zc_fl) in bit/s: None, 68027241.88
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68123270.50
(sw_c, sw_fr) in bit/s: None, 66922269.54
(sw_c, sw_rl) in bit/s: None, 26251769.10
(sw_c, sw_rr) in bit/s: 882759436.45, 62179190.71
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 64247989.44
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25733142.28
(sw_rr, sw_c) in bit/s: None, 43110939.74
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 55326222.56
----- 614. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.524ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.524ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.524ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 31368433.74
(sw_fl, zc_fl) in bit/s: None, 68574276.11
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68731328.39
(sw_c, sw_fr) in bit/s: None, 66922269.54
(sw_c, sw_rl) in bit/s: None, 26251769.10
(sw_c, sw_rr) in bit/s: 882759436.45, 62179190.71
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 64247989.44
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25733142.28
(sw_rr, sw_c) in bit/s: None, 43110939.74
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 55326222.56
----- 615. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fr'] , Bits:  688 , Interval:  150.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.485ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 31983399.47
(sw_fl, zc_fl) in bit/s: None, 68574276.11
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68731328.39
(sw_c, sw_fr) in bit/s: None, 66706013.73
(sw_c, sw_rl) in bit/s: None, 26251769.10
(sw_c, sw_rr) in bit/s: 882759436.45, 62179190.71
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 64800270.33
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25733142.28
(sw_rr, sw_c) in bit/s: None, 43110939.74
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 55326222.56
----- 616. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 31983399.47
(sw_fl, zc_fl) in bit/s: None, 68574276.11
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68731328.39
(sw_c, sw_fr) in bit/s: None, 66706013.73
(sw_c, sw_rl) in bit/s: None, 26251769.10
(sw_c, sw_rr) in bit/s: 882759436.45, 62179190.71
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 64800270.33
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25733142.28
(sw_rr, sw_c) in bit/s: None, 43110939.74
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 55326222.56
----- 617. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.168ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.485ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 32599062.06
(sw_fl, zc_fl) in bit/s: None, 68574276.11
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68731328.39
(sw_c, sw_fr) in bit/s: None, 67313390.48
(sw_c, sw_rl) in bit/s: None, 26251769.10
(sw_c, sw_rr) in bit/s: 882759436.45, 62179190.71
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 65353727.65
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25733142.28
(sw_rr, sw_c) in bit/s: None, 43110939.74
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 55326222.56
----- 618. Flow Operation -- remove -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 32599062.06
(sw_fl, zc_fl) in bit/s: None, 68574276.11
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68731328.39
(sw_c, sw_fr) in bit/s: None, 67313390.48
(sw_c, sw_rl) in bit/s: None, 26251769.10
(sw_c, sw_rr) in bit/s: 882759436.45, 62179190.71
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 65353727.65
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25733142.28
(sw_rr, sw_c) in bit/s: None, 43110939.74
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 55326222.56
----- 619. Flow Operation -- add -----
Flow Details: Source:  infotainment , Destination:  ['zc_fl', 'zc_fr', 'zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.168ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.485ms
Path (from, to, prio):  [('infotainment', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.486ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 32599062.06
(sw_fl, zc_fl) in bit/s: None, 68574276.11
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68731328.39
(sw_c, sw_fr) in bit/s: None, 67313390.48
(sw_c, sw_rl) in bit/s: None, 26251769.10
(sw_c, sw_rr) in bit/s: 882759436.45, 62848500.70
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 65353727.65
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25733142.28
(sw_rr, sw_c) in bit/s: None, 43110939.74
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 55890350.07
----- 620. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 68574276.11
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68731328.39
(sw_c, sw_fr) in bit/s: None, 67919525.48
(sw_c, sw_rl) in bit/s: None, 26251769.10
(sw_c, sw_rr) in bit/s: 882759436.45, 62848500.70
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 65904562.49
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25733142.28
(sw_rr, sw_c) in bit/s: None, 43110939.74
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 55890350.07
----- 621. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 68574276.11
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68731328.39
(sw_c, sw_fr) in bit/s: None, 67919525.48
(sw_c, sw_rl) in bit/s: None, 26251769.10
(sw_c, sw_rr) in bit/s: 882759436.45, 62848500.70
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 65904562.49
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 25733142.28
(sw_rr, sw_c) in bit/s: None, 43110939.74
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 55890350.07
----- 622. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 68574276.11
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68731328.39
(sw_c, sw_fr) in bit/s: None, 67919525.48
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 62848500.70
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 65904562.49
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43110939.74
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 55890350.07
----- 623. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 68574276.11
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68731328.39
(sw_c, sw_fr) in bit/s: None, 67919525.48
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 62848500.70
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 65904562.49
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43110939.74
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 55890350.07
----- 624. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.503ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.505ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 68574276.11
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 68731328.39
(sw_c, sw_fr) in bit/s: None, 67919525.48
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 63516839.15
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 65904562.49
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43110939.74
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 56452112.88
----- 625. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.525ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 69121009.64
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 69339533.58
(sw_c, sw_fr) in bit/s: None, 67919525.48
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 63516839.15
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 65904562.49
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 56452112.88
----- 626. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 69121009.64
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 69339533.58
(sw_c, sw_fr) in bit/s: None, 67919525.48
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 63516839.15
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 65904562.49
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 56452112.88
----- 627. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.525ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.525ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 69121009.64
(sw_fl, infotainment) in bit/s: None, 20864897.92
(sw_c, sw_fl) in bit/s: None, 69339533.58
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 63516839.15
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 56452112.88
----- 628. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  60.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.187ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 69121009.64
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 69339533.58
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 63516839.15
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3057484.41
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 56452112.88
----- 629. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.479ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 69666749.13
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 69091785.15
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 63516839.15
(sw_fr, sw_c) in bit/s: 246526917.67, 32076427.78
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 56452112.88
----- 630. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.512ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 70212028.10
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 69692398.50
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 63516839.15
(sw_fr, sw_c) in bit/s: 246526917.67, 32651153.41
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 56452112.88
----- 631. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 70212028.10
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 69692398.50
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 63516839.15
(sw_fr, sw_c) in bit/s: 246526917.67, 32651153.41
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 56452112.88
----- 632. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.512ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.514ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 70212028.10
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 69692398.50
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 64143736.19
(sw_fr, sw_c) in bit/s: 246526917.67, 32651153.41
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 57013333.29
----- 633. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.515ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 70212028.10
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 69692398.50
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 64812629.60
(sw_fr, sw_c) in bit/s: 246526917.67, 33226178.18
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 57575570.72
----- 634. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 70212028.10
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 69692398.50
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 64812629.60
(sw_fr, sw_c) in bit/s: 246526917.67, 33226178.18
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 57575570.72
----- 635. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rr', 'zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.513ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.515ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 70758572.26
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 70294220.87
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 64812629.60
(sw_fr, sw_c) in bit/s: 246526917.67, 33226178.18
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 57575570.72
----- 636. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.514ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 71306638.55
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 70897386.59
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 64812629.60
(sw_fr, sw_c) in bit/s: 246526917.67, 33801663.73
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 57575570.72
----- 637. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 71306638.55
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 70897386.59
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 64812629.60
(sw_fr, sw_c) in bit/s: 246526917.67, 33801663.73
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 57575570.72
----- 638. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.514ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.516ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 71306638.55
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 70897386.59
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 26762972.79
(sw_c, sw_rr) in bit/s: 882759436.45, 65482557.35
(sw_fr, sw_c) in bit/s: 246526917.67, 33801663.73
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26330063.70
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58139059.71
----- 639. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.515ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 71306638.55
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 70897386.59
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 65482557.35
(sw_fr, sw_c) in bit/s: 246526917.67, 34374342.61
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58139059.71
----- 640. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 71306638.55
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 70897386.59
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 65482557.35
(sw_fr, sw_c) in bit/s: 246526917.67, 34374342.61
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58139059.71
----- 641. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.515ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.515ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 71849968.30
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 71497919.34
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 65482557.35
(sw_fr, sw_c) in bit/s: 246526917.67, 34374342.61
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58139059.71
----- 642. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 71849968.30
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 71497919.34
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 65482557.35
(sw_fr, sw_c) in bit/s: 246526917.67, 34374342.61
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58139059.71
----- 643. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl', 'zc_rr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.515ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.515ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.516ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 71849968.30
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 71497919.34
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66150457.80
(sw_fr, sw_c) in bit/s: 246526917.67, 34374342.61
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 43684280.50
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58698270.42
----- 644. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.526ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 72394737.53
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 72819735.07
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66150457.80
(sw_fr, sw_c) in bit/s: 246526917.67, 34374342.61
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 44258104.75
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58698270.42
----- 645. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 72394737.53
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 72819735.07
(sw_c, sw_fr) in bit/s: None, 69255355.93
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66150457.80
(sw_fr, sw_c) in bit/s: 246526917.67, 34374342.61
(sw_fr, zc_fr) in bit/s: None, 66455103.08
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 44258104.75
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58698270.42
----- 646. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.526ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.526ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 72394737.53
(sw_fl, infotainment) in bit/s: None, 21461073.89
(sw_c, sw_fl) in bit/s: None, 72819735.07
(sw_c, sw_fr) in bit/s: None, 69868918.72
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66150457.80
(sw_fr, sw_c) in bit/s: 246526917.67, 34374342.61
(sw_fr, zc_fr) in bit/s: None, 67006726.12
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 44258104.75
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58698270.42
----- 647. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.515ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 72394737.53
(sw_fl, infotainment) in bit/s: None, 22044148.13
(sw_c, sw_fl) in bit/s: None, 72657892.67
(sw_c, sw_fr) in bit/s: None, 69868918.72
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66150457.80
(sw_fr, sw_c) in bit/s: 246526917.67, 34946321.78
(sw_fr, zc_fr) in bit/s: None, 67006726.12
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 44258104.75
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58698270.42
----- 648. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.516ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 72938916.81
(sw_fl, infotainment) in bit/s: None, 22044148.13
(sw_c, sw_fl) in bit/s: None, 73259379.72
(sw_c, sw_fr) in bit/s: None, 69868918.72
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66150457.80
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 67006726.12
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 44258104.75
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58698270.42
----- 649. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  30.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.526ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 73481780.35
(sw_fl, infotainment) in bit/s: None, 22044148.13
(sw_c, sw_fl) in bit/s: None, 74553484.93
(sw_c, sw_fr) in bit/s: None, 69868918.72
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66150457.80
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 67006726.12
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 44830807.21
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58698270.42
----- 650. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  30.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 73481780.35
(sw_fl, infotainment) in bit/s: None, 22044148.13
(sw_c, sw_fl) in bit/s: None, 74553484.93
(sw_c, sw_fr) in bit/s: None, 69868918.72
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66150457.80
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 67006726.12
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 44830807.21
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58698270.42
----- 651. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl', 'zc_fr'] , Bits:  688 , Interval:  30.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.526ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.527ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 73481780.35
(sw_fl, infotainment) in bit/s: None, 22044148.13
(sw_c, sw_fl) in bit/s: None, 74553484.93
(sw_c, sw_fr) in bit/s: None, 70482172.31
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66150457.80
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 67557031.63
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 44830807.21
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58698270.42
----- 652. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.527ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 73481780.35
(sw_fl, infotainment) in bit/s: None, 22044148.13
(sw_c, sw_fl) in bit/s: None, 74553484.93
(sw_c, sw_fr) in bit/s: None, 71094826.05
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66150457.80
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 68105324.19
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 45401909.20
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58698270.42
----- 653. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 73481780.35
(sw_fl, infotainment) in bit/s: None, 22044148.13
(sw_c, sw_fl) in bit/s: None, 74553484.93
(sw_c, sw_fr) in bit/s: None, 71094826.05
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66150457.80
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 68105324.19
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 45401909.20
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58698270.42
----- 654. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.527ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.527ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 74022624.69
(sw_fl, infotainment) in bit/s: None, 22044148.13
(sw_c, sw_fl) in bit/s: None, 75159350.72
(sw_c, sw_fr) in bit/s: None, 71094826.05
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66150457.80
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 68105324.19
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 45401909.20
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58698270.42
----- 655. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 74022624.69
(sw_fl, infotainment) in bit/s: None, 22044148.13
(sw_c, sw_fl) in bit/s: None, 75159350.72
(sw_c, sw_fr) in bit/s: None, 71094826.05
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66150457.80
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 68105324.19
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 45401909.20
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58698270.42
----- 656. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_fl', 'infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.527ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.527ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.527ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 74022624.69
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75159350.72
(sw_c, sw_fr) in bit/s: None, 71094826.05
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66150457.80
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 68105324.19
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 45401909.20
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58698270.42
----- 657. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 74022624.69
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75159350.72
(sw_c, sw_fr) in bit/s: None, 71094826.05
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66150457.80
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 68105324.19
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 45401909.20
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 58698270.42
----- 658. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['infotainment', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.516ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.518ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 74022624.69
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75159350.72
(sw_c, sw_fr) in bit/s: None, 71094826.05
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66818337.56
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 68105324.19
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 45401909.20
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 59256795.03
----- 659. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 74022624.69
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75159350.72
(sw_c, sw_fr) in bit/s: None, 71094826.05
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 66818337.56
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 68105324.19
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 45401909.20
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 59256795.03
----- 660. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.516ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.518ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 74022624.69
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75159350.72
(sw_c, sw_fr) in bit/s: None, 71094826.05
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 67487230.98
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 68105324.19
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 45401909.20
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 59816553.63
----- 661. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  20.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.528ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 74022624.69
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75159350.72
(sw_c, sw_fr) in bit/s: None, 71708388.84
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 67487230.98
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 68655129.53
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 45973803.31
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 59816553.63
----- 662. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment'] , Bits:  688 , Interval:  60.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33194185.61
(sw_fl, zc_fl) in bit/s: None, 74022624.69
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75159350.72
(sw_c, sw_fr) in bit/s: None, 71708388.84
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 67487230.98
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 68655129.53
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 45973803.31
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 59816553.63
----- 663. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['infotainment', 'zc_fr'] , Bits:  688 , Interval:  60.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 2.308ms
Reservation Dependent Flow Delay: 1.187ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.504ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33788831.81
(sw_fl, zc_fl) in bit/s: None, 74022624.69
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75159350.72
(sw_c, sw_fr) in bit/s: None, 71351509.96
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 67487230.98
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 69202869.61
(sw_rl, sw_c) in bit/s: 246526917.67, 3666745.10
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 45973803.31
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 59816553.63
----- 664. Flow Operation -- add -----
Flow Details: Source:  zc_rl , Destination:  ['zc_rr'] , Bits:  688 , Interval:  200.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rl', 'sw_rl', 1), ('sw_rl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.481ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33788831.81
(sw_fl, zc_fl) in bit/s: None, 74022624.69
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75159350.72
(sw_c, sw_fr) in bit/s: None, 71351509.96
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 67935496.87
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 69202869.61
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 45973803.31
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 60373955.75
----- 665. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  10.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.529ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33788831.81
(sw_fl, zc_fl) in bit/s: None, 74567231.24
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75767280.92
(sw_c, sw_fr) in bit/s: None, 71351509.96
(sw_c, sw_rl) in bit/s: None, 27385333.45
(sw_c, sw_rr) in bit/s: 882759436.45, 67935496.87
(sw_fr, sw_c) in bit/s: 246526917.67, 35518760.92
(sw_fr, zc_fr) in bit/s: None, 69202869.61
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 26926270.75
(sw_rr, sw_c) in bit/s: None, 46546573.69
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 60373955.75
----- 666. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.517ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33788831.81
(sw_fl, zc_fl) in bit/s: None, 74567231.24
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75767280.92
(sw_c, sw_fr) in bit/s: None, 71351509.96
(sw_c, sw_rl) in bit/s: None, 28007775.04
(sw_c, sw_rr) in bit/s: 882759436.45, 67935496.87
(sw_fr, sw_c) in bit/s: 246526917.67, 36089677.25
(sw_fr, zc_fr) in bit/s: None, 69202869.61
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 27521953.89
(sw_rr, sw_c) in bit/s: None, 46546573.69
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 60373955.75
----- 667. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33788831.81
(sw_fl, zc_fl) in bit/s: None, 74567231.24
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75767280.92
(sw_c, sw_fr) in bit/s: None, 71351509.96
(sw_c, sw_rl) in bit/s: None, 28007775.04
(sw_c, sw_rr) in bit/s: 882759436.45, 67935496.87
(sw_fr, sw_c) in bit/s: 246526917.67, 36089677.25
(sw_fr, zc_fr) in bit/s: None, 69202869.61
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 27521953.89
(sw_rr, sw_c) in bit/s: None, 46546573.69
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 60373955.75
----- 668. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.517ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.517ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33788831.81
(sw_fl, zc_fl) in bit/s: None, 75107383.60
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75532047.01
(sw_c, sw_fr) in bit/s: None, 71351509.96
(sw_c, sw_rl) in bit/s: None, 28007775.04
(sw_c, sw_rr) in bit/s: 882759436.45, 67935496.87
(sw_fr, sw_c) in bit/s: 246526917.67, 36089677.25
(sw_fr, zc_fr) in bit/s: None, 69202869.61
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 27521953.89
(sw_rr, sw_c) in bit/s: None, 46546573.69
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 60373955.75
----- 669. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33788831.81
(sw_fl, zc_fl) in bit/s: None, 75107383.60
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75532047.01
(sw_c, sw_fr) in bit/s: None, 71351509.96
(sw_c, sw_rl) in bit/s: None, 28007775.04
(sw_c, sw_rr) in bit/s: 882759436.45, 67935496.87
(sw_fr, sw_c) in bit/s: 246526917.67, 36089677.25
(sw_fr, zc_fr) in bit/s: None, 69202869.61
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 27521953.89
(sw_rr, sw_c) in bit/s: None, 46546573.69
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 60373955.75
----- 670. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_rl', 'zc_fl', 'zc_rr'] , Bits:  688 , Interval:  80.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.517ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.517ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.518ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33788831.81
(sw_fl, zc_fl) in bit/s: None, 75107383.60
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75532047.01
(sw_c, sw_fr) in bit/s: None, 71351509.96
(sw_c, sw_rl) in bit/s: None, 28007775.04
(sw_c, sw_rr) in bit/s: 882759436.45, 68823311.15
(sw_fr, sw_c) in bit/s: 246526917.67, 36089677.25
(sw_fr, zc_fr) in bit/s: None, 69202869.61
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 27521953.89
(sw_rr, sw_c) in bit/s: None, 46546573.69
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 60931008.28
----- 671. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.529ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33788831.81
(sw_fl, zc_fl) in bit/s: None, 75107383.60
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75532047.01
(sw_c, sw_fr) in bit/s: None, 72890941.40
(sw_c, sw_rl) in bit/s: None, 28007775.04
(sw_c, sw_rr) in bit/s: 882759436.45, 68823311.15
(sw_fr, sw_c) in bit/s: 246526917.67, 36089677.25
(sw_fr, zc_fr) in bit/s: None, 69749341.20
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 27521953.89
(sw_rr, sw_c) in bit/s: None, 47115753.66
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 60931008.28
----- 672. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33788831.81
(sw_fl, zc_fl) in bit/s: None, 75107383.60
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75532047.01
(sw_c, sw_fr) in bit/s: None, 72890941.40
(sw_c, sw_rl) in bit/s: None, 28007775.04
(sw_c, sw_rr) in bit/s: 882759436.45, 68823311.15
(sw_fr, sw_c) in bit/s: 246526917.67, 36089677.25
(sw_fr, zc_fr) in bit/s: None, 69749341.20
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 27521953.89
(sw_rr, sw_c) in bit/s: None, 47115753.66
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 60931008.28
----- 673. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.529ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.529ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 33788831.81
(sw_fl, zc_fl) in bit/s: None, 75107383.60
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75532047.01
(sw_c, sw_fr) in bit/s: None, 72890941.40
(sw_c, sw_rl) in bit/s: None, 28734443.93
(sw_c, sw_rr) in bit/s: 882759436.45, 68823311.15
(sw_fr, sw_c) in bit/s: 246526917.67, 36089677.25
(sw_fr, zc_fr) in bit/s: None, 69749341.20
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 28116740.10
(sw_rr, sw_c) in bit/s: None, 47115753.66
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 60931008.28
----- 674. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.505ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 34382511.16
(sw_fl, zc_fl) in bit/s: None, 75107383.60
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75532047.01
(sw_c, sw_fr) in bit/s: None, 72517913.11
(sw_c, sw_rl) in bit/s: None, 28734443.93
(sw_c, sw_rr) in bit/s: 882759436.45, 68823311.15
(sw_fr, sw_c) in bit/s: 246526917.67, 36089677.25
(sw_fr, zc_fr) in bit/s: None, 70295142.05
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 28116740.10
(sw_rr, sw_c) in bit/s: None, 47115753.66
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 60931008.28
----- 675. Flow Operation -- remove -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 34382511.16
(sw_fl, zc_fl) in bit/s: None, 75107383.60
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 75532047.01
(sw_c, sw_fr) in bit/s: None, 72517913.11
(sw_c, sw_rl) in bit/s: None, 28734443.93
(sw_c, sw_rr) in bit/s: 882759436.45, 68823311.15
(sw_fr, sw_c) in bit/s: 246526917.67, 36089677.25
(sw_fr, zc_fr) in bit/s: None, 70295142.05
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 28116740.10
(sw_rr, sw_c) in bit/s: None, 47115753.66
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 60931008.28
----- 676. Flow Operation -- add -----
Flow Details: Source:  zc_rr , Destination:  ['zc_fr', 'zc_rl', 'zc_fl'] , Bits:  688 , Interval:  500.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.529ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.529ms
Path (from, to, prio):  [('zc_rr', 'sw_rr', 1), ('sw_rr', 'sw_c', 1), ('sw_c', 'sw_rl', 1), ('sw_rl', 'zc_rl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.529ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 34382511.16
(sw_fl, zc_fl) in bit/s: None, 75646455.25
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 76934149.26
(sw_c, sw_fr) in bit/s: None, 72517913.11
(sw_c, sw_rl) in bit/s: None, 28734443.93
(sw_c, sw_rr) in bit/s: 882759436.45, 68823311.15
(sw_fr, sw_c) in bit/s: 246526917.67, 36089677.25
(sw_fr, zc_fr) in bit/s: None, 70295142.05
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 28116740.10
(sw_rr, sw_c) in bit/s: None, 47115753.66
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 60931008.28
----- 677. Flow Operation -- remove -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 34382511.16
(sw_fl, zc_fl) in bit/s: None, 75646455.25
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 76934149.26
(sw_c, sw_fr) in bit/s: None, 72517913.11
(sw_c, sw_rl) in bit/s: None, 28734443.93
(sw_c, sw_rr) in bit/s: 882759436.45, 68823311.15
(sw_fr, sw_c) in bit/s: 246526917.67, 36089677.25
(sw_fr, zc_fr) in bit/s: None, 70295142.05
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 28116740.10
(sw_rr, sw_c) in bit/s: None, 47115753.66
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 60931008.28
----- 678. Flow Operation -- add -----
Flow Details: Source:  zc_fl , Destination:  ['zc_fr', 'zc_rr'] , Bits:  688 , Interval:  1000.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_fr', 1), ('sw_fr', 'zc_fr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.505ms
Path (from, to, prio):  [('zc_fl', 'sw_fl', 1), ('sw_fl', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.506ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 34382511.16
(sw_fl, zc_fl) in bit/s: None, 75646455.25
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 76934149.26
(sw_c, sw_fr) in bit/s: None, 72517913.11
(sw_c, sw_rl) in bit/s: None, 28734443.93
(sw_c, sw_rr) in bit/s: 882759436.45, 69222551.89
(sw_fr, sw_c) in bit/s: 246526917.67, 36089677.25
(sw_fr, zc_fr) in bit/s: None, 70295142.05
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 28116740.10
(sw_rr, sw_c) in bit/s: None, 47115753.66
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 61486971.02
----- 679. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.517ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 34382511.16
(sw_fl, zc_fl) in bit/s: None, 76185273.64
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 76686053.82
(sw_c, sw_fr) in bit/s: None, 72517913.11
(sw_c, sw_rl) in bit/s: None, 28734443.93
(sw_c, sw_rr) in bit/s: 882759436.45, 69222551.89
(sw_fr, sw_c) in bit/s: 246526917.67, 36659868.09
(sw_fr, zc_fr) in bit/s: None, 70295142.05
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 28116740.10
(sw_rr, sw_c) in bit/s: None, 47115753.66
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 61486971.02
----- 680. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 34382511.16
(sw_fl, zc_fl) in bit/s: None, 76185273.64
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 76686053.82
(sw_c, sw_fr) in bit/s: None, 72517913.11
(sw_c, sw_rl) in bit/s: None, 28734443.93
(sw_c, sw_rr) in bit/s: 882759436.45, 69222551.89
(sw_fr, sw_c) in bit/s: 246526917.67, 36659868.09
(sw_fr, zc_fr) in bit/s: None, 70295142.05
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 28116740.10
(sw_rr, sw_c) in bit/s: None, 47115753.66
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 61486971.02
----- 681. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.517ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.519ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 34382511.16
(sw_fl, zc_fl) in bit/s: None, 76185273.64
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 76686053.82
(sw_c, sw_fr) in bit/s: None, 72517913.11
(sw_c, sw_rl) in bit/s: None, 28734443.93
(sw_c, sw_rr) in bit/s: 882759436.45, 70113960.18
(sw_fr, sw_c) in bit/s: 246526917.67, 36659868.09
(sw_fr, zc_fr) in bit/s: None, 70295142.05
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 28116740.10
(sw_rr, sw_c) in bit/s: None, 47115753.66
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 62042648.38
----- 682. Flow Operation -- remove -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Flow not reserved!
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 34382511.16
(sw_fl, zc_fl) in bit/s: None, 76185273.64
(sw_fl, infotainment) in bit/s: None, 22626528.81
(sw_c, sw_fl) in bit/s: None, 76686053.82
(sw_c, sw_fr) in bit/s: None, 72517913.11
(sw_c, sw_rl) in bit/s: None, 28734443.93
(sw_c, sw_rr) in bit/s: 882759436.45, 70113960.18
(sw_fr, sw_c) in bit/s: 246526917.67, 36659868.09
(sw_fr, zc_fr) in bit/s: None, 70295142.05
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 28116740.10
(sw_rr, sw_c) in bit/s: None, 47115753.66
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 62042648.38
----- 683. Flow Operation -- add -----
Flow Details: Source:  zc_fr , Destination:  ['zc_fl', 'zc_rr', 'infotainment'] , Bits:  688 , Interval:  100.000 ms , Deadline:  10.000 ms , User-Defined-Priority:  1 , Redundant Transm.: False
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'infotainment', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.517ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_fl', 1), ('sw_fl', 'zc_fl', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.517ms
Path (from, to, prio):  [('zc_fr', 'sw_fr', 1), ('sw_fr', 'sw_c', 1), ('sw_c', 'sw_rr', 1), ('sw_rr', 'zc_rr', 1)]
Reservation Independent Flow Delay: 4.624ms
Reservation Dependent Flow Delay: 3.519ms
Hop (from, to): slope for highest prio, slope for second highest prio, ...
(sw_fl, sw_c) in bit/s: 61132657.01, 34382511.16
(sw_fl, zc_fl) in bit/s: None, 76185273.64
(sw_fl, infotainment) in bit/s: None, 23208314.38
(sw_c, sw_fl) in bit/s: None, 76686053.82
(sw_c, sw_fr) in bit/s: None, 72517913.11
(sw_c, sw_rl) in bit/s: None, 28734443.93
(sw_c, sw_rr) in bit/s: 882759436.45, 70113960.18
(sw_fr, sw_c) in bit/s: 246526917.67, 36659868.09
(sw_fr, zc_fr) in bit/s: None, 70295142.05
(sw_rl, sw_c) in bit/s: 246526917.67, 4275272.44
(sw_rl, zc_rl) in bit/s: None, 28116740.10
(sw_rr, sw_c) in bit/s: None, 47115753.66
(sw_rr, adas) in bit/s: 821764366.71, None
(sw_rr, zc_rr) in bit/s: None, 62042648.38
--------------------------------
Successfully reserved flows:  447  of  211
Unsuccessful reservations:  0
Total flow operations: 683
------- Finished -------
Min. Calculation Time:  7.176399230957031e-05
Max. Calculation Time:  0.001111745834350586
Avg. Calculation Time:  0.0004185600476244009
----- End Online Admission ----
