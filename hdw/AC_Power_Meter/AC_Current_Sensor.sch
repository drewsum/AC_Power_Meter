EESchema Schematic File Version 4
LIBS:AC_Power_Meter-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 3 17
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
L Custom_Library:C_Custom C?
U 1 1 5BB2A066
P 4970 5070
AR Path="/5BB27BA3/5BB2A066" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB2A066" Ref="C?"  Part="1" 
AR Path="/5BB27B24/5BB2A066" Ref="C301"  Part="1" 
F 0 "C301" H 4995 5170 50  0000 L CNN
F 1 "0.1uF" H 4995 4970 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5008 4920 50  0001 C CNN
F 3 "" H 4995 5170 50  0001 C CNN
F 4 "0603" H 4820 5170 50  0000 R CNN "display_footprint"
F 5 "50V" H 4820 5070 50  0000 R CNN "Voltage"
F 6 "X7R" H 4820 4970 50  0000 R CNN "Dielectric"
F 7 "490-8020-1-ND" H 5395 5570 60  0001 C CNN "Digi-Key PN"
	1    4970 5070
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB2A071
P 5320 5070
AR Path="/5BB27BA3/5BB2A071" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB2A071" Ref="C?"  Part="1" 
AR Path="/5BB27B24/5BB2A071" Ref="C302"  Part="1" 
F 0 "C302" H 5345 5170 50  0000 L CNN
F 1 "10nF" H 5345 4970 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5358 4920 50  0001 C CNN
F 3 "" H 5345 5170 50  0001 C CNN
F 4 "0603" H 5170 5170 50  0001 R CNN "display_footprint"
F 5 "50V" H 5170 5070 50  0001 R CNN "Voltage"
F 6 "X7R" H 5170 4970 50  0001 R CNN "Dielectric"
F 7 "1276-1921-1-ND" H 5745 5570 60  0001 C CNN "Digi-Key PN"
	1    5320 5070
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB2A07C
P 5670 5070
AR Path="/5BB27BA3/5BB2A07C" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB2A07C" Ref="C?"  Part="1" 
AR Path="/5BB27B24/5BB2A07C" Ref="C303"  Part="1" 
F 0 "C303" H 5695 5170 50  0000 L CNN
F 1 "1nF" H 5695 4970 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5708 4920 50  0001 C CNN
F 3 "" H 5695 5170 50  0001 C CNN
F 4 "0603" H 5520 5170 50  0001 R CNN "display_footprint"
F 5 "50V" H 5520 5070 50  0001 R CNN "Voltage"
F 6 "X7R" H 5520 4970 50  0001 R CNN "Dielectric"
F 7 "478-1215-1-ND" H 6095 5570 60  0001 C CNN "Digi-Key PN"
	1    5670 5070
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BB2A083
P 5320 5300
AR Path="/5BB27B84/5BB2A083" Ref="#PWR?"  Part="1" 
AR Path="/5BB27B24/5BB2A083" Ref="#PWR0303"  Part="1" 
F 0 "#PWR0303" H 5320 5050 50  0001 C CNN
F 1 "GND" H 5320 5150 50  0000 C CNN
F 2 "" H 5320 5300 50  0001 C CNN
F 3 "" H 5320 5300 50  0001 C CNN
	1    5320 5300
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V #PWR?
U 1 1 5BB2A089
P 5320 4840
AR Path="/5BB27B84/5BB2A089" Ref="#PWR?"  Part="1" 
AR Path="/5BB27B24/5BB2A089" Ref="#PWR0302"  Part="1" 
F 0 "#PWR0302" H 5320 4690 50  0001 C CNN
F 1 "+3.3V" H 5320 4980 50  0000 C CNN
F 2 "" H 5320 4840 50  0000 C CNN
F 3 "" H 5320 4840 50  0000 C CNN
	1    5320 4840
	1    0    0    -1  
$EndComp
Wire Wire Line
	5320 4840 5320 4880
Wire Wire Line
	5320 4880 5670 4880
Wire Wire Line
	5670 4880 5670 4920
Connection ~ 5320 4880
Wire Wire Line
	5320 4880 5320 4920
Wire Wire Line
	5320 4880 4970 4880
Wire Wire Line
	4970 4880 4970 4920
Wire Wire Line
	5320 5220 5320 5260
Wire Wire Line
	5320 5260 5670 5260
Wire Wire Line
	5670 5260 5670 5220
Connection ~ 5320 5260
Wire Wire Line
	5320 5260 5320 5300
Wire Wire Line
	5320 5260 4970 5260
Wire Wire Line
	4970 5260 4970 5220
$Comp
L power:GND #PWR0305
U 1 1 5BB2AB7D
P 5350 4040
F 0 "#PWR0305" H 5350 3790 50  0001 C CNN
F 1 "GND" H 5350 3890 50  0000 C CNN
F 2 "" H 5350 4040 50  0001 C CNN
F 3 "" H 5350 4040 50  0001 C CNN
	1    5350 4040
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+3.3V #PWR?
U 1 1 5BB2ABA3
P 5350 3240
AR Path="/5BB27B84/5BB2ABA3" Ref="#PWR?"  Part="1" 
AR Path="/5BB27B24/5BB2ABA3" Ref="#PWR0304"  Part="1" 
F 0 "#PWR0304" H 5350 3090 50  0001 C CNN
F 1 "+3.3V" H 5350 3380 50  0000 C CNN
F 2 "" H 5350 3240 50  0000 C CNN
F 3 "" H 5350 3240 50  0000 C CNN
	1    5350 3240
	1    0    0    -1  
