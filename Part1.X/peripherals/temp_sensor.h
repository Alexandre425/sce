/* 
 * File:   temp_sensor.h
 * Author: alexandre
 *
 * Created on October 25, 2020, 4:43 PM
 */

#ifndef TEMP_SENSOR_H
#define	TEMP_SENSOR_H

#ifdef	__cplusplus
extern "C" {
#endif

unsigned char tsttc(void);

// Function to read the temperature
unsigned char readTemp(void);

#ifdef	__cplusplus
}
#endif

#endif	/* TEMP_SENSOR_H */

