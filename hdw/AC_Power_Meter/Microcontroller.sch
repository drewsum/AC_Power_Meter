EESchema Schematic File Version 4
LIBS:AC_Power_Meter-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 7 17
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
L Custom_Library:PIC18(L)F67K40-I_PT U701
U 1 1 5BB27DB5
P 5330 3640
F 0 "U701" H 6380 1840 50  0000 R CNN
F 1 "PIC18LF67K40-I/PT" H 5330 3690 50  0000 C CNN
F 2 "Housings_QFP:TQFP-64_10x10mm_Pitch0.5mm" H 5330 5740 50  0001 C CNN
F 3 "" H 4680 4290 50  0001 C CNN
F 4 "PIC18LF67K40-I/PT-ND" H 5330 3640 50  0001 C CNN "Digi-Key PN"
	1    5330 3640
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0712
U 1 1 5BB27E7D
P 5330 5620
F 0 "#PWR0712" H 5330 5370 50  0001 C CNN
F 1 "GND" H 5330 5470 50  0000 C CNN
F 2 "" H 5330 5620 50  0001 C CNN
F 3 "" H 5330 5620 50  0001 C CNN
	1    5330 5620
	1    0    0    -1  
$EndComp
Wire Wire Line
	5330 5620 5330 5580
Wire Wire Line
	5330 5580 5280 5580
Wire Wire Line
	5280 5580 5280 5540
Wire Wire Line
	5330 5580 5380 5580
Wire Wire Line
	5380 5580 5380 5540
Connection ~ 5330 5580
Wire Wire Line
	5330 1560 5330 1600
Wire Wire Line
	5330 1600 5280 1600
Wire Wire Line
	5280 1600 5280 1640
Wire Wire Line
	5330 1600 5380 1600
Wire Wire Line
	5380 1600 5380 1640
Connection ~ 5330 1600
Text GLabel 6580 4190 2    40   Input ~ 0
~MCLR
Text GLabel 4080 3390 0    60   Input ~ 0
ICSPCLK
Text GLabel 4080 3490 0    60   BiDi ~ 0
ICSPDAT
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB289D5
P 1600 7020
AR Path="/5BB27BA3/5BB289D5" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB289D5" Ref="C701"  Part="1" 
F 0 "C701" H 1625 7120 50  0000 L CNN
F 1 "0.1uF" H 1625 6920 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 1638 6870 50  0001 C CNN
F 3 "" H 1625 7120 50  0001 C CNN
F 4 "0603" H 1450 7120 50  0000 R CNN "display_footprint"
F 5 "50V" H 1450 7020 50  0000 R CNN "Voltage"
F 6 "X7R" H 1450 6920 50  0000 R CNN "Dielectric"
F 7 "490-8020-1-ND" H 2025 7520 60  0001 C CNN "Digi-Key PN"
	1    1600 7020
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB28AC0
P 1950 7020
AR Path="/5BB27BA3/5BB28AC0" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB28AC0" Ref="C702"  Part="1" 
F 0 "C702" H 1975 7120 50  0000 L CNN
F 1 "10nF" H 1975 6920 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 1988 6870 50  0001 C CNN
F 3 "" H 1975 7120 50  0001 C CNN
F 4 "0603" H 1800 7120 50  0001 R CNN "display_footprint"
F 5 "50V" H 1800 7020 50  0001 R CNN "Voltage"
F 6 "X7R" H 1800 6920 50  0001 R CNN "Dielectric"
F 7 "1276-1921-1-ND" H 2375 7520 60  0001 C CNN "Digi-Key PN"
	1    1950 7020
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB28D2A
P 2300 7020
AR Path="/5BB27BA3/5BB28D2A" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB28D2A" Ref="C703"  Part="1" 
F 0 "C703" H 2325 7120 50  0000 L CNN
F 1 "1nF" H 2325 6920 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2338 6870 50  0001 C CNN
F 3 "" H 2325 7120 50  0001 C CNN
F 4 "0603" H 2150 7120 50  0001 R CNN "display_footprint"
F 5 "50V" H 2150 7020 50  0001 R CNN "Voltage"
F 6 "X7R" H 2150 6920 50  0001 R CNN "Dielectric"
F 7 "478-1215-1-ND" H 2725 7520 60  0001 C CNN "Digi-Key PN"
	1    2300 7020
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0702
U 1 1 5BB28E47
P 1950 7250
F 0 "#PWR0702" H 1950 7000 50  0001 C CNN
F 1 "GND" H 1950 7100 50  0000 C CNN
F 2 "" H 1950 7250 50  0001 C CNN
F 3 "" H 1950 7250 50  0001 C CNN
	1    1950 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 6790 1950 6830
