#pragma once

#include <BSP/Backlight.h>
#include <BSP/Display.h>
#include <BSP/StatusLed.h>
#include <BSP/Touch.h>

namespace BenchBuddy {
namespace BSP {

/**
 * Represents the ESP32-2432S028R board support boundary.
 *
 * Hardware initialization will be added after pin assignments and board
 * variants are verified.
 */
class Board {
public:
  /**
   * Prepares board-level services.
   */
  void begin();

  /**
   * Runs board-level maintenance for the current frame.
   */
  void update();

private:
  Display display;
  Touch touch;
  Backlight backlight;
  StatusLed statusLed;
};

} // namespace BSP
} // namespace BenchBuddy
