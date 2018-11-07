/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18LF67K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set ISNS_ADC aliases
#define ISNS_ADC_TRIS                 TRISAbits.TRISA0
#define ISNS_ADC_LAT                  LATAbits.LATA0
#define ISNS_ADC_PORT                 PORTAbits.RA0
#define ISNS_ADC_WPU                  WPUAbits.WPUA0
#define ISNS_ADC_OD                   ODCONAbits.ODCA0
#define ISNS_ADC_ANS                  ANSELAbits.ANSELA0
#define ISNS_ADC_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define ISNS_ADC_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define ISNS_ADC_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define ISNS_ADC_GetValue()           PORTAbits.RA0
#define ISNS_ADC_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define ISNS_ADC_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define ISNS_ADC_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define ISNS_ADC_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define ISNS_ADC_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define ISNS_ADC_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define ISNS_ADC_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define ISNS_ADC_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSELA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA3 procedures
#define RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()              PORTAbits.RA3
#define RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetPullup()             do { WPUAbits.WPUA3 = 1; } while(0)
#define RA3_ResetPullup()           do { WPUAbits.WPUA3 = 0; } while(0)
#define RA3_SetAnalogMode()         do { ANSELAbits.ANSELA3 = 1; } while(0)
#define RA3_SetDigitalMode()        do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set POS12_ADC aliases
#define POS12_ADC_TRIS                 TRISAbits.TRISA4
#define POS12_ADC_LAT                  LATAbits.LATA4
#define POS12_ADC_PORT                 PORTAbits.RA4
#define POS12_ADC_WPU                  WPUAbits.WPUA4
#define POS12_ADC_OD                   ODCONAbits.ODCA4
#define POS12_ADC_ANS                  ANSELAbits.ANSELA4
#define POS12_ADC_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define POS12_ADC_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define POS12_ADC_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define POS12_ADC_GetValue()           PORTAbits.RA4
#define POS12_ADC_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define POS12_ADC_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define POS12_ADC_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define POS12_ADC_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define POS12_ADC_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define POS12_ADC_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define POS12_ADC_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define POS12_ADC_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set POS3P3_ADC aliases
#define POS3P3_ADC_TRIS                 TRISEbits.TRISE2
#define POS3P3_ADC_LAT                  LATEbits.LATE2
#define POS3P3_ADC_PORT                 PORTEbits.RE2
#define POS3P3_ADC_WPU                  WPUEbits.WPUE2
#define POS3P3_ADC_OD                   ODCONEbits.ODCE2
#define POS3P3_ADC_ANS                  ANSELEbits.ANSELE2
#define POS3P3_ADC_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define POS3P3_ADC_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define POS3P3_ADC_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define POS3P3_ADC_GetValue()           PORTEbits.RE2
#define POS3P3_ADC_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define POS3P3_ADC_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define POS3P3_ADC_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define POS3P3_ADC_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define POS3P3_ADC_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define POS3P3_ADC_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define POS3P3_ADC_SetAnalogMode()      do { ANSELEbits.ANSELE2 = 1; } while(0)
#define POS3P3_ADC_SetDigitalMode()     do { ANSELEbits.ANSELE2 = 0; } while(0)

// get/set IO_RF0 aliases
#define IO_RF0_TRIS                 TRISFbits.TRISF0
#define IO_RF0_LAT                  LATFbits.LATF0
#define IO_RF0_PORT                 PORTFbits.RF0
#define IO_RF0_WPU                  WPUFbits.WPUF0
#define IO_RF0_OD                   ODCONFbits.ODCF0
#define IO_RF0_ANS                  ANSELFbits.ANSELF0
#define IO_RF0_SetHigh()            do { LATFbits.LATF0 = 1; } while(0)
#define IO_RF0_SetLow()             do { LATFbits.LATF0 = 0; } while(0)
#define IO_RF0_Toggle()             do { LATFbits.LATF0 = ~LATFbits.LATF0; } while(0)
#define IO_RF0_GetValue()           PORTFbits.RF0
#define IO_RF0_SetDigitalInput()    do { TRISFbits.TRISF0 = 1; } while(0)
#define IO_RF0_SetDigitalOutput()   do { TRISFbits.TRISF0 = 0; } while(0)
#define IO_RF0_SetPullup()          do { WPUFbits.WPUF0 = 1; } while(0)
#define IO_RF0_ResetPullup()        do { WPUFbits.WPUF0 = 0; } while(0)
#define IO_RF0_SetPushPull()        do { ODCONFbits.ODCF0 = 0; } while(0)
#define IO_RF0_SetOpenDrain()       do { ODCONFbits.ODCF0 = 1; } while(0)
#define IO_RF0_SetAnalogMode()      do { ANSELFbits.ANSELF0 = 1; } while(0)
#define IO_RF0_SetDigitalMode()     do { ANSELFbits.ANSELF0 = 0; } while(0)

