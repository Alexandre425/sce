/* 
 * File:   config.h
 * Author: alexandre
 *
 * Created on November 1, 2020, 11:50 AM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif
    
#define NREG 25
#define PMON 3
#define TALA 5
#define ALAH 12
#define ALAM 0
#define ALAS 0
#define CLKH 12
#define CLKM 0
#define CLKS 30

uint8_t ALAT;
uint8_t ALAL;

typedef uint8_t alarm_t;
#define ALARM_C 0b00000001
#define ALARM_T 0b00000010
#define ALARM_L 0b00000100
#define ALARM_A 0b00001000

// Variable with the alarm flags
alarm_t alarms;
// 1 when an alarm was triggered
uint8_t alarm_trigger;

// Starting eeprom address
#define EEAddr                   0x7000 
#define EEAddr_reg               0x7032 

// Initializes the configurations with the default values
void configInit(void);
// Increments the temperature threshold for the alarm.
// Loops back at 50
void incTemperatureThreshold (void);
// Increments the luminosity threshold for the alarm.
// Loops back at 7
void incLuminosityThreshold (void);
// Sets the flag of the alarm and sets alarm_trigger to 1
void setAlarm(uint8_t FLAG);


#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

