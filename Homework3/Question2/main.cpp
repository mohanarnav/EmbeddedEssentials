#include "mbed.h"


DigitalIn enable(p5);
DigitalOut led(LED1);
DigitalOut out(p21);
int main()
{

   	while(1){

   		if(enable){

   			led=1;
   			wait(0.025);
   			led=0;
   			wait(0.025);

   		}else{

   			led=1;
   			wait(0.05);
   			led=0;
   			wait(0.05);

   		}
   	}

}
