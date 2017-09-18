#ifndef ROBOT_H
#define ROBOT_H

#include <Phantom.h>
#include <Arduino.h>
#include <RobotBase.h>

#include <Wire.h>
#include <Ultrasonic.h>
#include <NXTLightSensor.h>
#include <MPU9250.h>
#include <OmniDrive.h>
#include "I2CMotor.h"
#include "IRArray.h"
#include <DigitalOutput.h>
#include <DigitalInput.h>

class Robot:
	public Phantom::RobotBase {
public:
	// Sensors
	Phantom::Ultrasonic ultraLeft;
	Phantom::Ultrasonic ultraRight;
	Phantom::Ultrasonic ultraBack;
	Phantom::NXTLightSensor lightLeft;
	Phantom::NXTLightSensor lightRight;
	Phantom::MPU9250 mpu;
	IRArray ir;

	// Motors
	I2CMotor motorA;
	I2CMotor motorB;
	I2CMotor motorC;
	I2CMotor motorD;
	Phantom::OmniDrive omni;

	// Other
	Phantom::DigitalOutput enableLed;
	Phantom::DigitalInput enableSwitch;

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
