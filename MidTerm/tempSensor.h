/*
 * tempSensor.h
 *
 *  Created on: May 20, 2017
 *      Author: arnavm89
 */

#ifndef MIDTERM_TEMPSENSOR_H_
#define MIDTERM_TEMPSENSOR_H_

#include "mbed.h"

class TempSensor{

private:
	I2C* tempsensor;

public:

	float data;

	TempSensor(I2C* ic);
	void getReadings(void);
};



#endif /* MIDTERM_TEMPSENSOR_H_ */
