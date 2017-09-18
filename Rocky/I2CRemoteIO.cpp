#include "I2CRemoteIO.h"

I2CRemoteIO::I2CRemoteIO(uint8_t address): address(address) {

}

void I2CRemoteIO::init() {
	Wire.begin();
}

void I2CRemoteIO::digitalWrite(uint8_t pin, bool state) {
	Wire.beginTransmission(address);
	Wire.write("D");
	Wire.write("W");
	Wire.write(pin);
	Wire.write(state);
	Wire.endTransmission();
}

bool I2CRemoteIO::digitalRead(uint8_t pin) {
	Wire.beginTransmission(address);
	Wire.write("D");
	Wire.write("R");
	Wire.write(pin);
	Wire.endTransmission();

	Wire.requestFrom(address, 1);

	return Wire.read();
}

void I2CRemoteIO::analogWrite(uint8_t pin, uint8_t value) {
	Wire.beginTransmission(address);
	Wire.write("A");
	Wire.write("W");
	Wire.write(pin);
	Wire.write(value);
	Wire.endTransmission();
}

uint16_t I2CRemoteIO::analogRead(uint8_t pin) {
	Wire.beginTransmission(address);
	Wire.write("A");
	Wire.write("R");
	Wire.write(pin);
	Wire.endTransmission();

	Wire.requestFrom(address, 1);

	return Wire.read();
}