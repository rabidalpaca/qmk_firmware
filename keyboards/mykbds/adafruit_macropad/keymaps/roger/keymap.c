#include QMK_KEYBOARD_H

#define _BASE 0

enum _layers {
    _QWERTY = 0,
	_SHRT,
	_QRY,
	_NAV
};

enum combos {
  NAV_L_LAYER,
  NAV_R_LAYER,
  QRY_L_LAYER,
  QRY_R_LAYER,
  SHRT_L_LAYER,
  SHRT_R_LAYER,
};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};

const uint16_t PROGMEM dg_combo[] = {KC_D, KC_G, COMBO_END};
const uint16_t PROGMEM hk_combo[] = {KC_H, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [QRY_L_LAYER] = COMBO(df_combo, TG(_QRY)),
  [QRY_R_LAYER] = COMBO(jk_combo, TG(_QRY)),

  [NAV_L_LAYER] = COMBO(sd_combo, TG(_NAV)),
  [NAV_R_LAYER] = COMBO(kl_combo, TG(_NAV)),

  [SHRT_L_LAYER] = COMBO(dg_combo, TG(_SHRT)),
  [SHRT_R_LAYER] = COMBO(hk_combo, TG(_SHRT)),
};


typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    MAXP,
	QRYJOIN,
	OCBRCK,
	OCQTES,
	PHONE,
	USER,
	RTST,
	XYZ,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
	KC_QSLT,
	KC_IJOIN,
	KC_LJOIN,
	KC_RJOIN,
	KC_QINS,
	KC_QUPD,
	KC_QHAV,
	KC_QFRM,
	KC_QDEL,
	KC_QGPB,
	KC_QORD,
	KC_QWHR,
	KC_QCNT,
	KC_QLIK,
	KC_BTWN,
	KC_CMAL,
	KC_PAS1,
	KC_PAS2,
	KC_PAS3,
	KC_PAS4,
	KC_PAS5,
	KC_PAS6,
	KC_PAS7,
	KC_PAS8,
	KC_PAS9,
	KC_PAS10,
	KC_PAS11,
	KC_PAS12,
	KC_FRMT,
	KC_EXCU,
	KC_EXPD,
	KC_TBEN,
	KC_QTOP,
	KC_PLYR,
	KC_QLST,
	KC_SYSA,
	KC_SYSS,
	KC_DBO,
	KC_QS36F,
	KC_ICRP,
	KC_VTSI,
	KC_CLRL,
	ENC_L,
	ENC_R,
	ENC_D,
	KC_EMAIL
};

#define KC_WNLO G(KC_L)
#define KC_WNSLA C(KC_A)
#define KC_WNCOP C(KC_C)
#define KC_WNPAS C(KC_V)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
         KC_ESC,     KC_1,    KC_2,     KC_3,     KC_4,     KC_5,      KC_6,    KC_7,      KC_8,     KC_9,     KC_0,   KC_MINS,  KC_EQL, KC_BSPC, KC_MUTE,
         KC_TAB,     KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,    KC_U,      KC_I,     KC_O,     KC_P,   KC_LBRC, KC_RBRC, KC_BSLS,
        KC_WNLO,     KC_A,    KC_S,     KC_D,     KC_F,     KC_G,      KC_H,    KC_J,      KC_K,     KC_L,  KC_SCLN,   KC_QUOT,  KC_ENT,
        KC_LSFT,     KC_Z,    KC_X,     KC_C,     KC_V,     KC_B,      KC_N,    KC_M,   KC_COMM,   KC_DOT, KC_WNPAS,     KC_UP, KC_SLSH,
        KC_LCTL,  KC_LGUI, KC_LALT,   KC_SPC,                                          KC_WNSLA, KC_WNCOP,  KC_LEFT,   KC_DOWN, KC_RIGHT
    ),
	[_QRY] = LAYOUT(
        _______, _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,   _______, _______,   _______, _______, _______,  _______,
        _______, _______,  KC_QWHR,  _______,   _______,  _______,  _______,  KC_QUPD,  KC_QINS,   KC_QORD, _______,TD(OCBRCK), _______, _______,
        _______, _______,  KC_QSLT,  KC_QDEL,   KC_QFRM,  KC_QGPB,  KC_QHAV,  _______,  _______,   KC_QLIK, _______,TD(OCQTES), _______,
        _______, _______,  _______,  KC_QCNT,   _______,  KC_BTWN,  _______,  _______,  KC_CMAL,   _______, KC_FRMT,   _______, _______,
        _______, _______,  _______,  _______,                             			    KC_EXCU,   KC_EXPD,KC_LJOIN,TD(QRYJOIN),KC_RJOIN
    ),
	[_SHRT] = LAYOUT(
        _______, KC_PAS1,  KC_PAS2,  KC_PAS3,   KC_PAS4,  KC_PAS5,  KC_PAS6,  KC_PAS7,  KC_PAS8,  KC_PAS9, KC_PAS10,  KC_PAS11,KC_PAS12, _______,  _______,
        KC_TBEN, _______,  _______, KC_EMAIL,   _______,  _______,  _______, TD(USER),  _______,  _______,TD(PHONE),   _______, _______, _______,
        _______, _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______, _______,
        _______, _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______, _______,
        _______, _______,  _______,  _______,                             			    _______,  _______,  _______,   _______, _______
    ),
    [_NAV] = LAYOUT(
        _______,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,   KC_F7,     KC_F8,    KC_F9,   KC_F10,    KC_F11,  KC_F12,  KC_DEL,  _______,
        _______, RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,   RGB_SAD, RGB_VAI,   RGB_VAD,  _______,  _______,   _______, _______, _______,
        _______, _______,  _______,  _______,  _______,  _______,   _______, _______,   _______,  _______,  _______,   _______, _______,
        _______, _______,  _______,  _______,  _______,  _______,   _______, _______,   _______,  _______,  _______,   _______, _______,
        _______, _______,  _______,  _______,                                           _______,  _______,  _______,   _______, _______
    ),


};


void rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
		    //rgb_matrix_set_color_all(64,0,0);
			// rgb_matrix_mode(RGB_MATRIX_HUE_BREATHING);
			rgb_matrix_set_color(0, 255, 0, 0);
			rgb_matrix_set_color(13, 255, 0, 0);
			rgb_matrix_set_color(54, 255, 0, 0);
			rgb_matrix_set_color(62, 255, 0, 0);
            break;
        case _QRY:
            //rgb_matrix_set_color_all(0,64,0);
			rgb_matrix_set_color(0, 0, 255, 0);
			rgb_matrix_set_color(13, 0, 255, 0);
			rgb_matrix_set_color(54, 0, 255, 0);
			rgb_matrix_set_color(62, 0, 255, 0);
			//rgb_matrix_mode(RGB_MATRIX_GRADIENT_LEFT_RIGHT);
            break;
        case _SHRT:
            //rgb_matrix_set_color_all(64, 0, 64);
			rgb_matrix_set_color(0, 255, 0, 255);
			rgb_matrix_set_color(13, 255, 0, 255);
			rgb_matrix_set_color(54, 255, 0, 255);
			rgb_matrix_set_color(62, 255, 0, 255);
			// rgb_matrix_mode(RGB_MATRIX_GRADIENT_UP_DOWN);
            break;
        case _NAV:
            //rgb_matrix_set_color_all(0, 64, 64);
			rgb_matrix_set_color(0, 0, 255, 255);
			rgb_matrix_set_color(13, 0, 255, 255);
			rgb_matrix_set_color(54, 0, 255, 255);
			rgb_matrix_set_color(62, 0, 255, 255);
			// rgb_matrix_mode(RGB_MATRIX_PIXEL_RAIN);
            break;
        default:
            break;
    }
}
layer_state_t layer_state_set_user(layer_state_t state){
    //xprintf("Layer State: 0b%032lb (%u)\n", state, get_highest_layer(state));
    return state;
}

bool has_layer_changed = false;
static uint8_t current_layer;

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

static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

 td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_TAP;//TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_TAP;//TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return  TD_DOUBLE_TAP;//TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_TAP;//TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

void queryj_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("INNER JOIN  ON"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			break;
        case TD_SINGLE_HOLD:
			break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("FULL OUTER JOIN  ON"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			break;
        case TD_DOUBLE_HOLD:
			break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
			break;
		case TD_TRIPLE_TAP:
			send_string_with_delay_P(PSTR("CROSS JOIN "), 12);
			break;
		case TD_NONE:
			break;
		case TD_TRIPLE_HOLD:
			break;
		case TD_UNKNOWN:
			break;
    }
	layer_off(_QRY);
}
//
void queryj_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
			break;
        case TD_SINGLE_HOLD:
			break;
        case TD_DOUBLE_TAP:
			break;
        case TD_DOUBLE_HOLD:
			break;
        case TD_DOUBLE_SINGLE_TAP:
			break;
		case TD_NONE:
			break;
		case TD_TRIPLE_HOLD:
			break;
		case TD_TRIPLE_TAP:
			break;
		case TD_UNKNOWN:
			break;
    }
	layer_off(_QRY);
    xtap_state.state = TD_NONE;
}

