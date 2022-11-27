#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <Arduino.h>

#include <gfx.hpp>
#include <st7789.hpp>

#define LCD_WIDTH 128
#define LCD_HEIGHT 128
#define LCD_ROTATION 0
#define LCD_PORT 0
#define LCD_MISO -1
#define LCD_MOSI 2
#define LCD_CLK 3
#define LCD_CS 5
#define LCD_DC 6
#define LCD_RST 1
#define LCD_BCKL -1
#define LCD_READ_SPEED_PERCENT 400
#define LCD_WRITE_SPEED_PERCENT 200

using namespace arduino;
using namespace gfx;

using bus_type =
    tft_spi_ex<LCD_PORT, LCD_CS, LCD_MOSI, -1, LCD_CLK, SPI_MODE0, true>;
using lcd_type =
    st7789<LCD_WIDTH, LCD_HEIGHT, LCD_DC, LCD_RST, -1, bus_type, LCD_ROTATION,
           true, LCD_READ_SPEED_PERCENT, LCD_WRITE_SPEED_PERCENT>;
using lcd_color = color<typename lcd_type::pixel_type>;

class Display {
  uint32_t count = 0;
  int8_t prevOk = -1;
  int8_t ok = 0;
  lcd_type lcd;

 public:
  void init();
  void incrementCount();
  void setOk(const bool ok);
  void update();
};

#endif
