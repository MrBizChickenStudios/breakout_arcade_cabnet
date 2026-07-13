#include "Ball.h"
#include "Constants.h"
#include "Pong.h"
#include "Paddle.h"
#include "CPUPaddle.h"
#include "Score.h"

Ball ball;

Ball::Ball() {
    startX = SCREEN_WIDTH / 2;
    startY = SCREEN_HEIGHT / 2;
    oldX = startX;
    oldY = startY;
    x = startX;
    y = startY;
    radius = 10;
    deltaX = 2;
    deltaY = 2;
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

    collision();
}

void Ball::collision(){
    oldX = x;
    oldY = y;
    x += deltaX;
    y += deltaY;

    if (x - radius <= 0) {
        tft.fillCircle(oldX, oldY, radius, TFT_WHITE);
        reset();
        deltaX = -deltaX;
        score.updateCpuPlayerScore();
        // pong.drawScore();
        
        return;
    }

   
    if (x + radius >= SCREEN_WIDTH) {
        tft.fillCircle(oldX, oldY, radius, TFT_WHITE);
        reset();
        deltaX = -deltaX;
        score.updatePlayerScore();

        // pong.drawScore();

        return;
    }

    


    if (y - radius <= SCORE_BOX_HEIGHT) {
        y = SCORE_BOX_HEIGHT + radius;
        deltaY = -deltaY;
    }
    
    else if (y + radius >= SCREEN_HEIGHT) {
        y = SCREEN_HEIGHT - radius;
        deltaY = -deltaY;
    }

    if (x + radius >= paddle.GetPlayerX() && x - radius <= paddle.GetPlayerX() + paddle.GetPlayerWidth() &&
        y + radius >= paddle.GetPlayerY() && y - radius <= paddle.GetPlayerY() + paddle.GetPlayerHeight()) {
        y += 3;
        deltaX = -deltaX;
    }
        if (x + radius >= cpuPaddle.GetCpuX() && x - radius <= cpuPaddle.GetCpuX() + cpuPaddle.GetCpuWidth() &&
        y + radius >= cpuPaddle.GetCpuY() && y - radius <= cpuPaddle.GetCpuY() + cpuPaddle.GetCpuHeight()) {
        y += 3;
        deltaX = -deltaX;
    }
    
}
int Ball::GetBallX() const{
    return x;
}

int Ball::GetBallY() const{
    return y;
}

