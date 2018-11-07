EESchema Schematic File Version 4
LIBS:AC_Power_Meter-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 10 17
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 8800 5300 3    60   UnSpc ~ 0
~USB_ACTIVE
Wire Wire Line
	8190 2980 8270 2980
Wire Wire Line
	8190 1860 8190 2060
Wire Wire Line
	7990 2060 8190 2060
Wire Wire Line
	7990 1860 8190 1860
Connection ~ 8190 2060
Wire Wire Line
	8680 2060 8680 2140
Wire Wire Line
	8190 2060 8190 2980
Wire Wire Line
	8190 2060 8680 2060
Text GLabel 1850 2980 0    60   Output ~ 0
USB_UART_RX_ISO
Text GLabel 1850 3080 0    60   Input ~ 0
USB_UART_TX_ISO
$Comp
L Custom_Library:FT234XD U1002
U 1 1 5B518274
P 3390 3230
F 0 "U1002" H 3940 2830 60  0000 R CNN
F 1 "FT234XD" H 3390 3230 60  0000 C CNN
F 2 "Housings_DFN_QFN:DFN-12-1EP_3x3mm_Pitch0.45mm" H 3390 3630 60  0001 C CNN
F 3 "http://www.ftdichip.com/Support/Documents/DataSheets/ICs/DS_FT234XD.pdf" H 3390 3630 60  0001 C CNN
F 4 "768-1178-1-ND" H 4040 2930 60  0001 C CNN "Digi-Key PN"
	1    3390 3230
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3390 2740 3290 2740
Wire Wire Line
	3290 2740 3290 2780
Wire Wire Line
	3390 2700 3390 2740
Wire Wire Line
	3390 2740 3490 2740
Wire Wire Line
	3490 2740 3490 2780
Connection ~ 3390 2740
$Comp
L Device:Ferrite_Bead L1001
U 1 1 5B520B93
P 8420 2980
F 0 "L1001" V 8270 3005 50  0000 C CNN
F 1 "600R 0.5A" V 8570 2980 50  0000 C CNN
F 2 "Inductors_SMD:L_0603" V 8350 2980 50  0001 C CNN
F 3 "~" H 8420 2980 50  0001 C CNN
F 4 "732-1593-1-ND" V 8420 2980 50  0001 C CNN "Digi-Key PN"
	1    8420 2980
	0    1    1    0   
$EndComp
Wire Wire Line
	8930 3410 8930 2980
Wire Wire Line
	8930 2980 8570 2980
Wire Wire Line
	8930 2980 9200 2980
Connection ~ 8930 2980
Wire Wire Line
	1850 2980 2740 2980
Wire Wire Line
	1850 3080 2740 3080
Text GLabel 4040 3480 2    60   UnSpc ~ 0
~USB_ACTIVE
Wire Wire Line
	4820 3570 4820 2980
Wire Wire Line
	4820 2980 4040 2980
NoConn ~ 2740 3180
NoConn ~ 2740 3280
$Comp
L Device:R R?
U 1 1 5B526C2E
P 5350 3180
AR Path="/5A2D2FD2/5B526C2E" Ref="R?"  Part="1" 
AR Path="/5A0A8BD0/5B526C2E" Ref="R?"  Part="1" 
AR Path="/5BB27BCC/5B526C2E" Ref="R1007"  Part="1" 
F 0 "R1007" V 5430 3180 50  0000 C CNN
F 1 "27" V 5350 3180 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5280 3180 50  0001 C CNN
F 3 "" V 5430 3180 50  0001 C CNN
F 4 "1%" V 5090 3180 50  0001 C CNN "Tolerance"
F 5 "1/10W" V 5250 3180 50  0001 C CNN "Wattage"
F 6 "0603" V 5170 3180 50  0001 C CNN "display_footprint"
F 7 "P27.0HCT-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    5350 3180
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5B5274F9
P 5350 3280
AR Path="/5A2D2FD2/5B5274F9" Ref="R?"  Part="1" 
AR Path="/5A0A8BD0/5B5274F9" Ref="R?"  Part="1" 
AR Path="/5BB27BCC/5B5274F9" Ref="R1008"  Part="1" 
F 0 "R1008" V 5430 3280 50  0000 C CNN
F 1 "27" V 5350 3280 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5280 3280 50  0001 C CNN
F 3 "" V 5430 3280 50  0001 C CNN
F 4 "1%" V 5090 3280 50  0001 C CNN "Tolerance"
F 5 "1/10W" V 5250 3280 50  0001 C CNN "Wattage"
F 6 "0603" V 5170 3280 50  0001 C CNN "display_footprint"
F 7 "P27.0HCT-ND" H 0   0   50  0001 C CNN "Digi-Key PN"
	1    5350 3280
	0    1    1    0   
