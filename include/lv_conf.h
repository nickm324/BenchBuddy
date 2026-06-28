#pragma once

#ifndef LV_CONF_H
#define LV_CONF_H

/**
 * Minimal LVGL configuration for BenchBuddy.
 *
 * This prepares LVGL for a future ESP32-2432S028R display integration without
 * registering a display driver, input device, or hardware timer yet.
 */

#define LV_COLOR_DEPTH 16

#define LV_USE_STDLIB_MALLOC LV_STDLIB_BUILTIN
#define LV_USE_STDLIB_STRING LV_STDLIB_BUILTIN
#define LV_USE_STDLIB_SPRINTF LV_STDLIB_BUILTIN

#define LV_MEM_SIZE (64 * 1024U)
#define LV_DEF_REFR_PERIOD 33
#define LV_DPI_DEF 130
#define LV_USE_OS LV_OS_NONE

#define LV_USE_LOG 0
#define LV_USE_ASSERT_NULL 0
#define LV_USE_ASSERT_MALLOC 0
#define LV_USE_ASSERT_STYLE 0
#define LV_USE_ASSERT_MEM_INTEGRITY 0
#define LV_USE_ASSERT_OBJ 0

#endif // LV_CONF_H
