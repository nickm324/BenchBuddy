#include "Application.h"

namespace BenchBuddy {

void Application::begin() {
  storageManager.begin();
  themeManager.begin();
  displayManager.begin();
  touchManager.begin();
  navigationManager.begin();
}

void Application::update() {
  storageManager.update();
  themeManager.update();
  touchManager.update();
  navigationManager.update();
  displayManager.update();
}

} // namespace BenchBuddy
