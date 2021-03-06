EESchema Schematic File Version 4
LIBS:AC_Power_Meter-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 16 17
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
L Custom_Library:R_Custom R?
U 1 1 5BB80212
P 2630 2740
AR Path="/5BB27BA3/5BB80212" Ref="R?"  Part="1" 
AR Path="/5BB27B51/5BB80212" Ref="R?"  Part="1" 
AR Path="/5BB7FA89/5BB80212" Ref="R1603"  Part="1" 
F 0 "R1603" H 2550 2740 50  0000 R CNN
F 1 "1k" V 2630 2740 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2630 2740 50  0001 C CNN
F 3 "" H 2630 2740 50  0001 C CNN
F 4 "0603" H 2730 2820 50  0000 L CNN "display_footprint"
F 5 "1%" H 2730 2740 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 2740 2660 50  0000 L CNN "Wattage"
F 7 "MCT0603-1.00K-CFCT-ND" H 2930 3140 60  0001 C CNN "Digi-Key PN"
	1    2630 2740
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:LED_ALT_Custom D?
U 1 1 5BB8021D
P 2630 2340
AR Path="/5BB27B51/5BB8021D" Ref="D?"  Part="1" 
AR Path="/5BB7FA89/5BB8021D" Ref="D1601"  Part="1" 
F 0 "D1601" V 2630 2440 50  0000 L CNN
F 1 "Red" V 2700 2210 50  0000 R CNN
F 2 "LEDs:LED_0603" H 2630 2340 50  0001 C CNN
F 3 "" H 2630 2340 50  0001 C CNN
F 4 "0603" V 2620 2210 50  0000 R CNN "display_footprint"
F 5 "160-1447-1-ND" H 2830 2640 60  0001 C CNN "Digi-Key PN"
	1    2630 2340
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2630 2590 2630 2490
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB8025C
P 1430 2630
AR Path="/5BB27BA3/5BB8025C" Ref="R?"  Part="1" 
AR Path="/5BB27B51/5BB8025C" Ref="R?"  Part="1" 
AR Path="/5BB7FA89/5BB8025C" Ref="R1601"  Part="1" 
F 0 "R1601" H 1350 2630 50  0000 R CNN
F 1 "10k" V 1430 2630 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 1430 2630 50  0001 C CNN
F 3 "" H 1430 2630 50  0001 C CNN
F 4 "0603" H 1530 2710 50  0000 L CNN "display_footprint"
F 5 "1%" H 1530 2630 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 1540 2550 50  0000 L CNN "Wattage"
F 7 "RHM10KADCT-ND" H 1730 3030 60  0001 C CNN "Digi-Key PN"
	1    1430 2630
	1    0    0    -1  
