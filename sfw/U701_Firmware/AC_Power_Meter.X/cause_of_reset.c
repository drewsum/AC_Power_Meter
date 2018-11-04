/*
 * File:   reset_cause.c
 * Author: Drew Maatman
 *
 * Created on January 10, 2018, 10:07 PM
 */


#include "cause_of_reset.h"

// Instantiate an instance of the enum "reset_type" called "reset_cause"
enum reset_t reset_cause;

enum reset_t getCauseOfReset(void) {
 
    // Per page 98 of PIC18(L)F67K40
    
    // Test if power on reset:
    if(     
            // Check STATUS register
            STATUSbits.nTO      && 
            STATUSbits.nPD      &&
            !(STATUSbits.N)     &&
            
            !(STATUSbits.OV)    &&
            !(STATUSbits.Z)     &&
            !(STATUSbits.DC)    &&
            !(STATUSbits.C)     &&
            
            // Check PCON0 register
            !(PCON0bits.STKOVF) &&
            !(PCON0bits.STKUNF) &&
            PCON0bits.nWDTWV    &&
            PCON0bits.nRWDT     &&
            
            PCON0bits.nRMCLR    &&
            PCON0bits.nRI       &&
            !(PCON0bits.nPOR)
            // PCON0bits.nBOR (Don't Care)
            ) {
        
        // We've determined this was a Power On Reset
        reset_cause = Power_On_Reset;
        
    }

    // Test if Brown Out reset:
    else if(     
            // Check STATUS register
            STATUSbits.nTO      && 
            STATUSbits.nPD      &&
            !(STATUSbits.N)     &&
            
            !(STATUSbits.OV)    &&
            !(STATUSbits.Z)     &&
            !(STATUSbits.DC)    &&
            !(STATUSbits.C)     &&
            
            // Check PCON0 register
            !(PCON0bits.STKOVF) &&
            !(PCON0bits.STKUNF) &&
            PCON0bits.nWDTWV    &&
            PCON0bits.nRWDT     &&
            
            PCON0bits.nRMCLR    &&
            PCON0bits.nRI       &&
            //!(PCON0bits.nPOR) (Don't Care)
            !(PCON0bits.nBOR)
            ) {
        
        // We've determined this was a BOR
        reset_cause = Brown_Out_Reset;
        
    }
    
    // Test if Master Clear Reset:
    else if(     
              // Check STATUS register
//            STATUSbits.nTO      && 
//            STATUSbits.nPD      &&
//            !(STATUSbits.N)     &&
//            
//            !(STATUSbits.OV)    &&
//            !(STATUSbits.Z)     &&
//            !(STATUSbits.DC)    &&
//            !(STATUSbits.C)     &&
//            
//            // Check PCON0 register
//            !(PCON0bits.STKOVF) &&
//            !(PCON0bits.STKUNF) &&
//            PCON0bits.nWDTWV    &&
//            PCON0bits.nRWDT     &&
            
            !(PCON0bits.nRMCLR) //    &&
            //PCON0bits.nRI       &&
            //!(PCON0bits.nPOR) (Don't Care)
            //!(PCON0bits.nBOR)
            ) {
        
        // We've determined this was a Master Clear Reset
        reset_cause = Master_Clear_Reset;
        
    }
    
    // Test if Master Clear Reset during Sleep:
    else if(     
            // Check STATUS register
            STATUSbits.nTO      && 
            STATUSbits.nPD      &&
            //!(STATUSbits.N)     &&
            
            //!(STATUSbits.OV)    &&
            //!(STATUSbits.Z)     &&
            //!(STATUSbits.DC)    &&
            //!(STATUSbits.C)     &&
            
            // Check PCON0 register
            //!(PCON0bits.STKOVF) &&
            //!(PCON0bits.STKUNF) &&
            //PCON0bits.nWDTWV    &&
            //PCON0bits.nRWDT     &&
            
            !(PCON0bits.nRMCLR)    //&&
            //PCON0bits.nRI       &&
            //!(PCON0bits.nPOR) (Don't Care)
            //!(PCON0bits.nBOR)
            ) {
        
        // We've determined this was a Master Clear Sleep Reset
        reset_cause = Master_Clear_Sleep_Reset;
        
    }
    
