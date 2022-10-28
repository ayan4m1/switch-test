#include <Arduino.h>
#include <Button2.h>
#include <FastLED.h>

#define PIN_LS 6
#define PIN_SWITCH 7
#define PIN_RGB_POWER 38
#define PIN_RGB 39
#define LS_FREQ 4e3
#define NUM_RGB 1

CRGB leds[NUM_RGB] = {CRGB::Orange};
Button2 button = Button2();

void pressed(Button2& btn) {
  tone(PIN_LS, LS_FREQ);
  leds[0] = CRGB::Green;
}

void released(Button2& btn) {
  noTone(PIN_LS);
  leds[0] = CRGB::Red;
}

void note(uint32_t freq, uint16_t dur) {
  tone(PIN_LS, freq, dur);
  delay(dur - 1);
}

void startupMelody() {
  note(400, 170);
  note(600, 448);
  note(400, 170);
  note(800, 448);
  note(300, 768);
}

void setup() {
  pinMode(PIN_RGB_POWER, OUTPUT);
  digitalWrite(PIN_RGB_POWER, HIGH);

  FastLED.addLeds<NEOPIXEL, PIN_RGB>(leds, NUM_RGB);
  FastLED.show();

  button.setPressedHandler(pressed);
  button.setReleasedHandler(released);
  button.begin(PIN_SWITCH);

  startupMelody();

  leds[0] = CRGB::Red;
}

void loop() {
  button.loop();
  FastLED.show();
}
