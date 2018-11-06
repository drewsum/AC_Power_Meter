/**
  TMR7 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr7.c

  @Summary
    This is the generated driver implementation file for the TMR7 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for TMR7.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18LF67K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "tmr7.h"

/**
  Section: Global Variables Definitions
*/
volatile uint16_t timer7ReloadVal;
void (*TMR7_InterruptHandler)(void);

/**
  Section: TMR7 APIs
*/

void TMR7_Initialize(void)
{
    //Set the Timer to the options selected in the GUI

    //T7GE disabled; T7GTM disabled; T7GPOL low; T7GGO done; T7GSPM disabled; 
    T7GCON = 0x00;

    //GSS T7G_pin; 
    T7GATE = 0x00;

    //CS HFINTOSC; 
    T7CLK = 0x03;

    //TMR7H 236; 
    TMR7H = 0xEC;

    //TMR7L 120; 
    TMR7L = 0x78;

    // Load the TMR value to reload variable
    timer7ReloadVal=(uint16_t)((TMR7H << 8) | TMR7L);

    // Clearing IF flag before enabling the interrupt.
    PIR5bits.TMR7IF = 0;

    // Enabling TMR7 interrupt.
    PIE5bits.TMR7IE = 1;

    // Set Default Interrupt Handler
    TMR7_SetInterruptHandler(TMR7_DefaultInterruptHandler);

    // CKPS 1:8; nT7SYNC synchronize; TMR7ON enabled; T7RD16 disabled; 
    T7CON = 0x31;
}

void TMR7_StartTimer(void)
{
    // Start the Timer by writing to TMRxON bit
    T7CONbits.TMR7ON = 1;
}

void TMR7_StopTimer(void)
{
    // Stop the Timer by writing to TMRxON bit
    T7CONbits.TMR7ON = 0;
}

uint16_t TMR7_ReadTimer(void)
{
    uint16_t readVal;
    uint8_t readValHigh;
    uint8_t readValLow;
    
    T7CONbits.T7RD16 = 1;
	
    readValLow = TMR7L;
    readValHigh = TMR7H;
    
    readVal = ((uint16_t)readValHigh << 8) | readValLow;

    return readVal;
}

void TMR7_WriteTimer(uint16_t timerVal)
{
    if (T7CONbits.nT7SYNC == 1)
    {
        // Stop the Timer by writing to TMRxON bit
        T7CONbits.TMR7ON = 0;

        // Write to the Timer7 register
        TMR7H = (timerVal >> 8);
        TMR7L = timerVal;

        // Start the Timer after writing to the register
        T7CONbits.TMR7ON =1;
    }
    else
    {
        // Write to the Timer7 register
        TMR7H = (timerVal >> 8);
        TMR7L = timerVal;
    }
}

void TMR7_Reload(void)
{
    TMR7_WriteTimer(timer7ReloadVal);
}

void TMR7_StartSinglePulseAcquisition(void)
{
    T7GCONbits.T7GGO = 1;
}

uint8_t TMR7_CheckGateValueStatus(void)
{
    return (T7GCONbits.T7GVAL);
}

void TMR7_ISR(void)
{

    // Clear the TMR7 interrupt flag
    PIR5bits.TMR7IF = 0;
    TMR7_WriteTimer(timer7ReloadVal);

    if(TMR7_InterruptHandler)
    {
        TMR7_InterruptHandler();
    }
}


void TMR7_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR7_InterruptHandler = InterruptHandler;
}

void TMR7_DefaultInterruptHandler(void){
    // add your TMR7 interrupt custom code
    // or set custom function using TMR7_SetInterruptHandler()
}

/**
  End of File
*/
