#include "Paddle.h"
#include "Constants.h"

Paddle paddle;

Paddle::Paddle() {
    startX = 10;
    startY = SCREEN_HEIGHT / 2;
    width = 10;
    height = 50;
    speed = 5;

    x = startX;
    y = startY;

    oldX = x;
    oldY = y;
}
void Paddle::begin(){
    draw();
}
void Paddle::draw() {
   
    tft.fillRect(oldX, oldY, width, height, TFT_WHITE);
    tft.fillRect(x, y, width, height, TFT_BLACK);
}

void Paddle::update() {
    oldX = x;
    oldY = y;

    move();

   
}

void Paddle::move() {

    
    if (gamepadGet(4)) {
        y += speed;
        draw();
    }

   
    if (gamepadGet(0)) {
        y -= speed;
        draw();
    }

    if (y < SCORE_BOX_HEIGHT) {
        y = SCORE_BOX_HEIGHT;
    }

    
    if (y + height > SCREEN_HEIGHT) {
        y = SCREEN_HEIGHT - height;
    }
}


int Paddle::GetPlayerX() const{
    return x;
}

int Paddle::GetPlayerY() const{
    return y;
}

int Paddle::GetPlayerWidth() const{
    return width;
}

int Paddle::GetPlayerHeight() const{
    return height;
}