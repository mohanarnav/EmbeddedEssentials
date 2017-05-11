/*
 * bt.h
 *
 *  Created on: May 10, 2017
 *      Author: arnavm89
 */

#ifndef COURSEPROJECT_BT_H_
#define COURSEPROJECT_BT_H_

#include "mbed.h"

class BT {

private:

	uint8_t data;
	Serial* dev;

public:

	BT(Serial* d, int32_t speed);
	void sendData(int32_t length);

};

#endif /* COURSEPROJECT_BT_H_ */
