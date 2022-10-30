#ifndef BUZZER_HPP
#define BUZZER_HPP

#include <Arduino.h>

#define LS_PIN 18
#define LS_FREQ 4e3
#define MELODY_NOTES 5

class Buzzer {
  void playNote(const uint32_t freq, const uint16_t dur);

 public:
  void init();
  void playMelody();
  void playTone();
  void stopTone();
};

#endif
