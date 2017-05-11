
#include "sensor.h"
#include "bt.h"
#include "mbed.h"
#include<queue>
#include<stdio.h>

using namespace std;

AnalogIn hr_pin(p15);
AnalogIn gsr_pin(p17);
DigitalOut led(LED1);
Serial bt_out(p9,p10);

Sensor gsr(GSR , 44100, &gsr_pin);
BT bt(&bt_out, 9600);

int main()
{

	while(1){
		gsr.Task();

		if(buffer.size()>1000){
			led=1;
		}
	}
	return 0;
}
