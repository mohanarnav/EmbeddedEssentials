#include "mbed.h"
#include "7segment.h"


int main()
{

	Segment S1(p5,p6,p7,p8,p9,p10,p11);
	Segment S2(p12,p13,p14,p15,p16,p17,p18);
	Segment S3(p19,p20,p21,p22,p23,p24,p25);

	int32_t count=0;

	int32_t temp;
	int32_t d0;
	int32_t d1;
	int32_t d2;

   	while(1){

   		temp=count;
   		d0 = temp%16;
   		temp = temp>>4;
   		d1 = temp%16;
   		temp = temp>>4;
   		d2 = temp;

   		S1.segmentDisplay(d0);
   		S2.segmentDisplay(d1);
   		S3.segmentDisplay(d2);


   		wait(0.5);

   		count++;

   		if(count>4095){
   			count=0;
   		}



   	}


}

