#pragma once
#include <Arduino.h>
#include <TFT_eSPI.h>



class Score {
public:
    Score();

    void draw();
    void update();
    void updatePlayerScore();
    void updateCpuPlayerScore();
    void begin();

private:


    int playerScore = 0;
    int cpuScore = 0;

};

extern Score score;