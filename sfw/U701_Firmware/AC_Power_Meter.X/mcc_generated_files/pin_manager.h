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

// get/set IO_RA1 aliases
#define IO_RA1_TRIS                 TRISAbits.TRISA1
#define IO_RA1_LAT                  LATAbits.LATA1
#define IO_RA1_PORT                 PORTAbits.RA1
#define IO_RA1_WPU                  WPUAbits.WPUA1
#define IO_RA1_OD                   ODCONAbits.ODCA1
#define IO_RA1_ANS                  ANSELAbits.ANSELA1
#define IO_RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IO_RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IO_RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IO_RA1_GetValue()           PORTAbits.RA1
#define IO_RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IO_RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IO_RA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define IO_RA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define IO_RA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define IO_RA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define IO_RA1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define IO_RA1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

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

// get/set RA5 procedures
#define RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()              PORTAbits.RA5
#define RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()             do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()           do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetAnalogMode()         do { ANSELAbits.ANSELA5 = 1; } while(0)
#define RA5_SetDigitalMode()        do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set IO_RA6 aliases
#define IO_RA6_TRIS                 TRISAbits.TRISA6
#define IO_RA6_LAT                  LATAbits.LATA6
#define IO_RA6_PORT                 PORTAbits.RA6
#define IO_RA6_WPU                  WPUAbits.WPUA6
#define IO_RA6_OD                   ODCONAbits.ODCA6
#define IO_RA6_ANS                  ANSELAbits.ANSELA6
#define IO_RA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define IO_RA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define IO_RA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define IO_RA6_GetValue()           PORTAbits.RA6
#define IO_RA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define IO_RA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define IO_RA6_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define IO_RA6_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define IO_RA6_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define IO_RA6_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define IO_RA6_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define IO_RA6_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set IO_RB0 aliases
#define IO_RB0_TRIS                 TRISBbits.TRISB0
#define IO_RB0_LAT                  LATBbits.LATB0
#define IO_RB0_PORT                 PORTBbits.RB0
#define IO_RB0_WPU                  WPUBbits.WPUB0
#define IO_RB0_OD                   ODCONBbits.ODCB0
#define IO_RB0_ANS                  ANSELBbits.ANSELB0
#define IO_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define IO_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define IO_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define IO_RB0_GetValue()           PORTBbits.RB0
#define IO_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define IO_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define IO_RB0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define IO_RB0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define IO_RB0_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define IO_RB0_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define IO_RB0_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define IO_RB0_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set IO_RB1 aliases
#define IO_RB1_TRIS                 TRISBbits.TRISB1
#define IO_RB1_LAT                  LATBbits.LATB1
#define IO_RB1_PORT                 PORTBbits.RB1
#define IO_RB1_WPU                  WPUBbits.WPUB1
#define IO_RB1_OD                   ODCONBbits.ODCB1
#define IO_RB1_ANS                  ANSELBbits.ANSELB1
#define IO_RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define IO_RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define IO_RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define IO_RB1_GetValue()           PORTBbits.RB1
#define IO_RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define IO_RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define IO_RB1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define IO_RB1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define IO_RB1_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define IO_RB1_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define IO_RB1_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define IO_RB1_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set IO_RB2 aliases
#define IO_RB2_TRIS                 TRISBbits.TRISB2
#define IO_RB2_LAT                  LATBbits.LATB2
#define IO_RB2_PORT                 PORTBbits.RB2
#define IO_RB2_WPU                  WPUBbits.WPUB2
#define IO_RB2_OD                   ODCONBbits.ODCB2
#define IO_RB2_ANS                  ANSELBbits.ANSELB2
#define IO_RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IO_RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IO_RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IO_RB2_GetValue()           PORTBbits.RB2
#define IO_RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IO_RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IO_RB2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define IO_RB2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define IO_RB2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define IO_RB2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define IO_RB2_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define IO_RB2_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set IO_RB3 aliases
#define IO_RB3_TRIS                 TRISBbits.TRISB3
#define IO_RB3_LAT                  LATBbits.LATB3
#define IO_RB3_PORT                 PORTBbits.RB3
#define IO_RB3_WPU                  WPUBbits.WPUB3
#define IO_RB3_OD                   ODCONBbits.ODCB3
#define IO_RB3_ANS                  ANSELBbits.ANSELB3
#define IO_RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define IO_RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define IO_RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define IO_RB3_GetValue()           PORTBbits.RB3
#define IO_RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define IO_RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define IO_RB3_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define IO_RB3_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define IO_RB3_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define IO_RB3_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define IO_RB3_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define IO_RB3_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set IO_RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.ODCB4
#define IO_RB4_ANS                  ANSELBbits.ANSELB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set IO_RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_WPU                  WPUBbits.WPUB5
#define IO_RB5_OD                   ODCONBbits.ODCB5
#define IO_RB5_ANS                  ANSELBbits.ANSELB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set IO_RB6 aliases
#define IO_RB6_TRIS                 TRISBbits.TRISB6
#define IO_RB6_LAT                  LATBbits.LATB6
#define IO_RB6_PORT                 PORTBbits.RB6
#define IO_RB6_WPU                  WPUBbits.WPUB6
#define IO_RB6_OD                   ODCONBbits.ODCB6
#define IO_RB6_ANS                  ANSELBbits.ANSELB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define IO_RB6_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define IO_RB6_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define IO_RB6_SetAnalogMode()      do { ANSELBbits.ANSELB6 = 1; } while(0)
#define IO_RB6_SetDigitalMode()     do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS                 TRISBbits.TRISB7
#define IO_RB7_LAT                  LATBbits.LATB7
#define IO_RB7_PORT                 PORTBbits.RB7
#define IO_RB7_WPU                  WPUBbits.WPUB7
#define IO_RB7_OD                   ODCONBbits.ODCB7
#define IO_RB7_ANS                  ANSELBbits.ANSELB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define IO_RB7_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define IO_RB7_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define IO_RB7_SetAnalogMode()      do { ANSELBbits.ANSELB7 = 1; } while(0)
#define IO_RB7_SetDigitalMode()     do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set IO_RC0 aliases
#define IO_RC0_TRIS                 TRISCbits.TRISC0
#define IO_RC0_LAT                  LATCbits.LATC0
#define IO_RC0_PORT                 PORTCbits.RC0
#define IO_RC0_WPU                  WPUCbits.WPUC0
#define IO_RC0_OD                   ODCONCbits.ODCC0
#define IO_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RC0_GetValue()           PORTCbits.RC0
#define IO_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IO_RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define IO_RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define IO_RC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define IO_RC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)