void ocqts_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
		    send_string_with_delay_P(PSTR("''" SS_TAP(X_LEFT)), 12);
			break;
        case TD_SINGLE_HOLD:
			break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("'%%'" SS_TAP(X_LEFT) SS_TAP(X_LEFT)), 12);
			break;
        case TD_DOUBLE_HOLD:
			break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
			break;
		case TD_TRIPLE_TAP:
	        send_string_with_delay_P(PSTR("\"\"" SS_TAP(X_LEFT)), 12);
			break;
		case TD_NONE:
			break;
		case TD_TRIPLE_HOLD:
			send_string_with_delay_P(PSTR("\"%%\"" SS_TAP(X_LEFT)), 12);
			break;
		case TD_UNKNOWN:
			break;
    }
	layer_off(_QRY);
}
//
void ocqts_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
			break;
        case TD_SINGLE_HOLD:
			break;
        case TD_DOUBLE_TAP:
			break;
        case TD_DOUBLE_HOLD:
			break;
        case TD_DOUBLE_SINGLE_TAP:
			break;
		case TD_NONE:
			break;
		case TD_TRIPLE_HOLD:
			break;
		case TD_TRIPLE_TAP:
			break;
		case TD_UNKNOWN:
			break;
    }
	layer_off(_QRY);
    xtap_state.state = TD_NONE;
}

void ocbrck_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("()" SS_TAP(X_LEFT)), 12);
			break;
        case TD_SINGLE_HOLD:
			break;
        case TD_DOUBLE_TAP:
	        send_string_with_delay_P(PSTR("[]" SS_TAP(X_LEFT)), 12);
			break;
        case TD_DOUBLE_HOLD:
			break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
			break;
		case TD_TRIPLE_TAP:
	        send_string_with_delay_P(PSTR("{}" SS_TAP(X_LEFT)), 12);
			break;
		case TD_NONE:
			break;
		case TD_TRIPLE_HOLD:
			send_string_with_delay_P(PSTR("<>" SS_TAP(X_LEFT)), 12);
			break;
		case TD_UNKNOWN:
			break;
    }
	layer_off(_QRY);
}
//
void ocbrck_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
			break;
        case TD_SINGLE_HOLD:
			break;
        case TD_DOUBLE_TAP:
			break;
        case TD_DOUBLE_HOLD:
			break;
        case TD_DOUBLE_SINGLE_TAP:
			break;
		case TD_NONE:
			break;
		case TD_TRIPLE_HOLD:
			break;
		case TD_TRIPLE_TAP:
			break;
		case TD_UNKNOWN:
			break;
    }
	layer_off(_QRY);
    xtap_state.state = TD_NONE;
}

void user_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("P056839"), 12);
			break;
        case TD_SINGLE_HOLD:
			break;
        case TD_DOUBLE_TAP:
	        send_string_with_delay_P(PSTR("roger.young@protective.com"), 12);
			break;
        case TD_DOUBLE_HOLD:
			break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
			break;
		case TD_TRIPLE_TAP:
			break;
		case TD_NONE:
			break;
		case TD_TRIPLE_HOLD:
			break;
		case TD_UNKNOWN:
			break;
    }
	layer_off(_SHRT);
}
//
void user_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
			break;
        case TD_SINGLE_HOLD:
			break;
        case TD_DOUBLE_TAP:
			break;
        case TD_DOUBLE_HOLD:
			break;
        case TD_DOUBLE_SINGLE_TAP:
			break;
		case TD_NONE:
			break;
		case TD_TRIPLE_HOLD:
			break;
		case TD_TRIPLE_TAP:
			break;
		case TD_UNKNOWN:
			break;
    }
	layer_off(_SHRT);
    xtap_state.state = TD_NONE;
}

