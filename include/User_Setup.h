#pragma once

// ---------------- DISPLAY ----------------
#define ST7789_DRIVER

#define TFT_WIDTH  240
#define TFT_HEIGHT 320

#define TFT_MOSI 13
#define TFT_SCLK 14
#define TFT_CS   15
#define TFT_DC   2
#define TFT_RST  -1

#define TFT_BL   21
#define TFT_BACKLIGHT_ON HIGH

#define TFT_RGB_ORDER TFT_BGR

#define SPI_FREQUENCY  27000000

// Fonts
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT8

// ---------------- TOUCH ----------------
#define TOUCH_XPT2046
#define TOUCH_CS 33
#define TOUCH_IRQ -1