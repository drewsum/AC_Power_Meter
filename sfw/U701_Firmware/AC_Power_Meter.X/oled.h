/* 
 * File:   oled.h
 * Author: Drew Maatman
 *
 * Created on January 31, 2018, 9:34 PM
 */

#ifndef OLED_H
#define	OLED_H

// Libraries
#include <xc.h>
#include <string.h>
#include <stdlib.h>

#include "mcc_generated_files/mcc.h"

#include "mcc_generated_files/i2c1.h"

#include "error_handling.h"

#include "pin_macros.h"

#define OLED_ADDR (uint16_t) 0x3C

// OLED Dimension Macros
#define OLED_WIDTH 128
#define OLED_HEIGHT 64

// Define command macros
#define OLED_SETCONTRAST            0x81
#define OLED_DISPLAYALLON_RESUME    0xA4
#define OLED_DISPLAYALLON           0xA5
#define OLED_NORMALDISPLAY          0xA6
#define OLED_INVERTDISPLAY          0xA7
#define OLED_DISPLAYOFF             0xAE
#define OLED_DISPLAYON              0xAF
#define OLED_SETDISPLAYOFFSET       0xD3
#define OLED_SETCOMPINS             0xDA
#define OLED_SETVCOMDETECT          0xDB
#define OLED_SETDISPLAYCLOCKDIV     0xD5
#define OLED_SETPRECHARGE           0xD9
#define OLED_SETMULTIPLEX           0xA8
#define OLED_SETLOWCOLUMN           0x00
#define OLED_SETHIGHCOLUMN          0x10
#define OLED_SETSTARTLINE           0x40
#define OLED_MEMORYMODE             0x20
#define OLED_COLUMNADDR             0x21
#define OLED_PAGEADDR               0x22
#define OLED_COMSCANINC             0xC0
#define OLED_COMSCANDEC             0xC8
#define OLED_SEGREMAP               0xA0
#define OLED_CHARGEPUMP             0x8D

// Function prototypes
void OLED_Command(uint8_t temp);
void OLED_Data(uint8_t temp);
void OLED_Init(void);
void OLED_YX(unsigned char Row, unsigned char Column);
void OLED_PutChar(char ch);
void OLED_Clear(void);
void OLED_Write_String(char *s);
void OLED_Write_Integer(uint16_t i);
void OLED_Write_Float(float f);


    


    



#endif	/* OLED_H */

