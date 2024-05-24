#ifndef LED_H
#define LED_H

void init_led();
void led_off();
void led_compare_and_on(const float &reference_frequency,
                        const float &frequency);

#endif
