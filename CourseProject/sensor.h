/*
 * sensor.h
 *
 *  Created on: May 2, 2017
 *      Author: arnavm89
 */

#ifndef COURSEPROJECT_SENSOR_H_
#define COURSEPROJECT_SENSOR_H_

#include<stdint.h>
#include "mbed.h"
#include<queue>

using namespace std;

#define BUF_LENGTH 1000

typedef enum
{
	HR,
	GSR
} SensorType;


typedef struct
{
	SensorType sensor_type;
	float data;
} Buffer;


extern Buffer buffer[1000];
extern int itr;
extern uint8_t write_flag;

enum Status
{
	Ready,
	Busy
};

class Sensor
{

	private:

		AnalogIn* in;
		SensorType sensor_type;
		uint32_t sampling_rate;
		float data;

	public:
		Sensor(SensorType s, uint32_t r, AnalogIn* i);
		void Task(void);


};

#endif /* COURSEPROJECT_SENSOR_H_ */
