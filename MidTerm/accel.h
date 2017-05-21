/*
 * accel.h
 *
 *  Created on: May 16, 2017
 *      Author: arnavm89
 */

#ifndef MIDTERM_ACCEL_H_
#define MIDTERM_ACCEL_H_

#include <stdint.h>
#include "mbed.h"


class Accel
{
private:

	SPI* acc;
	DigitalOut* cs;

public:
	int16_t x_int;
	int16_t y_int;
	int16_t z_int;

	float x_float;
	float y_float;
	float z_float;

	char buffer[6];

	Accel(SPI* sp, DigitalOut* d_out);
	void getData_int(void);
	void getData_float(void);
	void printData_int(void);
	void printData_float(void);
};


#endif /* MIDTERM_ACCEL_H_ */
