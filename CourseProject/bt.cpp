/*
 * bt.cpp
 *
 *  Created on: May 10, 2017
 *      Author: arnavm89
 */

#include "bt.h"
#include "sensor.h"

BT::BT(Serial* d, int32_t speed){

	dev = d;
	dev->baud(speed);
	data = 0;

}

void BT::sendData(int32_t length){

	while(length>0){

		Buffer temp = buffer.front();
		buffer.pop();
		data = (uint8_t) (temp.data*128);
		uint8_t sendData = (data << 1) & ( (uint8_t) temp.sensor_type);
		dev->putc((unsigned char) sendData);
		length--;

	}

}
