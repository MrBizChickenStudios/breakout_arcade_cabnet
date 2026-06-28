#include <Arduino.h>
#include <TFT_eSPI.h>
#include "Touch.h"
#include "ButtonObject.h"
#include "Ball.h"

TFT_eSPI tft;

Ball ball(tft.height() / 2 , tft.width() / 2, 10);
int SCREEN_WIDTH = 0;
int SCREEN_HEIGHT = 0;

bool gameEnabled = false;

ButtonObject pongButton(50, 100, 140, 60, 10, "PONG");

void setup() {
    Serial.begin(115200);

    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_WHITE);
    SCREEN_WIDTH = tft.width(); ;
    SCREEN_HEIGHT = tft.height();

    touchSetup();

    pongButton.draw();

    
    pongButton.onClick = []() {
        gameEnabled = !gameEnabled;

        if (!gameEnabled) {
            tft.fillScreen(TFT_WHITE);
            ball.reset();
            pongButton.draw();
        }
    };
}

void loop() {

    if (touchPressed()) {
        TS_Point t = getTouch();

        pongButton.handleTouch(t.x, t.y);
        delay(150);
    }

    if (gameEnabled) {
        ball.update();
        ball.draw();
        delay(20);
    }
}