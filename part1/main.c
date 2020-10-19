#include "mcc_generated_files/mcc.h"
#include "peripherals/i2c.h"
#include "peripherals/lcd.h"
#include "peripherals/temp_sens.h"

void main(void)
{
	unsigned char c;
	unsigned char hc;
	unsigned char lc;
	unsigned char c1;
	unsigned char c2;
	unsigned char buf[17];

	// initialize the device
	SYSTEM_Initialize();

	// When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
	// Use the following macros to:

	// Enable the Global Interrupts
	//INTERRUPT_GlobalInterruptEnable();

	// Enable the Peripheral Interrupts
	//INTERRUPT_PeripheralInterruptEnable();

	// Disable the Global Interrupts
	//INTERRUPT_GlobalInterruptDisable();

	// Disable the Peripheral Interrupts
	//INTERRUPT_PeripheralInterruptDisable();

	i2c1_driver_open();
	I2C_SCL = 1;
	I2C_SDA = 1;
	WPUC3 = 1;
	WPUC4 = 1;
	LCDinit();

	while (1)
	{
		// Add your application code

		NOP();
		c = read_temperature();
		LCDcmd(0x80);
		LCDstr("Temp");
		LCDcmd(0x85);
		sprintf(buf, "Clock %02d", counter);
		LCDstr(buf);
		LCDcmd(0xc0);
		sprintf(buf, "%02d C", c);
		LCDstr(buf);
		LCDcmd(0x81);
		c1 = LCDrecv(0);
		c2 = LCDrecv(LCD_RS);
		LCDcmd(0xc8);
		sprintf(buf, "%02x %02x", c1, c2);
		LCDstr(buf);
		NOP();
		__delay_ms(3000);
	}
}

