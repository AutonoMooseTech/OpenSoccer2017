#ifndef IRARRAY_H
#define IRARRAY_H

#include <Phantom.h>

class IRArray {
public:
	IRArray(uint8_t pinPower, uint8_t pinLatch, uint8_t pinClock, uint8_t pinData, uint8_t sensorCount);

	bool* get();
	
private:
	uint8_t pinPower, pinLatch, pinClock, pinData;
	uint8_t sensorCount;
	uint8_t byteCount;
};


#endif
