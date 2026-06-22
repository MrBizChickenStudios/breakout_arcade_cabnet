#include <Arduino.h>
#include <TFT_eSPI.h>
#include "Ball.h"
#include "Tft.h"


Ball ball(160, 120, 10);

void setup() {

    Serial.begin(115200);
    tft.init();
    tft.invertDisplay(false);
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
}

void loop() {
    ball.update();
    ball.draw();

    delay(1000 / 60);
}