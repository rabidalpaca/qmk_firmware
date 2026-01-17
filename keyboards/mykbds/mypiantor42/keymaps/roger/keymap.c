#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
//#include "features/achordion.h"

// Defines names for use in layer keycodes and the keymap5
enum layer_names {
    _QWERTY,
	_SYM,
    _FUN,
	_PSS,
	_SQL
};


// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_BLUE}       // Light 4 LEDs, starting with LED 6
);
const rgblight_segment_t PROGMEM my_sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_RED}
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_sql_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PURPLE}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_fun_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_MAGENTA}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_pss_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_ORANGE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_qwerty_layer,
    my_sym_layer,
    my_sql_layer,
    my_fun_layer,
    my_pss_layer
);

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

static uint16_t key_timer; // timer to track the last keyboard activity
//static void refresh_rgb(void); // refreshes the activity timer and RGB, invoke whenever activity happens
//static void check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
//bool is_rgb_timeout = false; // store if RGB has timed out or not in a boolean

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,---------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |;;;;;///....,,,..//\\\//..///\.;:;:i
 * |------+------+------+------+------+-------------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------|------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |&
 * |------+------+------+------+------+------+------+------+------+------|
 */
/*
*/
[_QWERTY] = LAYOUT_split_3x6_3(
LT(0,KC_C),         LGUI_T(KC_Q), LALT_T(KC_W), LCTL_T(KC_E), LSFT_T(KC_R),      LT(_PSS,KC_T),    LT(_PSS,KC_Y), LSFT_T(KC_U), RCTL_T(KC_I), RALT_T(KC_O),    RGUI_T(KC_P),   LT(0,KC_C), //C(KC_X),
LT(0,KC_A),			        KC_A,         KC_S,         KC_D,         KC_F,      LT(_SYM,KC_G),    LT(_SYM,KC_H),         KC_J,         KC_K,         KC_L,   LT(0,KC_SCLN),LT(0,KC_QUOT),
LT(0,KC_V),        LT(_SQL,KC_Z),         KC_X,         KC_C,         KC_V,      LT(_FUN,KC_B),    LT(_FUN,KC_N),         KC_M,LT(0,KC_COMM), LT(0,KC_DOT),LT(_SQL,KC_SLSH),LT(0,KC_BSLS),
                                  LT(0,KC_ESC),       KC_TAB,       KC_SPC,        KC_ENT,  KC_BSPC,         KC_DEL
),
[_SYM] = LAYOUT_split_3x6_3(
LT(0,KC_GRAVE),     KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,        KC_F6,         KC_F7,       KC_F8,     KC_F9,       KC_F10,   LT(0,KC_PPLS),
    LT(0,KC_P),LT(0,KC_1),LT(0,KC_2),LT(0,KC_3),LT(0,KC_4),LT(0,KC_5),   LT(0,KC_6),    LT(0,KC_7),  LT(0,KC_8),LT(0,KC_9),   LT(0,KC_0),   LT(0,KC_PAST),
       XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,      XXXXXXX,       XXXXXXX,     XXXXXXX,   _______,      XXXXXXX,   LT(0,KC_EQL),
                               XXXXXXX,  XXXXXXX,    XXXXXXX,                      XXXXXXX,     XXXXXXX,   XXXXXXX
),

