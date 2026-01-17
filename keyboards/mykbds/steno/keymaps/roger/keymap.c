#include QMK_KEYBOARD_H
#include "keymap_steno.h"

#define _BASE 0

enum _layers {
	_QWERTY,
    _PLOVER
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
	PLOVER,  
	//EXT_PLV
};


#define ST_BOLT QK_STENO_BOLT
#define ST_GEM  QK_STENO_GEMINI


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_steno(
  PLOVER, 
  KC_1,  KC_2,   KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0 ,
  KC_Q,  KC_W,   KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P ,
  KC_Z,  KC_X,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_C,   KC_B
),
[_PLOVER] = LAYOUT_steno(
  STN_NUM, 
  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR ,
  STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR ,
  STN_A,    STN_O,   KC_NO,   KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,   STN_E,   STN_U
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case PLOVER:
     if (!record->event.pressed) {
        layer_on(_PLOVER);
      }
	  return false;
      break;
//	case EXT_PLV:
//      if (record->event.pressed) {
 //       layer_off(_PLOVER);
 //     }
//      return false;
//      break;
  }
  return true;
}

