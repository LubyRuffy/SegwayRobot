#include "System.h"

// Thread variables
ThreadController System;

Thread heartBeat;
Thread serialDebug;

// General variables
bool ledState = false;

void system_init(){
	// Setup Pins
	pinMode(PIN_LED, OUTPUT);

	// Serial
	Serial.begin(SERIAL_BAUDRATE);
	while(!Serial);

	// Setup heartBeat Thread
	heartBeat.onRun(heartBeat_callback);
	heartBeat.setInterval(HEART_BEAT_INTERVAL);

	// Setup serialDebug Thread
	serialDebug.onRun(serialDebug_callback);
	serialDebug.setInterval(SERIAL_DEBUG_INTERVAL);

	// Disable serialDebug Thread
	serialDebug.enabled = SERIAL_ENABLED;

	// Add Threads to System
	System.add(&heartBeat);
	System.add(&serialDebug);

	// Startup Message
	LOG("\n\nUP! "); LOG(PROJECT_NAME); LOG("\n");
}

void system_run(){
	System.run();
}

void heartBeat_callback(){
	// Blinking
	ledState = !ledState;
	digitalWrite(PIN_LED, ledState);
}

void serialDebug_callback(){
	if(!Serial.available())
		return;

	char cmd = Serial.read();

	if(cmd == 'p'){
		LOG("$ Ping back\n");
	}else if(cmd == 'i'){
		LOG("$ Toggling DEBUG in IMU\n");
		threadDebug.enabled = !threadDebug.enabled;
	}
}