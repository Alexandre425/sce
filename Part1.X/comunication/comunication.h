/* 
 * File:   newfile.h
 * Author: rafae
 *
 * Created on November 16, 2020, 11:36 AM
 */

#ifndef NEWFILE_H
#define	NEWFILE_H

#ifdef	__cplusplus
extern "C" {
#endif

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
#define CMD_OK 0 /* command successful */
#define CMD_ERROR 0xFF /* error in command */


#ifdef	__cplusplus
}
#endif

#endif	/* NEWFILE_H */

