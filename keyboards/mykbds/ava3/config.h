/* Copyright 2020 zvecr <git@zvecr.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 10 // Rows are doubled-up
#define MATRIX_COLS 7

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
 /*C14,A8,C13
#define MATRIX_ROW_PINS { B1, A7, A5, A3, A1 }
#define MATRIX_COL_PINS { B8, C14, A8, C13, B9, B3, B5}
*/
/*works
#define MATRIX_ROW_PINS { B12, B13, B14, B15, A15 }
#define MATRIX_COL_PINS { B3, B4, B5, B6, B7, B8, B9}
*/
/*works
#define MATRIX_ROW_PINS { B1, A7, A5, A3, A1 }
#define MATRIX_COL_PINS { B3, B4, B5, B6, B7, B8, B9}
*/
#define MATRIX_ROW_PINS { A1,  A3, A5,  A7, B1 }
#define MATRIX_COL_PINS { B5,  B3, A2, C13, A0, C14, B9 }		
/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define MATRIX_IO_DELAY 5

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
//#define SPLIT_HAND_PIN B3
//#define USE_SERIAL
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SOFT_SERIAL_PIN B6 //don't know why 
//#define SERIAL_USART_TX_PIN B6     // USART TX pin
#define SERIAL_USART_RX_PIN B7     // USART RX pin


//#define RGB_DI_PIN B4
//#define RGBLED_NUM 24
//#define RGBLED_SPLIT { 12, 12 }
//#define RGBLIGHT_ANIMATIONS

//#define WS2812_PWM_DRIVER PWMD3
//#define WS2812_PWM_CHANNEL 1
//#define WS2812_DMA_STREAM STM32_DMA1_STREAM3
//#define WS2812_DMA_CHANNEL 3

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#define ENCODERS_PAD_A { B14 }
#define ENCODERS_PAD_B { B15 }
#define ENCODER_RESOLUTION 2
#define TAP_CODE_DELAY 10
#define MEDIA_KEY_DELAY 2

#define USB_POLLING_INTERVAL_MS 1

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is userful for the Windows task manager shortcut (ctrl+shift+esc).
 */
// #define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0
//#define BOOTMAGIC_LITE_ROW_RIGHT 4
//#define BOOTMAGIC_LITE_COLUMN_RIGHT 0

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250
#define COMBO_COUNT 10
