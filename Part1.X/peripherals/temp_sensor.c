#include "temp_sensor.h"
#include "../I2C/i2c.h"
#include "../mcc_generated_files/mcc.h"
#include "../config.h"

unsigned char tsttc(void)
{
	unsigned char value;
	do
	{
		IdleI2C();
		StartI2C();
		IdleI2C();

		WriteI2C(0x9a | 0x00);
		IdleI2C();
		WriteI2C(0x01);
		IdleI2C();
		RestartI2C();
		IdleI2C();
		WriteI2C(0x9a | 0x01);
		IdleI2C();
		value = ReadI2C();
		IdleI2C();
		NotAckI2C();
		IdleI2C();
		StopI2C();
	} while (!(value & 0x40));

	IdleI2C();
	StartI2C();
	IdleI2C();
	WriteI2C(0x9a | 0x00);
	IdleI2C();
	WriteI2C(0x00);
	IdleI2C();
	RestartI2C();
	IdleI2C();
	WriteI2C(0x9a | 0x01);
	IdleI2C();
	value = ReadI2C();
	IdleI2C();
	NotAckI2C();
	IdleI2C();
	StopI2C();

	return value;
}


unsigned char readTemp(void)
{
    unsigned char read;   
    read = tsttc();
    
    return (read > 50 ? 50 : read);
}