#include "GamePad.h"

static int dataPin = 35;
static int clockPin = 22;
static int latchPin = 27;

static uint8_t _state = 0;

void gamepadBegin() {

    pinMode(dataPin, INPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(latchPin, OUTPUT);

    digitalWrite(clockPin, LOW);
    digitalWrite(latchPin, LOW);
}

void gamepadUpdate() {
    _state = 0;

    // latch data
    digitalWrite(latchPin, HIGH);
    delayMicroseconds(50);
    digitalWrite(latchPin, LOW);
    delayMicroseconds(50);

    // read 8 bits
    for (int i = 0; i < 8; i++) {
        _state <<= 1;

        if (!digitalRead(dataPin)) {
            _state |= 1;
        }

        digitalWrite(clockPin, HIGH);
        delayMicroseconds(50);
        digitalWrite(clockPin, LOW);
        delayMicroseconds(50);
    }
    // Serial.print("Gamepad state: ");
    // Serial.println(_state);
}

bool gamepadGet(int index) {
    if (index < 0 || index > 7) return false;

    return (_state & (1 << (7 - index)));
}