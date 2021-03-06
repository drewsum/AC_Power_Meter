EESchema Schematic File Version 4
LIBS:AC_Power_Meter-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 15 17
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Relay_SolidState:FOD4218 U1502
U 1 1 5BB3E612
P 4610 3480
F 0 "U1502" H 4410 3680 50  0000 L CNN
F 1 "FOD4218" H 4610 3280 50  0000 C CNN
F 2 "Housings_DIP:SMDIP-6_W7.62mm" H 4410 3280 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/FO/FOD4218.pdf" H 4585 3480 50  0001 L CNN
F 4 "FOD4218S-ND" H 4610 3480 50  0001 C CNN "Digi-Key PN"
	1    4610 3480
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01507
U 1 1 5BB3E8D8
P 4230 3660
F 0 "#PWR01507" H 4230 3410 50  0001 C CNN
F 1 "GND" H 4230 3510 50  0000 C CNN
F 2 "" H 4230 3660 50  0001 C CNN
F 3 "" H 4230 3660 50  0001 C CNN
	1    4230 3660
	1    0    0    -1  
$EndComp
Wire Wire Line
	4230 3660 4230 3580
Wire Wire Line
	4230 3580 4310 3580
$Comp
L Custom_Library:R_Custom R1503
U 1 1 5BB41BDF
P 3790 3380
F 0 "R1503" V 3690 3380 50  0000 C CNN
F 1 "220" V 3790 3380 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3790 3380 50  0001 C CNN
F 3 "" H 3790 3380 50  0001 C CNN
F 4 "0603" V 3890 3380 50  0000 C CNN "display_footprint"
F 5 "1%" V 3990 3380 50  0000 C CNN "Tolerance"
F 6 "1/10W" V 4090 3380 50  0000 C CNN "Wattage"
F 7 "311-220HRCT-ND" H 4090 3780 60  0001 C CNN "Digi-Key PN"
	1    3790 3380
	0    1    1    0   
$EndComp
Wire Wire Line
	3940 3380 4310 3380
Text GLabel 1580 3430 0    50   Input ~ 0
SSR_Force
$Comp
L Triac_Thyristor:BT139-600 Q1501
U 1 1 5BB4256C
P 6260 3600
F 0 "Q1501" H 6460 3675 50  0000 L CNN
F 1 "BT139-600" H 6460 3600 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220-3_Vertical" H 6460 3525 50  0001 L CIN
F 3 "https://www.rapidonline.com/pdf/47-3240.pdf" H 6260 3600 50  0001 L CNN
F 4 "1740-1050-ND" H 6260 3600 50  0001 C CNN "Digi-Key PN"
	1    6260 3600
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R1505
U 1 1 5BB4310F
P 5590 3380
F 0 "R1505" V 5490 3380 50  0000 C CNN
F 1 "180" V 5590 3380 50  0000 C CNN
F 2 "Resistors_SMD:R_2512" H 5590 3380 50  0001 C CNN
F 3 "" H 5590 3380 50  0001 C CNN
F 4 "2512" V 5690 3380 50  0000 C CNN "display_footprint"
F 5 "1%" V 5790 3380 50  0000 C CNN "Tolerance"
F 6 "1W" V 5890 3380 50  0000 C CNN "Wattage"
F 7 "A115990CT-ND" H 5890 3780 60  0001 C CNN "Digi-Key PN"
	1    5590 3380
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5740 3380 6260 3380
Wire Wire Line
	6260 3380 6260 3450
Wire Wire Line
	5440 3380 4910 3380
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB439FA
P 5460 3980
AR Path="/5BB27BA3/5BB439FA" Ref="R?"  Part="1" 
AR Path="/5BB27BE1/5BB439FA" Ref="R?"  Part="1" 
AR Path="/5BB31311/5BB439FA" Ref="R?"  Part="1" 
AR Path="/5BB31314/5BB439FA" Ref="R1504"  Part="1" 
AR Path="/5BBE5EA9/5BB439FA" Ref="R1504"  Part="1" 
F 0 "R1504" H 5380 3980 50  0000 R CNN
F 1 "1k" V 5460 3980 50  0000 C CNN
F 2 "Resistors_SMD:R_2512" H 5460 3980 50  0001 C CNN
F 3 "" H 5460 3980 50  0001 C CNN
F 4 "2512" H 5560 4060 50  0000 L CNN "display_footprint"
F 5 "5%" H 5560 3980 50  0000 L CNN "Tolerance"
F 6 "1W" H 5570 3900 50  0000 L CNN "Wattage"
F 7 "541-1.0KXCT-ND" H 5760 4380 60  0001 C CNN "Digi-Key PN"
	1    5460 3980
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6110 3700 5460 3700
Wire Wire Line
	5460 3700 5460 3580
Wire Wire Line
	5460 3580 4910 3580
Wire Wire Line
	5460 3830 5460 3700
Connection ~ 5460 3700
Wire Wire Line
	6260 3750 6260 4210