$EndComp
Text GLabel 1350 3140 0    50   Input ~ 0
~Active
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB81340
P 4890 2740
AR Path="/5BB27BA3/5BB81340" Ref="R?"  Part="1" 
AR Path="/5BB27B51/5BB81340" Ref="R?"  Part="1" 
AR Path="/5BB7FA89/5BB81340" Ref="R1608"  Part="1" 
F 0 "R1608" H 4810 2740 50  0000 R CNN
F 1 "1k" V 4890 2740 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 4890 2740 50  0001 C CNN
F 3 "" H 4890 2740 50  0001 C CNN
F 4 "0603" H 4990 2820 50  0000 L CNN "display_footprint"
F 5 "1%" H 4990 2740 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 5000 2660 50  0000 L CNN "Wattage"
F 7 "MCT0603-1.00K-CFCT-ND" H 5190 3140 60  0001 C CNN "Digi-Key PN"
	1    4890 2740
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:LED_ALT_Custom D?
U 1 1 5BB8134B
P 4890 2340
AR Path="/5BB27B51/5BB8134B" Ref="D?"  Part="1" 
AR Path="/5BB7FA89/5BB8134B" Ref="D1604"  Part="1" 
F 0 "D1604" V 4890 2440 50  0000 L CNN
F 1 "Green" V 4960 2210 50  0000 R CNN
F 2 "LEDs:LED_0603" H 4890 2340 50  0001 C CNN
F 3 "" H 4890 2340 50  0001 C CNN
F 4 "0603" V 4880 2210 50  0000 R CNN "display_footprint"
F 5 "160-1446-1-ND" H 5090 2640 60  0001 C CNN "Digi-Key PN"
	1    4890 2340
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4890 2590 4890 2490
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB81374
P 3690 3470
AR Path="/5BB27BA3/5BB81374" Ref="R?"  Part="1" 
AR Path="/5BB27B51/5BB81374" Ref="R?"  Part="1" 
AR Path="/5BB7FA89/5BB81374" Ref="R1606"  Part="1" 
F 0 "R1606" H 3610 3470 50  0000 R CNN
F 1 "10k" V 3690 3470 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 3690 3470 50  0001 C CNN
F 3 "" H 3690 3470 50  0001 C CNN
F 4 "0603" H 3790 3550 50  0000 L CNN "display_footprint"
F 5 "1%" H 3790 3470 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 3800 3390 50  0000 L CNN "Wattage"
F 7 "RHM10KADCT-ND" H 3990 3870 60  0001 C CNN "Digi-Key PN"
	1    3690 3470
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01614
U 1 1 5BB8137B
P 3690 3620
F 0 "#PWR01614" H 3690 3370 50  0001 C CNN
F 1 "GND" H 3690 3470 50  0000 C CNN
F 2 "" H 3690 3620 50  0001 C CNN
F 3 "" H 3690 3620 50  0001 C CNN
	1    3690 3620
	1    0    0    -1  
$EndComp
Wire Wire Line
	3690 3320 3690 3140
Text GLabel 3610 3140 0    50   Input ~ 0
Heartbeat
Wire Wire Line
	3610 3140 3690 3140
Connection ~ 3690 3140
Wire Wire Line
	1350 3140 1430 3140
Wire Wire Line
	1430 2780 1430 3140
Connection ~ 1430 3140
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB83381
P 7320 2740
AR Path="/5BB27BA3/5BB83381" Ref="R?"  Part="1" 
AR Path="/5BB27B51/5BB83381" Ref="R?"  Part="1" 
AR Path="/5BB7FA89/5BB83381" Ref="R1611"  Part="1" 
F 0 "R1611" H 7240 2740 50  0000 R CNN
F 1 "1k" V 7320 2740 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 7320 2740 50  0001 C CNN
F 3 "" H 7320 2740 50  0001 C CNN
F 4 "0603" H 7420 2820 50  0000 L CNN "display_footprint"
F 5 "1%" H 7420 2740 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 7430 2660 50  0000 L CNN "Wattage"
F 7 "MCT0603-1.00K-CFCT-ND" H 7620 3140 60  0001 C CNN "Digi-Key PN"
	1    7320 2740
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:LED_ALT_Custom D?
U 1 1 5BB8338C
P 7320 2340
AR Path="/5BB27B51/5BB8338C" Ref="D?"  Part="1" 
AR Path="/5BB7FA89/5BB8338C" Ref="D1605"  Part="1" 
F 0 "D1605" V 7320 2440 50  0000 L CNN
F 1 "Red" V 7390 2210 50  0000 R CNN
F 2 "LEDs:LED_0603" H 7320 2340 50  0001 C CNN
F 3 "" H 7320 2340 50  0001 C CNN
F 4 "0603" V 7310 2210 50  0000 R CNN "display_footprint"
F 5 "160-1447-1-ND" H 7520 2640 60  0001 C CNN "Digi-Key PN"
	1    7320 2340
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7320 2590 7320 2490
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB833B5
P 6120 3470
AR Path="/5BB27BA3/5BB833B5" Ref="R?"  Part="1" 
AR Path="/5BB27B51/5BB833B5" Ref="R?"  Part="1" 
AR Path="/5BB7FA89/5BB833B5" Ref="R1609"  Part="1" 
F 0 "R1609" H 6040 3470 50  0000 R CNN
F 1 "10k" V 6120 3470 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 6120 3470 50  0001 C CNN
F 3 "" H 6120 3470 50  0001 C CNN
F 4 "0603" H 6220 3550 50  0000 L CNN "display_footprint"
F 5 "1%" H 6220 3470 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 6230 3390 50  0000 L CNN "Wattage"
F 7 "RHM10KADCT-ND" H 6420 3870 60  0001 C CNN "Digi-Key PN"
	1    6120 3470
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01625
U 1 1 5BB833BC
P 6120 3620
F 0 "#PWR01625" H 6120 3370 50  0001 C CNN
F 1 "GND" H 6120 3470 50  0000 C CNN
F 2 "" H 6120 3620 50  0001 C CNN
F 3 "" H 6120 3620 50  0001 C CNN
	1    6120 3620
	1    0    0    -1  
