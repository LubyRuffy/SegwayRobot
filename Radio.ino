#include "Radio.h"

RF24 nRF24L01(PIN_RADIO_CE, PIN_RADIO_CSN);

bool Radio::init(){
	// Initializes package
	for(int i = 0; i < RADIO_DATA_PACKAGE_SIZE; i++){
		dataPackage[i] = 0;
	}

	// Begin operation of the chip
	nRF24L01.begin();
	// Set Power Amplifier level
	nRF24L01.setPALevel(RF24_PA_MAX);
	// Open a pipe for reading
	nRF24L01.openReadingPipe(1, RADIO_PIPE_ADDRESS);
	// Start listening on the pipes opened for reading
	nRF24L01.startListening();

	return true;
}

bool Radio::isAvailable(){
	return nRF24L01.available();
}

bool Radio::shouldRun(unsigned long time){
	if(!Thread::shouldRun(time))
		return false;

	if(!nRF24L01.available())
		return false;

	return true;
}

void Radio::run(){
	if (nRF24L01.available()) {
		runned();
		// Read the received packet
		bool done = false;
		done = nRF24L01.read(dataPackage, sizeof(dataPackage));
	}
}
