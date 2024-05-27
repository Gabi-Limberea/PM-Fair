#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

enum GuitarStrings { E = 0, A = 1, D = 2, G = 3, B = 4, e = 5 };

extern uint8_t current_string;
extern uint8_t prev_string;

void init_buttons();

#endif
