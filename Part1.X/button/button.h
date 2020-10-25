/* 
 * File:   button.h
 * Author: rafae
 *
 * Created on October 25, 2020, 4:31 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H

#define PRESSED             1
#define NOT_PRESSED         0
#define LEDs                LATA
#define LEDs_SetLow()       do { LATA = 0; } while(0)

uint8_t btnState = NOT_PRESSED;

#endif	/* BUTTON_H */

