#ifndef TFT_H
#define TFT_H

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

void init_tft(Adafruit_ST7735 &tft);
void draw_E(Adafruit_ST7735 &tft);
void draw_A(Adafruit_ST7735 &tft);
void draw_D(Adafruit_ST7735 &tft);
void draw_G(Adafruit_ST7735 &tft);
void draw_B(Adafruit_ST7735 &tft);
void draw_e(Adafruit_ST7735 &tft);

#endif
