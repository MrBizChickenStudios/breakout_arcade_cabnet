#pragma once
#include <Arduino.h>
#include <functional>
#include <TFT_eSPI.h>

extern TFT_eSPI tft;

class ButtonObject {
public:
    int x, y, width, height, radius;
    String label;
    bool isPressed;

    std::function<void()> onClick; 

    ButtonObject(int x_, int y_, int w, int h, int r, String text);

    void draw();
    bool contains(int px, int py) const;
    void handleTouch(int tx, int ty);
};