// get/set IO_RC1 aliases
#define IO_RC1_TRIS                 TRISCbits.TRISC1
#define IO_RC1_LAT                  LATCbits.LATC1
#define IO_RC1_PORT                 PORTCbits.RC1
#define IO_RC1_WPU                  WPUCbits.WPUC1
#define IO_RC1_OD                   ODCONCbits.ODCC1
#define IO_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_RC1_GetValue()           PORTCbits.RC1
#define IO_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define IO_RC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define IO_RC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define IO_RC1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define IO_RC1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)

// get/set IO_RC2 aliases
#define IO_RC2_TRIS                 TRISCbits.TRISC2
#define IO_RC2_LAT                  LATCbits.LATC2
#define IO_RC2_PORT                 PORTCbits.RC2
#define IO_RC2_WPU                  WPUCbits.WPUC2
#define IO_RC2_OD                   ODCONCbits.ODCC2
#define IO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_GetValue()           PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_RC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define IO_RC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define IO_RC2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define IO_RC2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)

// get/set IO_RC3 aliases
#define IO_RC3_TRIS                 TRISCbits.TRISC3
#define IO_RC3_LAT                  LATCbits.LATC3
#define IO_RC3_PORT                 PORTCbits.RC3
#define IO_RC3_WPU                  WPUCbits.WPUC3
#define IO_RC3_OD                   ODCONCbits.ODCC3
#define IO_RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define IO_RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define IO_RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define IO_RC3_GetValue()           PORTCbits.RC3
#define IO_RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define IO_RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define IO_RC3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define IO_RC3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define IO_RC3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define IO_RC3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)

// get/set IO_RC4 aliases
#define IO_RC4_TRIS                 TRISCbits.TRISC4
#define IO_RC4_LAT                  LATCbits.LATC4
#define IO_RC4_PORT                 PORTCbits.RC4
#define IO_RC4_WPU                  WPUCbits.WPUC4
#define IO_RC4_OD                   ODCONCbits.ODCC4
#define IO_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_RC4_GetValue()           PORTCbits.RC4
#define IO_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_RC4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define IO_RC4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define IO_RC4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define IO_RC4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)

// get/set IO_RC5 aliases
#define IO_RC5_TRIS                 TRISCbits.TRISC5
#define IO_RC5_LAT                  LATCbits.LATC5
#define IO_RC5_PORT                 PORTCbits.RC5
#define IO_RC5_WPU                  WPUCbits.WPUC5
#define IO_RC5_OD                   ODCONCbits.ODCC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)

// get/set SDA1 aliases
#define SDA1_TRIS                 TRISCbits.TRISC6
#define SDA1_LAT                  LATCbits.LATC6
#define SDA1_PORT                 PORTCbits.RC6
#define SDA1_WPU                  WPUCbits.WPUC6
#define SDA1_OD                   ODCONCbits.ODCC6
#define SDA1_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SDA1_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SDA1_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SDA1_GetValue()           PORTCbits.RC6
#define SDA1_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS                 TRISCbits.TRISC7
#define SCL1_LAT                  LATCbits.LATC7
#define SCL1_PORT                 PORTCbits.RC7
#define SCL1_WPU                  WPUCbits.WPUC7
#define SCL1_OD                   ODCONCbits.ODCC7
#define SCL1_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define SCL1_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define SCL1_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define SCL1_GetValue()           PORTCbits.RC7
#define SCL1_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)

