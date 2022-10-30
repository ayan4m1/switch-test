#include "Buzzer.hpp"

uint32_t melody[][2] = {
    {400, 170}, {600, 448}, {400, 170}, {800, 448}, {300, 768}};

void Buzzer::init() { pinMode(LS_PIN, OUTPUT); }

void Buzzer::playNote(const uint32_t freq, const uint16_t dur) {
  tone(LS_PIN, freq, dur);
  delay(dur - 1);
}

void Buzzer::playMelody() {
  for (uint8_t i = 0; i < MELODY_NOTES; i++) {
    this->playNote(melody[i][0], melody[i][1]);
  }
}

void Buzzer::playTone() { tone(LS_PIN, LS_FREQ); }

void Buzzer::stopTone() { noTone(LS_PIN); }
