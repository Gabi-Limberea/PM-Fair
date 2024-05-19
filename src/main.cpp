#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Arduino.h>

#define TFT_CS 10
#define TFT_RST 9
#define TFT_DC 8

#define RED 4
#define GREEN 5
#define BLUE 6

#define PREV_BUTTON 2
#define NEXT_BUTTON 3

// put function declarations here:
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
// int prev_button_pressed = 0;
// int next_button_pressed = 0;

void setup() {
	Serial.begin(9600);
	Serial.println("Initializing...");

    // put your setup code here, to run once:
    cli();

	Serial.println("Setting up TFT display...");
    tft.initR(INITR_BLACKTAB);
    tft.fillScreen(ST7735_BLACK);
    tft.setTextColor(ST7735_WHITE);
    tft.setTextSize(2);
    tft.setCursor(0, 0);

	Serial.println("Setting up buttons...");
	DDRD &= ~(1 << PD2);
	DDRD &= ~(1 << PD3);
	PORTD |= (1 << PORTD2);
	PORTD |= (1 << PORTD3);

	// Serial.println("Setting up LEDs...");
    // DDRD |= (1 << PD4) | (1 << PD5) | (1 << PD6);

	Serial.println("Setting up interrupts...");
    EICRA ^= EICRA;
    EICRA |= (1 << ISC01) | (1 << ISC11);
    EIMSK |= (1 << INT1) | (1 << INT0);

    sei();

	Serial.println("Setup complete!");
}

ISR(INT0_vect) { Serial.println("Prev button pressed!"); }

ISR(INT1_vect) { Serial.println("Next button pressed!"); }

void loop() {
    // put your main code here, to run repeatedly:
    tft.print("Hello, world!");

	// PORTD |= (1 << PD5);
	// PORTD &= ~(1 << PD4);
	// PORTD &= ~(1 << PD6);

    // Serial.println("prev: ");
    // Serial.println(PIND & (1 << PIND2));

    // Serial.println("next: ");
    // Serial.println(PIND & (1 << PIND3));

	
    // digitalWrite(RED, 255);
    // digitalWrite(GREEN, 255);
    // digitalWrite(BLUE, 0);

    delay(1000);
}

// #include <Arduino.h>
// void setup() {
// 	// put your setup code here, to run once:
// }

// void loop() {
// 	// put your main code here, to run repeatedly:
// }
