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
#ifndef ERROR_HANDLING_H
#define	ERROR_HANDLING_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include "mcc_generated_files/mcc.h"

#include "pin_macros.h"

// Error handling structure
struct error_struct {
    
    bool ISNS_ADC_error_flag;
    bool POS12_ADC_error_flag;
    bool POS3P3_ADC_error_flag;
    bool AVSS_ADC_error_flag;
    bool Temp_ADC_error_flag;
    bool FVR_ADC_error_flag;
    bool ADC_general_error_flag;
    bool I2C_COMM_error_flag;
    bool USB_UART_COMM_error_flag;
    
} error_handler;

// This function checks for ADC errors
bool getADCError(void);

// This function checks for COMM errors
bool getCOMMError(void);

// This function updates the error LEDs based on error handler state
void updateErrorLEDs(void);

// This function clears all ADC errors
void clearADCErrors(void);

// This function clears all COMM errors
void clearCOMMErrors(void);

#endif	/* ERROR_HANDLING_H */

