/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef CAUSE_OF_RESET_H
#define	CAUSE_OF_RESET_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// The type of reset, stored in an enumeration
extern enum reset_t{
    Power_On_Reset,
    Brown_Out_Reset,
    Master_Clear_Reset,
    Master_Clear_Sleep_Reset,
    Watch_Dog_Timer_Reset,
    Watch_Dog_Timer_Sleep_Reset,
    Windowed_Watch_Dog_Timer_Reset,
    Interrupt_Wake_Up_From_Sleep,
    RESET_Instruction_Executed,
    Stack_Overflow_Reset,
    Stack_Underflow_Reset,
    VREG_or_ULP_Ready_Fault_Reset
};

// This function returns a pointer to a string describing the cause of the most
// recent device reset
enum reset_t getCauseOfReset(void);

inline char * getCauseOfResetString(enum reset_t r);

#endif	/* CAUSE_OF_RESET_H */

