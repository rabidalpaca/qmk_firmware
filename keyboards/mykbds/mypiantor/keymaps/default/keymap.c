#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

// Defines names for use in layer keycodes and the keymap5
enum layer_names {
    _QWERTY,
	_SYM,
    _FUN,
	_PSS,
	_SQL
};

#define MY_DQUO LSFT(KC_QUOT)
#define MY_TIL LSFT(KC_GRAVE)
#define MY_UND LSFT(KC_MINUS)
#define MY_LSQLS LT(_SQL,KC_SPC)
#define MY_REDO LCTL(KC_Y)
#define MY_PSTE LCTL(KC_V)
#define MY_COPY LCTL(KC_C)
#define MY_CUT LCTL(KC_X)
#define MY_UNDO LCTL(KC_Z)
#define MY_1 KC_SECRET_1
#define MY_2 KC_SECRET_2
#define MY_3 KC_SECRET_3
#define MY_4 KC_SECRET_4
#define MY_5 KC_SECRET_5
#define MY_6 KC_SECRET_6
#define MY_7 KC_SECRET_7
#define MY_8 KC_SECRET_8
#define MY_9 KC_SECRET_9
#define MY_10 KC_SECRET_10
#define MY_11 KC_SECRET_11
#define MY_12 KC_SECRET_12
#define MY_13 KC_SECRET_13
#define MY_14 KC_SECRET_14
#define MY_15 KC_SECRET_15
#define MY_16 KC_SECRET_16
#define MY_17 KC_SECRET_17
#define MY_18 KC_SECRET_18
#define MY_19 KC_SECRET_19
#define MY_20 KC_SECRET_20
#define MY_21 KC_SECRET_21
#define MY_22 KC_SECRET_22
#define MY_23 KC_SECRET_23
#define MY_24 KC_SECRET_24
#define MY_25 KC_SECRET_25
#define MY_26 KC_SECRET_26
#define MY_27 KC_SECRET_27
#define MY_28 KC_SECRET_28
#define MY_29 KC_SECRET_29
#define MY_30 KC_SECRET_30


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,---------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+-------------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------|------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------|
 */
[_QWERTY] = LAYOUT_split_3x5_3(

            LGUI_T(KC_Q), LALT_T(KC_W), LCTL_T(KC_E), LSFT_T(KC_R),      LT(_PSS,KC_T),    LT(_PSS,KC_Y), LSFT_T(KC_U), RCTL_T(KC_I), RALT_T(KC_O),    LGUI_T(KC_P),
			        KC_A,         KC_S,         KC_D,         KC_F,      LT(_SYM,KC_G),    LT(_SYM,KC_H),         KC_J,         KC_K,         KC_L,         KC_SCLN,
           LT(_SQL,KC_Z),         KC_X,         KC_C,         KC_V,      LT(_FUN,KC_B),    LT(_FUN,KC_N),         KC_M,      KC_COMM,       KC_DOT,LT(_SQL,KC_SLSH),
                                          KC_ESC,KC_TAB,KC_SPC,             KC_ENT,  KC_BSPC, KC_DEL
    ),
[_SYM] = LAYOUT_split_3x5_3(
            KC_1,     KC_2,      KC_3,     KC_4,      KC_5,         KC_6,          KC_7,        KC_8,      KC_9,         KC_0,
            S(KC_1),  S(KC_2),   S(KC_3),  S(KC_4),   S(KC_5),      S(KC_6),       S(KC_7),     S(KC_8),   S(KC_9),      S(KC_0),
            KC_GRAVE,   MY_TIL,   KC_PIPE,  KC_SQBR,   KC_CRBR,        KC_LT,         KC_GT,     KC_SCLN,   KC_COLN,      KC_BSLS,
                                    KC_MYESC, KC_EQL , KC_EQEQ ,              MY_UND ,  KC_QUOT ,  MY_DQUO
),
[_FUN] = LAYOUT_split_3x5_3(
            KC_F1,    KC_F2,        KC_F3,        KC_F4,            KC_F5,         KC_F6,         KC_F7,      KC_F8,    KC_F9,     KC_F10,
            KC_LGUI,  KC_LALT,      KC_LCTL,      KC_LSFT,          KC_MUTE,       XXXXXXX,       KC_LEFT,    KC_DOWN,    KC_UP,   KC_RIGHT,
            MY_UNDO,   MY_CUT,      MY_COPY,      MY_PSTE,          MY_REDO,        KC_INS,       KC_HOME,    KC_PGDN,  KC_PGUP,     KC_END,
                                    KC_MYESC,      _______ ,    _______ ,          _______ ,  _______ ,  _______
),

[_PSS] = LAYOUT_split_3x5_3(
                   MY_17,    MY_23,     MY_5,        MY_18,              MY_20,            MY_25,         MY_21,       MY_9,    MY_15,       MY_16,
				    MY_1,    MY_19,     MY_4,         MY_6,               MY_7,             MY_8,         MY_10,      MY_11,    MY_12,       MY_29,
                   MY_26,    MY_24,     MY_3,        MY_22,               MY_2,            MY_14,         MY_13,      MY_27,    MY_28,       MY_30,
                               XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX
    )
,
[_SQL] = LAYOUT_split_3x5_3(
                  MY_SEL,   MY_WHR,    MY_IN,        MY_LK,              MY_JN,            MY_OB,         MY_AG,    XXXXXXX,  XXXXXXX, C(S(KC_F)),
				   MY_UP,  XXXXXXX,  XXXXXXX,      XXXXXXX,            XXXXXXX,            MY_GB,       XXXXXXX,    XXXXXXX,  XXXXXXX,  C(KC_ENT),
                 MY_DECI,  XXXXXXX,  XXXXXXX,       KC_PAR,             MY_ISN,           MY_LST,       XXXXXXX,    XXXXXXX,  XXXXXXX,    A(KC_E),
                                       MY_EQ, MY_DQ, MY_SQ,                                MY_SQ,  MY_DQ,  MY_EQ
    )
};


layer_state_t layer_state_set_user(layer_state_t state) {
  switch(get_highest_layer(state)) {
  case _SYM:
    // green-ish
    rgblight_sethsv(HSV_RED);
    break;
  case _FUN:
    // Dark Blue
    rgblight_sethsv(HSV_MAGENTA);
    break;
  case _PSS:
    // Dark Blue
    rgblight_sethsv(HSV_ORANGE);
    break;
  case _SQL:
    // Dark Blue
    rgblight_sethsv(HSV_GREEN);
    break;
  default:
    // Default colors
    rgblight_sethsv(HSV_BLUE);
    //rgb_matrix_mode(RGB_MATRIX_BREATHING);
    break;
  }
  return state;
}


__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
        case KC_CRBR:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("{} "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case KC_SQBR:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("[] "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case KC_PAR:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("() "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
        case KC_EQEQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" == "), 12);
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
        case MY_AG:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" MAX() "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
      case MY_AGMN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" MIN() "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
      case MY_AGAV:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" AVG() "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
      case MY_AGCT:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" COUNT(*) as CntOf "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			return false;}
      case MY_LST:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_TAP(X_HOME)"'"SS_TAP(X_END)"',"SS_TAP(X_DOWN)), 12);
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
            send_string_with_delay_P(PSTR(), 12);
			return false;}

    }
	return process_record_secrets(keycode, record);
}