void phone_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("636-536-5726"), 12);
			break;
        case TD_SINGLE_HOLD:
			break;
        case TD_DOUBLE_TAP:
	        send_string_with_delay_P(PSTR("636-288-8007"), 12);
			break;
        case TD_DOUBLE_HOLD:
			break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
			break;
		case TD_TRIPLE_TAP:
			break;
		case TD_NONE:
			break;
		case TD_TRIPLE_HOLD:
			break;
		case TD_UNKNOWN:
			break;
    }
	layer_off(_SHRT);
}
//
void phone_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
			break;
        case TD_SINGLE_HOLD:
			break;
        case TD_DOUBLE_TAP:
			break;
        case TD_DOUBLE_HOLD:
			break;
        case TD_DOUBLE_SINGLE_TAP:
			break;
		case TD_NONE:
			break;
		case TD_TRIPLE_HOLD:
			break;
		case TD_TRIPLE_TAP:
			break;
		case TD_UNKNOWN:
			break;
    }
	layer_off(_SHRT);
    xtap_state.state = TD_NONE;
}

void rtst_finished(qk_tap_dance_state_t *state, void *user_data) {
	xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("TD_SINGLE_TAP"), 12);
			break;
        case TD_SINGLE_HOLD:
			send_string_with_delay_P(PSTR("TD_SINGLE_HOLD"), 12);
			break;
        case TD_DOUBLE_TAP:
			send_string_with_delay_P(PSTR("TD_DOUBLE_TAP"), 12);
			break;
        case TD_DOUBLE_HOLD:
			send_string_with_delay_P(PSTR("TD_DOUBLE_HOLD"), 12);
			break;
        case TD_DOUBLE_SINGLE_TAP:
			send_string_with_delay_P(PSTR("TD_DOUBLE_SINGLE_TAP"), 12);
			break;
		case TD_NONE:
			break;
		case TD_TRIPLE_HOLD:
			send_string_with_delay_P(PSTR("TD_TRIPLE_HOLD"), 12);
			break;
		case TD_TRIPLE_TAP:
			send_string_with_delay_P(PSTR("TD_TRIPLE_TAP"), 12);
			break;
		case TD_UNKNOWN:
			break;
    }

    xtap_state.state = TD_NONE;
}

void rtst_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
			break;
        case TD_SINGLE_HOLD:
			break;
        case TD_DOUBLE_TAP:
			break;
        case TD_DOUBLE_HOLD:
			break;
        case TD_DOUBLE_SINGLE_TAP:
			break;
		case TD_NONE:
			break;
		case TD_TRIPLE_HOLD:
			break;
		case TD_TRIPLE_TAP:
			break;
		case TD_UNKNOWN:
			break;
    }

    xtap_state.state = TD_NONE;
}

void xyz_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
			send_string_with_delay_P(PSTR("636-536-5726"), 12);
			break;
        case TD_SINGLE_HOLD:
			break;
        case TD_DOUBLE_TAP:
	        send_string_with_delay_P(PSTR("636-288-8007"), 12);
			break;
        case TD_DOUBLE_HOLD:
			break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
			break;
		case TD_TRIPLE_TAP:
			break;
		case TD_NONE:
			break;
		case TD_TRIPLE_HOLD:
			break;
		case TD_UNKNOWN:
			break;
    }
	layer_off(_SHRT);
}
//
void xyz_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
			break;
        case TD_SINGLE_HOLD:
			break;
        case TD_DOUBLE_TAP:
			break;
        case TD_DOUBLE_HOLD:
			break;
        case TD_DOUBLE_SINGLE_TAP:
			break;
		case TD_NONE:
			break;
		case TD_TRIPLE_HOLD:
			break;
		case TD_TRIPLE_TAP:
			break;
		case TD_UNKNOWN:
			break;
    }
	layer_off(_SHRT);
    xtap_state.state = TD_NONE;
}


