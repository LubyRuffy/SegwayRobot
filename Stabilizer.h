#ifndef STABILIZER_H
#define STABILIZER_H

/** Configs **/
#include "config.h"
#include "pinout.h"

/** Libraries **/
#include <Arduino.h>
#include <Thread.h>

/** Modules **/
#include "System.h"

extern Thread threadStabilizer;

void threadStabilizer_callback();

class Stabilizer{

public:

	static void init();
};


#endif // STABILIZER_H