#include "CPUPaddle.h"
#include "Constants.h"

CPUPaddle::CPUPaddle() {
    startX = SCREEN_WIDTH - 10;
    startY = SCREEN_HEIGHT / 2;
    width = 10;
    height = 50;
    speed = 5;

    x = startX;
    y = startY;

    oldX = x;
    oldY = y;
}

void CPUPaddle::draw() {
   
    tft.fillRect(oldX, oldY, width, height, TFT_WHITE);

   
    tft.fillRect(x, y, width, height, TFT_BLACK);
}

void CPUPaddle::update(int ballY, int ballX, int& screenBoxHeight)
{
    oldX = x;
    oldY = y;

    move(ballY, ballX, screenBoxHeight);
    
}

void CPUPaddle::move(int ballY, int ballX, int& screenBoxHeight)
{
    oldX = x;
    oldY = y;

    // Only track when ball is on CPU side
    if (ballX > tft.width() / 2)
    {
        int center = y + height / 2;
        

        int diff = ballY - center;

    
        if (abs(diff) > 3)
        {
            if (diff > 0)
                y += speed;
            else
                y -= speed;
        }
        draw();
    }

    // Clamp movement
    if (y < screenBoxHeight + 5)
        y = screenBoxHeight + 5;

    if (y + height > SCREEN_HEIGHT)
        y = SCREEN_HEIGHT - height;
}