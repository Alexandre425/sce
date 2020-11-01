#include "timers.h"
#include "../config.h"

rtc_t rtcInit(void)
{
    rtc_t clk;
    clk.h = CLKH;
    clk.m = CLKM;
    clk.s = CLKS;
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
    }
    // Incrementing the measurement timer
    clk->meas_tmr++;
    if (clk->meas_tmr >= PMON)
    {
        clk->meas_tmr = 0;
        (clk->takeMeasurement)();
    }
}

