#pragma once

#include <cstdint>

namespace BenchBuddy {
namespace BSP {

/**
 * ESP32-2432S028R LCD hardware support.
 *
 * Owns the LovyanGFX configuration for the onboard ILI9341 display and
 * XPT2046 touch controller. LVGL integration is intentionally excluded.
 */
class Display {
public:
  /**
   * Prepares the display hardware boundary.
   */
  void begin();

  /**
   * Runs display hardware maintenance for the current frame.
   */
  void update();

private:
  void drawHardwareTestScreen();
  void drawTouchState(int32_t screenX, int32_t screenY);

  bool initialized = false;
  int32_t lastScreenX = -1;
  int32_t lastScreenY = -1;
  uint32_t lastTouchUpdateAtMs = 0;
};

} // namespace BSP
} // namespace BenchBuddy
