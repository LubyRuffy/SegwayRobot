#ifndef IMU_H
#define IMU_H

/** Configs **/
#include "config.h"
#include "pinout.h"

/** Libraries **/
#include <Arduino.h>
#include <Thread.h>
#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050_6Axis_MotionApps20.h>
#include <math.h>

/** Modules **/
#include "System.h"


class IMU: public Thread{
private:
	MPU6050 mpu;

	// Is the DMP in MPU enabled?
	bool dmpEnabled;

	// Last saved packet
	uint8_t packet[64];

	uint8_t fifoCount;
	uint8_t interruptStatus;

public:
	bool newData;

	bool init();

	// Checks if the Thread should run (Time && Enabled && FIFO buffer)
	bool shouldRun(unsigned long time);

	// Override the usual Run method
	void run();

	Quaternion q;
	VectorFloat gravity;
	float ypr[3];
};

#endif // IMU_H