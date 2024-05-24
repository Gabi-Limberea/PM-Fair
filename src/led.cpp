#include "led.h"
#include <Arduino.h>

void init_led() { DDRD |= (1 << PD4) | (1 << PD5) | (1 << PD6); }

void led_off() { PORTD &= ~((1 << PD4) | (1 << PD5) | (1 << PD6)); }

void led_compare_and_on(const float &reference_frequency,
                        const float &frequency) {
    if ((frequency - reference_frequency) < -1.0) {
        PORTD |= (1 << PD4);
        PORTD &= ~((1 << PD5) | (1 << PD6));
    } else if ((frequency - reference_frequency) > 1.0) {
        PORTD |= (1 << PD6);
        PORTD &= ~((1 << PD4) | (1 << PD5));
    } else if (abs(frequency - reference_frequency) < 1.0) {
        PORTD |= (1 << PD5);
        PORTD &= ~((1 << PD4) | (1 << PD6));
    }
}
