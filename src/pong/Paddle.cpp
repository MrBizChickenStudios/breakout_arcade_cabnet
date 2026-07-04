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

    oldX = x;
    oldY = y;
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

    
    if (gamepadGet(0)) {
        y += speed;
        draw();
    }

   
    if (gamepadGet(4)) {
        y -= speed;
        draw();
    }


}