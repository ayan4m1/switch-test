#include <Arduino.h>
#include <Button2.h>
#include <FastLED.h>

#include <Buzzer.hpp>
#include <Display.hpp>
#include <LED.hpp>

#define SWITCH_PIN 17

Button2 button = Button2();
Buzzer buzzer = Buzzer();
Display display = Display();
LED led = LED();

void pressed(Button2& btn) {
  display.setOk(true);
  buzzer.playTone();
  display.incrementCount();
}

void released(Button2& btn) {
  display.setOk(false);
  buzzer.stopTone();
}

void setup() {
  display.init();

  led.init();

  button.setPressedHandler(pressed);
  button.setReleasedHandler(released);
  button.begin(SWITCH_PIN);

  buzzer.init();
  buzzer.playMelody();
}

void loop() {
  button.loop();
  led.loop();

  EVERY_N_MILLIS(100) { display.update(); }
}
