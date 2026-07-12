#include "Ball.h"
#include "Constants.h"
#include "Pong.h"


Ball::Ball() {
    startX = SCREEN_WIDTH / 2;
    startY = SCREEN_HEIGHT / 2;
    oldX = startX;
    oldY = startY;
    x = startX;
    y = startY;
    radius = 10;
    // this->startX = startX;
    // this->startY = startY;
    // x = startX;
    // y = startY;
    // radius = r;
    deltaX = 2;
    deltaY = 2;
    // oldX = startX;
    // oldY = startY;
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

void Ball::update(Paddle& paddle, CPUPaddle& cpuPaddle, int& playerScore, int& cpuScore, int& screenBoxHeight){
    collision(paddle, cpuPaddle, playerScore, cpuScore, screenBoxHeight);
}

void Ball::collision(Paddle& paddle, CPUPaddle& cpuPaddle, int& playerScore, int& cpuScore, int& screenBoxHeight){
    oldX = x;
    oldY = y;
    x += deltaX;
    y += deltaY;

    if (x - radius <= 0) {
        tft.fillCircle(oldX, oldY, radius, TFT_WHITE);
        reset();
        deltaX = -deltaX;
        cpuScore ++;
        // pong.drawScore();
        
        return;
    }

   
    if (x + radius >= SCREEN_WIDTH) {
        tft.fillCircle(oldX, oldY, radius, TFT_WHITE);
        reset();
        deltaX = -deltaX;
        playerScore ++;
        // pong.drawScore();

        return;
    }

    


    if (y - radius <= screenBoxHeight) {
        y = screenBoxHeight + radius;
        deltaY = -deltaY;
    }
    
    else if (y + radius >= SCREEN_HEIGHT) {
        y = SCREEN_HEIGHT - radius;
        deltaY = -deltaY;
    }

    if (x + radius >= paddle.x && x - radius <= paddle.x + paddle.width &&
        y + radius >= paddle.y && y - radius <= paddle.y + paddle.height) {
        y += 3;
        deltaX = -deltaX;
    }
        if (x + radius >= cpuPaddle.x && x - radius <= cpuPaddle.x + cpuPaddle.width &&
        y + radius >= cpuPaddle.y && y - radius <= cpuPaddle.y + cpuPaddle.height) {
        y += 3;
        deltaX = -deltaX;
    }
    
}

