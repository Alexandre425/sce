/* 
 * File:   wdt.h
 * Author: alexandre
 *
 * Created on October 25, 2020, 3:52 PM
 */

#ifndef WDT_H
#define	WDT_H

#ifdef	__cplusplus
extern "C" {
#endif

#define WDTEnable()     (WDTCONbits.SWDTEN = 1)
#define WDTDisable()    (WDTCONbits.SWDTEN = 0)

#ifdef	__cplusplus
}
#endif

#endif	/* WDT_H */

