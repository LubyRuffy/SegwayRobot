#ifndef CONFIG_H
#define CONFIG_H 

/** Project **/
#define PROJECT_NAME					"SegwayRobot"

/** Thread Control **/
#define HEARTBEAT_ENABLED				true
#define SERIAL_DEBUG_ENABLED			true
#define IMU_ACQUIRE_ENABLED				true
#define STABILIZER_ENABLED				true
#define IMU_DEBUG_ENABLED				false
#define RADIO_RECEIVE_ENABLED			false

/** Thread Intervals **/
#define HEARTBEAT_INTERVAL				1000
#define SERIAL_DEBUG_INTERVAL			30
#define IMU_ACQUIRE_INTERVAL			5
#define STABILIZER_INTERVAL				5
#define IMU_DEBUG_INTERVAL				30
#define RADIO_RECEIVE_INTERVAL			100

/** PID constants **/
#define PID_ROLL_KP						1
#define PID_ROLL_KD						0
#define PID_ROLL_KI						0
#define PID_ROLL_I_LIMIT				100
#define PID_YAW_KP						1
#define PID_YAW_KD						0
#define PID_YAW_KI						0
#define PID_YAW_I_LIMIT					100

/** Serial **/
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
