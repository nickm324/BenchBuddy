#pragma once

namespace BenchBuddy {

/**
 * Coordinates touch input lifecycle and input event boundaries.
 *
 * This placeholder intentionally avoids hardware-specific touch code.
 */
class TouchManager {
public:
  /**
   * Initializes touch-facing services.
   */
  void begin();

  /**
   * Advances touch input processing for the current application frame.
   */
  void update();
};

} // namespace BenchBuddy