// get/set IO_RD0 aliases
#define IO_RD0_TRIS                 TRISDbits.TRISD0
#define IO_RD0_LAT                  LATDbits.LATD0
#define IO_RD0_PORT                 PORTDbits.RD0
#define IO_RD0_WPU                  WPUDbits.WPUD0
#define IO_RD0_OD                   ODCONDbits.ODCD0
#define IO_RD0_ANS                  ANSELDbits.ANSELD0
#define IO_RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define IO_RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define IO_RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define IO_RD0_GetValue()           PORTDbits.RD0
#define IO_RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define IO_RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define IO_RD0_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define IO_RD0_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define IO_RD0_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define IO_RD0_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define IO_RD0_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define IO_RD0_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set IO_RD1 aliases
#define IO_RD1_TRIS                 TRISDbits.TRISD1
#define IO_RD1_LAT                  LATDbits.LATD1
#define IO_RD1_PORT                 PORTDbits.RD1
#define IO_RD1_WPU                  WPUDbits.WPUD1
#define IO_RD1_OD                   ODCONDbits.ODCD1
#define IO_RD1_ANS                  ANSELDbits.ANSELD1
#define IO_RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define IO_RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define IO_RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define IO_RD1_GetValue()           PORTDbits.RD1
#define IO_RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define IO_RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define IO_RD1_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define IO_RD1_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define IO_RD1_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define IO_RD1_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define IO_RD1_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define IO_RD1_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set IO_RD2 aliases
#define IO_RD2_TRIS                 TRISDbits.TRISD2
#define IO_RD2_LAT                  LATDbits.LATD2
#define IO_RD2_PORT                 PORTDbits.RD2
#define IO_RD2_WPU                  WPUDbits.WPUD2
#define IO_RD2_OD                   ODCONDbits.ODCD2
#define IO_RD2_ANS                  ANSELDbits.ANSELD2
#define IO_RD2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define IO_RD2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define IO_RD2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define IO_RD2_GetValue()           PORTDbits.RD2
#define IO_RD2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define IO_RD2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define IO_RD2_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define IO_RD2_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define IO_RD2_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define IO_RD2_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define IO_RD2_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define IO_RD2_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set IO_RD3 aliases
#define IO_RD3_TRIS                 TRISDbits.TRISD3
#define IO_RD3_LAT                  LATDbits.LATD3
#define IO_RD3_PORT                 PORTDbits.RD3
#define IO_RD3_WPU                  WPUDbits.WPUD3
#define IO_RD3_OD                   ODCONDbits.ODCD3
#define IO_RD3_ANS                  ANSELDbits.ANSELD3
#define IO_RD3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define IO_RD3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define IO_RD3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define IO_RD3_GetValue()           PORTDbits.RD3
#define IO_RD3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define IO_RD3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define IO_RD3_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define IO_RD3_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define IO_RD3_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define IO_RD3_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define IO_RD3_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define IO_RD3_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set IO_RD4 aliases
#define IO_RD4_TRIS                 TRISDbits.TRISD4
#define IO_RD4_LAT                  LATDbits.LATD4
#define IO_RD4_PORT                 PORTDbits.RD4
#define IO_RD4_WPU                  WPUDbits.WPUD4
#define IO_RD4_OD                   ODCONDbits.ODCD4
#define IO_RD4_ANS                  ANSELDbits.ANSELD4
#define IO_RD4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define IO_RD4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define IO_RD4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define IO_RD4_GetValue()           PORTDbits.RD4
#define IO_RD4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define IO_RD4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define IO_RD4_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define IO_RD4_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define IO_RD4_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define IO_RD4_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define IO_RD4_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define IO_RD4_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set IO_RD5 aliases
#define IO_RD5_TRIS                 TRISDbits.TRISD5
#define IO_RD5_LAT                  LATDbits.LATD5
#define IO_RD5_PORT                 PORTDbits.RD5
#define IO_RD5_WPU                  WPUDbits.WPUD5
#define IO_RD5_OD                   ODCONDbits.ODCD5
#define IO_RD5_ANS                  ANSELDbits.ANSELD5
#define IO_RD5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define IO_RD5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define IO_RD5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define IO_RD5_GetValue()           PORTDbits.RD5
#define IO_RD5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define IO_RD5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define IO_RD5_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define IO_RD5_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define IO_RD5_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define IO_RD5_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define IO_RD5_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define IO_RD5_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set IO_RD6 aliases
#define IO_RD6_TRIS                 TRISDbits.TRISD6
#define IO_RD6_LAT                  LATDbits.LATD6
#define IO_RD6_PORT                 PORTDbits.RD6
#define IO_RD6_WPU                  WPUDbits.WPUD6
#define IO_RD6_OD                   ODCONDbits.ODCD6
#define IO_RD6_ANS                  ANSELDbits.ANSELD6
#define IO_RD6_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define IO_RD6_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define IO_RD6_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define IO_RD6_GetValue()           PORTDbits.RD6
#define IO_RD6_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define IO_RD6_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define IO_RD6_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define IO_RD6_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define IO_RD6_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define IO_RD6_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define IO_RD6_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define IO_RD6_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set IO_RD7 aliases
#define IO_RD7_TRIS                 TRISDbits.TRISD7
#define IO_RD7_LAT                  LATDbits.LATD7
#define IO_RD7_PORT                 PORTDbits.RD7
#define IO_RD7_WPU                  WPUDbits.WPUD7
#define IO_RD7_OD                   ODCONDbits.ODCD7
#define IO_RD7_ANS                  ANSELDbits.ANSELD7
#define IO_RD7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define IO_RD7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define IO_RD7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define IO_RD7_GetValue()           PORTDbits.RD7
#define IO_RD7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define IO_RD7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define IO_RD7_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define IO_RD7_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define IO_RD7_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define IO_RD7_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define IO_RD7_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define IO_RD7_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

