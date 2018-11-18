/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18LF67K40
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/*>>>>>>>>>>>>>>>>>>>>>>>>> File Inclusions <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */
#include <xc.h>
#include "mcc_generated_files/mcc.h"

#include <math.h>
#include <string.h>

#include "error_handling.h"
#include "pin_macros.h"
#include "device_IDs.h"
#include "cause_of_reset.h"
#include "ring_buffer_interface.h"
#include "double_to_EEPROM.h"
#include "oled.h"

// User IDs
#pragma config IDLOC0 = 0xD
#pragma config IDLOC1 = 0xE
#pragma config IDLOC2 = 0xA
#pragma config IDLOC3 = 0xD
#pragma config IDLOC4 = 0xB
#pragma config IDLOC5 = 0xE
#pragma config IDLOC6 = 0xE
#pragma config IDLOC7 = 0xF

/*>>>>>>>>>>>>>>>>>>>>>>>>> Global variables / Macros <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

// Pi
#define M_PI acos(-1.0)

// ADC Double Precision Post Processing Variables
volatile double FVR_ADC_Result;                 // Measured FVR voltage in volts, should be 2.048 (used for ADC calibration)
volatile double AVSS_ADC_Result;                // Measured AVSS voltage in volts (should be close to zero)
volatile double ADC_Result_Scaling;             // Scaling factor on ADC measurements from AVSS and FVR values
volatile double POS3P3_ADC_Result;              // POS3P3 Measurement in Volts
volatile double POS12_ADC_Result;               // POS12 Measurement in volts
volatile double Temp_ADC_Result;                // Temperature ADC result in degrees centigrade
volatile double Temp_ADC_Offset = 632.085;     // Temp ADC result offset in degrees centigrade
double Vpk_const = 169.7056274847714;           // Peak voltage in volts, sqrt(2) * 120
volatile double Vpk;                            // Calculated peak voltage from phase angle in volts
volatile double Ipk;                            // Calculated peak current from measurements and phase angle in amps
volatile double Imeas;                          // Measured current in amps
double Irms_offset = -0.113;                    // RMS current offset in amps
volatile double Irms;                           // RMS output current in amps
volatile double Vrms;                           // Calculated RMS output voltage in volts
volatile double Avg_Power;                      // Calculated output power in watts
volatile double Total_Energy;                   // Calculated energy in Watt Hours
volatile double TRIAC_Firing_Angle = 1.57;      // firing angle in radians

// more global variables
volatile unsigned int dimming_period = 0x7FEE;  // Maximum is 0xFFFF which corresponds to 0% on time
volatile bit load_enable = 0;                   // Load enabled flag
volatile bit eusart2RxStringReady = 0;          // ring buffer ready flag
volatile unsigned long dev_on_time = 0;         // On time counter, increments with heartbeat
volatile unsigned long load_on_time = 0;        // Load on time in seconds
reset_t reset_cause;                            // The cause of the most recent reset
adcc_channel_t next_channel = channel_VSS;                    // The next channel for the ADC to convert

// SRAM copies of values saved in EEPROM:
volatile double max_Irms;
volatile double max_Power;
volatile double max_POS3P3_ADC_Result;
volatile double max_POS12_ADC_Result;
volatile double max_Temp_ADC_Result;
volatile double max_FVR_ADC_Result;

// EEPROM variable addresses
const uint16_t max_Irms_address                 = 0x0000;
const uint16_t max_Power_address                = 0x0004;
const uint16_t max_POS3P3_ADC_Result_address    = 0x0008;
const uint16_t max_POS12_ADC_Result_address     = 0x000C;
const uint16_t max_Temp_ADC_Result_address      = 0x0010;
const uint16_t max_FVR_ADC_Result_address       = 0x0014;
const uint16_t Total_Energy_address             = 0x0018;

// strings to print current values on OLED
char print_Irms_str[17];
char print_Power_str[17];
char print_Vrms_str[17];
char print_Energy_str[17];

/*>>>>>>>>>>>>>>>>>>>>>>>>> Local Functions <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

// Calculate RMS from peak value for phase cutting
// Pass 'Peak' parameter as peak value
// Pass 'Angle' parameter as triac firing angle in radians
double peakToRMS(double Peak, double Angle) {

    // Start with a blank slate
    double RMS = 0.0;
    
    // Calculate RMS from phase angle and peak value
    RMS = 2.0 * M_PI;
    RMS = RMS - (2.0 * Angle);
    RMS = RMS + sin(2.0 * Angle);
    RMS = RMS / (4.0 * M_PI);
    RMS = sqrt(RMS);
    RMS = Peak * RMS;
    return RMS;
    
}

// Back-calculate peak current value from measured cut waveform
double currentMeasuredToPeak(double Measured, double Angle) {
    
    // Start with a blank slate
    double Peak = 0.0;
    
    // Calculate peak value by backtracking through waveform
    Peak = sin(Angle);
    Peak = Measured / Peak;
    return Peak;
    
}

// This function determines if a new maximum value needs to be written to EEPROM
void saveSRAMMaxToEEPROM(void) {
 
    // Check if current values are greater than saved values, if they are write over them in EEPROM
    // and copy them to SRAM maximum values
    if (Irms > max_Irms) {
        writeDoubleToEEPROM(Irms, max_Irms_address);
        max_Irms = Irms;
    }

    if (Avg_Power > max_Power) {
        writeDoubleToEEPROM(Avg_Power, max_Power_address);
        max_Power = Avg_Power;
    }
    
    if (POS3P3_ADC_Result > max_POS3P3_ADC_Result) {
        writeDoubleToEEPROM(POS3P3_ADC_Result, max_POS3P3_ADC_Result_address);
        max_POS3P3_ADC_Result = POS3P3_ADC_Result;
    }
    
    if (POS12_ADC_Result > max_POS12_ADC_Result) {
        writeDoubleToEEPROM(POS12_ADC_Result, max_POS12_ADC_Result_address);
        max_POS12_ADC_Result = POS12_ADC_Result;
    }
    
    if (Temp_ADC_Result > max_Temp_ADC_Result) {
        writeDoubleToEEPROM(Temp_ADC_Result, max_Temp_ADC_Result_address);
        max_Temp_ADC_Result = Temp_ADC_Result;
    }
    
    if (FVR_ADC_Result > max_FVR_ADC_Result) {
        writeDoubleToEEPROM(FVR_ADC_Result, max_FVR_ADC_Result_address);
        max_FVR_ADC_Result = FVR_ADC_Result;
    }
    
}

// This function refreshes SRAM variables from save locations in EEPROM
void recoverSRAMMaxFromEEPROM(void) {
 
    max_Irms                = readDoubleFromEEPROM(max_Irms_address);
    max_Power               = readDoubleFromEEPROM(max_Power_address);
    max_POS3P3_ADC_Result   = readDoubleFromEEPROM(max_POS3P3_ADC_Result_address);
    max_POS12_ADC_Result    = readDoubleFromEEPROM(max_POS12_ADC_Result_address);
    max_Temp_ADC_Result     = readDoubleFromEEPROM(max_Temp_ADC_Result_address);
    max_FVR_ADC_Result      = readDoubleFromEEPROM(max_FVR_ADC_Result_address);
    Total_Energy            = readDoubleFromEEPROM(Total_Energy_address);
    
    if (Total_Energy < 0.0) {
        
        Total_Energy = 0.0;
        
    }
    
}


/*>>>>>>>>>>>>>>>>>>>>>>>>> Callback Functions <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

// This function is called upon TMR6 ISR and toggles the heartbeat LED, as well
// as resets the watchdog timer
void heartbeatTimerCallback(void) {
 
    // Toggle heartbeat pin
    HEARTBEAT_PIN = !HEARTBEAT_PIN;
    
    // increment on time counter
    dev_on_time++;
    
    // If the load is enabled, increment counter
    if (load_enable) {
    
        load_on_time++;
    
    }
    
    // Kick the dog
    CLRWDT();
    
}

// Callback function for ADCC interrupts
void ADC_PostProcessingCallback(void) {
 
    // If the ADC is still going, shut it off
    ADCC_StopConversion();
    
    // Current channel is what's left in ADC channel select register
    adcc_channel_t current_adc_channel = ADPCH;
    
    // Determine post processing based on current channel
    switch (current_adc_channel) {
        
        case channel_VSS:
            
            AVSS_ADC_Result = (ADCC_GetConversionResult()) * (3.3/1023.0);
            
            if ((AVSS_ADC_Result > 0.01) || ADCC_HasAccumulatorOverflowed()) {
             
                error_handler.AVSS_ADC_error_flag = true;
                return;
                
            }
            
            next_channel = channel_FVR_buf1;
            
            break;
        
        // FVR Buffer 1 ADC post processing
        case channel_FVR_buf1:
            
            FVR_ADC_Result = (ADCC_GetConversionResult()) * (3.3/1023.0) + AVSS_ADC_Result;
            ADC_Result_Scaling = 2.048/FVR_ADC_Result;
            
            if (FVR_ADC_Result > 2.5 || FVR_ADC_Result < 2.0 || ADCC_HasAccumulatorOverflowed()) {
             
                error_handler.FVR_ADC_error_flag = true;
                return;
                
            }
            
            next_channel = POS3P3_ADC;
            
            break;
            
        // POS3P3_ADC Post Processing
        case POS3P3_ADC:
            
            POS3P3_ADC_Result = ((ADCC_GetFilterValue()) * (3.3/1023.0)) * 2.0 * ADC_Result_Scaling;
            
            if (POS3P3_ADC_Result > 3.5  || ADCC_HasAccumulatorOverflowed()) {
             
                error_handler.POS3P3_ADC_error_flag = true;
                return;
                
            }
            
            next_channel = ISNS_ADC;
            
            break;
            
        // current sensor ADC post processing
        case ISNS_ADC:
            
            Imeas = (ADCC_GetFilterValue()) * (POS3P3_ADC_Result/1023.0) * (3.787 / 2.0);
            
            // If our phase is controlled, convert measured current to peak current
            // and peak current to RMS current using TRIAC firing angle
            if (SSR_FORCE_PIN != 1) {
                

                // Only measure if load is enabled, set peak values to 0.0 otherwise

                if (load_enable) {

                    // If we're dimming more than 50%, the peak current will still be the measured current
                    if (dimming_period < 0x7FEE) {

                        Ipk = Imeas;
                        Irms = abs(peakToRMS(Ipk, TRIAC_Firing_Angle) + Irms_offset);

                    }

                    // If we're dimming less than 50%, peak current needs to be calculated
                    else {

                        Ipk = currentMeasuredToPeak(Imeas, TRIAC_Firing_Angle);
                        Irms = abs(peakToRMS(Ipk, TRIAC_Firing_Angle) + Irms_offset);

                    }

                    Vpk = Vpk_const;

                }

                else {

                    Ipk = 0.0;
                    Vpk = 0.0;
                    Irms = abs(peakToRMS(Ipk, TRIAC_Firing_Angle));

                }
                 
                Vrms = peakToRMS(Vpk, TRIAC_Firing_Angle);
                Avg_Power = Vrms * Irms;
                Total_Energy = Total_Energy + (Avg_Power * 0.07 / 3600.0);
                
            }
            
            // Ignore phase cutting if we're all the way on, convert raw peak value to RMS
            else {
             
                Ipk = Imeas;
                Irms = abs(peakToRMS(Ipk, 0.0) + Irms_offset);
                Vrms = peakToRMS(Vpk_const, 0.0);
                Avg_Power = Vrms * Irms;
                Total_Energy = Total_Energy + (Avg_Power * 0.07 / 3600.0);
                
            }

            if (Irms > 5.0  || ADCC_HasAccumulatorOverflowed()) {
             
                error_handler.ISNS_ADC_error_flag = true;
                return;
                
            }
            
            next_channel = POS12_ADC;
            
            break;
            
        // POS12 ADC Post Processing
        case POS12_ADC:
            
            POS12_ADC_Result = (ADCC_GetFilterValue()) * (POS3P3_ADC_Result/1023.0) * 4.0303030303;
            
            if (POS12_ADC_Result > 13.6  || ADCC_HasAccumulatorOverflowed()) {
             
                error_handler.POS12_ADC_error_flag = true;
                return;
                
            }
            
            next_channel = channel_Temp;
            
            break;
            
        // Internal temperature indicator ADC post processing
        case channel_Temp:
            
            Temp_ADC_Result = (0.659 - (POS3P3_ADC_Result/2.0) * (1 - ADCC_GetConversionResult()/1023.0)) / .00132 - 40.0 + Temp_ADC_Offset;
            
            if (Temp_ADC_Result > 100.0 || ADCC_HasAccumulatorOverflowed()) {
             
                error_handler.Temp_ADC_error_flag = 1;
                return;
                
            }
            
            next_channel = channel_VSS;
            
            break;
            
        // Default case, there was an error
        // This should not happen
        default:
            error_handler.ADC_general_error_flag = true;
            break;
        
    }
    
    if (ADCC_GetCurrentCountofConversions() != 255) {
        error_handler.ADC_general_error_flag = true;
    }
    
    if (ADCC_HasAccumulatorOverflowed()) {
        error_handler.ADC_general_error_flag = true;
    }
    
}

// Acquisition callback
void acquisitionTimerCallback(void) {

    // Empty sampling cap
    ADCC_DischargeSampleCapacitor();
    
    // Clear filter accumulator, start fresh with new channel
    ADCC_ClearAccumulator();
    
    // Start conversion with next channel to convert
    ADCC_StartConversion(next_channel);
    
}

// dimming off time callback
void dimmingOffTimeCallback(void) {
 
    // Turn the TRIAC off
    SSR_DIM_PIN = LOW;
    
    // Load timer with pre-load value and start timer
    TMR5_WriteTimer(dimming_period);
    TMR5_StartTimer();
    
    // Enable timer 5 interrupt
    PIE5bits.TMR5IE = 1;
    
}

// dimming on time callback
void dimmingOnTimeCallback(void) {
 
    // Turn triac on
    SSR_DIM_PIN = HIGH;
    
    // Shutoff dimming timer (TMR5)
    TMR5_StopTimer();
    
    // Disable timer 5 interrupt
    PIE5bits.TMR5IE = 0;
    
    
}

// This function is called upon TMR4 ISR and saves energy variable into EEPROM
// This function should be called at a fixed but extremely low frequency
// to avoid NVM burnout
void writeEnergyToEEPROMCallback(void) {

    double current_value = readDoubleFromEEPROM(Total_Energy_address);
    
    if (Total_Energy > current_value) {
        
        writeDoubleToEEPROM(Total_Energy, Total_Energy_address);
    
    }
    
}

// This function is called by timer 2 ISR and updates the OLED display 
// based on the OLED_Frame enumeration
void OLED_updateCallback(void) {
 
    switch (OLED_Frame) {
     
        case Boot_Frame_1:
            
            TMR2_StopTimer();
            TMR2_WriteTimer(0);
            CountCallBack = 0;
            
            // Print boot message 1
            strcpy(OLED_RAM_Buffer.line0, "AC Power Meter");
            strcpy(OLED_RAM_Buffer.line1, "ELEN 3035");
            strcpy(OLED_RAM_Buffer.line2, "Final Project");
            strcpy(OLED_RAM_Buffer.line3, getCauseOfResetStringSmall(reset_cause));
            OLED_UpdateFromRAMBuffer();
            OLED_Frame = Boot_Frame_2;
            
            TMR2_StartTimer();
            
            break;
            
        case Boot_Frame_2:
            
            TMR2_StopTimer();
            TMR2_WriteTimer(0);
            CountCallBack = 0;
            
            // Print boot message 2
            // Device ID
            strcpy(OLED_RAM_Buffer.line0, "Device ID:");
            char dev_id_str[17];
            sprintf(dev_id_str,"0x%X",getDeviceID());
            strcpy(OLED_RAM_Buffer.line1, dev_id_str);
            
            // Rev ID
            strcpy(OLED_RAM_Buffer.line2, "Revision ID:");
            char rev_id_str[17];
            sprintf(rev_id_str, "%c%03d", (char) getMajorRevisionID() + 65, getMinorRevisionID());
            strcpy(OLED_RAM_Buffer.line3, rev_id_str);
            
            OLED_UpdateFromRAMBuffer();
            OLED_Frame = Boot_Frame_3;
            
            TMR2_StartTimer();
            
            break;
            
        case Boot_Frame_3:
            
            TMR2_StopTimer();
            TMR2_WriteTimer(0);
            CountCallBack = 0;
            
            strcpy(OLED_RAM_Buffer.line0, "COM Port Setup:");
            strcpy(OLED_RAM_Buffer.line1, "115.2 kbs");
            strcpy(OLED_RAM_Buffer.line2, "8bit, no parity");
            strcpy(OLED_RAM_Buffer.line3, "1 stp, no flow");
            
            OLED_UpdateFromRAMBuffer();
            OLED_Frame = Boot_Frame_4;;
            
            TMR2_StartTimer();
            
            break;
            
        case Boot_Frame_4:
            
            TMR2_StopTimer();
            TMR2_WriteTimer(0);
            CountCallBack = 0;
            
            strcpy(OLED_RAM_Buffer.line0, "Boot Complete");
            strcpy(OLED_RAM_Buffer.line1, "Load Enabled,");
            strcpy(OLED_RAM_Buffer.line2, "More Settings");
            strcpy(OLED_RAM_Buffer.line3, "via USB, 'Help'");
            
            OLED_UpdateFromRAMBuffer();
            OLED_Frame = Live_Update;
            
            TMR2_StartTimer();
            
            break;
            
        case Load_Enabled:
            
            TMR2_StopTimer();
            TMR2_WriteTimer(0);
            CountCallBack = 0;
            
            strcpy(OLED_RAM_Buffer.line0, "Load Enabled");
            strcpy(OLED_RAM_Buffer.line1, " ");
            strcpy(OLED_RAM_Buffer.line2, " ");
            strcpy(OLED_RAM_Buffer.line3, " ");
            
            OLED_UpdateFromRAMBuffer();
            
            OLED_Frame = Live_Update;
            TMR2_Period8BitSet(0x64);   // Set TMR2 to faster rate
            TMR2_StartTimer();
            
            break;
            
        case Load_Disabled:
            
            TMR2_StopTimer();
            TMR2_WriteTimer(0);
            CountCallBack = 0;
            
            strcpy(OLED_RAM_Buffer.line0, "Load Disabled");
            strcpy(OLED_RAM_Buffer.line1, " ");
            strcpy(OLED_RAM_Buffer.line2, " ");
            strcpy(OLED_RAM_Buffer.line3, " ");
            
            OLED_UpdateFromRAMBuffer();
            
            OLED_Frame = Idle;
            TMR2_Period8BitSet(0x64);   // Set TMR2 to faster rate
            TMR2_StartTimer();
            
            break;
            
        case Dimming_Enabled:
            
            TMR2_StopTimer();
            TMR2_WriteTimer(0);
            CountCallBack = 0;
            
            strcpy(OLED_RAM_Buffer.line0, "Dimming Enabled");
            strcpy(OLED_RAM_Buffer.line1, " ");
            strcpy(OLED_RAM_Buffer.line2, " ");
            strcpy(OLED_RAM_Buffer.line3, " ");
            
            OLED_UpdateFromRAMBuffer();
            
            if (load_enable) {
            
                OLED_Frame = Live_Update;
                TMR2_Period8BitSet(0x64);   // Set TMR2 to faster rate
                TMR2_StartTimer();
                
            }
            
            else {
            
                OLED_Frame = Load_Disabled;
                TMR2_Period8BitSet(0xC2);   // Set TMR2 to slower rate set in MCC
                TMR2_StartTimer();
            }
            
            break;
            
        case Dimming_Disabled:
            
            TMR2_StopTimer();
            TMR2_WriteTimer(0);
            CountCallBack = 0;
            
            strcpy(OLED_RAM_Buffer.line0, "Dimming Disabled");
            strcpy(OLED_RAM_Buffer.line1, " ");
            strcpy(OLED_RAM_Buffer.line2, " ");
            strcpy(OLED_RAM_Buffer.line3, " ");
            
            OLED_UpdateFromRAMBuffer();
            
            if (load_enable) {
            
                OLED_Frame = Live_Update;
                TMR2_Period8BitSet(0x64);   // Set TMR2 to faster rate
                TMR2_StartTimer();
                
            }
            
            else {
            
                OLED_Frame = Load_Disabled;
                TMR2_Period8BitSet(0xC2);   // Set TMR2 to slower rate set in MCC
                TMR2_StartTimer();
            }
                
            break;
            
        case Dimming_Percentage:
            
            TMR2_StopTimer();
            TMR2_WriteTimer(0);
            CountCallBack = 0;
            TMR2_Period8BitSet(0xC2);   // Set TMR2 to slower rate set in MCC
            
            strcpy(OLED_RAM_Buffer.line0, "Dimming Percent:");
            char percentage_string[17];
            float percentage = (dimming_period / (float) 0xFFFF);
            percentage = round(percentage * 100.0);
            sprintf(percentage_string, "%.3f Percent", percentage);
            strcpy(OLED_RAM_Buffer.line1, percentage_string);
            
            strcpy(OLED_RAM_Buffer.line2, "TRIAC Angle:");
            char angle_string[17];
            float TRIAC_degrees = round(TRIAC_Firing_Angle * (180.0 / M_PI));
            sprintf(angle_string, "%.3f Deg", TRIAC_degrees);
            strcpy(OLED_RAM_Buffer.line3, angle_string);
            
            OLED_UpdateFromRAMBuffer();
            
            if (load_enable) {
            
                OLED_Frame = Live_Update;
                
            }
            
            else {
            
                OLED_Frame = Load_Disabled;

            }
            
            TMR2_StartTimer();

            break;
            
        case Live_Update:
            
            TMR2_StopTimer();
            TMR2_WriteTimer(0);
            CountCallBack = 0;
            
            // Print IRMS to OLED
            sprintf(print_Irms_str, "%.3f ARMS", Irms);
            strcpy(OLED_RAM_Buffer.line0, print_Irms_str);
            
            // Print voltage
            sprintf(print_Vrms_str, "%.3f VRMS", Vrms);
            strcpy(OLED_RAM_Buffer.line1, print_Vrms_str);
            
            // Print Power
            sprintf(print_Power_str, "%.3f Watts", Avg_Power);
            strcpy(OLED_RAM_Buffer.line2, print_Power_str);
            
            // Determine size of energy and print
            if (Total_Energy >= 1000.0) {
             
                sprintf(print_Energy_str, "%.3e WHours", Total_Energy);
                
            }
            
            else if (Total_Energy >= 100.0) {
             
                sprintf(print_Energy_str, "%.1f WHours", Total_Energy);
                
            }
            
            else {
            
                sprintf(print_Energy_str, "%.3f WHours", Total_Energy);
                
            }
            
            strcpy(OLED_RAM_Buffer.line3, print_Energy_str);
            
            
            OLED_UpdateFromRAMBuffer();
            
            OLED_Frame = Live_Update;
            TMR2_Period8BitSet(0x31);   // Set TMR2 to faster rate
            TMR2_StartTimer();
            
            break;
        
        case Idle:
            break;
            
        default:
            break;
        
    }
    
}


/*>>>>>>>>>>>>>>>>>>>>>>>>> Main Application <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

void main(void)
{
    
    // Determine the cause of the most recent reset, save to enum
    reset_cause = getCauseOfReset();
    
    // Wait a bit before booting to let the reset LED shine a little longer
    // This is helpful for visualizing quick resets
    __delay_ms(250);
    
    // Initialize the device
    SYSTEM_Initialize();
        
    // Retrieve saved EEPROM variables
    recoverSRAMMaxFromEEPROM();
    
    // Force SSR on at startup with dimming disabled
    // User can change this with serial commands
    SSR_FORCE_PIN = 1;
    SSR_DIM_PIN = 0;
    load_enable = 1;

    // Disable OLED update timer, clear it
    TMR2_StopTimer();
    TMR2_WriteTimer(0);
    
    // Call heartbeat function upon timer 6 ISR
    TMR6_SetInterruptHandler(heartbeatTimerCallback);
    
    // Call ADC callback upon ADCC interrupt
    ADCC_SetADTIInterruptHandler(ADC_PostProcessingCallback);
    
    // Set acquisition callback to be called upon TMR7 Interrupt
    TMR7_SetInterruptHandler(acquisitionTimerCallback);
    
    // assign dimming offtime callback to INT0
    INT0_SetInterruptHandler(dimmingOffTimeCallback);
    
    // Assign dimming on time callback to timer 5 overflow
    TMR5_SetInterruptHandler(dimmingOnTimeCallback);
    
    // Assign energy to EEPROM callback function to timer 4 ISR
    TMR4_SetInterruptHandler(writeEnergyToEEPROMCallback);
    
    // Assign OLED update callback to timer 2 ISR
    TMR2_SetInterruptHandler(OLED_updateCallback);
    
    // Disable dimming on startup
    TMR5_StopTimer();
    PIE0bits.INT0IE = 0;
    
    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();

    // Clear terminal, reset cursor, reset text attributes
    terminal_clearTerminal();
    terminal_setCursorHome();
    terminal_textAttributesReset();
    
    // Setup OLED
    OLED_Init();
    OLED_Clear();
    
    // Start OLED state machine, force callback
    OLED_Frame = Boot_Frame_1;
    OLED_updateCallback();
    
    terminal_printResetMessage();
    
    // Main loop
    while (1)
    {
        
        // Check eusart ready flag
        if (eusart2RxStringReady) {
         
            terminal_ringBufferPull();
            
        }
        
        // Save new maximums (if greater than saved) to EEPROM
        saveSRAMMaxToEEPROM();
        
        // Update error LEDs
        updateErrorLEDs();
        
    }
}
/**
 End of File
*/