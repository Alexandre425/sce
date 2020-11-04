#include <stdint.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/memory.h"
#include "I2C/i2c.h"
#include "mcc_generated_files/pin_manager.h"
#include "button/button.h"
#include "peripherals/lcd.h"
#include "peripherals/temp_sensor.h"
#include "timers/timers.h"
#include "config.h"

// Real time clock
rtc_t clk;
uint8_t nreg;
// Measurement variables
uint8_t temp;
uint8_t last_temp;
adc_result_t luminosity;
adc_result_t last_luminosity;
// UI variables
uint8_t mode;   // Selected with S1, from 0 to 6, from display to change luminosity

// Cursor position for each mode
const uint8_t CURSOR_POS[7] = {0x00, 0x81, 0x84, 0x87, 0x8f, 0xc1, 0xcf};

void* timerInterrupt(void)
{
    if (mode != 1 && mode != 2 && mode != 3) // Tick the clock only if not editing it
    {
        rtcTick(&clk);
    }
}

void* buttonS1Interrupt(void)
{
    // Reset the alarms -- Shouldn't this be moved to the other button???
    alarms = alarms & ALARM_A;

    mode = (mode + 1 > 6 ? 0 : mode + 1);
}

void* buttonS2Interrupt(void)
{
    switch (mode)
    {
    case 1:
        rtcIncrement(&clk, 1, 0, 0);
    break;
    case 2:
        rtcIncrement(&clk, 0, 1, 0);
    break;
    case 3:
        rtcIncrement(&clk, 0, 0, 1);
    break;
    case 4:
        alarms ^= ALARM_A;  // Bitwise XOR to toggle the bit
    break;
    case 5:
        incTemperatureThreshold();
    break;
    case 6:
        incLuminosityThreshold();
    break;
    
    default:
        // Move the alarm clean here?
    break;
    }
}

adc_result_t readLuminosity (void)
{
    adc_result_t res = ADCC_GetSingleConversion(POT_CHANNEL);
    return (res >> 13);
}

void generateAlarmString(unsigned char* alarm_buf)
{
    alarm_buf[0] = (alarms & ALARM_C ? 'C' : ' ');
    alarm_buf[1] = (alarms & ALARM_T ? 'T' : ' ');
    alarm_buf[2] = (alarms & ALARM_L ? 'L' : ' ');
    alarm_buf[3] = ' ';
    alarm_buf[4] = (alarms & ALARM_A ? 'A' : ' ');
}

//Light LED D2 when luminosity is above threshold
void checkLuminosity(void)
{
    if (luminosity >= ALAL){
        LED_D2_SetHigh();
        if (alarms & ALARM_A)   // If alarms are on
            alarms |= ALARM_L;
    }
    else {
        LED_D2_SetLow();
    }  
}

// Light LED D3 when temperature is above threshold
void checkTemperature(void)
{
    if(temp >= ALAT){
        LED_D3_SetHigh();
        if (alarms & ALARM_A)   // If alarms are on
            alarms |= ALARM_T;  // Trigger the temperature alarm
    }
    else {
        LED_D3_SetLow();
    }  
}

void displayMeasurement(void)
{
    
}

void takeMeasurement(void)
{
    // Take the measurements and save them to the global variables
    luminosity = readLuminosity();
    temp = readTemp();

    // Display the results on the LEDs
    checkLuminosity();
    checkTemperature();   
    
    // Writing the bytes to the EEPROM for a register
    if (temp != last_temp || luminosity != last_luminosity){
        DATAEE_WriteByte(EEAddr_reg + nreg, clk.h);
        DATAEE_WriteByte(EEAddr_reg + nreg+1, clk.m);
        DATAEE_WriteByte(EEAddr_reg + nreg+2, clk.s);
        DATAEE_WriteByte(EEAddr_reg + nreg+3, temp);
        DATAEE_WriteByte(EEAddr_reg + nreg+4, luminosity);
        // Updating register iterator and temperature and luminosity values
        nreg += 5;
        nreg = (nreg >= 125 ? '0' : nreg);
        last_temp = temp;
        last_luminosity = luminosity;
        // visual check
        LED_D4_SetHigh();
    } else {
        LED_D4_SetLow();
    }
}

void main(void)
{
    unsigned char buf[9];
    clk = rtcInit();
    rtcSetMeasurementFunction(&clk, takeMeasurement);
    last_luminosity = 99;
    last_temp = 99;
    nreg = 0;
    mode = 0;
    
    // initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    TMR1_SetInterruptHandler(timerInterrupt);

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    IOCBF4_SetInterruptHandler(buttonS1Interrupt);
    IOCCF5_SetInterruptHandler(buttonS2Interrupt);
    
    
    i2c1_driver_open();
    I2C_SCL = 1;
    I2C_SDA = 1;
    WPUC3 = 1;
    WPUC4 = 1;
    LCDinit();
    TMR1_StartTimer();

    takeMeasurement();
    configInit();

    while (1)
    {
        NOP();
        
        // Display the time
        LCDcmd(0x80);
        sprintf(buf, "%02d:%02d:%02d", clk.h, clk.m, clk.s);
        LCDstr(buf);
        // Display the temperature
        uint8_t display_temp = (mode ? ALAT : temp);
        LCDcmd(0xc0);
        sprintf(buf, "%02d C", display_temp);
        LCDstr(buf);
        // Display the alarms
        generateAlarmString(buf);
        LCDcmd(0x8b);
        LCDstr(buf);
        // Display the luminosity
        uint8_t displau_lum = (mode ? ALAL : luminosity);
        LCDcmd(0xcd);
        sprintf(buf, "L %u", displau_lum);
        LCDstr(buf);

        // Place the cursor on the correct spot depending on the mode
        if (mode)
        {
            LCDcmd(CURSOR_POS[mode]);
        }

        SLEEP();
    }
}

/**
 End of File
*/
