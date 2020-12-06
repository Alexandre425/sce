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
#define SCLK 0XC1 /* set clock */
#define RTL 0XC2 /* read temperature and luminosity */
#define RPAR 0XC3 /* read parameters */
#define MMP 0XC4 /* modify monitoring period */
#define MTA 0XC5 /* modify time alarm */
#define RALA 0XC6 /* read alarms (clock, temperature, luminosity, active/inactive) */
#define DAC 0XC7 /* define alarm clock */
#define DATL 0XC8 /* define alarm temperature and luminosity */
#define AALA 0XC9 /* activate/deactivate alarms */
#define IREG 0XCA /* information about registers (NREG, nr, iread, iwrite)*/
#define TRGC 0XCB /* transfer registers (curr. position)*/
#define TRGI 0XCC /* transfer registers (index) */
#define NMFL 0XCD /* notification memory (half) full */
#define CMD_OK 0x00 /* command successful */
#define CMD_ERROR 0xFF /* error in command */

void* readMessage(void); // Reads the message
void processMessage (uint8_t *); // Processes the command and calls fucntions to handle command
void sendError (unsigned char ); // Sends a reply with ok or error
/* Handlers for commands */
void readClock(void);
void setClock(uint8_t*);
void readTempLumin(void);
void readParam(void);
void modifyPMONITOR(uint8_t);
void modifyTimeAlarm(uint8_t);



// Command from message received
uint8_t msg_cmd;

#ifdef	__cplusplus
}
#endif

#endif	/* COMUNICATION_H */

