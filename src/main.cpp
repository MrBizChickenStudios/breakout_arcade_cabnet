#include <Arduino.h>
#include <TFT_eSPI.h>
#include "Ball.h"
#include "Tft.h"
#include "Constants.h"
#include "ButtonObject.h"

Ball ball(160, 120, 10);


int SCREEN_WIDTH = 0;
int SCREEN_HEIGHT = 0;

void setup() {

    Serial.begin(115200);
    tft.init();
    SCREEN_WIDTH = tft.height(); ;
    SCREEN_HEIGHT = tft.width();
    tft.invertDisplay(false);
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
}
ButtonObject button(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 25, 100, 50, 10);

void loop() {
    ball.update();
    ball.draw();
    button.draw();


    delay(1000 / 60);
}