#include "Display.h"

#include <LovyanGFX.hpp>

namespace BenchBuddy {
namespace BSP {

namespace {

constexpr int LcdMisoPin = 12;
constexpr int LcdMosiPin = 13;
constexpr int LcdSclkPin = 14;
constexpr int LcdCsPin = 15;
constexpr int LcdDcPin = 2;
constexpr int LcdResetPin = -1;
constexpr int BacklightPin = 21;

constexpr int DisplayWidth = 320;
constexpr int DisplayHeight = 240;

class Esp32_2432S028R_Lcd : public lgfx::LGFX_Device {
public:
  Esp32_2432S028R_Lcd() {
    {
      auto cfg = bus.config();
      cfg.spi_host = HSPI_HOST;
      cfg.spi_mode = 0;
      cfg.freq_write = 40000000;
      cfg.freq_read = 16000000;
      cfg.spi_3wire = false;
      cfg.use_lock = true;
      cfg.dma_channel = SPI_DMA_CH_AUTO;
      cfg.pin_sclk = LcdSclkPin;
      cfg.pin_mosi = LcdMosiPin;
      cfg.pin_miso = LcdMisoPin;
      cfg.pin_dc = LcdDcPin;
      bus.config(cfg);
      panel.setBus(&bus);
    }

    {
      auto cfg = panel.config();
      cfg.pin_cs = LcdCsPin;
      cfg.pin_rst = LcdResetPin;
      cfg.pin_busy = -1;
      cfg.panel_width = 240;
      cfg.panel_height = 320;
      cfg.memory_width = 240;
      cfg.memory_height = 320;
      cfg.offset_x = 0;
      cfg.offset_y = 0;
      cfg.offset_rotation = 0;
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits = 1;
      cfg.readable = true;
      cfg.invert = false;
      cfg.rgb_order = false;
      cfg.dlen_16bit = false;
      cfg.bus_shared = true;
      panel.config(cfg);
    }

    {
      auto cfg = light.config();
      cfg.pin_bl = BacklightPin;
      cfg.invert = false;
      cfg.freq = 44100;
      cfg.pwm_channel = 7;
      light.config(cfg);
      panel.setLight(&light);
    }

    setPanel(&panel);
  }

private:
  lgfx::Panel_ILI9341 panel;
  lgfx::Bus_SPI bus;
  lgfx::Light_PWM light;
};

Esp32_2432S028R_Lcd lcd;

} // namespace

void Display::begin() {
  if (initialized) {
    return;
  }

  lcd.init();
  lcd.setRotation(1);
  lcd.setBrightness(255);
  drawSplash();
  initialized = true;
}

void Display::update() {
}

void Display::drawSplash() {
  const uint32_t background = lcd.color888(12, 18, 30);
  const uint32_t accent = lcd.color888(56, 189, 248);
  const uint32_t text = lcd.color888(248, 250, 252);
  const uint32_t muted = lcd.color888(148, 163, 184);
  const uint32_t success = lcd.color888(34, 197, 94);

  lcd.fillScreen(background);
  lcd.drawRoundRect(18, 18, DisplayWidth - 36, DisplayHeight - 36, 10, accent);
  lcd.fillRoundRect(28, 28, DisplayWidth - 56, 4, 2, accent);

  lcd.setTextDatum(lgfx::textdatum::middle_center);
  lcd.setFont(&lgfx::fonts::Font4);
  lcd.setTextColor(text, background);
  lcd.drawString("BenchBuddy", DisplayWidth / 2, 82);

  lcd.setFont(&lgfx::fonts::Font2);
  lcd.setTextColor(muted, background);
  lcd.drawString("Version 0.1.0-dev", DisplayWidth / 2, 118);

  lcd.setTextColor(success, background);
  lcd.drawString("Display Test Passed", DisplayWidth / 2, 154);

  lcd.setTextColor(muted, background);
  lcd.drawString("ESP32-2432S028R LCD Bring-up", DisplayWidth / 2, 194);
}

} // namespace BSP
} // namespace BenchBuddy
