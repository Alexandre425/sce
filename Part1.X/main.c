#include <stdint.h>
#include <xc.h>
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
#include "mcc_generated_files/tmr2.h"
#include "mcc_generated_files/tmr5.h"
#include "mcc_generated_files/pwm6.h"
#include "comunication/comunication.h"
#include "mcc_generated_files/adcc.h"

// Number of data registers
uint8_t nreg;
uint8_t last_sent_index;

// Measurement variables
uint8_t last_temp;
adc_result_t last_luminosity;


// PWM variables
const uint8_t duty_cycle_inc = 60;
uint8_t pwm_count;
uint16_t duty_cycle;
int8_t sign;

// The different modes changed by the buttons
enum modes
{
    M_VIEW,                         // Normal, viewing mode
    M_TIME_H, M_TIME_M, M_TIME_S,   // Modes to change the clock time
    M_C, M_T, M_L, M_A,             // To access the thresholds or en/disable alarms
    M_ALARM_H, M_ALARM_M, M_ALARM_S,// Change the alarm clock
    M_THRESH_TEMP, M_THRESH_LUM     // Change the thresholds
} mode;

// Cursor position for each mode
const uint8_t CURSOR_POS[13] = 
{0x00, 0x81, 0x84, 0x87, 0x8b, 0x8c, 0x8d ,0x8f, 0x81, 0x84, 0x87 ,0xc1, 0xcf};

void generateAlarmString(unsigned char* alarm_buf)
{
    if (alarms & ALARM_A)
    {
    alarm_buf[0] = (alarms & ALARM_C ? 'C' : ' ');
    alarm_buf[1] = (alarms & ALARM_T ? 'T' : ' ');
    alarm_buf[2] = (alarms & ALARM_L ? 'L' : ' ');
    alarm_buf[3] = ' ';
    alarm_buf[4] = (alarms & ALARM_A ? 'A' : ' ');
    } 
    else 
    {
    alarm_buf[0] = ' ';
    alarm_buf[1] = ' ';
    alarm_buf[2] = ' ';
    alarm_buf[3] = ' ';
    alarm_buf[4] = ' ';
    }
}

// Updates the LCD (every second and when there's a button press)
void updateLCD(void)
{
    unsigned char buf[9];
    // Display the time
    LCDcmd(0x80);
    rtc_t display_clk = (mode == M_ALARM_H || mode == M_ALARM_M || mode == M_ALARM_S ? ALA_CLK : clk);
    sprintf(buf, "%02d:%02d:%02d", display_clk.h, display_clk.m, display_clk.s);
    LCDstr(buf);
    // Display the temperature
    uint8_t display_temp = (mode == M_THRESH_TEMP ? ALAT : temp);
    LCDcmd(0xc0);
    sprintf(buf, "%02d C", display_temp);
    LCDstr(buf);
    // Display the alarms
    generateAlarmString(buf);
    LCDcmd(0x8b);
    LCDstr(buf);
    // Display the luminosity
    uint8_t display_lum = (mode == M_THRESH_LUM ? ALAL : luminosity);
    LCDcmd(0xcd);
    sprintf(buf, "L %u", display_lum);
    LCDstr(buf);
    
    // Display the memory alarm
    uint8_t display_mem = (nreg/5 > 12 ? 'M' : ' ');
    LCDcmd(0xc7);
    sprintf(buf, "%c", display_mem);
    LCDstr(buf);

    // Place the cursor on the correct spot depending on the mode
    if (mode)
        LCDcmd(CURSOR_POS[mode]);
}

void* timerInterrupt(void)
{
    if (mode != 1 && mode != 2 && mode != 3) // Tick the clock only if not editing it
    {
        rtcTick(&clk);
    }
    updateLCD();
}


// Brightens or dims the LED when an alarm occurs
void* alarmPWMInterrupt(void)
{
    duty_cycle += duty_cycle_inc * sign;
    if (duty_cycle > 1024)
    {
        sign = -sign;
        duty_cycle += duty_cycle_inc * sign;
    }

    if (pwm_count++ > pwm_max_count)
    {
        TMR3_StopTimer();
        duty_cycle = 0;
    }

    PWM6_LoadDutyValue(duty_cycle);
}

void* bounceTimer(void)
{
    TMR5_StopTimer();
    IOCBNbits.IOCBN4 = 1;
    IOCCNbits.IOCCN5 = 1;
}


