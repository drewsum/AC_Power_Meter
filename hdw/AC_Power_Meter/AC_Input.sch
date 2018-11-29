EESchema Schematic File Version 4
LIBS:AC_Power_Meter-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 2 17
Title ""
Date "2018-10-01"
Rev "A"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:Earth_Protective #PWR0201
U 1 1 5BB4A2E5
P 4890 4120
F 0 "#PWR0201" H 5140 3870 50  0001 C CNN
F 1 "Earth_Protective" H 5340 3970 50  0001 C CNN
F 2 "" H 4890 4020 50  0001 C CNN
F 3 "~" H 4890 4020 50  0001 C CNN
	1    4890 4120
	1    0    0    -1  
$EndComp
Wire Wire Line
	4890 4120 4890 4040
Wire Wire Line
	4890 4040 4810 4040
$Comp
L Device:Fuse F201
U 1 1 5BB4B169
P 5180 3240
F 0 "F201" V 5260 3240 50  0000 C CNN
F 1 "15A" V 5105 3240 50  0000 C CNN
F 2 "Fuse_Holders_and_Fuses:Fuse_CB61F" V 5110 3240 50  0001 C CNN
F 3 "~" H 5180 3240 50  0001 C CNN
F 4 "283-4372-1-ND" H 5180 3240 50  0001 C CNN "Digi-Key PN"
	1    5180 3240
	0    1    1    0   
$EndComp
Wire Wire Line
	5030 3240 4810 3240
$Comp
L power:HT #PWR0202
U 1 1 5BB4B805
P 5410 3160
F 0 "#PWR0202" H 5410 3280 50  0001 C CNN
F 1 "HT" H 5410 3250 50  0000 C CNN
F 2 "" H 5410 3160 50  0001 C CNN
F 3 "" H 5410 3160 50  0001 C CNN
	1    5410 3160
	1    0    0    -1  
$EndComp
Wire Wire Line
	5410 3160 5410 3240
Wire Wire Line
	5410 3240 5330 3240
$Comp
L power:NEUT #PWR0203
U 1 1 5BB4B8DC
P 5410 3720
F 0 "#PWR0203" H 5410 3570 50  0001 C CNN
F 1 "NEUT" H 5410 3870 50  0000 C CNN
F 2 "" H 5410 3720 50  0001 C CNN
F 3 "" H 5410 3720 50  0001 C CNN
	1    5410 3720
	-1   0    0    1   
$EndComp
Wire Wire Line
	5410 3720 5410 3640
Wire Wire Line
	4810 3640 5410 3640
$Comp
L Connector_Generic:Conn_01x01 J201
U 1 1 5BB4D19A
P 4610 3240
F 0 "J201" H 4610 3340 50  0000 C CNN
F 1 "HT_IN" H 4610 3140 50  0000 C CNN
F 2 "Custom Footprints Library:Keystone_8191" H 4610 3240 50  0001 C CNN
F 3 "~" H 4610 3240 50  0001 C CNN
F 4 "36-8191-ND" H 4610 3240 50  0001 C CNN "Digi-Key PN"
	1    4610 3240
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J202
U 1 1 5BB4D248
P 4610 3640
F 0 "J202" H 4610 3740 50  0000 C CNN
F 1 "NEUT_IN" H 4610 3540 50  0000 C CNN
F 2 "Custom Footprints Library:Keystone_8191" H 4610 3640 50  0001 C CNN
F 3 "~" H 4610 3640 50  0001 C CNN
F 4 "36-8191-ND" H 4610 3640 50  0001 C CNN "Digi-Key PN"
	1    4610 3640
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J203
U 1 1 5BB4D2A4
P 4610 4040
F 0 "J203" H 4610 4140 50  0000 C CNN
F 1 "EARTH_IN" H 4610 3940 50  0000 C CNN
F 2 "Custom Footprints Library:Keystone_8191" H 4610 4040 50  0001 C CNN
F 3 "~" H 4610 4040 50  0001 C CNN
F 4 "36-8191-ND" H 4610 4040 50  0001 C CNN "Digi-Key PN"
	1    4610 4040
	-1   0    0    -1  
