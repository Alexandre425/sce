#include "config.h"
#include "mcc_generated_files/memory.h"

void configInit(void)
{
    // Checking for the magic word
    if (DATAEE_ReadByte(EEAddr_MAGIC_WORD) != MAGIC_WORD)
    {
        //DATAEE_WriteByte();
    } else {
        ALAT = 28;
        ALAL = 4;
        alarms = ALARM_A;
    }
}

void incTemperatureThreshold (void)
{
    ALAT = (ALAT + 1 > 50 ? 0 : ALAT + 1);
}
void incLuminosityThreshold (void)
{
    ALAL = (ALAL + 1 > 7 ? 0 : ALAL + 1);
}

void setAlarm(uint8_t FLAG)
{
    if (!(alarms & FLAG))
    {
        alarm_trigger = 1;
        alarms |= FLAG;
    }
}
