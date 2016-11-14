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
#include "Radio.h"
#include "IMU.h"
#include "Motors.h"

extern ThreadController System;

extern Thread heartBeat;
extern Thread serialDebug;
extern Thread batteryChecker;

extern void system_init();
extern void system_run();
extern void heartBeat_callback();
extern void serialDebug_callback();

#endif // SYSTEM_H
