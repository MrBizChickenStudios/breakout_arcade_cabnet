#include <Arduino.h>
#include <TFT_eSPI.h>
#include "Touch.h"
#include "ButtonObject.h"

#include "GamePad.h"
// #include "Paddle.h"
#include "pong/Ball.h"
#include "pong/Paddle.h"
#include "pong/CPUPaddle.h"
#include "pong/Pong.h"
TFT_eSPI tft;

int SCREEN_WIDTH = 0;
int SCREEN_HEIGHT = 0;
Pong pong(SCREEN_WIDTH, SCREEN_HEIGHT);
// Paddle paddle(SCREEN_WIDTH + 2, SCREEN_HEIGHT / 2, 10, 50, 5);
// // Paddle paddle2(100, 100, 50, 10, 5);

// Ball ball(tft.width() / 2, tft.height() / 2, 10);

// bool pongGameEnabled = false;
// bool breakoutGameEnabled = false;

// ButtonObject pongButton(30, 100, 80, 60, 10, "PONG");
// ButtonObject breakoutButton(130, 100, 80, 60, 10, "BREAKOUT");


// void drawMenu() {
//     tft.fillScreen(TFT_WHITE);
//     pongButton.draw();
//     breakoutButton.draw();
// }

// void menu(){
//     if (gamepadGet(3)) {

//         pongGameEnabled = false;
//         breakoutGameEnabled = false;

//         ball.reset();


//         tft.fillScreen(TFT_WHITE);

//         drawMenu();
//     }
// }
void setup() {
    Serial.begin(115200);

    tft.init();
    tft.setRotation(1);

    SCREEN_WIDTH = tft.width();
    SCREEN_HEIGHT = tft.height();

    tft.fillScreen(TFT_WHITE);

    // touchSetup();
    gamepadBegin();




    // pongButton.onClick = []() {
    //     pongGameEnabled = true;
    //     breakoutGameEnabled = false;

    //     tft.fillScreen(TFT_WHITE);
    //     ball.reset();
    // };

    // breakoutButton.onClick = []() {
    //     breakoutGameEnabled = true;
    //     pongGameEnabled = false;

    //     tft.fillScreen(TFT_WHITE);
    //     ball.reset();
    // };
    // drawMenu();
}

void loop() {
    pong.draw();
    pong.update();
    gamepadUpdate();

    // if (touchPressed()) {
    //     TS_Point t = getTouch();

    //     if (!pongGameEnabled && !breakoutGameEnabled) {
    //         pongButton.handleTouch(t.x, t.y);
    //         breakoutButton.handleTouch(t.x, t.y);
    //     }

    //     delay(150);
    // }

    // if (pongGameEnabled) {
    //     ball.update();
    //     paddle.update(false);

    //     ball.draw();
       
    // }

    // if (breakoutGameEnabled) {
    //     ball.update();
    //     paddle.update(true);

    //     ball.draw();
   
    // }

    for (int i = 0; i < 8; i++) {
        if (gamepadGet(i)) {
            Serial.print("Button ");
            Serial.print(i);
            Serial.println(" pressed");
        }
    }
    // menu();
    delay(20);
}