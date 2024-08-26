#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap5
enum layer_names {
    _QWERTY,
	_SYM,
	_SQL,
	_KYN,
	_PSS,
	_FUN
};

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
	KC_ORDBY
	};
	
enum combos {
  DF_SPC,
  JK_ENT,
  OP_BKSP,
  IOP_DEL,
  QW_ESC,
  ASD_TAB,
  KLSEMI_TAB
};

const uint16_t PROGMEM df_spc[] = {KC_D, LT(_FUN,KC_F), COMBO_END};
const uint16_t PROGMEM jk_ent[] = {LT(_FUN,KC_J), KC_K, COMBO_END};
const uint16_t PROGMEM op_del[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM iop_del[] = {KC_I, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM asd_tab[] = {KC_A, KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM klsemi_tab[] = {KC_K, KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM qw_esc[] = {KC_Q, KC_W, COMBO_END};

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
	X_JON,
	X_AGS,
	X_AGG,
	X_WHE,
	X_SEL,
	X_VAR,
	X_PS0,
	X_PS1,
	X_PS2,
	X_PS3,
	X_PS4,
	X_PS5,
	X_PS6,
	X_PS7,
	X_PS8,
	X_PS9
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
void xwhe_finished(qk_tap_dance_state_t *state, void *user_data);
void xsel_finished(qk_tap_dance_state_t *state, void *user_data);
void xvar_finished(qk_tap_dance_state_t *state, void *user_data);
void xps0_finished(qk_tap_dance_state_t *state, void *user_data);
void xps1_finished(qk_tap_dance_state_t *state, void *user_data);
void xps2_finished(qk_tap_dance_state_t *state, void *user_data);
void xps3_finished(qk_tap_dance_state_t *state, void *user_data);
void xps4_finished(qk_tap_dance_state_t *state, void *user_data);
void xps5_finished(qk_tap_dance_state_t *state, void *user_data);
void xps6_finished(qk_tap_dance_state_t *state, void *user_data);
void xps7_finished(qk_tap_dance_state_t *state, void *user_data);
void xps8_finished(qk_tap_dance_state_t *state, void *user_data);
void xps9_finished(qk_tap_dance_state_t *state, void *user_data);

#define MT_WINX MT(MOD_RGUI,KC_X)
#define MT_WNSD MT(MOD_LGUI,KC_DOT)
#define MT_ALTC MT(MOD_RALT,KC_C)
#define MT_ALTCM MT(MOD_LALT,KC_COMM)
#define MT_CTRV MT(MOD_RCTL,KC_V)
#define MT_CTRM MT(MOD_LCTL,KC_M)
#define MT_SFTS MT(MOD_RSFT,KC_SLSH)
#define MT_SHTZ MT(MOD_LSFT,KC_Z)
#define MY_DQUO LSFT(KC_QUOT)
#define MY_TIL LSFT(KC_GRAVE)
#define MY_UND LSFT(KC_MINUS)

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
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,            XXXXXXX,           KC_MUTE,                             KC_MUTE,         XXXXXXX,       XXXXXXX,    XXXXXXX, XXXXXXX,    XXXXXXX,   XXXXXXX, 
                 XXXXXXX,    KC_Q,    KC_W,    KC_E,LT(_KYN,KC_R),      LT(_SQL,KC_T),                                                           LT(_SQL,KC_Y), LT(_KYN,KC_U),       KC_I,    KC_O,       KC_P,   XXXXXXX, 
				 XXXXXXX,    KC_A,    KC_S,    KC_D,LT(_FUN,KC_F),      LT(_SYM,KC_G),                                                           LT(_SYM,KC_H), LT(_FUN,KC_J),       KC_K,    KC_L,    KC_SCLN,   XXXXXXX,  
                 XXXXXXX, MT_SHTZ, MT_WINX, MT_ALTC,      MT_CTRV,               KC_B,           XXXXXXX,                             XXXXXXX,            KC_N,       MT_CTRM,   MT_ALTCM, MT_WNSD,    MT_SFTS,   XXXXXXX,
       XXXXXXX,                                              XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  				 			                       XXXXXXX
    ),
[_SYM] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,            XXXXXXX,           XXXXXXX,                             XXXXXXX,         XXXXXXX,       XXXXXXX,    XXXXXXX, XXXXXXX,    XXXXXXX,     XXXXXXX, 
                 XXXXXXX,KC_GRAVE,  MY_TIL, KC_PIPE,      XXXXXXX,            XXXXXXX,                                                                 XXXXXXX,        MY_UND,    MY_DQUO, KC_QUOT,   KC_MINUS,     XXXXXXX,
				 XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,       KC_DLR,            KC_PERC,                                                                 KC_CIRC,       KC_AMPR,    KC_ASTR, KC_LPRN,    KC_RPRN,     XXXXXXX, 
                 XXXXXXX,  KC_EQL, KC_MINS, KC_PLUS,      KC_LCBR,            KC_RCBR,           XXXXXXX,                             XXXXXXX,         KC_LBRC,       KC_RBRC,    KC_SCLN, KC_COLN,    KC_BSLS,     XXXXXXX,
       XXXXXXX,                                              XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,   XXXXXXX,     XXXXXXX,     XXXXXXX,   XXXXXXX, XXXXXXX,    XXXXXXX,  				 			                       XXXXXXX
    ),
[_FUN] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,            XXXXXXX,           XXXXXXX,                             XXXXXXX,         XXXXXXX,       XXXXXXX,    XXXXXXX, XXXXXXX,    XXXXXXX,     XXXXXXX, 
                 XXXXXXX,   KC_F1,   KC_F2,   KC_F3,        KC_F4,              KC_F5,                                                                   KC_F6,         KC_F7,      KC_F8,   KC_F9,     KC_F10,     XXXXXXX,
				 XXXXXXX,    KC_1,    KC_2,    KC_3,         KC_4,               KC_5,                                                                    KC_6,          KC_7,       KC_8,    KC_9,       KC_0,     XXXXXXX,
                 XXXXXXX,TD(X_PS1),TD(X_PS2),TD(X_PS3),     TD(X_PS4),           TD(X_PS5),           XXXXXXX,                             XXXXXXX,        TD(X_PS6),      TD(X_PS7),   TD(X_PS8),TD(X_PS9),   TD(X_PS0),     XXXXXXX, 
       XXXXXXX,                                              XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,   XXXXXXX,     XXXXXXX,     XXXXXXX,   XXXXXXX, XXXXXXX,    XXXXXXX,  				 			                       XXXXXXX
    ),                                         
[_SQL] = LAYOUT(
                 XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,     XXXXXXX,             XXXXXXX,           XXXXXXX,                             XXXXXXX,         XXXXXXX,       XXXXXXX,    XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX, 
                 XXXXXXX,TD(X_VAR),   XXXXXXX,TD(X_IN),     XXXXXXX,             XXXXXXX,                                                                   KC_F1,         KC_F2,      KC_F3,   KC_F4,      KC_F5,    XXXXXXX,
				 XXXXXXX,TD(X_SEL),TD(X_WHE),TD(X_LIK),  TD(X_JON),          TD(X_AGG),                                                                KC_ORDBY,       XXXXXXX,      KC_UP, XXXXXXX,    XXXXXXX,    XXXXXXX,  
                 XXXXXXX,TD(X_AGS),   XXXXXXX,   XXXXXXX,     XXXXXXX,             XXXXXXX,           XXXXXXX,                             XXXXXXX,         XXXXXXX,       KC_LEFT,    KC_DOWN, KC_RGHT,     KC_ENT,    XXXXXXX,
       XXXXXXX,                                              XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,   XXXXXXX,     XXXXXXX,     XXXXXXX,   XXXXXXX, XXXXXXX,    XXXXXXX,  				 			                       XXXXXXX
    ),  
[_KYN] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,            XXXXXXX,           XXXXXXX,                             XXXXXXX,          XXXXXXX,       XXXXXXX,    XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX, 
                 XXXXXXX, KC_INS,  KC_PSCR, XXXXXXX,     XXXXXXX,            XXXXXXX,                                                                  KC_PGUP,      KC_PRVWD,      KC_UP,KC_NXTWD,   KC_DLINE,    XXXXXXX, 
				 XXXXXXX,XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX,            XXXXXXX,                                                                  KC_PGDN,       KC_LEFT,    KC_DOWN, KC_RGHT,    XXXXXXX,    XXXXXXX,  
                 XXXXXXX,XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX,            XXXXXXX,           XXXXXXX,                             XXXXXXX,          XXXXXXX,      KC_LSTRT,    XXXXXXX, KC_LEND,    XXXXXXX,    XXXXXXX,
       XXXXXXX,                                              XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,   XXXXXXX,     XXXXXXX,     XXXXXXX,   XXXXXXX, XXXXXXX,    XXXXXXX,  				 			                       XXXXXXX
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
		case KC_ORDBY:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("ORDER BY "), 12);
			layer_clear();return false;}
    }
    return true;
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

