#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap5
enum layer_names {
    _QWERTY,
	_SYM,
	_SQL,
	_KYN,
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
  OP_BKSP,
  IOP_DEL,
  QW_ESC,
  ASD_TAB,
  KLSEMI_TAB
};

const uint16_t PROGMEM df_spc[] = {LT(_FUN,KC_D), LT(_SYM,KC_F), COMBO_END};
const uint16_t PROGMEM jk_ent[] = {LT(_SYM,KC_J), LT(_FUN,KC_K), COMBO_END};
const uint16_t PROGMEM op_del[] = {MT(MOD_LGUI,KC_O), KC_P, COMBO_END};
const uint16_t PROGMEM iop_del[] = {MT(MOD_LALT,KC_I), MT(MOD_LGUI,KC_O), KC_P, COMBO_END};
const uint16_t PROGMEM asd_tab[] = {LT(_KYN,KC_A),LT(_SQL,KC_S), LT(_FUN,KC_D), COMBO_END};
const uint16_t PROGMEM klsemi_tab[] = {LT(_FUN,KC_K), LT(_SQL,KC_L), LT(_KYN,KC_SCLN), COMBO_END};
const uint16_t PROGMEM qw_esc[] = {KC_Q, MT(MOD_RGUI,KC_W), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [DF_SPC] = COMBO(df_spc, KC_SPC),
  [JK_ENT] = COMBO(jk_ent, KC_ENT),
  [OP_BKSP] = COMBO(op_del, KC_BSPC),
  [IOP_DEL] = COMBO(iop_del, KC_DEL),
  [QW_ESC] = COMBO(qw_esc, KC_ESC),
  [ASD_TAB] = COMBO(asd_tab, KC_TAB),
  [KLSEMI_TAB] = COMBO(klsemi_tab, LSFT(KC_TAB))
};

enum {
    X_IN, 
	X_LIK,
	X_AGS,
	X_AGG,
	X_SEL,
	X_VAR
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

#define MT_WINW MT(MOD_RGUI,KC_W)
#define MT_WINO MT(MOD_LGUI,KC_O)
#define MT_ALTE MT(MOD_RALT,KC_E)
#define MT_ALTI MT(MOD_LALT,KC_I)
#define MT_CTRU MT(MOD_RCTL,KC_U)
#define MT_CTRR MT(MOD_LCTL,KC_R)
#define MT_SFTS MT(MOD_RSFT,KC_SLSH)
#define MT_SHTZ MT(MOD_LSFT,KC_Z)
#define MY_DQUO LSFT(KC_QUOT)
#define MY_TIL LSFT(KC_GRAVE)
#define MY_UND LSFT(KC_MINUS)
#define MY_LSQLS LT(_SQL,KC_S)
#define MY_LSQLL LT(_SQL,KC_L)
#define MY_LSYMF LT(_SYM,KC_F)
#define MY_LSYMJ LT(_SYM,KC_J)
#define MY_LFUND LT(_FUN,KC_D)
#define MY_LFUNK LT(_FUN,KC_K)
#define MY_LKYNA LT(_KYN,KC_A)
#define MY_LKYKS LT(_KYN,KC_H)
#define MY_LPASH LT(_PSS,KC_A)
#define MY_LPASG LT(_PSS,KC_G)
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
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI | Alt  | App  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT(
                
                   KC_Q,   KC_W,  KC_E,      KC_R,               KC_T
    )
};




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

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t temp_mod = get_mods();
    uint8_t temp_osm = get_oneshot_mods();
    bool    is_ctrl  = (temp_mod | temp_osm) & MOD_MASK_CTRL;
    bool    is_shift = (temp_mod | temp_osm) & MOD_MASK_SHIFT;

    if (is_shift) {
        if (index == 0) { /* First encoder */
            if (clockwise) {
               // rgb_matrix_increase_hue();
            } else {
               // rgb_matrix_decrease_hue();
            }
        } else if (index == 1) { /* Second encoder */
            if (clockwise) {
               // rgb_matrix_decrease_sat();
            } else {
                //rgb_matrix_increase_sat();
            }
        }
    } else if (is_ctrl) {
        if (index == 0) { /* First encoder */
            if (clockwise) {
               // rgb_matrix_increase_val();
            } else {
                //rgb_matrix_decrease_val();
            }
        } else if (index == 1) { /* Second encoder */
            if (clockwise) {
                //rgb_matrix_increase_speed();
            } else {
                //rgb_matrix_decrease_speed();
            }
        }
    } else {
        if (index == 1) { /* First encoder */
            if (clockwise) {
                tap_code(KC_PGUP);
                // tap_code(KC_MS_WH_UP);
            } else {
                tap_code(KC_PGDOWN);
                // tap_code(KC_MS_WH_DOWN);
            }
        } else if (index == 0) { /* Second encoder */
            uint16_t mapped_code        = 0;
            if (clockwise) {
                mapped_code = KC_VOLD;
            } else {
                mapped_code = KC_VOLU;
            }
            tap_code_delay(mapped_code, MEDIA_KEY_DELAY);
        }
    }
    return true;
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
            break;
        case TD_DOUBLE_TAP:
            send_string_with_delay_P(PSTR("IN ('','')" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)), 12);
            break;
        case TD_TRIPLE_TAP: 
			send_string_with_delay_P(PSTR("IN (\"\",\"\")" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)), 12);
            break;
		case TD_QUADRUPLE_TAP: 
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
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("LIKE \"%%\""SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
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
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("HAVING \n"SS_TAP(X_LEFT)), 12);
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
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("AVG(*) as avgof, \n"), 12);
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
			send_string_with_delay_P(PSTR("SELECT\n * \n FROM "), 12);
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("ALTER TABLE "SS_TAP(X_LEFT)), 12);
            break;
        case TD_TRIPLE_TAP: 
			send_string_with_delay_P(PSTR("DELETE FROM WHERE  ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);	
            break;
		case TD_QUADRUPLE_TAP: 
			send_string_with_delay_P(PSTR("UPDATE A SET  =  FROM  as A WHERE A.  ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);	
            break;
        default:
            break;
    }
}

void xvar_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("DECLARE @int INT ="), 12);
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("DECLARE @str VARCHAR(50) = ''SS_TAP(X_LEFT)"), 12);
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
	[X_VAR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xvar_finished, generic_reset)
};


