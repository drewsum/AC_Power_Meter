/**
  HLVD Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    hlvd.h

  @Summary
    This is the generated header file for the HLVD driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs 

  @Description
    This header file provides APIs for driver for HLVD.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18LF67K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15
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

#ifndef HLVD_H
#define HLVD_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif

/**
  Section: Enum Declarations
*/

/** HLVD Trip points
 
 @Summary 
   This defines trip point values.
 
 @Description
   This defines trip point values.

 */
typedef enum
{
    HLVD_TRIP_POINT_1p85v = 0, // 0x0
    HLVD_TRIP_POINT_2p06v = 1, // 0x1
    HLVD_TRIP_POINT_2p26v = 2, // 0x2
    HLVD_TRIP_POINT_2p47v = 3, // 0x3
    HLVD_TRIP_POINT_2p57v = 4, // 0x4
    HLVD_TRIP_POINT_2p78v = 5, // 0x5
    HLVD_TRIP_POINT_2p88v = 6, // 0x6
    HLVD_TRIP_POINT_3p09v = 7, // 0x7
    HLVD_TRIP_POINT_3p4v = 8, // 0x8
    HLVD_TRIP_POINT_3p6v = 9, // 0x9
    HLVD_TRIP_POINT_3p71v = 10, // 0xA
    HLVD_TRIP_POINT_3p91v = 11, // 0xB
    HLVD_TRIP_POINT_4p12v = 12, // 0xC
    HLVD_TRIP_POINT_4p32v = 13, // 0xD
    HLVD_TRIP_POINT_4p83 = 14, // 0xE

}HLVD_TRIP_POINTS;

extern volatile bit VCC_overvoltage_flag;

/**
  Section: HLVD Module APIs
*/

/**
  @Summary
    Initializes the HLVD

  @Description
    This routine initializes the Initializes the HLVD.
    This routine must be called before any other HLVD routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Example
    <code>
    bool gAppShutdown = false;
    {
      //initialize the module
      HLVD_Initialize();
      //check if reference voltage is stable 
      while(!HLVD_IsBandGapVoltageStable());
      while(1)
      {
         //Polling
         HLVD_Tasks();
      }
    }
    void HLVD_TripDetectionCallback(void)
    {
       //process application code here
       gAppShutdown = true; 
    }   
    </code> 
*/
void HLVD_Initialize(void);

/**
  @Summary
    This function enables the HLVD peripheral.

  @Description
    This function enables the HLVD peripheral.

  @Preconditions
    HLVD_Initialize Is_HLVD_Ref_Voltage_Stable
   function should be called first.

  @Param
    None

  @Returns
    None.

  @Example
  <code>
      HLVD_Disable();
      //Set the trip points and voltage direction
      HLVD_TripPointSetup(EXCEED_TRIP_POINT,
        HLVD_TRIP_POINT_1p85v);
      //Enable the module
      HLVD_Enable();
      //check if reference voltage is stable 
      while(!HLVD_IsBandGapVoltageStable());
      while(1)
      {
         
      }
    void HLVD_TripDetectionCallback(void)
    {
       //process application code here      
    }
   </code>     
 */
void HLVD_Enable(void);

/**
  @Summary
    This function disables the HLVD peripheral.

  @Description
    This function disables the HLVD peripheral.

  @Preconditions
    HLVD_Initialize and
    HLVD_IsBandGapVoltageStable
    function should be called first.

  @Param
    None

  @Returns
    None.

  @Example
   Refer the HLVD_Enable code example
*/
void HLVD_Disable(void);

/**
  @Summary
    This function returns the status of band gap voltage.

  @Description
    This function returns the status of band gap voltage.

  @Preconditions
    HLVD_Initialize function should be called first

  @Param
    None

  @Returns
    bool - true - Band gap voltage is stable
           false - Band gap voltage is unstable

  @Example
  Refer the HLVD_Enable code example
*/
bool HLVD_IsBandGapVoltageStable(void);


/**
  @Summary
    This function sets the Positive, Negative voltage trip and trip value

  @Description
    This function sets the Positive, Negative voltage trip and trip value

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Example
   Refer the HLVD_Enable code example
*/
void HLVD_TripPointSetup(bool Negative_Trip,bool Positive_Trip,
        HLVD_TRIP_POINTS trip_points);


/**
  @Summary
    Returns output status as High or Low voltage 

  @Description
    This routine returns output status of the HLVD module.

  @Param
    None.

  @Returns
    Output status
 
  @Example 
    <code>
    bool outputStatus;
    outputStatus = HLVD_OutputStatusGet();
    </code>
*/
bool HLVD_OutputStatusGet(void);


/**
  @Summary
    Implements ISR

  @Description
    This routine is used to implement the ISR for the interrupt-driven
    implementations.

  @Returns
    None

  @Param
    None
*/
void HLVD_ISR(void); 


#ifdef __cplusplus  // Provide C++ Compatibility
}
#endif

#endif	//HLVD_H
/**
 End of File
*/

