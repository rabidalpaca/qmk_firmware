#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap5
enum layer_names {
    _MIR,
	_SYM,
	_SQL,
	_NAV,
	_FUN,
	_PSS
};
/*
enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
	KC_ORDBY,
	KC_SECRET_1,
	KC_SECRET_2,
	KC_SECRET_3,
	KC_SECRET_4,
	KC_SECRET_5,
	KC_SECRET_6,
	KC_SECRET_7,
	KC_SECRET_8,
	KC_SECRET_9,
	KC_SECRET_10,
	KC_SECRET_11,
	KC_SECRET_12,
	KC_SECRET_13,
	KC_SECRET_14,
	KC_SECRET_15,
	KC_SECRET_16,
	KC_SECRET_17,
	KC_SECRET_18,
	KC_SECRET_19,
	KC_SECRET_20,
	KC_SECRET_21,
	KC_SECRET_22,
	KC_SECRET_23,
	KC_SECRET_24,
	KC_SECRET_25,
	KC_SECRET_26,
	KC_SECRET_27,
	KC_SECRET_28,
	KC_SECRET_29,
	KC_SECRET_30
	};
*/

enum combos {
  DF_SPC,
  JK_ENT,
  UI_BKSP,
  YU_DEL,
  FG_ESC,
  HJ_TAB
  //KLSEMI_TAB
};

