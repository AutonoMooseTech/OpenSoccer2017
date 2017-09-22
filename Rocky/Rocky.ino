#include <Phantom.h>
#include "Robot.h"
#include <Wire.h>

Robot robot;

void setup() {
	SerialUSB.begin(57600);
	Wire.begin(); // As master
	robot.setup();
}

void loop() {
	robot.update();
	robot.loop();
}