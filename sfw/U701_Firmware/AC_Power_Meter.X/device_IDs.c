
#include "device_IDs.h"

uint16_t getDeviceID(void) {
 
    // Grab device ID from flash and pass it back to function caller
    // program memory address 0x3FFFFE holds device ID integer
    return FLASH_ReadWord(0x3FFFFE);
    
}

uint8_t getMajorRevisionID(void) {
 
    // Revision IDs are stored at flash memory address 0x3FFFFC in flash memory
    uint16_t REVID_RAW = FLASH_ReadWord(0x3FFFFC);
    
    // shift and mask off extra bits
    return (REVID_RAW >> 6) & 0b11111;
    
}


uint8_t getMinorRevisionID(void) {
 
    // Revision IDs are stored at flash memory address 0x3FFFFC in flash memory
    uint16_t REVID_RAW = FLASH_ReadWord(0x3FFFFC);
    
    // shift and mask off extra bits
    return REVID_RAW & 0b11111;
    
}


inline char * getDeviceIDString(uint16_t inputDevID) {
 
    // Possible return strings
    const char *strings[] = {
    
        "PIC18F67K40",
        "PIC18LF67K40",
        "Undefined"
        
    };
    
    // Decode return string from device ID bits
    // Each case corresponds to a possible device ID
    switch (inputDevID) {
    
        case 0x6AC0:
            return strings[0];
            break;
            
        case 0x6B20:
            return strings[1];
            break;
        
        default:
            return strings[2];
            break;
            
    }
    
}

uint16_t getUserID(uint8_t inputUserID) {
 
    // Initial address user IDs are stored at
    uint32_t initialOffset = 0x200000;
    
    // Address offset required based on accessed user ID
    uint8_t IDOffset = inputUserID * 2;
    
    return FLASH_ReadWord(initialOffset + IDOffset);
    
    
    
}