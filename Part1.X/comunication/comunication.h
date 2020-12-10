/* 
 * File:   newfile.h
 * Author: rafae
 *
 * Created on November 16, 2020, 11:36 AM
 */

#ifndef COMUNICATION_H
#define	COMUNICATION_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
    
/* It is assumed that SOM and EOM values do not occur in the message */
#define SOM 0xFD /* start of message */
#define EOM 0xFE /* end of message */
#define RCLK 0xC0 /* read clock */
#define SCLK 0xC1 /* set clock */
#define RTL 0xC2 /* read temperature and luminosity */
#define RPAR 0xC3 /* read parameters */
#define MMP 0xC4 /* modify monitoring period */
#define MTA 0xC5 /* modify time alarm */
#define RALA 0xC6 /* read alarms (clock, temperature, luminosity, active/inactive) */
#define DAC 0xC7 /* define alarm clock */
#define DATL 0xC8 /* define alarm temperature and luminosity */
#define AALA 0xC9 /* activate/deactivate alarms */
#define IREG 0xCA /* information about registers (NREG, nr, iread, iwrite)*/
#define TRGC 0xCB /* transfer registers (curr. position)*/
#define TRGI 0xCC /* transfer registers (index) */
#define NMFL 0xCD /* notification memory (half) full */
#define CMD_OK 0x00 /* command successful */
#define CMD_ERROR 0xFF /* error in command */

void readMessage(void); // Reads the message
void processMessage (void); // Processes the command and calls fucntions to handle command
void sendError (uint8_t); // Sends a reply with ok or error
/* Handlers for commands */
void readClock(void);
void setClock(void);
void readTempLumin(void);
void readParam(void);
void modifyPMONITOR(void);
void modifyTimeAlarm(void);
void readAlarm (void);
void setAlarmClock(void);
void setAlarmTempLumin(void);
void setAlarmCom(void);
void readReg(void);
void transferCurrent(void);
void transferIndex (void);
//void memNotification(void);
//void checkMem(void);


#ifdef	__cplusplus
}
#endif

#endif	/* COMUNICATION_H */

