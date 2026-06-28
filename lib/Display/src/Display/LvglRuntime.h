#pragma once

namespace BenchBuddy {

/**
 * Placeholder boundary for the future LVGL runtime integration.
 *
 * LVGL initialization, display flushing, input device registration, and tick
 * handling will be added after the display and touch hardware drivers are
 * selected.
 */
class LvglRuntime {
public:
  /**
   * Prepares the UI runtime boundary.
   */
  void begin();

  /**
   * Performs UI runtime maintenance for the current frame.
   */
  void update();
};

} // namespace BenchBuddy