void xjon_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("INNER JOIN  ON"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("LEFT OUTER JOIN  ON"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            break;
        case TD_TRIPLE_TAP: 
			send_string_with_delay_P(PSTR("FULL OUTER JOIN  ON"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
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

void xwhe_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("WHERE "), 12);
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("WHERE  ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
            break;
        case TD_TRIPLE_TAP: 
			send_string_with_delay_P(PSTR("WHERE  BETWEEN  AND"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);		
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

void xps0_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("636-536-5726"), 12);
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("636-288-8007"), 12);
            break;
        case TD_TRIPLE_TAP: 
			send_string_with_delay_P(PSTR("roger.young@protective.com"), 12);
            break;
		case TD_QUADRUPLE_TAP: 
			send_string_with_delay_P(PSTR("ntdomain\\po56839"), 12);
            break;
        default:
            break;
    }
}

void xps1_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("4Nnoying4Nt!"), 12);
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("B0ringB4t!"), 12);
            break;
        case TD_TRIPLE_TAP: 
			send_string_with_delay_P(PSTR("Cr4zyC4t!"), 12);
            break;
		case TD_QUADRUPLE_TAP: 
            break;
        default:
            break;
    }
}

void xps2_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("D0peyD1ngo"), 12);
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("3Nvious3Lephant!"), 12);
            break;
        case TD_TRIPLE_TAP:
			send_string_with_delay_P(PSTR("F1estyF1sh!"), 12);
            break;
		case TD_QUADRUPLE_TAP: 
            break;
        default:
            break;
    }
}

