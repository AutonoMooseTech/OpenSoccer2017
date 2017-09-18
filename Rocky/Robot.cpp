#include "Robot.h"

Robot::Robot():
	RobotBase(),
	ultraLeft(4, 5),
	ultraRight(A2, A1),
	ultraBack(0, 0),
	lightLeft(A0),
	lightRight(A1),
	mpu(0x68),
	ir(10, A4, A3, A5, 16),
	motorA(0x08, 3, 2, 4),
	motorB(0x08, 6, 7, 8),
	motorC(0x08, 5, 6, 10),
	motorD(0x08, 11, 12, 13),
	omni(motorA, motorB, motorC, motorD),
	enableLed(2),
	enableSwitch(3)
	{
	motorA.setMax(140);
	motorB.setMax(140);
	motorC.setMax(140);
	motorD.setMax(140);
}

void Robot::setup() {
	mpu.initI2C();
	enableSwitch.setPullup(true);
}

void Robot::loop() {
	setState(state_t(enableSwitch.get()));
}

void Robot::disabledSetup() {
	enableLed.set(LOW);
	motorA.disable();
	motorB.disable();
	motorC.disable();
	motorD.disable();
}

void Robot::disabledLoop() {
}

void Robot::enabledSetup() {
	enableLed.set(HIGH);
}

void Robot::enabledLoop() {
	omni.set(0, 1.0);
}