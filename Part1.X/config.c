#include "config.h"
#include "mcc_generated_files/memory.h"

void configInit(void)
{
    // Checking for the magic word
    if (DATAEE_ReadByte(EEAddr_MAGIC_WORD) != MAGIC_WORD || checkChecksum())
    {
        DATAEE_WriteByte(EEAddr_MAGIC_WORD, MAGIC_WORD);
        DATAEE_WriteByte(EEAddr_TIME_H, CLKH);
        DATAEE_WriteByte(EEAddr_TIME_M, CLKM);
        DATAEE_WriteByte(EEAddr_ALARMS, 0);
        DATAEE_WriteByte(EEAddr_ALAL, ALAL_ini);
        DATAEE_WriteByte(EEAddr_ALAT, ALAT_ini);
        DATAEE_WriteByte(EEAddr_ALAH, ALAH);
        DATAEE_WriteByte(EEAddr_ALAM, ALAM);
        DATAEE_WriteByte(EEAddr_ALAS, ALAS);
        DATAEE_WriteByte(EEAddr_PMON, PMON);
        DATAEE_WriteByte(EEAddr_TALA, TALA);
        DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
    }
    uint8_t h = DATAEE_ReadByte(EEAddr_ALAH);
    uint8_t m = DATAEE_ReadByte(EEAddr_ALAM);
    uint8_t s = DATAEE_ReadByte(EEAddr_ALAS);
    ALA_CLK = rtcInit(h, m, s);
    h = DATAEE_ReadByte(EEAddr_TIME_H);
    m = DATAEE_ReadByte(EEAddr_TIME_M);
    clk = rtcInit(h, m, 0);
    ALAT = DATAEE_ReadByte(EEAddr_ALAT);
    ALAL = DATAEE_ReadByte(EEAddr_ALAL);
    alarms = DATAEE_ReadByte(EEAddr_ALARMS);
    PMONITOR = DATAEE_ReadByte(EEAddr_PMON);
    TimeALA = DATAEE_ReadByte(EEAddr_TALA);
    pwm_max_count = (TimeALA*1000)/30;
}

void incTemperatureThreshold (void)
{
    ALAT = (ALAT + 1 > 50 ? 0 : ALAT + 1);
    DATAEE_WriteByte(EEAddr_ALAT, ALAT);
    DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
}
void incLuminosityThreshold (void)
{
    ALAL = (ALAL + 1 > 7 ? 0 : ALAL + 1);
    DATAEE_WriteByte(EEAddr_ALAL, ALAL);
    DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
}

void setAlarm(uint8_t FLAG)
{
    if (!(alarms & FLAG))
    {
        alarm_trigger = 1;
        alarms |= FLAG;
    }
}

uint8_t addChecksum (void)
{
    return(DATAEE_ReadByte(EEAddr_TIME_H)+DATAEE_ReadByte(EEAddr_TIME_M)+DATAEE_ReadByte(EEAddr_ALARMS)+
            DATAEE_ReadByte(EEAddr_ALAT)+DATAEE_ReadByte(EEAddr_ALAL)+DATAEE_ReadByte(EEAddr_ALAH)+
            DATAEE_ReadByte(EEAddr_ALAM)+DATAEE_ReadByte(EEAddr_ALAS)+DATAEE_ReadByte(EEAddr_PMON)+
            DATAEE_ReadByte(EEAddr_TALA));
} 

unsigned char checkChecksum (void)
{
    //uint8_t checksum = DATAEE_ReadByte(EEAddr_CHECKSUM);
    return (DATAEE_ReadByte(EEAddr_CHECKSUM) != addChecksum() ? 1 : 0);
    /*{
        return 1;
    }
    else
    {
        return 0;
    }*/
}