[_FUN] = LAYOUT_split_3x6_3(
 _______,   XXXXXXX,   S(KC_BTN1),      _______,      _______,          KC_MUTE,        KC_INS,       _______,     _______,  _______,    XXXXXXX,     XXXXXXX,
 _______,C(KC_BTN1),LT(0,KC_BTN1),      KC_WH_U,      KC_BTN2,          KC_VOLU,       KC_HOME,       XXXXXXX,       KC_UP,  XXXXXXX,    KC_PGUP,     XXXXXXX,
 _______,   XXXXXXX,      KC_WH_L,      KC_WH_D,      KC_WH_R,          KC_VOLD,        KC_END,       KC_LEFT,     KC_DOWN, KC_RIGHT,    KC_PGDN,     XXXXXXX,
                                _______,      _______ ,    _______ ,          _______ ,  _______ ,  _______
),
[_PSS] = LAYOUT_split_3x6_3(
XXXXXXX,                   MY_17,    MY_23,     MY_5,        MY_18,              MY_20,            MY_25,         MY_21,       MY_9,    MY_15,       MY_16,  XXXXXXX,
XXXXXXX,				    MY_1,    MY_19,     MY_4,         MY_6,               MY_7,             MY_8,         MY_10,      MY_11,    MY_12,       MY_29,  XXXXXXX,
XXXXXXX,                   MY_26,    MY_24,     MY_3,        MY_22,               MY_2,            MY_14,         MY_13,      MY_27,    MY_28,       MY_30,  XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX
),
[_SQL] = LAYOUT_split_3x6_3(
LT(0,MY_DECL),      LT(0,MY_SEL), LT(0,MY_WHR),       MY_IN,  LT(0,MY_LK),       LT(0,MY_JN1),            MY_OB,  LT(0,MY_AG1),    XXXXXXX,  XXXXXXX,  C(S(KC_F)), _______,
  LT(0,MY_WQ),			   MY_UP,LT(0,MY_WHRC),LT(0,MY_INC),      XXXXXXX,       LT(0,MY_JN2),      LT(0,MY_GB),  LT(0,MY_AG2),    XXXXXXX,  XXXXXXX,   C(KC_ENT), _______,
      _______,           XXXXXXX,      XXXXXXX,LT(0,MY_ISN),      XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,    XXXXXXX,  XXXXXXX,     A(KC_E), _______,
                                       _______, _______, _______,                                _______,  _______,  _______
    )
};

//void refresh_rgb() {
//  key_timer = timer_read(); // store time of last refresh
 // if (is_rgb_timeout) { // only do something if rgb has timed out
 //   print("Activity detected, removing timeout\n");
 //   is_rgb_timeout = false;
  //  rgblight_wakeup();
 //}
//}

//void check_rgb_timeout() {
//  if (!is_rgb_timeout && timer_elapsed(key_timer) > RGBLIGHT_TIMEOUT) {
 //   rgblight_suspend();
 //   is_rgb_timeout = true;
 // }
//}

void keyboard_post_init_user(void) {
        rgblight_layers = my_rgb_layers;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_Q):
            return TAPPING_TERM + 100;
        case RGUI_T(KC_P):
            return TAPPING_TERM + 100;
        case LALT_T(KC_W):
            return TAPPING_TERM + 0;
        case RALT_T(KC_O):
            return TAPPING_TERM + 0;
        default:
            return TAPPING_TERM;
    }
}

