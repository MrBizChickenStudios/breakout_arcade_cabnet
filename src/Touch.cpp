#include "Touch.h"
#include <SPI.h>
#include <XPT2046_Touchscreen.h>

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

#define XPT2046_CS 33
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25

// raw touch calibration
#define X_MIN 550
#define X_MAX 3755

#define Y_MIN 624
#define Y_MAX 3319

XPT2046_Touchscreen ts(XPT2046_CS);

// ---------------- INIT ----------------
void touchSetup() {
    SPI.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
    ts.begin();
}

// ---------------- RAW PRESS CHECK ----------------
bool touchPressed() {
    return ts.touched();
}

// ---------------- MAPPED TOUCH (THIS IS STEP 2 + 3) ----------------
TS_Point getTouch() {
    TS_Point p = ts.getPoint();

   int x = map(p.x, 568, 3755, 0, SCREEN_HEIGHT);
   int y = map(p.y, 624, 3319, 0, SCREEN_WIDTH);

    x = constrain(x, 0, 239);
    y = constrain(y, 0, 319);

    return TS_Point(x, y, p.z);
}