$EndComp
Wire Wire Line
	5200 3180 4040 3180
Wire Wire Line
	5200 3280 4040 3280
Wire Wire Line
	3390 3760 3390 3720
Wire Wire Line
	3390 3720 3490 3720
Wire Wire Line
	3490 3720 3490 3680
Wire Wire Line
	3390 3720 3290 3720
Wire Wire Line
	3290 3720 3290 3680
Connection ~ 3390 3720
Wire Wire Line
	5500 3180 5860 3180
Wire Wire Line
	5860 3570 5860 3180
Connection ~ 5860 3180
Wire Wire Line
	6620 3570 6620 3280
Connection ~ 6620 3280
Wire Wire Line
	6620 3280 5500 3280
Wire Wire Line
	2740 3480 2540 3480
Wire Wire Line
	2540 3480 2540 3630
Wire Wire Line
	2540 2800 2540 3480
Connection ~ 2540 3480
$Comp
L Custom_Library:TP TP?
U 1 1 5B53630B
P 8170 3950
AR Path="/5A557C58/5B53630B" Ref="TP?"  Part="1" 
AR Path="/5A0A3EA5/5B53630B" Ref="TP?"  Part="1" 
AR Path="/5A0A8BD0/5B53630B" Ref="TP?"  Part="1" 
AR Path="/5BB27BCC/5B53630B" Ref="TP1002"  Part="1" 
F 0 "TP1002" H 8170 4100 50  0000 C CNN
F 1 "TP" H 8170 4100 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 8170 3950 60  0001 C CNN
F 3 "" H 8170 3950 60  0000 C CNN
	1    8170 3950
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG01002
U 1 1 5B569FD9
P 8680 1980
F 0 "#FLG01002" H 8680 2055 50  0001 C CNN
F 1 "PWR_FLAG" H 8680 2130 50  0000 C CNN
F 2 "" H 8680 1980 50  0001 C CNN
F 3 "~" H 8680 1980 50  0001 C CNN
	1    8680 1980
	1    0    0    -1  
$EndComp
Wire Wire Line
	8680 1980 8680 2060
Connection ~ 8680 2060
NoConn ~ 9200 3380
Text Notes 540  690  0    100  ~ 20
UART to USB Bridge, +5V USB Window Comparator
Text Label 4120 3180 0    60   ~ 0
BRIDGE_USB+
Text Label 4120 3280 0    60   ~ 0
BRIDGE_USB-
Text Label 6700 3180 0    60   ~ 0
CONN_USB+
Text Label 6700 3280 0    60   ~ 0
CONN_USB-
$Comp
L Connector:USB_B_Mini J1001
U 1 1 5BB4A700
P 9500 3180
F 0 "J1001" H 9300 3630 50  0000 L CNN
F 1 "USB_B_Mini" H 9300 3530 50  0000 L CNN
F 2 "Connectors:USB_Mini-B" H 9650 3130 50  0001 C CNN
F 3 "~" H 9650 3130 50  0001 C CNN
F 4 "732-2109-1-ND" H 9500 3180 50  0001 C CNN "Digi-Key PN"
	1    9500 3180
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR01033
U 1 1 5BB4A786
P 9500 3580
F 0 "#PWR01033" H 9500 3330 50  0001 C CNN
F 1 "GND_USB" H 9500 3430 50  0000 C CNN
F 2 "" H 9500 3580 50  0001 C CNN
F 3 "" H 9500 3580 50  0001 C CNN
	1    9500 3580
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:TPD3S014DBVR U1004
U 1 1 5BB4AA25
P 7440 2060
F 0 "U1004" H 7740 1710 50  0000 L CNN
F 1 "TPD3S014DBVR" H 7440 2410 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-6" H 7590 1510 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/tpd3s014.pdf" H 7590 1310 50  0001 L CNN
F 4 "296-38835-1-ND" H 7590 1410 50  0001 L CNN "Digi-Key PN"
	1    7440 2060
	-1   0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR01028
