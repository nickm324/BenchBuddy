# BenchBuddy Hardware

BenchBuddy targets the ESP32-2432S028R, commonly known as the Cheap Yellow Display.

This document records known hardware expectations for the project. Display pin assignments below are the standard ESP32-2432S028R configuration used for the initial LCD bring-up.

## Target Board

- Board: ESP32-2432S028R
- Common name: Cheap Yellow Display
- MCU module: ESP32-WROOM-32
- Display: ILI9341 TFT display
- Touch controller: XPT2046 resistive touch
- Storage: microSD card slot
- Indicator: RGB LED

## Hardware Boundaries

- `lib/BSP`: board-specific hardware ownership and verified pin mappings.
- `lib/Display`: graphics and UI integration boundaries for LovyanGFX and LVGL.
- `lib/Touch`: normalized input events for the application.
- `lib/Storage`: persistent data access that may later use onboard flash or microSD.

## Verified Display Pin Assignments

The onboard ILI9341 LCD is connected on the ESP32 HSPI bus.

| Signal | GPIO |
| --- | ---: |
| LCD MISO | 12 |
| LCD MOSI | 13 |
| LCD SCLK | 14 |
| LCD CS | 15 |
| LCD DC | 2 |
| LCD RESET | Not connected |
| Backlight | 21 |

The display is configured as a 240 x 320 ILI9341 panel and rotated to landscape for the 320 x 240 BenchBuddy splash screen.

Source reference: [ESP32 Cheap Yellow Display pin documentation](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/blob/main/PINS.md).

## TODO: Remaining Pin Verification

The ESP32-2432S028R is sold in multiple revisions and pin mappings found online can vary.

Before implementing additional hardware initialization, verify and document:

- XPT2046 SPI pins
- XPT2046 chip select and interrupt pins
- microSD SPI pins and chip select
- Backlight active level across the specific board revision
- RGB LED pins and active levels
- Any board revision markings that affect wiring

Do not add touch, microSD, or RGB LED driver initialization until this section is completed.
