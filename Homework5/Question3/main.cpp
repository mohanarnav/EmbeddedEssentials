/*
 * main.cpp
 *
 *  Created on: May 10, 2017
 *      Author: arnavm89
 */

#include "ADXL345.h"

ADXL345 accelerometer(p5, p6, p7, p8);
Serial pc(USBTX, USBRX);
InterruptIn in(p15);

void task(void);

int main() {

    int readings[3] = {0, 0, 0};

    printf("Starting ADXL345 test...\n");
    printf("Device ID is: 0x%02x\n", accelerometer.getDevId());

    //Go into standby mode to configure the device.
    accelerometer.setPowerControl(0x00);

    //Full resolution, +/-16g, 4mg/LSB.
    accelerometer.setDataFormatControl(0x0B);

    //3.2kHz data rate.
    accelerometer.setDataRate(ADXL345_3200HZ);

    accelerometer.setActivityThreshold(75);
    accelerometer.setInactivityThreshold(75);
	accelerometer.setTimeInactivity(10);

    accelerometer.setInterruptEnableControl(0x40);
    accelerometer.setInterruptMappingControl(0x40);
  	accelerometer.setTapAxisControl(0x07);
    accelerometer.setTapDuration(15);
    accelerometer.setTapThreshold(50);
    accelerometer.setTapLatency(80);
    accelerometer.setWindowTime(200);
    accelerometer.setTapLatency(80);


    //Measurement mode.
    accelerometer.setPowerControl(0x08);



    in.rise(&task);

    while (1) {

        wait(0.1);

        accelerometer.getOutput(readings);

        //13-bit, sign extended values.
        printf("%i, %i, %i\n", (int16_t)readings[0], (int16_t)readings[1], (int16_t)readings[2]);

    }

}

void task(void){
	printf("fall experienced");
}
