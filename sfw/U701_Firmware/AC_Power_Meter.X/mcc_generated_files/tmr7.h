/**
  TMR7 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr7.h

  @Summary
    This is the generated header file for the TMR7 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for TMR7.
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

#ifndef TMR7_H
#define TMR7_H

/**
  Section: Included Files
*/

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif


/**
  Section: TMR7 APIs
*/

/**
  @Summary
    Initializes the TMR7

  @Description
    This routine initializes the TMR7.
    This routine must be called before any other TMR7 routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    main()
    {
        // Initialize TMR7 module
        TMR7_Initialize();

        // Do something else...
    }
    </code>
*/
void TMR7_Initialize(void);

/**
  @Summary
    This function starts the TMR7.

  @Description
    This function starts the TMR7 operation.
    This function must be called after the initialization of TMR7.

  @Preconditions
    Initialize  the TMR7 before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize TMR7 module

    // Start TMR7
    TMR7_StartTimer();

    // Do something else...
    </code>
*/
void TMR7_StartTimer(void);

/**
  @Summary
    This function stops the TMR7.

  @Description
    This function stops the TMR7 operation.
    This function must be called after the start of TMR7.

  @Preconditions
    Initialize  the TMR7 before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize TMR7 module

    // Start TMR7
    TMR7_StartTimer();

    // Do something else...

    // Stop TMR7;
    TMR7_StopTimer();
    </code>
*/
void TMR7_StopTimer(void);

/**
  @Summary
    Reads the TMR7 register.

  @Description
    This function reads the TMR7 register value and return it.

  @Preconditions
    Initialize  the TMR7 before calling this function.

  @Param
    None

  @Returns
    This function returns the current value of TMR7 register.

  @Example
    <code>
    // Initialize TMR7 module

    // Start TMR7
    TMR7_StartTimer();

    // Read the current value of TMR7
    if(0 == TMR7_ReadTimer())
    {
        // Do something else...

        // Reload the TMR value
        TMR7_Reload();
    }
    </code>
*/
uint16_t TMR7_ReadTimer(void);

/**
  @Summary
    Writes the TMR7 register.

  @Description
    This function writes the TMR7 register.
    This function must be called after the initialization of TMR7.

  @Preconditions
    Initialize  the TMR7 before calling this function.

  @Param
    timerVal - Value to write into TMR7 register.

  @Returns
    None

  @Example
    <code>
    #define PERIOD 0x80
    #define ZERO   0x00

    while(1)
    {
        // Read the TMR7 register
        if(ZERO == TMR7_ReadTimer())
        {
            // Do something else...

            // Write the TMR7 register
            TMR7_WriteTimer(PERIOD);
        }

        // Do something else...
    }
    </code>
*/
void TMR7_WriteTimer(uint16_t timerVal);

/**
  @Summary
    Reload the TMR7 register.

  @Description
    This function reloads the TMR7 register.
    This function must be called to write initial value into TMR7 register.

  @Preconditions
    Initialize  the TMR7 before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    while(1)
    {
        if(TMR7IF)
        {
            // Do something else...

            // clear the TMR7 interrupt flag
            TMR7IF = 0;

            // Reload the initial value of TMR7
            TMR7_Reload();
        }
    }
    </code>
*/
void TMR7_Reload(void);

/**
  @Summary
    Starts the single pulse acquisition in TMR7 gate operation.

  @Description
    This function starts the single pulse acquisition in TMR7 gate operation.
    This function must be used when the TMR7 gate is enabled.

  @Preconditions
    Initialize  the TMR7 with gate enable before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    uint16_t xVal;
    uint16_t yVal;

    // enable TMR7 singlepulse mode
    TMR7_StartSinglePulseAcquistion();

    // check TMR7 gate status
    if(TMR7_CheckGateValueStatus()== 0)
        xVal = TMR7_ReadTimer();

    // wait untill gate interrupt occured
    while(TMR7GIF == 0)
    {
    }

    yVal = TMR7_ReadTimer();
    </code>
*/
void TMR7_StartSinglePulseAcquisition(void);

/**
  @Summary
    Check the current state of Timer1 gate.

  @Description
    This function reads the TMR7 gate value and return it.
    This function must be used when the TMR7 gate is enabled.

  @Preconditions
    Initialize  the TMR7 with gate enable before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    uint16_t xVal;
    uint16_t yVal;

    // enable TMR7 singlepulse mode
    TMR7_StartSinglePulseAcquistion();

    // check TMR7 gate status
    if(TMR7_CheckGateValueStatus()== 0)
        xVal = TMR7_ReadTimer();

    // wait untill gate interrupt occured
    while(TMR7IF == 0)
    {
    }

    yVal = TMR7_ReadTimer();
    </code>
*/
uint8_t TMR7_CheckGateValueStatus(void);

/**
  @Summary
    Timer Interrupt Service Routine

  @Description
    Timer Interrupt Service Routine is called by the Interrupt Manager.

  @Preconditions
    Initialize  the TMR7 module with interrupt before calling this ISR.

  @Param
    None

  @Returns
    None
*/
void TMR7_ISR(void);

/**
  @Summary
    Set Timer Interrupt Handler

  @Description
    This sets the function to be called during the ISR

  @Preconditions
    Initialize  the TMR7 module with interrupt before calling this.

  @Param
    Address of function to be set

  @Returns
    None
*/
 void TMR7_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Timer Interrupt Handler

  @Description
    This is a function pointer to the function that will be called during the ISR

  @Preconditions
    Initialize  the TMR7 module with interrupt before calling this isr.

  @Param
    None

  @Returns
    None
*/
extern void (*TMR7_InterruptHandler)(void);

/**
  @Summary
    Default Timer Interrupt Handler

  @Description
    This is the default Interrupt Handler function

  @Preconditions
    Initialize  the TMR7 module with interrupt before calling this isr.

  @Param
    None

  @Returns
    None
*/
void TMR7_DefaultInterruptHandler(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // TMR7_H
/**
 End of File
*/
