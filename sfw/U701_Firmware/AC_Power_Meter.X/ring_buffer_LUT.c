
#include <xc.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "error_handling.h"
#include "ring_buffer_LUT.h"
#include "pin_macros.h"
#include "mcc_generated_files/memory.h"
#include "mcc_generated_files/adcc.h"
#include "device_IDs.h"
#include "cause_of_reset.h"
#include "double_to_EEPROM.h"
#include "oled.h"

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
extern volatile double Total_Energy;
adcc_channel_t current_adc_channel;
extern reset_t reset_cause;

// Max Values saved in EEPROM:
extern volatile double max_Irms;
extern volatile double max_Power;
extern volatile double max_POS3P3_ADC_Result;
extern volatile double max_POS12_ADC_Result;
extern volatile double max_Temp_ADC_Result;
extern volatile double max_FVR_ADC_Result;

// EEPROM variable address
extern const uint16_t max_Irms_address                 = 0x0000;
extern const uint16_t max_Power_address                = 0x0004;
extern const uint16_t max_POS3P3_ADC_Result_address    = 0x0008;
extern const uint16_t max_POS12_ADC_Result_address     = 0x000C;
extern const uint16_t max_Temp_ADC_Result_address      = 0x0010;
extern const uint16_t max_FVR_ADC_Result_address       = 0x0014;
extern const uint16_t Total_Energy_address             = 0x0018;

extern volatile bit USB_live_update_flag;


extern void OLED_updateCallback(void);

