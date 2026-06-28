#pragma once

namespace BenchBuddy {
namespace BSP {

/**
 * Placeholder for ESP32-2432S028R touch hardware support.
 *
 * The future implementation will configure the XPT2046 touch controller after
 * pin assignments are verified.
 */
class Touch {
public:
  /**
   * Prepares the touch hardware boundary.
   */
  void begin();

  /**
   * Runs touch hardware maintenance for the current frame.
   */
  void update();
};

} // namespace BSP
} // namespace BenchBuddy
