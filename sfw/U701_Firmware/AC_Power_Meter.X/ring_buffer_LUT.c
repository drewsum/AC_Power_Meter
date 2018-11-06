
#include <xc.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "ring_buffer_LUT.h"
#include "pin_macros.h"
#include "mcc_generated_files/memory.h"
#include "mcc_generated_files/adcc.h"
#include "device_IDs.h"
#include "cause_of_reset.h"

#ifndef M_PI
    #define M_PI acos(-1.0)
#endif

// Text attribute enums
extern text_attribute_t attribute;
extern text_color_t foreground_color;
extern text_color_t background_color;

// Printable/changeable variables
extern volatile double POS3P3_ADC_Result;
extern volatile double POS12_ADC_Result;
extern volatile double Temp_ADC_Result;
extern volatile double FVR_ADC_Result;
extern volatile double AVSS_ADC_Result;
extern volatile unsigned long dev_on_time;
extern volatile unsigned long load_on_time;
extern volatile double Imeas;
extern volatile double Irms;
extern volatile double Vrms;
extern volatile double Avg_Power;
extern volatile double TRIAC_Firing_Angle;
extern unsigned int dimming_period;
extern volatile bit load_enable;
extern volatile bit adc_error_flag;
extern volatile bit VCC_overvoltage_flag;
adcc_channel_t current_adc_channel;
extern reset_t reset_cause;

