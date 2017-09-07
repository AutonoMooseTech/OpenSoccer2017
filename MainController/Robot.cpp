#include "Robot.h"

Robot::Robot():
	RobotBase(),
	ultraLeft(4, 5),
	ultraRight(A2, A1),
	lightLeft(A0),
	lightRight(A1),
	mpu(0x68),
	encoderA(11, 12),
	encoderB(A0, 13),
	encoderC(6, 7),
	encoderD(8, 9),
	motorA(0x08, 6, 10, 11),
	motorB(0x08, 5, 8, 7),
	motorC(0x08, 9, 14, 15),
	motorD(0x08, 3, 2, 4),
	omni(motorA, motorB, motorC, motorD),
	enableLed(2),
	enableSwitch(3, true)
	{
	motorA.setMax(140);
	motorB.setMax(140);
	motorC.setMax(140);
	motorD.setMax(140);
}

void Robot::setup() {
	mpu.initI2C();
}

void Robot::loop() {
	setState(state_t(enableSwitch.get()));
	SerialUSB.println(encoderA.get());
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