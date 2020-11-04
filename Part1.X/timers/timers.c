#include "timers.h"
#include "../config.h"
#include "../mcc_generated_files/mcc.h"
#include "../mcc_generated_files/memory.h"
#include "../mcc_generated_files/pin_manager.h"

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
    // Blinking the LED
    LED_D5_Toggle();
    // Incrementing the measurement timer
    clk->meas_tmr++;
    if (clk->meas_tmr >= PMON && PMON!=0)
    {
        clk->meas_tmr = 0;
        (clk->takeMeasurement)();
    }
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

