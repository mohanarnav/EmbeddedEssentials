/*
 * bt.cpp
 *
 *  Created on: May 10, 2017
 *      Author: arnavm89
 */

#include "bt.h"
#include "sensor.h"

int temp_itr = 0;

BT::BT(Serial* d, int32_t speed){

	dev = d;
	dev->baud(speed);
	data = 0;

}

void BT::sendData(void){


	if(itr!=temp_itr)
	{
		if(itr!=0)
		{
			dev->printf("%+1.2f\n", buffer[itr].data);
		}else{
		    dev->printf("%+1.2f\n", buffer[BUF_LENGTH - 1].data);
		}

		temp_itr = itr;

	}

}

char BT::getData(){

	if(dev->readable())
	{
		return dev->getc();
	}else
	{
		return '0';
	}
}