U 1 1 5BB4AC69
P 7440 2460
F 0 "#PWR01028" H 7440 2210 50  0001 C CNN
F 1 "GND_USB" H 7440 2310 50  0000 C CNN
F 2 "" H 7440 2460 50  0001 C CNN
F 3 "" H 7440 2460 50  0001 C CNN
	1    7440 2460
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR01012
U 1 1 5BB4AEAB
P 3390 2700
F 0 "#PWR01012" H 3390 2550 50  0001 C CNN
F 1 "+5V_USB" H 3390 2840 50  0000 C CNN
F 2 "" H 3390 2700 50  0001 C CNN
F 3 "" H 3390 2700 50  0001 C CNN
	1    3390 2700
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR01013
U 1 1 5BB4AF36
P 3390 3760
F 0 "#PWR01013" H 3390 3510 50  0001 C CNN
F 1 "GND_USB" H 3390 3610 50  0000 C CNN
F 2 "" H 3390 3760 50  0001 C CNN
F 3 "" H 3390 3760 50  0001 C CNN
	1    3390 3760
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB4B732
P 8680 2290
AR Path="/5BB27BA3/5BB4B732" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB4B732" Ref="C?"  Part="1" 
AR Path="/5BB27BCC/5BB4B732" Ref="C1013"  Part="1" 
F 0 "C1013" H 8705 2390 50  0000 L CNN
F 1 "0.1uF" H 8705 2190 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8718 2140 50  0001 C CNN
F 3 "" H 8705 2390 50  0001 C CNN
F 4 "0603" H 8530 2390 50  0000 R CNN "display_footprint"
F 5 "50V" H 8530 2290 50  0000 R CNN "Voltage"
F 6 "X7R" H 8530 2190 50  0000 R CNN "Dielectric"
F 7 "490-8020-1-ND" H 9105 2790 60  0001 C CNN "Digi-Key PN"
	1    8680 2290
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB4BF2D
P 8930 3560
AR Path="/5BB27BA3/5BB4BF2D" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB4BF2D" Ref="C?"  Part="1" 
AR Path="/5BB27BCC/5BB4BF2D" Ref="C1014"  Part="1" 
F 0 "C1014" H 8955 3660 50  0000 L CNN
F 1 "0.1uF" H 8955 3460 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 8968 3410 50  0001 C CNN
F 3 "" H 8955 3660 50  0001 C CNN
F 4 "0603" H 8780 3660 50  0000 R CNN "display_footprint"
F 5 "50V" H 8780 3560 50  0000 R CNN "Voltage"
F 6 "X7R" H 8780 3460 50  0000 R CNN "Dielectric"
F 7 "490-8020-1-ND" H 9355 4060 60  0001 C CNN "Digi-Key PN"
	1    8930 3560
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR01032
U 1 1 5BB4C661
P 8930 3710
F 0 "#PWR01032" H 8930 3460 50  0001 C CNN
F 1 "GND_USB" H 8930 3560 50  0000 C CNN
F 2 "" H 8930 3710 50  0001 C CNN
F 3 "" H 8930 3710 50  0001 C CNN
	1    8930 3710
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB4C6C2
P 6630 2350
AR Path="/5BB27BA3/5BB4C6C2" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB4C6C2" Ref="C?"  Part="1" 
AR Path="/5BB27BCC/5BB4C6C2" Ref="C1012"  Part="1" 
F 0 "C1012" H 6655 2450 50  0000 L CNN
F 1 "0.1uF" H 6655 2250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6668 2200 50  0001 C CNN
F 3 "" H 6655 2450 50  0001 C CNN
F 4 "0603" H 6480 2450 50  0000 R CNN "display_footprint"
F 5 "50V" H 6480 2350 50  0000 R CNN "Voltage"
F 6 "X7R" H 6480 2250 50  0000 R CNN "Dielectric"
F 7 "490-8020-1-ND" H 7055 2850 60  0001 C CNN "Digi-Key PN"
	1    6630 2350
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR01027
U 1 1 5BB4CE01
P 6630 2500
F 0 "#PWR01027" H 6630 2250 50  0001 C CNN
F 1 "GND_USB" H 6630 2350 50  0000 C CNN
F 2 "" H 6630 2500 50  0001 C CNN
F 3 "" H 6630 2500 50  0001 C CNN
	1    6630 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6630 2200 6630 2060
