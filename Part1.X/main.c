#include "mcc_generated_files/mcc.h"
#include "I2C/i2c.h"
#include "timers/wdt.h"
#include "button/button.h"
#include "mcc_generated_files/pin_manager.h"
#include "peripherals/lcd.h"
#include "peripherals/temp_sensor.h"

//#include "stdio.h"

/*
                         Main application
 */

void checkButtonS1(void) {
    if (btnState == NOT_PRESSED) {
        if (SWITCH_S1_PORT == LOW) {
            __delay_ms(100);
            btnState = PRESSED;
        }
    } else if (SWITCH_S1_PORT == HIGH) {
        btnState = NOT_PRESSED;
//        switchEvent = 1;
    }
}

void main(void)
{
    unsigned char c;
    unsigned char hc;
    unsigned char lc;
    unsigned char c1;
    unsigned char c2;
    unsigned char buf[17];
    unsigned int counter = 0;
    
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    i2c1_driver_open();
    I2C_SCL = 1;
    I2C_SDA = 1;
    WPUC3 = 1;
    WPUC4 = 1;
    LCDinit();

    while (1)
    {
        NOP();
        if(SWITCH_S1_GetValue()){
            LED_D2_SetHigh();
            LED_D3_SetHigh();
            LED_D4_SetHigh();
            LED_D5_SetHigh();
        } else {
            LEDs_SetLow();
        }
        // Add your application code

        c = tsttc();
        //        hc = (c / 10);
        //        lc = (c % 10);
        LCDcmd(0x80);
        LCDstr("Temp");
        LCDcmd(0x85);
        sprintf( buf,"Clock %02d", counter );
        LCDstr(buf);
        LCDcmd(0xc0);
        //LCDchar(hc + 48);LCDchar(lc + 48);LCDchar(' ');LCDchar('C');
        sprintf(buf, "%02d C", c);
        LCDstr(buf);
        LCDcmd(0x81);
        c1 = LCDrecv(0);
        c2 = LCDrecv(LCD_RS);
        LCDcmd(0xc8);
        sprintf(buf, "%x", SWITCH_S1_GetValue());
        LCDstr(buf);
        NOP();
        __delay_ms(2000);
        counter = counter + 2;
    }
}

/**
 End of File
*/