$EndComp
Text GLabel 4950 3740 0    50   Output ~ 0
ISNS_HT_OUT
$Comp
L Custom_Library:+3.3V #PWR?
U 1 1 5BB2B17F
P 6670 3060
AR Path="/5BB27B84/5BB2B17F" Ref="#PWR?"  Part="1" 
AR Path="/5BB27B24/5BB2B17F" Ref="#PWR0306"  Part="1" 
F 0 "#PWR0306" H 6670 2910 50  0001 C CNN
F 1 "+3.3V" H 6670 3200 50  0000 C CNN
F 2 "" H 6670 3060 50  0000 C CNN
F 3 "" H 6670 3060 50  0000 C CNN
	1    6670 3060
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB2B40B
P 6670 3210
AR Path="/5BB27BA3/5BB2B40B" Ref="R?"  Part="1" 
AR Path="/5BB27B24/5BB2B40B" Ref="R301"  Part="1" 
F 0 "R301" H 6590 3210 50  0000 R CNN
F 1 "10k" V 6670 3210 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 6670 3210 50  0001 C CNN
F 3 "" H 6670 3210 50  0001 C CNN
F 4 "0603" H 6770 3290 50  0000 L CNN "display_footprint"
F 5 "1%" H 6770 3210 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 6780 3130 50  0000 L CNN "Wattage"
F 7 "RHM10KADCT-ND" H 6970 3610 60  0001 C CNN "Digi-Key PN"
	1    6670 3210
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB2B41F
P 6670 4050
AR Path="/5BB27BA3/5BB2B41F" Ref="R?"  Part="1" 
AR Path="/5BB27B24/5BB2B41F" Ref="R302"  Part="1" 
F 0 "R302" H 6590 4050 50  0000 R CNN
F 1 "0" V 6670 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 6670 4050 50  0001 C CNN
F 3 "" H 6670 4050 50  0001 C CNN
F 4 "None" H 6590 4130 50  0000 R CNN "Config"
F 5 "0603" H 6770 4130 50  0000 L CNN "display_footprint"
F 6 "1%" H 6770 4050 50  0000 L CNN "Tolerance"
F 7 "1/10W" H 6780 3970 50  0000 L CNN "Wattage"
F 8 "" H 6970 4450 60  0001 C CNN "Digi-Key PN"
	1    6670 4050
	-1   0    0    1   
$EndComp
Wire Wire Line
	5750 3740 6670 3740
Wire Wire Line
	6670 3740 6670 3360
Wire Wire Line
	6670 3740 6670 3900
Connection ~ 6670 3740
$Comp
L power:GND #PWR0307
U 1 1 5BB2B800
P 6670 4200
F 0 "#PWR0307" H 6670 3950 50  0001 C CNN
F 1 "GND" H 6670 4050 50  0000 C CNN
F 2 "" H 6670 4200 50  0001 C CNN
F 3 "" H 6670 4200 50  0001 C CNN
	1    6670 4200
	1    0    0    -1  
$EndComp
Text Notes 3530 4440 0    50   ~ 0
3.787 Peak Amps Max to support full output swing of conditioning stages
$Comp
L power:HT #PWR0301
U 1 1 5BB463D5
P 4870 3360
F 0 "#PWR0301" H 4870 3480 50  0001 C CNN
F 1 "HT" H 4870 3450 50  0000 C CNN
F 2 "" H 4870 3360 50  0001 C CNN
F 3 "" H 4870 3360 50  0001 C CNN
	1    4870 3360
	1    0    0    -1  
$EndComp
Wire Wire Line
	4870 3360 4870 3440
Wire Wire Line
	4870 3440 4950 3440
Text Notes 540  690  0    100  ~ 20
AC Current Sensor
$Comp
L Custom_Library:MU_Logo #G301
U 1 1 5BB6B7BB
P 9900 1100
F 0 "#G301" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
Text GLabel 5750 3440 2    50   Output ~ 0
ISNS_OUT
$Comp
L Sensor_Current:ACS722xLCTR-05AB U301
U 1 1 5BD3627A
P 5350 3640
F 0 "U301" H 5450 4090 50  0000 L CNN
F 1 "ACS722LLCTR-05AB" H 5450 3990 50  0000 L CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 5450 3290 50  0001 L CIN
F 3 "http://www.allegromicro.com/~/media/Files/Datasheets/ACS722-Datasheet.ashx?la=en" H 5350 3640 50  0001 C CNN
F 4 "620-1634-1-ND" H 5350 3640 50  0001 C CNN "Digi-Key PN"
	1    5350 3640
	1    0    0    -1  
$EndComp
$EndSCHEMATC
