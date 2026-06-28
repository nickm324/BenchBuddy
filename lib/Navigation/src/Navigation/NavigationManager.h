#pragma once

namespace BenchBuddy {

/**
 * Coordinates screen flow and active feature routing.
 *
 * This placeholder contains no application-specific navigation logic yet.
 */
class NavigationManager {
public:
  /**
   * Initializes navigation state.
   */
  void begin();

  /**
   * Advances navigation state for the current application frame.
   */
  void update();
};

} // namespace BenchBuddy
