#include "I2CMotor.h"

I2CMotor::I2CMotor(uint8_t address, uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB): MotorBase(), io(address), pinPWM(pinPWM), pinDirA(pinDirA), pinDirB(pinDirB) {

}

void I2CMotor::set(float speed) {
	io.digitalWrite(this->pinDirA, speed > 0.0f); // Use sign to set direction pins 
	io.digitalWrite(this->pinDirB, speed < 0.0f);
	io.analogWrite(this->pinPWM, Phantom::map(fabs(speed), 0.0f, 1.0f, min, max)); // Write PWM Value
}

void I2CMotor::setMin(uint8_t min) {
	this->min = min;
}

void I2CMotor::setMax(uint8_t max) {
	this->max = max;
}

void I2CMotor::setBounds(uint8_t min, uint8_t max) {
	setMin(min);
	setMax(max);
}

void I2CMotor::disable() {
	io.digitalWrite(this->pinDirA, LOW); // Use sign to set direction pins 
	io.digitalWrite(this->pinDirA, LOW);
	io.digitalWrite(this->pinPWM, LOW);
}