#include "Ball.h"
#include "Constants.h"
#include "Breakout.h"
#include "Paddle.h"


BreakoutBall breakoutBall;

BreakoutBall::BreakoutBall() {
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

void BreakoutBall::draw() {
    tft.fillCircle(oldX, oldY, radius, TFT_WHITE);
    tft.fillCircle(x, y, radius, TFT_BLACK);
   
}

void BreakoutBall::reset() {
    x = startX;
    y = startY;
    oldX = startX;
    oldY = startY;
}

void BreakoutBall::update(){

    collision();
}

void BreakoutBall::collision(){
    oldX = x;
    oldY = y;
    x += deltaX;
    y += deltaY;

    if (x - radius <= 0) {
        tft.fillCircle(oldX, oldY, radius, TFT_WHITE);
   
        deltaX = -deltaX;
  

        
        return;
    }

   
    if (x + radius >= SCREEN_WIDTH) {
        tft.fillCircle(oldX, oldY, radius, TFT_WHITE);
  
        deltaX = -deltaX;
   

     

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

    if (y + radius >= breakoutPaddle.GetPlayerY() &&
        x >= breakoutPaddle.GetPlayerX() &&
        x <= breakoutPaddle.GetPlayerX() + breakoutPaddle.GetPlayerWidth()) 
    {
        deltaY = -deltaY;
    }
    
}
int BreakoutBall::GetBallX() const{
    return x;
}

int BreakoutBall::GetBallY() const{
    return y;
}


