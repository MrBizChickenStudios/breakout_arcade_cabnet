#include "Paddle.h"
#include "Constants.h"
#include "Pong.h"


Pong::Pong(int screenW, int screenH)
    : screenW(screenW),
      screenH(screenH),
      ball(tft.width() / 2, tft.height() / 2, 10),
      paddle(10, tft.height() / 2, 10, 50, 5),
      cpuPaddle(tft.height() - 10, tft.width() / 2, 10, 50, 5)
{
}

void Pong::draw() {
    ball.draw();


}



void Pong::update() {
    ball.update(paddle, cpuPaddle);
    paddle.update();
    cpuPaddle.update(ball.y, ball.x);

}

    


