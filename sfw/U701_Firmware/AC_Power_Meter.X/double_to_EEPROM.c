

#include "double_to_EEPROM.h"

// This function writes a double to EEPROM starting at the given address
void writeDoubleToEEPROM(double input_double, uint16_t starting_address) {
 
    // Create an array of bytes from the input data
    double_bytes_t input_data;
    input_data.double_t = input_double;
    
    // Iterate over all bytes in double and save to EEPROM
    for (int byte_index = 0; byte_index < sizeof(double); byte_index++) {
     
        DATAEE_WriteByte((starting_address + byte_index), input_data.byte_array_t[byte_index]);
        
    }
    
}

// This function retrieves a double from EEPROM from the starting address
double readDoubleFromEEPROM(uint16_t starting_address) {
 
    // Create an array of bytes to read and return to function caller
    double_bytes_t output_data;
    
    // Iterate over all bytes in double and save to output array
    for (int byte_index = 0; byte_index < sizeof(double); byte_index++) {
     
        output_data.byte_array_t[byte_index] = DATAEE_ReadByte(starting_address + byte_index);
        
    }
    
    // Kick back interpreted double to function caller
    return output_data.double_t;
    
}
