#include "Paddle.h"
#include "Constants.h"
#include "Score.h"

Score score;

Score::Score(){

    int playerScore = 0;
    int cpuScore = 0;

}

void Score::begin(){
    draw();
}

void Score::draw() {
    tft.fillRect(0, 0, SCREEN_WIDTH, SCORE_BOX_HEIGHT, TFT_BLACK);

    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(2);


    tft.setCursor(40, 8);
    tft.print(playerScore);


    tft.setCursor(SCREEN_WIDTH / 2 - 5, 8);
    tft.print(":");


    tft.setCursor(SCREEN_WIDTH - 55, 8);
    tft.print(cpuScore);

}


void Score::updatePlayerScore(){
    playerScore++;
    draw();
}

void Score::updateCpuPlayerScore(){
    cpuScore++;
    draw();
}


    


