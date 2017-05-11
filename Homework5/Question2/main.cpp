/*
 * main.cpp
 *
 *  Created on: May 10, 2017
 *      Author: arnavm89
 */

#include "mbed.h"

InterruptIn button(p18);
Ticker ticker1;
Ticker ticker2;
Timer debounce;

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);


void toggle1(void);
void toggle2(void);
void toggle3(void);

int main()
{

	ticker1.attach(&toggle1,1.0);
	ticker2.attach(&toggle2,0.5);

	debounce.start();
	button.rise(&toggle3);


	while(1)

	{
		wait(0.25);
	}

}

void toggle1(void){
	led1 = !led1;
}

void toggle2(void){
	led2 = !led2;
}

void toggle3(void){
	if(debounce.read_ms()>500){
		led3 = !led3;
		debounce.reset();
	}
}

