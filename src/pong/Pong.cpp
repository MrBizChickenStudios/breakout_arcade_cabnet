#include "Paddle.h"
#include "Constants.h"
#include "Pong.h"
#include "Ball.h"
#include "Score.h"
Pong pong;
void Pong::pongBegin(){
    paddle.begin();
    score.begin();
}

Pong::Pong(){


}


void Pong::draw() {
    ball.draw();


}



void Pong::update() {
    ball.update();
    paddle.update();
    cpuPaddle.update();

}

    


