#include QMK_KEYBOARD_H


enum layer_names {
    _QWERTY = 0,
	_PSS,
    _SQL
};

// #include "g/keymap_combo.h"

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
    [_QWERTY] = LAYOUT(

         KC_ESC,    LT(0,KC_1),   LT(0,KC_2),   LT(0,KC_3),   LT(0,KC_4),   LT(0,KC_5),   LT(0,KC_6),  LT(0,KC_7),   LT(0,KC_8),   LT(0,KC_9),      LT(0,KC_0),LT(0,KC_MINS), LT(0,KC_EQL),      KC_BSPC,  KC_MUTE,
       MO(_SQL),  LGUI_T(KC_Q), LALT_T(KC_W), LCTL_T(KC_E), LSFT_T(KC_R),         KC_T,         KC_Y,RSFT_T(KC_U), RCTL_T(KC_I), RALT_T(KC_O),    RGUI_T(KC_P),LT(0,KC_LBRC),LT(0,KC_SLSH),LT(0,KC_BSLS),
        KC_SELW,          KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,        KC_J,         KC_K,         KC_L,   LT(0,KC_SCLN),LT(0,KC_QUOT),       KC_ENT,
        KC_SELL,          KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,        KC_M,LT(0,KC_COMM), LT(0,KC_DOT),        MO(_SQL),        KC_UP,   LT(0,KC_Z),
        C(KC_A),    LT(0,KC_C),      C(KC_V),                                   KC_SPC,                                MO(_SQL),     MO(_PSS),         KC_LEFT,      KC_DOWN,     KC_RIGHT
   ),
	[_PSS] = LAYOUT(

        _______,       _______,      _______,      _______,      _______,      _______,      _______,      _______,     _______,      _______,         _______,   _______,    _______, _______,  _______,
        _______,         MY_17,        MY_23,         MY_5,        MY_18,        MY_20,        MY_25,        MY_21,        MY_9,        MY_15,           MY_16,   _______,    _______, _______,
        _______,          MY_1,        MY_19,         MY_4,         MY_6,         MY_7,         MY_8,        MY_10,       MY_11,        MY_12,           MY_29,   _______,    _______,
        _______,         MY_26,        MY_24,         MY_3,        MY_22,         MY_2,        MY_14,        MY_13,       MY_27,        MY_28,           MY_30,   _______,    _______,
        _______,       _______,      _______,                                  _______,                                 _______,      _______,         _______,   _______,    _______
   ),
    [_SQL] = LAYOUT(

        _______,       _______,      _______,      _______,      _______,      _______,      _______,      _______,     _______,      _______,         _______,   _______,    _______, _______,  _______,
        _______, LT(0,MY_DECL),  LT(0,MY_SEL), LT(0,MY_WHR),       MY_IN,  LT(0,MY_LK), LT(0,MY_JN1),        MY_OB,LT(0,MY_AG1),      _______,         _______,   _______,    _______, _______,
    LT(0,MY_WQ),       _______,        MY_UP, LT(0,MY_WHRC),LT(0,MY_INC),      _______, LT(0,MY_JN2),  LT(0,MY_GB),LT(0,MY_AG2),      _______,         _______,   _______,    _______,
        _______,       _______,      _______,      _______, LT(0,MY_ISN),      _______,      _______,      _______,     _______,      _______,         _______,   _______,    _______,
        _______,       _______,      _______,                                  _______,                                 _______,      _______,         _______,   _______,    _______
   )
};


bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
		    rgb_matrix_set_color_all(96,0,0);
			rgb_matrix_set_color(14, 0, 0, 255);//blue
			rgb_matrix_set_color(15, 255, 0, 255);
			rgb_matrix_set_color(28, 0, 255, 0);
			rgb_matrix_set_color(41, 0, 255, 0);
            rgb_matrix_set_color(52, 0, 255, 255);
			rgb_matrix_set_color(54, 0, 255, 0);
			rgb_matrix_set_color(55, 0, 255, 0);
			rgb_matrix_set_color(56, 0, 255, 0);//green
            rgb_matrix_set_color(58, 0, 0, 255);
            rgb_matrix_set_color(59, 0, 0, 255);
            rgb_matrix_set_color(60, 0, 255, 255);
            rgb_matrix_set_color(61, 0, 255, 255);
            rgb_matrix_set_color(62, 0, 255, 255);
            break;
        case _PSS:
		    rgb_matrix_set_color_all(96,0,0);
            rgb_matrix_set_color(24, 255, 0, 255);//p
            break;
        case _SQL:
		    rgb_matrix_set_color_all(96,0,0);
            rgb_matrix_set_color(30, 255, 0, 255);//s
            break;
        default:
            break;

    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state){
    return state;
}

bool encoder_update_kb(uint8_t index, bool clockwise) {
    return encoder_update_user(index, clockwise);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
		if (IS_LAYER_ON(_QWERTY))
		{
  		tap_code(KC_WH_D);
		}
		else
		{
		tap_code(KC_VOLD);
		}
    } else {
		if (IS_LAYER_ON(_QWERTY))
		{
 		tap_code(KC_WH_U);
		}
		else
		{
        tap_code(KC_VOLU);
		}
    }
    return true;
}

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_Q):
            return TAPPING_TERM + 100;
