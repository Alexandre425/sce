#include "comunication.h"
#include "../config.h"
#include "../mcc_generated_files/eusart.h"
#include "../peripherals/lcd.h"
#include "../mcc_generated_files/memory.h"

// Command from message received
uint8_t msg_cmd;
uint8_t msg_data[7];

void readMessage(void)
{
    uint8_t som = 0;

    while (som!=SOM){
        som = EUSART_Read();
    }
    
    msg_cmd = EUSART_Read();
    
    for(unsigned char i= 0; i<7 ; i++){
        msg_data[i] = EUSART_Read();
        if (msg_data[i]==EOM)
            break;
    }
    
    processMessage();
    return;
}

void processMessage (void)
{   
    EUSART_Write(SOM);
    EUSART_Write(msg_cmd);
    switch(msg_cmd){
        case RCLK:
            readClock();
            break;
            
        case SCLK:
            setClock();
            break;
            
        case RTL:
            readTempLumin();
            break;
            
        case RPAR:
            readParam();
            break;
            
        case MMP:
            modifyPMONITOR();
            break;
            
        case MTA:
            modifyTimeAlarm();
            break;
            
        case RALA:
            readAlarm();
            break;
            
        case DAC:
            setAlarmClock();
            break;
            
        case DATL:
            setAlarmTempLumin();
            break;
            
        case AALA:
            setAlarmCom();
            break;
            
        case IREG:
            readReg();
            break;
            
        case TRGC:
            transferCurrent();
            break;
            
        case TRGI:
            transferIndex();
            break;
        default:
            sendError(CMD_ERROR);
            break;
    }
    
}

void sendError (uint8_t msg_ok)
{
    EUSART_Write(msg_ok);
    EUSART_Write(EOM);
}

void readClock(void)
{
    EUSART_Write(clk.h);
    EUSART_Write(clk.m);
    EUSART_Write(clk.s);
    EUSART_Write(EOM);
}

void setClock(void)
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
    EUSART_Write(temp);
    EUSART_Write(luminosity);
    EUSART_Write(EOM);
}

void readParam (void)
{
    EUSART_Write(PMONITOR);
    EUSART_Write(TimeALA);
    EUSART_Write(EOM);
}

void modifyPMONITOR(void)
{
    if( msg_data[0] < 0 || msg_data[0] > 99)
    {
        sendError(CMD_ERROR);
        return;
    }
    PMONITOR = msg_data[0];
    DATAEE_WriteByte(EEAddr_PMON, PMONITOR);
    DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
    sendError(CMD_OK);
}

void modifyTimeAlarm(void)
{
    if(msg_data[0] < 0 || msg_data[0] > 59 )
    {
        sendError(CMD_ERROR);
        return;
    }
    TimeALA = msg_data[0];
    pwm_max_count = (TimeALA*1000)/30;
    DATAEE_WriteByte(EEAddr_TALA, TimeALA);
    DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
    sendError(CMD_OK);
}

void readAlarm (void)
{
    EUSART_Write(ALA_CLK.h);
    EUSART_Write(ALA_CLK.m);
    EUSART_Write(ALA_CLK.s);
    EUSART_Write(ALAT);
    EUSART_Write(ALAL);
    if(alarms & ALARM_A)
        EUSART_Write(1);
    else
        EUSART_Write(0);
    EUSART_Write(EOM);
}

void setAlarmClock(void)
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

void setAlarmTempLumin(void)
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

void setAlarmCom(void)
{
    if (msg_data[0] > 1) {
        sendError(CMD_ERROR);
        return;
    }
    if (msg_data[0] == 0)
        if(alarms & ALARM_A)
            alarms = alarms ^= ALARM_A;
        else
            alarms = alarms;

    if (msg_data[0] == 1)
        alarms |= ALARM_A;

    DATAEE_WriteByte(EEAddr_ALARMS, alarms);
    DATAEE_WriteByte(EEAddr_CHECKSUM, addChecksum());
    sendError(CMD_OK);
}

void readReg(void)
{
    EUSART_Write(NREG);
    if(iread > nreg){
        EUSART_Write((nreg/5)+25-iread/5);
    } else {    
        EUSART_Write((nreg/5) - iread/5);
    }
    EUSART_Write(iread/5);
    EUSART_Write(nreg/5);
    EUSART_Write(EOM);
}

void transferCurrent(void)
{
    unsigned char i,j;
    if(msg_data[0] > 25)
    {
        sendError(CMD_ERROR);
        return;
    }

    if(iread > nreg){
        if(!full_reg)
            EUSART_Write(0);
        else {
            if((nreg/5)+25-iread/5 > msg_data[0])
                EUSART_Write(msg_data[0]);
            else
                EUSART_Write((nreg/5)+25-iread/5);
        }
    } else {    
        if((nreg/5) - iread/5 > msg_data[0])
            EUSART_Write(msg_data[0]);
        else
            EUSART_Write((nreg/5) - iread/5);
    }

    for(i = 0; i<msg_data[0] && iread != nreg; i++)
    {
        for(j = 0; j<5; j++){
            EUSART_Write(DATAEE_ReadByte(EEAddr_reg + iread+j));
        }
        iread += 5;
        if((iread+5)>=125)
            iread = 0;
        else
            iread = iread+5;
    }
    EUSART_Write(EOM);
    
}

void transferIndex (void)
{
    unsigned char i, j, index;

    index = msg_data[1]*5;
    
    if(!full_reg){
        if(index > nreg){
            EUSART_Write(0); // no reg sent
            EUSART_Write(0); // index
        } else {   
            if((nreg/5) - index/5 > msg_data[0] ){
                EUSART_Write(msg_data[0]);
                EUSART_Write((nreg/5));
            }else{
                EUSART_Write((nreg/5) - index/5);
                EUSART_Write(nreg/5);
            }

            for(i = 0; i<msg_data[0] && index < nreg; i++)
            {
                for(j = 0; j<5; j++){
                    EUSART_Write(DATAEE_ReadByte(EEAddr_reg + index+j));
                }
                index += 5;
                if((index+5)>=125)
                    index = 0;
                else
                    index = index+5;
            }
        }
        EUSART_Write(EOM);
        return;
    }
    EUSART_Write(msg_data[0]);
    if ((index/5 + msg_data[0]) > 24)
        EUSART_Write((index/5 + msg_data[0])-24 );
    else
        EUSART_Write(index/5 + msg_data[0]);
        
    for(i = 0; i<msg_data[0]; i++)
    {
        for(j = 0; j<5; j++){
            EUSART_Write(DATAEE_ReadByte(EEAddr_reg + index+j));
        }
        index += 5;
        if((index+5)>=125)
            index = 0;
        else
            index = index+5;
    }
    EUSART_Write(EOM);
}

