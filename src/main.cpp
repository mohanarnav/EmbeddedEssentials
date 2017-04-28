#include "mbed.h"

PwmOut PWM(p21);
PwmOut PWM2(LED1);
DigitalIn enable(p5);

int main()
{
	PWM.period(0.1);
	PWM2.period(0.1);

   	PWM=0.5;
   	PWM2=0.5;

   	while(1){

   		if(enable){
   			PWM.period(0.05);
   			PWM2.period(0.05);

   			PWM=0.5;
   			PWM2=0.5;
   		}else{
   			PWM.period(0.1);
   			PWM2.period(0.1);

   			PWM=0.5;
   			PWM2=0.5;
   		}
   	}

}