Wire Wire Line
	1950 6830 2300 6830
Wire Wire Line
	2300 6830 2300 6870
Connection ~ 1950 6830
Wire Wire Line
	1950 6830 1950 6870
Wire Wire Line
	1950 6830 1600 6830
Wire Wire Line
	1600 6830 1600 6870
Wire Wire Line
	1950 7170 1950 7210
Wire Wire Line
	1950 7210 2300 7210
Wire Wire Line
	2300 7210 2300 7170
Connection ~ 1950 7210
Wire Wire Line
	1950 7210 1950 7250
Wire Wire Line
	1950 7210 1600 7210
Wire Wire Line
	1600 7210 1600 7170
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB29946
P 3170 7020
AR Path="/5BB27BA3/5BB29946" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB29946" Ref="C704"  Part="1" 
F 0 "C704" H 3195 7120 50  0000 L CNN
F 1 "0.1uF" H 3195 6920 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3208 6870 50  0001 C CNN
F 3 "" H 3195 7120 50  0001 C CNN
F 4 "0603" H 3020 7120 50  0000 R CNN "display_footprint"
F 5 "50V" H 3020 7020 50  0000 R CNN "Voltage"
F 6 "X7R" H 3020 6920 50  0000 R CNN "Dielectric"
F 7 "490-8020-1-ND" H 3595 7520 60  0001 C CNN "Digi-Key PN"
	1    3170 7020
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB29951
P 3520 7020
AR Path="/5BB27BA3/5BB29951" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB29951" Ref="C705"  Part="1" 
F 0 "C705" H 3545 7120 50  0000 L CNN
F 1 "10nF" H 3545 6920 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3558 6870 50  0001 C CNN
F 3 "" H 3545 7120 50  0001 C CNN
F 4 "0603" H 3370 7120 50  0001 R CNN "display_footprint"
F 5 "50V" H 3370 7020 50  0001 R CNN "Voltage"
F 6 "X7R" H 3370 6920 50  0001 R CNN "Dielectric"
F 7 "1276-1921-1-ND" H 3945 7520 60  0001 C CNN "Digi-Key PN"
	1    3520 7020
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB2995C
P 3870 7020
AR Path="/5BB27BA3/5BB2995C" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB2995C" Ref="C706"  Part="1" 
F 0 "C706" H 3895 7120 50  0000 L CNN
F 1 "1nF" H 3895 6920 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3908 6870 50  0001 C CNN
F 3 "" H 3895 7120 50  0001 C CNN
F 4 "0603" H 3720 7120 50  0001 R CNN "display_footprint"
F 5 "50V" H 3720 7020 50  0001 R CNN "Voltage"
F 6 "X7R" H 3720 6920 50  0001 R CNN "Dielectric"
F 7 "478-1215-1-ND" H 4295 7520 60  0001 C CNN "Digi-Key PN"
	1    3870 7020
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0706
U 1 1 5BB29963
P 3520 7250
F 0 "#PWR0706" H 3520 7000 50  0001 C CNN
F 1 "GND" H 3520 7100 50  0000 C CNN
F 2 "" H 3520 7250 50  0001 C CNN
F 3 "" H 3520 7250 50  0001 C CNN
	1    3520 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3520 6790 3520 6830
Wire Wire Line
	3520 6830 3870 6830
Wire Wire Line
	3870 6830 3870 6870
Connection ~ 3520 6830
Wire Wire Line
	3520 6830 3520 6870
Wire Wire Line
	3520 6830 3170 6830
Wire Wire Line
	3170 6830 3170 6870
Wire Wire Line
	3520 7170 3520 7210
