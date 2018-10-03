EESchema Schematic File Version 4
LIBS:AC_Power_Meter-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 15 16
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
L Relay_SolidState:FOD4218 U?
U 1 1 5BB3E612
P 4610 3480
F 0 "U?" H 4410 3680 50  0000 L CNN
F 1 "FOD4218" H 4610 3680 50  0000 L CNN
F 2 "" H 4410 3280 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/FO/FOD4218.pdf" H 4585 3480 50  0001 L CNN
F 4 "FOD4218S-ND" H 4610 3480 50  0001 C CNN "Digi-Key PN"
	1    4610 3480
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BB3E8D8
P 4230 3660
F 0 "#PWR?" H 4230 3410 50  0001 C CNN
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
L Custom_Library:R_Custom R?
U 1 1 5BB41BDF
P 3790 3380
F 0 "R?" V 3690 3380 50  0000 C CNN
F 1 "220" V 3790 3380 50  0000 C CNN
F 2 "" H 3790 3380 50  0001 C CNN
F 3 "" H 3790 3380 50  0001 C CNN
F 4 "0603" V 3890 3380 50  0000 C CNN "display_footprint"
F 5 "1%" V 3990 3380 50  0000 C CNN "Tolerance"
F 6 "1/10W" V 4090 3380 50  0000 C CNN "Wattage"
F 7 "PN" H 4090 3780 60  0001 C CNN "Digi-Key PN"
	1    3790 3380
	0    1    1    0   
$EndComp
Wire Wire Line
	3940 3380 4310 3380
Text GLabel 3640 3380 0    50   Input ~ 0
Drive_TRIAC
$Comp
L Triac_Thyristor:BT139-600 Q?
U 1 1 5BB4256C
P 6260 3600
F 0 "Q?" H 6460 3675 50  0000 L CNN
F 1 "BT139-600" H 6460 3600 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 6460 3525 50  0001 L CIN
F 3 "https://www.rapidonline.com/pdf/47-3240.pdf" H 6260 3600 50  0001 L CNN
F 4 "1740-1050-ND" H 6260 3600 50  0001 C CNN "Digi-Key PN"
	1    6260 3600
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB4310F
P 5590 3380
F 0 "R?" V 5490 3380 50  0000 C CNN
F 1 "180" V 5590 3380 50  0000 C CNN
F 2 "" H 5590 3380 50  0001 C CNN
F 3 "" H 5590 3380 50  0001 C CNN
F 4 "2512" V 5690 3380 50  0000 C CNN "display_footprint"
F 5 "1%" V 5790 3380 50  0000 C CNN "Tolerance"
F 6 "1W" V 5890 3380 50  0000 C CNN "Wattage"
F 7 "PN" H 5890 3780 60  0001 C CNN "Digi-Key PN"
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
AR Path="/5BB31314/5BB439FA" Ref="R?"  Part="1" 
F 0 "R?" H 5380 3980 50  0000 R CNN
F 1 "1k" V 5460 3980 50  0000 C CNN
F 2 "" H 5460 3980 50  0001 C CNN
F 3 "" H 5460 3980 50  0001 C CNN
F 4 "2512" H 5560 4060 50  0000 L CNN "display_footprint"
F 5 "1%" H 5560 3980 50  0000 L CNN "Tolerance"
F 6 "1W" H 5570 3900 50  0000 L CNN "Wattage"
F 7 "PN" H 5760 4380 60  0001 C CNN "Digi-Key PN"
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
AR Path="/5BB31314/5BB44391" Ref="R?"  Part="1" 
F 0 "R?" H 7240 3600 50  0000 R CNN
F 1 "39" V 7320 3600 50  0000 C CNN
F 2 "" H 7320 3600 50  0001 C CNN
F 3 "" H 7320 3600 50  0001 C CNN
F 4 "2512" H 7420 3680 50  0000 L CNN "display_footprint"
F 5 "1%" H 7420 3600 50  0000 L CNN "Tolerance"
F 6 "1W" H 7430 3520 50  0000 L CNN "Wattage"
F 7 "PN" H 7620 4000 60  0001 C CNN "Digi-Key PN"
	1    7320 3600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7320 3450 7320 3380
Wire Wire Line
	7320 3380 6260 3380
Connection ~ 6260 3380
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB444F5
P 7320 3980
F 0 "C?" H 7345 4080 50  0000 L CNN
F 1 "10nF" H 7345 3880 50  0000 L CNN
F 2 "" H 7358 3830 50  0001 C CNN
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
$EndSCHEMATC
