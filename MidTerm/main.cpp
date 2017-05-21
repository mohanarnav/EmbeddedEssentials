/*
 * main.cpp
 *
 *  Created on: May 16, 2017
 *      Author: arnavm89
 */

#include "accel.h"
#include "TextLCD.h"

SPI sp(p11,p12,p13); // setup SPI interface on pins 11,12,13
DigitalOut cs(p14); // use pin 14 as chip select
DigitalOut led(LED1);
DigitalOut led2(LED2);

InterruptIn cal_but(p18);
InterruptIn lcd_but(p17);

Timer debounce;

int count;
uint8_t file_flag = 0;
uint8_t lcd_flag = 0;



TextLCD lcd(p24, p25, p26, p27, p28, p29, p30); // rs, rw, e, d0, d1, d2, d3
Accel accel(&sp, &cs);
LocalFileSystem local("local");
void toggle(void);
void Calibrate(FILE* fp, int count);
void isr2(void);

int main()
{

	// Setting up custom calibration
	debounce.start();
	cal_but.rise(&toggle);
	lcd_but.rise(&isr2);

	FILE *fp;
	printf("testing communication \n");

	while(1){

		if(file_flag == 1)
		{

			Calibrate(fp, count);
			file_flag = 0;
			wait(1);
		}

		if(lcd_flag == 1)
		{
			accel.getData_float();
			printf("Displaying on the LCD \n");
			lcd.cls();
			lcd.locate(2, 0);
			lcd.printf("Accel Readings: ");
			wait(2);
			lcd.cls();
			lcd.locate(2, 0);
			lcd.printf("x = %+1.2fg", accel.x_float);
			wait(2);
			lcd.cls();
			lcd.locate(2, 0);
			lcd.printf("y = %+1.2fg", accel.y_float);
			wait(2);
			lcd.cls();
			lcd.locate(2, 0);
			lcd.printf("z = %+1.2fg", accel.z_float);
			wait(2);
			lcd.cls();
			lcd_flag=0;
			led2 =0;
		}
		wait(1);

	}

}

void isr2(void){

	if(debounce.read_ms()>500){
			led2 = 1;
			debounce.reset();
			lcd_flag = 1;

	}

}

void toggle(void){
	if(debounce.read_ms()>500){
		led = 1;
		debounce.reset();
		file_flag = 1;
		count++;
		if(count>7)
		{
			count = 0;
			led = 0;
		}

	}
}

void Calibrate(FILE* fp, int count)
{
  switch(count)
							{
							case 1: printf("begin calibration; press the button when ready for +z axis \n");
									fp = fopen("/local/calibration_report.txt", "w");
									fprintf(fp, "Calibrations for accelerometer axes: \n");
									fclose(fp);
									accel.printData_float();
									break;
							case 2: printf("+z calibrated, prepare for -z axis \n");
									accel.getData_float();
									fp = fopen("/local/calibration_report.txt", "a");
									fprintf(fp, "+z axis:  x = %+1.2fg, y = %+1.2fg, z = %+1.2fg \n  ", accel.x_float, accel.y_float, accel.z_float);
									fclose(fp);
									accel.printData_float();
									break;
							case 3: printf("-z calibrated, prepare for +x axis \n");
									accel.getData_float();
									fp = fopen("/local/calibration_report.txt", "a");
									fprintf(fp, "-z axis:  x = %+1.2fg, y = %+1.2fg, z = %+1.2fg \n  ", accel.x_float, accel.y_float, accel.z_float);
									fclose(fp);
									accel.printData_float();
									break;
							case 4: printf("+x calibrated, prepare for -x axis \n");
									accel.getData_float();
									fp = fopen("/local/calibration_report.txt", "a");
									fprintf(fp, "+x axis:  x = %+1.2fg, y = %+1.2fg, z = %+1.2fg \n  ", accel.x_float, accel.y_float, accel.z_float);
									fclose(fp);
									accel.printData_float();
									break;
							case 5: printf("-x calibrated, prepare for +y axis \n");
									accel.getData_float();
									fp = fopen("/local/calibration_report.txt", "a");
									fprintf(fp, "-x axis:  x = %+1.2fg, y = %+1.2fg, z = %+1.2fg \n  ", accel.x_float, accel.y_float, accel.z_float);
									fclose(fp);
									accel.printData_float();
									break;
							case 6: printf("+y calibrated, prepare for -y axis \n");
									accel.getData_float();
									fp = fopen("/local/calibration_report.txt", "a");
									fprintf(fp, "+y axis:  x = %+1.2fg, y = %+1.2fg, z = %+1.2fg \n  ", accel.x_float, accel.y_float, accel.z_float);
									fclose(fp);
									accel.printData_float();
									break;
							case 7: printf("-y calibrated, calibration file complete \n");
									accel.getData_float();
									fp = fopen("/local/calibration_report.txt", "a");
									fprintf(fp, "-y axis:  x = %+1.2fg, y = %+1.2fg, z = %+1.2fg \n  ", accel.x_float, accel.y_float, accel.z_float);
									fclose(fp);
									accel.printData_float();
									break;
							default: break;
					}

}
