#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/tmr1.h"
#include "I2C/i2c.h"
#include "mcc_generated_files/pin_manager.h"

#include "button/button.h"

#include "peripherals/lcd.h"
#include "peripherals/temp_sensor.h"

#include "timers/timers.h"

#include "config.h"

rtc_t clk;
unsigned char temp;
adc_result_t luminosity;

void* timerInterrupt(void)
{
    rtcTick(&clk);
}

void* buttonInterrupt(void)
{
    LED_D5_Toggle();
}

void takeMeasurement(unsigned char nreg)
{
    DATAEE_WriteByte(nreg, clk.h);
    DATAEE_WriteByte(nreg+1, clk.m);
    DATAEE_WriteByte(nreg+2, clk.s);
    DATAEE_WriteByte(nreg+3, temp);
    DATAEE_WriteByte(nreg+4, luminosity);
    
    LED_D2_Toggle();
}

adc_result_t readLuminosity (void)
{
    adc_result_t res = ADCC_GetSingleConversion(POT_CHANNEL);
    return (res >> 12);
}

void enableAlarms (void)
{
    
}

void generateAlarmString(unsigned char* alarm_buf)
{
    alarm_buf[0] = (alarms & ALARM_C ? 'C' : ' ');
    alarm_buf[1] = (alarms & ALARM_T ? 'T' : ' ');
    alarm_buf[2] = (alarms & ALARM_L ? 'L' : ' ');
    alarm_buf[4] = (alarms & ALARM_A ? 'A' : ' ');
}


void main(void)
{
    unsigned char c;
    unsigned char hc;
    unsigned char lc;
    unsigned char c1;
    unsigned char c2;
    unsigned char buf[17];
    unsigned char alarm_buf[6];
    alarm_buf[3] = ' ';
    alarm_buf[5] = '\0';
    clk = rtcInit();
    rtcSetMeasurementFunction(&clk, takeMeasurement);
    
    ALAF = 1;
    alarms = ALARM_C | ALARM_L | ALARM_A;

    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    TMR1_SetInterruptHandler(timerInterrupt);

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    IOCBF4_SetInterruptHandler(buttonInterrupt);
    
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
    TMR1_StartTimer();

    while (1)
    {
        NOP();
        
        // Clear the display
        LCDcmd(0x80);
        LCDstr("                ");
        LCDcmd(0xc0);
        LCDstr("                ");
        // Display the ytime
        LCDcmd(0x80);
        sprintf(buf, "%02d:%02d:%02d", clk.h, clk.m, clk.s);
        LCDstr(buf);
        // Display the temperature
        LCDcmd(0xc0);
        // Take a temperature measurement
        temp = readTemp();
        sprintf(buf, "%02d C", temp);
        LCDstr(buf);
        // Display the alarms
        generateAlarmString(alarm_buf);
        LCDcmd(0x8b);
        LCDstr(alarm_buf);
        // Display the luminosity
        LCDcmd(0xc4);
        sprintf(buf, "L %u", readLuminosity()%8);
        LCDstr(buf);
        
        LCDcmd(0x81);
        c1 = LCDrecv(0);
        c2 = LCDrecv(LCD_RS);
        LCDcmd(0xc6);
        sprintf(buf, "%x", SWITCH_S1_GetValue());
        LCDstr(buf);
        NOP();
        SLEEP();
    }
}

/**
 End of File
*/