$EndComp
Wire Wire Line
	6120 3320 6120 3140
Text GLabel 6040 3140 0    50   Input ~ 0
ADC_Error
Wire Wire Line
	6040 3140 6120 3140
Connection ~ 6120 3140
$Comp
L Custom_Library:LED_ALT_Custom D?
U 1 1 5BB83BD0
P 2630 4980
AR Path="/5BB27B51/5BB83BD0" Ref="D?"  Part="1" 
AR Path="/5BB7FA89/5BB83BD0" Ref="D1602"  Part="1" 
F 0 "D1602" V 2630 5080 50  0000 L CNN
F 1 "Green" V 2700 4850 50  0000 R CNN
F 2 "LEDs:LED_0603" H 2630 4980 50  0001 C CNN
F 3 "" H 2630 4980 50  0001 C CNN
F 4 "0603" V 2620 4850 50  0000 R CNN "display_footprint"
F 5 "160-1446-1-ND" H 2830 5280 60  0001 C CNN "Digi-Key PN"
	1    2630 4980
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2630 5230 2630 5130
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB83BF9
P 1430 6110
AR Path="/5BB27BA3/5BB83BF9" Ref="R?"  Part="1" 
AR Path="/5BB27B51/5BB83BF9" Ref="R?"  Part="1" 
AR Path="/5BB7FA89/5BB83BF9" Ref="R1602"  Part="1" 
F 0 "R1602" H 1350 6110 50  0000 R CNN
F 1 "10k" V 1430 6110 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 1430 6110 50  0001 C CNN
F 3 "" H 1430 6110 50  0001 C CNN
F 4 "0603" H 1530 6190 50  0000 L CNN "display_footprint"
F 5 "1%" H 1530 6110 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 1540 6030 50  0000 L CNN "Wattage"
F 7 "RHM10KADCT-ND" H 1730 6510 60  0001 C CNN "Digi-Key PN"
	1    1430 6110
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01602
U 1 1 5BB83C00
P 1430 6260
F 0 "#PWR01602" H 1430 6010 50  0001 C CNN
F 1 "GND" H 1430 6110 50  0000 C CNN
F 2 "" H 1430 6260 50  0001 C CNN
F 3 "" H 1430 6260 50  0001 C CNN
	1    1430 6260
	1    0    0    -1  
$EndComp
Wire Wire Line
	1430 5960 1430 5780
Text GLabel 1350 5780 0    50   Input ~ 0
Comm_Error
Wire Wire Line
	1350 5780 1430 5780
Connection ~ 1430 5780
Text Notes 540  690  0    100  ~ 20
Status LEDs
$Comp
L Custom_Library:MU_Logo #G1601
U 1 1 5BB6AE86
P 9900 1100
F 0 "#G1601" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q1401
U 1 1 5BBE1E2B
P 2530 3140
F 0 "Q1401" H 2730 3215 50  0000 L CNN
F 1 "2N7002" H 2730 3140 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 2730 3065 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7002.pdf" H 2530 3140 50  0001 L CNN
	1    2530 3140
	1    0    0    -1  
$EndComp
Wire Wire Line
	2630 2940 2630 2890