// get/set IO_RE0 aliases
#define IO_RE0_TRIS                 TRISEbits.TRISE0
#define IO_RE0_LAT                  LATEbits.LATE0
#define IO_RE0_PORT                 PORTEbits.RE0
#define IO_RE0_WPU                  WPUEbits.WPUE0
#define IO_RE0_OD                   ODCONEbits.ODCE0
#define IO_RE0_ANS                  ANSELEbits.ANSELE0
#define IO_RE0_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define IO_RE0_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define IO_RE0_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define IO_RE0_GetValue()           PORTEbits.RE0
#define IO_RE0_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define IO_RE0_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define IO_RE0_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define IO_RE0_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define IO_RE0_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define IO_RE0_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define IO_RE0_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define IO_RE0_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set IO_RE1 aliases
#define IO_RE1_TRIS                 TRISEbits.TRISE1
#define IO_RE1_LAT                  LATEbits.LATE1
#define IO_RE1_PORT                 PORTEbits.RE1
#define IO_RE1_WPU                  WPUEbits.WPUE1
#define IO_RE1_OD                   ODCONEbits.ODCE1
#define IO_RE1_ANS                  ANSELEbits.ANSELE1
#define IO_RE1_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define IO_RE1_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define IO_RE1_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define IO_RE1_GetValue()           PORTEbits.RE1
#define IO_RE1_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define IO_RE1_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define IO_RE1_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define IO_RE1_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define IO_RE1_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define IO_RE1_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define IO_RE1_SetAnalogMode()      do { ANSELEbits.ANSELE1 = 1; } while(0)
#define IO_RE1_SetDigitalMode()     do { ANSELEbits.ANSELE1 = 0; } while(0)

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

// get/set IO_RE3 aliases
#define IO_RE3_TRIS                 TRISEbits.TRISE3
#define IO_RE3_LAT                  LATEbits.LATE3
#define IO_RE3_PORT                 PORTEbits.RE3
#define IO_RE3_WPU                  WPUEbits.WPUE3
#define IO_RE3_OD                   ODCONEbits.ODCE3
#define IO_RE3_ANS                  ANSELEbits.ANSELE3
#define IO_RE3_SetHigh()            do { LATEbits.LATE3 = 1; } while(0)
#define IO_RE3_SetLow()             do { LATEbits.LATE3 = 0; } while(0)
#define IO_RE3_Toggle()             do { LATEbits.LATE3 = ~LATEbits.LATE3; } while(0)
#define IO_RE3_GetValue()           PORTEbits.RE3
#define IO_RE3_SetDigitalInput()    do { TRISEbits.TRISE3 = 1; } while(0)
#define IO_RE3_SetDigitalOutput()   do { TRISEbits.TRISE3 = 0; } while(0)
#define IO_RE3_SetPullup()          do { WPUEbits.WPUE3 = 1; } while(0)
#define IO_RE3_ResetPullup()        do { WPUEbits.WPUE3 = 0; } while(0)
#define IO_RE3_SetPushPull()        do { ODCONEbits.ODCE3 = 0; } while(0)
#define IO_RE3_SetOpenDrain()       do { ODCONEbits.ODCE3 = 1; } while(0)
#define IO_RE3_SetAnalogMode()      do { ANSELEbits.ANSELE3 = 1; } while(0)
#define IO_RE3_SetDigitalMode()     do { ANSELEbits.ANSELE3 = 0; } while(0)

// get/set IO_RE4 aliases
#define IO_RE4_TRIS                 TRISEbits.TRISE4
#define IO_RE4_LAT                  LATEbits.LATE4
#define IO_RE4_PORT                 PORTEbits.RE4
#define IO_RE4_WPU                  WPUEbits.WPUE4
#define IO_RE4_OD                   ODCONEbits.ODCE4
#define IO_RE4_ANS                  ANSELEbits.ANSELE4
#define IO_RE4_SetHigh()            do { LATEbits.LATE4 = 1; } while(0)
#define IO_RE4_SetLow()             do { LATEbits.LATE4 = 0; } while(0)
#define IO_RE4_Toggle()             do { LATEbits.LATE4 = ~LATEbits.LATE4; } while(0)
#define IO_RE4_GetValue()           PORTEbits.RE4
#define IO_RE4_SetDigitalInput()    do { TRISEbits.TRISE4 = 1; } while(0)
#define IO_RE4_SetDigitalOutput()   do { TRISEbits.TRISE4 = 0; } while(0)
#define IO_RE4_SetPullup()          do { WPUEbits.WPUE4 = 1; } while(0)
#define IO_RE4_ResetPullup()        do { WPUEbits.WPUE4 = 0; } while(0)
#define IO_RE4_SetPushPull()        do { ODCONEbits.ODCE4 = 0; } while(0)
#define IO_RE4_SetOpenDrain()       do { ODCONEbits.ODCE4 = 1; } while(0)
#define IO_RE4_SetAnalogMode()      do { ANSELEbits.ANSELE4 = 1; } while(0)
#define IO_RE4_SetDigitalMode()     do { ANSELEbits.ANSELE4 = 0; } while(0)