Wire Wire Line
	6630 2060 6890 2060
$Comp
L Custom_Library:GND_USB #PWR01030
U 1 1 5BB4D84A
P 8680 2440
F 0 "#PWR01030" H 8680 2190 50  0001 C CNN
F 1 "GND_USB" H 8680 2290 50  0000 C CNN
F 2 "" H 8680 2440 50  0001 C CNN
F 3 "" H 8680 2440 50  0001 C CNN
	1    8680 2440
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR01026
U 1 1 5BB4D8FA
P 6630 1980
F 0 "#PWR01026" H 6630 1830 50  0001 C CNN
F 1 "+5V_USB" H 6630 2120 50  0000 C CNN
F 2 "" H 6630 1980 50  0001 C CNN
F 3 "" H 6630 1980 50  0001 C CNN
	1    6630 1980
	1    0    0    -1  
$EndComp
Wire Wire Line
	6630 1980 6630 2060
Connection ~ 6630 2060
$Comp
L Custom_Library:TP TP1001
U 1 1 5BB4E248
P 6050 1990
F 0 "TP1001" H 6050 2140 50  0000 C CNN
F 1 "TP" H 6050 2140 50  0001 C CNN
F 2 "Measurement_Points:Measurement_Point_Round-SMD-Pad_Small" H 6050 1990 60  0001 C CNN
F 3 "" H 6050 1990 60  0000 C CNN
	1    6050 1990
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 1990 6050 2060
Wire Wire Line
	6050 2060 6630 2060
$Comp
L power:PWR_FLAG #FLG01001
U 1 1 5BB4EBB8
P 5670 1990
F 0 "#FLG01001" H 5670 2065 50  0001 C CNN
F 1 "PWR_FLAG" H 5670 2140 50  0000 C CNN
F 2 "" H 5670 1990 50  0001 C CNN
F 3 "~" H 5670 1990 50  0001 C CNN
	1    5670 1990
	1    0    0    -1  
$EndComp
Wire Wire Line
	5670 1990 5670 2060
Wire Wire Line
	5670 2060 6050 2060
