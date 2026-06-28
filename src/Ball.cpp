#include "Ball.h"
#include "Constants.h"


Ball::Ball(int startX, int startY, int r) {
    this->startX = startX;
    this->startY = startY;
    x = startX;
    y = startY;
    radius = r;
    deltaX = 2;
    deltaY = 2;
    oldX = startX;
    oldY = startY;
}

void Ball::draw() {
    tft.fillCircle(oldX, oldY, radius, TFT_WHITE);
    tft.fillCircle(x, y, radius, TFT_BLACK);
   
}

void Ball::reset() {
    x = startX;
    y = startY;
    oldX = startX;
    oldY = startY;
}

void Ball::update(){
    oldX = x;
    oldY = y;
    x += deltaX;
    y += deltaY;

    if (x - radius <= 0) {
        x = radius;
        deltaX = -deltaX;
    } else if (x + radius >= SCREEN_WIDTH) {
        x = SCREEN_WIDTH - radius;
        deltaX = -deltaX;
    }

    if (y - radius <= 0) {
        y = radius;
        deltaY = -deltaY;
    } else if (y + radius >= SCREEN_HEIGHT) {
        y = SCREEN_HEIGHT - radius;
        deltaY = -deltaY;
    }
}

