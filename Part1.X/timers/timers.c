#include "timers.h"
#include "../config.h"
#include "../mcc_generated_files/mcc.h"
#include "../mcc_generated_files/memory.h"
#include "../mcc_generated_files/pin_manager.h"

rtc_t rtcInit(uint8_t h, uint8_t m, uint8_t s)
{
    rtc_t clk;
    clk.h = h;
    clk.m = m;
    clk.s = s;
    clk.meas_tmr = 0;
    clk.takeMeasurement = 0x0;
    return clk;
}

void rtcSetMeasurementFunction(rtc_t* clk, void (*fc)(void))
{
    clk->takeMeasurement = fc;
}

void rtcTick(rtc_t* clk)
{
    // Incrementing the real time clock
    clk->s++;
    if (clk->s >= 60)
    {
        clk->s = 0;
        clk->m++;
        if (clk->m >= 60)
        {
            clk->m = 0;
            clk->h++;
            if (clk->h >= 24)
            {
                clk->h = 0;
            }
        }
        // Save the time every minute
        DATAEE_WriteByte(EEAddr_TIME_H, clk->h);
        DATAEE_WriteByte(EEAddr_TIME_M, clk->m);
        DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
    }
    // Blinking the LED
    LED_D5_Toggle();
    // Incrementing the measurement timer
    clk->meas_tmr++;
    if (clk->meas_tmr >= PMONITOR && PMONITOR!=0)
    {
        clk->meas_tmr = 0;
        (clk->takeMeasurement)();
    }
    // Checking for the time alarm
    if ((alarms & ALARM_A) && clk->h == ALA_CLK.h && clk->m == ALA_CLK.m && clk->s == ALA_CLK.s)
        setAlarm(ALARM_C);
}

void rtcIncrement(rtc_t* clk, uint8_t h, uint8_t m, uint8_t s)
{
    if (h)
        clk->h = (clk->h + 1 >= 24 ? 0 : clk->h + 1);
    if (m)
        clk->m = (clk->m + 1 >= 60 ? 0 : clk->m + 1);
    if (s)
        clk->s = (clk->s + 1 >= 60 ? 0 : clk->s + 1);
}

