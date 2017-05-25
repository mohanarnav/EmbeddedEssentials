
#include "sensor.h"
#include "bt.h"
#include "mbed.h"
#include<stdio.h>

using namespace std;

AnalogIn hr_pin(p17);
AnalogIn gsr_pin(p15);
DigitalOut led(LED1);
Serial bt_out(p9,p10);

Ticker tick;
/* PwmOut pwm(p21); */

Sensor gsr(GSR , 44100, &gsr_pin);
Sensor hr(HR, 44100, &hr_pin);

BT bt(&bt_out, 9600);

uint8_t flag = 0;

void hrIsr(void);

int main()
{

	tick.attach(&hrIsr,0.008);

/* PWM used for pwm sampling test **

	pwm.period(0.5);
	pwm.write(0.5);

*/

	while(1){

		bt.sendData();
	}
	return 0;
}

void hrIsr(void)
{
	hr.Task();
}
