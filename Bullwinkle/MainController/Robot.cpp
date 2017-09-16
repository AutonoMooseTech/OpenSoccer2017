#include "Robot.h"

Robot::Robot():
	RobotBase(),
	ultraLeft(4, 5),
	ultraRight(A0, 13),
	ultraBack(12, 11),
	lightLeft(A1),
	lightRight(A2),
	mpu(0x68),
	ir(10, A4, A3, A5, 16),
	//encoderA(11, 12),
	//encoderB(A0, 13),
	//encoderC(6, 7),
	//encoderD(8, 9),
	motorA(0x08, 6, 10, 11),
	motorB(0x08, 5, 8, 7),
	motorC(0x08, 9, 14, 15),
	motorD(0x08, 3, 2, 4),
	omni(motorA, motorB, motorC, motorD),
	enableLed(0),
	enableSwitch(3),
	sideLed(1),
	sideSwitch(4)
	{
	motorA.setMax(140);
	motorB.setMax(140);
	motorC.setMax(140);
	motorD.setMax(140);
}

void Robot::setup() {
	//mpu.initI2C();
	enableSwitch.setPullup(true);
	sideSwitch.setPullup(true);
}

void Robot::loop() {
	setState(state_t(enableSwitch.get()));
	sideLed.set(sideSwitch.get());
	SerialUSB.println(lightRight.get());
}

void Robot::disabledSetup() {
	enableLed.set(LOW);
	omni.set(0.0, 0.0);
	motorA.disable();
	motorB.disable();
	motorC.disable();
	motorD.disable();
}

void Robot::disabledLoop() {
	motorA.disable();
	motorB.disable();
	motorC.disable();
	motorD.disable();
}

void Robot::enabledSetup() {
	enableLed.set(HIGH);
}

void Robot::enabledLoop() {
	omni.set(-90, 0.5);
}