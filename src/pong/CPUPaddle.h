#pragma once

#include <Arduino.h>
#include <TFT_eSPI.h>
#include "GamePad.h"

extern TFT_eSPI tft;

class CPUPaddle {
public:

    CPUPaddle();
    int GetCpuX() const;
    int GetCpuY() const;
    int GetCpuWidth() const;
    int GetCpuHeight() const;

    void draw();
    void update();


private:
    int x;
    int y;
    int width = 10;
    int height = 50;
    int oldX;
    int oldY;
    int startX;
    int startY;
    int speed;
    void reset();
    void move(); 
};

extern CPUPaddle cpuPaddle;