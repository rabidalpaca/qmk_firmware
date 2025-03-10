// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

//#include "config_common.h"

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define TRI_LAYER_LOWER_LAYER 1
#define TRI_LAYER_UPPER_LAYER 2
#define TRI_LAYER_ADJUST_LAYER 4

//#define NOP_FUDGE 0.4
#define RGBLIGHT_LIMIT_VAL 196
#define WS2812_DI_PIN GP17
#define RGBLIGHT_LED_COUNT 1
#define SPLIT_LAYER_STATE_ENABLE
#define RGBLIGHT_LAYERS
#define RGBLIGHT_SPLIT
#define RGBLIGHT_LAYER_BLINK
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
//#define TAPPING_TOGGLE 2

//#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 750

#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define COMBO_TERM 65
#define COMBO_VARIABLE_LEN
//#define COMBO_COUNT 0
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 6
#define MOUSEKEY_TIME_TO_MAX 64
#define MEDIA_KEY_DELAY 2
#define ONESHOT_TAP_TOGGLE 2
#define COMBO_MUST_PRESS_IN_ORDER_PER_COMBO
#define MASTER_LEFT