Wire Wire Line
	6260 4210 5460 4210
Wire Wire Line
	5460 4210 5460 4130
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB44391
P 7320 3600
AR Path="/5BB27BA3/5BB44391" Ref="R?"  Part="1" 
AR Path="/5BB27BE1/5BB44391" Ref="R?"  Part="1" 
AR Path="/5BB31311/5BB44391" Ref="R?"  Part="1" 
AR Path="/5BB31314/5BB44391" Ref="R1506"  Part="1" 
AR Path="/5BBE5EA9/5BB44391" Ref="R1506"  Part="1" 
F 0 "R1506" H 7240 3600 50  0000 R CNN
F 1 "39" V 7320 3600 50  0000 C CNN
F 2 "Resistors_SMD:R_2512" H 7320 3600 50  0001 C CNN
F 3 "" H 7320 3600 50  0001 C CNN
F 4 "2512" H 7420 3680 50  0000 L CNN "display_footprint"
F 5 "5%" H 7420 3600 50  0000 L CNN "Tolerance"
F 6 "1W" H 7430 3520 50  0000 L CNN "Wattage"
F 7 "541-39XCT-ND" H 7620 4000 60  0001 C CNN "Digi-Key PN"
	1    7320 3600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7320 3450 7320 3380
Wire Wire Line
	7320 3380 6260 3380
Connection ~ 6260 3380
$Comp
L Custom_Library:C_Custom C1502
U 1 1 5BB444F5
P 7320 3980
F 0 "C1502" H 7345 4080 50  0000 L CNN
F 1 "10nF" H 7345 3880 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206" H 7358 3830 50  0001 C CNN
F 3 "" H 7345 4080 50  0001 C CNN
F 4 "445-2291-1-ND" H 7745 4480 60  0001 C CNN "Digi-Key PN"
F 5 "1206" H 7170 4080 50  0000 R CNN "display_footprint"
F 6 "630V" H 7170 3980 50  0000 R CNN "Voltage"
F 7 "X7R" H 7170 3880 50  0000 R CNN "Dielectric"
	1    7320 3980
	1    0    0    -1  
$EndComp
Wire Wire Line
	7320 3830 7320 3750
Wire Wire Line
	7320 4130 7320 4210
Wire Wire Line
	7320 4210 6260 4210
Connection ~ 6260 4210
Text GLabel 7650 3380 2    50   Input ~ 0
ISNS_HT_OUT
Wire Wire Line
	7650 3380 7320 3380
Connection ~ 7320 3380
Text GLabel 7650 4210 2    50   Output ~ 0
TRIAC_HT_OUT
Wire Wire Line
	7650 4210 7320 4210
Connection ~ 7320 4210
Text Notes 540  690  0    100  ~ 20
Output AC Solid State Switch, Random Phase
$Comp
L Custom_Library:MU_Logo #G1501
U 1 1 5BB6B3BC
P 9900 1100
F 0 "#G1501" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:74LVC1G32_Power U1501
U 1 1 5BB650E5
P 3050 3380
F 0 "U1501" H 3150 3530 50  0000 L CNN
F 1 "74LVC1G32" H 3150 3230 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-353_SC-70-5" H 3050 3380 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 3050 3380 50  0001 C CNN
F 4 "296-9848-1-ND" H 3050 3380 50  0001 C CNN "Digi-Key PN"
	1    3050 3380
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01504
U 1 1 5BB65527
P 3050 3480
F 0 "#PWR01504" H 3050 3230 50  0001 C CNN
F 1 "GND" H 3050 3330 50  0000 C CNN
F 2 "" H 3050 3480 50  0001 C CNN
F 3 "" H 3050 3480 50  0001 C CNN
	1    3050 3480
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 3380 3640 3380
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB662D3
P 2460 3700
AR Path="/5BB27BA3/5BB662D3" Ref="R?"  Part="1" 
AR Path="/5BB27B51/5BB662D3" Ref="R?"  Part="1" 
AR Path="/5BB7FA89/5BB662D3" Ref="R?"  Part="1" 
AR Path="/5BB31314/5BB662D3" Ref="R1502"  Part="1" 
AR Path="/5BBE5EA9/5BB662D3" Ref="R1502"  Part="1" 
F 0 "R1502" H 2380 3700 50  0000 R CNN
F 1 "10k" V 2460 3700 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2460 3700 50  0001 C CNN
F 3 "" H 2460 3700 50  0001 C CNN
F 4 "0603" H 2560 3780 50  0000 L CNN "display_footprint"
F 5 "1%" H 2560 3700 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 2570 3620 50  0000 L CNN "Wattage"
F 7 "RHM10KADCT-ND" H 2760 4100 60  0001 C CNN "Digi-Key PN"
	1    2460 3700
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB6645C
P 1790 3700
AR Path="/5BB27BA3/5BB6645C" Ref="R?"  Part="1" 
AR Path="/5BB27B51/5BB6645C" Ref="R?"  Part="1" 
AR Path="/5BB7FA89/5BB6645C" Ref="R?"  Part="1" 
AR Path="/5BB31314/5BB6645C" Ref="R1501"  Part="1" 
AR Path="/5BBE5EA9/5BB6645C" Ref="R1501"  Part="1" 
F 0 "R1501" H 1710 3700 50  0000 R CNN
F 1 "10k" V 1790 3700 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 1790 3700 50  0001 C CNN
F 3 "" H 1790 3700 50  0001 C CNN
F 4 "0603" H 1890 3780 50  0000 L CNN "display_footprint"
F 5 "1%" H 1890 3700 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 1900 3620 50  0000 L CNN "Wattage"
F 7 "RHM10KADCT-ND" H 2090 4100 60  0001 C CNN "Digi-Key PN"
	1    1790 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01502