// get/set IO_RF1 aliases
#define IO_RF1_TRIS                 TRISFbits.TRISF1
#define IO_RF1_LAT                  LATFbits.LATF1
#define IO_RF1_PORT                 PORTFbits.RF1
#define IO_RF1_WPU                  WPUFbits.WPUF1
#define IO_RF1_OD                   ODCONFbits.ODCF1
#define IO_RF1_ANS                  ANSELFbits.ANSELF1
#define IO_RF1_SetHigh()            do { LATFbits.LATF1 = 1; } while(0)
#define IO_RF1_SetLow()             do { LATFbits.LATF1 = 0; } while(0)
#define IO_RF1_Toggle()             do { LATFbits.LATF1 = ~LATFbits.LATF1; } while(0)
#define IO_RF1_GetValue()           PORTFbits.RF1
#define IO_RF1_SetDigitalInput()    do { TRISFbits.TRISF1 = 1; } while(0)
#define IO_RF1_SetDigitalOutput()   do { TRISFbits.TRISF1 = 0; } while(0)
#define IO_RF1_SetPullup()          do { WPUFbits.WPUF1 = 1; } while(0)
#define IO_RF1_ResetPullup()        do { WPUFbits.WPUF1 = 0; } while(0)
#define IO_RF1_SetPushPull()        do { ODCONFbits.ODCF1 = 0; } while(0)
#define IO_RF1_SetOpenDrain()       do { ODCONFbits.ODCF1 = 1; } while(0)
#define IO_RF1_SetAnalogMode()      do { ANSELFbits.ANSELF1 = 1; } while(0)
#define IO_RF1_SetDigitalMode()     do { ANSELFbits.ANSELF1 = 0; } while(0)

// get/set IO_RF2 aliases
#define IO_RF2_TRIS                 TRISFbits.TRISF2
#define IO_RF2_LAT                  LATFbits.LATF2
#define IO_RF2_PORT                 PORTFbits.RF2
#define IO_RF2_WPU                  WPUFbits.WPUF2
#define IO_RF2_OD                   ODCONFbits.ODCF2
#define IO_RF2_ANS                  ANSELFbits.ANSELF2
#define IO_RF2_SetHigh()            do { LATFbits.LATF2 = 1; } while(0)
#define IO_RF2_SetLow()             do { LATFbits.LATF2 = 0; } while(0)
#define IO_RF2_Toggle()             do { LATFbits.LATF2 = ~LATFbits.LATF2; } while(0)
#define IO_RF2_GetValue()           PORTFbits.RF2
#define IO_RF2_SetDigitalInput()    do { TRISFbits.TRISF2 = 1; } while(0)
#define IO_RF2_SetDigitalOutput()   do { TRISFbits.TRISF2 = 0; } while(0)
#define IO_RF2_SetPullup()          do { WPUFbits.WPUF2 = 1; } while(0)
#define IO_RF2_ResetPullup()        do { WPUFbits.WPUF2 = 0; } while(0)
#define IO_RF2_SetPushPull()        do { ODCONFbits.ODCF2 = 0; } while(0)
#define IO_RF2_SetOpenDrain()       do { ODCONFbits.ODCF2 = 1; } while(0)
#define IO_RF2_SetAnalogMode()      do { ANSELFbits.ANSELF2 = 1; } while(0)
#define IO_RF2_SetDigitalMode()     do { ANSELFbits.ANSELF2 = 0; } while(0)

// get/set IO_RF3 aliases
#define IO_RF3_TRIS                 TRISFbits.TRISF3
#define IO_RF3_LAT                  LATFbits.LATF3
#define IO_RF3_PORT                 PORTFbits.RF3
#define IO_RF3_WPU                  WPUFbits.WPUF3
#define IO_RF3_OD                   ODCONFbits.ODCF3
#define IO_RF3_ANS                  ANSELFbits.ANSELF3
#define IO_RF3_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define IO_RF3_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define IO_RF3_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define IO_RF3_GetValue()           PORTFbits.RF3
#define IO_RF3_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define IO_RF3_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define IO_RF3_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define IO_RF3_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define IO_RF3_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define IO_RF3_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define IO_RF3_SetAnalogMode()      do { ANSELFbits.ANSELF3 = 1; } while(0)
#define IO_RF3_SetDigitalMode()     do { ANSELFbits.ANSELF3 = 0; } while(0)