const uint16_t PROGMEM df_spc[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_ent[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM ui_del[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM yu_del[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM hj_tab[] = {KC_H, KC_J, COMBO_END};
//const uint16_t PROGMEM klsemi_tab[] = {KC_K, KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM fg_esc[] = {KC_F, KC_G, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [DF_SPC] = COMBO(df_spc, KC_SPC),
  [JK_ENT] = COMBO(jk_ent, KC_ENT),
  [UI_BKSP] = COMBO(ui_del, KC_BSPC),
  [YU_DEL] = COMBO(yu_del, KC_DEL),
  [FG_ESC] = COMBO(fg_esc, KC_ESC),
  [HJ_TAB] = COMBO(hj_tab, KC_TAB),
//  [KLSEMI_TAB] = COMBO(klsemi_tab, LSFT(KC_TAB))
};

enum {
    X_IN,
	X_LIK,
	X_AGS,
	X_AGG,
	X_SEL,
	X_VAR,
    X_PLSMNS
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
	TD_SINGLE_TAPHOLD,
    TD_DOUBLE_TAP,
	TD_TRIPLE_TAP,
	TD_QUADRUPLE_TAP
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void xins_finished(qk_tap_dance_state_t *state, void *user_data);
void xlik_finished(qk_tap_dance_state_t *state, void *user_data);
void xjon_finished(qk_tap_dance_state_t *state, void *user_data);
void xags_finished(qk_tap_dance_state_t *state, void *user_data);
void xagg_finished(qk_tap_dance_state_t *state, void *user_data);
void xsel_finished(qk_tap_dance_state_t *state, void *user_data);
void xvar_finished(qk_tap_dance_state_t *state, void *user_data);
void xplsmns_finished(qk_tap_dance_state_t *state, void *user_data);

#define MT_WINW MT(MOD_RGUI,KC_W)
#define MT_WINDO MT(MOD_LGUI,KC_DOT)
#define MT_ALTE MT(MOD_RALT,KC_E)
#define MT_ALTCOM MT(MOD_LALT,KC_COMM)
#define MT_CTRN MT(MOD_RCTL,KC_N)
#define MT_CTRR MT(MOD_LCTL,KC_R)
#define MT_SFTS MT(MOD_RSFT,KC_SLSH)
#define MT_SHTZ MT(MOD_LSFT,KC_Z)
#define MY_DQUO LSFT(KC_QUOT)
#define MY_TIL LSFT(KC_GRAVE)
#define MY_UND LSFT(KC_MINUS)
#define MY_LNVSP LT(_NAV,KC_SPC)
//#define MY_LSQLL LT(_SQL,KC_L)
//#define MY_LSYMF LT(_SYM,KC_F)
//#define MY_LSYMJ LT(_SYM,KC_J)
//#define MY_LFUND LT(_FUN,KC_D)
//#define MY_LFUNK LT(_FUN,KC_K)
//#define MY_LKYNA LT(_KYN,KC_A)
//#define MY_LKYKS LT(_KYN,KC_SCLN)
//#define MY_LPASH LT(_PSS,KC_H)
//#define MY_LPASG LT(_PSS,KC_G)
#define MY_REDO LCTL(KC_Y)
#define MY_PSTE LCTL(KC_V)
#define MY_COPY LCTL(KC_C)
#define MY_CUT LCTL(KC_X)
#define MY_UNDO LCTL(KC_Z)
#define MY_CTRH LCTL(KC_HOME)
#define MY_CTRE LCTL(KC_END)
#define MY_SFTL LSFT(KC_LEFT)
#define MY_SFTR LSFT(KC_RIGHT)
#define MY_CTRLM LCTL(KC_BTN1)
#define MY_CTRRM LCTL(KC_BTN2)
#define MY_SFTLM LSFT(KC_BTN1)
#define MY_SFTRM LSFT(KC_BTN2)
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
 * |------+------+------+------+------+-------------+------+------+------|fgfgfggfhhhhjjjj
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------|------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------|
 */
[_MIR] = LAYOUT_split_3x6_3(

                    KC_Q,              KC_W,              KC_F,              KC_P,              KC_G,              KC_J,              KC_L,              KC_U,              KC_Y,           KC_QUOT,           \
			LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),              KC_D,              KC_H,      LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),      \
                 MT_SHTZ,     KC_X,     KC_C,         KC_D,               KC_V,             KC_K,          KC_H,    KC_COMM,   KC_DOT,     MT_SFTS,
                          KC_ESC, MY_LNVSP, OSL(_SYM),           OSL(_FUN),  MO(_SQL),  OSL(_PSS)
                       //KC_Q,     KC_W,     KC_E,         KC_R,               KC_T,             KC_Y,          KC_U,       KC_I
    ),
[_SYM] = LAYOUT_split_3x6_3(
                KC_GRAVE,   MY_TIL,  KC_PIPE,      XXXXXXX,            XXXXXXX,          XXXXXXX,        MY_UND,    MY_DQUO,  KC_QUOT,    KC_MINUS,
				 KC_EXLM,    KC_AT,  KC_HASH,       KC_DLR,            KC_PERC,          KC_CIRC,       KC_AMPR,    KC_ASTR,  KC_LPRN,     KC_RPRN,
                  KC_EQL,  KC_MINS,  KC_PLUS,      KC_LCBR,            KC_RCBR,          KC_LBRC,       KC_RBRC,    KC_SCLN,  KC_COLN,     KC_BSLS,
                           KC_TAB, XXXXXXX,  KC_SPC,           KC_ENT,  XXXXXXX,  LSFT(KC_TAB)
                           //KC_A,     KC_S,     KC_D,         KC_F,               KC_G,             KC_H,          KC_J,       KC_K

    ),
/*[_FUN] = LAYOUT(
                   KC_F1,    KC_F2,    KC_F3,        KC_F4,              KC_F5,            KC_F6,         KC_F7,      KC_F8,    KC_F9,     KC_F10,
				    KC_1,     KC_2,     KC_3,         KC_4,               KC_5,             KC_6,          KC_7,       KC_8,     KC_9,       KC_0,
				 KC_EXLM,    KC_AT,  KC_HASH,       KC_DLR,            KC_PERC,          KC_CIRC,       KC_AMPR,    KC_ASTR,  KC_LPRN,    KC_RPRN
     ),*/
[_FUN] = LAYOUT_split_3x6_3(
                   KC_F9,   KC_F10,   KC_F11,       KC_F12,            XXXXXXX,          XXXXXXX,          KC_7,       KC_8,      KC_9,TD(X_PLSMNS),
			       KC_F5,    KC_F6,    KC_F7,        KC_F8,            XXXXXXX,          XXXXXXX,          KC_4,       KC_5,      KC_6,      KC_DOT,
				   KC_F1,    KC_F2,    KC_F3,        KC_F4,            XXXXXXX,             KC_0,          KC_1,       KC_2,      KC_3,      KC_EQL,
                                _______, XXXXXXX, XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX
                                //KC_E,         KC_R,               KC_T,             KC_Y,          KC_U,       KC_I,     KC_O,        KC_P
     ),
[_PSS] = LAYOUT_split_3x6_3(
                   MY_17,    MY_23,     MY_5,        MY_18,              MY_20,            MY_25,         MY_21,       MY_9,    MY_15,       MY_16,
				    MY_1,    MY_19,     MY_4,         MY_6,               MY_7,             MY_8,         MY_10,      MY_11,    MY_12,       MY_29,
                   MY_26,    MY_24,     MY_3,        MY_22,               MY_2,            MY_14,         MY_13,      MY_27,    MY_28,       MY_30,
                               _______, XXXXXXX, XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX
                               //KC_D,         KC_F,               KC_G,             KC_H,          KC_J,       KC_K,     KC_L,     KC_SCLN
    ),
[_SQL] = LAYOUT_split_3x6_3(
                 KC_QSEL,  KC_QWH1, TD(X_IN),      KC_QJN1,            XXXXXXX,            KC_F1,         KC_F2,      KC_F3,    KC_F4,       KC_F5,
			   TD(X_SEL),  KC_QWH2,TD(X_LIK),      KC_QJN2,          TD(X_AGG),          KC_QORB,       XXXXXXX,      KC_UP,  XXXXXXX,     XXXXXXX,
               TD(X_VAR),  KC_QWH3,  XXXXXXX,      KC_QJN3,          TD(X_AGS),          XXXXXXX,       KC_LEFT,    KC_DOWN,  KC_RGHT,       KC_ENT,
                              _______, XXXXXXX, XXXXXXX,           XXXXXXX,XXXXXXX,  XXXXXXX
    ),
[_NAV] = LAYOUT_split_3x6_3(
                 XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,            XXXXXXX,          MY_REDO,       MY_PSTE,    MY_COPY,   MY_CUT,     MY_UNDO,
				 XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,            XXXXXXX,          KC_PGDN,       KC_HOME,      KC_UP,   KC_END,     XXXXXXX,
                 XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,            XXXXXXX,          MY_SFTL,       KC_LEFT,    KC_DOWN,  KC_RIGHT,    MY_SFTR,
                              _______, _______, _______,                                      KC_ENT,XXXXXXX,  XXXXXXX
    )
};

/*
void keyboard_post_init_user(void) {
    //rgb_matrix_mode(RGB_MATRIX_BREATHING);
    rgb_matrix_set_color_all(HSV_BLUE);
    //rgb_matrix_set_color_all(RGB_BLACK);
}
*/

layer_state_t layer_state_set_user(layer_state_t state) {
  switch(get_highest_layer(state)) {
  case _SYM:
    // green-ish
    rgblight_sethsv(HSV_RED);
    break;
  case _SQL:
    // Red
    rgblight_sethsv(HSV_AZURE);
    break;
  case _FUN:
    // Dark Blue
    rgblight_sethsv(HSV_MAGENTA);
    break;
  case _NAV:
    // Dark Blue
    rgblight_sethsv(HSV_GREEN);
    break;
  case _PSS:
    // Dark Blue
    rgblight_sethsv(HSV_ORANGE);
    break;
  default:
    // Default colors
    rgblight_sethsv(HSV_BLUE);
    //rgb_matrix_mode(RGB_MATRIX_BREATHING);
    break;
  }
  return state;
}

/*
bool rgb_matrix_indicators_user(void) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 1:sym
            rgb_matrix_set_color_all(RGB_RED);
            break;
		case 2:SQL
			rgb_matrix_set_color_all(RGB_BLUE);
            break;
		case 3:KYN
            rgb_matrix_set_color_all(RGB_GREEN);
            break;
		case 4:FUN
            rgb_matrix_set_color_all(RGB_MAGENTA);
            break;
		case 5:pss
            rgb_matrix_set_color_all(RGB_ORANGE);
            break;
        default:
            rgb_matrix_set_color_all(RGB_BLUE);
            rgb_matrix_enable();
            rgb_matrix_mode(RGB_MATRIX_BREATHING);
            break;
    }
    return true;
}
*/

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case KC_QORB:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("ORDER BY "), 12);
			layer_clear();return false;}
		case KC_QSEL:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("SELECT\n * \n FROM "), 12);
			layer_clear();return false;}
		case KC_QWH1:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("WHERE "), 12);
			layer_clear();return false;}
		case KC_QWH2:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("WHERE  ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			layer_clear();return false;}
		case KC_QWH3:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("WHERE  BETWEEN  AND"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			layer_clear();return false;}
		case KC_QJN1:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("INNER JOIN  ON"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			layer_clear();return false;}
		case KC_QJN2:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("LEFT OUTER JOIN  ON"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			layer_clear();return false;}
		case KC_QJN3:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("FULL OUTER JOIN  ON"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			layer_clear();return false;}
    }
    //return true;
	return process_record_secrets(keycode, record);
}