U 1 1 5BB664BB
P 2460 3850
F 0 "#PWR01502" H 2460 3600 50  0001 C CNN
F 1 "GND" H 2460 3700 50  0000 C CNN
F 2 "" H 2460 3850 50  0001 C CNN
F 3 "" H 2460 3850 50  0001 C CNN
	1    2460 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01501
U 1 1 5BB664E1
P 1790 3850
F 0 "#PWR01501" H 1790 3600 50  0001 C CNN
F 1 "GND" H 1790 3700 50  0000 C CNN
F 2 "" H 1790 3850 50  0001 C CNN
F 3 "" H 1790 3850 50  0001 C CNN
	1    1790 3850
	1    0    0    -1  
$EndComp
Text GLabel 1580 3330 0    50   Input ~ 0
SSR_Dim
Wire Wire Line
	1580 3330 1790 3330
Wire Wire Line
	1580 3430 2460 3430
Wire Wire Line
	1790 3550 1790 3330
Connection ~ 1790 3330
Wire Wire Line
	1790 3330 2750 3330
Wire Wire Line
	2460 3550 2460 3430
Connection ~ 2460 3430
Wire Wire Line
	2460 3430 2750 3430
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB67D0F
P 3280 4080
AR Path="/5BB27BA3/5BB67D0F" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB67D0F" Ref="C?"  Part="1" 
AR Path="/5BB27B24/5BB67D0F" Ref="C?"  Part="1" 
AR Path="/5BB27B51/5BB67D0F" Ref="C?"  Part="1" 
AR Path="/5BB31314/5BB67D0F" Ref="C1501"  Part="1" 
AR Path="/5BBE5EA9/5BB67D0F" Ref="C1501"  Part="1" 
F 0 "C1501" H 3305 4180 50  0000 L CNN
F 1 "0.1uF" H 3305 3980 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3318 3930 50  0001 C CNN
F 3 "" H 3305 4180 50  0001 C CNN
F 4 "0603" H 3130 4180 50  0000 R CNN "display_footprint"
F 5 "50V" H 3130 4080 50  0000 R CNN "Voltage"
F 6 "X7R" H 3130 3980 50  0000 R CNN "Dielectric"
F 7 "490-8020-1-ND" H 3705 4580 60  0001 C CNN "Digi-Key PN"
	1    3280 4080
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BB67D16
P 3280 4230
AR Path="/5BB27B1A/5BB67D16" Ref="#PWR?"  Part="1" 
AR Path="/5BB27B51/5BB67D16" Ref="#PWR?"  Part="1" 
AR Path="/5BB31314/5BB67D16" Ref="#PWR01506"  Part="1" 
AR Path="/5BBE5EA9/5BB67D16" Ref="#PWR01506"  Part="1" 
F 0 "#PWR01506" H 3280 3980 50  0001 C CNN
F 1 "GND" H 3280 4080 50  0000 C CNN
F 2 "" H 3280 4230 50  0001 C CNN
F 3 "" H 3280 4230 50  0001 C CNN
	1    3280 4230
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Heatsink HS1501
U 1 1 5BC1D984
P 6260 3190
F 0 "HS1501" H 6260 3390 50  0000 C CNN
F 1 "Heatsink" H 6260 3140 50  0000 C CNN
F 2 "" H 6272 3190 50  0001 C CNN
F 3 "" H 6272 3190 50  0001 C CNN
	1    6260 3190
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF3EDCB
P 3280 3930
F 0 "#PWR?" H 3280 3780 50  0001 C CNN
F 1 "+3.3V" H 3280 4070 50  0000 C CNN
F 2 "" H 3280 3930 50  0001 C CNN
F 3 "" H 3280 3930 50  0001 C CNN
	1    3280 3930
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF3EDF5
P 3050 3280
F 0 "#PWR?" H 3050 3130 50  0001 C CNN
F 1 "+3.3V" H 3050 3420 50  0000 C CNN
F 2 "" H 3050 3280 50  0001 C CNN
F 3 "" H 3050 3280 50  0001 C CNN
	1    3050 3280
	1    0    0    -1  
$EndComp
$EndSCHEMATC
