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
Text Notes 540  690  0    100  ~ 20
Firmware Notes
$Comp
L Custom_Library:MU_Logo #G1801
U 1 1 5BB8481C
P 9900 1100
F 0 "#G1801" H 9900 614 60  0001 C CNN
F 1 "MU_Logo" H 9900 1586 60  0001 C CNN
F 2 "" H 9900 1100 50  0001 C CNN
F 3 "" H 9900 1100 50  0001 C CNN
	1    9900 1100
	1    0    0    -1  
$EndComp
Text Notes 720  2240 0    50   ~ 0
* Configure RA0 as both an ADC input and the inverting input into an internal comparator\n* Comparator will be used with internal DAC to set a current limit\n* Configure ADC clock as FRC, external +/-VREF\n* Configure clocking structure to use ECM clock mode, 16MHz clock input, 4xPLL = 64MHz SYSCLK\n* Configure RA4 as an ADC input\n* Configure RA5 as EXTINT0 for ZCD\n* Configure RB0 as EXTINT1 for output switching\n* Configure RB6:7 as MSSP1 I2C IO\n* Configure RC2 and RC3 as interrupt on change inputs\n* Configure RE2 as an ADC input\n* Configure RF0 as open drain output, force low after booting\n* Configure RF1:3 as push pull outputs, start low\n* Configure RG6 as EUSART2 RX and RG7 as EUSART2 TX\n* Configure the ADC to use digital filtering with lowest crossover frequency\n* Use Timer7 to gather ADC data on all channels and run calculations on it at a fixed time base\n* Use Timer5 as the time base for output dimming\n* Use Timer6 as hearthbeat time base
$EndSCHEMATC
