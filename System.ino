#include "System.h"

ThreadController SystemController;

Thread thread_stabilizer;

PID pidRoll(PID_ROLL_KP, PID_ROLL_KI, PID_ROLL_KD, PID_ROLL_I_LIMIT);
PID pidYaw(PID_YAW_KP, PID_YAW_KI, PID_YAW_KD, PID_YAW_I_LIMIT);

IMU* imu;

void System::init(){
	// Startup Message
	LOG(">> UP! "); LOG(PROJECT_NAME); LOG("\n");

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
	// // Find out dt (delta time)
	// unsigned long now = millis();
	// float dt = (now - lastComputeTime) / 1000.0;
	// lastComputeTime = now;

	// if(Drone::state != ARMED){
	// 	pidYaw.reset();
	// 	pidRoll.reset();
	// 	pidPitch.reset();

	// 	Motors::stop();
	// 	return;
	// }

	// // Check if dt is good to go
	// if(dt <= 0.0 || dt >= 0.2){
	// 	LOG(">> dt too high! "); LOG(dt); LOG("\n");
	// 	return;
	// }

	// pidYaw.addNewSample(Drone::ypr[2]);
	// pidRoll.addNewSample(Drone::ypr[2]);
	// pidPitch.addNewSample(Drone::ypr[1]);

	// float outYaw = pidYaw.process(dt);
	// float outRoll = pidRoll.process(dt);
	// float outPitch = pidPitch.process(dt);

	// // Iterate and distribute power to propelers
	// for(int i = 0; i < PROP_COUNT; i++){

	// 	powers[i] = outPitch * Drone::props[i][PROP_Y_W] +
	// 				outRoll * Drone::props[i][PROP_X_W] +
	// 				outYaw * Drone::props[i][PROP_DIR];

	// }

	// // Output Motor powers
	// Motors::setPower(powers);
}