/*
 * tempSensor.cpp
 *
 *  Created on: May 20, 2017
 *      Author: arnavm89
 */

#include "tempSensor.h"

 //sda, sc1
Serial pc(USBTX, USBRX); //tx, rx
const int addr = 0x90;
char config_t[3];
char temp_read[2];
float data;

TempSensor::TempSensor(I2C* ic)
{
	tempsensor = ic;

	config_t[0] = 0x01;
	//set pointer reg to 'config register'
	config_t[1] = 0x60;
	// config data byte1
	config_t[2] = 0xA0;
	// config data byte2
	tempsensor->write(addr, config_t, 3);
	config_t[0] = 0x00;
	//set pointer reg to 'data register'
	tempsensor->write(addr, config_t, 1);
	//send to pointer 'read temp'
}


void TempSensor::getReadings(void){

	wait(1);
	//read the two-byte temp data
	tempsensor->read(addr, temp_read, 2);
	data = 0.0625 * (((temp_read[0] << 8) + temp_read[1]) >> 4); //convert data
	pc.printf("Temp = %.2f degC\n\r", data);
}
