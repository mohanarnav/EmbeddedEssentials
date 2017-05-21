/*
 * main.cpp
 *
 *  Created on: May 20, 2017
 *      Author: arnavm89
 */


#include "mbed.h"
#include "ADXL345_I2C.h"
#include "TextLCD.h"

 ADXL345_I2C accelerometer(p9, p10);
 Serial pc(USBTX, USBRX);
 TextLCD lcd(p24, p25, p26, p27, p28, p29, p30); // rs, rw, e, d0, d1, d2, d3

const int addr = 0x90;
char config_t[3];

char temp_read[2];
char accel_read[2];
float temp_data;
float x_float =0;
float y_float =0;
float z_float =0;

int main() {

	pc.baud(9600);
    int readings[3] = {0, 0, 0};

    pc.printf("Starting ADXL345 test...\n");
    wait(.001);
    pc.printf("Device ID is: 0x%02x\n", accelerometer.getDeviceID());
    wait(.001);

    // These are here to test whether any of the initialization fails. It will print the failure
    if (accelerometer.setPowerControl(0x00)){
        pc.printf("didn't intitialize power control\n");
        return 0;  }
    //Full resolution, +/-16g, 4mg/LSB.
    wait(.001);

    if(accelerometer.setDataFormatControl(0x0B)){
       pc.printf("didn't set data format\n");
       return 0;  }
    wait(.001);

    //3.2kHz data rate.
    if(accelerometer.setDataRate(ADXL345_3200HZ)){
       pc.printf("didn't set data rate\n");
       return 0;    }
    wait(.001);

    //Measurement mode.

    if(accelerometer.setPowerControl(MeasurementMode)) {
       pc.printf("didn't set the power control to measurement\n");
       return 0;   }

    while (1) {

        wait(0.1);

        // accelerometer initialization
        accelerometer.setPowerControl(0x00);
        accelerometer.setDataFormatControl(0x0B);
        accelerometer.setDataRate(ADXL345_3200HZ);
        accelerometer.setPowerControl(MeasurementMode);
        accelerometer.getOutput(readings);

        x_float = (float) (0.04 * (int16_t) readings[0]);
        y_float = (float) (0.04 * (int16_t) readings[1]);
        z_float = (float) (0.04 * (int16_t) readings[2]);

        lcd.cls();
        lcd.locate(2, 0);
        lcd.printf("Accel Readings: ");
        wait(2);
        lcd.cls();
        lcd.locate(2, 0);
        lcd.printf("x = %+1.2fg", x_float);
        wait(2);
        lcd.cls();
        lcd.locate(2, 0);
        lcd.printf("y = %+1.2fg", y_float);
        wait(2);
        lcd.cls();
        lcd.locate(2, 0);
        lcd.printf("z = %+1.2fg", z_float);
        wait(2);
        lcd.cls();
        wait(1);

        // Modifying i2c for temperature sensor

        config_t[0] = 0x01;
        //set pointer reg to 'config register'
        config_t[1] = 0x60;
        // config data byte1
        config_t[2] = 0xA0;
        // config data byte2

        accelerometer.i2c_.write(addr, config_t, 3);
    	config_t[0] = 0x00;
    	//set pointer reg to 'data register'
    	accelerometer.i2c_.write(addr, config_t, 1);
    	//send to pointer 'read temp'

    	wait(1);
    	//read the two-byte temp data
    	accelerometer.i2c_.read(addr, temp_read, 2);
    	temp_data = 0.0625 * (((temp_read[0] << 8) + temp_read[1]) >> 4); //convert data
    	lcd.cls();
    	lcd.locate(2,0);
    	lcd.printf("Temperature: ");
    	wait(2);
    	lcd.cls();
    	lcd.locate(2,0);
    	lcd.printf("%.2f degC", temp_data);
    	wait(2);
    	lcd.cls();

    }

}

