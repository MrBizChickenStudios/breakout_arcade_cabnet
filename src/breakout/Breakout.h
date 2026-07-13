#pragma once
#include <Arduino.h>
#include <TFT_eSPI.h>

#include "Paddle.h"
#include "Ball.h"

class Breakout {
public:
    Breakout();

    void draw();
    void update(); 
    void breakoutBegin();

private:



};

extern Breakout breakout;