#include "ButtonObject.h"
#include "Touch.h"

ButtonObject::ButtonObject(int x_, int y_, int w, int h, int r, String text) {
    x = x_;
    y = y_;
    width = w;
    height = h;
    radius = r;
    label = text;
    isPressed = false;
}

bool ButtonObject::contains(int px, int py) const {
    return px >= x && px < x + width &&
           py >= y && py < y + height;
}

void ButtonObject::draw() {
    uint16_t fillColor = isPressed ? TFT_GREEN : TFT_WHITE;

    tft.fillRoundRect(x, y, width, height, radius, fillColor);
    tft.setTextColor(TFT_BLACK);
    tft.setTextDatum(MC_DATUM);

    tft.drawString(label, x + width/2, y + height/2);
}

void ButtonObject::handleTouch(int tx, int ty) {
    if (!contains(tx, ty)) return;

    isPressed = !isPressed;
    draw();

    if (onClick) {
        onClick();  
    }
}