layer_state_t layer_state_set_user(layer_state_t state){
rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
rgblight_set_layer_state(1, layer_state_cmp(state, _SYM));
rgblight_set_layer_state(2, layer_state_cmp(state, _SQL));
rgblight_set_layer_state(3, layer_state_cmp(state, _FUN));
rgblight_set_layer_state(4, layer_state_cmp(state, _PSS));
return state;
}

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  layer_clear();
  return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
        case MY_SQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" '' "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            }
			return false;
        case MY_DQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" \"\" "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
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
        case MY_OB:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" ORDER BY "), 12);
            }
			return false;
      case MY_WQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_TAP(X_HOME)"'"SS_TAP(X_END)"',"SS_TAP(X_DOWN)), 12);
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
                tap_code16(KC_LBRC); // Intercept hold function to send [
                tap_code16(KC_RBRC); // Intercept hold function to send ]
                tap_code(KC_LEFT); //to move inside
            }
			return false;
         case LT(0,KC_ESC):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_ESC); // Intercept tap function to send
            } else if (record->event.pressed) {
                tap_code16(S(KC_Z)); // Intercept hold function to send [
            }
			return false;
         case LT(0,KC_C):
            if (record->tap.count && record->event.pressed) {
			    send_string_with_delay_P(PSTR(""SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)), 12);
                tap_code16(C(KC_C)); // Intercept tap function to send Copy
            } else if (record->event.pressed) {
                send_string_with_delay_P(PSTR(""SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)), 12);
                tap_code16(C(KC_X)); // Intercept hold function to send Cut
            }
			return false;
         case LT(0,KC_V):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C)); // Intercept tap function to send Copy
            } else if (record->event.pressed) {
                tap_code16(C(KC_V)); // Intercept hold function to send Cut
            }
			return false;
         case LT(0,KC_A):
            if (record->tap.count && record->event.pressed) {
                send_string_with_delay_P(PSTR(""SS_DOWN(X_LCTL)SS_TAP(X_RIGHT)SS_DOWN(X_LSFT)SS_TAP(X_LEFT)SS_UP(X_LSFT)SS_UP(X_LCTL)), 12);
                tap_code16(C(KC_C)); // Intercept tap function to send Copy
            } else if (record->event.pressed) {
                send_string_with_delay_P(PSTR(""SS_DOWN(X_LCTL)SS_TAP(X_RIGHT)SS_DOWN(X_LSFT)SS_TAP(X_LEFT)SS_UP(X_LSFT)SS_UP(X_LCTL)), 12);
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
         case LT(0,KC_SCLN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_SCLN); // Intercept tap function to send::;;:;;:..''';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;::>..
            } else if (record->event.pressed) {
                tap_code16(S(KC_SCLN)); // Intercept hold function to send :
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
         case LT(0,KC_GRAVE):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_GRAVE); // Intercept tap function to send `
            } else if (record->event.pressed) {
                tap_code16(S(KC_GRAVE)); // Intercept hold function to send ~
            }
			return false;
         case LT(_SQL,KC_SLSH):
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_SLSH)); // Intercept tap function to send `
                return false;
            }
			return false;
         case LT(0,KC_P):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PIPE); // Intercept tap function to send 0
            } else if (record->event.pressed) {
                tap_code16(S(KC_LBRC)); // Intercept hold function to send {
                tap_code16(S(KC_RBRC)); // Intercept hold function to send }
                tap_code(KC_LEFT); //to move inside
            }
			return false;
         case LT(0,KC_PPLS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PPLS); // Intercept tap function to send +
            } else if (record->event.pressed) {
                tap_code16(KC_PMNS); // Intercept hold function to send -
            }
			return false;
         case LT(0,KC_PAST):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PAST); // Intercept tap function to send *
            } else if (record->event.pressed) {
                tap_code16(KC_PSLS); // Intercept hold function to send /
            }
			return false;
         case LT(0,KC_EQL):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_EQL); // Intercept tap function to send =
            } else if (record->event.pressed) {
                tap_code16(S(KC_MINUS)); // Intercept hold function to send _
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
         case LT(0,KC_BTN1):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_BTN1); // Intercept tap function to send 0
            } else if (record->event.pressed) {
                register_code(KC_MS_BTN1); //Holds Left Mouse Button until another Left Mouse Button is tapped?.
            }
			return false;
    }
	return process_record_secrets(keycode, record);
}

void matrix_scan_user(void) {
  //achordion_task();
}

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

/* Then, call the above functions from QMK's built in post processing functions like so */

/* Runs at the end of each scan loop, check if RGB timeout has occured */
void housekeeping_task_user(void) {
  #ifdef RGBLIGHT_TIMEOUT
  check_rgb_timeout();
  #endif

  /* rest of the function code here */
}

/* Runs after each key press, check if activity occurred */
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef RGBLIGHT_TIMEOUT
  if (record->event.pressed) refresh_rgb();
  #endif

  /* rest of the function code here */
}

