#ifndef SYSTEM_H
#define SYSTEM_H

/** Configs **/
#include "config.h"
#include "pinout.h"

/** Libraries **/
#include <Arduino.h>
#include <Thread.h>
#include <ThreadController.h>

/** Modules **/
#include "IMU.h"

extern ThreadController SystemController;
extern Thread thread_stabilizer;

extern IMU* imu;

void thread_stabilizer_callback();

class System{

public:
	static void init();
	static void run();
};

#endif // SYSTEM_H
