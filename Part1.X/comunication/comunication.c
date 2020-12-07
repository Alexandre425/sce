#include "comunication.h"
#include "../config.h"
#include "../mcc_generated_files/eusart.h"
#include "../peripherals/lcd.h"

void* readMessage(void)
{
    uint8_t som = 0;
    uint8_t msg_data[7];
    
    LCDcmd(0xc8);
    LCDstr("A");

    while (som!=SOM){
        som = EUSART_Read();
    }
    
    msg_cmd = EUSART_Read();
    
    for(unsigned char i= 0; i<7 ; i++){
        msg_data[0] = EUSART_Read();
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
            break;
        case DAC:
            break;
        case DATL:
            break;
        case AALA:
            break;
        case IREG:
            break;
        case TRGC:
            break;
        case TRGI:
            break;
        case NMFL:
            break;
        default:
            
            break;
    }
    
}

void sendError (unsigned char msg_ok)
{
    EUSART_Write(SOM);
    EUSART_Write(msg_cmd);
    if(msg_ok == '0'){
        EUSART_Write(CMD_OK); 
    } else if (msg_ok == '1'){
        EUSART_Write(CMD_ERROR);
    }
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
    if(msg_data[0] < 0 || msg_data[0] > 23 ||
            msg_data[1] < 0 || msg_data[1] > 59 ||
            msg_data[2] < 0 || msg_data[2] > 59)
    {
        sendError('1');
        return;
    }
    
    (&clk)->h = msg_data[0];
    (&clk)->m = msg_data[1];
    (&clk)->s = msg_data[2];
    sendError('0');
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
        sendError('1');
        return;
    }
    PMONITOR = msg_data;
    sendError('0');
}

void modifyTimeAlarm(uint8_t msg_data)
{
    if(msg_data < 0 || msg_data > 59 ){
        sendError('1');
        return;
    }
    TimeALA = msg_data;
    pwm_max_count = (TimeALA*1000)/30;
    sendError('0');
}