// Determine the tapdance state to return
td_state_t cur_dance(qk_tap_dance_state_t *state) {
     switch (state->count)
  {
    case 1:
    {
      if (state->interrupted || state->pressed == 0) return TD_SINGLE_TAP;
      else return TD_SINGLE_TAPHOLD;
      break;
    }
    case 2:
    {
      return TD_DOUBLE_TAP;
      break;
    }
    case 3:
    {
      return TD_TRIPLE_TAP;
      break;
    }
    default:
    {
      return TD_QUADRUPLE_TAP;
      break;
    }
  }
 }

void xins_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            send_string_with_delay_P(PSTR("IN (, )" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)), 12);
            layer_clear();
            break;
        case TD_DOUBLE_TAP:
            send_string_with_delay_P(PSTR("IN ('','')" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)), 12);
            layer_clear();
            break;
        case TD_TRIPLE_TAP:
			send_string_with_delay_P(PSTR("IN (\"\",\"\")" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)), 12);
            layer_clear();
            break;
		case TD_QUADRUPLE_TAP:
            break;
        default:
            break;
    }
}

void xplsmns_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            send_string_with_delay_P(PSTR("+"), 12);
            break;
        case TD_DOUBLE_TAP:
            send_string_with_delay_P(PSTR("-"), 12);
            break;
        case TD_TRIPLE_TAP:
			send_string_with_delay_P(PSTR("*"), 12);
            break;
		case TD_QUADRUPLE_TAP:
        	send_string_with_delay_P(PSTR("/"), 12);
            break;
        default:
            break;
    }
}

