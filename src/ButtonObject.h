#pragma once

#include <Arduino.h>
#include <TFT_eSPI.h>

extern TFT_eSPI tft;

class ButtonObject {
public:
    int x;
    int y;
    int width;
    int height;
    int radius;

    ButtonObject(int x, int y, int w, int h, int r);

    void draw();
};