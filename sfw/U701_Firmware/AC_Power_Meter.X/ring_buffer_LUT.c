
#include <string.h>
#include <ctype.h>

#include "ring_buffer_LUT.h"

// Text attribute enums
extern text_attribute_t attribute;
extern text_color_t foreground_color;
extern text_color_t background_color;

// Printable variables
extern float POS3P3_ADC_Result;
extern float POS12_ADC_Result;

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
        printf("\n\r"); 
        // Set to green text
        terminal_textAttributes(GREEN, BLACK, NORMAL);
        // Tell term who we are
        printf("AC Power Meter\n\r");
        printf("Marquette University ELEN 3035 Final Project\n\r");
        // Reset to white text
        terminal_textAttributesReset();
        // Get some space on terminal
        printf("\n\r");

    }
    
    // Report POS3P3 ADC Conversion Result
    else if((0 == strcmp(line, "Measure POS3P3?"))) {
     
        // Get some space on terminal
        printf("\n\r");
        // set text color to yellow and print help message
        terminal_textAttributes(YELLOW, BLACK, NORMAL);
        printf("+3.3V rail measured as +%f Volts\n\r", POS3P3_ADC_Result);
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        printf("\n\r");
        
        
    }
    
    // Report POS12 ADC Conversion Result
    else if((0 == strcmp(line, "Measure POS12?"))) {
     
        // Get some space on terminal
        printf("\n\r");
        // set text color to yellow and print help message
        terminal_textAttributes(YELLOW, BLACK, NORMAL);
        printf("+12V rail measured as +%f Volts\n\r", POS12_ADC_Result);
        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        printf("\n\r");
        
        
    }

    // help, print options
    else if((0 == strcmp(line, "Help"))) {

        // Get some space on terminal
        printf("\n\r");
        // set text color to yellow and print help message
        terminal_textAttributes(YELLOW, BLACK, NORMAL);
        printf("List of supported commands:\n\r"
                "   Reset: Clears the terminal and resets the micro\n\r"
                "   Clear: Clears the terminal but doesn't reset the micro\n\r"
                "   *IDN?: Returns device identification\n\r"
                "   Measure POS3P3?: Returns +3.3V ADC Conversion in volts\n\r"
                "   Measure POS12?: Returns +12V ADC Conversion in volts\n\r"
                "   Help: This message, lists commands\n\r");

        // Reset to white foreground
        terminal_textAttributesReset();
        // Get some space on terminal
        printf("\n\r");

    }


    
}
