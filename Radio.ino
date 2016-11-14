#include "Radio.h"

Thread exchangeData;

RF24 nRF24L01(PIN_RADIO_CE, PIN_RADIO_CSN);

uint8_t Radio::dataPackage[RADIO_DATA_PACKAGE_SIZE];

void Radio::init(){
	// Initializes package
	for(int i = 0; i < RADIO_DATA_PACKAGE_SIZE; i++){
		Radio::dataPackage[i] = 0;
	}

	// Begin operation of the chip
	nRF24L01.begin();
	// Set Power Amplifier level
	nRF24L01.setPALevel(RF24_PA_MAX);
	// Open a pipe for reading
	nRF24L01.openReadingPipe(1, RADIO_PIPE_ADDRESS);
	// Start listening on the pipes opened for reading
	nRF24L01.startListening();

	// Setup receiveData Thread
	exchangeData.onRun(exchangeData_callback);
	exchangeData.setInterval(RADIO_RECEIVE_INTERVAL);

	// Add Thread to System
	System.add(&exchangeData);
}

void exchangeData_callback(){
	if(Radio::isAvailable()){
		Radio::receiveData();
	}
}

bool Radio::isAvailable(){
	return nRF24L01.available();
}

bool Radio::receiveData(){
	// Read the received packet
	bool done = false;
	done = nRF24L01.read(dataPackage, sizeof(dataPackage));
	return done;
}
