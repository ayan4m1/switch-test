#include <Arduino.h>
#include <FastLED.h>

#include <Buzzer.hpp>
#include <Display.hpp>
#include <htcw_button.hpp>

#define SWITCH_PIN 36

using namespace arduino;
using btn_t = button<SWITCH_PIN, 10, true>;

btn_t btn;
Buzzer buzzer = Buzzer();
Display display = Display();

void stateChange(const bool pressed, void* state) {
  display.setOk(pressed);
  if (pressed) {
    buzzer.playTone();
    display.incrementCount();
  } else {
    buzzer.stopTone();
  }
}

void setup() {
  display.init();

  btn.callback(stateChange);
  btn.initialize();

  buzzer.init();
  buzzer.playMelody();
}

void loop() {
  btn.update();

  EVERY_N_MILLIS(100) { display.update(); }
}
