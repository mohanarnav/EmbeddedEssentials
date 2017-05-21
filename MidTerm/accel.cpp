/*
 * accel.cpp
 *
 *  Created on: May 16, 2017
 *      Author: arnavm89
 */

#include "accel.h"

Serial pc(USBTX, USBRX);
LocalFileSystem local("local");

Accel::Accel(SPI* sp, DigitalOut* d_out)
{
	x_int = 0;
	y_int = 0;
	z_int = 0;

	x_float = 0.0;
	y_float = 0.0;
	z_float = 0.0;

	acc = sp;
	cs = d_out;

	*cs = 1;

	acc->format(8,3); // 8 bit data, Mode 3
	// acc->frequency(2000000); // 2 MHz clock rate
	acc->frequency(3200);

	*cs = 0;
	acc->write(0x31); // Data format register.
	acc->write(0x0B); // format +/- 16 g ; 0.004g / LSB
	*cs = 1;

	*cs = 0;
	acc->write(0x2D); // Power control register.
	acc->write(0x08); // measure mode
	*cs = 1;

	 pc.baud(9600);
}


void Accel::getData_int(void)
{

	*cs = 0;
	acc->write(0x80|0x40|0x32); // RW bit high, MB bit high, plus address

	for(int i = 0; i < 6; i++)
	{
		buffer[i]=acc->write(0x00); // read back 6 data bytes
	}

	*cs = 1;

	x_int = (short) buffer[1]<<8 | buffer[0];
	y_int = (short) buffer[3]<<8 | buffer[2];
	z_int = (short) buffer[5]<<8 | buffer[4];

}

void Accel::getData_float(void)
{
	getData_int();
	x_float = 0.04 * x_int;
	y_float = 0.04 * y_int;
	z_float = 0.04 * z_int;

}

void Accel::printData_float(void)
{
	//printf("x = %+1.2fg\t y = %+1.2fg\t z = %+1.2fg\n\r  ", x_float, y_float, z_float);
	pc.printf("x = %+1.2fg, y = %+1.2fg, z = %+1.2fg \n  ", x_float, y_float, z_float);
}

void Accel::printData_int(void)
{
	pc.printf("x = %d, y = %d, z = %d \n ", x_int, y_int, z_int);
}





