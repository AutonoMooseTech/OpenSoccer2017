#ifndef IR_H
#define IR_H

#include "Arduino.h"
#include "Wire.h"

#define IR_SENSOR_COUNT 16

class IR {
public:
  IR(uint8_t powerPin, uint8_t clockPin, uint8_t latchPin, uint8_t dataPin);
  ~IR();

  float getBest();

  void refresh();
private:
  // Pin Configuration
  uint8_t _powerPin;
  uint8_t _clockPin;
  uint8_t _latchPin;
  uint8_t _dataPin;

  // Shift-In Configuration
  uint16_t _maxPulseLength = 250;
  uint16_t _byteCount;
  uint8_t _rawDataArray[2];
  uint16_t _dataArray[IR_SENSOR_COUNT];

  // Outputs
  uint8_t _best;
};

#endif /* IR_H */