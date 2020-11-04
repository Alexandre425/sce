
#ifndef TIMERS_H
#define	TIMERS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
    
typedef struct rtc
{
    uint8_t h;
    uint8_t m;
    uint8_t s;
    uint8_t meas_tmr;
    void (*takeMeasurement)();

} rtc_t;

// Returns a real time clock with the time set to 0
rtc_t rtcInit(void);
// Increments the time by one and overflows if necessary
void rtcTick(rtc_t* clk);
// Sets the measurement function that is called once the measurement timer overflows (PMON seconds)
void rtcSetMeasurementFunction(rtc_t* clk, void (*fc)(void));
// Increments the clock in each field if a '1' is passed, does not if a '0' is passed
// Ex: To increment the minutes, pass it (&clk, 0, 1, 0)
void rtcIncrement(rtc_t* clk, uint8_t h, uint8_t m, uint8_t s);


#ifdef	__cplusplus
}
#endif

#endif	/* TIMERS_H */

