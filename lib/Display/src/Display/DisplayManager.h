#pragma once

#include <BSP/Display.h>

namespace BenchBuddy {

/**
 * Coordinates display lifecycle and rendering boundaries.
 *
 * This placeholder intentionally avoids hardware-specific display code.
 */
class DisplayManager {
public:
  /**
   * Initializes display-facing services.
   */
  void begin();

  /**
   * Advances display work for the current application frame.
   */
  void update();

private:
  BSP::Display display;
};

} // namespace BenchBuddy
