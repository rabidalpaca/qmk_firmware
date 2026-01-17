#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "features/layer_lock.h"

// Defines names for use in layer keycodes and the keymap5
enum layer_names {
    _QWERTY = 0,
	_SYM,
    _FUNC,
	_PSS,
	_SQL
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
}

td_tap_t;
enum {
    MY_SYSQ, // Our custom tap dance key; add any other tap dance keys to this enum
    MY_FUPS
};

// Declare the functions to be used with your tap dance key(=)

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void ss_finished(tap_dance_state_t *state, void *user_data);
void ss_reset(tap_dance_state_t *state, void *user_data);
void fp_finished(tap_dance_state_t *state, void *user_data);
void fp_reset(tap_dance_state_t *state, void *user_data);


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
#define MY_31 KC_SECRET_31
#define MY_32 KC_SECRET_32
#define MY_33 KC_SECRET_33
#define MY_34 KC_SECRET_34
#define MY_35 KC_SECRET_35
#define MY_36 KC_SECRET_36

uint8_t mod_state;
bool shifted;
bool controled;

static uint16_t key_timer; // timer to track the last keyboard activity
static void refresh_rgb(void); // refreshes the activity timer and RGB, invoke whenever activity happens
static void check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
bool is_rgb_timeout = false; // store if RGB has timed out or not in a boolean

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_split_3x6_3(
LT(0,KC_C),         LGUI_T(KC_Q), LALT_T(KC_W), LCTL_T(KC_E), LSFT_T(KC_R),   LT(_SQL,KC_T),    LT(_SQL,KC_Y),  LSFT_T(KC_U), RCTL_T(KC_I), RALT_T(KC_O),       RGUI_T(KC_P),    MY_QTMCR,
LT(0,KC_A),			        KC_A,         KC_S,         KC_D,         KC_F,      LT(1,KC_G),       LT(1,KC_H),          KC_J,         KC_K,         KC_L,      LT(0,KC_SCLN),    MY_OPMCR, //LT(0,KC_QUOT),
LT(0,KC_V),                 KC_Z,         KC_X,         KC_C,         KC_V,      LT(2,KC_B),       LT(2,KC_N),          KC_M,LT(0,KC_COMM), LT(0,KC_DOT),           MY_EXMCR,    MY_EQMCR, //LT(0,KC_BSLS),S(KC_SLSH)
                                      MO(_PSS),       KC_SPC,       KC_SPC,          KC_ENT,          QK_AREP,     LLOCK
),
[_SYM] = LAYOUT_split_3x6_3(
LT(0,KC_GRAVE),     KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,        KC_F6,         KC_F7,       KC_F8,     KC_F9,       KC_F10,         _______, //LT(0,KC_PPLS),
    LT(0,KC_P),LT(0,KC_1),LT(0,KC_2),LT(0,KC_3),LT(0,KC_4),LT(0,KC_5),   LT(0,KC_6),    LT(0,KC_7),  LT(0,KC_8),LT(0,KC_9),   LT(0,KC_0),         _______,
       RGB_M_TW,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,      XXXXXXX,       XXXXXXX,     XXXXXXX,   XXXXXXX,      XXXXXXX,         _______,
                               _______,  _______,    _______,                      _______,     _______,   _______
),