void xlik_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("LIKE '%%'"SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            layer_clear();
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("LIKE \"%%\""SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            layer_clear();
            break;
        case TD_TRIPLE_TAP:
            break;
		case TD_QUADRUPLE_TAP:
            break;
        default:
            break;
    }
}

void xagg_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("GROUP BY \n" SS_TAP(X_TAB)), 12);
            layer_clear();
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("HAVING \n"SS_TAP(X_LEFT)), 12);
            layer_clear();
            break;
        case TD_TRIPLE_TAP:
            break;
		case TD_QUADRUPLE_TAP:
            break;
        default:
            break;
    }
}

void xags_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("COUNT(*) as cntof, \n"), 12);
            layer_clear();
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("AVG(*) as avgof, \n"), 12);
            layer_clear();
            break;
        case TD_TRIPLE_TAP:
            break;
		case TD_QUADRUPLE_TAP:
            break;
        default:
            break;
    }
}

void xsel_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("ALTER  TABLE "), 12);
            layer_clear();
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("DELETE FROM  WHERE ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            layer_clear();
            break;
        case TD_TRIPLE_TAP:
			send_string_with_delay_P(PSTR("UPDATE A SET  =  FROM  as A WHERE A.  ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            layer_clear();
            break;
		case TD_QUADRUPLE_TAP:
            break;
        default:
            break;
    }
}

void xvar_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("DECLARE @int INT = "), 12);
            layer_clear();
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("DECLARE @str VARCHAR(50) = ''"SS_TAP(X_LEFT)), 12);
            layer_clear();
            break;
        case TD_TRIPLE_TAP:
            break;
		case TD_QUADRUPLE_TAP:
            break;
        default:
            break;
    }
}

void generic_reset(qk_tap_dance_state_t *state, void *user_data) {

}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [X_IN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xins_finished, generic_reset),
	[X_LIK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xlik_finished, generic_reset),
	[X_AGS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xags_finished, generic_reset),
	[X_AGG] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xagg_finished, generic_reset),
	[X_SEL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xsel_finished, generic_reset),
	[X_VAR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xvar_finished, generic_reset),
    [X_PLSMNS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xplsmns_finished, generic_reset)
};


