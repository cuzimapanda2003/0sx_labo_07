#include "Alarm.h"

Alarm::Alarm(int rPin, int gPin, int bPin, int buzzerPin, float* distancePtr)
  : _rPin(rPin), _gPin(gPin), _bPin(bPin), _buzzerPin(buzzerPin), _distance(distancePtr) {
  pinMode(_rPin, OUTPUT);
  pinMode(_gPin, OUTPUT);
  pinMode(_bPin, OUTPUT);
  pinMode(_buzzerPin, OUTPUT);
}

void Alarm::update() {
  switch (_state) {
    case OFF:
      _offState();
      break;
    case WATCHING:
      _watchState();
      break;
    case ON:
      _onState();
      break;
    case TESTING:
      _testingState();
      break;
  }
}

void Alarm::setColourA(int r, int g, int b) {
  
}

void Alarm::setColourB(int r, int g, int b) {
}

void Alarm::setVariationTiming(unsigned long ms) {
}

void Alarm::setDistance(float d) {
}

void Alarm::setTimeout(unsigned long ms) {
}

void Alarm::turnOff() {
}

void Alarm::turnOn() {
}

void Alarm::test() {
}

AlarmState Alarm::getState() const {
  return _state;
}

void Alarm::_setRGB(int r, int g, int b) {
}

void Alarm::_turnOff() {
}

void Alarm::_offState() {
}

void Alarm::_watchState() {
}

void Alarm::_onState() {
}

void Alarm::_testingState() {
}
