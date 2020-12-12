/* 
 * File:   config.h
 * Author: alexandre
 *
 * Created on November 1, 2020, 11:50 AM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#include <stdint.h>
#include "timers/timers.h"
#include "mcc_generated_files/adcc.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
#define NREG     25
#define PMON     3
#define TALA     5
#define ALAH     12
#define ALAM     0
#define ALAS     0
#define ALAT_ini 28
#define ALAL_ini 4
#define CLKH     0
#define CLKM     0
    

uint8_t ALAT;
uint8_t ALAL;
uint8_t PMONITOR; // Monitorization period
uint8_t TimeALA;

// The alarm clock
rtc_t ALA_CLK;
rtc_t clk;

// Measurement variables
uint8_t temp;
uint8_t luminosity;
uint8_t pwm_max_count;

// Number of data registers
uint8_t nreg;
unsigned char half_reg;
unsigned char full_reg;
unsigned char first_reg;
uint8_t iread;

typedef uint8_t alarm_t;
#define ALARM_C 0b00000001
#define ALARM_T 0b00000010
#define ALARM_L 0b00000100
#define ALARM_A 0b00001000

// Variable with the alarm flags
alarm_t alarms;
// 1 when an alarm was triggered
uint8_t alarm_trigger;

#define MAGIC_WORD  0b11010101

// Starting eeprom address
#define EEAddr              0x7000  // Initial address for saving EEPROM memory
#define EEAddr_MAGIC_WORD   0x7001  // Address of the magic word
#define EEAddr_TIME_H       0x7002  // Address of the saved time
#define EEAddr_TIME_M       0x7003
#define EEAddr_ALARMS       0x7004
#define EEAddr_ALAT         0x7005  // Temperature threshold
#define EEAddr_ALAL         0x7006  // Luminosity threshold
#define EEAddr_ALAH         0x7007  // Alarm hour
#define EEAddr_ALAM         0x7008  // Alarm minute
#define EEAddr_ALAS         0x7009  // Alarm second
#define EEAddr_PMON         0x700a  // Address of the checksum 
#define EEAddr_TALA         0x700b  // Address of the checksum 
#define EEAddr_CHECKSUM     0x700c  // Address of the checksum 
#define EEAddr_reg          0x7032  // Start address for registers


// Initializes the configurations with the saved values (in EEPROM)
// If the magic word or checksum is incorrect, loads the default values
void configInit(void);
// Increments the temperature threshold for the alarm.
// Loops back at 50
void incTemperatureThreshold (void);
// Increments the luminosity threshold for the alarm.
// Loops back at 7
void incLuminosityThreshold (void);
// Sets the flag of the alarm and sets alarm_trigger to 1
void setAlarm(uint8_t );
// Add all the non-volatile saved values
uint8_t addChecksum (void);
// Check if the Checksum is correct, returns 0 if so
unsigned char checkChecksum (void);

#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

