#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Arduino.h>

#include "adc.h"
#include "buttons.h"
#include "led.h"
#include "tft.h"

#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8

#define RED 4
#define GREEN 5
#define BLUE 6

#define PREV_BUTTON 2
#define NEXT_BUTTON 3

// data storage variables
float frequency = 0;
float reference_frequency = 0;

// put function declarations here:
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
    Serial.begin(9600);
    Serial.println("Initializing...");

    cli();

    Serial.println("Setting up TFT display...");
    init_tft(tft);

    Serial.println("Setting up buttons and interrupts...");
    init_buttons();

    Serial.println("Setting up LEDs...");
    init_led();

    Serial.println("Setting up ADC...");
    init_adc();

    sei();

    current_string = E;
    prev_string = E;
    reference_frequency = 82.41;

    Serial.println("Setup complete!");
}

void loop() {
    switch (current_string) {
    case E:
        draw_E(tft);
        reference_frequency = 82.41;
        break;
    case A:
        draw_A(tft);
        reference_frequency = 110.00;
        break;
    case D:
        draw_D(tft);
        reference_frequency = 146.83;
        break;
    case G:
        draw_G(tft);
        reference_frequency = 196.00;
        break;
    case B:
        draw_B(tft);
        reference_frequency = 246.94;
        break;
    case e:
        draw_e(tft);
        reference_frequency = 329.63;
        break;
    }

    if (current_string != prev_string) {
        led_off();
        prev_string = current_string;
    }

    if (checkMaxAmp > ampThreshold) {
        frequency = 38462 / float(period);

        if (frequency > 30.0 && frequency < 500.0) {
            // Serial.println(frequency);
            led_compare_and_on(reference_frequency, frequency);
        }
    }

    delay(100);
}
