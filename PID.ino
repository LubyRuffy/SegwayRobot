#include "PID.h"

PID::PID(double _kP, double _kI, double _kD, double _iLimit){
	kP = _kP;
	kI = _kI;
	kD = _kD;
	iLimit = _iLimit;
}
	
void PID::reset(){
	P = I = D = 0;
}

void PID::addNewSample(double _sample){
	sample = _sample;
}

void PID::setSetPoint(double _setPoint){
	setPoint = _setPoint;
}

double PID::process(float deltaTime){
	error = setPoint - sample;
	
	P = error * kP;
	
	I = I + (error * kI) * deltaTime;
	I = (I >  iLimit) ?  iLimit : I;
	I = (I < -iLimit) ? -iLimit : I;

	D = (lastSample - sample) * kD / deltaTime;
	lastSample = sample;
	
	pid = P + I + D;
	
	return pid;
}