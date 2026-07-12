#pragma once

#include <Arduino.h>
#include <TFT_eSPI.h>
#include "GamePad.h"

extern TFT_eSPI tft;

class Paddle {
public:
    int x;
    int y;
    int width = 10;
    int height = 50;
    int oldX;
    int oldY;
    int startX;
    int startY;
    int speed;
    Paddle();


    void draw();
    void update(int& screenBoxHeight);
    void reset();
    void move(int& screenBoxHeight);
};