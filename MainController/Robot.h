#ifndef ROBOT_H
#define ROBOT_H

#include <Phantom.h>
#include <Arduino.h>
#include <RobotBase.h>

#include <Wire.h>
#include <Ultrasonic.h>
#include <SenseLight.h>
#include <MPU9250.h>
#include "OmniViaI2C.h"
#include <DigitalOutput.h>
#include <DigitalInput.h>

class Robot:
	public Phantom::RobotBase {
public:
	Robot();

	// Sensors
	Phantom::Ultrasonic ultraLeft;
	Phantom::Ultrasonic ultraRight;
	Phantom::SenseLight lightLeft;
	Phantom::SenseLight lightRight;
	Phantom::MPU9250 mpu;

	// Motors
  	OmniViaI2C omni;

  	// Other
  	Phantom::DigitalOutput enableLed;
  	Phantom::DigitalInput enableSwitch;

	void setup();
	void loop();
	void disabledSetup();
	void disabledLoop();
	void enabledSetup();
	void enabledLoop();
private:
};

#endif
