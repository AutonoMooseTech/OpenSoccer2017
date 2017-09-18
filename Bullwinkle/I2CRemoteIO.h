#ifndef I2CREMOTEIO_H
#define I2CREMOTEIO_H

#include <Wire.h>

class I2CRemoteIO {
public:
	I2CRemoteIO(uint8_t address);
	
	void init();

	void digitalWrite(uint8_t pin, bool state);
	bool digitalRead(uint8_t pin);

	void analogWrite(uint8_t pin, uint8_t value);
	uint16_t analogRead(uint8_t pin);
private:
	uint8_t address;
};

#endif