void ringBufferLUT(char * line) {

// THIS IS WHERE WE DO THE ACTUAL PARSING OF RECEIVED STRING AND
// ACT ON IT

    // Clear Screen, reset
    if((0 == strcmp(line, "Reset"))) {

        
        // Save Total energy into EEPROM before we reset
        writeDoubleToEEPROM(Total_Energy, Total_Energy_address);
        
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
        printf("Device silicon revision ID as stored in Flash is: %c%03d\n\r",
                ((char) getMajorRevisionID() + 65),getMinorRevisionID());

        terminal_textAttributesReset();

    }
    
    // print User IDs
    else if((0 == strcmp(line, "User IDs?"))) {

        terminal_textAttributes(GREEN, BLACK, NORMAL);
        
        printf("The following User IDs have been retrieved from flash memory:\n\r");

        // Loop through all 8 user ID locations in flash
        for (int userID = 0; userID <= 7; userID++) {
         
            printf("    User ID Word %d (Flash address 0x20000%X): 0x%04X\n\r",
                    userID,
                    (2 * userID),
                    getUserID(userID));
            
        }

        terminal_textAttributesReset();

    }
    
    // Report POS3P3 ADC Conversion Result
    else if((0 == strcmp(line, "ADC Errors?"))) {
     
        if (getADCError()) {
            
            terminal_textAttributes(RED, BLACK, NORMAL);
            printf("ADC error(s) detected!\n\r");
            printf("The following channels caused an ADC error:\n\r");
            
            if (error_handler.ADC_general_error_flag) {
                printf("    General ADC error\n\r");
            }
            
            if (error_handler.AVSS_ADC_error_flag) {
                printf("    AVSS\n\r");
            }
            
            if (error_handler.FVR_ADC_error_flag) {
                printf("    FVR\n\r");
            }
            
            if (error_handler.ISNS_ADC_error_flag) {
                printf("    ISNS\n\r");
            }
            
            if (error_handler.POS12_ADC_error_flag) {
                printf("    POS12\n\r");
            }
            
            if (error_handler.POS3P3_ADC_error_flag) {
                printf("    POS3P3\n\r");
            }
            
            if (error_handler.Temp_ADC_error_flag) {
                printf("    Die Temp\n\r");
            }
            
            terminal_textAttributes(YELLOW, BLACK, NORMAL);
            printf("Call 'Clear ADC Errors' to clear ADC error(s)\n\r");
            terminal_textAttributesReset();
            
        }
        
        else {
         
            terminal_textAttributes(GREEN, BLACK, NORMAL);
            printf("No ADC error(s) detected\n\r");
            terminal_textAttributesReset();
        
        }
        
    }
    
    // Clear ADC error
    else if((0 == strcmp(line, "Clear ADC Errors"))) {
     
        clearADCErrors();
        
        terminal_textAttributes(GREEN, BLACK, NORMAL);
        printf("ADC Error(s) cleared\n\r");
        terminal_textAttributesReset();
        
    }
    
    // Report POS3P3 ADC Conversion Result
    else if((0 == strcmp(line, "Comm Errors?"))) {
       
        if (getCOMMError()) {
        
            terminal_textAttributes(RED, BLACK, NORMAL);
            printf("Communications error(s) detected! Interfaces causing error(s):\n\r");
            
            if (error_handler.I2C_COMM_error_flag) {
                printf("    OLED Display I2C\n\r");
            }
            
            if (error_handler.USB_UART_COMM_error_flag) {
                printf("    USB UART (this interface)\n\r");
            }
            
            terminal_textAttributes(YELLOW, BLACK, NORMAL);
            printf("Call 'Clear Comm Errors' to clear communications error(s)\n\r");
            terminal_textAttributesReset();
        
        }
        
        else {
            
            terminal_textAttributes(GREEN, BLACK, NORMAL);
            printf("No communications error(s) detected\n\r");
            terminal_textAttributesReset();
            
        }   
    }
    
        // Report POS3P3 ADC Conversion Result
    else if((0 == strcmp(line, "Clear Comm Errors"))) {
    
        clearCOMMErrors();
        
        terminal_textAttributes(GREEN, BLACK, NORMAL);
        printf("Communications error(s) cleared\n\r");
        terminal_textAttributesReset();
    
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
        printf("Die Temperature measured as %.3fC\n\r", Temp_ADC_Result);
        terminal_textAttributesReset();

        
        
    }
    
    // Report FVR buffer 1 ADC Conversion Result
    else if((0 == strcmp(line, "Measure FVR?"))) {
     
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Fixed Voltage Reference Buffer 1 measured as %.3f Volts\n\r", FVR_ADC_Result);
        terminal_textAttributesReset();
        
    }
    
    // Report VSS ADC Conversion Result
    else if((0 == strcmp(line, "Measure AVSS?"))) {
     
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("AVSS measured as %.3f Volts\n\r", AVSS_ADC_Result);
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
    
    // Report output energy
    else if ((0 == strcmp(line, "Measure Energy?"))) {
     
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        
        if (Total_Energy >= 1000.0) {
         
            printf("Measured output energy since last measurement reset is %.2e Watt Hours\n\r", Total_Energy);
            
        }
        
        else if (Total_Energy >= 100.0) {
         
            printf("Measured output energy since last measurement reset is %.2f Watt Hours\n\r", Total_Energy);
            
        }
        
        else {
         
            printf("Measured output energy since last measurement reset is %.3f Watt Hours\n\r", Total_Energy);
            
        }
        
        
        terminal_textAttributesReset();
        
    }
    
    // erase output energy
    else if ((0 == strcmp(line, "Clear Energy"))) {
     
        // Clear SRAM and EEPROM total energy values
        Total_Energy = 0.0;
        writeDoubleToEEPROM(0.0, Total_Energy_address);
        
        terminal_textAttributes(GREEN, BLACK, NORMAL);
        printf("Measured output energy has been reset to zero Watt Hours\n\r");
        terminal_textAttributesReset();
        
    }
    
    // Ask if the user is sure if they want to enable dimming
    else if ((0 == strcmp(line, "Enable Dimming"))) {
    
        // Ask if user is sure
        // Print a fancy warning message
        terminal_textAttributesReset();
        terminal_textAttributes(RED, BLACK, NORMAL);
        printf("WARNING: Using the dimming feature with load devices other than a light bulb can result in device damage");
        terminal_textAttributesReset();
        terminal_printNewline();
        terminal_textAttributes(RED, BLACK, NORMAL);
        printf("Only enable dimming if you are completely sure the load is compatible with a solid state dimming circuit");
        terminal_textAttributesReset();
        terminal_printNewline();
        terminal_textAttributes(BLACK, YELLOW, NORMAL);
        printf("Are you sure you'd like to enable output dimming?");
        terminal_textAttributesReset();
        terminal_printNewline();
        terminal_textAttributes(YELLOW, BLACK, NORMAL);
        printf("If yes, reply 'Enable Dimming Y' on the next line:\n\r");
        terminal_textAttributesReset();
        
    }
    
    // REALLY enable TRIAC dimming
    else if ((0 == strcmp(line, "Enable Dimming Y"))) {
     
        if (load_enable) {
            // Disable forcing of TRIAC conduction
            SSR_FORCE_PIN = 0;

            // Enable ZCD interrupt
            PIE0bits.INT0IE = 1;

            // Print to OLED
            OLED_Frame = Dimming_Enabled;
            OLED_updateCallback();

            terminal_textAttributes(GREEN, BLACK, NORMAL);
            printf("Output dimming has been enabled\n\r");
            terminal_textAttributesReset();
        }
        
        else {
         
            terminal_textAttributes(RED, BLACK, NORMAL);
            printf("Load is Disabled\n\r");
            terminal_textAttributes(YELLOW,BLACK,NORMAL);
            printf("Enabled the load by calling 'Enable Load'\n\r");
            terminal_textAttributesReset();
            
        }
            
    }
    
    // Disable triac dimming
    else if ((0 == strcmp(line, "Disable Dimming"))) {
     
        // Force TRIAC conduction
        SSR_FORCE_PIN = 1;
        
        // Disable ZCD interrupt
        PIE0bits.INT0IE = 0;
        TMR5_StopTimer();
        
        OLED_Frame = Dimming_Disabled;
        OLED_updateCallback();

        terminal_textAttributes(RED, BLACK, NORMAL);
        printf("TRIAC output dimming has been disabled\n\r");
        terminal_textAttributesReset();
        
    }
    
    // Enable load
    else if ((0 == strcmp(line, "Enable Load"))) {
     
        SSR_FORCE_PIN = 1;
        SSR_DIM_PIN = 0;
        load_enable = 1;
        
        OLED_Frame = Load_Enabled;
        OLED_updateCallback();
        
        terminal_textAttributes(GREEN, BLACK, NORMAL);
        printf("Load has been enabled, dimming disabled\n\r");
        terminal_textAttributesReset();
        
    }
    
    // check if load is enabled
    else if ((0 == strcmp(line, "Load Enabled?"))) {
     
        if  (load_enable == 1) {
         
            terminal_textAttributes(GREEN, BLACK, NORMAL);
            printf("Load is currently enabled\n\r");
            terminal_textAttributesReset();
   
        }
        
        else {
         
            terminal_textAttributes(RED, BLACK, NORMAL);
            printf("Load is currently disabled\n\r");
            terminal_textAttributesReset();

            
        }
        
    }
    
    // check if dimming is enabled
    else if ((0 == strcmp(line, "Dimming Enabled?"))) {
     
        if  (load_enable == 1 && SSR_FORCE_PIN != 1) {
         
            terminal_textAttributes(GREEN, BLACK, NORMAL);
            printf("Dimming is currently enabled\n\r");
            terminal_textAttributesReset();
   
        }
        
        else if (load_enable == 1){
         
            terminal_textAttributes(YELLOW, BLACK, NORMAL);
            printf("Load is currently enabled, but dimming is disabled\n\r");
            terminal_textAttributesReset();

        }
        
        else {
         
            terminal_textAttributes(RED, BLACK, NORMAL);
            printf("Load and dimming are currently disabled\n\r");
            terminal_textAttributesReset();
            
        }


        
    }
        
    // disable load
    else if ((0 == strcmp(line, "Disable Load"))) {
     
        // Shutoff dimming timer (TMR5)
        TMR5_StopTimer();

        // Disable timer 5 interrupt
        PIE5bits.TMR5IE = 0;
        
        // Disable dimming interrupt
        PIE0bits.INT0IE = 0;
        
        SSR_DIM_PIN = 0;
        SSR_FORCE_PIN = 0;
        load_enable = 0;
        
        terminal_textAttributes(RED, BLACK, NORMAL);
        printf("Load has been disabled\n\r");
        terminal_textAttributesReset();
        
        OLED_Frame = Load_Disabled;
        OLED_updateCallback();
        
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
            dimming_period = (percentage) * (0xFFFF / 100);
            
            terminal_textAttributes(GREEN, BLACK, NORMAL);
            printf("Dimming has been set to %d percent\n\r", percentage);
            printf("Calculated TRIAC firing angle is %.3f radians (%.3f degrees)\n\r", TRIAC_Firing_Angle, angle_degrees);
            printf("This corresponds to a 16 bit timer pre-load value of 0x%X (%u LSBs) \n\r", dimming_period, dimming_period);
            terminal_textAttributesReset();
            
            __delay_ms(100);
            
            OLED_Frame = Dimming_Percentage;
            OLED_updateCallback();
            
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
     
        terminal_textAttributes(GREEN, BLACK, NORMAL);
        printf("Load on time since last device reset is %d seconds\n\r", load_on_time);
        terminal_textAttributesReset();
         
    }

    // Report maximum recorded output current
    else if((0 == strcmp(line, "Max RMS Current?"))) {
     
        // Retrieve maximum current from EEPROM
        double max_current_print = readDoubleFromEEPROM(max_Irms_address);
        
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Maximum recorded RMS output current is %.3f Arms\n\r", max_current_print);
        terminal_textAttributesReset();
         
    }
    
    // Report maximum recorded output power
    else if((0 == strcmp(line, "Max Power?"))) {
     
        // Retrieve maximum current from EEPROM
        double max_Power_print = readDoubleFromEEPROM(max_Power_address);
        
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Maximum recorded output power is %.3f Watts\n\r", max_Power_print);
        terminal_textAttributesReset();
         
    }
    
    // Report maximum recorded POS3P3 Voltage
    else if((0 == strcmp(line, "Max POS3P3 Voltage?"))) {
     
        // Retrieve maximum current from EEPROM
        double max_voltage_print = readDoubleFromEEPROM(max_POS3P3_ADC_Result_address);
        
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Maximum recorded +3.3V rail voltage is %.3f Volts\n\r", max_voltage_print);
        terminal_textAttributesReset();
         
    }
    
    // Report maximum recorded POS12 Voltage
    else if((0 == strcmp(line, "Max POS12 Voltage?"))) {
     
        // Retrieve maximum current from EEPROM
        double max_voltage_print = readDoubleFromEEPROM(max_POS12_ADC_Result_address);
        
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Maximum recorded +12V rail voltage is %.3f Volts\n\r", max_voltage_print);
        terminal_textAttributesReset();
         
    }
    
    // Report maximum recorded die temp
    else if((0 == strcmp(line, "Max Die Temp?"))) {
     
        // Retrieve maximum current from EEPROM
        double max_temp_print = readDoubleFromEEPROM(max_Temp_ADC_Result_address);
        
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Maximum recorded die temperature is %.3f C\n\r", max_temp_print);
        terminal_textAttributesReset();
         
    }
    
    // Report maximum recorded FVR voltage
    else if((0 == strcmp(line, "Max FVR Voltage?"))) {
     
        // Retrieve maximum current from EEPROM
        double max_voltage_print = readDoubleFromEEPROM(max_FVR_ADC_Result_address);
        
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Maximum recorded FVR buffer 1 voltage is %.3f Volts\n\r", max_voltage_print);
        terminal_textAttributesReset();
         
    }
    
    // Report maximum recorded output power
    else if((0 == strcmp(line, "Clear Max Values"))) {
     
        // Clear max values in EEPROM
        writeDoubleToEEPROM(0.0, max_Irms_address);
        writeDoubleToEEPROM(0.0, max_Power_address);
        writeDoubleToEEPROM(0.0, max_POS3P3_ADC_Result_address);
        writeDoubleToEEPROM(0.0, max_POS12_ADC_Result_address);
        writeDoubleToEEPROM(0.0, max_Temp_ADC_Result_address);
        writeDoubleToEEPROM(0.0, max_FVR_ADC_Result_address);
        
        //  Clear max values in SRAM
        max_Irms = 0.0;
        max_Power = 0.0;
        max_POS3P3_ADC_Result = 0.0;
        max_POS12_ADC_Result = 0.0;
        max_Temp_ADC_Result = 0.0;
        max_FVR_ADC_Result = 0.0;
        
        terminal_textAttributes(GREEN, BLACK, NORMAL);
        printf("Maximum recorded values erased from SRAM and EEPROM\n\r");
        terminal_textAttributesReset();
         
    }
    
    // device summary command
    else if ((0 == strcmp(line, "Device Summary"))) {
        
        terminal_printNewline();
        
        // Determine if we need to make text red or green depending on
        // badness of cause of reset
        if (    reset_cause == Stack_Overflow_Reset ||
                reset_cause == Stack_Underflow_Reset ||
                reset_cause == Windowed_Watch_Dog_Timer_Reset ||
                reset_cause == Watch_Dog_Timer_Reset ||
                reset_cause == Brown_Out_Reset ||
                reset_cause == Watch_Dog_Timer_Reset ||
                reset_cause == Undefined_Reset
                ) {

            terminal_textAttributes(RED, BLACK, BOLD);

        }

        else {

            terminal_textAttributes(GREEN, BLACK, NORMAL);

        }

        // Print the cause of the reset
        printf("Cause of last reset: %s\n\r", getCauseOfResetString(reset_cause));
        terminal_printNewline();

        // print device ID from flash
        terminal_textAttributes(GREEN, BLACK, NORMAL);
        printf("Device ID stored in Flash is: 0x%X. This corresponds to a device "
                    "part number of %s\n\r",
                    getDeviceID(),
                    getDeviceIDString(getDeviceID()));

        // print revision ID from flash
        printf("Device silicon revision ID as stored in Flash is: %c%03d\n\r",
                    ((char) getMajorRevisionID() + 65),getMinorRevisionID());

        // print user IDs
        printf("The following User IDs have been retrieved from flash memory:\n\r");

        // Loop through all 8 user ID locations in flash and print
        for (int userID = 0; userID <= 7; userID++) {

            printf("    User ID Word %d (Flash address 0x20000%X): 0x%04X\n\r",
                    userID,
                    (2 * userID),
                    getUserID(userID));

        }

        terminal_printNewline();
        
        printf("Device on time since last reset condition is %d seconds\n\r", dev_on_time);
        
        terminal_printNewline();

        // print if there was an ADC error during startup
        if (getADCError()) {

                terminal_textAttributes(RED, BLACK, NORMAL);
                printf("ADC error(s) detected!\n\r");
                printf("The following channels caused an ADC error:\n\r");

                if (error_handler.ADC_general_error_flag) {
                    printf("    General ADC error\n\r");
                }

                if (error_handler.AVSS_ADC_error_flag) {
                    printf("    AVSS\n\r");
                }

                if (error_handler.FVR_ADC_error_flag) {
                    printf("    FVR\n\r");
                }

                if (error_handler.ISNS_ADC_error_flag) {
                    printf("    ISNS\n\r");
                }

                if (error_handler.POS12_ADC_error_flag) {
                    printf("    POS12\n\r");
                }

                if (error_handler.POS3P3_ADC_error_flag) {
                    printf("    POS3P3\n\r");
                }

                if (error_handler.Temp_ADC_error_flag) {
                    printf("    Die Temp\n\r");
                }

                terminal_textAttributes(YELLOW, BLACK, NORMAL);
                printf("Call 'Clear ADC Errors' to clear ADC error(s)\n\r");
                terminal_textAttributesReset();

            }

            else {

                terminal_textAttributes(GREEN, BLACK, NORMAL);
                printf("No ADC error(s) detected\n\r");
                terminal_textAttributesReset();

            }

        // Print if there was a comm error during startup
        if (getCOMMError()) {

                terminal_textAttributes(RED, BLACK, NORMAL);
                printf("Communications error(s) detected! Interfaces causing error(s):\n\r");

                if (error_handler.I2C_COMM_error_flag) {
                    printf("    OLED Display I2C\n\r");
                }

                if (error_handler.USB_UART_COMM_error_flag) {
                    printf("    USB UART (this interface)\n\r");
                }

                terminal_textAttributes(YELLOW, BLACK, NORMAL);
                printf("Call 'Clear Comm Errors' to clear communications error(s)\n\r");
                terminal_textAttributesReset();

            }

            else {

                terminal_textAttributes(GREEN, BLACK, NORMAL);
                printf("No communications error(s) detected\n\r");
                terminal_textAttributesReset();

            }

        // Print device measurements
        terminal_printNewline();
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("+3.3V rail measured as +%.3f Volts\n\r", POS3P3_ADC_Result);
        printf("+12V rail measured as +%.3f Volts\n\r", POS12_ADC_Result);
        printf("Die Temperature measured as %.3fC\n\r", Temp_ADC_Result);
        printf("Fixed Voltage Reference Buffer 1 measured as %.3f Volts\n\r", FVR_ADC_Result);
        printf("AVSS measured as %.3f Volts\n\r", AVSS_ADC_Result);

        terminal_printNewline();
        
        double max_POS3P3_print = readDoubleFromEEPROM(max_POS3P3_ADC_Result_address);
        printf("Maximum recorded +3.3V rail voltage is %.3f Volts\n\r", max_POS3P3_print);
        double max_POS12_print = readDoubleFromEEPROM(max_POS12_ADC_Result_address);
        printf("Maximum recorded +12V rail voltage is %.3f Volts\n\r", max_POS12_print);
        double max_temp_print = readDoubleFromEEPROM(max_Temp_ADC_Result_address);
        printf("Maximum recorded die temperature is %.3f C\n\r", max_temp_print);
        double max_FVR_print = readDoubleFromEEPROM(max_FVR_ADC_Result_address);
        printf("Maximum recorded FVR buffer 1 voltage is %.3f Volts\n\r", max_FVR_print);
        
        terminal_textAttributesReset();
        terminal_printNewline();
        
        
        

    
    }
    
    // measurements summary command
    else if ((0 == strcmp(line, "Measurement Summary"))) {
     
        terminal_printNewline();
        
        if  (load_enable == 1 && SSR_FORCE_PIN != 1) {
         
            terminal_textAttributes(GREEN, BLACK, NORMAL);
            printf("Dimming is currently enabled\n\r");
            
            // Calculate TRIAC firing angle
            double angle_degrees = TRIAC_Firing_Angle * (180.0 / M_PI);
            float percentage_print = round(((180.0 - angle_degrees) / 180.0) * 100.0);
            printf("Dimming has been set to %.2f percent\n\r", percentage_print);
            
            terminal_textAttributesReset();
   
        }
        
        else if (load_enable == 1){
         
            terminal_textAttributes(YELLOW, BLACK, NORMAL);
            printf("Load is currently enabled, but dimming is disabled\n\r");
            terminal_textAttributesReset();

        }
        
        else {
         
            terminal_textAttributes(RED, BLACK, NORMAL);
            printf("Load and dimming are currently disabled\n\r");
            terminal_textAttributesReset();
            
        }
        
        terminal_printNewline();
        
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Load on time since last device reset is %d seconds\n\r", load_on_time);
        printf("RMS Output Current is %.3f Arms\n\r", Irms);
        printf("RMS Output Voltage is %.3f Vrms\n\r", Vrms);
        printf("Output power calculated as %.3f Watts from RMS values\n\r", Avg_Power);
        
        if (Total_Energy >= 1000.0) {
         
            printf("Measured output energy since last measurement reset is %.2e Watt Hours\n\r", Total_Energy);
            
        }
        
        else if (Total_Energy >= 100.0) {
         
            printf("Measured output energy since last measurement reset is %.2f Watt Hours\n\r", Total_Energy);
            
        }
        
        else {
         
            printf("Measured output energy since last measurement reset is %.3f Watt Hours\n\r", Total_Energy);
            
        }
        
        terminal_printNewline();
        
        double max_current_print = readDoubleFromEEPROM(max_Irms_address);
        printf("Maximum recorded RMS output current is %.3f Arms\n\r", max_current_print);
        double max_Power_print = readDoubleFromEEPROM(max_Power_address);
        printf("Maximum recorded output power is %.3f Watts\n\r", max_Power_print);
        
        terminal_textAttributesReset();
        
        terminal_printNewline();
        
    }
    
    // enable live updates
    else if ((0 == strcmp(line, "Live Measurement Updates"))) {
     
        if (load_enable) {
            
            TMR2_StopTimer();
            USB_live_update_flag = true;
            terminal_textAttributes(GREEN, BLACK, NORMAL);
            printf("Enabling live measurement updates\n\r");
            terminal_textAttributesReset();
            __delay_ms(1000);
            OLED_Frame = Live_Update;
            OLED_updateCallback();

        }
        
        else {
         
            terminal_textAttributes(RED, BLACK, NORMAL);
            printf("Load is not currently enabled\n\r");
            terminal_textAttributesReset();
            
        }
            
    }
    
    
    // Different help messages
    else if((0 == strcmp(line, "Help Device Control Commands"))) {
     
        terminal_textAttributes(YELLOW, BLACK, NORMAL);
        printf("List of supported Device Control Commands:\n\r"
                
                "   Reset: Clears the terminal and resets the microcontroller\n\r"
                "   Clear: Clears the terminal but doesn't reset the micro\n\r"
                "   Cause of Reset?: Returns the cause of the most recent device reset\n\r"
                "   *IDN?: Returns device identification string\n\r"
                "   Device On Time?: Returns device on time since last device reset\n\r"
                "   Device ID?: Returns device ID as pre-programmed in flash memory\n\r"
                "   Revision ID?: Returns device silicon revision ID as pre-programmed in flash memory\n\r"
                "   User IDs?: Returns a list of user IDs (displayed in hex) as stored in flash memory\n\r"
                "   ADC Errors?: Returns the cause of an ADC error if an error occurred\n\r"
                "   Clear ADC Errors: Clears the ADC error and resumes ADC conversions\n\r"
                "   Comm Errors?: Returns if a communications error has occurred\n\r"
                "   Clear Comm Errors: Clears the communications error\n\r"
                "   Clear Max Values: Erases maximum recorded values from EEPROM\n\r"
                "   Device Summary: Prints a list of current and maximum measured device values as well as hardware IDs\n\r\n\r"
                "   Help: This message, lists supported commands\n\r\n\r"
                );
        
        terminal_textAttributesReset();

    }
    
    // Different help messages
    else if((0 == strcmp(line, "Help Device Measurement Commands"))) {
     
        terminal_textAttributes(YELLOW, BLACK, NORMAL);
        printf("List of supported Device Measurement Commands:\n\r"
                
                "   Measure POS3P3?: Returns +3.3V ADC Conversion in volts\n\r"
                "   Measure POS12?: Returns +12V ADC Conversion in volts\n\r"
                "   Measure Die Temp?: Returns the microcontroller die temperature in degrees C\n\r"
                "   Measure FVR?: Returns the internal fixed voltage reference buffer 1 output in volts\n\r"
                "   Measure AVSS?: Returns the measured value of Analog VSS in volts\n\r"
                "   Max POS3P3 Voltage?: Returns the maximum recorded +3.3V Rail Voltage measured\n\r"
                "   Max POS12 Voltage?: Returns the maximum recorded +12V Rail Voltage measured\n\r"
                "   Max Die Temp?: Returns the maximum recorded die temperature measured\n\r"
                "   Max FVR Voltage?: Returns the maximum recorded FVR Buffer 1 Voltage measured\n\r\n\r"
                );
        
        terminal_textAttributesReset();
        
    }

    // Different help messages
    else if((0 == strcmp(line, "Help Primary Measurement Commands"))) {
     
        terminal_textAttributes(YELLOW, BLACK, NORMAL);
        printf("List of supported Primary Measurement Commands:\n\r"
                
                "   Measure Detected Current?: Returns measured output current in amps as seen by ADC\n\r"
                "   Measure RMS Current?: Returns the calculated RMS output current from measurements and TRIAC firing angle\n\r"
                "   Measure RMS Voltage?: Returns the calculated RMS output voltage from TRIAC firing angle\n\r"
                "   Measure Power?: Returns the calculated output power in Watts\n\r"
                "   Measure Energy?: Returns measured energy since measurement reset in Watt Hours\n\r"
                "   Clear Energy: Resets the measured output energy to zero\n\r"
                "   Load On Time?: Returns load on time since last device reset in seconds\n\r"
                "   Max RMS Current?: Prints the maximum recorded RMS output current\n\r"
                "   Max Power?: Prints the maximum recorded output power\n\r"
                "   Measurement Summary: Prints a summary of instantaneous and maximum measured load values\n\r"
                "   Live Measurement Updates: Streams live measurement updates to terminal\n\r\n\r"
                );
        
        terminal_textAttributesReset();
        
    }
    
    // Different help messages
    else if((0 == strcmp(line, "Help Output Control Commands"))) {
     
        terminal_textAttributes(YELLOW, BLACK, NORMAL);
        printf("List of supported Output Control Commands:\n\r"
                
                "   Enable Dimming: Enable TRIAC output dimming\n\r"
                "   Disable Dimming: Disable TRIAC output dimming\n\r"
                "   Enable Load: Enables the output TRIAC with dimming disabled\n\r"
                "   Disable Load: Disables the output TRIAC completely\n\r"
                "   Load Enabled?: Returns if the output load is enabled or disabled\n\r"
                "   Dimming Enabled?: Returns if dimming of the output load is enabled or not\n\r"
                "   Set Dimming Percentage: <x>: Sets the output dimming percentage as x percent\n\r\n\r"
                );
        
        terminal_textAttributesReset();
        
    }
    
    // all help messages
    else if((0 == strcmp(line, "Help All"))) {
     
        terminal_textAttributes(YELLOW, BLACK, NORMAL);
        printf("List of all supported commands:\n\r"
                
                "Device Control Commands: Commands to view and control low level system functionality\n\r"
                "   Reset: Clears the terminal and resets the microcontroller\n\r"
                "   Clear: Clears the terminal but doesn't reset the micro\n\r"
                "   Cause of Reset?: Returns the cause of the most recent device reset\n\r"
                "   *IDN?: Returns device identification string\n\r"
                "   Device On Time?: Returns device on time since last device reset\n\r"
                "   Device ID?: Returns device ID as pre-programmed in flash memory\n\r"
                "   Revision ID?: Returns device silicon revision ID as pre-programmed in flash memory\n\r"
                "   User IDs?: Returns a list of user IDs (displayed in hex) as stored in flash memory\n\r"
                "   ADC Errors?: Returns the cause of an ADC error if an error occurred\n\r"
                "   Clear ADC Errors: Clears the ADC error and resumes ADC conversions\n\r"
                "   Comm Errors?: Returns if a communications error has occurred\n\r"
                "   Clear Comm Errors: Clears the communications error\n\r"
                "   Clear Max Values: Erases maximum recorded values from EEPROM\n\r"
                "   Help: This message, lists supported commands\n\r"
                "   Device Summary: Prints a list of current and maximum measured device values as well as hardware IDs\n\r\n\r"
                
                "Device Measurement Commands: View low level system measurements\n\r"
                "   Measure POS3P3?: Returns +3.3V ADC Conversion in volts\n\r"
                "   Measure POS12?: Returns +12V ADC Conversion in volts\n\r"
                "   Measure Die Temp?: Returns the microcontroller die temperature in degrees C\n\r"
                "   Measure FVR?: Returns the internal fixed voltage reference buffer 1 output in volts\n\r"
                "   Measure AVSS?: Returns the measured value of Analog VSS in volts\n\r"
                "   Max POS3P3 Voltage?: Returns the maximum recorded +3.3V Rail Voltage measured\n\r"
                "   Max POS12 Voltage?: Returns the maximum recorded +12V Rail Voltage measured\n\r"
                "   Max Die Temp?: Returns the maximum recorded die temperature measured\n\r"
                "   Max FVR Voltage?: Returns the maximum recorded FVR Buffer 1 Voltage measured\n\r\n\r"
                
                "Primary Measurement Commands: View high level output measurements and calculations\n\r"
                "   Measure Detected Current?: Returns measured output current in amps as seen by ADC\n\r"
                "   Measure RMS Current?: Returns the calculated RMS output current from measurements and TRIAC firing angle\n\r"
                "   Measure RMS Voltage?: Returns the calculated RMS output voltage from TRIAC firing angle\n\r"
                "   Measure Power?: Returns the calculated output power in Watts\n\r"
                "   Measure Energy?: Returns measured energy since measurement reset in Watt Hours\n\r"
                "   Clear Energy: Resets the measured output energy to zero\n\r"
                "   Load On Time?: Returns load on time since last device reset in seconds\n\r"
                "   Max RMS Current?: Prints the maximum recorded RMS output current\n\r"
                "   Max Power?: Prints the maximum recorded output power\n\r"
                "   Measurement Summary: Prints a summary of instantaneous and maximum measured load values\n\r"
                "   Live Measurement Updates: Streams live measurement updates to terminal\n\r\n\r"
                
                "Output Control Commands: Control the output state and dimming features\n\r"
                "   Enable Dimming: Enable TRIAC output dimming\n\r"
                "   Disable Dimming: Disable TRIAC output dimming\n\r"
                "   Enable Load: Enables the output TRIAC with dimming disabled\n\r"
                "   Disable Load: Disables the output TRIAC completely\n\r"
                "   Load Enabled?: Returns if the output load is enabled or disabled\n\r"
                "   Dimming Enabled?: Returns if dimming of the output load is enabled or not\n\r"
                "   Set Dimming Percentage: <x>: Sets the output dimming percentage as x percent\n\r\n\r"
                
                );
        
        terminal_textAttributesReset();
        
    }
    
    
    // help, print options
    else if((0 == strcmp(line, "Help"))) {

        terminal_textAttributes(YELLOW, BLACK, NORMAL);
        printf("Please specify what type of commands you'd like help with:\n\r"
               "Try 'Help <command set>'\n\r\n\r"
                
                "Supported Command Sets:\n\r"
                "   Device Control Commands: Commands to view and control low level system functionality\n\r"
                "   Device Measurement Commands: View low level system measurements\n\r"
                "   Primary Measurement Commands: View high level output measurements and calculations\n\r"
                "   Output Control Commands: Control the output state and dimming features\n\r\n\r"
                
                "'Help All' will list all commands\n\r"
                );
        
        // Get some space on terminal
        terminal_printNewline();
        printf("Help messages and neutral responses appear in yellow\n\r");
        
        terminal_textAttributes(GREEN, BLACK, NORMAL);
        printf("System parameters and affirmative responses appear in green\n\r");
        terminal_textAttributes(CYAN, BLACK, NORMAL);
        printf("Measurement responses appear in cyan\n\r");
        terminal_textAttributes(RED, BLACK, NORMAL);
        printf("Errors and negative responses appear in red\n\r");
        terminal_textAttributesReset();
        printf("User input appears in white\n\r");
        
        // Get some space on terminal
        terminal_printNewline();

    }
    
    // Hidden ascii art for my own entertainment
    else if ((0 == strcmp(line, "Easter Egg"))) {

        terminal_printNewline();
        terminal_textAttributes(RED, BLACK, NORMAL);
        printf(
"    _   ___   ___                      __  __     _                          _   ___  _      \n\r"               
"   /_\\ / __| | _ \\_____ __ _____ _ _  |  \\/  |___| |_ ___ _ _   __ _ _ _  __| | |   \\(_)_ __  _ __  ___ _ _ \n\r"
"  / _ \\ (__  |  _/ _ \\ V  V / -_) '_| | |\\/| / -_)  _/ -_) '_| / _` | ' \\/ _` | | |) | | '  \\| '  \\/ -_) '_|\n\r"
" /_/ \\_\\___| |_| \\___/\\_/\\_/\\___|_|   |_|  |_\\___|\\__\\___|_|   \\__,_|_||_\\__,_| |___/|_|_|_|_|_|_|_\\___|_|  \n\r"
                                                                                                            
                
    );
        
        terminal_printNewline();
        terminal_textAttributes(YELLOW, BLUE, NORMAL);
        printf("Marquette University EECE");
        terminal_textAttributes(GREEN, BLACK, NORMAL);
        terminal_printNewline();
        printf("ELEN 3035 Final Project\n\r");
        printf("Drew Maatman and Gabe Thalji");
        terminal_printNewline();
        terminal_textAttributes(YELLOW, BLACK, BOLD);
        printf("PSOCs SUCK\n\r");
        terminal_textAttributesReset();
        terminal_printNewline();
        
    }
    
    // If we've gotten an unsupported command:
    else {
     
        if (strlen(line) >= 1) {

            terminal_textAttributes(RED, BLACK, NORMAL);
            printf("Unsupported or mis-entered command\n\r");
            terminal_textAttributes(YELLOW, BLACK, NORMAL);
            printf("Commands are case sensitive, backspace is supported, command history is not supported\n\r");
            printf("Call 'Help' for list of supported command sets, or 'Help All' for list of all supported commands\n\r");
            terminal_textAttributesReset();
        
        }
        
        else if (USB_live_update_flag) {
         
            USB_live_update_flag = false;
            terminal_textAttributes(RED, BLACK, NORMAL);
            printf("Live measurement updates disabled\n\r");
            terminal_textAttributesReset();
            
        }
        
    }
        
        
    
}


// This function dumps a bunch of debug data on reset to the serial port
void terminal_printResetMessage(void) {

    // Print boot message header
    terminal_textAttributes(YELLOW, BLUE, BOLD);
    printf("AC Power Meter / Dimmer, ELEN 3035 Final Project");
    terminal_textAttributes(YELLOW, BLACK, BOLD);
    terminal_printNewline();
    printf("Drew Maatman and Gabe Thalji\n\r");
    
    terminal_printNewline();
    
    // Determine if we need to make text red or green depending on
    // badness of cause of reset
    if (    reset_cause == Stack_Overflow_Reset ||
            reset_cause == Stack_Underflow_Reset ||
            reset_cause == Windowed_Watch_Dog_Timer_Reset ||
            reset_cause == Watch_Dog_Timer_Reset ||
            reset_cause == Brown_Out_Reset ||
            reset_cause == Watch_Dog_Timer_Reset ||
            reset_cause == Undefined_Reset
            ) {
     
        terminal_textAttributes(RED, BLACK, BOLD);
        
    }
    
    else {
     
        terminal_textAttributes(GREEN, BLACK, NORMAL);
        
    }
    
    // Print the cause of the reset
    printf("Cause of reset: %s\n\r", getCauseOfResetString(reset_cause));
    terminal_printNewline();
    
    terminal_textAttributes(GREEN, BLACK, NORMAL);
    printf("System parameters and affirmative responses appear in green\n\r");
    terminal_textAttributes(CYAN, BLACK, NORMAL);
    printf("Measurement responses appear in cyan\n\r");
    terminal_textAttributes(RED, BLACK, NORMAL);
    printf("Errors and negative responses appear in red\n\r");
    terminal_textAttributes(YELLOW, BLACK, NORMAL);
    printf("Help messages and neutral responses appear in yellow\n\r");
    terminal_textAttributesReset();
    printf("User input appears in white\n\r");
    
    terminal_printNewline();
    
    // print device ID from flash
    terminal_textAttributes(GREEN, BLACK, NORMAL);
    printf("Device ID stored in Flash is: 0x%X. This corresponds to a device "
                "part number of %s\n\r",
                getDeviceID(),
                getDeviceIDString(getDeviceID()));
    
    // print revision ID from flash
    printf("Device silicon revision ID as stored in Flash is: %c%03d\n\r",
                ((char) getMajorRevisionID() + 65),getMinorRevisionID());
    
    // print user IDs
    printf("The following User IDs have been retrieved from flash memory:\n\r");
    
    // Loop through all 8 user ID locations in flash and print
    for (int userID = 0; userID <= 7; userID++) {

        printf("    User ID Word %d (Flash address 0x20000%X): 0x%04X\n\r",
                userID,
                (2 * userID),
                getUserID(userID));

    }
    
    terminal_printNewline();
    
    // print if there was an ADC error during startup
    if (getADCError()) {
            
            terminal_textAttributes(RED, BLACK, NORMAL);
            printf("ADC error(s) detected!\n\r");
            printf("The following channels caused an ADC error:\n\r");
            
            if (error_handler.ADC_general_error_flag) {
                printf("    General ADC error\n\r");
            }
            
            if (error_handler.AVSS_ADC_error_flag) {
                printf("    AVSS\n\r");
            }
            
            if (error_handler.FVR_ADC_error_flag) {
                printf("    FVR\n\r");
            }
            
            if (error_handler.ISNS_ADC_error_flag) {
                printf("    ISNS\n\r");
            }
            
            if (error_handler.POS12_ADC_error_flag) {
                printf("    POS12\n\r");
            }
            
            if (error_handler.POS3P3_ADC_error_flag) {
                printf("    POS3P3\n\r");
            }
            
            if (error_handler.Temp_ADC_error_flag) {
                printf("    Die Temp\n\r");
            }
            
            terminal_textAttributes(YELLOW, BLACK, NORMAL);
            printf("Call 'Clear ADC Errors' to clear ADC error(s)\n\r");
            terminal_textAttributesReset();
            
        }
        
        else {
         
            terminal_textAttributes(GREEN, BLACK, NORMAL);
            printf("No ADC error(s) detected\n\r");
            terminal_textAttributesReset();
        
        }
    
    // Print if there was a comm error during startup
    if (getCOMMError()) {
        
            terminal_textAttributes(RED, BLACK, NORMAL);
            printf("Communications error(s) detected! Interfaces causing error(s):\n\r");
            
            if (error_handler.I2C_COMM_error_flag) {
                printf("    OLED Display I2C\n\r");
            }
            
            if (error_handler.USB_UART_COMM_error_flag) {
                printf("    USB UART (this interface)\n\r");
            }
            
            terminal_textAttributes(YELLOW, BLACK, NORMAL);
            printf("Call 'Clear Comm Errors' to clear communications error(s)\n\r");
            terminal_textAttributesReset();
        
        }
        
        else {
            
            terminal_textAttributes(GREEN, BLACK, NORMAL);
            printf("No communications error(s) detected\n\r");
            terminal_textAttributesReset();
            
        }
    
    // Print initial state of load
    terminal_printNewline();
    terminal_textAttributes(YELLOW, BLACK, NORMAL);
    printf("Load is currently enabled, dimming is disabled\n\r");
    
    // Print device measurements
    terminal_printNewline();
    terminal_textAttributes(CYAN, BLACK, NORMAL);
    printf("+3.3V rail measured as +%.3f Volts\n\r", POS3P3_ADC_Result);
    printf("+12V rail measured as +%.3f Volts\n\r", POS12_ADC_Result);
    printf("Die Temperature measured as %.3fC\n\r", Temp_ADC_Result);
    printf("Fixed Voltage Reference Buffer 1 measured as %.3f Volts\n\r", FVR_ADC_Result);
    printf("AVSS measured as %.3f Volts\n\r", AVSS_ADC_Result);
    
    terminal_printNewline();
    
    terminal_textAttributes(YELLOW, BLACK, NORMAL);
    printf("Call 'Help' for list of supported command sets, or 'Help All' for list of all supported commands\n\r");
    
    // Tell user we're up and running
    terminal_textAttributes(BLACK, GREEN, BOLD);
    terminal_printNewline();
    printf("Boot Complete");
    terminal_textAttributesReset();
    terminal_printNewline();
    terminal_printNewline();
    terminal_textAttributesReset();
    
    
}

