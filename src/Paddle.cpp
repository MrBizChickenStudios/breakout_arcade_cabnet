#include "Paddle.h"
#include "Constants.h"


Paddle::Paddle(int startX, int startY, int width, int height, int speed) {
    this->startX = startX;
    this->startY = startY;
    this->width = width;
    this->height = height;
    this->speed = speed;
    x = startX;
    y = startY;
    oldX = startX;
    oldY = startY;
}

void Paddle::draw() {
    tft.fillRect(oldX, oldY, width, height, TFT_WHITE);
    tft.fillRect(x, y, width, height, TFT_BLACK);
   
}



void Paddle::update(bool breakoutMode) {
    oldX = x;
    oldY = y;
    if (breakoutMode) {
        if (gamepadGet(1) && x + width < SCREEN_WIDTH) {
            x += speed;
        }

    
        if (gamepadGet(2) && x > 0) {
            x -= speed;
        }

    }

    if (!breakoutMode) {
        if (gamepadGet(0) && y + height < SCREEN_HEIGHT) {
            y += speed;
        }

        if (gamepadGet(4) && y > 0) {
            y -= speed;
        }
    }



}

    


