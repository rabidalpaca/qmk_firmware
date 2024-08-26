/* Copyright (C) 2023 jonylee@hfd
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

#include QMK_KEYBOARD_H

enum __layers {
    _QWERTY,
    _AHK1,
    _NUM,
    _FUN,
    _PSS,
};

#include "g/keymap_combo.h"

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// clang-format off!
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [_QWERTY] = LAYOUT( /* Base */
       LT(_NUM,KC_Q),   LT(_FUN,KC_W), LT(_PSS,KC_E),LT(_AHK1,KC_R),          KC_T,              KC_Y,  LT(_AHK1,KC_U),      LT(_PSS,KC_I),    LT(_FUN,KC_O),           LT(_NUM,KC_P),
        LSFT_T(KC_Z),    LCTL_T(KC_X),  LGUI_T(KC_C),  LALT_T(KC_V),          KC_B,              KC_N,    RALT_T(KC_M),    RGUI_T(KC_COMM),   RCTL_T(KC_DOT),         LSFT_T(KC_SLSH),
        TG(_AHK1)),
    [_AHK1] = LAYOUT( /* Base */
        RSFT(KC_Q),    RSFT(KC_W),    RSFT(KC_E),  RSFT(KC_R),    RSFT(KC_T),    RSFT(KC_Y),    RSFT(KC_U),      RSFT(KC_I),       RSFT(KC_O),       KC_UP,
        RSFT(KC_Z),    RSFT(KC_X),    RSFT(KC_C),  RSFT(KC_V),    RSFT(KC_B),    RSFT(KC_N),    RSFT(KC_M),   RSFT(KC_COMM),     RSFT(KC_DOT),     KC_DOWN,
        TG(_AHK1)),
    [_NUM] = LAYOUT( /* Base */
        KC_KP_1,  KC_KP_2,   KC_KP_3,  KC_KP_4,   KC_KP_5,      KC_KP_6,       KC_KP_7,     KC_KP_8,   KC_KP_9,      KC_KP_0,
        S(KC_1),  S(KC_2),   S(KC_3),  S(KC_4),   S(KC_5),      S(KC_6),       S(KC_7),     S(KC_8),   S(KC_9),      S(KC_0),
        TG(_NUM)),
    [_FUN] = LAYOUT( /* Base */
           KC_F1,        KC_F2,      KC_F3,      KC_F4,      KC_F5,         KC_F6,          KC_F7,        KC_F8,      KC_F9,         KC_F10,
           KC_F11,      KC_F12,     KC_F13,     KC_F14,     KC_F15,        KC_F16,         KC_F17,       KC_F18,     KC_F19,         KC_F20,
        TG(_FUN)),
    [_PSS] = LAYOUT( /* Base */
           KC_SECRET_1,        KC_SECRET_2,      KC_SECRET_3,      KC_SECRET_4,      KC_SECRET_5,         KC_SECRET_6,          KC_SECRET_7,        KC_SECRET_8,      KC_SECRET_9,         KC_SECRET_10,
           KC_SECRET_11,      KC_SECRET_12,     KC_SECRET_13,     KC_SECRET_14,     KC_SECRET_15,        KC_SECRET_16,         KC_SECRET_17,       KC_SECRET_18,     KC_SECRET_19,         KC_SECRET_20,
        TG(_FUN)),
};
/*
  _______, _______,
       KC_MYESC,   KC_EQL,
*/
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 20};
const uint8_t RGBLED_KNIGHT_INTERVALS[] PROGMEM = {63, 31, 15};

layer_state_t layer_state_set_user(layer_state_t state) {
  switch(get_highest_layer(state)) {
  case _AHK1:
    // green-ish
    rgblight_sethsv(HSV_RED);
    rgblight_mode(RGBLIGHT_MODE_KNIGHT);
    break;
  case _QWERTY:
    // green-ish
    rgblight_sethsv(HSV_BLUE);
    rgblight_mode(RGBLIGHT_MODE_KNIGHT);
    break;
  case _NUM:
    // green-ish
    rgblight_sethsv(HSV_GREEN);
    rgblight_mode(RGBLIGHT_MODE_KNIGHT);
    break;
  case _PSS:
    // green-ish
    rgblight_sethsv(HSV_ORANGE);
    rgblight_mode(RGBLIGHT_MODE_KNIGHT);
    break;
  case _FUN:
    // green-ish
    rgblight_sethsv(HSV_PURPLE);
    rgblight_mode(RGBLIGHT_MODE_KNIGHT);
    break;
  default:
    // Default colors
    rgblight_sethsv(HSV_BLUE);
    rgblight_mode(RGBLIGHT_MODE_KNIGHT);

    break;
  }
  return state;
}

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

// clang-format off
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_AHK1] =    { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_NUM] =    { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_FUN] =    { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_PSS] =    { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    /*
    [WIN_W] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [WIN_FN] = { ENCODER_CCW_CW(RGB_VAI, RGB_VAD) },
    [MAC_B] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_W] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_FN] = { ENCODER_CCW_CW(RGB_VAI, RGB_VAD) }
    */
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //return true;
switch (keycode) {
        case KC_CRBR:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("{}"SS_TAP(X_LEFT)), 12);
			return false;}
        case KC_SQBR:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("[]"SS_TAP(X_LEFT)), 12);
			return false;}
        }

	return process_record_secrets(keycode, record);
}
