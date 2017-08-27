#ifndef ROBOT_H
#define ROBOT_H


#include <Arduino.h>
#include <Phantom.h>
#include <Wire.h>
#include "RobotMap.h"
#include <RobotBase.h>
#include <Scheduler.h>
#include <VNH2SP30.h>
#include <OmniDrive.h>

class Robot: public Phantom::RobotBase {
public:
	Robot();

	Phantom::VNH2SP30 motorA;
	Phantom::VNH2SP30 motorB;
	Phantom::VNH2SP30 motorC;
	Phantom::VNH2SP30 motorD;

	Phantom::OmniDrive omni;

	void setup();
	void loop();
	void disabledSetup();
	void disabledLoop();
	void enabledSetup();
	void enabledLoop();
private:
};

#endif