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

    Ball();


    void draw();
    void update(Paddle& paddle, CPUPaddle& cpuPaddle, int& playerScore, int& cpuScore, int& screenBoxHeight);
    void reset();
    void collision(Paddle& paddle, CPUPaddle& cpuPaddle, int& playerScore, int& cpuScore, int& screenBoxHeight);
};