#include "timers.h"

rtc_t rtcInit(void)
{
    rtc_t clk;
    clk.h = 0;
    clk.m = 0;
    clk.s = 0;
    return clk;
}

void rtcTick(rtc_t* clk)
{
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
}

