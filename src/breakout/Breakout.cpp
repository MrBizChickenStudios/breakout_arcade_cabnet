#include "Paddle.h"
#include "Constants.h"
#include "Breakout.h"
#include "Ball.h"

Breakout breakout;
void Breakout::breakoutBegin(){
    breakoutPaddle.begin();

}

Breakout::Breakout(){


}


void Breakout::draw() {
    breakoutBall.draw();


}



void Breakout::update() {
    breakoutBall.update();
    breakoutPaddle.update();


}

    


