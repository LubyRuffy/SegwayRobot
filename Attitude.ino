#include "Attitude.h"

IMU* imu;
Thread threadAttitude;
Thread threadDebug;

void Attitude::init(){
	// Init IMU
	imu = new IMU();
	imu->init();
	imu->enabled = true;
	imu->setInterval(5);

	// Initialize Attitude Thread
	threadAttitude.setInterval(5);
	threadAttitude.onRun(threadAttitude_callback);

	// Debug Thread
	threadDebug.setInterval(10);
	threadDebug.onRun(threadDebug_callback);
	threadDebug.enabled = false;

	// System
	System.add(imu);
	System.add(&threadAttitude);
	System.add(&threadDebug);
}

void threadAttitude_callback(){
	// control here
}

void threadDebug_callback(){
	LOG("YPR:\t"); 
	LOG(imu->ypr[0]); LOG("\t");
	LOG(imu->ypr[1]); LOG("\t");
	LOG(imu->ypr[2]); LOG("\n");
}