#pragma once

#include <Arduino.h>
#include <TFT_eSPI.h>
#include "Paddle.h"
#include "CPUPaddle.h"


class Ball {
public:
    int x;
    int y;
    int radius;
    int deltaX;
    int deltaY;
    int oldX;
    int oldY;
    int startX;
    int startY;

    Ball(int startX, int startY, int r);

    void draw();
    void update(Paddle& paddle, CPUPaddle& cpuPaddle);
    void reset();
    void collision(Paddle& paddle, CPUPaddle& cpuPaddle);
};