// get/set IO_RE5 aliases
#define IO_RE5_TRIS                 TRISEbits.TRISE5
#define IO_RE5_LAT                  LATEbits.LATE5
#define IO_RE5_PORT                 PORTEbits.RE5
#define IO_RE5_WPU                  WPUEbits.WPUE5
#define IO_RE5_OD                   ODCONEbits.ODCE5
#define IO_RE5_ANS                  ANSELEbits.ANSELE5
#define IO_RE5_SetHigh()            do { LATEbits.LATE5 = 1; } while(0)
#define IO_RE5_SetLow()             do { LATEbits.LATE5 = 0; } while(0)
#define IO_RE5_Toggle()             do { LATEbits.LATE5 = ~LATEbits.LATE5; } while(0)
#define IO_RE5_GetValue()           PORTEbits.RE5
#define IO_RE5_SetDigitalInput()    do { TRISEbits.TRISE5 = 1; } while(0)
#define IO_RE5_SetDigitalOutput()   do { TRISEbits.TRISE5 = 0; } while(0)
#define IO_RE5_SetPullup()          do { WPUEbits.WPUE5 = 1; } while(0)
#define IO_RE5_ResetPullup()        do { WPUEbits.WPUE5 = 0; } while(0)
#define IO_RE5_SetPushPull()        do { ODCONEbits.ODCE5 = 0; } while(0)
#define IO_RE5_SetOpenDrain()       do { ODCONEbits.ODCE5 = 1; } while(0)
#define IO_RE5_SetAnalogMode()      do { ANSELEbits.ANSELE5 = 1; } while(0)
#define IO_RE5_SetDigitalMode()     do { ANSELEbits.ANSELE5 = 0; } while(0)

// get/set IO_RE6 aliases
#define IO_RE6_TRIS                 TRISEbits.TRISE6
#define IO_RE6_LAT                  LATEbits.LATE6
#define IO_RE6_PORT                 PORTEbits.RE6
#define IO_RE6_WPU                  WPUEbits.WPUE6
#define IO_RE6_OD                   ODCONEbits.ODCE6
#define IO_RE6_ANS                  ANSELEbits.ANSELE6
#define IO_RE6_SetHigh()            do { LATEbits.LATE6 = 1; } while(0)
#define IO_RE6_SetLow()             do { LATEbits.LATE6 = 0; } while(0)
#define IO_RE6_Toggle()             do { LATEbits.LATE6 = ~LATEbits.LATE6; } while(0)
#define IO_RE6_GetValue()           PORTEbits.RE6
#define IO_RE6_SetDigitalInput()    do { TRISEbits.TRISE6 = 1; } while(0)
#define IO_RE6_SetDigitalOutput()   do { TRISEbits.TRISE6 = 0; } while(0)
#define IO_RE6_SetPullup()          do { WPUEbits.WPUE6 = 1; } while(0)
#define IO_RE6_ResetPullup()        do { WPUEbits.WPUE6 = 0; } while(0)
#define IO_RE6_SetPushPull()        do { ODCONEbits.ODCE6 = 0; } while(0)
#define IO_RE6_SetOpenDrain()       do { ODCONEbits.ODCE6 = 1; } while(0)
#define IO_RE6_SetAnalogMode()      do { ANSELEbits.ANSELE6 = 1; } while(0)
#define IO_RE6_SetDigitalMode()     do { ANSELEbits.ANSELE6 = 0; } while(0)

// get/set IO_RE7 aliases
#define IO_RE7_TRIS                 TRISEbits.TRISE7
#define IO_RE7_LAT                  LATEbits.LATE7
#define IO_RE7_PORT                 PORTEbits.RE7
#define IO_RE7_WPU                  WPUEbits.WPUE7
#define IO_RE7_OD                   ODCONEbits.ODCE7
#define IO_RE7_ANS                  ANSELEbits.ANSELE7
#define IO_RE7_SetHigh()            do { LATEbits.LATE7 = 1; } while(0)
#define IO_RE7_SetLow()             do { LATEbits.LATE7 = 0; } while(0)
#define IO_RE7_Toggle()             do { LATEbits.LATE7 = ~LATEbits.LATE7; } while(0)
#define IO_RE7_GetValue()           PORTEbits.RE7
#define IO_RE7_SetDigitalInput()    do { TRISEbits.TRISE7 = 1; } while(0)
#define IO_RE7_SetDigitalOutput()   do { TRISEbits.TRISE7 = 0; } while(0)
#define IO_RE7_SetPullup()          do { WPUEbits.WPUE7 = 1; } while(0)
#define IO_RE7_ResetPullup()        do { WPUEbits.WPUE7 = 0; } while(0)
#define IO_RE7_SetPushPull()        do { ODCONEbits.ODCE7 = 0; } while(0)
#define IO_RE7_SetOpenDrain()       do { ODCONEbits.ODCE7 = 1; } while(0)
#define IO_RE7_SetAnalogMode()      do { ANSELEbits.ANSELE7 = 1; } while(0)
#define IO_RE7_SetDigitalMode()     do { ANSELEbits.ANSELE7 = 0; } while(0)

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

// get/set IO_RF4 aliases
#define IO_RF4_TRIS                 TRISFbits.TRISF4
#define IO_RF4_LAT                  LATFbits.LATF4
#define IO_RF4_PORT                 PORTFbits.RF4
#define IO_RF4_WPU                  WPUFbits.WPUF4
#define IO_RF4_OD                   ODCONFbits.ODCF4
#define IO_RF4_ANS                  ANSELFbits.ANSELF4
#define IO_RF4_SetHigh()            do { LATFbits.LATF4 = 1; } while(0)
#define IO_RF4_SetLow()             do { LATFbits.LATF4 = 0; } while(0)
#define IO_RF4_Toggle()             do { LATFbits.LATF4 = ~LATFbits.LATF4; } while(0)
#define IO_RF4_GetValue()           PORTFbits.RF4
#define IO_RF4_SetDigitalInput()    do { TRISFbits.TRISF4 = 1; } while(0)
#define IO_RF4_SetDigitalOutput()   do { TRISFbits.TRISF4 = 0; } while(0)
#define IO_RF4_SetPullup()          do { WPUFbits.WPUF4 = 1; } while(0)
#define IO_RF4_ResetPullup()        do { WPUFbits.WPUF4 = 0; } while(0)
#define IO_RF4_SetPushPull()        do { ODCONFbits.ODCF4 = 0; } while(0)
#define IO_RF4_SetOpenDrain()       do { ODCONFbits.ODCF4 = 1; } while(0)
#define IO_RF4_SetAnalogMode()      do { ANSELFbits.ANSELF4 = 1; } while(0)
#define IO_RF4_SetDigitalMode()     do { ANSELFbits.ANSELF4 = 0; } while(0)

