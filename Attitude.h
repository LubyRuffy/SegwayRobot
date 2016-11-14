#ifndef ATTITUDE_H
#define ATTITUDE_H

/** Configs **/
#include "config.h"
#include "pinout.h"

/** Libraries **/
#include <Arduino.h>
#include <Thread.h>

/** Modules **/
#include "System.h"
#include "IMU.h"

extern Thread threadAttitude;
extern Thread threadDebug;

void threadAttitude_callback();
void threadDebug_callback();

class Attitude{

public:
	static void init();

};

#endif // ATTITUDE_H