void ringBufferLUT(char * line) {

// THIS IS WHERE WE DO THE ACTUAL PARSING OF RECEIVED STRING AND
// ACT ON IT

    // Clear Screen, reset
    if((0 == strcmp(line, "Reset"))) {

        // Clear the screen
        printf("\033[2J");

        // Move cursor to home
        printf("\033[H");

        // Reset
        RESET();

    }

    // Clear screen, don't reset
    else if((0 == strcmp(line, "Clear"))) {

        // Clear the screen
        printf("\033[2J");

        // Move cursor to home
        printf("\033[H");

    }
    
    // print Device ID
    else if((0 == strcmp(line, "Cause of Reset?"))) {

        terminal_textAttributes(GREEN, BLACK, NORMAL);
        
        // Determine cause of reset and print
        printf("The cause of the most recent device reset was: %s\n\r",
                getCauseOfResetString(reset_cause));
       
        terminal_textAttributesReset();

    }

    // Identification string
    else if((0 == strcmp(line, "*IDN?")) || (0 == strcmp(line, "IDN"))) {

        terminal_textAttributes(GREEN, BLACK, NORMAL);
        printf("AC Power Meter\n\r");
        printf("Marquette University ELEN 3035 Final Project\n\r");
        terminal_textAttributesReset();

    }
    
    // print Device ID
    else if((0 == strcmp(line, "Device ID?"))) {

        terminal_textAttributes(GREEN, BLACK, NORMAL);
        
        // Grab and print device ID from flash
        printf("Device ID stored in Flash is: 0x%X. This corresponds to a device "
                "part number of %s\n\r",
                getDeviceID(),
                getDeviceIDString(getDeviceID()));

        terminal_textAttributesReset();

    }
    
    // print Revision ID
    else if((0 == strcmp(line, "Revision ID?"))) {

        terminal_textAttributes(GREEN, BLACK, NORMAL);
        
        // Grab and print revision ID from flash
        printf("Device silicon revision ID as stored in Flash is: %c%d\n\r",
                ((char) getMajorRevisionID() + 65),getMinorRevisionID());

        terminal_textAttributesReset();

    }
    
    // print User IDs
    else if((0 == strcmp(line, "User IDs?"))) {

        terminal_textAttributes(GREEN, BLACK, NORMAL);
        
        printf("The following User IDs have been retrieved from flash memory:\n\r");

        // Loop through all 8 user ID locations in flash
        for (int userID = 0; userID <= 7; userID++) {
         
            printf("    User ID Word %d (Flash address 0x20000%X): 0x%X\n\r",
                    userID,
                    (2 * userID),
                    getUserID(userID));
            
        }

        terminal_textAttributesReset();

    }
    
    // Report POS3P3 ADC Conversion Result
    else if((0 == strcmp(line, "ADC Error?"))) {
     
        if (adc_error_flag) {

            terminal_textAttributes(RED, BLACK, NORMAL);
            
            // Get the current ADC channel enumeration from the ADPCH register
            current_adc_channel = ADPCH;
            
            // buffer string for holding the ADC error channel
            char channel_name[22];
            
            switch (current_adc_channel) {
             
                case ISNS_ADC:
                    strcpy(channel_name, "ISNS");
                    break;
                    
                case POS12_ADC:
                    strcpy(channel_name, "POS12");
                    break;
                    
                case POS3P3_ADC:
                    strcpy(channel_name, "POS3P3");
                    break;
                    
                case channel_VSS:
                    strcpy(channel_name, "Internal AVSS");
                    break;
                    
                case channel_Temp:
                    strcpy(channel_name, "Internal Temp");
                    break;
                    
                case channel_DAC1:
                    strcpy(channel_name, "Internal DAC1");
                    break;
                    
                case channel_FVR_buf1:
                    strcpy(channel_name, "Internal FVR Buffer 1");
                    break;
                    
                default:
                    strcpy(channel_name, "Undefined");
                    break;
                
            }
            
            
            printf("The following channel caused an ADC error: %s\n\r", channel_name);
            terminal_textAttributesReset();
        
        }
        
        else {
         
            terminal_textAttributes(GREEN, BLACK, NORMAL);
            printf("No ADC Error detected\n\r");
            terminal_textAttributesReset();
        
        }
        
    }
    
    // Clear ADC error
    else if((0 == strcmp(line, "Clear ADC Error"))) {
     
        ADC_ERROR_PIN = LOW;
        adc_error_flag = 0;
        // Enable acquisition timer interrupt (TMR7)
        PIE5bits.TMR7IE == 1;
        TMR7_StartTimer();
        
        terminal_textAttributes(GREEN, BLACK, NORMAL);
        printf("Clearing ADC Error\n\r");
        terminal_textAttributesReset();
        
    }
    
    // Clear ADC error
    else if((0 == strcmp(line, "VCC Overvoltage?"))) {
        
        // If we've seen a VCC overvoltage event
        if (VCC_overvoltage_flag == 1) {
        
            terminal_textAttributes(RED, BLACK, NORMAL);
            printf("VCC Overvoltage condition has occurred (VCC has exceeded 3.60V)\n\r");
            terminal_textAttributesReset();
            
            // clear overvoltage flag
            VCC_overvoltage_flag = 0;
            
        }
        
        else {
         
            terminal_textAttributes(GREEN, BLACK, NORMAL);
            printf("VCC Overvoltage condition has not occurred\n\r");
            terminal_textAttributesReset();
            
        }
        
    }
    
    // Report POS3P3 ADC Conversion Result
    else if((0 == strcmp(line, "Measure POS3P3?"))) {

        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("+3.3V rail measured as +%.3f Volts\n\r", POS3P3_ADC_Result);
        terminal_textAttributesReset();
        
    }
    
    // Report POS12 ADC Conversion Result
    else if((0 == strcmp(line, "Measure POS12?"))) {
     
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("+12V rail measured as +%.3f Volts\n\r", POS12_ADC_Result);
        terminal_textAttributesReset();
        
    }
    
    // Report Die temp ADC Conversion Result
    else if((0 == strcmp(line, "Measure Die Temp?"))) {
     
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Die Temperature measured as %fC\n\r", Temp_ADC_Result);
        terminal_textAttributesReset();

        
        
    }
    
    // Report FVR buffer 1 ADC Conversion Result
    else if((0 == strcmp(line, "Measure FVR?"))) {
     
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Fixed Voltage Reference Buffer 1 measured as %f Volts\n\r", FVR_ADC_Result);
        terminal_textAttributesReset();
        
    }
    
    // Report VSS ADC Conversion Result
    else if((0 == strcmp(line, "Measure AVSS?"))) {
     
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("AVSS measured as %.3f Volts by ADC\n\r", AVSS_ADC_Result);
        terminal_textAttributesReset();
        
    }
    
    // Report measured current
    else if ((0 == strcmp(line, "Measure Detected Current?"))) {

        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Measured Current is %.3f Amps\n\r", Imeas);
        terminal_textAttributesReset();
        
    }
    
    // Report RMS output current
    else if ((0 == strcmp(line, "Measure RMS Current?"))) {
     
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("RMS Output Current is %.3f Arms\n\r", Irms);
        terminal_textAttributesReset();
        
    }
    
    // Report RMS output voltage
    else if ((0 == strcmp(line, "Measure RMS Voltage?"))) {
     
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("RMS Output Voltage is %.3f Vrms\n\r", Vrms);
        terminal_textAttributesReset();
        
    }
    
    // Report output power
    else if ((0 == strcmp(line, "Measure Power?"))) {
     
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Output power calculated as %.3f Watts from RMS values\n\r", Avg_Power);
        terminal_textAttributesReset();
        
    }
    
    // Enable triac dimming
    else if ((0 == strcmp(line, "Enable Dimming"))) {
     
        // Disable forcing of TRIAC conduction
        SSR_FORCE_PIN = 0;
        
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("TRIAC output dimming has been enabled\n\r");
        terminal_textAttributesReset();
        
    }
    
    // Disable triac dimming
    else if ((0 == strcmp(line, "Disable Dimming"))) {
     
        // Force TRIAC conduction
        SSR_FORCE_PIN = 1;

        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("TRIAC output dimming has been disabled\n\r");
        terminal_textAttributesReset();
        
    }
    
    // Enable load
    else if ((0 == strcmp(line, "Enable Load"))) {
     
        SSR_FORCE_PIN = 1;
        SSR_DIM_PIN = 0;
        load_enable = 1;
        
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Load has been enabled, dimming disabled\n\r");
        terminal_textAttributesReset();
        
    }
    
    // disable load
    else if ((0 == strcmp(line, "Disable Load"))) {
     
        SSR_DIM_PIN = 0;
        SSR_FORCE_PIN = 0;
        load_enable = 0;
        
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Load has been disabled\n\r");
        terminal_textAttributesReset();
        
    }
    
    // Set dimming percentage
    else if ((strstr(line, "Set Dimming Percentage: "))) {
     
        // argument buffer holds characters that make up argument
        char arg_buff[3];
        
        // Parse the argument
        for (int index = 0; index < 3; index++) {
         
            arg_buff[index] = line[index + 24];
            
        }
        
        int percentage = atoi(arg_buff);
                
        // If the user has entered bad data
        if (    (percentage >= 100) || 
                (percentage <= 0)) {
            
            terminal_textAttributes(RED, BLACK, NORMAL);
            printf("ERROR: Please set dimming percentage to an integer greater than 0 and less than 100\n\r");
            terminal_textAttributes(YELLOW, BLACK, NORMAL);
            printf("If you'd like to completely enable or disable the load, disable dimming and use respective commands\n\r");
            printf("Enter 'Help' for list of available commands\n\r");
            terminal_textAttributesReset();
        
        }
        
        // If data checks out
        else {
            
            // Calculate TRIAC firing angle
            TRIAC_Firing_Angle = ((100.0 - (double) percentage) / 100.0) * M_PI;
            double angle_degrees = TRIAC_Firing_Angle * (180.0 / M_PI);
            dimming_period = (100 - percentage) * (0xFFFF / 100);
            
            terminal_textAttributes(GREEN, BLACK, NORMAL);
            printf("Dimming has been set to %d percent\n\r", percentage);
            printf("Calculated TRIAC firing angle is %.3f radians (%.3f degrees)\n\r", TRIAC_Firing_Angle, angle_degrees);
            printf("This corresponds to a 16 bit timer pre-load value of 0x%X (%u LSBs) \n\r", dimming_period, dimming_period);
            terminal_textAttributesReset();
            
        }
        
    }
    
    // Report microcontroller on time since last reset
    else if((0 == strcmp(line, "Device On Time?"))) {
     
        terminal_textAttributes(GREEN, BLACK, NORMAL);
        printf("Device on time since last reset condition is %d seconds\n\r", dev_on_time);
        terminal_textAttributesReset();
         
    }
    
    // Report load on time since last reset
    else if((0 == strcmp(line, "Load On Time?"))) {
     
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Load on time since last device reset is %d seconds\n\r", load_on_time);
        terminal_textAttributesReset();
         
    }
    
    

    // help, print options
    else if((0 == strcmp(line, "Help"))) {

        terminal_textAttributes(YELLOW, BLACK, NORMAL);
        printf("List of supported commands:\n\r"
                
                "Device Commands:\n\r"
                "   Reset: Clears the terminal and resets the micro\n\r"
                "   Clear: Clears the terminal but doesn't reset the micro\n\r"
                "   Cause of Reset?: Returns the cause of the most recent device reset\n\r"
                "   *IDN?: Returns device identification string\n\r"
                "   Device On Time?: Returns device on time since last device reset\n\r"
                "   Device ID?: Returns device ID as pre-programmed in flash memory\n\r"
                "   Revision ID?: Returns device silicon revision ID as pre-programmed in flash memory\n\r"
                "   User IDs?: Returns a list of user IDs (displayed in hex) as stored in flash memory\n\r"
                "   ADC Error?: Returns the cause of an ADC error if an error occurred\n\r"
                "   Clear ADC Error: Clears the ADC error and resumes ADC conversions\n\r"
                "   VCC Overvoltage?: States if a VCC overvoltage condition has occurred or not\n\r"
                "   Help: This message, lists supported commands\n\r"
                
                "Device Measurement Commands:\n\r"
                "   Measure POS3P3?: Returns +3.3V ADC Conversion in volts\n\r"
                "   Measure POS12?: Returns +12V ADC Conversion in volts\n\r"
                "   Measure Die Temp?: Returns the microcontroller die temperature in degrees C\n\r"
                "   Measure FVR?: Returns the internal fixed voltage reference buffer 1 output in volts\n\r"
                "   Measure AVSS?: Returns the measured value of Analog VSS in volts\n\r"
                
                "Primary Measurement Commands:\n\r"
                "   Measure Detected Current?: Returns measured output current in amps as seen by ADC\n\r"
                "   Measure RMS Current?: Returns the calculated RMS output current from measurements and TRIAC firing angle\n\r"
                "   Measure RMS Voltage?: Returns the calculated RMS output voltage from TRIAC firing angle\n\r"
                "   Measure Power?: Returns the calculated output power in Watts\n\r"
                "   Load On Time?: Returns load on time since last device reset in seconds\n\r"
                
                "Output Control Commands:\n\r"
                "   Enable Dimming: Enable TRIAC output dimming\n\r"
                "   Disable Dimming: Disable TRIAC output dimming\n\r"
                "   Enable Load: Enables the output TRIAC with dimming disabled\n\r"
                "   Disable Load: Disables the output TRIAC completely\n\r"
                "   Set Dimming Percentage: <x>: Sets the output dimming percentage as x percent\n\r"
                );
        
        // Get some space on terminal
        terminal_printNewline();
        printf("Help messages appear in yellow\n\r");
        
        terminal_textAttributes(GREEN, BLACK, NORMAL);
        printf("System parameters appear in green\n\r");
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Measurement responses appear in cyan\n\r");
        terminal_textAttributes(RED, BLACK, NORMAL);
        printf("Errors appear in red\n\r");
        terminal_textAttributesReset();
        printf("User input appears in white\n\r");
        
        // Get some space on terminal
        terminal_printNewline();

    }
    
}