/* Test which brings default HelloWorld project from mbed online compiler
   to be built under GCC.
*/
#include "mbed.h"

PwmOut PWM(p21);
PwmOut PWM2(LED1);

int main()
{
	PWM.period(0.1f);
	PWM2.period(0.1f);

   	PWM.write(0.5);
   	PWM2.write(0.5);

   	while(1);

}

