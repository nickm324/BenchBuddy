#pragma once

namespace BenchBuddy {

/**
 * Owns shared visual theme state and presentation tokens.
 *
 * This placeholder does not define concrete colors, fonts, or assets yet.
 */
class ThemeManager {
public:
  /**
   * Initializes theme state.
   */
  void begin();

  /**
   * Advances theme-related work for the current application frame.
   */
  void update();
};

} // namespace BenchBuddy
