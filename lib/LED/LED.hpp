#ifndef LED_HPP
#define LED_HPP

#include <Arduino.h>
#include <FastLED.h>

#define RGB_PIN_POWER 38
#define RGB_PIN_DATA 39
#define RGB_NUM_LEDS 1

#define COLOR_OK CRGB::Green
#define COLOR_READY CRGB::Red

class LED {
  CRGB leds[RGB_NUM_LEDS] = {COLOR_READY};

 public:
  void setColor(const CRGB color);
  void init();
  void loop();
};

#endif
