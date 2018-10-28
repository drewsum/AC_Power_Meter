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

// Includes
#include "mcc_generated_files/mcc.h"

#include <math.h>

#include "pin_macros.h"
#include "ring_buffer_interface.h"

// Global Variables

// ring buffer ready flag
volatile bit eusart2RxStringReady = 0;

// On time counter, increments with heartbeat
unsigned long on_time = 0;

// ADC Double Precision Post Processing Variables
double FVR_ADC_Result;
double ADC_Result_Scaling;
double POS3P3_ADC_Result;
double POS12_ADC_Result;
double Temp_ADC_Result;
double Temp_ADC_Offset = -267.409;

// Callback Functions

// This function is called upon TMR6 ISR and toggles the heartbeat LED, as well
// as resets the watchdog timer
void heartbeatTimerCallback(void) {
 
    // Toggle heartbeat pin
    HEARTBEAT_PIN = !HEARTBEAT_PIN;
    
    // increment ontime
    on_time++;
    
    // Kick the dog
    CLRWDT();
    
}

// Callback function for ADCC interrupts
void ADC_postProcessingCallback(void) {
 
    adcc_channel_t currentADCChannel = ADPCH;
    
    switch (currentADCChannel) {
        
        // FVR Buffer 1 ADC post processing
        case channel_FVR_buf1:
            FVR_ADC_Result = (ADCC_GetConversionResult()) * (3.3/1023.0);
            ADC_Result_Scaling = 2.048/FVR_ADC_Result;
            
            break;
        
        // POS3P3_ADC Post Processing
        case POS3P3_ADC:
            POS3P3_ADC_Result = (ADCC_GetConversionResult()) * (3.3/1023.0) * 2.0 * ADC_Result_Scaling;
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
    
    // Measure FVR buffer 1 with ADC
    ADCC_StartConversion(channel_FVR_buf1);
    
    // Wait for previous conversion to finish
    while(!ADCC_IsConversionDone());
    
    // Measure POS3P3 With ADC
    ADCC_StartConversion(POS3P3_ADC);
    
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



/*
                         Main application
 */
void main(void)
{
    
    // Wait a bit before booting to let the reset LED shine a little longer
    // This is helpful for visualizing quick resets
    __delay_ms(250);
    
    // Initialize the device
    SYSTEM_Initialize();

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