$Comp
L power:GND #PWR01408
U 1 1 5BBE20B0
P 2630 3340
F 0 "#PWR01408" H 2630 3090 50  0001 C CNN
F 1 "GND" H 2630 3190 50  0000 C CNN
F 2 "" H 2630 3340 50  0001 C CNN
F 3 "" H 2630 3340 50  0001 C CNN
	1    2630 3340
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R1405
U 1 1 5BBE2548
P 2010 3140
F 0 "R1405" V 1910 3140 50  0000 C CNN
F 1 "10" V 2010 3140 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2010 3140 50  0001 C CNN
F 3 "" H 2010 3140 50  0001 C CNN
F 4 "0603" V 2110 3140 50  0000 C CNN "display_footprint"
F 5 "1%" V 2210 3140 50  0000 C CNN "Tolerance"
F 6 "1/10" V 2310 3140 50  0000 C CNN "Wattage"
F 7 "MCT0603-10.0-CFCT-ND" H 2310 3540 60  0001 C CNN "Digi-Key PN"
	1    2010 3140
	0    1    1    0   
$EndComp
Wire Wire Line
	2160 3140 2330 3140
Wire Wire Line
	1430 3140 1860 3140
$Comp
L Transistor_FET:2N7002 Q1403
U 1 1 5BBE338B
P 4790 3140
F 0 "Q1403" H 4990 3215 50  0000 L CNN
F 1 "2N7002" H 4990 3140 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 4990 3065 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7002.pdf" H 4790 3140 50  0001 L CNN
	1    4790 3140
	1    0    0    -1  
$EndComp
Wire Wire Line
	4890 2940 4890 2890
$Comp
L power:GND #PWR01419
U 1 1 5BBE3393
P 4890 3340
F 0 "#PWR01419" H 4890 3090 50  0001 C CNN
F 1 "GND" H 4890 3190 50  0000 C CNN
F 2 "" H 4890 3340 50  0001 C CNN
F 3 "" H 4890 3340 50  0001 C CNN
	1    4890 3340
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R1407
U 1 1 5BBE339D
P 4270 3140
F 0 "R1407" V 4170 3140 50  0000 C CNN
F 1 "10" V 4270 3140 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 4270 3140 50  0001 C CNN
F 3 "" H 4270 3140 50  0001 C CNN
F 4 "0603" V 4370 3140 50  0000 C CNN "display_footprint"
F 5 "1%" V 4470 3140 50  0000 C CNN "Tolerance"
F 6 "1/10" V 4570 3140 50  0000 C CNN "Wattage"
F 7 "MCT0603-10.0-CFCT-ND" H 4570 3540 60  0001 C CNN "Digi-Key PN"
	1    4270 3140
	0    1    1    0   
$EndComp
Wire Wire Line
	4420 3140 4590 3140
Wire Wire Line
	3690 3140 4120 3140
$Comp
L Transistor_FET:2N7002 Q1404
U 1 1 5BBE3958
P 7220 3140
F 0 "Q1404" H 7420 3215 50  0000 L CNN
F 1 "2N7002" H 7420 3140 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 7420 3065 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7002.pdf" H 7220 3140 50  0001 L CNN
	1    7220 3140
	1    0    0    -1  
$EndComp
Wire Wire Line
	7320 2940 7320 2890
$Comp
L power:GND #PWR01420
U 1 1 5BBE3960
P 7320 3340
F 0 "#PWR01420" H 7320 3090 50  0001 C CNN
F 1 "GND" H 7320 3190 50  0000 C CNN
F 2 "" H 7320 3340 50  0001 C CNN
F 3 "" H 7320 3340 50  0001 C CNN
	1    7320 3340
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R1408
U 1 1 5BBE396A
P 6700 3140
F 0 "R1408" V 6600 3140 50  0000 C CNN
F 1 "10" V 6700 3140 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 6700 3140 50  0001 C CNN
F 3 "" H 6700 3140 50  0001 C CNN
F 4 "0603" V 6800 3140 50  0000 C CNN "display_footprint"
F 5 "1%" V 6900 3140 50  0000 C CNN "Tolerance"
F 6 "1/10" V 7000 3140 50  0000 C CNN "Wattage"
F 7 "MCT0603-10.0-CFCT-ND" H 7000 3540 60  0001 C CNN "Digi-Key PN"
	1    6700 3140
	0    1    1    0   
$EndComp
Wire Wire Line
	6850 3140 7020 3140