void* buttonS1Interrupt(void)
{
    // If in viewing mode and there are alarms
    if (alarms & ALARM_A && alarms != ALARM_A && mode == M_VIEW)
    {
        alarms &= ALARM_A; // Reset the alarms
    } 
    else 
    { 
        switch (mode)   // Switch modes
        {
        case M_A:           // Alarm enable edit mode: loop back to view mode
            mode = M_VIEW;
            break;
        case M_ALARM_S:     // Back to T
            mode = M_T;
            break;
        case M_THRESH_TEMP: // Back to L
            mode = M_L;
            break;
        case M_THRESH_LUM:  // Back to A
            mode = M_A;
            break;
        default:            // For all others: simply move to the next state
            mode++;         // Hopefully it never goes above the last enumeration!
            break;
        }
    }
    updateLCD();
    TMR5_StartTimer();
    IOCBNbits.IOCBN4 = 0;
}

void* buttonS2Interrupt(void)
{
    switch (mode)
    {
    case M_TIME_H:
        rtcIncrement(&clk, 1, 0, 0);
        DATAEE_WriteByte(EEAddr_TIME_H, clk.h);
        DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
        break;
    case M_TIME_M:
        rtcIncrement(&clk, 0, 1, 0);
        DATAEE_WriteByte(EEAddr_TIME_M, clk.m);
        DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());

        break;
    case M_TIME_S:
        rtcIncrement(&clk, 0, 0, 1);
        break;
    case M_C:
        mode = M_ALARM_H; 
        break;
    case M_T:
        mode = M_THRESH_TEMP; 
        break;
    case M_L:
        mode = M_THRESH_LUM; 
        break;
    case M_A:
        alarms ^= ALARM_A;  // Bitwise XOR to toggle the bit
        DATAEE_WriteByte(EEAddr_ALARMS, alarms);
        DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
        break;
    case M_ALARM_H:
        rtcIncrement(&ALA_CLK, 1, 0, 0);
        DATAEE_WriteByte(EEAddr_ALAH, ALA_CLK.h);
        DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
        break;
    case M_ALARM_M:
        rtcIncrement(&ALA_CLK, 0, 1, 0);
        DATAEE_WriteByte(EEAddr_ALAM, ALA_CLK.m);
        DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
        break;
    case M_ALARM_S:
        rtcIncrement(&ALA_CLK, 0, 0, 1);
        DATAEE_WriteByte(EEAddr_ALAS, ALA_CLK.s);
        DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
        break;
    case M_THRESH_TEMP:
        incTemperatureThreshold();
        break;
    case M_THRESH_LUM:
        incLuminosityThreshold();
        break;
    default:
        break;
    }
    updateLCD();
    TMR5_StartTimer();
    IOCCNbits.IOCCN5 = 0;
}

adc_result_t readLuminosity (void)
{
    adc_result_t res = ADCC_GetSingleConversion(POT_CHANNEL);
    return (res >> 13);
}


//Light LED D2 when luminosity is above threshold
void checkLuminosity(void)
{
    if (luminosity >= ALAL){
        if (alarms & ALARM_A)   // If alarms are on
        {
            setAlarm(ALARM_L);
            LED_D2_SetHigh();
        }
        else
        {
            LED_D2_SetLow();
        }
    }
    else {
        LED_D2_SetLow();
    }  
}

// Light LED D3 when temperature is above threshold
void checkTemperature(void) 
{
    if(temp >= ALAT){
        if (alarms & ALARM_A)   // If alarms are on
        {
            setAlarm(ALARM_T);
            LED_D3_SetHigh();
        }
        else
        {
            LED_D3_SetLow();
        }
    }
    else {
        LED_D3_SetLow();
    }  
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
    }
}

void main(void)
{
    last_luminosity = 99;
    last_temp = 99;
    nreg = 0;
    mode = 0;
    last_sent_index = 0;
    
    // initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    TMR1_SetInterruptHandler(timerInterrupt);
    TMR3_SetInterruptHandler(alarmPWMInterrupt);
    TMR5_SetInterruptHandler(bounceTimer);

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    IOCBF4_SetInterruptHandler(buttonS1Interrupt);
    IOCCF5_SetInterruptHandler(buttonS2Interrupt);
    
    // Set interrupt handles for comunication
    EUSART_SetRxInterruptHandler(readMessage);
    
    configInit();
    rtcSetMeasurementFunction(&clk, takeMeasurement);
    i2c1_driver_open();
    I2C_SCL = 1;
    I2C_SDA = 1;
    WPUC3 = 1;
    WPUC4 = 1;
    LCDinit();
    TMR1_StartTimer();
    TMR3_StopTimer();       
    PWM6_LoadDutyValue(0);  // Turn off the LED4
    takeMeasurement();

    while (1)
    {
        NOP();
        
        // Check for an alarm trigger
        if (alarm_trigger)
        {
            pwm_count = 0;
            duty_cycle = 0;
            sign = 1;

            TMR3_StartTimer();
            alarm_trigger = 0;
        }
        SLEEP();
    }
}

/**
 End of File
*/