    // Test if WDT Time-Out Reset:
    else if(     
            // Check STATUS register
            !(STATUSbits.nTO)      && 
            //STATUSbits.nPD      &&
            //!(STATUSbits.N)     &&
            
            //!(STATUSbits.OV)    &&
            //!(STATUSbits.Z)     &&
            //!(STATUSbits.DC)    &&
            //!(STATUSbits.C)     &&
            
            // Check PCON0 register
            //!(PCON0bits.STKOVF) &&
            //!(PCON0bits.STKUNF) &&
            //PCON0bits.nWDTWV    &&
            !(PCON0bits.nRWDT)     //&&
            
            //!(PCON0bits.nRMCLR)    //&&
            //PCON0bits.nRI       &&
            //!(PCON0bits.nPOR) (Don't Care)
            //!(PCON0bits.nBOR)
            ) {
        
        // We've determined this was a Master Clear Sleep Reset
        reset_cause = Watch_Dog_Timer_Reset;
        
    }
    
    // Test if WDT Wake from Sleep:
    else if(     
            // Check STATUS register
            !(STATUSbits.nTO)      && 
            !(STATUSbits.nPD)      //&&
            //!(STATUSbits.N)     &&
            
            //!(STATUSbits.OV)    &&
            //!(STATUSbits.Z)     &&
            //!(STATUSbits.DC)    &&
            //!(STATUSbits.C)     &&
            
            // Check PCON0 register
            //!(PCON0bits.STKOVF) &&
            //!(PCON0bits.STKUNF) &&
            //PCON0bits.nWDTWV    &&
            //PCON0bits.nRWDT     &&
            
            //!(PCON0bits.nRMCLR)    //&&
            //PCON0bits.nRI       &&
            //!(PCON0bits.nPOR) (Don't Care)
            //!(PCON0bits.nBOR)
            ) {
        
        // We've determined this was a Master Clear Sleep Reset
        reset_cause = Watch_Dog_Timer_Sleep_Reset;
        
    }
            
    // Test if WWDT Violation:
    else if(     
            // Check STATUS register
            //!(STATUSbits.nTO)      && 
            //!)STATUSbits.nPD)      //&&
            //!(STATUSbits.N)     &&
            
            //!(STATUSbits.OV)    &&
            //!(STATUSbits.Z)     &&
            //!(STATUSbits.DC)    &&
            //!(STATUSbits.C)     &&
            
            // Check PCON0 register
            //!(PCON0bits.STKOVF) &&
            //!(PCON0bits.STKUNF) &&
            !(PCON0bits.nWDTWV)    //&&
            //PCON0bits.nRWDT     &&
            
            //!(PCON0bits.nRMCLR)    //&&
            //PCON0bits.nRI       &&
            //!(PCON0bits.nPOR) (Don't Care)
            //!(PCON0bits.nBOR)
            ) {
        
        // We've determined this was a Master Clear Sleep Reset
        reset_cause = Windowed_Watch_Dog_Timer_Reset;
        
    }
    
    // Test if Interrupt Wake from Sleep:
    else if(     
            // Check STATUS register
            STATUSbits.nTO      && 
            !(STATUSbits.nPD)      &&
            //!(STATUSbits.N)     &&
            
            !(STATUSbits.OV)    //&&
            //!(STATUSbits.Z)     &&
            //!(STATUSbits.DC)    &&
            //!(STATUSbits.C)     &&
            
            // Check PCON0 register
            //!(PCON0bits.STKOVF) &&
            //!(PCON0bits.STKUNF) &&
            //PCON0bits.nWDTWV    &&
            //PCON0bits.nRWDT     &&
            
            //!(PCON0bits.nRMCLR)    //&&
            //PCON0bits.nRI       &&
            //!(PCON0bits.nPOR) (Don't Care)
            //!(PCON0bits.nBOR)
            ) {
        
        // We've determined this was a Master Clear Sleep Reset
        reset_cause = Interrupt_Wake_Up_From_Sleep;
        
    }
    