Connection ~ 6050 2060
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB4F7CF
P 5860 3720
AR Path="/5BB27BA3/5BB4F7CF" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB4F7CF" Ref="C?"  Part="1" 
AR Path="/5BB27BCC/5BB4F7CF" Ref="C1010"  Part="1" 
F 0 "C1010" H 5885 3820 50  0000 L CNN
F 1 "47pF" H 5885 3620 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 5898 3570 50  0001 C CNN
F 3 "" H 5885 3820 50  0001 C CNN
F 4 "0603" H 5710 3820 50  0000 R CNN "display_footprint"
F 5 "50V" H 5710 3720 50  0000 R CNN "Voltage"
F 6 "C0G/NP0" H 5710 3620 50  0000 R CNN "Dielectric"
F 7 "478-1171-1-ND" H 6285 4220 60  0001 C CNN "Digi-Key PN"
	1    5860 3720
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB50205
P 6620 3720
AR Path="/5BB27BA3/5BB50205" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB50205" Ref="C?"  Part="1" 
AR Path="/5BB27BCC/5BB50205" Ref="C1011"  Part="1" 
F 0 "C1011" H 6645 3820 50  0000 L CNN
F 1 "47pF" H 6645 3620 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 6658 3570 50  0001 C CNN
F 3 "" H 6645 3820 50  0001 C CNN
F 4 "0603" H 6470 3820 50  0000 R CNN "display_footprint"
F 5 "50V" H 6470 3720 50  0000 R CNN "Voltage"
F 6 "C0G/NP0" H 6470 3620 50  0000 R CNN "Dielectric"
F 7 "478-1171-1-ND" H 7045 4220 60  0001 C CNN "Digi-Key PN"
	1    6620 3720
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR01024
U 1 1 5BB50277
P 5860 3870
F 0 "#PWR01024" H 5860 3620 50  0001 C CNN
F 1 "GND_USB" H 5860 3720 50  0000 C CNN
F 2 "" H 5860 3870 50  0001 C CNN
F 3 "" H 5860 3870 50  0001 C CNN
	1    5860 3870
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR01025
U 1 1 5BB502A3
P 6620 3870
F 0 "#PWR01025" H 6620 3620 50  0001 C CNN
F 1 "GND_USB" H 6620 3720 50  0000 C CNN
F 2 "" H 6620 3870 50  0001 C CNN
F 3 "" H 6620 3870 50  0001 C CNN
	1    6620 3870
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB50496
P 4820 3720
AR Path="/5BB27BA3/5BB50496" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB50496" Ref="C?"  Part="1" 
AR Path="/5BB27BCC/5BB50496" Ref="C1009"  Part="1" 
F 0 "C1009" H 4845 3820 50  0000 L CNN
F 1 "0.1uF" H 4845 3620 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4858 3570 50  0001 C CNN
F 3 "" H 4845 3820 50  0001 C CNN
F 4 "0603" H 4670 3820 50  0000 R CNN "display_footprint"
F 5 "50V" H 4670 3720 50  0000 R CNN "Voltage"
F 6 "X7R" H 4670 3620 50  0000 R CNN "Dielectric"
F 7 "490-8020-1-ND" H 5245 4220 60  0001 C CNN "Digi-Key PN"
	1    4820 3720
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR01023
U 1 1 5BB5053D
P 4820 3870
F 0 "#PWR01023" H 4820 3620 50  0001 C CNN
F 1 "GND_USB" H 4820 3720 50  0000 C CNN
F 2 "" H 4820 3870 50  0001 C CNN
F 3 "" H 4820 3870 50  0001 C CNN
	1    4820 3870
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB50764
P 2540 3780
AR Path="/5BB27BA3/5BB50764" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB50764" Ref="C?"  Part="1" 
AR Path="/5BB27BCC/5BB50764" Ref="C1004"  Part="1" 
F 0 "C1004" H 2565 3880 50  0000 L CNN
F 1 "0.1uF" H 2565 3680 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2578 3630 50  0001 C CNN
F 3 "" H 2565 3880 50  0001 C CNN
F 4 "0603" H 2390 3880 50  0000 R CNN "display_footprint"
F 5 "50V" H 2390 3780 50  0000 R CNN "Voltage"
F 6 "X7R" H 2390 3680 50  0000 R CNN "Dielectric"
F 7 "490-8020-1-ND" H 2965 4280 60  0001 C CNN "Digi-Key PN"
	1    2540 3780
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR01008
U 1 1 5BB508B4
P 2540 3930
F 0 "#PWR01008" H 2540 3680 50  0001 C CNN
F 1 "GND_USB" H 2540 3780 50  0000 C CNN
F 2 "" H 2540 3930 50  0001 C CNN
F 3 "" H 2540 3930 50  0001 C CNN
	1    2540 3930
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB50CA2
P 2540 2650
AR Path="/5BB27BA3/5BB50CA2" Ref="R?"  Part="1" 
AR Path="/5BB27BCC/5BB50CA2" Ref="R1004"  Part="1" 
F 0 "R1004" H 2460 2650 50  0000 R CNN
F 1 "10k" V 2540 2650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 2540 2650 50  0001 C CNN
F 3 "" H 2540 2650 50  0001 C CNN
F 4 "0603" H 2640 2730 50  0000 L CNN "display_footprint"
F 5 "1%" H 2640 2650 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 2650 2570 50  0000 L CNN "Wattage"
F 7 "RHM10KADCT-ND" H 2840 3050 60  0001 C CNN "Digi-Key PN"
	1    2540 2650
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR01007
U 1 1 5BB5169B
P 2540 2500
F 0 "#PWR01007" H 2540 2350 50  0001 C CNN
F 1 "+5V_USB" H 2540 2640 50  0000 C CNN
F 2 "" H 2540 2500 50  0001 C CNN
F 3 "" H 2540 2500 50  0001 C CNN
	1    2540 2500
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR01029
U 1 1 5BB518BA
P 8170 3950
F 0 "#PWR01029" H 8170 3700 50  0001 C CNN
F 1 "GND_USB" H 8170 3800 50  0000 C CNN
F 2 "" H 8170 3950 50  0001 C CNN
F 3 "" H 8170 3950 50  0001 C CNN
	1    8170 3950
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:R_Custom R?
U 1 1 5BB51B66
P 8800 5150
AR Path="/5BB27BA3/5BB51B66" Ref="R?"  Part="1" 
AR Path="/5BB27BCC/5BB51B66" Ref="R1009"  Part="1" 
F 0 "R1009" H 8720 5150 50  0000 R CNN
F 1 "1k" V 8800 5150 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" H 8800 5150 50  0001 C CNN
F 3 "" H 8800 5150 50  0001 C CNN
F 4 "0603" H 8900 5230 50  0000 L CNN "display_footprint"
F 5 "1%" H 8900 5150 50  0000 L CNN "Tolerance"
F 6 "1/10W" H 8910 5070 50  0000 L CNN "Wattage"
F 7 "MCT0603-1.00K-CFCT-ND" H 9100 5550 60  0001 C CNN "Digi-Key PN"
	1    8800 5150
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR01031
U 1 1 5BB52061
P 8800 4700
F 0 "#PWR01031" H 8800 4550 50  0001 C CNN
F 1 "+5V_USB" H 8800 4840 50  0000 C CNN
F 2 "" H 8800 4700 50  0001 C CNN
F 3 "" H 8800 4700 50  0001 C CNN
	1    8800 4700
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB2F222
P 3350 1820
AR Path="/5BB27BA3/5BB2F222" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB2F222" Ref="C?"  Part="1" 
AR Path="/5BB27BCC/5BB2F222" Ref="C1005"  Part="1" 
F 0 "C1005" H 3375 1920 50  0000 L CNN
F 1 "0.1uF" H 3375 1720 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3388 1670 50  0001 C CNN
F 3 "" H 3375 1920 50  0001 C CNN
F 4 "0603" H 3200 1920 50  0000 R CNN "display_footprint"
F 5 "50V" H 3200 1820 50  0000 R CNN "Voltage"
F 6 "X7R" H 3200 1720 50  0000 R CNN "Dielectric"
F 7 "490-8020-1-ND" H 3775 2320 60  0001 C CNN "Digi-Key PN"
	1    3350 1820
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB2F482
P 3980 1810
AR Path="/5BB27BA3/5BB2F482" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB2F482" Ref="C?"  Part="1" 
AR Path="/5BB27BCC/5BB2F482" Ref="C1006"  Part="1" 
F 0 "C1006" H 4005 1910 50  0000 L CNN
F 1 "0.1uF" H 4005 1710 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 4018 1660 50  0001 C CNN
F 3 "" H 4005 1910 50  0001 C CNN
F 4 "0603" H 3830 1910 50  0000 R CNN "display_footprint"
F 5 "50V" H 3830 1810 50  0000 R CNN "Voltage"
F 6 "X7R" H 3830 1710 50  0000 R CNN "Dielectric"
F 7 "490-8020-1-ND" H 4405 2310 60  0001 C CNN "Digi-Key PN"
	1    3980 1810
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:C_Custom C?
U 1 1 5BB2F4D0
P 4610 1800
AR Path="/5BB27BA3/5BB2F4D0" Ref="C?"  Part="1" 
AR Path="/5BB27B84/5BB2F4D0" Ref="C?"  Part="1" 
AR Path="/5BB27BCC/5BB2F4D0" Ref="C1008"  Part="1" 
F 0 "C1008" H 4635 1900 50  0000 L CNN
F 1 "4.7uF" H 4635 1700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 4648 1650 50  0001 C CNN
F 3 "" H 4635 1900 50  0001 C CNN
F 4 "0805" H 4460 1900 50  0000 R CNN "display_footprint"
F 5 "25V" H 4460 1800 50  0000 R CNN "Voltage"
F 6 "X7R" H 4460 1700 50  0000 R CNN "Dielectric"
F 7 "478-10056-1-ND" H 5035 2300 60  0001 C CNN "Digi-Key PN"
	1    4610 1800
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR01011
U 1 1 5BB2F9DC
P 3350 1970
F 0 "#PWR01011" H 3350 1720 50  0001 C CNN
F 1 "GND_USB" H 3350 1820 50  0000 C CNN
F 2 "" H 3350 1970 50  0001 C CNN
F 3 "" H 3350 1970 50  0001 C CNN
	1    3350 1970
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR01017
U 1 1 5BB2FA18
P 3980 1960
F 0 "#PWR01017" H 3980 1710 50  0001 C CNN
F 1 "GND_USB" H 3980 1810 50  0000 C CNN
F 2 "" H 3980 1960 50  0001 C CNN
F 3 "" H 3980 1960 50  0001 C CNN
	1    3980 1960
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:GND_USB #PWR01021
U 1 1 5BB2FA4D
P 4610 1950
F 0 "#PWR01021" H 4610 1700 50  0001 C CNN
F 1 "GND_USB" H 4610 1800 50  0000 C CNN
F 2 "" H 4610 1950 50  0001 C CNN
F 3 "" H 4610 1950 50  0001 C CNN
	1    4610 1950
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR01020
U 1 1 5BB2FAC3
P 4610 1650
F 0 "#PWR01020" H 4610 1500 50  0001 C CNN
F 1 "+5V_USB" H 4610 1790 50  0000 C CNN
F 2 "" H 4610 1650 50  0001 C CNN
F 3 "" H 4610 1650 50  0001 C CNN
	1    4610 1650
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR01016
U 1 1 5BB2FAFF
P 3980 1660
F 0 "#PWR01016" H 3980 1510 50  0001 C CNN
F 1 "+5V_USB" H 3980 1800 50  0000 C CNN
F 2 "" H 3980 1660 50  0001 C CNN
F 3 "" H 3980 1660 50  0001 C CNN
	1    3980 1660
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:+5V_USB #PWR01010
U 1 1 5BB2FB34
P 3350 1670
F 0 "#PWR01010" H 3350 1520 50  0001 C CNN
F 1 "+5V_USB" H 3350 1810 50  0000 C CNN
F 2 "" H 3350 1670 50  0001 C CNN
F 3 "" H 3350 1670 50  0001 C CNN
	1    3350 1670
	1    0    0    -1  
