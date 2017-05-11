/*
 * main.cpp
 *
 *  Created on: May 10, 2017
 *      Author: arnavm89
 */

#include "mbed.h"
InterruptIn button(p18);
DigitalOut led1(LED1);
Timer debounce; // Interrupt on digital pushbutton input p18

void toggle(void); // function prototype

int main()
{
	debounce.start();
	button.rise(&toggle);
}

void toggle()
{
	if (debounce.read_ms()>500)
	{
		led1=!led1;
		debounce.reset();
	}

}
