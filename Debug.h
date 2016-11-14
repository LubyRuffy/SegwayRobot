#ifndef DEBUG_H
#define DEBUG_H

/** Configs **/
#include "config.h"
#include "pinout.h"

/** Libraries **/
#include <Arduino.h>
#include <Thread.h>

/** Modules **/
#include "System.h"
#include "IMU.h"

extern Thread thread_heartBeat;
extern Thread thread_serialDebug;

static void thread_heartBeat_callback();
static void thread_serialDebug_callback();
static void thread_IMUDebug_callback();

class Debug{

public:
	static void init();
};

#endif // DEBUG_H
