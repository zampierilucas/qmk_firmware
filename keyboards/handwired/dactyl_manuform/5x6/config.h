/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #include "config_common.h"

#define RGBLIGHT_SLEEP

#define OLEDDISPLAY_TIMEOUT 10
#define OLED_BRIGHTNESS 122

#define RGBLIGHT_TIMEOUT 15  // in Minutes

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 6
#define FORCE_NKRO

// Pins Wiring
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { B6, B2, B3, B1, F7, F6 }

#define DIODE_DIRECTION COL2ROW
#define USE_I2C
#define SPLIT_USB_DETECT
// #define USB_MAX_POWER_CONSUMPTION 500

#define WS2812_DI_PIN D3
#define RGB_MATRIX_LED_COUNT 64
#define RGB_MATRIX_SPLIT { 32, 32 }
#define RGB_MATRIX_CENTER { 112, 30 }

#define USB_POLLING_INTERVAL_MS 1
