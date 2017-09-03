#include "OmniViaI2C.h"

OmniViaI2C::OmniViaI2C(uint8_t address): address(address) {

}

void OmniViaI2C::enable() {
	Wire.beginTransmission(address);
	Wire.write("E");
	Wire.endTransmission();
}

void OmniViaI2C::disable() {
	Wire.beginTransmission(address);
	Wire.write("D");
	Wire.endTransmission();
}

void OmniViaI2C::set(float angle, float speed) {
	Wire.beginTransmission(8);
	Wire.write("O");
	Wire.write(Phantom::map(angle, 0, 360, 0, 255));
	Wire.write(Phantom::map(speed, -1.0f, 1.0f, 0, 255));
	Wire.endTransmission();
}