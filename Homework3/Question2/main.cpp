/* Test which brings default HelloWorld project from mbed online compiler
   to be built under GCC.
*/
#include "mbed.h"
#include "DebounceIn.h"

DebounceIn push(p8);

DigitalOut led1(LED1);

int main() {

    push.mode(PullUp);

    int old_pb=0;
    int new_pb;


    while(1) {

    new_pb = push;

        if ((new_pb==0) && (old_pb==1)) {

           led1 = 0;
           wait(0.025);
           led1 = 1;
           wait(0.025);

            }
        else {

            led1 = 0;
            wait(0.05);
            led1 = 1;
            wait(0.05);

       }

   }

}
