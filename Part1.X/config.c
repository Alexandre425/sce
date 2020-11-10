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
        DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
    }
    unsigned char h = DATAEE_ReadByte(EEAddr_ALAH);
    unsigned char m = DATAEE_ReadByte(EEAddr_ALAM);
    unsigned char s = DATAEE_ReadByte(EEAddr_ALAS);
    ALA_CLK = rtcInit(h, m, s);
    ALAT = DATAEE_ReadByte(EEAddr_ALAT);
    ALAL = DATAEE_ReadByte(EEAddr_ALAL);
    alarms = DATAEE_ReadByte(EEAddr_ALARMS);
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
            DATAEE_ReadByte(EEAddr_ALAM)+DATAEE_ReadByte(EEAddr_ALAS));
} 

bool checkChecksum ( void)
{
    unsigned char checksum = DATAEE_ReadByte(EEAddr_CHECKSUM);
    if(checksum != addChecksum())
    {
        return true;
    }
    else
    {
        return false;
    }
}