
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

char* getRevisionIDString(uint8_t inputMajRevID, uint8_t inputMinRevID) {
 
    char returnString[4];
    
    // A major revision of 0b00000 corresponds to revision of 'A'
    // Obtain the ASCII character for the major rev ID and add a 17 character
    // offset
    // 17 char offset = 'A' (int = 65) - '0' (int = 48)
    char MajRevStr[1];
    utoa(inputMajRevID, MajRevStr, 10);
    MajRevStr[0] += 17;
    
    // Minor Revision will just be an int converted to a number
    char MinRevStr[2];
    utoa(inputMinRevID, MinRevStr, 10);
    
    // Copy Major Revision string into output string
    strcpy(returnString, MajRevStr);
    
    // Tack on minor revision string onto return sting
    strcat(returnString, MinRevStr);
    
    // Pass back revision ID string to 
    return *returnString;
    
}

uint16_t getUserID(uint8_t inputUserID) {
 
    // Initial address user IDs are stored at
    uint16_t initialOffset = 0x200000;
    
    // Address offset required based on accessed user ID
    uint8_t IDOffset = inputUserID * 2;
    
    return FLASH_ReadWord(initialOffset + IDOffset);
    
    
    
}