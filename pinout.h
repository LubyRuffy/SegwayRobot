#ifndef PINOUT_H
#define PINOUT_H

/** General Pins **/
#define PIN_LED							13

/** Radio **/
#define PIN_RADIO_CE					A2
#define PIN_RADIO_CSN					A3

/** IMU **/  // Hardware I2C. Pinout is not used in firmware.
// SDA -> A4
// SCL -> A5
// INT -> D2

/** Motors **/
#define PIN_MOTOR_FRONT_PWM 			9
#define PIN_MOTOR_FRONT_DIR_A			8
#define PIN_MOTOR_FRONT_DIR_B			10
#define PIN_MOTOR_REAR_PWM				6
#define PIN_MOTOR_REAR_DIR_A			7
#define PIN_MOTOR_REAR_DIR_B			5

#endif // PINOUT_H