void xps3_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("G0ryG0rilla!"), 12);
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("H4ppyH1ppo!"), 12);
            break;
        case TD_TRIPLE_TAP: 
			send_string_with_delay_P(PSTR("1Diot1Mp!"), 12);
            break;
		case TD_QUADRUPLE_TAP: 
            break;
        default:
            break;
    }
}

void xps4_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("Jump1ngJ4guar!"), 12);	
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("K0rnyK0ala!"), 12);
            break;
        case TD_TRIPLE_TAP: 
			send_string_with_delay_P(PSTR("L0stL3pard!"), 12);
            break;
		case TD_QUADRUPLE_TAP: 
            break;
        default:
            break;
    }
}

void xps5_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("M0rbidM0use!"), 12);
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("N3roticN4rwhal!"), 12);
            break;
        case TD_TRIPLE_TAP:
			send_string_with_delay_P(PSTR("0Vert0Ctopus!"), 12);
            break;
		case TD_QUADRUPLE_TAP: 
            break;
        default:
            break;
    }
}

void xps6_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("P4leP3nda!"), 12);
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("Qu1etQu4il!"), 12);
            break;
        case TD_TRIPLE_TAP: 
			send_string_with_delay_P(PSTR("R4bidR4coon!"), 12);
            break;
		case TD_QUADRUPLE_TAP: 
            break;
        default:
            break;
    }
}

void xps7_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("S1llySn4ke!"), 12);
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("T4ckyT1ger!"), 12);
            break;
        case TD_TRIPLE_TAP: 
			send_string_with_delay_P(PSTR("Us3lessU4kari!"), 12);
            break;
		case TD_QUADRUPLE_TAP: 
            break;
        default:
            break;
    }
}

void xps8_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("V4liantVultur3!"), 12);
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("W4rmW3asel!"), 12);
            break;
        case TD_TRIPLE_TAP: 
			send_string_with_delay_P(PSTR("X3nophobicX3rus!"), 12);
            break;
		case TD_QUADRUPLE_TAP: 
            break;
        default:
            break;
    }
}

void xps9_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("Y0ungY4k!"), 12);
            break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("Z3alousZ3bra!"), 12);
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
	[X_JON] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xjon_finished, generic_reset),
	[X_AGS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xags_finished, generic_reset),
	[X_AGG] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xagg_finished, generic_reset),
	[X_WHE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xwhe_finished, generic_reset),
	[X_SEL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xsel_finished, generic_reset),
	[X_VAR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xvar_finished, generic_reset),
	[X_PS0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xps0_finished, generic_reset),
	[X_PS1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xps1_finished, generic_reset),
	[X_PS2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xps2_finished, generic_reset),
	[X_PS3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xps3_finished, generic_reset),
	[X_PS4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xps4_finished, generic_reset),
	[X_PS5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xps5_finished, generic_reset),
	[X_PS6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xps6_finished, generic_reset),
	[X_PS7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xps7_finished, generic_reset),
	[X_PS8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xps8_finished, generic_reset),
	[X_PS9] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xps9_finished, generic_reset),
};


