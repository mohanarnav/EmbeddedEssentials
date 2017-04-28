/*
 * 7segment.h
 *
 *  Created on: Apr 27, 2017
 *      Author: arnavm89
 */

#ifndef INC_7SEGMENT_H_
#define INC_7SEGMENT_H_
#include "mbed.h"
#include<stdint.h>


class Segment{

private:
	PinName L1;
	PinName L2;
	PinName L3;
	PinName L4;
	PinName L5;
	PinName L6;
	PinName L7;

public:
	Segment(PinName l1,
			PinName l2,
			PinName l3,
			PinName l4,
			PinName l5,
			PinName l6,
			PinName l7);

	void segmentDisplay(int32_t num);

};



#endif /* INC_7SEGMENT_H_ */
