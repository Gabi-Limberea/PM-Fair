#include "buttons.h"

uint8_t current_string;
unsigned long last_interrupt_time = 0;

void init_buttons() {
    DDRD &= ~(1 << PD2);
    DDRD &= ~(1 << PD3);
    PORTD |= (1 << PORTD2);
    PORTD |= (1 << PORTD3);

	EICRA ^= EICRA;
    EICRA |= (1 << ISC01) | (1 << ISC11);
    EIMSK |= (1 << INT1) | (1 << INT0);
}

ISR(INT0_vect) {
    if (millis() - last_interrupt_time > 200) {
        current_string = (current_string + 5) % 6;
        last_interrupt_time = millis();
    }
}

ISR(INT1_vect) {
    if (millis() - last_interrupt_time > 200) {
        current_string = (current_string + 1) % 6;
        last_interrupt_time = millis();
    }
}
