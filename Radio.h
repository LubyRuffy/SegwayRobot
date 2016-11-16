#ifndef RADIO_H
#define RADIO_H

/** Configs **/
#include "config.h"
#include "pinout.h"

/** Libraries **/
#include <Arduino.h>
#include <Thread.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

/** Modules **/
#include "System.h"

extern Thread exchangeData;

extern void exchangeData_callback();

class Radio: public Thread{
private:
	// RF24 nRF24L01(PIN_RADIO_CE, PIN_RADIO_CSN);
public:
	uint8_t dataPackage[RADIO_DATA_PACKAGE_SIZE];
	bool init();
	// Checks if the Thread should run (Time && Enabled && FIFO buffer)
	bool shouldRun(unsigned long time);
	// Override the usual Run method
	void run();
	bool isAvailable();
};


#endif // RADIO_H