Wire Wire Line
	3520 7210 3870 7210
Wire Wire Line
	3870 7210 3870 7170
Connection ~ 3520 7210
Wire Wire Line
	3520 7210 3520 7250
Wire Wire Line
	3520 7210 3170 7210
Wire Wire Line
	3170 7210 3170 7170
Text GLabel 6580 4390 2    60   Output ~ 0
USB_UART_TX
Text GLabel 6580 4290 2    60   Input ~ 0
USB_UART_RX
Text Notes 540  690  0    100  ~ 20
8 bit High Performance Enhanced Flash PIC Microcontroller
$Comp
L Custom_Library:MU_Logo #G701
U 1 1 5BB68D1E
P 9900 1100
F 0 "#G701" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
Text GLabel 4080 1890 0    50   Input ~ 0
ISNS_ADC
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BBE6824
P 2790 3920
AR Path="/5BB27BA3/5BBE6824" Ref="R?"  Part="1" 
AR Path="/5BB27BF7/5BBE6824" Ref="R?"  Part="1" 
AR Path="/5BB27B84/5BBE6824" Ref="R704"  Part="1" 
F 0 "R704" H 2710 3920 50  0000 R CNN
F 1 "10k" V 2790 3920 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2790 3920 50  0001 C CNN
F 3 "" H 2790 3920 50  0001 C CNN
F 4 "0603" H 2890 4000 50  0000 L CNN "display_footprint"
F 5 "1%" H 2890 3920 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 2900 3840 50  0000 L CNN "Wattage"
F 7 "RHM10KADCT-ND" H 3090 4320 60  0001 C CNN "Digi-Key PN"
	1    2790 3920
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BBE682F
P 2040 3920
AR Path="/5BB27BA3/5BBE682F" Ref="R?"  Part="1" 
AR Path="/5BB27BF7/5BBE682F" Ref="R?"  Part="1" 
AR Path="/5BB27B84/5BBE682F" Ref="R703"  Part="1" 
F 0 "R703" H 1960 3920 50  0000 R CNN
F 1 "10k" V 2040 3920 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2040 3920 50  0001 C CNN
F 3 "" H 2040 3920 50  0001 C CNN
F 4 "0603" H 2140 4000 50  0000 L CNN "display_footprint"
F 5 "1%" H 2140 3920 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 2150 3840 50  0000 L CNN "Wattage"
F 7 "RHM10KADCT-ND" H 2340 4320 60  0001 C CNN "Digi-Key PN"
	1    2040 3920
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BBE6845
P 1590 4290
AR Path="/5A2D2FD2/5BBE6845" Ref="R?"  Part="1" 
AR Path="/5A0A8BD0/5BBE6845" Ref="R?"  Part="1" 
AR Path="/5BB27BCC/5BBE6845" Ref="R?"  Part="1" 
AR Path="/5BB27BF7/5BBE6845" Ref="R?"  Part="1" 
AR Path="/5BB27B84/5BBE6845" Ref="R701"  Part="1" 
F 0 "R701" V 1670 4290 50  0000 C CNN
F 1 "0" V 1590 4290 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 1520 4290 50  0001 C CNN
F 3 "" V 1670 4290 50  0001 C CNN
F 4 "1%" V 1330 4290 50  0001 C CNN "Tolerance"
F 5 "1/10W" V 1490 4290 50  0001 C CNN "Wattage"
F 6 "0603" V 1410 4290 50  0001 C CNN "display_footprint"
F 7 "P0.0GCT-ND" H 10  -900 50  0001 C CNN "Digi-Key PN"
	1    1590 4290
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5BBE684F
P 1590 4390
AR Path="/5A2D2FD2/5BBE684F" Ref="R?"  Part="1" 
AR Path="/5A0A8BD0/5BBE684F" Ref="R?"  Part="1" 
AR Path="/5BB27BCC/5BBE684F" Ref="R?"  Part="1" 
AR Path="/5BB27BF7/5BBE684F" Ref="R?"  Part="1" 
AR Path="/5BB27B84/5BBE684F" Ref="R702"  Part="1" 
F 0 "R702" V 1670 4390 50  0000 C CNN
F 1 "0" V 1590 4390 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 1520 4390 50  0001 C CNN
F 3 "" V 1670 4390 50  0001 C CNN
F 4 "1%" V 1330 4390 50  0001 C CNN "Tolerance"
F 5 "1/10W" V 1490 4390 50  0001 C CNN "Wattage"
F 6 "0603" V 1410 4390 50  0001 C CNN "display_footprint"
F 7 "P0.0GCT-ND" H 10  -900 50  0001 C CNN "Digi-Key PN"
	1    1590 4390
	0    1    1    0   
