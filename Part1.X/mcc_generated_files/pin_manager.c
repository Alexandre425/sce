/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18875
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
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

#include <xc.h>
#include "pin_manager.h"
#include "stdbool.h"




void (*IOCBF4_InterruptHandler)(void);
void (*IOCCF5_InterruptHandler)(void);


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x00;
    LATD = 0x00;
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x07;
    TRISA = 0x0F;
    TRISB = 0xFF;
    TRISC = 0xBF;
    TRISD = 0xFF;

    /**
    ANSELx registers
    */
    ANSELD = 0xFF;
    ANSELC = 0x47;
    ANSELB = 0xEF;
    ANSELE = 0x07;
    ANSELA = 0x0F;

    /**
    WPUx registers
    */
    WPUD = 0x00;
    WPUE = 0x00;
    WPUB = 0x00;
    WPUA = 0x00;
    WPUC = 0x00;

    /**
    ODx registers
    */
    ODCONE = 0x00;
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;
    ODCOND = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x07;


    /**
    IOCx registers 
    */
    //interrupt on change for group IOCBF - flag
    IOCBFbits.IOCBF4 = 0;
    //interrupt on change for group IOCBN - negative
    IOCBNbits.IOCBN4 = 1;
    //interrupt on change for group IOCBP - positive
    IOCBPbits.IOCBP4 = 0;
    //interrupt on change for group IOCCF - flag
    IOCCFbits.IOCCF5 = 0;
    //interrupt on change for group IOCCN - negative
    IOCCNbits.IOCCN5 = 1;
    //interrupt on change for group IOCCP - positive
    IOCCPbits.IOCCP5 = 0;



    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCBF4_SetInterruptHandler(IOCBF4_DefaultInterruptHandler);
    IOCCF5_SetInterruptHandler(IOCCF5_DefaultInterruptHandler);
   
    // Enable IOCI interrupt 
    PIE0bits.IOCIE = 1; 
    
	
    RXPPS = 0x17;   //RC7->EUSART:RX;    
    SSP1CLKPPS = 0x13;   //RC3->MSSP1:SCL1;    
    RC3PPS = 0x14;   //RC3->MSSP1:SCL1;    
    RC4PPS = 0x15;   //RC4->MSSP1:SDA1;    
    RA6PPS = 0x0E;   //RA6->PWM6:PWM6OUT;    
    RC6PPS = 0x10;   //RC6->EUSART:TX;    
    SSP1DATPPS = 0x14;   //RC4->MSSP1:SDA1;    
}
  
void PIN_MANAGER_IOC(void)
{   
	// interrupt on change for pin IOCBF4
    if(IOCBFbits.IOCBF4 == 1)
    {
        IOCBF4_ISR();  
    }	
	// interrupt on change for pin IOCCF5
    if(IOCCFbits.IOCCF5 == 1)
    {
        IOCCF5_ISR();  
    }	
}

/**
   IOCBF4 Interrupt Service Routine
*/
void IOCBF4_ISR(void) {

    // Add custom IOCBF4 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCBF4_InterruptHandler)
    {
        IOCBF4_InterruptHandler();
    }
    IOCBFbits.IOCBF4 = 0;
}

/**
  Allows selecting an interrupt handler for IOCBF4 at application runtime
*/
void IOCBF4_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCBF4_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCBF4
*/
void IOCBF4_DefaultInterruptHandler(void){
    // add your IOCBF4 interrupt custom code
    // or set custom function using IOCBF4_SetInterruptHandler()
}

/**
   IOCCF5 Interrupt Service Routine
*/
void IOCCF5_ISR(void) {

    // Add custom IOCCF5 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCCF5_InterruptHandler)
    {
        IOCCF5_InterruptHandler();
    }
    IOCCFbits.IOCCF5 = 0;
}

/**
  Allows selecting an interrupt handler for IOCCF5 at application runtime
*/
void IOCCF5_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCCF5_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCCF5
*/
void IOCCF5_DefaultInterruptHandler(void){
    // add your IOCCF5 interrupt custom code
    // or set custom function using IOCCF5_SetInterruptHandler()
}

/**
 End of File
*/