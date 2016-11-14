#ifndef MOTORS_H
#define MOTORS_H

/** Configs **/
#include "config.h"
#include "pinout.h"

/** Libraries **/
#include <Arduino.h>

class Motors{

public:
	static void init();	
	static void setPower(int powers[MOTOR_NUM_OF_MOTORS]);	
};

#endif // MOTORS_H
