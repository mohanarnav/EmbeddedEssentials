/*
 * main.cpp
 *
 *  Created on: Apr 30, 2017
 *      Author: arnavm89
 */

#include "mbed.h"

AnalogIn in(p15);
PwmOut out(p21);

int main() {

	float ratio;

	out.period(0.001);

	while(1){

		float inVal;
		inVal = in;

		ratio = inVal/1.4;
		out.write(ratio);
	}




}

