// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SERIAL_USART_TX_PIN GP12
#define USB_VBUS_PIN GP13

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7

/* RP2040- and hardware-specific config */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
//#define TAPPING_TOGGLE 2

//#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 750
#define SPLIT_LAYER_STATE_ENABLE
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define COMBO_TERM 65
#define COMBO_VARIABLE_LEN
//#define COMBO_COUNT 0
#define MOUSEKEY_DELAY 50
#define MOUSEKEY_INTERVAL 16
#define MEDIA_KEY_DELAY 2
//#define ONESHOT_TAP_TOGGLE 2
#define COMBO_MUST_PRESS_IN_ORDER_PER_COMBO
