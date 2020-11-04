#include "config.h"

void configInit(void)
{
    ALAT = 28;
    ALAL = 4;
    alarms = ALARM_A;
}

void incTemperatureThreshold (void)
{
    ALAT = (ALAT + 1 > 50 ? 0 : ALAT + 1);
}
void incLuminosityThreshold (void)
{
    ALAL = (ALAL + 1 > 7 ? 0 : ALAL + 1);
}