$EndComp
Wire Wire Line
	2040 4070 2040 4390
Wire Wire Line
	2790 4070 2790 4290
Text GLabel 1440 4290 0    50   BiDi ~ 0
I2C_SDA
Text GLabel 1440 4390 0    50   Output ~ 0
I2C_SCL
Text GLabel 4080 2390 0    50   Input ~ 0
Zero_Cross_Detect
Text GLabel 6580 3690 2    50   Output ~ 0
SSR_Force
Text GLabel 6580 3790 2    50   Output ~ 0
SSR_Dim
Text GLabel 6580 2790 2    40   Output ~ 0
~Active
Text GLabel 6580 2890 2    50   Output ~ 0
Comm_Error
Text GLabel 6580 2990 2    50   Output ~ 0
Heartbeat
Text GLabel 6580 3090 2    50   Output ~ 0
ADC_Error
Wire Wire Line
	2790 4290 1740 4290
Wire Wire Line
	1740 4390 2040 4390
$Comp
L Oscillator:ASV-xxxMHz X701
U 1 1 5BBF1E7B
P 9450 5970
F 0 "X701" H 9500 6220 50  0000 L CNN
F 1 "ASV-16.000MHz" H 9500 5720 50  0000 L CNN
F 2 "Oscillators:Oscillator_SMD_Abracon_ASV-4pin_7.0x5.1mm" H 10150 5620 50  0001 C CNN
F 3 "http://www.abracon.com/Oscillators/ASV.pdf" H 9350 5970 50  0001 C CNN
F 4 "535-10072-1-ND" H 9450 5970 50  0001 C CNN "Digi-Key PN"
	1    9450 5970
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0717
U 1 1 5BBF2845
P 9450 6270
F 0 "#PWR0717" H 9450 6020 50  0001 C CNN
F 1 "GND" H 9450 6120 50  0000 C CNN
F 2 "" H 9450 6270 50  0001 C CNN
F 3 "" H 9450 6270 50  0001 C CNN
	1    9450 6270
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BBF2EFB
P 8680 5660
AR Path="/5BB27BA3/5BBF2EFB" Ref="R?"  Part="1" 
AR Path="/5BB27BF7/5BBF2EFB" Ref="R?"  Part="1" 
AR Path="/5BB27B84/5BBF2EFB" Ref="R705"  Part="1" 
F 0 "R705" H 8600 5660 50  0000 R CNN
F 1 "10k" V 8680 5660 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 8680 5660 50  0001 C CNN
F 3 "" H 8680 5660 50  0001 C CNN
F 4 "0603" H 8780 5740 50  0000 L CNN "display_footprint"
F 5 "1%" H 8780 5660 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 8790 5580 50  0000 L CNN "Wattage"
F 7 "RHM10KADCT-ND" H 8980 6060 60  0001 C CNN "Digi-Key PN"
	1    8680 5660
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 5970 8680 5970
Wire Wire Line
	8680 5970 8680 5810
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BBF4380
P 7630 6010
AR Path="/5BB27BA3/5BBF4380" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BBF4380" Ref="C708"  Part="1" 
F 0 "C708" H 7655 6110 50  0000 L CNN
F 1 "0.1uF" H 7655 5910 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 7668 5860 50  0001 C CNN
F 3 "" H 7655 6110 50  0001 C CNN
F 4 "0603" H 7480 6110 50  0000 R CNN "display_footprint"
F 5 "50V" H 7480 6010 50  0000 R CNN "Voltage"
F 6 "X7R" H 7480 5910 50  0000 R CNN "Dielectric"
F 7 "490-8020-1-ND" H 8055 6510 60  0001 C CNN "Digi-Key PN"
	1    7630 6010
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BBF438B
P 7980 6010
AR Path="/5BB27BA3/5BBF438B" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BBF438B" Ref="C709"  Part="1" 
F 0 "C709" H 8005 6110 50  0000 L CNN
F 1 "10nF" H 8005 5910 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8018 5860 50  0001 C CNN
F 3 "" H 8005 6110 50  0001 C CNN
F 4 "0603" H 7830 6110 50  0001 R CNN "display_footprint"
F 5 "50V" H 7830 6010 50  0001 R CNN "Voltage"
F 6 "X7R" H 7830 5910 50  0001 R CNN "Dielectric"
F 7 "1276-1921-1-ND" H 8405 6510 60  0001 C CNN "Digi-Key PN"
	1    7980 6010
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BBF4396
P 8330 6010
AR Path="/5BB27BA3/5BBF4396" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BBF4396" Ref="C710"  Part="1" 
F 0 "C710" H 8355 6110 50  0000 L CNN
F 1 "1nF" H 8355 5910 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8368 5860 50  0001 C CNN
F 3 "" H 8355 6110 50  0001 C CNN
F 4 "0603" H 8180 6110 50  0001 R CNN "display_footprint"
F 5 "50V" H 8180 6010 50  0001 R CNN "Voltage"
F 6 "X7R" H 8180 5910 50  0001 R CNN "Dielectric"
F 7 "478-1215-1-ND" H 8755 6510 60  0001 C CNN "Digi-Key PN"
	1    8330 6010
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0714
U 1 1 5BBF439D
P 7980 6240
F 0 "#PWR0714" H 7980 5990 50  0001 C CNN
F 1 "GND" H 7980 6090 50  0000 C CNN
F 2 "" H 7980 6240 50  0001 C CNN
F 3 "" H 7980 6240 50  0001 C CNN
	1    7980 6240
	1    0    0    -1  
