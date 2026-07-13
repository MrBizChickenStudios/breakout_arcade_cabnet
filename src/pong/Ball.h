#pragma once

#include <Arduino.h>
#include <TFT_eSPI.h>
#include "Paddle.h"
#include "CPUPaddle.h"


class Ball {
public:


    Ball();

    int GetBallX() const;
    int GetBallY() const;
    void draw();
    void update();
   
private:
    int x;
    int y;
    int radius;
    int deltaX;
    int deltaY;
    int oldX;
    int oldY;
    int startX;
    int startY;
    void reset();
    void collision();


};
extern Ball ball;