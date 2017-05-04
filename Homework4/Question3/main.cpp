#include "mbed.h"

#define BufLength 5000
#define ADC_CONVERSION_TIME 0.000020382
#define DAC_COMPENSATION 0.000004586
AnalogIn in(p15);
AnalogOut out(p18);
PwmOut pwm(p21);

float buffer[BufLength];

int main() {

	pwm.period(0.001);		// BW of sq wave is 10kHz assuming it's bandlimited at 10th harmonic.
	pwm.write(0.5);			// Nyquist rate = 20 Khz.

	for(int i=0; i<BufLength; i++){
		buffer[i] = in;
	}

	for(int i=0; i<BufLength; i++){
		printf("%f ",buffer[i]);
	}

	int j=0;

	while(j<BufLength){
		out=buffer[j];
		j++;

		if(j==BufLength){
			j=0;
		}

		wait(ADC_CONVERSION_TIME-DAC_COMPENSATION);

	}

}