return false;
        case RGUI_T(KC_P):
            return TAPPING_TERM + 100;
return false;
        case LALT_T(KC_W):
            return TAPPING_TERM + 0;
            break;
        case RALT_T(KC_O):
            return TAPPING_TERM + 0;
        break;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

        switch (keycode) {
          case LT(0,KC_1):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_1); // Intercept tap function to send 1
            } else if (record->event.pressed) {
                tap_code16(S(KC_1)); // Intercept hold function to send !
            }
			return false;
         case LT(0,KC_2):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_2); // Intercept tap function to send 2
            } else if (record->event.pressed) {
                tap_code16(S(KC_2)); // Intercept hold function to send @
            }
			return false;
        case LT(0,KC_3):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_3); // Intercept tap function to send 3
            } else if (record->event.pressed) {
                tap_code16(S(KC_3)); // Intercept hold function to send #
            }
			return false;
         case LT(0,KC_4):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_4); // Intercept tap function to send 4
            } else if (record->event.pressed) {
                tap_code16(S(KC_4)); // Intercept hold function to $
            }
			return false;
         case LT(0,KC_5):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_5); // Intercept tap function to send 5
            } else if (record->event.pressed) {
                tap_code16(S(KC_5)); // Intercept hold function to send %
            }
			return false;
         case LT(0,KC_6):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_6); // Intercept tap function to send 6
            } else if (record->event.pressed) {
                tap_code16(S(KC_6)); // Intercept hold function to send ^
            }
			return false;
         case LT(0,KC_7):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_7); // Intercept tap function to send 7
            } else if (record->event.pressed) {
                tap_code16(S(KC_7)); // Intercept hold function to send &
            }
			return false;
         case LT(0,KC_8):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_8); // Intercept tap function to send 8
            } else if (record->event.pressed) {
                tap_code16(S(KC_8)); // Intercept hold function to send *
            }
			return false;
         case LT(0,KC_9):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_9); // Intercept tap function to send 9
            } else if (record->event.pressed) {
                tap_code16(S(KC_9)); // Intercept hold function to send (
                tap_code16(S(KC_0)); // Intercept hold function to send )
                tap_code(KC_LEFT); //to move inside
            }
			return false;
         case LT(0,KC_0):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_0); // Intercept tap function to send
            } else if (record->event.pressed) {
                tap_code16(KC_DEL); // Intercept hold function to send Delete
            }
			return false;
         case LT(0,KC_SCLN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_SCLN); // Intercept tap function to send ;
            } else if (record->event.pressed) {
                tap_code16(KC_COLN); // Intercept hold function to send :
            }
			return false;
         case LT(0,KC_QUOT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_QUOT); // Intercept tap function to send '
                tap_code16(KC_QUOT); // Intercept tap function to send '
                tap_code(KC_LEFT); //to move inside
            } else if (record->event.pressed) {
                tap_code16(S(KC_QUOT)); // Intercept hold function to send "
                tap_code16(S(KC_QUOT)); // Intercept hold function to send "
                tap_code(KC_LEFT); //to move inside
            }
			return false;
         case LT(0,KC_C):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C)); // Intercept tap function to send Copy
            } else if (record->event.pressed) {
                tap_code16(C(KC_X)); // Intercept hold function to send Cut
            }
			return false;
         case LT(0,KC_COMM):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_COMM); // Intercept tap function to send ,
            } else if (record->event.pressed) {
                tap_code16(S(KC_COMM)); // Intercept hold function to send <
            }
			return false;
         case LT(0,KC_DOT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DOT); // Intercept tap function to send .
            } else if (record->event.pressed) {
                tap_code16(S(KC_DOT)); // Intercept hold function to send >
            }
			return false;
         case LT(0,KC_BSLS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_BSLS); // Intercept tap function to send
            } else if (record->event.pressed) {
                tap_code16(KC_SLSH); // Intercept hold function to send /
            }
			return false;
         case LT(0,KC_LBRC):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LBRC); // Intercept tap function to send [
                tap_code16(KC_RBRC); // Intercept tap function to send ]
                tap_code(KC_LEFT); //to move inside
            } else if (record->event.pressed) {
                tap_code16(S(KC_LBRC)); // Intercept hold function to send {
                tap_code16(S(KC_RBRC)); // Intercept hold function to send }
                tap_code(KC_LEFT); //to move inside
            }
			return false;
         case LT(0,KC_MINS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_MINS); // Intercept tap function to send -
                tap_code16(KC_SPC);
            } else if (record->event.pressed) {
                tap_code16(S(KC_MINS)); // Intercept hold function to send _
            }
			return false;
         case LT(0,KC_EQL):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_EQL); // Intercept tap function to send =
                tap_code16(KC_SPC);
            } else if (record->event.pressed) {
                tap_code16(S(KC_EQL)); // Intercept hold function to send +
                tap_code16(KC_SPC);
            }
			return false;
        case LT(0,KC_Z):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_GRAVE); // Intercept tap function to send `
            } else if (record->event.pressed) {
                tap_code16(S(KC_GRAVE)); // Intercept hold function to send ~
            }
			return false;
        case LT(0,KC_SLSH):
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_SLSH)); // Intercept tap function to send `
            } else if (record->event.pressed) {
                tap_code16(S(KC_BSLS)); // Intercept hold function to send ~
            }
			return false;
         case LT(0,MY_SEL):
            if (record->tap.count && record->event.pressed) {
			send_string_with_delay_P(PSTR("SELECT\n"SS_TAP(X_TAB)"*\n"SS_TAP(X_TAB)"FROM\n"SS_TAP(X_TAB)), 12);
            } else if (record->event.pressed) {
			send_string_with_delay_P(PSTR("SELECT\n"SS_TAP(X_TAB)"*\n"SS_TAP(X_TAB)"FROM  \n"SS_TAP(X_TAB)"WHERE  ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            }
			return false;
         case LT(0,MY_DECL):
            if (record->tap.count && record->event.pressed) {
			send_string_with_delay_P(PSTR("DECLARE @int INT = "), 12);
            } else if (record->event.pressed) {
			send_string_with_delay_P(PSTR("DECLARE @str VARCHAR(50) = ''"SS_TAP(X_LEFT)), 12);
            }
			return false;
         case LT(0,MY_WHR):
            if (record->tap.count && record->event.pressed) {
			send_string_with_delay_P(PSTR(" WHERE  = "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            } else if (record->event.pressed) {
            send_string_with_delay_P(PSTR(" WHERE  BETWEEN  AND "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            }
			return false;
         case LT(0,MY_WHRC):
            if (record->tap.count && record->event.pressed) {
			send_string_with_delay_P(PSTR(" WHERE  = '' "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            } else if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" WHERE  = \"\" "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            }
			return false;
         case LT(0,MY_INC):
            if (record->tap.count && record->event.pressed) {
			send_string_with_delay_P(PSTR(" IN ('','') "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            } else if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" IN (\"\",\"\") " SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            }
			return false;
         case LT(0,MY_LK):
            if (record->tap.count && record->event.pressed) {
			send_string_with_delay_P(PSTR(" LIKE '%%' "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            } else if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" LIKE \"%%\" "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            }
			return false;
         case LT(0,MY_JN1):
            if (record->tap.count && record->event.pressed) {
			send_string_with_delay_P(PSTR(" INNER JOIN  ON  = "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            } else if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" LEFT OUTER JOIN  ON  = "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            }
			return false;
         case LT(0,MY_JN2):
            if (record->tap.count && record->event.pressed) {
			send_string_with_delay_P(PSTR(" FULL OUTER JOIN  ON  = "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            } else if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" CROSS JOIN "), 12);
            }
			return false;
         case LT(0,MY_GB):
            if (record->tap.count && record->event.pressed) {
            send_string_with_delay_P(PSTR(" GROUP BY "), 12);
            } else if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" HAVING "), 12);
            }
			return false;
         case LT(0,MY_AG1):
            if (record->tap.count && record->event.pressed) {
			send_string_with_delay_P(PSTR(" COUNT(*) as CntOf "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            } else if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" AVG() as AvgOf "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            }
			return false;
         case LT(0,MY_AG2):
            if (record->tap.count && record->event.pressed) {
			send_string_with_delay_P(PSTR(" MAX() as MaxOf "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            } else if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" MIN() as MinOf "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            }
			return false;
         case LT(0,MY_ISN):
            if (record->tap.count && record->event.pressed) {
			send_string_with_delay_P(PSTR(" IS NULL "), 12);
            } else if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" IS NOT NULL "), 12);
            }
			return false;
         case LT(0,MY_WQ):
            if (record->tap.count && record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_TAP(X_HOME)"'"SS_TAP(X_END)"',"SS_TAP(X_DOWN)), 12); //wrap a line in single quotes
            } else if (record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_TAP(X_HOME)"\""SS_TAP(X_END)"\","SS_TAP(X_DOWN)), 12); //wrap a line in double quotes
            }
			return false;
        case MY_UP:
			if (record->event.pressed) {
            send_string_with_delay_P(PSTR("UPDATE A SET  =  FROM  as A WHERE A.  ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            }
			return false;
        case MY_IN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" IN (,) "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            }
			return false;
        case MY_ISN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" IS NULL "), 12);
            }
			return false;
        case KC_SELW:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(""SS_DOWN(X_LCTL)SS_TAP(X_RIGHT)SS_DOWN(X_LSFT)SS_TAP(X_LEFT)SS_UP(X_LSFT)SS_UP(X_LCTL)), 12);
            }
			return false;
        case KC_SELL:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(""SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)), 12);
            }
			return false;
        case MY_OB:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" ORDER BY "), 12);
            }
			return false;
      case MY_WQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_TAP(X_HOME)"'"SS_TAP(X_END)"',"SS_TAP(X_DOWN)SS_TAP(X_HOME)), 12);
            }
			return false;
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
            }
			return false;
    //return true;
    }
	return process_record_secrets(keycode, record);
}
