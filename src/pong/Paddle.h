#pragma once

#include <Arduino.h>
#include <TFT_eSPI.h>
#include "GamePad.h"

extern TFT_eSPI tft;

class Paddle {
public:

    Paddle();

    int GetPlayerX() const;
    int GetPlayerY() const;
    int GetPlayerWidth() const;
    int GetPlayerHeight() const;
    void draw();
    void update();
    void begin();

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

extern Paddle paddle;