// get/set IO_RG0 aliases
#define IO_RG0_TRIS                 TRISGbits.TRISG0
#define IO_RG0_LAT                  LATGbits.LATG0
#define IO_RG0_PORT                 PORTGbits.RG0
#define IO_RG0_WPU                  WPUGbits.WPUG0
#define IO_RG0_OD                   ODCONGbits.ODCG0
#define IO_RG0_ANS                  ANSELGbits.ANSELG0
#define IO_RG0_SetHigh()            do { LATGbits.LATG0 = 1; } while(0)
#define IO_RG0_SetLow()             do { LATGbits.LATG0 = 0; } while(0)
#define IO_RG0_Toggle()             do { LATGbits.LATG0 = ~LATGbits.LATG0; } while(0)
#define IO_RG0_GetValue()           PORTGbits.RG0
#define IO_RG0_SetDigitalInput()    do { TRISGbits.TRISG0 = 1; } while(0)
#define IO_RG0_SetDigitalOutput()   do { TRISGbits.TRISG0 = 0; } while(0)
#define IO_RG0_SetPullup()          do { WPUGbits.WPUG0 = 1; } while(0)
#define IO_RG0_ResetPullup()        do { WPUGbits.WPUG0 = 0; } while(0)
#define IO_RG0_SetPushPull()        do { ODCONGbits.ODCG0 = 0; } while(0)
#define IO_RG0_SetOpenDrain()       do { ODCONGbits.ODCG0 = 1; } while(0)
#define IO_RG0_SetAnalogMode()      do { ANSELGbits.ANSELG0 = 1; } while(0)
#define IO_RG0_SetDigitalMode()     do { ANSELGbits.ANSELG0 = 0; } while(0)

// get/set IO_RG1 aliases
#define IO_RG1_TRIS                 TRISGbits.TRISG1
#define IO_RG1_LAT                  LATGbits.LATG1
#define IO_RG1_PORT                 PORTGbits.RG1
#define IO_RG1_WPU                  WPUGbits.WPUG1
#define IO_RG1_OD                   ODCONGbits.ODCG1
#define IO_RG1_ANS                  ANSELGbits.ANSELG1
#define IO_RG1_SetHigh()            do { LATGbits.LATG1 = 1; } while(0)
#define IO_RG1_SetLow()             do { LATGbits.LATG1 = 0; } while(0)
#define IO_RG1_Toggle()             do { LATGbits.LATG1 = ~LATGbits.LATG1; } while(0)
#define IO_RG1_GetValue()           PORTGbits.RG1
#define IO_RG1_SetDigitalInput()    do { TRISGbits.TRISG1 = 1; } while(0)
#define IO_RG1_SetDigitalOutput()   do { TRISGbits.TRISG1 = 0; } while(0)
#define IO_RG1_SetPullup()          do { WPUGbits.WPUG1 = 1; } while(0)
#define IO_RG1_ResetPullup()        do { WPUGbits.WPUG1 = 0; } while(0)
#define IO_RG1_SetPushPull()        do { ODCONGbits.ODCG1 = 0; } while(0)
#define IO_RG1_SetOpenDrain()       do { ODCONGbits.ODCG1 = 1; } while(0)
#define IO_RG1_SetAnalogMode()      do { ANSELGbits.ANSELG1 = 1; } while(0)
#define IO_RG1_SetDigitalMode()     do { ANSELGbits.ANSELG1 = 0; } while(0)

// get/set RG6 procedures
#define RG6_SetHigh()            do { LATGbits.LATG6 = 1; } while(0)
#define RG6_SetLow()             do { LATGbits.LATG6 = 0; } while(0)
#define RG6_Toggle()             do { LATGbits.LATG6 = ~LATGbits.LATG6; } while(0)
#define RG6_GetValue()              PORTGbits.RG6
#define RG6_SetDigitalInput()    do { TRISGbits.TRISG6 = 1; } while(0)
#define RG6_SetDigitalOutput()   do { TRISGbits.TRISG6 = 0; } while(0)
#define RG6_SetPullup()             do { WPUGbits.WPUG6 = 1; } while(0)
#define RG6_ResetPullup()           do { WPUGbits.WPUG6 = 0; } while(0)
#define RG6_SetAnalogMode()         do { ANSELGbits.ANSELG6 = 1; } while(0)
#define RG6_SetDigitalMode()        do { ANSELGbits.ANSELG6 = 0; } while(0)

// get/set RG7 procedures
#define RG7_SetHigh()            do { LATGbits.LATG7 = 1; } while(0)
#define RG7_SetLow()             do { LATGbits.LATG7 = 0; } while(0)
#define RG7_Toggle()             do { LATGbits.LATG7 = ~LATGbits.LATG7; } while(0)
#define RG7_GetValue()              PORTGbits.RG7
#define RG7_SetDigitalInput()    do { TRISGbits.TRISG7 = 1; } while(0)
#define RG7_SetDigitalOutput()   do { TRISGbits.TRISG7 = 0; } while(0)
#define RG7_SetPullup()             do { WPUGbits.WPUG7 = 1; } while(0)
#define RG7_ResetPullup()           do { WPUGbits.WPUG7 = 0; } while(0)
#define RG7_SetAnalogMode()         do { ANSELGbits.ANSELG7 = 1; } while(0)
#define RG7_SetDigitalMode()        do { ANSELGbits.ANSELG7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/