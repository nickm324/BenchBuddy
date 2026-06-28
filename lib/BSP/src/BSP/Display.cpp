#include "Display.h"

#include <Arduino.h>
#include <LovyanGFX.hpp>
#include <cstdio>

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

constexpr int TouchMosiPin = 32;
constexpr int TouchMisoPin = 39;
constexpr int TouchSclkPin = 25;
constexpr int TouchCsPin = 33;
constexpr int TouchIrqPin = 36;

constexpr int DisplayWidth = 320;
constexpr int DisplayHeight = 240;
constexpr int TouchStatusLeft = 20;
constexpr int TouchStatusTop = 176;
constexpr int TouchStatusWidth = 280;
constexpr int TouchStatusHeight = 52;
constexpr int TouchCircleRadius = 5;
constexpr uint32_t TouchUpdateIntervalMs = 100;

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

    {
      auto cfg = touch.config();
      cfg.x_min = 300;
      cfg.x_max = 3900;
      cfg.y_min = 300;
      cfg.y_max = 3900;
      cfg.pin_int = TouchIrqPin;
      cfg.bus_shared = false;
      cfg.offset_rotation = 0;
      cfg.spi_host = VSPI_HOST;
      cfg.freq = 1000000;
      cfg.pin_sclk = TouchSclkPin;
      cfg.pin_mosi = TouchMosiPin;
      cfg.pin_miso = TouchMisoPin;
      cfg.pin_cs = TouchCsPin;
      touch.config(cfg);
      panel.setTouch(&touch);
    }

    setPanel(&panel);
  }

private:
  friend class BenchBuddy::BSP::Display;

  lgfx::Panel_ILI9341 panel;
  lgfx::Bus_SPI bus;
  lgfx::Light_PWM light;
  lgfx::Touch_XPT2046 touch;
};

Esp32_2432S028R_Lcd lcd;
uint16_t touchCalibration[8] = {};

void printTouchCalibration() {
  Serial.println();
  Serial.println("BenchBuddy XPT2046 calibration values:");
  Serial.print("uint16_t touchCalibration[8] = { ");
  for (uint8_t index = 0; index < 8; ++index) {
    Serial.print(touchCalibration[index]);
    if (index < 7) {
      Serial.print(", ");
    }
  }
  Serial.println(" };");
}

} // namespace

void Display::begin() {
  if (initialized) {
    return;
  }

  Serial.begin(115200);
  lcd.init();
  lcd.setRotation(1);
  lcd.setBrightness(255);

  lcd.fillScreen(lcd.color888(2, 6, 23));
  lcd.setTextDatum(lgfx::textdatum::middle_center);
  lcd.setFont(&lgfx::fonts::Font2);
  lcd.setTextColor(lcd.color888(248, 250, 252), lcd.color888(2, 6, 23));
  lcd.drawString("Touch calibration", lcd.width() / 2, lcd.height() / 2);

  const uint8_t markerSize =
      static_cast<uint8_t>(((lcd.width() > lcd.height()) ? lcd.width()
                                                         : lcd.height()) >>
                           3);
  lcd.calibrateTouch(touchCalibration, lcd.color888(248, 250, 252),
                     lcd.color888(2, 6, 23), markerSize);
  lcd.setTouchCalibrate(touchCalibration);
  printTouchCalibration();

  drawHardwareTestScreen();
  lastTouchUpdateAtMs = millis();
  initialized = true;
}

void Display::update() {
  if (!initialized) {
    return;
  }

  const uint32_t now = millis();
  if (now - lastTouchUpdateAtMs < TouchUpdateIntervalMs) {
    return;
  }
  lastTouchUpdateAtMs = now;

  int32_t screenX = 0;
  int32_t screenY = 0;
  if (!lcd.getTouch(&screenX, &screenY)) {
    return;
  }

  drawTouchState(screenX, screenY);
  lastScreenX = screenX;
  lastScreenY = screenY;
}

void Display::drawHardwareTestScreen() {
  const uint32_t background = lcd.color888(2, 6, 23);
  const uint32_t border = lcd.color888(250, 204, 21);
  const uint32_t text = lcd.color888(248, 250, 252);
  const uint32_t muted = lcd.color888(148, 163, 184);
  const uint32_t crosshair = lcd.color888(34, 197, 94);

  lcd.fillScreen(background);
  lcd.drawRect(0, 0, DisplayWidth, DisplayHeight, border);
  lcd.drawRect(3, 3, DisplayWidth - 6, DisplayHeight - 6, border);

  lcd.setTextDatum(lgfx::textdatum::top_center);
  lcd.setFont(&lgfx::fonts::Font4);
  lcd.setTextColor(text, background);
  lcd.drawString("HARDWARE TEST", DisplayWidth / 2, 16);

  lcd.setFont(&lgfx::fonts::Font2);
  lcd.setTextColor(muted, background);
  lcd.drawString("Touch mapping debug", DisplayWidth / 2, 58);

  lcd.drawFastHLine(0, DisplayHeight / 2, DisplayWidth, crosshair);
  lcd.drawFastVLine(DisplayWidth / 2, 0, DisplayHeight, crosshair);
  lcd.drawCircle(DisplayWidth / 2, DisplayHeight / 2, 12, crosshair);

  const uint32_t panelBackground = lcd.color888(15, 23, 42);
  lcd.fillRect(TouchStatusLeft, TouchStatusTop, TouchStatusWidth, TouchStatusHeight,
               panelBackground);
  lcd.drawRoundRect(TouchStatusLeft, TouchStatusTop, TouchStatusWidth,
                    TouchStatusHeight, 6, muted);
  lcd.setTextDatum(lgfx::textdatum::middle_center);
  lcd.setTextColor(muted, panelBackground);
  lcd.drawString("Waiting for touch...", DisplayWidth / 2,
                 TouchStatusTop + (TouchStatusHeight / 2));
}

void Display::drawTouchState(int32_t screenX, int32_t screenY) {
  const uint32_t panelBackground = lcd.color888(15, 23, 42);
  const uint32_t text = lcd.color888(248, 250, 252);
  const uint32_t muted = lcd.color888(148, 163, 184);
  const uint32_t red = lcd.color888(239, 68, 68);

  lcd.fillRect(TouchStatusLeft, TouchStatusTop, TouchStatusWidth, TouchStatusHeight,
               panelBackground);
  lcd.drawRoundRect(TouchStatusLeft, TouchStatusTop, TouchStatusWidth,
                    TouchStatusHeight, 6, muted);

  lcd.setTextDatum(lgfx::textdatum::middle_center);
  lcd.setFont(&lgfx::fonts::Font2);

  lcd.setTextColor(muted, panelBackground);
  lcd.drawString("LovyanGFX calibrated touch", DisplayWidth / 2,
                 TouchStatusTop + 16);

  char touchMessage[40];
  std::snprintf(touchMessage, sizeof(touchMessage), "TOUCH: x=%ld y=%ld",
                static_cast<long>(screenX), static_cast<long>(screenY));
  lcd.setTextColor(text, panelBackground);
  lcd.drawString(touchMessage, DisplayWidth / 2, TouchStatusTop + 38);

  if (screenY < TouchStatusTop - TouchCircleRadius - 2) {
    lcd.fillCircle(screenX, screenY, TouchCircleRadius, red);
  }
}

} // namespace BSP
} // namespace BenchBuddy