[_FUNC] = LAYOUT_split_3x6_3(
 _______,   KC_BTN1,     MS_SFTLC,      _______,      _______,          KC_MUTE,        KC_INS,       _______,     _______,  _______,    XXXXXXX,     XXXXXXX,
 _______,  MS_CTLLC,LT(0,KC_BTN1),      KC_WH_U,      KC_BTN2,          KC_VOLU,       KC_HOME,       XXXXXXX,       KC_UP,  XXXXXXX,    KC_PGUP,     XXXXXXX,
 _______,   XXXXXXX,      KC_WH_L,      KC_WH_D,      KC_WH_R,          KC_VOLD,        KC_END,       KC_LEFT,     KC_DOWN, KC_RIGHT,    KC_PGDN,     XXXXXXX,
                                _______,      _______ ,    _______ ,          _______ ,  _______ ,  _______
),
[_PSS] = LAYOUT_split_3x6_3(
XXXXXXX,                   MY_17,    MY_23,     MY_5,        MY_18,              MY_20,            MY_25,         MY_21,       MY_9,    MY_15,       MY_16,  XXXXXXX,
XXXXXXX,				    MY_1,    MY_19,     MY_4,         MY_6,               MY_7,             MY_8,         MY_10,      MY_11,    MY_12,       MY_29,  XXXXXXX,
XXXXXXX,                   MY_26,    MY_24,     MY_3,        MY_22,               MY_2,            MY_14,         MY_13,      MY_27,    MY_28,       MY_30,  XXXXXXX,
                               _______, XXXXXXX, XXXXXXX,           XXXXXXX,  XXXXXXX,  _______
),
[_SQL] = LAYOUT_split_3x6_3(
      _______,           _______,      _______,         _______,      _______,            _______,      _______,       _______,    _______,  _______,     _______,   _______,
  LT(0,MY_WQ),			MY_SLMCR,    MY_SCHMCR,        MY_WHMCR,     MY_JNMCR,            MY_GBMCR,    MY_AGMCR,     MY_SYSMCR,   MY_DCMCR,  _______,     _______,   _______,
      XXXXXXX,           XXXXXXX,      XXXXXXX,         XXXXXXX,      XXXXXXX,            XXXXXXX,      XXXXXXX,       XXXXXXX,    _______,  _______,     _______,   _______,
                                       _______, _______, _______,                                _______,  _______,  _______
    )
};

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
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        default:
            return TAPPING_TERM;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch(get_highest_layer(state)) {
  case _SQL:
    // green-ish
   rgblight_sethsv(HSV_PURPLE);
   //rgblight_mode(RGBLIGHT_MODE_TWINKLE + 1);
    break;
  case _PSS:
    // green-ish
    rgblight_sethsv(HSV_GREEN);
    //rgblight_mode(RGBLIGHT_MODE_TWINKLE + 2);
    break;
  case _SYM:
    // green-ish
    rgblight_sethsv(HSV_RED);
    //rgblight_mode(RGBLIGHT_MODE_TWINKLE + 3);
    break;
  case _FUNC:
    // green-ish
    rgblight_sethsv(HSV_MAGENTA);
    //rgblight_mode(RGBLIGHT_MODE_TWINKLE + 4);
    break;
  default:
    // Default colors
    rgblight_sethsv(HSV_BLUE);
    rgblight_mode(RGBLIGHT_MODE_TWINKLE + 2);

    break;
  }
  return state;
}

void refresh_rgb() {
  key_timer = timer_read(); // store time of last refresh
  if (is_rgb_timeout) { // only do something if rgb has timed out
    print("Activity detected, removing timeout\n");
    is_rgb_timeout = false;
    rgblight_wakeup();
  }
}

void check_rgb_timeout() {
  if (!is_rgb_timeout && timer_elapsed(key_timer) > RGBLIGHT_TIMEOUT) {
    rgblight_suspend();
    is_rgb_timeout = true;
  }
}

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  layer_clear();
  return true;
}

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        //if (!state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two Double Hold  Double Hold  Double Hold
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ss_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

