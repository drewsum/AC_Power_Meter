
#include "device_IDs.h"

uint16_t getDeviceID(void) {
 
    // Grab device ID from flash and pass it back to function caller
    // program memory address 0x3FFFFE holds device ID integer
    return FLASH_ReadWord(0x3FFFFE);
    
}


char* getDeviceIDString(uint16_t inputDevID) {
 
    // Return string buffer
    char returnString[12];
    
    // Decode return string from device ID bits
    // Each case corresponds to a possible device ID
    switch (inputDevID) {
    
        case 0x6AC0:
            strcpy(returnString, "PIC18F67K40");
            break;
            
        case 0x6B20:
            strcpy(returnString, "PIC18LF67K40");
            break;
        
        default:
            strcpy(returnString, "Undefined");
            break;
    
    }
    
    // Pass pointer to return string back to function call
    return *returnString;
    
}
