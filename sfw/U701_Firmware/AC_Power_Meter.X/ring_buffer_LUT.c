
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "ring_buffer_LUT.h"
#include "pin_macros.h"

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

    // Identification string
    else if((0 == strcmp(line, "*IDN?")) || (0 == strcmp(line, "IDN"))) {

               // Get some space on terminal
        terminal_printNewline();
        // Set to green text
        terminal_textAttributes(GREEN, BLACK, NORMAL);
        // Tell term who we are
        printf("AC Power Meter\n\r");
        printf("Marquette University ELEN 3035 Final Project\n\r");
        // Reset to white text
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();

    }
    
    // Report POS3P3 ADC Conversion Result
    else if((0 == strcmp(line, "Measure POS3P3?"))) {
     
        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("+3.3V rail measured as +%f Volts\n\r", POS3P3_ADC_Result);
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();
        
        
    }
    
    // Report POS12 ADC Conversion Result
    else if((0 == strcmp(line, "Measure POS12?"))) {
     
        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("+12V rail measured as +%f Volts\n\r", POS12_ADC_Result);
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();
        
        
    }
    
    // Report Die temp ADC Conversion Result
    else if((0 == strcmp(line, "Measure Die Temp?"))) {
     
        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Die Temperature measured as %fC\n\r", Temp_ADC_Result);
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();
        
        
    }
    
    // Report FVR buffer 1 ADC Conversion Result
    else if((0 == strcmp(line, "Measure FVR?"))) {
     
        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Fixed Voltage Reference Buffer 1 measured as %f Volts\n\r", FVR_ADC_Result);
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();
        
        
    }
    
    // Report VSS ADC Conversion Result
    else if((0 == strcmp(line, "Measure AVSS?"))) {
     
        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("AVSS measured as %.3f Volts by ADC\n\r", AVSS_ADC_Result);
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();
        
        
    }
    
    // Report measured current
    else if ((0 == strcmp(line, "Measure Detected Current?"))) {

        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Measured Current is %.3f Amps\n\r", Imeas);
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();
        
    }
    
    // Report RMS output current
    else if ((0 == strcmp(line, "Measure RMS Current?"))) {
     
        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("RMS Output Current is %.3f Arms\n\r", Irms);
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();
        
    }
    
    // Report RMS output voltage
    else if ((0 == strcmp(line, "Measure RMS Voltage?"))) {
     
        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("RMS Output Voltage is %.3f Vrms\n\r", Vrms);
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();
        
    }
    
    // Report output power
    else if ((0 == strcmp(line, "Measure Power?"))) {
     
        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Output power calculated as %.3f Watts from RMS values\n\r", Avg_Power);
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();
        
    }
    
    // Enable triac dimming
    else if ((0 == strcmp(line, "Enable Dimming"))) {
     
        // Disable forcing of TRIAC conduction
        SSR_FORCE_PIN = 0;
        
        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("TRIAC output dimming has been enabled\n\r");
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();
        
    }
    
    // Disable triac dimming
    else if ((0 == strcmp(line, "Disable Dimming"))) {
     
        // Force TRIAC conduction
        SSR_FORCE_PIN = 1;
        
        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("TRIAC output dimming has been disabled\n\r");
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();
        
    }
    
    // Enable load
    else if ((0 == strcmp(line, "Enable Load"))) {
     
        SSR_FORCE_PIN = 1;
        SSR_DIM_PIN = 0;
        load_enable = 1;
        
        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Load has been enabled, dimming disabled\n\r");
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();
        
    }
    
    // disable load
    else if ((0 == strcmp(line, "Disable Load"))) {
     
        SSR_DIM_PIN = 0;
        SSR_FORCE_PIN = 0;
        load_enable = 0;
        
        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Load has been disabled\n\r");
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();
        
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
            
            // Get some space on terminal
            terminal_printNewline();
            // set text color to red and print help message
            terminal_textAttributes(RED, BLACK, NORMAL);
            printf("ERROR: Please set dimming percentage to an integer greater than 0 and less than 100\n\r");
            // set text color to yellow and print help message
            terminal_textAttributes(YELLOW, BLACK, NORMAL);
            printf("If you'd like to completely enable or disable the load, disable dimming and use respective commands\n\r");
            printf("Enter 'Help' for list of available commands\n\r");
            // Reset to white foreground
            terminal_textAttributesReset();
            // Get some space on terminal
            terminal_printNewline();

        }
        
        // If data checks out
        else {
            
            // Calculate TRIAC firing angle
            TRIAC_Firing_Angle = ((100.0 - (double) percentage) / 100.0) * M_PI;
            double angle_degrees = TRIAC_Firing_Angle * (180.0 / M_PI);
            dimming_period = (100 - percentage) * (0xFFFF / 100);
            
            // Get some space on terminal
            terminal_printNewline();
            // set text color to yellow and print help message
            terminal_textAttributes(CYAN, BLACK, NORMAL);
            printf("Dimming has been set to %d percent\n\r", percentage);
            printf("Calculated TRIAC firing angle is %.3f radians (%.3f degrees)\n\r", TRIAC_Firing_Angle, angle_degrees);
            printf("This corresponds to a 16 bit timer pre-load value of 0x%X (%u LSBs) \n\r", dimming_period, dimming_period);
            // Reset to white foreground
            terminal_textAttributesReset();
            // Get some space on terminal
            terminal_printNewline();

        }
        
    }
    
    // Report microcontroller on time since last reset
    else if((0 == strcmp(line, "Device On Time?"))) {
     
        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Device on time since last reset condition is %d seconds\n\r", dev_on_time);
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();
         
    }
    
    // Report load on time since last reset
    else if((0 == strcmp(line, "Load On Time?"))) {
     
        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Load on time since last device reset is %d seconds\n\r", load_on_time);
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        terminal_printNewline();
         
    }
    
    

    // help, print options
    else if((0 == strcmp(line, "Help"))) {

        // Get some space on terminal
        terminal_printNewline();
        // set text color to yellow and print help message
        terminal_textAttributes(YELLOW, BLACK, NORMAL);
        printf("List of supported commands:\n\r\n\r"
                
                "Housekeeping Commands:\n\r"
                "   Reset: Clears the terminal and resets the micro\n\r"
                "   Clear: Clears the terminal but doesn't reset the micro\n\r"
                "   *IDN?: Returns device identification string\n\r"
                "   Device On Time?: Returns device on time since last device reset\n\r"
                "   Help: This message, lists supported commands\n\r\n\r"
                
                "Housekeeping Measurement Commands:\n\r"
                "   Measure POS3P3?: Returns +3.3V ADC Conversion in volts\n\r"
                "   Measure POS12?: Returns +12V ADC Conversion in volts\n\r"
                "   Measure Die Temp?: Returns the microcontroller die temperature in degrees C\n\r"
                "   Measure FVR?: Returns the internal fixed voltage reference buffer 1 output in volts\n\r"
                "   Measure AVSS?: Returns the measured value of Analog VSS in volts\n\r\n\r"
                
                "Primary Measurement Commands:\n\r"
                "   Measure Detected Current?: Returns measured output current in amps as seen by ADC\n\r"
                "   Measure RMS Current?: Returns the calculated RMS output current from measurements and TRIAC firing angle\n\r"
                "   Measure RMS Voltage?: Returns the calculated RMS output voltage from TRIAC firing angle\n\r"
                "   Measure Power?: Returns the calculated output power in Watts\n\r"
                "   Load On Time?: Returns load on time since last device reset in seconds\n\r\n\r"
                
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
        printf("IDN string appears in green\n\r");
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
