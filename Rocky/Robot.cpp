#include "Robot.h"

Robot::Robot():
	RobotBase(),
	ultraLeft(4, 5),
	ultraRight(A2, A1),
	ultraBack(0, 0),
	lightLeft(A0),
	lightRight(A1),
	gyro(0x68),
	ir(10, A4, A3, A5),
	pixy(0x54),
	motorA(0x08, 11, 13, 12),
	motorB(0x08, 5, 10, 9),
	motorC(0x08, 6, 7, 8),
	motorD(0x08, 3, 4, 2),
	omni(motorA, motorB, motorC, motorD),
	ledEnable(0),
	ledSide(1),
	ledPixyEnable(2),
	switchEnable(3),
	switchSide(4),
	switchPixyEnable(5)
	{
	motorA.setMax(140);
	motorB.setMax(140);
	motorC.setMax(140);
	motorD.setMax(140);
}

void Robot::setup() {
	gyro.init();
	gyro.callibrate();
	pixy.init();
	enableSwitch.setPullup(true);
}

void Robot::loop() {
	gyro.update();
	setState(state_t(enableSwitch.get()));
	int b = ir.getBest();
}

void Robot::disabledSetup() {
	enableLed.set(LOW);
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
	gyro.reset();
}

float i;

void Robot::enabledLoop() {
	//float angle = ((ir.getBest() * 22.5) - 180) * 1.4;
	//omni.set(angle, 0.5, gyro.getZ() / 25);
	omni.set(90, 0.5, 0);
}