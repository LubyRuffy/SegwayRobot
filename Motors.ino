#include "Motors.h"

int pin_motorPwm[MOTOR_NUM_OF_MOTORS];
int pin_motorDirA[MOTOR_NUM_OF_MOTORS];
int pin_motorDirB[MOTOR_NUM_OF_MOTORS];

void Motors::init(){
	// Initialize variables
	pin_motorPwm[0] = PIN_MOTOR_FRONT_PWM;
	pin_motorDirA[0] = PIN_MOTOR_FRONT_DIR_A;
	pin_motorDirB[0] = PIN_MOTOR_FRONT_DIR_B;
	pin_motorPwm[1] = PIN_MOTOR_REAR_PWM;
	pin_motorDirA[1] = PIN_MOTOR_REAR_DIR_A;
	pin_motorDirB[1] = PIN_MOTOR_REAR_DIR_B;

	// Setup pins
	for(int i=0; i<MOTOR_NUM_OF_MOTORS; i++){
		pinMode(pin_motorPwm[i], OUTPUT);
		pinMode(pin_motorDirA[i], OUTPUT);
		pinMode(pin_motorDirB[i], OUTPUT);;
	}

	// Set direction to none direction
	for(int i=0; i<MOTOR_NUM_OF_MOTORS; i++){
		digitalWrite(pin_motorDirA[i], HIGH);
		digitalWrite(pin_motorDirB[i], HIGH);
	}
}

void Motors::setPower(int power[MOTOR_NUM_OF_MOTORS]){
	for(int i=0; i<MOTOR_NUM_OF_MOTORS; i++){
		bool state = (power[i] >= 0);

		// Set motor direction
		digitalWrite(pin_motorDirA[i], state);
		digitalWrite(pin_motorDirB[i], !state);

		// Check power is out range
		power[i] = abs(power[i]);
		power[i] = (power[i] < MOTOR_OUTPUT_MIN) ? MOTOR_OUTPUT_MIN : power[i];
		power[i] = (power[i] > MOTOR_OUTPUT_MAX) ? MOTOR_OUTPUT_MAX : power[i];

		// Write PWM
		analogWrite(pin_motorPwm[i], power[i]);
	}
}