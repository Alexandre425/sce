#include "comunication.h"
#include "../config.h"
#include "../mcc_generated_files/eusart.h"
#include "../peripherals/lcd.h"
#include "../mcc_generated_files/memory.h"

void readMessage(void)
{
    uint8_t som = 0;
    uint8_t msg_data[7];

    while (som!=SOM){
        som = EUSART_Read();
    }
    
    msg_cmd = EUSART_Read();
    
    for(unsigned char i= 0; i<7 ; i++){
        msg_data[i] = EUSART_Read();
        if (msg_data[i]==EOM)
            break;
    }
    
    processMessage(msg_data);
    return;
}

void processMessage (uint8_t* msg_data)
{   
    switch(msg_cmd){
        case RCLK:
            readClock();
            break;
        case SCLK:
            setClock(msg_data);
            break;
        case RTL:
            readTempLumin();
            break;
        case RPAR:
            readParam();
            break;
        case MMP:
            modifyPMONITOR(msg_data[0]);
            break;
        case MTA:
            modifyTimeAlarm(msg_data[0]);
            break;
        case RALA:
            readAlarm();
            break;
        case DAC:
            setAlarmClock(msg_data);
            break;
        case DATL:
            setAlarmTempLumin(msg_data);
            break;
        case AALA:
            setAlarmCom(msg_data);
            break;
        case IREG:
            readReg();
            break;
        case TRGC:
            transferCurrent(msg_data);
            break;
        case TRGI:
            transferIndex(msg_data);
            break;
        case NMFL:
            memNotification();
            break;
        default:
            break;
    }
    
}

void sendError (uint8_t msg_ok)
{
    EUSART_Write(SOM);
    EUSART_Write(msg_cmd);
    EUSART_Write(msg_ok);
    EUSART_Write(EOM);
}

void readClock(void)
{
    EUSART_Write(SOM);
    EUSART_Write(msg_cmd);
    EUSART_Write(clk.h);
    EUSART_Write(clk.m);
    EUSART_Write(clk.s);
    EUSART_Write(EOM);
}

void setClock(uint8_t* msg_data)
{
    if(msg_data[0] > 23 || msg_data[1] > 59 || msg_data[2] > 59)
    {
        sendError(CMD_ERROR);
        return;
    }
    
    (&clk)->h = msg_data[0];
    (&clk)->m = msg_data[1];
    (&clk)->s = msg_data[2];
    DATAEE_WriteByte(EEAddr_TIME_H, clk.h);
    DATAEE_WriteByte(EEAddr_TIME_M, clk.m);
    DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
    sendError(CMD_OK);
}

void readTempLumin(void)
{
    EUSART_Write(SOM);
    EUSART_Write(msg_cmd);
    EUSART_Write(temp);
    EUSART_Write(luminosity);
    EUSART_Write(EOM);
}

void readParam (void)
{
    EUSART_Write(SOM);
    EUSART_Write(msg_cmd);
    EUSART_Write(PMONITOR);
    EUSART_Write(TimeALA);
    EUSART_Write(EOM);
}

void modifyPMONITOR(uint8_t msg_data)
{
    if( msg_data < 0 || msg_data > 99)
    {
        sendError(CMD_ERROR);
        return;
    }
    PMONITOR = msg_data;
    DATAEE_WriteByte(EEAddr_PMON, PMONITOR);
    DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
    sendError(CMD_OK);
}

void modifyTimeAlarm(uint8_t msg_data)
{
    if(msg_data < 0 || msg_data > 59 ){
        sendError(CMD_ERROR);
        return;
    }
    TimeALA = msg_data;
    pwm_max_count = (TimeALA*1000)/30;
    DATAEE_WriteByte(EEAddr_TALA, TimeALA);
    DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
    sendError(CMD_OK);
}

void readAlarm (void)
{
    EUSART_Write(SOM);
    EUSART_Write(msg_cmd);
    EUSART_Write(ALA_CLK.h);
    EUSART_Write(ALA_CLK.m);
    EUSART_Write(ALA_CLK.s);
    EUSART_Write(ALAT);
    EUSART_Write(ALAL);
    EUSART_Write((alarms & ALARM_A ? 1 : 0));
    EUSART_Write(EOM);
}

