#ifndef ADC_H
#define ADC_H

#include <Arduino.h>

extern byte checkMaxAmp;
extern byte ampThreshold;
extern unsigned int period;

void reset();
void init_adc();

#endif
