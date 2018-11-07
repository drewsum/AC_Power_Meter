    


#include "ring_buffer_interface.h"

// Text attribute enums
text_attribute_t attribute;
text_color_t foreground_color;
text_color_t background_color;


void terminal_ringBufferPull(void) {

    int charNumber = eusart2RxCount;
            
    // Clear line buffer
    for (int index = 0; index < EUSART_2_RX_BUFFER_SIZE; index++) {

        line[index] = '\0';

    }

    // Fill line from ring buffer
    for(int index = 0; index < charNumber; index++){

        line[index] = EUSART2_Read();

    }

    // Reset ring buffer
    eusart2RxTail = eusart2RxHead;

    // Try to kill off ending returns/newlines
    while((line[strlen(line) - 1] == (int) '\n') ||
          (line[strlen(line) - 1] == (int) '\r')) {
     
        // NULL
        line[strlen(line) - 1] = '\0';
        
    }
    

    // Clear ready flag
    eusart2RxStringReady = 0;

    // Check to see if line matches a command
    ringBufferLUT(line);

    
}

// This message is printed to the terminal on reset of microcontroller
// Can be left blank
void terminal_printResetMessage(void) {
 

        // Clear the screen
        printf("\033[2J");

        // Move cursor to home
        printf("\033[H");

        // Tell terminal we're up and running
        printf("    Boot complete\n\r"
                "    PIC18F67K40 mTouch Test Board\n\r"
                "    Evaluates the mTouch capacitive touch library distributed by Microchip\n\r"
                "    Sets the state of five LEDs based on mTouch capacitive pushbuttons\n\r"
                "    Baud rate: 115200 bps\n\r"
                "    No parity, 8 bits, no flow control, 1 stop bit\n\r"
                "    Commands are case sensitive\n\r"
                "    Enter a command, or enter Help for list of commands\n\r");


        // Get some space on terminal
        printf("\n\r");
        
}

// This function clears the terminal
void terminal_clearTerminal(void) {
    printf("\033[2J");
}

// This function moves the terminal cursor to top left corner
void terminal_setCursorHome(void) {
    printf("\033[H");
}

// This function clears the line the cursor is currently at on the terminal
void terminal_clearLine(void) {
    printf("\033[K");
}

// This function saves the current cursor position on the terminal
void terminal_saveCursor(void) {
    printf("\033[s");
}

// This function returns the cursor to saved position on terminal
void terminal_returnCursor(void) {
    printf("\033[u");
}

// Text attributes function
// See attributes enums in "ring_buffer_interface.h"
// Call like so:
/*

    terminal_textAttributes(<TEXT COLOR (ALL CAPS)>, 
                            <BACKGROUND COLOR (ALL CAPS)>, 
                            <TEXT EFFECT (ALL CAPS)>);

*/

void terminal_textAttributes(text_color_t foreground_color,
        text_color_t background_color,
        text_attribute_t input_attribute) {
    
    char output_buff[15];
    
    strncpy(output_buff, "\033[", sizeof(output_buff));
    
    switch (input_attribute) {
     
        case NORMAL:
            strcat(output_buff,"0"); 
            break;
        case BOLD:
            strcat(output_buff,"1");
            break;
        case UNDERSCORE:
            strcat(output_buff,"4");
            break;
        case BLINK:
            strcat(output_buff,"5");
            break;
        case REVERSE:
            strcat(output_buff,"7");
            break;
        case CONCEALED:
            strcat(output_buff,"8");
            break;

        default:
            strcat(output_buff,"0");
            break;
    }
    
    strcat(output_buff,";");
    
    switch (foreground_color) {
     
        case BLACK:
            strcat(output_buff,"30");
            break;
        case RED:
            strcat(output_buff,"31");
            break;
        case GREEN:
            strcat(output_buff,"32");
            break;
        case YELLOW:
            strcat(output_buff,"33");
            break;
        case BLUE:
            strcat(output_buff,"34");
            break;
        case MAGENTA:
            strcat(output_buff,"35");
            break;
        case CYAN:
            strcat(output_buff,"36");
            break;
        case WHITE:
            strcat(output_buff,"37");
            break;
            
        default:
            strcat(output_buff,"37");
            break;
    }
    
    strcat(output_buff,";");
    
    switch (background_color) {
     
        case BLACK:
            strcat(output_buff,"40");
            break;
        case RED:
            strcat(output_buff,"41");
            break;
        case GREEN:
            strcat(output_buff,"42");
            break;
        case YELLOW:
            strcat(output_buff,"43");
            break;
        case BLUE:
            strcat(output_buff,"44");
            break;
        case MAGENTA:
            strcat(output_buff,"45");
            break;
        case CYAN:
            strcat(output_buff,"46");
            break;
        case WHITE:
            strcat(output_buff,"47");
            break;
            
        default:
            strcat(output_buff,"47");
            break;
    }
    
    strcat(output_buff,"m");
    
    printf(output_buff);
}

// Reset text attributes to white text, black background, no effects
void terminal_textAttributesReset(void) {
 
    terminal_textAttributes(WHITE, BLACK, NORMAL);
    
}

// Print newline on terminal
void terminal_printNewline(void) {

    printf("\n\r");
    
}

