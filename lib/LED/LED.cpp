#include "LED.hpp"

void LED::init() {
  pinMode(RGB_PIN_POWER, OUTPUT);
  digitalWrite(RGB_PIN_POWER, HIGH);

  FastLED.addLeds<NEOPIXEL, RGB_PIN_DATA>(leds, RGB_NUM_LEDS);
  FastLED.show();
}

void LED::loop() { FastLED.show(); }

void LED::setColor(const CRGB color) { leds[0] = color; }