    // Test if RESET Executed:
    else if(     
            // Check STATUS register
            //!(STATUSbits.nTO)      && 
            //!)STATUSbits.nPD)      //&&
            //!(STATUSbits.N)     &&
            
            //!(STATUSbits.OV)    &&
            //!(STATUSbits.Z)     &&
            //!(STATUSbits.DC)    &&
            //!(STATUSbits.C)     &&
            
            // Check PCON0 register
            //!(PCON0bits.STKOVF) &&
            //!(PCON0bits.STKUNF) &&
            //PCON0bits.nWDTWV    &&
            //PCON0bits.nRWDT     &&
            
            //!(PCON0bits.nRMCLR)    //&&
            !(PCON0bits.nRI)       //&&
            //!(PCON0bits.nPOR) (Don't Care)
            //!(PCON0bits.nBOR)
            ) {
        
        // We've determined this was a Master Clear Sleep Reset
        reset_cause = RESET_Instruction_Executed;
        
    }
    
    // Test if Stack Overflow Reset:
    else if(     
            // Check STATUS register
            //!(STATUSbits.nTO)      && 
            //!)STATUSbits.nPD)      //&&
            //!(STATUSbits.N)     &&
            
            //!(STATUSbits.OV)    &&
            //!(STATUSbits.Z)     &&
            //!(STATUSbits.DC)    &&
            //!(STATUSbits.C)     &&
            
            // Check PCON0 register
            PCON0bits.STKOVF //&&
            //!(PCON0bits.STKUNF) &&
            //PCON0bits.nWDTWV    &&
            //PCON0bits.nRWDT     &&
            
            //!(PCON0bits.nRMCLR)    //&&
            //PCON0bits.nRI       &&
            //!(PCON0bits.nPOR) (Don't Care)
            //!(PCON0bits.nBOR)
            ) {
        
        // We've determined this was a Master Clear Sleep Reset
        reset_cause = Stack_Overflow_Reset;
        
    }
    
    // Test if Stack Underflow Reset:
    else if(     
            // Check STATUS register
            //!(STATUSbits.nTO)      && 
            //!(STATUSbits.nPD)      //&&
            //!(STATUSbits.N)     &&
            
            //!(STATUSbits.OV)    &&
            //!(STATUSbits.Z)     &&
            //!(STATUSbits.DC)    &&
            //!(STATUSbits.C)     &&
            
            // Check PCON0 register
            //!(PCON0bits.STKOVF) &&
            PCON0bits.STKUNF //&&
            //PCON0bits.nWDTWV    &&
            //PCON0bits.nRWDT     &&
            
            //!(PCON0bits.nRMCLR)    //&&
            //PCON0bits.nRI       &&
            //!(PCON0bits.nPOR) (Don't Care)
            //!(PCON0bits.nBOR)
            ) {
        
        // We've determined this was a Master Clear Sleep Reset
        reset_cause = Stack_Underflow_Reset;
        
    }
    
    // Test if VREG or ULP Ready Fault:
    else if(     
            // Check STATUS register
            //!(STATUSbits.nTO)      && 
            //!)STATUSbits.nPD)      //&&
            STATUSbits.N     &&
            
            STATUSbits.OV    &&
            !(STATUSbits.Z)     &&
            !(STATUSbits.DC)    &&
            !(STATUSbits.C)     &&
            
            // Check PCON0 register
            !(PCON0bits.STKOVF) &&
            !(PCON0bits.STKUNF) &&
            PCON0bits.nWDTWV    &&
            PCON0bits.nRWDT     &&
            
            !(PCON0bits.nRMCLR)    &&
            !(PCON0bits.nRI)       &&
            PCON0bits.nPOR
            //!(PCON0bits.nBOR)
            ) {
        
        // We've determined this was a Master Clear Sleep Reset
        reset_cause = VREG_or_ULP_Ready_Fault_Reset;
        
    }
            
    // Return determined reset type
    return reset_cause;
    
}


inline char *getCauseOfResetString(enum reset_t r) {
   
    // The ordering MUST match the ordering of the reset_type enumeration
    const char *strings[] = {
        "Power On Reset",
        "Brown Out Reset",
        "Master Clear Reset",
        "Master Clear Sleep Reset",
        "Watch Dog Timer Violation Reset",
        "Watch Dog Timer Sleep Reset",
        "Windowed Watch Dog Timer Violation Reset",
        "Interrupt Wake Up From Sleep",
        "RESET Instruction Executed",
        "Stack Overflow Reset",
        "Stack Underflow Reset",
        "VREG or ULP Ready Fault Reset"
    };

    return strings[r];
}


