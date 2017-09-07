#ifndef I2CREMOTECONTROL_H
#define I2CREMOTECONTROL_H

#include <Phantom.h>
#include <Wire.h>

class I2CRemoteControl {
public:
	I2CRemoteControl(uint8_t address);

	void init();

	void onReceive();
	void onRequest();
private:
	uint8_t address;
	uint8_t type, mode;
	uint8_t pin, output;
};

#endif