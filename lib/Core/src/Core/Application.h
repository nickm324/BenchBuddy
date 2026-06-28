#pragma once

#include <Display/DisplayManager.h>
#include <Navigation/NavigationManager.h>
#include <Storage/StorageManager.h>
#include <Theme/ThemeManager.h>
#include <Touch/TouchManager.h>

namespace BenchBuddy {

/**
 * Owns the top-level BenchBuddy firmware lifecycle.
 *
 * Application composes the shared managers and provides the two lifecycle
 * hooks called by the Arduino entry point.
 */
class Application {
public:
  /**
   * Initializes application-level services and managers.
   */
  void begin();

  /**
   * Advances one application frame.
   */
  void update();

private:
  StorageManager storageManager;
  ThemeManager themeManager;
  DisplayManager displayManager;
  TouchManager touchManager;
  NavigationManager navigationManager;
};

} // namespace BenchBuddy
