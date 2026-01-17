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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xCB10
#define PRODUCT_ID      0x1169
#define DEVICE_VER      0x0100
#define MANUFACTURER    Keebio
#define PRODUCT         BFO-9000

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 9

// wiring of each half
#define MATRIX_ROW_PINS { GP0, GP1, GP4, GP5, GP6, GP7 }
#define MATRIX_COL_PINS { GP9, GP10, GP19, GP20, GP18, GP26, GP27, GP28, GP29 }

#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN GP3
#define SERIAL_PIO_USE_PIO1

#define SPLIT_MAX_CONNECTION_ERRORS 0
#define SERIAL_USART_DRIVER SIOD0 // USART driver of TX and RX pin. default: SD1
#define SERIAL_USART_TIMEOUT 20    // USART driver timeout. default 20
/*#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1*/

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

/* ws2812 RGB LED */
#define RGB_DI_PIN GP8
#define RGBLED_NUM 20    // Number of LEDs
#define RGBLED_SPLIT { 10, 10 }
#define WS2812_PIO_USE_PIO1 
#define RGBLIGHT_SPLIT
#define RGBLIGHT_ANIMATIONS

#define COMBO_COUNT 6
#define TAPPING_TERM 200