qk_tap_dance_action_t tap_dance_actions[] = {
   // [MAXP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, maxp_finished, maxp_reset),
	[QRYJOIN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, queryj_finished, queryj_reset),
	[OCBRCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ocbrck_finished, ocbrck_reset),
	[OCQTES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ocqts_finished, ocqts_reset),
	[PHONE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, phone_finished, phone_reset),
	[USER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, user_finished, user_reset),
	[RTST] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rtst_finished, rtst_reset),
	[XYZ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xyz_finished, xyz_reset),
};
__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void matrix_scan_user(void) {
	if (current_layer == get_highest_layer(layer_state)) {
		has_layer_changed = false;
	} else {
		has_layer_changed = true;
		current_layer = get_highest_layer(layer_state);
	if (current_layer == 0) {
		rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);
	}
	if (current_layer == 1) {
		rgb_matrix_mode(RGB_MATRIX_PIXEL_FLOW);
	}
	if (current_layer == 2) {
		rgb_matrix_mode(RGB_MATRIX_PIXEL_RAIN);
	}
	if (current_layer == 3) {
		rgb_matrix_mode(RGB_MATRIX_JELLYBEAN_RAINDROPS);
	}

  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case KC_PAS1:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("1diot1mp!"), 12);

			layer_clear();return false;}
		case KC_PAS2:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("Jump1ngJ4guar!"), 12);

			layer_clear();return false;}
		case KC_PAS3:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("K0rnyK0ala!"), 12);

			layer_clear();return false;}
		case KC_PAS4:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("L0stL3pard!"), 12);

			layer_clear();return false;}
		case KC_PAS5:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("M0rbidM0use!"), 12);

			layer_clear();return false;}
		case KC_PAS6:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("N3roticN4rwhal!"), 12);

			layer_clear();return false;}
		case KC_PAS7:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("P4leP3nda!"), 12);

			layer_clear();return false;}
		case KC_PAS8:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("R4bidR4coon!"), 12);

			layer_clear();return false;}
		case KC_PAS9:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("S1llySn4ke!"), 12);

			layer_clear();return false;}
		case KC_PAS10:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("T4ckyT1ger!"), 12);

			layer_clear();return false;}
		case KC_PAS11:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("V4liantVultur3!"), 12);

			layer_clear();return false;}
		case KC_PAS12:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("W4rmW3asel!"), 12);

			layer_clear();return false;}
		case KC_QSLT:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("SELECT\n"SS_TAP(X_TAB)), 12);
			layer_clear();return false;
			}
		case KC_LJOIN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("LEFT OUTER JOIN  ON"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);

			layer_clear();return false;}
		case KC_RJOIN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("RIGHT OUTER JOIN "), 12);

			layer_clear();return false;}
		case KC_QINS:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("IN (, )" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)), 12);

			layer_clear();return false;}
		case KC_QUPD:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("UPDATE tbl SET "), 12);

			layer_clear();return false;}
		case KC_QFRM:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("FROM \n"SS_TAP(X_TAB)), 12);

			layer_clear();return false;}
		case KC_QDEL:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("DELETE \n"), 12);

			layer_clear();return false;}
		case KC_QCNT:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("COUNT(*) as cnt, \n"), 12);

			layer_clear();return false;}
		case KC_QGPB:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("GROUP BY \n" SS_TAP(X_TAB)), 12);

			layer_clear();return false;}
		case KC_QORD:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("ORDER BY \n"SS_TAP(X_TAB)), 12);

			layer_clear();return false;}
		case KC_QLIK:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("LIKE '%%'"SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);

			layer_clear();return false;}
		case KC_QHAV:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("HAVING \n"SS_TAP(X_LEFT)), 12);

			layer_clear();return false;}
		case KC_QWHR:
		if (record->event.pressed) {
			send_string_with_delay_P(PSTR("WHERE \n"SS_TAP(X_LEFT)), 12);

			layer_clear();return false;}
		case KC_BTWN:
		if (record->event.pressed) {
			send_string_with_delay_P(PSTR("BETWEEN  AND"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);

			layer_clear();return false;}
		case KC_CMAL:
		if (record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_DOWN(X_LCTRL) SS_DOWN(X_LSHIFT) SS_TAP(X_LEFT) SS_UP(X_LCTRL) SS_UP(X_LSHIFT) SS_TAP(X_LEFT) "," SS_TAP(X_UP)SS_DOWN(X_LCTRL) SS_DOWN(X_LSHIFT) SS_TAP(X_RIGHT) SS_UP(X_LCTRL) SS_UP(X_LSHIFT) SS_TAP(X_RIGHT)), 12);

			layer_clear();return false;}
		case KC_FRMT:
		if (record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_DOWN(X_LCTRL) SS_DOWN(X_LSHIFT) "f" SS_UP(X_LCTRL) SS_UP(X_LSHIFT)), 12);

			layer_clear();return false;}
		case KC_EXCU:
		if (record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_DOWN(X_LCTRL)SS_TAP(X_ENTER) SS_UP(X_LCTRL)), 12);

			layer_clear();return false;}
		case KC_EXPD:
		if (record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_DOWN(X_LCTRL) SS_TAP(X_SPACE) SS_UP(X_LCTRL)), 12);

			layer_clear();return false;}
		case KC_QTOP:
		if (record->event.pressed) {
			send_string_with_delay_P(PSTR("TOP 100 * "), 12);
			layer_clear();return false;}
		case KC_CLRL:
		if (record->event.pressed) {
			layer_clear();return false;}
		case KC_PLYR:
		if (record->event.pressed) {
			send_string_with_delay_P(PSTR("_QRY \n"), 12);
			send_string_with_delay_P(PSTR("_AUL \n"), 12);
			send_string_with_delay_P(PSTR("_BIAP \n"), 12);
			send_string_with_delay_P(PSTR("_DW \n"), 12);
			send_string_with_delay_P(PSTR("_FID \n"), 12);
			send_string_with_delay_P(PSTR("_MX \n"), 12);
			send_string_with_delay_P(PSTR("_REV \n"), 12);
			send_string_with_delay_P(PSTR("_SHRT \n"), 12);
			send_string_with_delay_P(PSTR("_USW \n"), 12);

			layer_clear();return false;}
		case KC_QLST:
		if (record->event.pressed) {
			send_string_with_delay_P(PSTR("P1 - P3 CNT \n"), 12);
			send_string_with_delay_P(PSTR("P4 - P6 CLMS \n"), 12);
			send_string_with_delay_P(PSTR("P7 - P9 OTHR \n"), 12);

			layer_clear();return false;}
		case KC_SYSS:
		if (record->event.pressed) {
			  send_string_with_delay_P(PSTR("SELECT TABLE_SCHEMA, TABLE_NAME, COLUMN_NAME, ORDINAL_POSITION, \n"), 12);
			  send_string_with_delay_P(PSTR("DATA_TYPE, CHARACTER_MAXIMUM_LENGTH, NUMERIC_PRECISION, NUMERIC_SCALE \n"), 12);
			  send_string_with_delay_P(PSTR("FROM [INFORMATION_SCHEMA].[COLUMNS] \n"), 12);
			  send_string_with_delay_P(PSTR("WHERE COLUMN_NAME like '%%' \n"), 12);
			  send_string_with_delay_P(PSTR("AND TABLE_NAME like '%%' \n"), 12);
			  send_string_with_delay_P(PSTR("AND TABLE_SCHEMA like '%%' \n"), 12);

			layer_clear();return false;}
		case KC_DBO:
		if (record->event.pressed) {
			  send_string_with_delay_P(PSTR("DBO."), 12);

			layer_clear();return false;}
		case KC_QS36F:
		if (record->event.pressed) {
			  send_string_with_delay_P(PSTR("QS36F."), 12);

			layer_clear();return false;}
		case KC_TBEN:
		if (record->event.pressed) {
			  send_string_with_delay_P(PSTR(SS_DOWN(X_TAB) SS_TAP(X_ENTER) SS_UP(X_TAB) ), 12);

			layer_clear();return false;}
		case KC_SYSA:
		if (record->event.pressed) {
			  send_string_with_delay_P(PSTR("SELECT tab.TABLE_SCHEMA, tab.TABLE_NAME, col.COLUMN_NAME, col.ORDINAL_POSITION, \n"), 12);
			  send_string_with_delay_P(PSTR("col.DATA_TYPE, col.LENGTH, col.NUMERIC_SCALE \n"), 12);
			  send_string_with_delay_P(PSTR("FROM QSYS2.SYSTABLES tab \n"), 12);
			  send_string_with_delay_P(PSTR("INNER JOIN QSYS2.SYSCOLUMNS col \n"), 12);
			  send_string_with_delay_P(PSTR("ON tab.TABLE_NAME = col.TABLE_NAME \n"), 12);
			  send_string_with_delay_P(PSTR("WHERE col.COLUMN_NAME like '%%' \n"), 12);
			  send_string_with_delay_P(PSTR("AND tab.TABLE_NAME like '%%' \n"), 12);
			  send_string_with_delay_P(PSTR("AND tab.TABLE_SCHEMA like '%%' \n"), 12);

			layer_clear();return false;}
		case KC_ICRP:
		if (record->event.pressed) {
			  send_string_with_delay_P(PSTR("."), 12);
			layer_clear();
			return false;}
		case KC_VTSI:
		if (record->event.pressed) {
			  send_string_with_delay_P(PSTR("VTSINT."), 12);
			layer_clear();
			return false;}
	}
	//return process_record_keymap(keycode, record) && process_record_secrets(keycode, record);
	return true;
	}
