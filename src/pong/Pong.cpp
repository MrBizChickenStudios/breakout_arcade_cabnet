#include "Paddle.h"
#include "Constants.h"
#include "Pong.h"
#include "Ball.h"

Pong pong;

Pong::Pong(){

    ball = Ball();
    paddle = Paddle();
    cpuPaddle = CPUPaddle();

}

void Pong::drawScore() {

    
    if (playerScore == lastPlayerScore &&
        cpuScore == lastCpuScore) {
        return;
    }

    lastPlayerScore = playerScore;
    lastCpuScore = cpuScore;
    
    tft.fillRect(0, 0, SCREEN_WIDTH, screenBoxHeight, TFT_BLACK);

    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(2);

   
    tft.setCursor(40, 8);
    tft.print(playerScore);

   
    tft.setCursor(SCREEN_WIDTH / 2 - 5, 8);
    tft.print(":");

    
    tft.setCursor(SCREEN_WIDTH - 55, 8);
    tft.print(cpuScore);
}

void Pong::draw() {
    ball.draw();
    drawScore();

}



void Pong::update() {
    ball.update(paddle, cpuPaddle, playerScore, cpuScore, screenBoxHeight);
    paddle.update(screenBoxHeight);
    cpuPaddle.update(ball.y, ball.x, screenBoxHeight);

}

    


