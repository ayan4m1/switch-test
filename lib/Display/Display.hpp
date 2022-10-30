#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <Arduino.h>

#include <gfx.hpp>
#include <ssd1306.hpp>

#include "PixelOperator8.hpp"

#define LCD_WIDTH 128
#define LCD_HEIGHT 32
#define LCD_ROTATION 0
#define LCD_BIT_DEPTH 1
#define LCD_PORT 0
#define LCD_PIN_SDA 7
#define LCD_PIN_SCL 6
#define LCD_PIN_RST -1
#define LCD_PIN_DC -1
#define LCD_WRITE_SPEED_PERCENT 400
#define LCD_ADDRESS 0x3C
#define LCD_VDC_3_3 true

using namespace arduino;
using namespace gfx;

using bus_type = tft_i2c_ex<LCD_PORT, LCD_PIN_SDA, LCD_PIN_SCL>;
using lcd_type =
    ssd1306<LCD_WIDTH, LCD_HEIGHT, bus_type, LCD_ROTATION, LCD_BIT_DEPTH,
            LCD_ADDRESS, LCD_VDC_3_3, LCD_WRITE_SPEED_PERCENT, LCD_PIN_DC,
            LCD_PIN_RST, true>;
using lcd_color = color<typename lcd_type::pixel_type>;

class Display {
  lcd_type lcd;

 public:
  void init();
  void update(const uint32_t count);
};

#endif