// get/set IO_RF5 aliases
#define IO_RF5_TRIS                 TRISFbits.TRISF5
#define IO_RF5_LAT                  LATFbits.LATF5
#define IO_RF5_PORT                 PORTFbits.RF5
#define IO_RF5_WPU                  WPUFbits.WPUF5
#define IO_RF5_OD                   ODCONFbits.ODCF5
#define IO_RF5_ANS                  ANSELFbits.ANSELF5
#define IO_RF5_SetHigh()            do { LATFbits.LATF5 = 1; } while(0)
#define IO_RF5_SetLow()             do { LATFbits.LATF5 = 0; } while(0)
#define IO_RF5_Toggle()             do { LATFbits.LATF5 = ~LATFbits.LATF5; } while(0)
#define IO_RF5_GetValue()           PORTFbits.RF5
#define IO_RF5_SetDigitalInput()    do { TRISFbits.TRISF5 = 1; } while(0)
#define IO_RF5_SetDigitalOutput()   do { TRISFbits.TRISF5 = 0; } while(0)
#define IO_RF5_SetPullup()          do { WPUFbits.WPUF5 = 1; } while(0)
#define IO_RF5_ResetPullup()        do { WPUFbits.WPUF5 = 0; } while(0)
#define IO_RF5_SetPushPull()        do { ODCONFbits.ODCF5 = 0; } while(0)
#define IO_RF5_SetOpenDrain()       do { ODCONFbits.ODCF5 = 1; } while(0)
#define IO_RF5_SetAnalogMode()      do { ANSELFbits.ANSELF5 = 1; } while(0)
#define IO_RF5_SetDigitalMode()     do { ANSELFbits.ANSELF5 = 0; } while(0)

// get/set IO_RF6 aliases
#define IO_RF6_TRIS                 TRISFbits.TRISF6
#define IO_RF6_LAT                  LATFbits.LATF6
#define IO_RF6_PORT                 PORTFbits.RF6
#define IO_RF6_WPU                  WPUFbits.WPUF6
#define IO_RF6_OD                   ODCONFbits.ODCF6
#define IO_RF6_ANS                  ANSELFbits.ANSELF6
#define IO_RF6_SetHigh()            do { LATFbits.LATF6 = 1; } while(0)
#define IO_RF6_SetLow()             do { LATFbits.LATF6 = 0; } while(0)
#define IO_RF6_Toggle()             do { LATFbits.LATF6 = ~LATFbits.LATF6; } while(0)
#define IO_RF6_GetValue()           PORTFbits.RF6
#define IO_RF6_SetDigitalInput()    do { TRISFbits.TRISF6 = 1; } while(0)
#define IO_RF6_SetDigitalOutput()   do { TRISFbits.TRISF6 = 0; } while(0)
#define IO_RF6_SetPullup()          do { WPUFbits.WPUF6 = 1; } while(0)
#define IO_RF6_ResetPullup()        do { WPUFbits.WPUF6 = 0; } while(0)
#define IO_RF6_SetPushPull()        do { ODCONFbits.ODCF6 = 0; } while(0)
#define IO_RF6_SetOpenDrain()       do { ODCONFbits.ODCF6 = 1; } while(0)
#define IO_RF6_SetAnalogMode()      do { ANSELFbits.ANSELF6 = 1; } while(0)
#define IO_RF6_SetDigitalMode()     do { ANSELFbits.ANSELF6 = 0; } while(0)

// get/set IO_RF7 aliases
#define IO_RF7_TRIS                 TRISFbits.TRISF7
#define IO_RF7_LAT                  LATFbits.LATF7
#define IO_RF7_PORT                 PORTFbits.RF7
#define IO_RF7_WPU                  WPUFbits.WPUF7
#define IO_RF7_OD                   ODCONFbits.ODCF7
#define IO_RF7_ANS                  ANSELFbits.ANSELF7
#define IO_RF7_SetHigh()            do { LATFbits.LATF7 = 1; } while(0)
#define IO_RF7_SetLow()             do { LATFbits.LATF7 = 0; } while(0)
#define IO_RF7_Toggle()             do { LATFbits.LATF7 = ~LATFbits.LATF7; } while(0)
#define IO_RF7_GetValue()           PORTFbits.RF7
#define IO_RF7_SetDigitalInput()    do { TRISFbits.TRISF7 = 1; } while(0)
#define IO_RF7_SetDigitalOutput()   do { TRISFbits.TRISF7 = 0; } while(0)
#define IO_RF7_SetPullup()          do { WPUFbits.WPUF7 = 1; } while(0)
#define IO_RF7_ResetPullup()        do { WPUFbits.WPUF7 = 0; } while(0)
#define IO_RF7_SetPushPull()        do { ODCONFbits.ODCF7 = 0; } while(0)
#define IO_RF7_SetOpenDrain()       do { ODCONFbits.ODCF7 = 1; } while(0)
#define IO_RF7_SetAnalogMode()      do { ANSELFbits.ANSELF7 = 1; } while(0)
#define IO_RF7_SetDigitalMode()     do { ANSELFbits.ANSELF7 = 0; } while(0)

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