$EndComp
$Comp
L Custom_Library:LED_ALT_Custom D?
U 1 1 5BBD1770
P 8800 4850
AR Path="/5BB27B51/5BBD1770" Ref="D?"  Part="1" 
AR Path="/5BB7FA89/5BBD1770" Ref="D?"  Part="1" 
AR Path="/5BB27BCC/5BBD1770" Ref="D1002"  Part="1" 
F 0 "D1002" V 8800 4950 50  0000 L CNN
F 1 "Yellow" V 8870 4720 50  0000 R CNN
F 2 "LEDs:LED_0603" H 8800 4850 50  0001 C CNN
F 3 "" H 8800 4850 50  0001 C CNN
F 4 "0603" V 8790 4720 50  0000 R CNN "display_footprint"
F 5 "160-1448-1-ND" H 9000 5150 60  0001 C CNN "Digi-Key PN"
	1    8800 4850
	0    -1   -1   0   
$EndComp
$Comp
L Custom_Library:MU_Logo #G1001
U 1 1 5BB69985
P 9900 1100
F 0 "#G1001" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:Ferrite_Bead L1002
U 1 1 5BB59622
P 9980 3630
F 0 "L1002" V 9830 3655 50  0000 C CNN
F 1 "600R 0.5A" V 10130 3630 50  0000 C CNN
F 2 "Inductors_SMD:L_0603" V 9910 3630 50  0001 C CNN
F 3 "~" H 9980 3630 50  0001 C CNN
F 4 "732-1593-1-ND" V 9980 3630 50  0001 C CNN "Digi-Key PN"
	1    9980 3630
	0    -1   -1   0   
