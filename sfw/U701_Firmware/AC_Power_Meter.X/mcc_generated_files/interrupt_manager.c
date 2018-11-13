/**
  Generated Interrupt Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt_manager.h

  @Summary:
    This is the Interrupt Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for global interrupt handling.
    For individual peripheral handlers please see the peripheral driver for
    all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18LF67K40
        Driver Version    :  2.12
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45 or later
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

#include "interrupt_manager.h"
#include "mcc.h"

void  INTERRUPT_Initialize (void)
{
    // Enable Interrupt Priority Vectors
    INTCONbits.IPEN = 1;

    // Assign peripheral interrupt priority vectors

    // BCLI - high priority
    IPR3bits.BCL1IP = 1;

    // SSPI - high priority
    IPR3bits.SSP1IP = 1;

    // TMRI - high priority
    IPR5bits.TMR4IP = 1;

    // HLVDI - high priority
    IPR2bits.HLVDIP = 1;

    // INT0I - high priority
    IPR0bits.INT0IP = 1;

    // RCI - high priority
    IPR3bits.RC2IP = 1;

    // TMRI - high priority
    IPR5bits.TMR5IP = 1;

    // ADTI - high priority
    IPR1bits.ADTIP = 1;


    // TMRI - low priority
    IPR5bits.TMR6IP = 0;    

    // TXI - low priority
    IPR3bits.TX2IP = 0;    

    // TMRI - low priority
    IPR5bits.TMR7IP = 0;    

}

void __interrupt() INTERRUPT_InterruptManagerHigh (void)
{
   // interrupt handler
    if(PIE3bits.BCL1IE == 1 && PIR3bits.BCL1IF == 1)
    {
        I2C1_BusCollisionISR();
    }
    else if(PIE3bits.SSP1IE == 1 && PIR3bits.SSP1IF == 1)
    {
        I2C1_ISR();
    }
    else if(PIE5bits.TMR4IE == 1 && PIR5bits.TMR4IF == 1)
    {
        TMR4_ISR();
    }
    else if(PIE2bits.HLVDIE == 1 && PIR2bits.HLVDIF == 1)
    {
        HLVD_ISR();
    }
    else if(PIE0bits.INT0IE == 1 && PIR0bits.INT0IF == 1)
    {
        INT0_ISR();
    }
    else if(PIE3bits.RC2IE == 1 && PIR3bits.RC2IF == 1)
    {
        EUSART2_RxDefaultInterruptHandler();
    }
    else if(PIE5bits.TMR5IE == 1 && PIR5bits.TMR5IF == 1)
    {
        TMR5_ISR();
    }
    else if(PIE1bits.ADTIE == 1 && PIR1bits.ADTIF == 1)
    {
        ADCC_ThresholdISR();
    }
    else
    {
        //Unhandled Interrupt
    }
}

void __interrupt(low_priority) INTERRUPT_InterruptManagerLow (void)
{
    // interrupt handler
    if(PIE5bits.TMR6IE == 1 && PIR5bits.TMR6IF == 1)
    {
        TMR6_ISR();
    }
    else if(PIE3bits.TX2IE == 1 && PIR3bits.TX2IF == 1)
    {
        EUSART2_TxDefaultInterruptHandler();
    }
    else if(PIE5bits.TMR7IE == 1 && PIR5bits.TMR7IF == 1)
    {
        TMR7_ISR();
    }
    else
    {
        //Unhandled Interrupt
    }
}
/**
 End of File
*/
