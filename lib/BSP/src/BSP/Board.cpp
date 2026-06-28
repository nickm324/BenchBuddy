#include "Board.h"

namespace BenchBuddy {
namespace BSP {

void Board::begin() {
  display.begin();
  touch.begin();
  backlight.begin();
  statusLed.begin();
}

void Board::update() {
  display.update();
  touch.update();
  backlight.update();
  statusLed.update();
}

} // namespace BSP
} // namespace BenchBuddy
