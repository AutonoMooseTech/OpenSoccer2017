#ifndef ROBOT_H
#define ROBOT_H

#include <Phantom.h>
#include <Arduino.h>
#include <RobotBase.h>

#include <Wire.h>
#include <Ultrasonic.h>
#include <SenseLight.h>
#include <MPU9250Gyro.h>
#include <OmniDrive.h>
#include "I2CMotor.h"
#include <Encoder.h>
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
	Phantom::SenseLight lightLeft;
	Phantom::SenseLight lightRight;
	Phantom::MPU9250Gyro gyro;
	IR ir;

	//Phantom::Encoder encoderA;
	//Phantom::Encoder encoderB;
	//Phantom::Encoder encoderC;
	//Phantom::Encoder encoderD;

	// Motors
	I2CMotor motorA;
	I2CMotor motorB;
	I2CMotor motorC;
	I2CMotor motorD;
	Phantom::OmniDrive omni;

	// Other
	Phantom::DigitalOutput enableLed;
	Phantom::DigitalInput enableSwitch;
	Phantom::DigitalOutput sideLed;
	Phantom::DigitalInput sideSwitch;

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
