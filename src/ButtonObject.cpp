#include "ButtonObject.h"

ButtonObject::ButtonObject(int x_, int y_, int w, int h, int r) {
    x = x_;
    y = y_;
    width = w;
    height = h;
    radius = r;
}

void ButtonObject::draw() {
    tft.fillRoundRect(x, y, width, height, radius, TFT_WHITE);
}



