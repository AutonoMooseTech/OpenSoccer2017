#include <Phantom.h>
#include "Robot.h"
#include <Wire.h>

Robot robot;

void setup() {
	robot.setup();
	SerialUSB.begin(57600);
	Wire.begin(); // As master

	// Interrupts
	//attachInterrupt(digitalPinToInterrupt(robot.encoderA.pinA), encA, CHANGE);
	//attachInterrupt(digitalPinToInterrupt(robot.encoderA.pinB), encA, CHANGE);

	//attachInterrupt(digitalPinToInterrupt(robot.encoderB.pinA), encB, CHANGE);
	//attachInterrupt(digitalPinToInterrupt(robot.encoderB.pinB), encB, CHANGE);

	//attachInterrupt(digitalPinToInterrupt(robot.encoderC.pinA), encC, CHANGE);
	//attachInterrupt(digitalPinToInterrupt(robot.encoderC.pinB), encC, CHANGE);

	//attachInterrupt(digitalPinToInterrupt(robot.encoderD.pinA), encD, CHANGE);
	//attachInterrupt(digitalPinToInterrupt(robot.encoderD.pinB), encD, CHANGE);
}

void loop() {
	robot.update();
	robot.loop();
}
/*
void encA() {
	robot.encoderA.update();
}

void encB() {
	robot.encoderB.update();
}

void encC() {
	robot.encoderC.update();
}

void encD() {
	robot.encoderD.update();
}
*/