void setAlarmClock(uint8_t* msg_data)
{
    if(msg_data[0] > 23 || msg_data[1] > 59 || msg_data[2] > 59)
    {
        sendError(CMD_ERROR);
        return;
    }
    
    (&ALA_CLK)->h = msg_data[0];
    (&ALA_CLK)->m = msg_data[1];
    (&ALA_CLK)->s = msg_data[2];
    DATAEE_WriteByte(EEAddr_ALAH, ALA_CLK.h);
    DATAEE_WriteByte(EEAddr_ALAM, ALA_CLK.m);
    DATAEE_WriteByte(EEAddr_ALAS, ALA_CLK.s);
    DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
    sendError(CMD_OK);
}

void setAlarmTempLumin(uint8_t* msg_data)
{
    if(msg_data[0] > 50 || msg_data[1] > 7)
    {
        sendError(CMD_ERROR);
        return;
    }
    
    ALAT = msg_data[0];
    ALAL = msg_data[1];
    DATAEE_WriteByte(EEAddr_ALAT, ALAT);
    DATAEE_WriteByte(EEAddr_ALAL, ALAL);
    DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
    sendError(CMD_OK);
}

void setAlarmCom(uint8_t* msg_data)
{
    if(msg_data[0] > 1)
    {
        sendError(CMD_ERROR);
        return;
    }
    if(msg_data[0] == 0)
        alarms = (alarms & ALARM_A ? alarms ^= ALARM_A : alarms);
    
    if(msg_data[0] == 1)
        alarms |= ALARM_A;
    
    DATAEE_WriteByte(EEAddr_ALARMS, alarms);
    DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
    sendError(CMD_OK);
}

void readReg(void)
{
    EUSART_Write(SOM);
    EUSART_Write(msg_cmd);
    EUSART_Write(NREG);
    EUSART_Write((full_reg ? NREG : nreg/5));
    EUSART_Write(iread); // wasn't sure what to put here
    EUSART_Write(nreg/5); // same
    EUSART_Write(EOM);
}

void transferCurrent(uint8_t* msg_data) // not finished
{
    unsigned char i;
    
    if(msg_data[0] > 25)
    {
        sendError(CMD_ERROR);
        return;
    }
    
    EUSART_Write(SOM);
    EUSART_Write(msg_cmd);
    
    for(i = 0; i<msg_data[0]; i++)
    {
        EUSART_Write(DATAEE_ReadByte(EEAddr_reg + iread));
        EUSART_Write(DATAEE_ReadByte(EEAddr_reg + iread+1));
        EUSART_Write(DATAEE_ReadByte(EEAddr_reg + iread+2));
        EUSART_Write(DATAEE_ReadByte(EEAddr_reg + iread+3));
        EUSART_Write(DATAEE_ReadByte(EEAddr_reg + iread+4));
        iread += 5;
        iread = (iread >= 125 ? 0 : iread);
    }
    EUSART_Write(EOM);
}

void transferIndex (uint8_t* msg_data)
{
    unsigned char i;
    
    if(msg_data[0] > 25 || msg_data[1]>NREG-1)
    {
        sendError(CMD_ERROR);
        return;
    }
    
    EUSART_Write(SOM);
    EUSART_Write(msg_cmd);
    iread = msg_data[1]*5;
    for(i = 0; i<msg_data[0]; i++)
    {
        EUSART_Write(DATAEE_ReadByte(EEAddr_reg + iread));
        EUSART_Write(DATAEE_ReadByte(EEAddr_reg + iread+1));
        EUSART_Write(DATAEE_ReadByte(EEAddr_reg + iread+2));
        EUSART_Write(DATAEE_ReadByte(EEAddr_reg + iread+3));
        EUSART_Write(DATAEE_ReadByte(EEAddr_reg + iread+4));
        iread += 5;
        iread = (iread >= 125 ? 0 : iread);
    }
    EUSART_Write(EOM);
}

void memNotification(void)
{
    EUSART_Write(SOM);
    EUSART_Write(msg_cmd);
    EUSART_Write((half_reg ? 1 : 0)); 
    EUSART_Write(EOM);
}