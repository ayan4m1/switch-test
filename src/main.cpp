#include <Arduino.h>
#include <Button2.h>

#define PIN_LS 6
#define PIN_SWITCH 7
#define LS_FREQ 4e3

Button2 button = Button2();

void pressed(Button2& btn) { tone(PIN_LS, LS_FREQ); }

void released(Button2& btn) { noTone(PIN_LS); }

void startupMelody() {
  tone(PIN_LS, 2000, 150);
  delay(150);
  tone(PIN_LS, 4000, 250);
  delay(250);
  tone(PIN_LS, 2000, 150);
  delay(1000);
}

void setup() {
  button.setPressedHandler(pressed);
  button.setReleasedHandler(released);
  button.begin(PIN_SWITCH);

  startupMelody();
}

void loop() { button.loop(); }
