#include "RobotMap.h"
#include "Robot.h"

using namespace Phantom;

Robot robot;

void setup() {
	robot.setup();
	// I2C
	Wire.begin();
}

void loop() {
	robot.loop();
	robot.update();
}
