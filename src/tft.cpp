#include "tft.h"

void init_tft(Adafruit_ST7735 &tft) {
    tft.initR(INITR_GREENTAB);
    tft.fillScreen(ST7735_BLACK);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
    tft.setTextSize(2);
    tft.setCursor(0, 0);
}

void draw_E(Adafruit_ST7735 &tft) {
    tft.drawChar(30, 30, 'E', ST7735_WHITE, ST7735_BLACK, 12);
    tft.setCursor(20, 130);
    tft.print("82.4Hz ");
}

void draw_A(Adafruit_ST7735 &tft) {
	tft.drawChar(30, 30, 'A', ST7735_WHITE, ST7735_BLACK, 12);
	tft.setCursor(20, 130);
	tft.print("110.0Hz");
}

void draw_D(Adafruit_ST7735 &tft) {
	tft.drawChar(30, 30, 'D', ST7735_WHITE, ST7735_BLACK, 12);
	tft.setCursor(20, 130);
	tft.print("146.8Hz");
}

void draw_G(Adafruit_ST7735 &tft) {
	tft.drawChar(30, 30, 'G', ST7735_WHITE, ST7735_BLACK, 12);
	tft.setCursor(20, 130);
	tft.print("196.0Hz");
}

void draw_B(Adafruit_ST7735 &tft) {
	tft.drawChar(30, 30, 'B', ST7735_WHITE, ST7735_BLACK, 12);
	tft.setCursor(20, 130);
	tft.print("246.9Hz");
}

void draw_e(Adafruit_ST7735 &tft) {
	tft.drawChar(30, 30, 'e', ST7735_WHITE, ST7735_BLACK, 12);
	tft.setCursor(20, 130);
	tft.print("329.6Hz");
}
