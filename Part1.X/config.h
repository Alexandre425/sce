/* 
 * File:   config.h
 * Author: alexandre
 *
 * Created on November 1, 2020, 11:50 AM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

#define NREG 25
#define PMON 3
#define TALA 5
#define ALAH 12
#define ALAM 0
#define ALAS 0
#define ALAT 28
#define ALAL 4
#define CLKH 12
#define CLKM 0
#define CLKS 30

unsigned char ALAF;

typedef unsigned char alarm_t;
#define ALARM_C 0b00000001
#define ALARM_T 0b00000010
#define ALARM_L 0b00000100
#define ALARM_A 0b00001000

alarm_t alarms;


#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

