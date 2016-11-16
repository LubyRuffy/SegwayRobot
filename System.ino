#include "System.h"

ThreadController SystemController;

Thread thread_stabilizer;

IMU* imu;

PID pidRoll(PID_ROLL_KP, PID_ROLL_KI, PID_ROLL_KD, PID_ROLL_I_LIMIT);
PID pidYaw(PID_YAW_KP, PID_YAW_KI, PID_YAW_KD, PID_YAW_I_LIMIT);

unsigned long lastComputeTime;

void System::init(){
	// Startup Message
	LOG(">> UP! "); LOG(PROJECT_NAME); LOG("\n");

	pidRoll.reset();
	pidYaw.reset();

	// Init IMU Thread
	imu = new IMU();
	imu->init();
	imu->setInterval(IMU_ACQUIRE_INTERVAL);
	imu->enabled = IMU_ACQUIRE_ENABLED;

	// Initialize Stabilizer Thread
	thread_stabilizer.setInterval(STABILIZER_INTERVAL);
	thread_stabilizer.onRun(thread_stabilizer_callback);
	thread_stabilizer.enabled = STABILIZER_ENABLED;

	// System
	SystemController.add(imu);
	SystemController.add(&thread_stabilizer);
}

void System::run(){
	SystemController.run();
}

void thread_stabilizer_callback(){
	// Find out dt (delta time)
	unsigned long now = millis();
	float dt = (now - lastComputeTime) / 1000.0;
	lastComputeTime = now;

	// Check if dt is good to go
	if((dt <= 0.0) || (dt >= 0.2)){
		LOG(">> dt too high! "); LOG(dt); LOG("\n");
		return;
	}

	pidRoll.setSetPoint(0);
	pidYaw.setSetPoint(0);

	pidRoll.addNewSample(imu->ypr[0]);
	pidYaw.addNewSample(imu->ypr[2]);

	float outRoll = pidRoll.process(dt);
	float outYaw = pidYaw.process(dt);

	// Iterate and distribute power to motors
	int powers[MOTOR_NUM_OF_MOTORS];
	for(int i=0; i<MOTOR_NUM_OF_MOTORS; i++){
		powers[i] = (int) (outRoll + outYaw);
	}

	// Output Motor powers
	Motors::setPower(powers);
}