static td_tap_t fp_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void ss_finished(tap_dance_state_t *state, void *user_data) {
    ss_tap_state.state = cur_dance(state);
    switch (ss_tap_state.state) {
        case TD_SINGLE_TAP:
            if(layer_state_is(_SYM))
            {layer_off(_SYM);}
            else
            {layer_on(_SYM);}
            break;
        case TD_SINGLE_HOLD:
            set_oneshot_layer(_SYM, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        case TD_DOUBLE_TAP:
            set_oneshot_layer(_SQL, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        case TD_DOUBLE_HOLD:
            set_oneshot_layer(_SQL, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            //send_string_with_delay_P(PSTR(" Double Single Tap "), 12);
            break;
        case TD_TRIPLE_TAP:
            //send_string_with_delay_P(PSTR(" Triple Tap "), 12);
            layer_clear();
            break;
        case TD_TRIPLE_HOLD:
            break;
        default:
            break;
    }
}

void fp_finished(tap_dance_state_t *state, void *user_data) {
    fp_tap_state.state = cur_dance(state);
    switch (fp_tap_state.state) {
        case TD_SINGLE_TAP:
            if(get_auto_mouse_enable()){set_auto_mouse_enable(false);layer_on(_FUNC);}else{set_auto_mouse_enable(true);layer_off(_FUNC);}
            break;
        case TD_SINGLE_HOLD:
            if(get_auto_mouse_enable()){set_auto_mouse_enable(false);layer_on(_FUNC);}else{set_auto_mouse_enable(true);layer_off(_FUNC);}
            break;
        case TD_DOUBLE_TAP:
            set_oneshot_layer(_PSS, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        case TD_DOUBLE_HOLD:
            set_oneshot_layer(_PSS, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            send_string_with_delay_P(PSTR(" Double Single Tap "), 12);
            break;
        case TD_TRIPLE_TAP:
            send_string_with_delay_P(PSTR(" Triple Tap "), 12);
            layer_clear();
            break;
        case TD_TRIPLE_HOLD:
            break;
        default:
            break;
    }
}

void ss_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    switch (ss_tap_state.state) {
        case TD_SINGLE_HOLD:
            //layer_off(_SYM);
            break;
        case TD_DOUBLE_HOLD:
            //layer_off(_SQL);
            break;
        default:
            break;
        }
    ss_tap_state.state = TD_NONE;
}

void fp_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    switch (fp_tap_state.state) {
        case TD_SINGLE_HOLD:
            layer_off(_FUNC);
            //if(get_auto_mouse_enable()){set_auto_mouse_enable(false);}else{set_auto_mouse_enable(true);}
            break;
        case TD_DOUBLE_HOLD:
            //layer_off(_PSS);
            break;
        default:
            break;
        }
    fp_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [MY_SYSQ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ss_finished, ss_reset)
    ,[MY_FUPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fp_finished, fp_reset)
};

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
    // Forget Shift on letter keys when Shift or AltGr are the only mods.
    switch (keycode) {
        case MY_WHMCR:
                   controled = 0;
                   shifted = 0;
                   mod_state = get_mods();
                   if(mod_state & MOD_MASK_CTRL){
                        controled = 1;
                        del_mods(MOD_MASK_CTRL);
                        }
                   if(mod_state & MOD_MASK_SHIFT){
                        shifted = 1;
                        del_mods(MOD_MASK_SHIFT);
                        }
            if ((*remembered_mods & ~(MOD_MASK_CS)) == 0) {
                *remembered_mods &= ~MOD_MASK_CS;
            }
            if ((*remembered_mods & ~(MOD_MASK_SHIFT)) == 0) {
                *remembered_mods &= ~MOD_MASK_SHIFT;
            }
            if ((*remembered_mods & ~(MOD_MASK_CTRL)) == 0) {
                *remembered_mods &= ~MOD_MASK_CTRL;
            }
            break;
        case MY_SCHMCR:
                   controled = 0;
                   shifted = 0;
                   mod_state = get_mods();
                   if(mod_state & MOD_MASK_CTRL){
                        controled = 1;
                        del_mods(MOD_MASK_CTRL);
                        }
                   if(mod_state & MOD_MASK_SHIFT){
                        shifted = 1;
                        del_mods(MOD_MASK_SHIFT);
                        }
            if ((*remembered_mods & ~(MOD_MASK_CS)) == 0) {
                *remembered_mods &= ~MOD_MASK_CS;
            }
            if ((*remembered_mods & ~(MOD_MASK_SHIFT)) == 0) {
                *remembered_mods &= ~MOD_MASK_SHIFT;
            }
            if ((*remembered_mods & ~(MOD_MASK_CTRL)) == 0) {
                *remembered_mods &= ~MOD_MASK_CTRL;
            }
            break;
        case MY_QTMCR:
                   controled = 0;
                   shifted = 0;
                   mod_state = get_mods();
                   if(mod_state & MOD_MASK_CTRL){
                        controled = 1;
                        del_mods(MOD_MASK_CTRL);
                        }
                   if(mod_state & MOD_MASK_SHIFT){
                        shifted = 1;
                        del_mods(MOD_MASK_SHIFT);
                        }
            if ((*remembered_mods & ~(MOD_MASK_CS)) == 0) {
                *remembered_mods &= ~MOD_MASK_CS;
            }
            if ((*remembered_mods & ~(MOD_MASK_SHIFT)) == 0) {
                *remembered_mods &= ~MOD_MASK_SHIFT;
            }
            if ((*remembered_mods & ~(MOD_MASK_CTRL)) == 0) {
                *remembered_mods &= ~MOD_MASK_CTRL;
            }
            break;
        case MY_GBMCR:
                   controled = 0;
                   shifted = 0;
                   mod_state = get_mods();
                   if(mod_state & MOD_MASK_CTRL){
                        controled = 1;
                        del_mods(MOD_MASK_CTRL);
                        }
                   if(mod_state & MOD_MASK_SHIFT){
                        shifted = 1;
                        del_mods(MOD_MASK_SHIFT);
                        }
            if ((*remembered_mods & ~(MOD_MASK_CS)) == 0) {
                *remembered_mods &= ~MOD_MASK_CS;
            }
            if ((*remembered_mods & ~(MOD_MASK_SHIFT)) == 0) {
                *remembered_mods &= ~MOD_MASK_SHIFT;
            }
            if ((*remembered_mods & ~(MOD_MASK_CTRL)) == 0) {
                *remembered_mods &= ~MOD_MASK_CTRL;
            }
            break;
        case MY_EQMCR:
                   controled = 0;
                   shifted = 0;
                   mod_state = get_mods();
                   if(mod_state & MOD_MASK_CTRL){
                        controled = 1;
                        del_mods(MOD_MASK_CTRL);
                        }
                   if(mod_state & MOD_MASK_ALT){
                        del_mods(MOD_MASK_ALT);
                        }
                   if(mod_state & MOD_MASK_SHIFT){
                        shifted = 1;
                        del_mods(MOD_MASK_SHIFT);
                        }
            if ((*remembered_mods & ~(MOD_MASK_CS)) == 0) {
                *remembered_mods &= ~MOD_MASK_CS;
            }
            if ((*remembered_mods & ~(MOD_MASK_SHIFT)) == 0) {
                *remembered_mods &= ~MOD_MASK_SHIFT;
            }
            if ((*remembered_mods & ~(MOD_MASK_CTRL)) == 0) {
                *remembered_mods &= ~MOD_MASK_CTRL;
            }
            if ((*remembered_mods & ~(MOD_MASK_ALT)) == 0) {
                *remembered_mods &= ~MOD_MASK_ALT;
            }
            break;
        case MY_EXMCR:
                   controled = 0;
                   shifted = 0;
                   mod_state = get_mods();
                   if(mod_state & MOD_MASK_CTRL){
                        controled = 1;
                        del_mods(MOD_MASK_CTRL);
                        }
                   if(mod_state & MOD_MASK_ALT){
                        del_mods(MOD_MASK_ALT);
                        }
                   if(mod_state & MOD_MASK_SHIFT){
                        shifted = 1;
                        del_mods(MOD_MASK_SHIFT);
                        }
            if ((*remembered_mods & ~(MOD_MASK_CS)) == 0) {
                *remembered_mods &= ~MOD_MASK_CS;
            }
            if ((*remembered_mods & ~(MOD_MASK_SHIFT)) == 0) {
                *remembered_mods &= ~MOD_MASK_SHIFT;
            }
            if ((*remembered_mods & ~(MOD_MASK_CTRL)) == 0) {
                *remembered_mods &= ~MOD_MASK_CTRL;
            }
            if ((*remembered_mods & ~(MOD_MASK_ALT)) == 0) {
                *remembered_mods &= ~MOD_MASK_ALT;
            }
            break;
        case MY_OPMCR:
                   controled = 0;
                   shifted = 0;
                   mod_state = get_mods();
                   if(mod_state & MOD_MASK_CTRL){
                        controled = 1;
                        del_mods(MOD_MASK_CTRL);
                        }
                   if(mod_state & MOD_MASK_ALT){
                        del_mods(MOD_MASK_ALT);
                        }
                   if(mod_state & MOD_MASK_SHIFT){
                        shifted = 1;
                        del_mods(MOD_MASK_SHIFT);
                        }
            if ((*remembered_mods & ~(MOD_MASK_CS)) == 0) {
                *remembered_mods &= ~MOD_MASK_CS;
            }
            if ((*remembered_mods & ~(MOD_MASK_SHIFT)) == 0) {
                *remembered_mods &= ~MOD_MASK_SHIFT;
            }
            if ((*remembered_mods & ~(MOD_MASK_CTRL)) == 0) {
                *remembered_mods &= ~MOD_MASK_CTRL;
            }
            if ((*remembered_mods & ~(MOD_MASK_ALT)) == 0) {
                *remembered_mods &= ~MOD_MASK_ALT;
            }
            break;
    }
    return true;
}

void housekeeping_task_user(void) {
  #ifdef RGBLIGHT_TIMEOUT
  check_rgb_timeout();
  #endif

  /* rest of the function code here */
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef RGBLIGHT_TIMEOUT
  if (record->event.pressed) refresh_rgb();
  #endif

  /* rest of the function code here */
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        static uint8_t saved_mods   = 0;
        if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
        switch (keycode) {
          case MS_SFTLC:
            if (record->event.pressed) {
                    // when keycode  is pressed
                    register_code16(LSFT(KC_BTN1));
                } else {
                    // when keycode is released
                    unregister_code16(LSFT(KC_BTN1));
                }
            break;
          case MS_CTLLC:
            if (record->event.pressed) {
                    // when keycode  is pressed
                    register_code16(LCTL(KC_BTN1));
                } else {
                    // when keycode is released
                    unregister_code16(LCTL(KC_BTN1));
                }
            break;
          case MY_OPMCR:
                if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                        tap_code(KC_BSPC);
                        if(shifted == 0 && controled == 0){
		                    send_string_with_delay_P(PSTR("*"), 15);
                        }
                        if(shifted == 1 && controled == 0){
                            send_string_with_delay_P(PSTR("/"), 15);
                        }
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
                    if(shifted == 0 && controled == 0){
		            send_string_with_delay_P(PSTR("+"), 15);
                    }
                    if(shifted == 1 && controled == 0){
                      send_string_with_delay_P(PSTR("-"), 15);
                    }
                    }
            }
            return false;
          case MY_EQMCR:
                if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                        if(shifted == 1 || controled == 1){
                        tap_code(KC_BSPC);
                        }
			            send_string_with_delay_P(PSTR("="), 12);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
                    if(shifted == 0 && controled == 0)
		            send_string_with_delay_P(PSTR("="), 15);
                    if(shifted == 1 && controled == 0){
                      send_string_with_delay_P(PSTR("!="), 15);
                    }
                    if(controled == 1 && shifted == 0){
                      send_string_with_delay_P(PSTR("<="), 15);
                    }
                    if(controled == 1 && shifted == 1){
                      send_string_with_delay_P(PSTR(">="), 15);
                    }
                }
            }
            return false;
         case MY_EXMCR:
                if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                        tap_code(KC_BSPC);
			            send_string_with_delay_P(PSTR("|"), 12);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
                    if(shifted == 0 && controled == 0)
		            send_string_with_delay_P(PSTR("?"), 15);
                    if(shifted == 1 && controled == 0){
                      send_string_with_delay_P(PSTR("/"), 15);
                    }
                    if(controled == 1 && shifted == 0){
                      send_string_with_delay_P(PSTR("\\"), 15);
                    }
                    if(controled == 1 && shifted == 1){
                      send_string_with_delay_P(PSTR("_"), 15);
                    }
                }
            }
            return false;
          case MY_DCMCR:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
			            send_string_with_delay_P(PSTR(SS_TAP(X_LEFT)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)"DECLARE @str VARCHAR(50) = ''"SS_TAP(X_LEFT)), 12);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
		            send_string_with_delay_P(PSTR("\nDECLARE @int INT = "), 15);
                }
            }
            return false;
        case MY_SYSMCR:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
			        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_UP(X_LSFT)), 15);
                    send_string_with_delay_P(PSTR("SELECT tab.TABLE_SCHEMA, tab.TABLE_NAME, col.COLUMN_NAME, col.ORDINAL_POSITION, \n"), 12);
                    send_string_with_delay_P(PSTR("col.DATA_TYPE, col.LENGTH, col.NUMERIC_SCALE \n"), 12);
                    send_string_with_delay_P(PSTR("FROM QSYS2.SYSTABLES tab \n"), 12);
                    send_string_with_delay_P(PSTR("INNER JOIN QSYS2.SYSCOLUMNS col \n"), 12);
                    send_string_with_delay_P(PSTR("ON tab.TABLE_NAME = col.TABLE_NAME \n"), 12);
                    send_string_with_delay_P(PSTR("WHERE col.COLUMN_NAME like '%%' \n"), 12);
                    send_string_with_delay_P(PSTR("AND tab.TABLE_NAME like '%%' \n"), 12);
                    send_string_with_delay_P(PSTR("AND tab.TABLE_SCHEMA like '%%' \n"), 12);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
                    send_string_with_delay_P(PSTR("SELECT TABLE_SCHEMA, TABLE_NAME, COLUMN_NAME, ORDINAL_POSITION, \n"), 12);
                    send_string_with_delay_P(PSTR("DATA_TYPE, CHARACTER_MAXIMUM_LENGTH, NUMERIC_PRECISION, NUMERIC_SCALE \n"), 12);
                    send_string_with_delay_P(PSTR("FROM [INFORMATION_SCHEMA].[COLUMNS] \n"), 12);
                    send_string_with_delay_P(PSTR("WHERE COLUMN_NAME like '%%' \n"), 12);
                    send_string_with_delay_P(PSTR("AND TABLE_NAME like '%%' \n"), 12);
                    send_string_with_delay_P(PSTR("AND TABLE_SCHEMA like '%%' \n"), 12);
                }
            }
            return false;
          case MY_GBMCR:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                        if(controled == 1){
                            send_string_with_delay_P(PSTR("\n HAVING "), 15);
                        }
                        if(shifted == 1){
                            send_string_with_delay_P(PSTR("\n ORDER BY"), 15);
                        }
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
                    if (shifted == 0 && controled == 0)
                    {
			        send_string_with_delay_P(PSTR("\n ORDER BY "), 15);
                    }
                    else
                    {
                    send_string_with_delay_P(PSTR("\n GROUP BY "), 15);
                    }
                }
            }
            return false;
          case MY_SCHMCR:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)),15);
                        if (controled == 1 && shifted == 0) //REV
                        {
                            send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_LEFT)SS_UP(X_LSFT)" ICORPD."), 15);
                        }
                        if (shifted == 1 && controled == 0) //USW
                        {
                        }
                        if (shifted == 1 && controled == 1) //MAX
                        {
			                send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_LEFT)SS_UP(X_LSFT)" PRODTAPD."), 15);
                        }
                            if (shifted == 0 && controled == 0) //MS
                        {
                            send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_LEFT)SS_UP(X_LSFT)" BI_DM_ASSETPROTECTION.DBO."), 15);
                        }
                    }
                    if (get_repeat_key_count() == 2){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)),15);
                        if (controled == 1 && shifted == 0) //REV
                            {
			                    send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_LEFT)SS_UP(X_LSFT)" VTSINT."), 15);
                            }
                        if (shifted == 1 && controled == 0) //USW
                            {
                            }
                        if (shifted == 1 && controled == 1) //MAX
                            {
			                    send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_LEFT)SS_UP(X_LSFT)" PRODTBLPD."), 15);
                            }
                            if (shifted == 0 && controled == 0) //MS
                            {
                                send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_LEFT)SS_UP(X_LSFT)" BI_DM_ASSETPROTECTION.QS36F."), 15);
                            }
                        }
                    if (get_repeat_key_count() == 3){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)),15);
                        if (controled == 1 && shifted == 0) //REV
                            {
			                    send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_LEFT)SS_UP(X_LSFT)" ICORPDCD."), 15);
                            }
                        if (shifted == 1 && controled == 0) //USW
                            {
                            }
                        if (shifted == 1 && controled == 1) //MAX
                            {
			                    send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_LEFT)SS_UP(X_LSFT)" PROQUERY."), 15);
                            }
                            if (shifted == 0 && controled == 0) //MS
                            {
                            }
                        }
                   if (get_repeat_key_count() == 4){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)),15);
                        if (controled == 1 && shifted == 0) //REV
                            {
                            }
                        if (shifted == 1 && controled == 0) //USW
                            {
                            }
                        if (shifted == 1 && controled == 1) //MAX
                            {
                            }
                            if (shifted == 0 && controled == 0) //MS
                            {
                            }
                        }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
                    send_string_with_delay_P(PSTR("\n"), 15);
                    if (controled == 1 && shifted == 0) //REV
                    {
                        send_string_with_delay_P(PSTR(" QSYS2."), 15);
                    }
                    if (shifted == 1 && controled == 0) //USW
                    {
                        send_string_with_delay_P(PSTR(" QS36F."), 15);
                    }
                    if (shifted == 1 && controled == 1) //MAX
                    {
                        send_string_with_delay_P(PSTR(" QSYS2."), 15);
                    }
                    if (shifted == 0 && controled == 0) //MS
                    {
			            send_string_with_delay_P(PSTR(" FIIDMART.DBO."), 15);
                    }
                }
            }
            return false;
          case MY_AGMCR:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
			        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)", AVG() as AvgOf "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 15);
                    }
                    if (get_repeat_key_count() == 2){
			        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)", MAX() as MaxOf "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 15);
                    }
                    if (get_repeat_key_count() == 3){
			        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)", MIN() as MinOf "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 15);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
			        send_string_with_delay_P(PSTR("/n,COUNT(*) as CntOf "), 15);
                }
            }
            return false;
          case MY_QTMCR:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                    send_string_with_delay_P(PSTR(SS_TAP(X_END)SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_TAP(X_LEFT)SS_UP(X_LSFT)SS_UP(X_LCTL)"\""), 15);
                    if(shifted == 1)
                    {
                     send_string_with_delay_P(PSTR("%"), 15);
                    }
                    if(controled == 1)
                    {
                     send_string_with_delay_P(PSTR("%%"), 15);
                    }
			        send_string_with_delay_P(PSTR("\""SS_TAP(X_LEFT)), 15);
                    if(shifted == 1 && controled == 1)
                    {
                     send_string_with_delay_P(PSTR(SS_TAP(X_LEFT)), 15);
                    }
                    }

                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
			        send_string_with_delay_P(PSTR(" '"), 15);
                    if(shifted == 1)
                    {
                     send_string_with_delay_P(PSTR("%"), 15);
                    }
                    if(controled == 1)
                    {
                     send_string_with_delay_P(PSTR("%%"), 15);
                    }
			        send_string_with_delay_P(PSTR("'"SS_TAP(X_LEFT)), 15);
                    if(shifted == 1 && controled == 1)
                    {
                     send_string_with_delay_P(PSTR(SS_TAP(X_LEFT)), 15);
                    }
                }
            }
            return false;
          case MY_SLMCR:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_UP(X_LSFT)), 15);
                        send_string_with_delay_P(PSTR("SELECT TOP 10\n"SS_TAP(X_TAB)"*\n"SS_TAP(X_TAB)"FROM\n AS A\n"SS_TAP(X_TAB)), 15);
                        }
                    if (get_repeat_key_count() == 2){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_UP(X_LSFT)), 15);
                        send_string_with_delay_P(PSTR("SELECT\n"SS_TAP(X_TAB)"*\n"SS_TAP(X_TAB)"FROM\n AS A FETCH FIRST 10 ROWS ONLY\n"SS_TAP(X_TAB)), 15);
                        }
                    if (get_repeat_key_count() == 1){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_UP(X_LSFT)), 15);
                        send_string_with_delay_P(PSTR("UPDATE A SET  =  FROM  as A WHERE A.  ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
			        send_string_with_delay_P(PSTR("SELECT\n"SS_TAP(X_TAB)"*\n"SS_TAP(X_TAB)"FROM\n  AS A"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 15);
                }
            }
            return false;
          case MY_JNMCR:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)"LEFT OUTER JOIN "),15);
                    }
                    if (get_repeat_key_count() == 2){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)"FULL OUTER JOIN "),15);
                    }
                    if (get_repeat_key_count() == 3){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)"CROSS JOIN "),15);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
                    send_string_with_delay_P(PSTR("\nINNER JOIN  AS B ON"), 15);
                }
            }
            return false;
          case MY_WHMCR:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)"WHERE  "),15);
                        if(controled == 1) {
                        send_string_with_delay_P(PSTR("NOT "), 15);
                        }
                        send_string_with_delay_P(PSTR("LIKE '%'"), 15);
                    }
                    if (get_repeat_key_count() == 2){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)"WHERE  "),15);
                        if(controled == 1) {
                        send_string_with_delay_P(PSTR("NOT "), 15);
                        }
                        send_string_with_delay_P(PSTR("IN "), 15);
                    if(shifted == 1)
                        {
                        send_string_with_delay_P(PSTR("('','')"), 15);
                        }
                        else
                        {
                        send_string_with_delay_P(PSTR("( , )"), 15);
                        }
                    }
                    if (get_repeat_key_count() == 3){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)"WHERE  IS "),15);
                        if(controled == 1) {
                        send_string_with_delay_P(PSTR("NOT "), 15);
                        }
                        send_string_with_delay_P(PSTR("NULL "), 15);
                    }
                    if (get_repeat_key_count() == 4){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)"WHERE  "),15);
                        if(controled == 1) {
                        send_string_with_delay_P(PSTR("NOT "), 15);
                        }
                        send_string_with_delay_P(PSTR("BETWEEN "), 15);
                        if (shifted == 1)
                        {
                        send_string_with_delay_P(PSTR("'' AND ''"), 15);
                        }
                        else
                        {
                        send_string_with_delay_P(PSTR(" AND "), 15);
                        }
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
                   send_string_with_delay_P(PSTR("WHERE "), 15);
                    if(controled == 1)
                    {
                    send_string_with_delay_P(PSTR("!"), 15);
                    }
                    send_string_with_delay_P(PSTR("= "), 15);
                    if(shifted == 1)
                    {
                    send_string_with_delay_P(PSTR("''"), 15);
                    }
                    else
                    {
                    send_string_with_delay_P(PSTR(""), 15);
                    }
                }
            }
            return false;
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
                tap_code(KC_LEFT); //to move ide
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
                tap_code16(C(KC_Z)); // Intercept hold function to send [
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
                tap_code16(KC_SCLN); // Intercept tap function to send;
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
         case LT(0,KC_P):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PIPE); // Intercept tap function to send 0
            } else if (record->event.pressed) {
                tap_code16(S(KC_LBRC)); // Intercept hold function to send {
                tap_code16(S(KC_RBRC)); // Intercept hold function to send }
                tap_code(KC_LEFT); //to move inside
            }
			return false;
       case BSP_DEL:
            if (record->event.pressed) {
                saved_mods = get_mods() & MOD_MASK_SHIFT;

                if (saved_mods == MOD_MASK_SHIFT) {  // Both shifts pressed
                    register_code(KC_DEL);
                } else if (saved_mods) {   // One shift pressed
                    del_mods(saved_mods);  // Remove any Shifts present
                    register_code(KC_DEL);
                    add_mods(saved_mods);  // Add shifts again
                } else {
                    register_code(KC_BSPC);
                }
            } else {
                unregister_code(KC_DEL);
                unregister_code(KC_BSPC);
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

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

// /* Then, call the above functions from QMK's built in post processing functions like so */

// /* Runs at the end of each scan loop, check if RGB timeout has occured */
// void housekeeping_task_user(void) {
//   #ifdef RGBLIGHT_TIMEOUT
//   check_rgb_timeout();
//   #endif

//   /* rest of the function code here */
// }

// /* Runs after each key press, check if activity occurred */
// void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
//   #ifdef RGBLIGHT_TIMEOUT
//   if (record->event.pressed) refresh_rgb();
//   #endif

//   /* rest of the function code here */
// }



