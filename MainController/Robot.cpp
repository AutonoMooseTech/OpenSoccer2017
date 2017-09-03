#include "Robot.h"

Robot::Robot():
	RobotBase(),
	ultraLeft(4, 5),
	ultraRight(A2, A1),
	lightLeft(A0),
	lightRight(A1),
	mpu(0x68),
	omni(8),
	enableLed(2),
	enableSwitch(3, true)
	{
	
}

void Robot::setup() {
	mpu.initI2C();
}

void Robot::loop() {
	setState(state_t(enableSwitch.get()));
	SerialUSB.println(ultraRight.get());
}

void Robot::disabledSetup() {
	enableLed.set(LOW);

	omni.disable();
}

void Robot::disabledLoop() {
}

void Robot::enabledSetup() {
	enableLed.set(HIGH);

	omni.enable();
}

void Robot::enabledLoop() {

	omni.set(0, 1.0);
}
