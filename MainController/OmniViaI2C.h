#ifndef OMNIVIAI2C_H
#define OMNIVIAI2C_H

#include <Phantom.h>
#include <Wire.h>

class OmniViaI2C {
public:
	OmniViaI2C(uint8_t address);

	void enable();
	void disable();

	void set(float angle, float speed);
private:
	uint8_t address;
};

#endif