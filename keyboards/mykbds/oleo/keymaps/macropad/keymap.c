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
    _SQL,
    _PSS,
};

// 1st layer on the cycle
#define MIN_CYCLE_SECRET 1
// Last layer on the cycle
int CYCLE_SECRET = 1;
#define MAX_CYCLE_SECRET 30

#include "g/keymap_combo.h"

// clang-format off!
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [_SQL] = LAYOUT( /* Base */
             MY_DECI,          MY_SEL,        MY_WHR,         MY_IN,         MY_LK,             MY_JN,           MY_OB,              MY_GB,            MY_WQ,           MY_SQ,
              MY_WSQ,         MY_AGCT,        MY_ISN,  LALT_T(KC_V),          KC_B,            MY_SYS,           MY_UP,             MY_PAR,            KC_EQ,           MY_DQ,
        MO(_PSS)),
    [_PSS] = LAYOUT( /* Secrets */
           KC_SECRET_1,        KC_SECRET_2,      KC_SECRET_3,      KC_SECRET_4,      KC_SECRET_5,         KC_SECRET_6,          KC_SECRET_7,        KC_SECRET_8,      KC_SECRET_9,         KC_SECRET_10,
           KC_SECRET_11,      KC_SECRET_12,     KC_SECRET_13,     KC_SECRET_14,     KC_SECRET_15,        KC_SECRET_16,         KC_SECRET_17,       KC_SECRET_18,     KC_SECRET_19,         KC_SECRET_20,
        XXXXXXX),
};
/*
  _______, _______,
       KC_MYESC,   KC_EQL,
*/
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 20};
const uint8_t RGBLED_KNIGHT_INTERVALS[] PROGMEM = {63, 31, 15};

layer_state_t layer_state_set_user(layer_state_t state) {
  switch(get_highest_layer(state)) {
  case _SQL:
    // green-ish
    rgblight_sethsv(HSV_BLUE);
    rgblight_mode(RGBLIGHT_MODE_KNIGHT);
    break;
  case _PSS:
    // green-ish
    rgblight_sethsv(HSV_RED);
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
    [_SQL] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_PSS] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    //[_PSS] =    { ENCODER_CCW_CW(update_dial(-1), update_dial(1)) },
    /*
    [WIN_W] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [WIN_FN] = { ENCODER_CCW_CW(RGB_VAI, RGB_VAD) },
    [MAC_B] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_W] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_FN] = { ENCODER_CCW_CW(RGB_VAI, RGB_VAD) }
    */
};
#endif

void update_dial(int direction) {
    if ((CYCLE_SECRET + direction <= MAX_CYCLE_SECRET) && (CYCLE_SECRET + direction >= MIN_CYCLE_SECRET)) {              // check correct direction
            CYCLE_SECRET = CYCLE_SECRET + direction;
    }
    else {                                           // wrong direction so fail, except...
        if (CYCLE_SECRET + direction > MAX_CYCLE_SECRET) {  // a few extra ticks just after changing direction is acceptable
            CYCLE_SECRET = 1;
        }
        else
        {
          CYCLE_SECRET = MIN_CYCLE_SECRET;
        }
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case KC_SQBR:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("[] "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case KC_PAR:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("() "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_SEL:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("SELECT\n"SS_TAP(X_TAB)"*\n"SS_TAP(X_TAB)"FROM\n"SS_TAP(X_TAB)), 12);
			return false;}
        case MY_SELW:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("SELECT\n"SS_TAP(X_TAB)"*\n"SS_TAP(X_TAB)"FROM  \n"SS_TAP(X_TAB)"WHERE  ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_SQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" '' "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_DQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" \"\" "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_WHR:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" WHERE  = "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_WHRSQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" WHERE  = '' "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_WHRDQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" WHERE  = \"\" "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_WHRB:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" WHERE  BETWEEN  AND "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_UP:
			if (record->event.pressed) {
            send_string_with_delay_P(PSTR("UPDATE A SET  =  FROM  as A WHERE A.  ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_IN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" IN (,) "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_INSQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" IN ('','') "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
		    return false;}
        case MY_INDQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" IN (\"\",\"\") " SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
		    return false;}
        case MY_LK:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" LIKE '%%' "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_LKDQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" LIKE \"%%\" "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_EQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" = "), 12);
			return false;}
        case MY_ISN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" IS NULL "), 12);
			return false;}
        case MY_ISNN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" IS NOT NULL "), 12);
			return false;}
        case MY_JN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" INNER JOIN  ON  = "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_LJN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" LEFT OUTER JOIN  ON  = "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_FJN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" FULL OUTER JOIN  ON  = "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_CJN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" CROSS JOIN "), 12);
			return false;}
        case MY_DECI:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("DECLARE @int INT = "), 12);
			return false;}
        case MY_DECV:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("DECLARE @str VARCHAR(50) = ''"SS_TAP(X_LEFT)), 12);
			return false;}
        case MY_OB:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" ORDER BY "), 12);
			return false;}
        case MY_GB:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" GROUP BY "), 12);
			return false;}
        case MY_HV:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" HAVING "), 12);
			return false;}
        case MY_AGCT:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" COUNT(*) as CntOf "), 12);
			return false;}
      case MY_AGMN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" MIN() "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
      case MY_AGAV:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" AVG() "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
      case MY_AGMX:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" MAX() "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
      case MY_WSQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_TAP(X_HOME)"'"SS_TAP(X_END)"',"SS_TAP(X_DOWN)SS_TAP(X_HOME)), 12);
			return false;}
      case MY_WDQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_TAP(X_HOME)"\""SS_TAP(X_END)"\","SS_TAP(X_DOWN)SS_TAP(X_HOME)), 12);
			return false;}
      case MY_SYS:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("Declare @tablename varchar(100) = ''\n"), 12);
            send_string_with_delay_P(PSTR("Declare @columnname varchar(100) = ''\n"), 12);
            send_string_with_delay_P(PSTR("SELECT\n"), 12);
            send_string_with_delay_P(PSTR("TABLE_SCHEMA\n"), 12);
            send_string_with_delay_P(PSTR(", TABLE_NAME\n"), 12);
            send_string_with_delay_P(PSTR(", COLUMN_NAME\n"), 12);
            send_string_with_delay_P(PSTR(", ORDINAL_POSITION\n"), 12);
            send_string_with_delay_P(PSTR(", column_Default\n"), 12);
            send_string_with_delay_P(PSTR(", IS_NULLABLE\n"), 12);
            send_string_with_delay_P(PSTR(", DATA_TYPE\n"), 12);
            send_string_with_delay_P(PSTR(", CHARACTER_MAXIMUM_LENGTH\n"), 12);
            send_string_with_delay_P(PSTR(", numeric_Scale\n"), 12);
            send_string_with_delay_P(PSTR(", NUMERIC_PRECISION\n"), 12);
            send_string_with_delay_P(PSTR(", DATETIME_PRECISION\n"), 12);
            send_string_with_delay_P(PSTR("FROM\n"), 12);
            send_string_with_delay_P(PSTR("INFORMATION_SCHEMA.COLUMNS\n"), 12);
            send_string_with_delay_P(PSTR("WHERE\n"), 12);
            send_string_with_delay_P(PSTR("TABLE_NAME LIKE '%' + @tablename + '%'\n"), 12);
            send_string_with_delay_P(PSTR("AND\n"), 12);
            send_string_with_delay_P(PSTR("COLUMN_NAME LIKE '%' + @columnname + '%'\n"), 12);
            send_string_with_delay_P(PSTR(""), 12);
			return false;}
    }
	return process_record_secrets(keycode, record);
}
