/* 
 * File:   ring_buffer_interface.h
 * Author: Drew Maatman
 *
 * Created on January 17, 2018, 7:47 PM
 */

/* 
 * SUBSTANTIAL EDITING OF MCC GENERATED EUSART FILES IS REQUIRED
 * READ BELOW
 * 
 * Requires a "ring_buffer_LUT" file to act on strings received
 * 
 */

#ifndef RING_BUFFER_INTERFACE_H
#define	RING_BUFFER_INTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <xc.h>
    
#include "ring_buffer_LUT.h"

#ifndef EUSART_2_RX_BUFFER_SIZE

    // Default line buffer size is 64 chars, this can be changed, but should
    // match whatever the MCC generated receive ring buffer size is
    #define EUSART_2_RX_BUFFER_SIZE 64

#endif

// Buffer ready to dump flag
extern volatile bit eusart2RxStringReady;

// Number of bytes received
extern volatile uint8_t eusart2RxCount;

// Receive head and tail
extern volatile uint8_t eusart2RxHead;
extern volatile uint8_t eusart2RxTail;


// Received String from EUSART rx ring buffer, this is what we actually compare
// against command strings
char line[EUSART_2_RX_BUFFER_SIZE];


// Enumeration holding attributes data for setting text fanciness
typedef enum {
    
    NORMAL,
    BOLD,
    UNDERSCORE,
    BLINK,
    REVERSE,
    CONCEALED
            
} text_attribute_t;

// Enumeration for setting text color attributes
typedef enum {
    
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
            
} text_color_t;


/*
  @Summary
    Pulls strings off of the ring buffer once a newline or return character has 
    been received, and acts on it

  @Description
    This routine pulls characters off the ring buffer and gets rid of leading
    or trailing newlines/returns characters, and also sets up the rx ring
    buffer to receive a new string, leaving old data

  @Preconditions
    Having an MCC generated UART driver, and adding the stuff listed below
    Some variables in this file should be edited to use correct EUSART module
    if there are multiple modules within the microcontroller being used
  
    A "ring_buffer_LUT" header/source file is also required to be able to parse
    the received strings and act on them. A function from that is called here

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example

*/
void terminal_ringBufferPull(void);

/*
  @Summary
    This routine is called on device reset (not automatically) and just prints
    stuff to the terminal

  @Description
    

  @Preconditions
    Having an MCC generated UART driver, and adding the stuff listed below
    Some variables in this file should be edited to use correct EUSART module
    if there are multiple modules within the microcontroller being used
  
    A "ring_buffer_LUT" header/source file is also required to be able to parse
    the received strings and act on them. A function from that is called here

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example

*/
void terminal_printResetMessage(void);
    


// Terminal manipulation functions
void terminal_clearTerminal(void);  // clears the whole terminal
void terminal_setCursorHome(void);  // Sets cursor to home position
void terminal_clearLine(void);      // clears the current line where the cursor appears
void terminal_saveCursor(void);     // Saves the current position of the cursor
void terminal_returnCursor(void);   // Returns the cursor to saved position

// Text attributes function
void terminal_textAttributes(text_color_t foreground_color,
        text_color_t background_color,
        text_attribute_t input_attribute);

// Reset to white foreground, black background, no fancy stuff
void terminal_textAttributesReset(void);

// Misc functions
void terminal_printNewline(void);



#ifdef	__cplusplus
}
#endif

#endif	/* RING_BUFFER_INTERFACE_H */



/* VERY IMPORTANT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * ADD THE FOLLOWING INTO THE EUSART_RECEIVE_ISR ROUTINE:
 * 
 * // This next chunk is not generated by MCC, and must remain here
    // It tells main() or whatever is pulling from the ring buffer that
    // data is ready to be read, since the terminal sent a newline or 
    // carriage return
    if((RC1REG == (int) '\n') || (RC1REG == (int) '\r')) {
        
        eusart1RxStringReady = 1;
        
        // Clear the stuff leftover in receive register, probably not needed
        RC1REG = 0;
        
    }
    
    else {
        
        eusart1RxStringReady = 0;
        
    }
   
    // If we've received a backspace
    if((RC1REG == (int) '\b')) {
     
        eusart1RxBuffer[eusart1RxHead] = '\0';
        eusart1RxHead--;
 
        // Erase the "backspaced" character
        printf("\033[K");
        
        if(eusart1RxHead != eusartR1xTail) {
        
            eusart1RxBuffer[eusart1RxHead] = '\0';
            eusart1RxHead--;

        }
        
        RC1REG = 0;
        
    }
  
 
 * ALSO ADD THIS AFTER THE INSTANTIATIONS OF THE RECEIVE RING BUFFER VARIABLES:
    
   volatile bit eusart1RxStringReady = 0;
  
 * THIS FLAG TELLS MAIN TO RUN THE ABOVE FUNCTION, ringBufferPull, and is set
 * when the user types "return" in terminal
 * 
 */ 