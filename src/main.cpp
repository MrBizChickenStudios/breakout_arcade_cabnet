#include <Arduino.h>
#include <TFT_eSPI.h>
#include "Touch.h"
#include "ButtonObject.h"
#include "Ball.h"
#include "GamePad.h"



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

    gamepadBegin();

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

    // if (touchPressed()) {
    //     TS_Point t = getTouch();

    //     pongButton.handleTouch(t.x, t.y);
    //     delay(150);
    // }

    // if (gameEnabled) {
    //     ball.update();
    //     ball.draw();
    //     delay(20);
    // }

     gamepadUpdate();
    if (gamepadGet(0)) Serial.println("Button 0 pressed");
    if (gamepadGet(1)) Serial.println("Button 1 pressed");
    if (gamepadGet(2)) Serial.println("Button 2 pressed");
    if (gamepadGet(3)) Serial.println("Button 3 pressed");
    if (gamepadGet(4)) Serial.println("Button 4 pressed");
    if (gamepadGet(5)) Serial.println("Button 5 pressed");
    if (gamepadGet(6)) Serial.println("Button 6 pressed");
    if (gamepadGet(7)) Serial.println("Button 7 pressed");

    // delay(100);

    // digitalWrite(27, HIGH);
    // delay(50);
    // digitalWrite(27, LOW);
    // delay(50);    

}