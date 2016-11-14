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

class Radio{

public:
	static uint8_t dataPackage[RADIO_DATA_PACKAGE_SIZE];

	static void init();
	static bool isAvailable();
	static bool receiveData();
};


#endif // RADIO_H
