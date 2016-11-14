#ifndef CONFIG_H
#define CONFIG_H 

/** Project **/
#define PROJECT_NAME					"SegwayRobot"

/** Thread Intervals **/
#define HEART_BEAT_INTERVAL				1000
#define SERIAL_DEBUG_INTERVAL			500
#define IMU_ACQUIRE_INTERVAL			30
#define RADIO_RECEIVE_INTERVAL			100

/** Serial **/
#define SERIAL_ENABLED					true
#define SERIAL_BAUDRATE					115200
#define LOG								Serial.print

/** Radio **/
#define RADIO_DATA_PACKAGE_SIZE			5
#define RADIO_PIPE_ADDRESS				0xF0F0F0F0AALL

/** IMU **/

/** Motors **/
#define MOTOR_NUM_OF_MOTORS				2
#define MOTOR_OUTPUT_MAX				255
#define MOTOR_OUTPUT_MIN				30

#endif // CONFIG_H