$EndComp
$Comp
L Custom_Library:GND_USB #PWR01034
U 1 1 5BB59B66
P 10210 3710
F 0 "#PWR01034" H 10210 3460 50  0001 C CNN
F 1 "GND_USB" H 10210 3560 50  0000 C CNN
F 2 "" H 10210 3710 50  0001 C CNN
F 3 "" H 10210 3710 50  0001 C CNN
	1    10210 3710
	1    0    0    -1  
$EndComp
Wire Wire Line
	10210 3710 10210 3630
Wire Wire Line
	10210 3630 10130 3630
Wire Wire Line
	9830 3630 9600 3630
Wire Wire Line
	9600 3630 9600 3580
Wire Wire Line
	5860 3180 7790 3180
Wire Wire Line
	7690 2460 7690 3280
Connection ~ 7690 3280
Wire Wire Line
	7690 3280 6620 3280
Wire Wire Line
	7690 3280 9200 3280
Wire Wire Line
	7790 3180 7790 2460
Connection ~ 7790 3180
Wire Wire Line
	7790 3180 9200 3180
Text Notes 2030 6200 0    75   ~ 0
USB COM Port Settings:\nBaud Rate: 115200 bps\nData Width: 8 bit\nParity: None\nStop Bits: 1 bit\nFlow Control: None
$EndSCHEMATC
