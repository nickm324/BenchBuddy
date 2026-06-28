#pragma once

namespace BenchBuddy {
namespace BSP {

/**
 * Placeholder for ESP32-2432S028R status LED support.
 *
 * RGB LED control will be added after pin assignments and drive behavior are
 * verified.
 */
class StatusLed {
public:
  /**
   * Prepares the status LED hardware boundary.
   */
  void begin();

  /**
   * Runs status LED hardware maintenance for the current frame.
   */
  void update();
};

} // namespace BSP
} // namespace BenchBuddy
