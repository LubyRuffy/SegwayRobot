#ifndef CONFIG_H
#define CONFIG_H 

/** Project **/
#define PROJECT_NAME					"SegwayRobot"

/** Thread Control **/
#define HEARTBEAT_ENABLED				false
#define SERIAL_DEBUG_ENABLED			true
#define IMU_ACQUIRE_ENABLED				true
#define STABILIZER_ENABLED				true
#define IMU_DEBUG_ENABLED				false
#define RADIO_RECEIVE_ENABLED			true

/** Thread Intervals **/
#define HEARTBEAT_INTERVAL				1000
#define SERIAL_DEBUG_INTERVAL			30
#define IMU_ACQUIRE_INTERVAL			5
#define STABILIZER_INTERVAL				10
#define IMU_DEBUG_INTERVAL				30
#define RADIO_RECEIVE_INTERVAL			30

/** PID constants **/
#define PID_ROLL_KP						6
#define PID_ROLL_KD						0.0001
#define PID_ROLL_KI						0.2
#define PID_ROLL_I_LIMIT				10
#define PID_YAW_KP						9
#define PID_YAW_KD						0
#define PID_YAW_KI						0.1
#define PID_YAW_I_LIMIT					10

/** Serial **/
#define SERIAL_BAUDRATE					115200
#define LOG								Serial.print

/** Radio **/
#define RADIO_DATA_PACKAGE_SIZE			2
#define RADIO_PIPE_ADDRESS				0xE8E8F0F0E1LL

/** IMU **/

/** Motors **/
#define MOTOR_NUM_OF_MOTORS				2
#define MOTOR_OUTPUT_MAX				255
#define MOTOR_OUTPUT_MIN				110

#endif // CONFIG_H