// get/set IO_RG2 aliases
#define IO_RG2_TRIS                 TRISGbits.TRISG2
#define IO_RG2_LAT                  LATGbits.LATG2
#define IO_RG2_PORT                 PORTGbits.RG2
#define IO_RG2_WPU                  WPUGbits.WPUG2
#define IO_RG2_OD                   ODCONGbits.ODCG2
#define IO_RG2_ANS                  ANSELGbits.ANSELG2
#define IO_RG2_SetHigh()            do { LATGbits.LATG2 = 1; } while(0)
#define IO_RG2_SetLow()             do { LATGbits.LATG2 = 0; } while(0)
#define IO_RG2_Toggle()             do { LATGbits.LATG2 = ~LATGbits.LATG2; } while(0)
#define IO_RG2_GetValue()           PORTGbits.RG2
#define IO_RG2_SetDigitalInput()    do { TRISGbits.TRISG2 = 1; } while(0)
#define IO_RG2_SetDigitalOutput()   do { TRISGbits.TRISG2 = 0; } while(0)
#define IO_RG2_SetPullup()          do { WPUGbits.WPUG2 = 1; } while(0)
#define IO_RG2_ResetPullup()        do { WPUGbits.WPUG2 = 0; } while(0)
#define IO_RG2_SetPushPull()        do { ODCONGbits.ODCG2 = 0; } while(0)
#define IO_RG2_SetOpenDrain()       do { ODCONGbits.ODCG2 = 1; } while(0)
#define IO_RG2_SetAnalogMode()      do { ANSELGbits.ANSELG2 = 1; } while(0)
#define IO_RG2_SetDigitalMode()     do { ANSELGbits.ANSELG2 = 0; } while(0)

// get/set IO_RG3 aliases
#define IO_RG3_TRIS                 TRISGbits.TRISG3
#define IO_RG3_LAT                  LATGbits.LATG3
#define IO_RG3_PORT                 PORTGbits.RG3
#define IO_RG3_WPU                  WPUGbits.WPUG3
#define IO_RG3_OD                   ODCONGbits.ODCG3
#define IO_RG3_ANS                  ANSELGbits.ANSELG3
#define IO_RG3_SetHigh()            do { LATGbits.LATG3 = 1; } while(0)
#define IO_RG3_SetLow()             do { LATGbits.LATG3 = 0; } while(0)
#define IO_RG3_Toggle()             do { LATGbits.LATG3 = ~LATGbits.LATG3; } while(0)
#define IO_RG3_GetValue()           PORTGbits.RG3
#define IO_RG3_SetDigitalInput()    do { TRISGbits.TRISG3 = 1; } while(0)
#define IO_RG3_SetDigitalOutput()   do { TRISGbits.TRISG3 = 0; } while(0)
#define IO_RG3_SetPullup()          do { WPUGbits.WPUG3 = 1; } while(0)
#define IO_RG3_ResetPullup()        do { WPUGbits.WPUG3 = 0; } while(0)
#define IO_RG3_SetPushPull()        do { ODCONGbits.ODCG3 = 0; } while(0)
#define IO_RG3_SetOpenDrain()       do { ODCONGbits.ODCG3 = 1; } while(0)
#define IO_RG3_SetAnalogMode()      do { ANSELGbits.ANSELG3 = 1; } while(0)
#define IO_RG3_SetDigitalMode()     do { ANSELGbits.ANSELG3 = 0; } while(0)

// get/set IO_RG4 aliases
#define IO_RG4_TRIS                 TRISGbits.TRISG4
#define IO_RG4_LAT                  LATGbits.LATG4
#define IO_RG4_PORT                 PORTGbits.RG4
#define IO_RG4_WPU                  WPUGbits.WPUG4
#define IO_RG4_OD                   ODCONGbits.ODCG4
#define IO_RG4_ANS                  ANSELGbits.ANSELG4
#define IO_RG4_SetHigh()            do { LATGbits.LATG4 = 1; } while(0)
#define IO_RG4_SetLow()             do { LATGbits.LATG4 = 0; } while(0)
#define IO_RG4_Toggle()             do { LATGbits.LATG4 = ~LATGbits.LATG4; } while(0)
#define IO_RG4_GetValue()           PORTGbits.RG4
#define IO_RG4_SetDigitalInput()    do { TRISGbits.TRISG4 = 1; } while(0)
#define IO_RG4_SetDigitalOutput()   do { TRISGbits.TRISG4 = 0; } while(0)
#define IO_RG4_SetPullup()          do { WPUGbits.WPUG4 = 1; } while(0)
#define IO_RG4_ResetPullup()        do { WPUGbits.WPUG4 = 0; } while(0)
#define IO_RG4_SetPushPull()        do { ODCONGbits.ODCG4 = 0; } while(0)
#define IO_RG4_SetOpenDrain()       do { ODCONGbits.ODCG4 = 1; } while(0)
#define IO_RG4_SetAnalogMode()      do { ANSELGbits.ANSELG4 = 1; } while(0)
#define IO_RG4_SetDigitalMode()     do { ANSELGbits.ANSELG4 = 0; } while(0)

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

