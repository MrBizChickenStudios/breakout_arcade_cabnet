#include "Paddle.h"
#include "Constants.h"

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

void Paddle::draw() {
   
    tft.fillRect(oldX, oldY, width, height, TFT_WHITE);
    tft.fillRect(x, y, width, height, TFT_BLACK);
}

void Paddle::update(int& screenBoxHeight) {
    oldX = x;
    oldY = y;

    move(screenBoxHeight);

   
}

void Paddle::move(int& screenBoxHeight) {

    
    if (gamepadGet(4)) {
        y += speed;
        draw();
    }

   
    if (gamepadGet(0)) {
        y -= speed;
        draw();
    }

    if (y < screenBoxHeight) {
        y = screenBoxHeight;
    }

    
    if (y + height > SCREEN_HEIGHT) {
        y = SCREEN_HEIGHT - height;
    }
}