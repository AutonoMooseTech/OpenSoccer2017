#ifndef SENSELIGHTVIAI2C_H
#define SENSELIGHTVIAI2C_H

#include <Arduino.h>
#include <Phantom.h>
#include <Wire.h>

class SenseLightViaI2C {
public:
	SenseLightViaI2C(uint8_t address, uint8_t id);
	
	float get();

private:
	uint8_t address;
	uint8_t id;
	float reading;
};

#endif