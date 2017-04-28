#include "7segment.h"

Segment::Segment(PinName l1,
		PinName l2,
		PinName l3,
		PinName l4,
		PinName l5,
		PinName l6,
		PinName l7){
	L1 = l1;
	L2 = l2;
	L3 = l3;
	L4 = l4;
	L5 = l5;
	L6 = l6;
	L7 = l7;


}

void Segment::segmentDisplay(int32_t num){


	DigitalOut LED1(L1);
	DigitalOut LED2(L2);
	DigitalOut LED3(L3);
	DigitalOut LED4(L4);
	DigitalOut LED5(L5);
	DigitalOut LED6(L6);
	DigitalOut LED7(L7);

	switch(num){
	case 0: LED1=1; LED2=1; LED3=1; LED4=0; LED5=1; LED6=1; LED7=1; break;
	case 1: LED1=0; LED2=0; LED3=1; LED4=0; LED5=0; LED6=1; LED7=0; break;
	case 2: LED1=1; LED2=0; LED3=1; LED4=1; LED5=1; LED6=0; LED7=1; break;
	case 3: LED1=1; LED2=0; LED3=1; LED4=0; LED5=0; LED6=1; LED7=1; break;
	case 4: LED1=0; LED2=1; LED3=1; LED4=1; LED5=0; LED6=1; LED7=0; break;
	case 5: LED1=1; LED2=1; LED3=0; LED4=0; LED5=0; LED6=1; LED7=1; break;
	case 6: LED1=1; LED2=1; LED3=0; LED4=1; LED5=1; LED6=1; LED7=1; break;
	case 7: LED1=1; LED2=0; LED3=1; LED4=0; LED5=0; LED6=1; LED7=0; break;
	case 8: LED1=1; LED2=1; LED3=1; LED4=1; LED5=1; LED6=1; LED7=1; break;
	case 9: LED1=1; LED2=1; LED3=1; LED4=1; LED5=0; LED6=1; LED7=1; break;
	case 10: LED1=1; LED2=1; LED3=1; LED4=1; LED5=1; LED6=1; LED7=0; break;
	case 11: LED1=1; LED2=1; LED3=1; LED4=1; LED5=1; LED6=1; LED7=1; break;
	case 12: LED1=1; LED2=1; LED3=0; LED4=0; LED5=1; LED6=0; LED7=1; break;
	case 13: LED1=1; LED2=1; LED3=1; LED4=0; LED5=1; LED6=1; LED7=1; break;
	case 14: LED1=1; LED2=1; LED3=0; LED4=1; LED5=1; LED6=0; LED7=1; break;
	case 15: LED1=1; LED2=1; LED3=0; LED4=1; LED5=1; LED6=0; LED7=0; break;
	default: break;

	}

}
