#include "CPUPaddle.h"
#include "Constants.h"

CPUPaddle::CPUPaddle(int startX, int startY, int width, int height, int speed) {
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

void CPUPaddle::draw() {
   
    tft.fillRect(oldX, oldY, width, height, TFT_WHITE);

   
    tft.fillRect(x, y, width, height, TFT_BLACK);
}

void CPUPaddle::update(int ballY, int ballX)
{
    oldX = x;
    oldY = y;

    move(ballY, ballX);
    draw();
}

void CPUPaddle::move(int ballY, int ballX)
{  

    if (ballX > tft.width() / 2){
            int center = y + height / 2;

        if (ballY > center) {
            y += speed;
            draw();
        } else if (ballY < center) {
            y -= speed;
            draw();
        }
    }

}