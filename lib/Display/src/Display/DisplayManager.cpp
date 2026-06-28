#include "DisplayManager.h"

namespace BenchBuddy {

void DisplayManager::begin() {
  display.begin();
}

void DisplayManager::update() {
  display.update();
}

} // namespace BenchBuddy
