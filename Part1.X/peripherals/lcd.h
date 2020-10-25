/* 
 * File:   lcd.h
 * Author: alexandre
 *
 * Created on October 25, 2020, 4:27 PM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

#define LCD_ADDR 0x4e // 0x27 << 1
#define LCD_BL 0x08
#define LCD_EN 0x04
#define LCD_RW 0x02
#define LCD_RS 0x01

void LCDsend(unsigned char c);
unsigned char LCDrecv(unsigned char mode);
void LCDsend2x4(unsigned char c, unsigned char mode);
void LCDcmd(unsigned char c);
void LCDchar(unsigned char c);
void LCDstr(unsigned char *p);
int LCDbusy();
void LCDinit(void);


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

