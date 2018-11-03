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
#include "mcc_generated_files/mcc.h"

#include <math.h>

#include "pin_macros.h"
#include "ring_buffer_interface.h"

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
volatile double Temp_ADC_Offset = -267.409;     // Temp ADC result offset in degrees centigrade
double Vpk_const = 169.7056274847714;           // Peak voltage in volts, sqrt(2) * 120
volatile double Vpk;                            // Calculated peak voltage from phase angle in volts
volatile double Ipk;                            // Calculated peak current from measurements and phase angle in amps
volatile double Imeas;                          // Measured current in amps
double Irms_offset = -0.113;                    // RMS current offset in amps
volatile double Irms;                           // RMS output current in amps
volatile double Vrms;                           // Calculated RMS output voltage in volts
volatile double Avg_Power;                      // Calculated output power in watts
volatile double TRIAC_Firing_Angle = 90.0;      // firing angle in radians

// more global variables
volatile unsigned int dimming_period = 0x7FEE;  // Maximum is 0xFFFF which corresponds to 0% on time;
volatile bit load_enable = 0;                   // Load enabled flag
volatile bit eusart2RxStringReady = 0;          // ring buffer ready flag
volatile unsigned long dev_on_time = 0;         // On time counter, increments with heartbeat
volatile unsigned long load_on_time = 0;        // Load on time in seconds




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
void ADC_postProcessingCallback(void) {
 
    adcc_channel_t currentADCChannel = ADPCH;
    
    switch (currentADCChannel) {
        
        case channel_VSS:
            AVSS_ADC_Result = (ADCC_GetConversionResult()) * (3.3/1023.0);
            break;
        
        // FVR Buffer 1 ADC post processing
        case channel_FVR_buf1:
            FVR_ADC_Result = (ADCC_GetConversionResult()) * (3.3/1023.0) + AVSS_ADC_Result;
            ADC_Result_Scaling = 2.048/FVR_ADC_Result;
            break;
            
        // POS3P3_ADC Post Processing
        case POS3P3_ADC:
            POS3P3_ADC_Result = ((ADCC_GetConversionResult()) * (3.3/1023.0)) * 2.0 * ADC_Result_Scaling;
            break;
            
        case ISNS_ADC:
            Imeas = (ADCC_GetConversionResult()) * (POS3P3_ADC_Result/1023.0) * (3.787 / 2.0);
            
            // If our phase is controlled, convert measured current to peak current
            // and peak current to RMS current using TRIAC firing angle
            if (SSR_FORCE_PIN != 1) {
                

                // Only measure if load is enabled, set peak values to 0.0 otherwise

                if (load_enable) {

                    // If we're dimming more than 50%, the peak current will still be the measured current
                    if (dimming_period < 0x7FEE) {

                        Ipk = Imeas;

                    }

                    // If we're dimming less than 50%, peak current needs to be calculated
                    else {

                        Ipk = currentMeasuredToPeak(Imeas, TRIAC_Firing_Angle);

                    }

                    Vpk = Vpk_const;

                }

                else {

                    Ipk = 0.0;
                    Vpk = 0.0;

                }
                 
                Irms = peakToRMS(Ipk, TRIAC_Firing_Angle) + Irms_offset;
                Vrms = peakToRMS(Vpk, TRIAC_Firing_Angle);
                Avg_Power = Vrms * Irms;
                
            }
            
            // Ignore phase cutting if we're all the way on, convert raw peak value to RMS
            else {
             
                Ipk = Imeas;
                Irms = peakToRMS(Ipk, 0.0) + Irms_offset;
                Vrms = peakToRMS(Vpk_const, 0.0);
                Avg_Power = Vrms * Irms;
                
            }
            break;
            
        // POS12 ADC Post Processing
        case POS12_ADC:
            POS12_ADC_Result = (ADCC_GetConversionResult()) * (POS3P3_ADC_Result/1023.0) * 4.0303030303;
            break;
            
        // Internal temperature indicator ADC post processing
        case channel_Temp:
            Temp_ADC_Result = (0.659 - (POS3P3_ADC_Result/2.0) * (1 - ADCC_GetConversionResult()/1023.0)) / .00132 - 40.0 + Temp_ADC_Offset;
            break;
            
        // Default case, there was an error
        default:
            ADC_ERROR_PIN = HIGH;
            break;
        
    }
    
}

// Acquisition callback
void acquisitionTimerCallback(void) {
    
    // Measure VSS with ADC
    ADCC_StartConversion(channel_VSS);
    
    // Wait for previous conversion to finish
    while(!ADCC_IsConversionDone());    
    
    
    // Measure FVR buffer 1 with ADC
    ADCC_StartConversion(channel_FVR_buf1);
    
    // Wait for previous conversion to finish
    while(!ADCC_IsConversionDone());
    
    // Measure POS3P3 With ADC
    ADCC_StartConversion(POS3P3_ADC);
    
    // Wait for previous conversion to finish
    while(!ADCC_IsConversionDone());
    
    // Measure Current Sensor With ADC
    ADCC_StartConversion(ISNS_ADC);
    
    // Wait for previous conversion to finish
    while(!ADCC_IsConversionDone());
    
    // Measure POS12 with ADC
    ADCC_StartConversion(POS12_ADC);
    
    // Wait for previous conversion to finish
    while(!ADCC_IsConversionDone());
    
    // Measure temperature with ADC
    ADCC_StartConversion(channel_Temp);
    
    // Wait for previous conversion to finish
    while(!ADCC_IsConversionDone());
    
    
}




/*>>>>>>>>>>>>>>>>>>>>>>>>> Main Application <<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

void main(void)
{
    
    // Wait a bit before booting to let the reset LED shine a little longer
    // This is helpful for visualizing quick resets
    __delay_ms(250);
    
    // Initialize the device
    SYSTEM_Initialize();
    
    // Force SSR off at startup
    SSR_FORCE_PIN = 0;
    SSR_DIM_PIN = 0;
    load_enable = 0;

    // Call heartbeat function upon timer 6 ISR
    TMR6_SetInterruptHandler(heartbeatTimerCallback);
    
    // Call ADC callback upon ADCC interrupt
    ADCC_SetADIInterruptHandler(ADC_postProcessingCallback);
    
    // Set acquisition callback to be called upon TMR7 Interrupt
    TMR7_SetInterruptHandler(acquisitionTimerCallback);
    
    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();

    
    // Clear terminal, reset cursor, reset text attributes
    terminal_clearTerminal();
    terminal_setCursorHome();
    terminal_textAttributesReset();
    
    // Main loop
    while (1)
    {
        
        // Check eusart ready flag
        if (eusart2RxStringReady) {
         
            terminal_ringBufferPull();
            
        }
        
    }
}
/**
 End of File
*/