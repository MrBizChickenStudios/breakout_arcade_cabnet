#pragma once
#include <Arduino.h>
#include <TFT_eSPI.h>

#include "Paddle.h"
#include "CPUPaddle.h"
#include "Ball.h"

class Pong {
public:
    Pong(int screenW, int screenH);

    void draw();
    void update();

private:
    Ball ball;
    Paddle paddle;
    CPUPaddle cpuPaddle;

    int screenW;
    int screenH;
};