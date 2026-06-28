#pragma once

namespace BenchBuddy {

/**
 * Placeholder boundary for the future LovyanGFX display driver.
 *
 * The ESP32-2432S028R panel configuration will be added here when hardware
 * integration begins.
 */
class LovyanGfxDisplay {
public:
  /**
   * Prepares the graphics driver boundary.
   */
  void begin();

  /**
   * Performs display driver maintenance for the current frame.
   */
  void update();
};

} // namespace BenchBuddy
