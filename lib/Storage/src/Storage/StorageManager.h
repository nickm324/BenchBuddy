#pragma once

namespace BenchBuddy {

/**
 * Owns persistent storage lifecycle and data access boundaries.
 *
 * This placeholder intentionally avoids platform-specific persistence code.
 */
class StorageManager {
public:
  /**
   * Initializes storage-facing services.
   */
  void begin();

  /**
   * Advances storage maintenance for the current application frame.
   */
  void update();
};

} // namespace BenchBuddy
