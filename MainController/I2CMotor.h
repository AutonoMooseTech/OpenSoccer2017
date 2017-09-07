#ifndef I2CMOTOR_H
#define I2CMOTOR_H

#include <Phantom.h>
#include <MotorBase.h>
#include "I2CRemoteIO.h"

class I2CMotor: public Phantom::MotorBase {
public:
	I2CRemoteIO io;

	I2CMotor(uint8_t address, uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB);

	void set(float speed);

	void setMin(uint8_t min);
	void setMax(uint8_t max);
	void setBounds(uint8_t min, uint8_t max);

	void disable();
private:
	uint8_t pinPWM, pinDirA, pinDirB;
	uint8_t min = 0, max = 255;
};

#endif