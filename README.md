## Electric Guitar Tuner

### Gabriela Limberea - 332CA

## Description

This is the source code for an electric guitar tuner that uses a 6.3mm input jack to
receive the guitar signal, amplify it and then compute the frequency of the note played.
The tuner allows the user to select a reference note/frequency using buttons and an LCD,
and then and LED will indicate if the string needs to be tuned up or down.

## Libraries

The project uses the following libraries:

-   `Arduino.h` - for the Serial communication
-   `Adafruit_GFX.h` and `Adafruit_ST7735.h` - for the LCD display, instead of the
    default `TFT.h` library that is based on the Adafruit libraries and has been
    deprecated. It is specifically designed for the ST7735 display, which use
    SPI communication.

## Code structure

1. `adc.cpp/h` - contains the initialization function for the ADC and the definition
   of the interrupt service routine that reads the ADC value and computes the max amplitude of the signal and its period. The code is the same as in
   [this instructable](https://www.instructables.com/Arduino-Frequency-Detection/),
   with a few modifications to adapt it to the project.

2. `tft.cpp/h` - contains the initialization function for the LCD display and the
   functions that write the text on the screen.

3. `buttons.cpp/h` - contains the initialization function for the buttons and the
   definition of the interrupt service routines that handle the button presses.

4. `led.cpp/h` - contains the initialization function for the LED and the function
   that turns it on or off based on the computed frequency.

5. `main.cpp` - the main file that contains the setup and loop functions. In `setup()`
   all the components are initialized and interrupts are enabled. In `loop()`, the
   program handles the output to the screen and the LED based on the computed frequency.

## Sources

-   [Arduino Frequency Detection](https://www.instructables.com/Arduino-Frequency-Detection/)
-   [Arduino Audio Input](https://www.instructables.com/Arduino-Audio-Input/)