// get/set IO_RH0 aliases
#define IO_RH0_TRIS                 TRISHbits.TRISH0
#define IO_RH0_LAT                  LATHbits.LATH0
#define IO_RH0_PORT                 PORTHbits.RH0
#define IO_RH0_WPU                  WPUHbits.WPUH0
#define IO_RH0_OD                   ODCONHbits.ODCH0
#define IO_RH0_SetHigh()            do { LATHbits.LATH0 = 1; } while(0)
#define IO_RH0_SetLow()             do { LATHbits.LATH0 = 0; } while(0)
#define IO_RH0_Toggle()             do { LATHbits.LATH0 = ~LATHbits.LATH0; } while(0)
#define IO_RH0_GetValue()           PORTHbits.RH0
#define IO_RH0_SetDigitalInput()    do { TRISHbits.TRISH0 = 1; } while(0)
#define IO_RH0_SetDigitalOutput()   do { TRISHbits.TRISH0 = 0; } while(0)
#define IO_RH0_SetPullup()          do { WPUHbits.WPUH0 = 1; } while(0)
#define IO_RH0_ResetPullup()        do { WPUHbits.WPUH0 = 0; } while(0)
#define IO_RH0_SetPushPull()        do { ODCONHbits.ODCH0 = 0; } while(0)
#define IO_RH0_SetOpenDrain()       do { ODCONHbits.ODCH0 = 1; } while(0)

// get/set IO_RH1 aliases
#define IO_RH1_TRIS                 TRISHbits.TRISH1
#define IO_RH1_LAT                  LATHbits.LATH1
#define IO_RH1_PORT                 PORTHbits.RH1
#define IO_RH1_WPU                  WPUHbits.WPUH1
#define IO_RH1_OD                   ODCONHbits.ODCH1
#define IO_RH1_SetHigh()            do { LATHbits.LATH1 = 1; } while(0)
#define IO_RH1_SetLow()             do { LATHbits.LATH1 = 0; } while(0)
#define IO_RH1_Toggle()             do { LATHbits.LATH1 = ~LATHbits.LATH1; } while(0)
#define IO_RH1_GetValue()           PORTHbits.RH1
#define IO_RH1_SetDigitalInput()    do { TRISHbits.TRISH1 = 1; } while(0)
#define IO_RH1_SetDigitalOutput()   do { TRISHbits.TRISH1 = 0; } while(0)
#define IO_RH1_SetPullup()          do { WPUHbits.WPUH1 = 1; } while(0)
#define IO_RH1_ResetPullup()        do { WPUHbits.WPUH1 = 0; } while(0)
#define IO_RH1_SetPushPull()        do { ODCONHbits.ODCH1 = 0; } while(0)
#define IO_RH1_SetOpenDrain()       do { ODCONHbits.ODCH1 = 1; } while(0)

// get/set IO_RH2 aliases
#define IO_RH2_TRIS                 TRISHbits.TRISH2
#define IO_RH2_LAT                  LATHbits.LATH2
#define IO_RH2_PORT                 PORTHbits.RH2
#define IO_RH2_WPU                  WPUHbits.WPUH2
#define IO_RH2_OD                   ODCONHbits.ODCH2
#define IO_RH2_SetHigh()            do { LATHbits.LATH2 = 1; } while(0)
#define IO_RH2_SetLow()             do { LATHbits.LATH2 = 0; } while(0)
#define IO_RH2_Toggle()             do { LATHbits.LATH2 = ~LATHbits.LATH2; } while(0)
#define IO_RH2_GetValue()           PORTHbits.RH2
#define IO_RH2_SetDigitalInput()    do { TRISHbits.TRISH2 = 1; } while(0)
#define IO_RH2_SetDigitalOutput()   do { TRISHbits.TRISH2 = 0; } while(0)
#define IO_RH2_SetPullup()          do { WPUHbits.WPUH2 = 1; } while(0)
#define IO_RH2_ResetPullup()        do { WPUHbits.WPUH2 = 0; } while(0)
#define IO_RH2_SetPushPull()        do { ODCONHbits.ODCH2 = 0; } while(0)
#define IO_RH2_SetOpenDrain()       do { ODCONHbits.ODCH2 = 1; } while(0)

// get/set IO_RH3 aliases
#define IO_RH3_TRIS                 TRISHbits.TRISH3
#define IO_RH3_LAT                  LATHbits.LATH3
#define IO_RH3_PORT                 PORTHbits.RH3
#define IO_RH3_WPU                  WPUHbits.WPUH3
#define IO_RH3_OD                   ODCONHbits.ODCH3
#define IO_RH3_SetHigh()            do { LATHbits.LATH3 = 1; } while(0)
#define IO_RH3_SetLow()             do { LATHbits.LATH3 = 0; } while(0)
#define IO_RH3_Toggle()             do { LATHbits.LATH3 = ~LATHbits.LATH3; } while(0)
#define IO_RH3_GetValue()           PORTHbits.RH3
#define IO_RH3_SetDigitalInput()    do { TRISHbits.TRISH3 = 1; } while(0)
#define IO_RH3_SetDigitalOutput()   do { TRISHbits.TRISH3 = 0; } while(0)
#define IO_RH3_SetPullup()          do { WPUHbits.WPUH3 = 1; } while(0)
#define IO_RH3_ResetPullup()        do { WPUHbits.WPUH3 = 0; } while(0)
#define IO_RH3_SetPushPull()        do { ODCONHbits.ODCH3 = 0; } while(0)
#define IO_RH3_SetOpenDrain()       do { ODCONHbits.ODCH3 = 1; } while(0)

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