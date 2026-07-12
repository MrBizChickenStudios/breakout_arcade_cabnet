#pragma once
#include <Arduino.h>
#include <TFT_eSPI.h>

#include "Paddle.h"
#include "CPUPaddle.h"
#include "Ball.h"

class Pong {
public:
    Pong();

    void draw();
    void update();
    void drawScore();

private:
    Ball ball;
    Paddle paddle;
    CPUPaddle cpuPaddle;

    int playerScore = 0;
    int cpuScore = 0;

    int lastPlayerScore = -1;
    int lastCpuScore = -1;

    int screenBoxHeight = 30;

};

extern Pong pong;