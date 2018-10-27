
#include <string.h>
#include <ctype.h>

#include "ring_buffer_LUT.h"


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

        // Tell term who we are
        printf("AC Power Meter");

        // Get some space on terminal
        printf("\n\r");

    }

    // help, print options
    else if((0 == strcmp(line, "Help"))) {

        // Get some space on terminal
        printf("\n\r");
        // Print help message
        printf("List of supported commands:\n\r"
                "   Reset: Clears the terminal and resets the micro\n\r"
                "   Clear: Clears the terminal but doesn't reset the micro\n\r"
                "   *IDN?: Returns device identification\n\r"
                "   Help: This message, lists commands\n\r");

        // Get some space on terminal
        printf("\n\r");

    }


    
}
