#ifndef ROBOT_H
#define ROBOT_H

#include <Arduino.h>
#undef max
#undef min
#include <Phantom.h>
#include <Wire.h>
#include "RobotMap.h"
#include <RobotBase.h>

class Robot: public Phantom::RobotBase {
public:
	Robot();

	void setup();
	void loop();
	void disabledSetup();
	void disabledLoop();
	void enabledSetup();
	void enabledLoop();
private:
};

#endif
