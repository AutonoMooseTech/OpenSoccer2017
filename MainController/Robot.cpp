#include "Robot.h"

Robot::Robot():
	RobotBase(),
	ultraLeft(4, 5),
	ultraRight(A2, A1),
	lightLeft(A0),
	lightRight(A1),
	mpu(0x68),
	omni(I2C_ADDR_OMNI)
	{
	
}

void Robot::setup() {
	mpu.initI2C();

	pinMode(PIN_ENABLE_LED, OUTPUT);
	pinMode(PIN_ENABLE_SWITCH, INPUT_PULLUP);
}

void Robot::loop() {
	setState(state_t(digitalRead(3)));
	SerialUSB.println(ultraRight.get());
}

void Robot::disabledSetup() {
	digitalWrite(PIN_ENABLE_LED, LOW);

	omni.disable();
}

void Robot::disabledLoop() {
}

void Robot::enabledSetup() {
	digitalWrite(PIN_ENABLE_LED, HIGH);

	omni.enable();
}

void Robot::enabledLoop() {

	omni.set(0, 1.0);
}
