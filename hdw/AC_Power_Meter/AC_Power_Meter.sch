EESchema Schematic File Version 4
LIBS:AC_Power_Meter-cache
EELAYER 26 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 1 17
Title ""
Date "2018-10-01"
Rev "A"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 3470 1440 500  150 
U 5BB27B1A
F0 "AC Input" 50
F1 "AC_Input.sch" 50
$EndSheet
$Sheet
S 3470 1910 500  150 
U 5BB27B24
F0 "AC Current Sensor" 50
F1 "AC_Current_Sensor.sch" 50
$EndSheet
$Sheet
S 3470 2380 500  150 
U 5BB27B36
F0 "AC Output" 50
F1 "AC_Output.sch" 50
$EndSheet
$Sheet
S 3470 2850 500  150 
U 5BB27B51
F0 "POS12 Power Supply" 50
F1 "POS12_Power_Supply.sch" 50
$EndSheet
$Sheet
S 3470 3320 500  150 
U 5BB27B73
F0 "POS3P3 Power Supply" 50
F1 "POS3P3_Power_Supply.sch" 50
$EndSheet
$Sheet
S 3470 3790 500  150 
U 5BB27B84
F0 "Microcontroller" 50
F1 "Microcontroller.sch" 50
$EndSheet
$Sheet
S 3470 4260 500  150 
U 5BB27BA3
F0 "Microcontroller Programming" 50
F1 "Microcontroller_Programming.sch" 50
$EndSheet
$Sheet
S 3470 4730 500  150 
U 5BB27BB5
F0 "Sensor Signal Conditioning" 50
F1 "Sensor_Signal_Conditioning.sch" 50
$EndSheet
$Sheet
S 3470 5200 500  150 
U 5BB27BCC
F0 "USB UART Bridge" 50
F1 "USB_UART_Bridge.sch" 50
$EndSheet
$Sheet
S 3470 5670 500  150 
U 5BB27BE1
F0 "USB UART Isolation" 50
F1 "USB_UART_Isolation.sch" 50
$EndSheet
$Sheet
S 3470 6140 500  150 
U 5BB27BF7
F0 "OLED Display" 50
F1 "OLED_Display.sch" 50
$EndSheet
$Sheet
S 7720 1440 500  150 
U 5BB27C33
F0 "Mechanical" 50
F1 "Mechanical.sch" 50
$EndSheet
$Comp
L Custom_Library:MU_Logo #G101
U 1 1 5BB67CD7
P 9900 1100
F 0 "#G101" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
Text Notes 540  690  0    100  ~ 20
Table of Contents:
Text Notes 4070 780  0    150  ~ 30
AC Power Meter
Text Notes 770  6260 0    100  ~ 0
1. AC Input\n\n\n2. AC Current Sensor\n\n\n3. AC Output\n\n\n4. +12V Power Supply\n\n\n5. +3.3V Power Supply\n\n\n6. Microcontroller\n\n\n7. Microcontoller Programming\n\n\n8. Sensor Signal Conditioning\n\n\n9. USB UART Bridge\n\n\n10. USB UART Isolation\n\n\n11. OLED Display
Text Notes 5660 3480 0    100  ~ 0
12. Mechanical\n\n\n13. Zero Cross Detect\n\n\n14. Output Switch\n\n\n15. Status LEDs\n\n\n17. Firmware Notes
$Sheet
S 7720 1940 500  150 
U 5BBE5EA4
F0 "Zero Cross Detect" 50
F1 "Zero_Cross_Detect.sch" 50
$EndSheet
$Sheet
S 7720 2440 500  150 
U 5BBE5EA9
F0 "Output Switch" 50
F1 "Output_Switch.sch" 50
$EndSheet
$Sheet
S 7720 2850 500  150 
U 5BB7FA89
F0 "Status LEDs" 50
F1 "Status_LEDs.sch" 50
$EndSheet
$Sheet
S 7720 3350 500  150 
U 5BB83979
F0 "Firmware Notes" 50
F1 "Firmware_Notes.sch" 50
$EndSheet
$EndSCHEMATC
