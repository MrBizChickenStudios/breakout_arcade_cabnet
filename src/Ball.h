#pragma once

#include <Arduino.h>
#include <TFT_eSPI.h>

extern TFT_eSPI tft;

class Ball {
public:
    int x;
    int y;
    int radius;
    int deltaX;
    int dletaY;
    int oldX;
    int oldY;

    Ball(int startX, int startY, int r);

    void draw();
    void update();
};