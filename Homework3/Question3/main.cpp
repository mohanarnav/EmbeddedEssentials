#include "mbed.h"
#include "DebounceIn.h"

DebounceIn pb(p8);
DigitalOut myled(LED1);


int main() {

    pb.mode(PullUp);
    int count = 0;

    int old_pb=0;
    int new_pb;

    while(1) {

    new_pb = pb;

        if ((new_pb==0) && (old_pb==1)) {

        	count++;

            if (count==10){
                    myled = 1;
                    count = 0;
                }

            }

        	old_pb = new_pb;


        }
}