$EndComp
Text Notes 2960 3690 0    50   ~ 0
From Panel AC Input Socket ->
Text Notes 540  690  0    100  ~ 20
AC Input Connections
$Comp
L Custom_Library:MU_Logo #G201
U 1 1 5BB67903
P 9900 1100
F 0 "#G201" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_WallPlug_Earth P?
U 1 1 5BBD4895
P 2520 3560
AR Path="/5BB27C33/5BBD4895" Ref="P?"  Part="1" 
AR Path="/5BB27B1A/5BBD4895" Ref="P201"  Part="1" 
F 0 "P201" H 2520 3710 50  0000 C BNN
F 1 "AC In Socket" V 2320 3560 50  0000 C BNN
F 2 "" H 2920 3560 50  0001 C CNN
F 3 "~" H 2920 3560 50  0001 C CNN
F 4 "Q223-ND" H 2520 3560 50  0001 C CNN "Digi-Key PN"
	1    2520 3560
	1    0    0    -1  
$EndComp
NoConn ~ 2820 3460
NoConn ~ 2820 3660
NoConn ~ 2820 3860
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5BBA6FA3
P 5750 3220
F 0 "#FLG0101" H 5750 3295 50  0001 C CNN
F 1 "PWR_FLAG" H 5750 3370 50  0000 C CNN
F 2 "" H 5750 3220 50  0001 C CNN
F 3 "~" H 5750 3220 50  0001 C CNN
	1    5750 3220
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 3220 5750 3240
Wire Wire Line
	5750 3240 5410 3240
Connection ~ 5410 3240
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5BBA7038
P 5750 3720
F 0 "#FLG0102" H 5750 3795 50  0001 C CNN
F 1 "PWR_FLAG" H 5750 3870 50  0000 C CNN
F 2 "" H 5750 3720 50  0001 C CNN
F 3 "~" H 5750 3720 50  0001 C CNN
	1    5750 3720
	-1   0    0    1   
$EndComp
Wire Wire Line
	5750 3720 5750 3640
Wire Wire Line
	5750 3640 5410 3640
Connection ~ 5410 3640
$Comp
L power:PWR_FLAG #FLG0106
U 1 1 5BBB71E9
P 5310 4120
F 0 "#FLG0106" H 5310 4195 50  0001 C CNN
F 1 "PWR_FLAG" H 5310 4270 50  0000 C CNN
F 2 "" H 5310 4120 50  0001 C CNN
F 3 "~" H 5310 4120 50  0001 C CNN
	1    5310 4120
	-1   0    0    1   
$EndComp
Wire Wire Line
	5310 4120 5310 4040
Wire Wire Line
	5310 4040 4890 4040
Connection ~ 4890 4040
$Comp
L Custom_Library:Screw MK?
U 1 1 5BBA935B
P 2020 2100
AR Path="/5BB27C33/5BBA935B" Ref="MK?"  Part="1" 
AR Path="/5BB27B1A/5BBA935B" Ref="MK201"  Part="1" 
F 0 "MK201" H 2020 2200 50  0000 C CNN
F 1 "4-40 Screw" H 2020 2300 50  0000 C CNN
F 2 "" H 2020 2350 50  0001 C CNN
F 3 "" H 2020 2350 50  0001 C CNN
F 4 "36-9502-ND" H 2020 2100 50  0001 C CNN "Digi-Key PN"
	1    2020 2100
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:Screw MK?
U 1 1 5BBA9363
P 2770 2100
AR Path="/5BB27C33/5BBA9363" Ref="MK?"  Part="1" 
AR Path="/5BB27B1A/5BBA9363" Ref="MK203"  Part="1" 
F 0 "MK203" H 2770 2200 50  0000 C CNN
F 1 "4-40 Screw" H 2770 2300 50  0000 C CNN
F 2 "" H 2770 2350 50  0001 C CNN
F 3 "" H 2770 2350 50  0001 C CNN
F 4 "36-9502-ND" H 2770 2100 50  0001 C CNN "Digi-Key PN"
	1    2770 2100
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:Nut MK202
U 1 1 5BBAE4E8
P 2020 2520
F 0 "MK202" H 2020 2570 50  0000 C CNN
F 1 "Nut" H 2020 2670 50  0000 C CNN
F 2 "" H 2020 2870 50  0001 C CNN
F 3 "" H 2020 2870 50  0001 C CNN
F 4 "36-4694-ND" H 2020 2520 50  0001 C CNN "Digi-Key PN"
	1    2020 2520
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:Nut MK204
U 1 1 5BBAEFC1
P 2770 2520
F 0 "MK204" H 2770 2570 50  0000 C CNN
F 1 "Nut" H 2770 2670 50  0000 C CNN
F 2 "" H 2770 2870 50  0001 C CNN
F 3 "" H 2770 2870 50  0001 C CNN
F 4 "36-4694-ND" H 2770 2520 50  0001 C CNN "Digi-Key PN"
	1    2770 2520
	1    0    0    -1  
$EndComp
$EndSCHEMATC
