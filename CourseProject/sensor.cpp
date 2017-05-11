/*
 * sensor.cpp
 *
 *  Created on: May 2, 2017
 *      Author: arnavm89
 */

#include "sensor.h"

queue<Buffer> buffer;

Sensor::Sensor(SensorType s, uint32_t r, AnalogIn* i){

	sensor_type = s;
	sampling_rate = r;
	in=i;
	data=0;
}

void Sensor::Task(void){

	data = *in;
	printf("%f ", data);
	buffer.push({sensor_type, data});

	if(buffer.size()>1000)
	{
		buffer.pop();
	}

}
