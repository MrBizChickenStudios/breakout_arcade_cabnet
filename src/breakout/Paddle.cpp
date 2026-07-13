#include "Paddle.h"
#include "Constants.h"

BreakoutPaddle breakoutPaddle;

BreakoutPaddle::BreakoutPaddle() {
    startX = SCREEN_WIDTH / 2;
    startY = SCREEN_HEIGHT + -10;
    width = 50;
    height = 10;
    speed = 5;

    x = startX;
    y = startY;

    oldX = x;
    oldY = y;
}
void BreakoutPaddle::begin(){
    draw();
}
void BreakoutPaddle::draw() {
   
    tft.fillRect(oldX, oldY, width, height, TFT_WHITE);
    tft.fillRect(x, y, width, height, TFT_BLACK);
}

void BreakoutPaddle::update() {
    oldX = x;
    oldY = y;

    move();

   
}

void BreakoutPaddle::move() {

    
    if (gamepadGet(6)) {
        x += speed;
        draw();
    }

   
    if (gamepadGet(5)) {
        x -= speed;
        draw();
    }

    if (y < SCORE_BOX_HEIGHT) {
        y = SCORE_BOX_HEIGHT;
    }

    
    if (y + height > SCREEN_HEIGHT) {
        y = SCREEN_HEIGHT - height;
    }
}


int BreakoutPaddle::GetPlayerX() const{
    return x;
}

int BreakoutPaddle::GetPlayerY() const{
    return y;
}

int BreakoutPaddle::GetPlayerWidth() const{
    return width;
}

int BreakoutPaddle::GetPlayerHeight() const{
    return height;
}