/*
 * File:   error_handling.c
 * Author: Drew Maatman
 *
 * Created on November 13, 2018, 9:34 AM
 */

#include "error_handling.h"

// This function checks for ADC errors
bool getADCError(void) {
 
    // If an ADC error has been detected
    if (    error_handler.ADC_general_error_flag    ||
            error_handler.AVSS_ADC_error_flag       ||
            error_handler.FVR_ADC_error_flag        ||
            error_handler.ISNS_ADC_error_flag       ||
            error_handler.POS12_ADC_error_flag      ||
            error_handler.POS3P3_ADC_error_flag     ||
            error_handler.Temp_ADC_error_flag       ) {
     
        return true;
        
    }
    
    else {
     
        return false;
        
    }
    
}

// This function checks for COMM errors
bool getCOMMError(void) {

    // If a COMM error has been detected
    if (    error_handler.I2C_COMM_error_flag       ||
            error_handler.USB_UART_COMM_error_flag  ) {
     
        return true;
        
    }
    
    else {
     
        return false;
        
    }
    
}

// This function updates the error LEDs based on error handler state
void updateErrorLEDs(void) {
 
    // If an ADC error has been detected
    if (getADCError()) {
     
        ADC_ERROR_PIN = HIGH;
        
    }
    
    // If a COMM error has been detected
    if (getCOMMError()) {
     
        COMM_ERROR_PIN = HIGH;
        
    }
    
}

// This function clears all ADC errors
void clearADCErrors(void) {
    
    // Clear error flags in error handler structure
    error_handler.ISNS_ADC_error_flag         = false;
    error_handler.POS12_ADC_error_flag        = false;
    error_handler.POS3P3_ADC_error_flag       = false;
    error_handler.AVSS_ADC_error_flag         = false;
    error_handler.Temp_ADC_error_flag         = false;
    error_handler.FVR_ADC_error_flag          = false;
    error_handler.ADC_general_error_flag      = false;
    
    // Turn off error LED
    ADC_ERROR_PIN = LOW;
    
}

// This function clears all COMM errors
void clearCOMMErrors(void) {
    
    // Clear error flags in error handler structure
    error_handler.I2C_COMM_error_flag       = false;
    error_handler.USB_UART_COMM_error_flag  = false;
    
    // Clear comm error led
    COMM_ERROR_PIN = LOW;
    
}