$EndComp
Wire Wire Line
	7980 5780 7980 5820
Wire Wire Line
	7980 5820 8330 5820
Wire Wire Line
	8330 5820 8330 5860
Connection ~ 7980 5820
Wire Wire Line
	7980 5820 7980 5860
Wire Wire Line
	7980 5820 7630 5820
Wire Wire Line
	7630 5820 7630 5860
Wire Wire Line
	7980 6160 7980 6200
Wire Wire Line
	7980 6200 8330 6200
Wire Wire Line
	8330 6200 8330 6160
Connection ~ 7980 6200
Wire Wire Line
	7980 6200 7980 6240
Wire Wire Line
	7980 6200 7630 6200
Wire Wire Line
	7630 6200 7630 6160
Text GLabel 9750 5970 2    50   Output ~ 0
CLKIN
Text GLabel 4080 2590 0    50   Input ~ 0
CLKIN
Text GLabel 6580 2090 2    50   Input ~ 0
POS3P3_ADC
Text GLabel 4080 2290 0    50   Input ~ 0
POS12_ADC
$Comp
L power:+3.3VADC #PWR0710
U 1 1 5BB8B55F
P 4080 2190
F 0 "#PWR0710" H 4230 2140 50  0001 C CNN
F 1 "+3.3VADC" V 4080 2290 50  0000 L CNN
F 2 "" H 4080 2190 50  0001 C CNN
F 3 "" H 4080 2190 50  0001 C CNN
	1    4080 2190
	0    -1   -1   0   
$EndComp
$Comp
L power:GNDA #PWR0709
U 1 1 5BB8C78A
P 4080 2090
F 0 "#PWR0709" H 4080 1840 50  0001 C CNN
F 1 "GNDA" V 4080 1940 50  0000 R CNN
F 2 "" H 4080 2090 50  0001 C CNN
F 3 "" H 4080 2090 50  0001 C CNN
	1    4080 2090
	0    1    1    0   
