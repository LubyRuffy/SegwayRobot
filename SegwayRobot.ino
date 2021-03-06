/** Configs **/
#include "config.h"
#include "pinout.h"

/** Libraries **/
#include <Thread.h>
#include <ThreadController.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <Wire.h>
#include <I2Cdev.h>
#include "MPU6050_6Axis_MotionApps20.h"

/** Modules **/
#include "System.h"
#include "Debug.h"
#include "Radio.h"
#include "IMU.h"
#include "Motors.h"
#include "PID.h"

void setup(){
	System::init();
	Debug::init();
	Motors::init();
}

void loop(){
	System::run();
}
