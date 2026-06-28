#pragma once

#include <Arduino.h>
#include <XPT2046_Touchscreen.h>

void touchSetup();
bool touchPressed();
TS_Point getTouch();