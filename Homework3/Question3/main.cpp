#include "mbed.h"


DigitalIn enable(p5);
DigitalOut led(LED1);

int main() {

    int count = 0;

    led=0;
    while(1) {

        if (enable) {

        	count++;

            if (count==10){
                    led = 1;
                    count = 0;
                }

            }


        }

}
