/*
 * sensor.cpp
 *
 *  Created on: May 2, 2017
 *      Author: arnavm89
 */

#include "sensor.h"

Buffer buffer[BUF_LENGTH];
DigitalOut extLED(p20);
int itr=0;
uint8_t write_flag = 0;

Sensor::Sensor(SensorType s, uint32_t r, AnalogIn* i){

	sensor_type = s;
	sampling_rate = r;
	in=i;
	data=0;
}

void Sensor::Task(void){

	data = *in;
	buffer[itr] = {sensor_type, data};
	itr++;

	if(itr>BUF_LENGTH-1)
	{
		extLED = !extLED;
		itr=0;
		write_flag=1;
	}


}

