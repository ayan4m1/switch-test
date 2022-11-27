#include "Display.hpp"

#include "PixelOperator8.hpp"

void Display::init() {
  pinMode(LCD_BCKL, OUTPUT);
  digitalWrite(LCD_BCKL, LOW);
  lcd.clear(lcd.bounds());
}

void Display::update() {
  auto bg = ok ? lcd_color::green : lcd_color::dark_red;
  char sz[32];
  open_text_info oti;
  oti.font = &PixelOperator8;
  oti.scale = PixelOperator8.scale(32);
  oti.offset = spoint16(-3, 0);
  oti.text = sz;
  snprintf(sz, sizeof(sz), "%d", count);

  ssize16 text_size = PixelOperator8.measure_text(
      ssize16::max(), spoint16::zero(), oti.text, oti.scale);
  srect16 text_rect = text_size.bounds().center((srect16)lcd.bounds());

  auto bmp = create_bitmap_from(lcd, (size16)text_size);
  if (bmp.begin() == nullptr) {
    return;
  }

  if (prevOk != ok) {
    draw::filled_rectangle(lcd, lcd.bounds(), bg);
  }

  draw::filled_rectangle(bmp, bmp.bounds(), bg);
  draw::text(bmp, bmp.bounds(), oti, lcd_color::white);
  draw::bitmap(lcd, text_rect, bmp, bmp.bounds());

  free(bmp.begin());

  prevOk = ok;
}

void Display::incrementCount() { count++; }

void Display::setOk(const bool ok) { this->ok = ok; }