Wire Wire Line
	6120 3140 6550 3140
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BBE3FFA
P 2630 5380
AR Path="/5BB27BA3/5BBE3FFA" Ref="R?"  Part="1" 
AR Path="/5BB27B51/5BBE3FFA" Ref="R?"  Part="1" 
AR Path="/5BB7FA89/5BBE3FFA" Ref="R1604"  Part="1" 
F 0 "R1604" H 2550 5380 50  0000 R CNN
F 1 "1k" V 2630 5380 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2630 5380 50  0001 C CNN
F 3 "" H 2630 5380 50  0001 C CNN
F 4 "0603" H 2730 5460 50  0000 L CNN "display_footprint"
F 5 "1%" H 2730 5380 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 2740 5300 50  0000 L CNN "Wattage"
F 7 "MCT0603-1.00K-CFCT-ND" H 2930 5780 60  0001 C CNN "Digi-Key PN"
	1    2630 5380
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q1402
U 1 1 5BBE410D
P 2530 5780
F 0 "Q1402" H 2730 5855 50  0000 L CNN
F 1 "2N7002" H 2730 5780 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 2730 5705 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7002.pdf" H 2530 5780 50  0001 L CNN
	1    2530 5780
	1    0    0    -1  
$EndComp
Wire Wire Line
	2630 5580 2630 5530
$Comp
L power:GND #PWR01411
U 1 1 5BBE4115
P 2630 5980
F 0 "#PWR01411" H 2630 5730 50  0001 C CNN
F 1 "GND" H 2630 5830 50  0000 C CNN
F 2 "" H 2630 5980 50  0001 C CNN
F 3 "" H 2630 5980 50  0001 C CNN
	1    2630 5980
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R1406
U 1 1 5BBE411F
P 2010 5780
F 0 "R1406" V 1910 5780 50  0000 C CNN
F 1 "10" V 2010 5780 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2010 5780 50  0001 C CNN
F 3 "" H 2010 5780 50  0001 C CNN
F 4 "0603" V 2110 5780 50  0000 C CNN "display_footprint"
F 5 "1%" V 2210 5780 50  0000 C CNN "Tolerance"
F 6 "1/10" V 2310 5780 50  0000 C CNN "Wattage"
F 7 "MCT0603-10.0-CFCT-ND" H 2310 6180 60  0001 C CNN "Digi-Key PN"
	1    2010 5780
	0    1    1    0   
$EndComp
Wire Wire Line
	2160 5780 2330 5780
Wire Wire Line
	1430 5780 1860 5780
$Comp
L power:+3.3V #PWR?
U 1 1 5BF3FEED
P 2630 2190
F 0 "#PWR?" H 2630 2040 50  0001 C CNN
F 1 "+3.3V" H 2630 2330 50  0000 C CNN
F 2 "" H 2630 2190 50  0001 C CNN
F 3 "" H 2630 2190 50  0001 C CNN
	1    2630 2190
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF3FF9F
P 1430 2480
F 0 "#PWR?" H 1430 2330 50  0001 C CNN
F 1 "+3.3V" H 1430 2620 50  0000 C CNN
F 2 "" H 1430 2480 50  0001 C CNN
F 3 "" H 1430 2480 50  0001 C CNN
	1    1430 2480
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF3FFD2
P 4890 2190
F 0 "#PWR?" H 4890 2040 50  0001 C CNN
F 1 "+3.3V" H 4890 2330 50  0000 C CNN
F 2 "" H 4890 2190 50  0001 C CNN
F 3 "" H 4890 2190 50  0001 C CNN
	1    4890 2190
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF400A5
P 7320 2190
F 0 "#PWR?" H 7320 2040 50  0001 C CNN
F 1 "+3.3V" H 7320 2330 50  0000 C CNN
F 2 "" H 7320 2190 50  0001 C CNN
F 3 "" H 7320 2190 50  0001 C CNN
	1    7320 2190
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF401A0
P 2630 4830
F 0 "#PWR?" H 2630 4680 50  0001 C CNN
F 1 "+3.3V" H 2630 4970 50  0000 C CNN
F 2 "" H 2630 4830 50  0001 C CNN
F 3 "" H 2630 4830 50  0001 C CNN
	1    2630 4830
	1    0    0    -1  
$EndComp
$EndSCHEMATC
