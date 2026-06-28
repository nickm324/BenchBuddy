#pragma once

namespace BenchBuddy {
namespace BSP {

/**
 * Placeholder for ESP32-2432S028R display backlight support.
 *
 * Brightness control and GPIO or PWM setup will be added after pin assignments
 * are verified.
 */
class Backlight {
public:
  /**
   * Prepares the backlight hardware boundary.
   */
  void begin();

  /**
   * Runs backlight hardware maintenance for the current frame.
   */
  void update();
};

} // namespace BSP
} // namespace BenchBuddy
