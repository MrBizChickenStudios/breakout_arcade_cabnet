#include "Ball.h"
#include "Constants.h"


Ball::Ball(int startX, int startY, int r) {
    x = startX;
    y = startY;
    radius = r;
    deltaX = 2;
    dletaY = 2;
    oldX = startX;
    oldY = startY;
}

void Ball::draw() {
    tft.fillCircle(oldX, oldY, radius, TFT_BLACK);
    tft.fillCircle(x, y, radius, TFT_WHITE);
   
}

void Ball::update(){
    oldX = x;
    oldY = y;
    x += deltaX;
    y += dletaY;

    if (x - radius <= 0) {
        x = radius;
        deltaX = -deltaX;
    } else if (x + radius >= SCREEN_WIDTH) {
        x = SCREEN_WIDTH - radius;
        deltaX = -deltaX;
    }

    if (y - radius <= 0) {
        y = radius;
        dletaY = -dletaY;
    } else if (y + radius >= SCREEN_HEIGHT) {
        y = SCREEN_HEIGHT - radius;
        dletaY = -dletaY;
    }
}

