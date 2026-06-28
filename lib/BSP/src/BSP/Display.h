#pragma once

namespace BenchBuddy {
namespace BSP {

/**
 * ESP32-2432S028R LCD hardware support.
 *
 * Owns the LovyanGFX configuration for the onboard ILI9341 display only.
 * Touch and LVGL integration are intentionally excluded from this layer for
 * the initial display bring-up.
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
  void drawSplash();

  bool initialized = false;
};

} // namespace BSP
} // namespace BenchBuddy
