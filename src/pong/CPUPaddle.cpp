#include "CPUPaddle.h"
#include "Constants.h"
#include "Ball.h"
CPUPaddle cpuPaddle;

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

void CPUPaddle::update()
{
    oldX = x;
    oldY = y;

    move();
    
}

void CPUPaddle::move()
{
    oldX = x;
    oldY = y;

    // Only track when ball is on CPU side
    if (ball.GetBallX()> tft.width() / 2)
    {
        int center = y + height / 2;
        

        int diff = ball.GetBallY() - center;

    
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
    if (y < SCORE_BOX_HEIGHT + 5)
        y = SCORE_BOX_HEIGHT + 5;

    if (y + height > SCREEN_HEIGHT)
        y = SCREEN_HEIGHT - height;
}

int CPUPaddle::GetCpuX() const{
    return x;
}

int CPUPaddle::GetCpuY() const{
    return y;
}

int CPUPaddle::GetCpuWidth() const{
    return width;
}

int CPUPaddle::GetCpuHeight() const{
    return height;
}