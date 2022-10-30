#include "Display.hpp"

#include "PixelOperator8.hpp"

void Display::init() { lcd.clear(lcd.bounds()); }

void Display::update(const uint32_t count) {
  char sz[32];
  draw::suspend(lcd);
  draw::filled_rectangle(lcd, lcd.bounds(), lcd_color::black);
  open_text_info oti;
  oti.font = &PixelOperator8;
  oti.scale = PixelOperator8.scale(24);
  oti.text = sz;
  snprintf(sz, sizeof(sz), "%d", count);
  ssize16 text_size = PixelOperator8.measure_text(
      ssize16::max(), spoint16::zero(), oti.text, oti.scale);
  srect16 text_rect = text_size.bounds().center((srect16)lcd.bounds());
  draw::text(lcd, text_rect, oti, lcd_color::white);
  draw::resume(lcd);
}
