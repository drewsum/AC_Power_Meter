EESchema Schematic File Version 4
LIBS:AC_Power_Meter-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 2 16
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
L power:Earth_Protective #PWR?
U 1 1 5BB4A2E5
P 4890 4120
F 0 "#PWR?" H 5140 3870 50  0001 C CNN
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
L Device:Fuse F?
U 1 1 5BB4B169
P 5180 3240
F 0 "F?" V 5260 3240 50  0000 C CNN
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
L power:HT #PWR?
U 1 1 5BB4B805
P 5410 3160
F 0 "#PWR?" H 5410 3280 50  0001 C CNN
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
L power:NEUT #PWR?
U 1 1 5BB4B8DC
P 5410 3720
F 0 "#PWR?" H 5410 3570 50  0001 C CNN
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
L Connector_Generic:Conn_01x01 J?
U 1 1 5BB4D19A
P 4610 3240
F 0 "J?" H 4610 3340 50  0000 C CNN
F 1 "HT_IN" H 4610 3140 50  0000 C CNN
F 2 "" H 4610 3240 50  0001 C CNN
F 3 "~" H 4610 3240 50  0001 C CNN
	1    4610 3240
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J?
U 1 1 5BB4D248
P 4610 3640
F 0 "J?" H 4610 3740 50  0000 C CNN
F 1 "NEUT_IN" H 4610 3540 50  0000 C CNN
F 2 "" H 4610 3640 50  0001 C CNN
F 3 "~" H 4610 3640 50  0001 C CNN
	1    4610 3640
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J?
U 1 1 5BB4D2A4
P 4610 4040
F 0 "J?" H 4610 4140 50  0000 C CNN
F 1 "EARTH_IN" H 4610 3940 50  0000 C CNN
F 2 "" H 4610 4040 50  0001 C CNN
F 3 "~" H 4610 4040 50  0001 C CNN
	1    4610 4040
	-1   0    0    -1  
$EndComp
Text Notes 2960 3690 0    50   ~ 0
From Panel AC Input Socket ->
Text Notes 540  690  0    100  ~ 20
AC Input Connections
$Comp
L Custom_Library:MU_Logo #G?
U 1 1 5BB67903
P 9900 1100
F 0 "#G?" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
$EndSCHEMATC
