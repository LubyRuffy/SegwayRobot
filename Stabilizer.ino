#include "Stabilizer.h"

Thread threadStabilizer;

PID pidYaw(1, 0, 0, 100);
PID pidRoll(1, 0, 0, 100);
PID pidPitch(1, 0, 0, 100);

void Stabilizer::init(){
	// Stabilizer thread
	threadStabilizer.onRun(threadStabilizer_callback);
	threadStabilizer.setInterval(10);

	// Add threads to System
	System.add(&threadStabilizer);
}

unsigned long lastComputeTime = 0;
void threadStabilizer_callback(){

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
	// 	LOG("$ dt too high! "); LOG(dt); LOG("\n");
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