$EndComp
NoConn ~ 4080 1990
NoConn ~ 4080 2490
NoConn ~ 4080 2990
NoConn ~ 4080 3090
NoConn ~ 4080 3190
NoConn ~ 4080 3290
NoConn ~ 4080 3690
NoConn ~ 4080 3790
NoConn ~ 4080 4090
NoConn ~ 4080 4190
NoConn ~ 4080 4590
NoConn ~ 4080 4690
NoConn ~ 4080 4790
NoConn ~ 4080 4890
NoConn ~ 4080 4990
NoConn ~ 4080 5090
NoConn ~ 6580 2290
NoConn ~ 6580 2390
NoConn ~ 6580 2490
NoConn ~ 6580 2590
NoConn ~ 6580 3190
NoConn ~ 6580 3290
NoConn ~ 6580 3390
NoConn ~ 6580 3490
NoConn ~ 6580 3890
NoConn ~ 6580 3990
NoConn ~ 6580 4090
NoConn ~ 6580 4590
NoConn ~ 6580 4690
NoConn ~ 6580 4790
NoConn ~ 6580 4890
Wire Wire Line
	4080 4390 2040 4390
Connection ~ 2040 4390
Wire Wire Line
	2790 4290 4080 4290
Connection ~ 2790 4290
NoConn ~ 4080 5190
NoConn ~ 4080 5290
NoConn ~ 4080 2890
NoConn ~ 6580 1990
NoConn ~ 6580 2190
NoConn ~ 6580 1890
NoConn ~ 4080 2790
NoConn ~ 4080 3890
NoConn ~ 4080 3990
$Comp
L power:+3.3V #PWR?
U 1 1 5BF35500
P 1950 6790
F 0 "#PWR?" H 1950 6640 50  0001 C CNN
F 1 "+3.3V" H 1950 6930 50  0000 C CNN
F 2 "" H 1950 6790 50  0001 C CNN
F 3 "" H 1950 6790 50  0001 C CNN
	1    1950 6790
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF355A2
P 3520 6790
F 0 "#PWR?" H 3520 6640 50  0001 C CNN
F 1 "+3.3V" H 3520 6930 50  0000 C CNN
F 2 "" H 3520 6790 50  0001 C CNN
F 3 "" H 3520 6790 50  0001 C CNN
	1    3520 6790
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF3565D
P 2040 3770
F 0 "#PWR?" H 2040 3620 50  0001 C CNN
F 1 "+3.3V" H 2040 3910 50  0000 C CNN
F 2 "" H 2040 3770 50  0001 C CNN
F 3 "" H 2040 3770 50  0001 C CNN
	1    2040 3770
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF35768
P 2790 3770
F 0 "#PWR?" H 2790 3620 50  0001 C CNN
F 1 "+3.3V" H 2790 3910 50  0000 C CNN
F 2 "" H 2790 3770 50  0001 C CNN
F 3 "" H 2790 3770 50  0001 C CNN
	1    2790 3770
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF35793
P 5330 1560
F 0 "#PWR?" H 5330 1410 50  0001 C CNN
F 1 "+3.3V" H 5330 1700 50  0000 C CNN
F 2 "" H 5330 1560 50  0001 C CNN
F 3 "" H 5330 1560 50  0001 C CNN
	1    5330 1560
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF3588E
P 7980 5780
F 0 "#PWR?" H 7980 5630 50  0001 C CNN
F 1 "+3.3V" H 7980 5920 50  0000 C CNN
F 2 "" H 7980 5780 50  0001 C CNN
F 3 "" H 7980 5780 50  0001 C CNN
	1    7980 5780
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF35999
P 8680 5510
F 0 "#PWR?" H 8680 5360 50  0001 C CNN
F 1 "+3.3V" H 8680 5650 50  0000 C CNN
F 2 "" H 8680 5510 50  0001 C CNN
F 3 "" H 8680 5510 50  0001 C CNN
	1    8680 5510
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5BF35A94
P 9450 5670
F 0 "#PWR?" H 9450 5520 50  0001 C CNN
F 1 "+3.3V" H 9450 5810 50  0000 C CNN
F 2 "" H 9450 5670 50  0001 C CNN
F 3 "" H 9450 5670 50  0001 C CNN
	1    9450 5670
	1    0    0    -1  
$EndComp
$EndSCHEMATC
