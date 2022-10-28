#include <Arduino.h>
#include <Button2.h>

#define PIN_LS 6
#define PIN_SWITCH 7
#define LS_FREQ 4e3

Button2 button = Button2();

void pressed(Button2& btn) { tone(PIN_LS, LS_FREQ); }

void released(Button2& btn) { noTone(PIN_LS); }

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
  button.setPressedHandler(pressed);
  button.setReleasedHandler(released);
  button.begin(PIN_SWITCH);

  startupMelody();
}

void loop() { button.loop(); }
