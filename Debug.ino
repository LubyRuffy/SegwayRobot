#include "Debug.h"

Thread thread_heartBeat;
Thread thread_serialDebug;
Thread thread_IMUDebug;

bool ledState = false;

void Debug::init(){
	// Setup Pins
	pinMode(PIN_LED, OUTPUT);

	// Serial
	Serial.begin(SERIAL_BAUDRATE);
	while(!Serial);

	// Setup Heart Beat Thread
	thread_heartBeat.onRun(thread_heartBeat_callback);
	thread_heartBeat.setInterval(HEARTBEAT_INTERVAL);
	thread_heartBeat.enabled = HEARTBEAT_ENABLED;

	// Setup Serial Debug Thread
	thread_serialDebug.onRun(thread_serialDebug_callback);
	thread_serialDebug.setInterval(SERIAL_DEBUG_INTERVAL);
	thread_serialDebug.enabled = SERIAL_DEBUG_ENABLED;

	// Setup IMU Debug Thread
	thread_IMUDebug.onRun(thread_IMUDebug_callback);
	thread_IMUDebug.setInterval(IMU_DEBUG_INTERVAL);
	thread_IMUDebug.enabled = IMU_DEBUG_ENABLED;

	// Add Threads to System
	SystemController.add(&thread_heartBeat);
	SystemController.add(&thread_serialDebug);
	SystemController.add(&thread_IMUDebug);

	// Startup Message
	LOG("\n\n>> UP! "); LOG(PROJECT_NAME); LOG("\n");
}

void thread_heartBeat_callback(){
	// Blinking
	ledState = !ledState;
	digitalWrite(PIN_LED, ledState);
}

void thread_serialDebug_callback(){
	if(!Serial.available())
		return;

	char cmd = Serial.read();

	if(cmd == 'p'){
		LOG(">> Ping back\n");
	}else if(cmd == 'i'){
		LOG(">> Toggling DEBUG in IMU\n");
		thread_IMUDebug.enabled = !thread_IMUDebug.enabled;
	}
}

void thread_IMUDebug_callback(){
	LOG(">> YPR:\t"); 
	LOG(imu->getYaw()); LOG("\t");
	LOG(imu->getPitch()); LOG("\t");
	LOG(imu->getRoll()); LOG("\n");
}