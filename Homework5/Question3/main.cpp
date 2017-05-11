/*
 * main.cpp
 *
 *  Created on: May 10, 2017
 *      Author: arnavm89
 */

#include "ADXL345.h"

ADXL345 accelerometer(p5, p6, p7, p8);
Serial pc(USBTX, USBRX);

int main() {

    int readings[3] = {0, 0, 0};

    pc.printf("Starting ADXL345 test...\n");
    pc.printf("Device ID is: 0x%02x\n", accelerometer.getDevId());

    //Go into standby mode to configure the device.
    accelerometer.setPowerControl(0x00);

    //Full resolution, +/-16g, 4mg/LSB.
    accelerometer.setDataFormatControl(0x0B);

    //3.2kHz data rate.
    accelerometer.setDataRate(ADXL345_3200HZ);

    //Measurement mode.
    accelerometer.setPowerControl(0x08);

    while (1) {

        wait(0.1);

        accelerometer.getOutput(readings);

        //13-bit, sign extended values.
        pc.printf("%i, %i, %i\n", (int16_t)readings[0], (int16_t)readings[1], (int16_t)readings[2]);

    }

}
