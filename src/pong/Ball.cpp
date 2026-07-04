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

void Ball::update(Paddle& paddle, CPUPaddle& cpuPaddle){
    collision(paddle, cpuPaddle);
}

void Ball::collision(Paddle& paddle, CPUPaddle& cpuPaddle){
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

    if (x + radius >= paddle.x && x - radius <= paddle.x + paddle.width &&
        y + radius >= paddle.y && y - radius <= paddle.y + paddle.height) {
        y += 5;
        deltaX = -deltaX;
    }
        if (x + radius >= cpuPaddle.x && x - radius <= cpuPaddle.x + cpuPaddle.width &&
        y + radius >= cpuPaddle.y && y - radius <= cpuPaddle.y + cpuPaddle.height) {
        y += 5;
        deltaX = -deltaX;
    }
    
}

