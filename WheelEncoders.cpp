#include <Arduino.h>

#include "WheelEncoders.h"

volatile int WheelEncoders::_ticksLeft = 0;
volatile int WheelEncoders::_ticksRight = 0;

void WheelEncoders::setUp(const int leftInterruptPin,
                          const int rightInterruptPin) {
    pinMode(leftInterruptPin, INPUT_PULLUP);
    pinMode(rightInterruptPin, INPUT_PULLUP);

    // only matters that we attach the interrupt on a consistent action
    attachInterrupt(digitalPinToInterrupt(leftInterruptPin), leftInterrupt,
                    FALLING);
    attachInterrupt(digitalPinToInterrupt(rightInterruptPin), rightInterrupt,
                    FALLING);

    clear();
}

int WheelEncoders::getLeftTicks() {
    return _ticksLeft;
}

int WheelEncoders::getRightTicks() {
    return _ticksRight;
}

void WheelEncoders::clear() {
    _ticksLeft = 0;
    _ticksRight = 0;
}

void WheelEncoders::leftInterrupt() {
    ++_ticksLeft;
}

void WheelEncoders::rightInterrupt() {
    ++_ticksRight;
}
