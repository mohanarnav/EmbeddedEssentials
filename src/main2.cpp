/*
 * main.cpp
 *
 *  Created on: Apr 13, 2017
 *      Author: arnavm89
 */

#include "mbed.h"

DigitalOut myLed[4] = {DigitalOut(LED1),DigitalOut(LED2),DigitalOut(LED3),DigitalOut(LED4)};

int main(){

	int i=0;
	int itr=1;

	while(1){

		if(i==3){
			itr=-1;
		}

		if(i==0){
			itr=1;
		}

		myLed[i]=1;
		wait(0.75);
		myLed[i]=0;

		i+=itr;
	}

}

