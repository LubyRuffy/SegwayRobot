#ifndef PINOUT_H
#define PINOUT_H

/** General Pins **/
#define PIN_LED							13

/** Radio **/
#define PIN_RADIO_CE					9 
#define PIN_RADIO_CSN					10

/** IMU **/
// SDA -> A4
// SCL -> A5
// INT -> D2

/** Motors **/
#define PIN_MOTOR_FRONT_PWM 			A1
#define PIN_MOTOR_FRONT_DIR_A			8
#define PIN_MOTOR_FRONT_DIR_B			8
#define PIN_MOTOR_REAR_PWM				A1
#define PIN_MOTOR_REAR_DIR_A			8
#define PIN_MOTOR_REAR_DIR_B			8

#endif // PINOUT_H
