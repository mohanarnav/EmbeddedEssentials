/*
 * main.cpp
 *
 *  Created on: Apr 30, 2017
 *      Author: arnavm89
 */
#include "mbed.h"

AnalogIn in(p15);
AnalogOut out(p18);

int main() {

	while(1){

		float ratio = in;
		out = ratio;
		printf("%f ", ratio);
	}


}
