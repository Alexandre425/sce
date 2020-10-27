
#ifndef TIMERS_H
#define	TIMERS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
    
typedef struct rtc
{
    unsigned char h;
    unsigned char m;
    unsigned char s;
} rtc_t;

// Returns a real time clock with the time set to 0
rtc_t rtcInit(void);
// Increments the time by one and overflows if necessary
void rtcTick(rtc_t* clk);

#ifdef	__cplusplus
}
#endif

#endif	/* TIMERS_H */

