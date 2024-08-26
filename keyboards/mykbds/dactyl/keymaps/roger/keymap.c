#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "features/achordion.h"
#include "features/layer_lock.h"

// Defines names for use in layer keycodes and the keymap5
enum layer_names {
    _QWERTY = 0,
	_SYM,
    _FUNC,
	_SQL,
	_PSS
};


#define ZCTRZ LT(0,KC_Z)
#define XCTRX LT(0,KC_X)
#define CCTRC LT(0,KC_C)
#define VCTRV LT(0,KC_V)
#define ACTRA LT(0,KC_A)
#define CMALT LT(0,KC_COMM)
#define DOTGT LT(0,KC_DOT)
#define SCLCL LT(0,KC_SCLN)
#define OCPAR LT(0,KC_9) //( and )
#define OCBRK LT(0,KC_8) //[ and ]
#define OCBRC LT(0,KC_0) //{ and }
#define QTDQT LT(0,KC_7) //single quote double quote
#define PLSMN LT(0,KC_6) //plus minus
#define EQNEQ LT(0,KC_5) //equal not equal
#define SLBSL LT(0,KC_4) //slash backslash
#define QSUDR LT(0,KC_3) //question underline
#define EXCPI LT(0,KC_2) //eclamation pipe
#define GRVTI LT(0,KC_1) //grave tilda
#define ASTPC LT(0,KC_W) //Asterisk percent

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
[_QWERTY] = LAYOUT_split_3x6_3(
ASTPC,  KC_Q, LALT_T(KC_W), LCTL_T(KC_E), LSFT_T(KC_R),        KC_T,              KC_Y, SFT_T(KC_U), RCTL_T(KC_I), RALT_T(KC_O),  KC_P, QTDQT, //MY_QTMCR,LT(0,KC_ESC)
SLBSL, ACTRA,         KC_S,         KC_D,         KC_F,        KC_G,              KC_H,        KC_J,         KC_K,         KC_L, SCLCL, PLSMN, //MY_OPMCR, //LT(0,KC_QUOT),LT(0,KC_Q)
EXCPI, ZCTRZ,        XCTRX,        CCTRC,        VCTRV,        KC_B,              KC_N,        KC_M,        CMALT,        DOTGT, QSUDR, EQNEQ,// MY_EQMCR, //LT(0,KC_BSLS),S(KC_SLSH),LT(0,KC_W),MY_EXMCR
                               MO(_FUNC),       KC_SPC,    MO(_SYM),          MO(_SYM),      KC_ENT,     MO(_FUNC)
),
[_SYM] = LAYOUT_split_3x6_3(
QK_UNDERGLOW_TOGGLE,     KC_F1,     KC_F2,     KC_F3,    KC_F4,     KC_F5,        KC_F6,         KC_F7,       KC_F8,       KC_F9,       KC_F10,      _______, //LT(0,KC_PPLS),
QK_UNDERGLOW_HUE_UP,      KC_1,      KC_2,      KC_3,     KC_4,      KC_5,         KC_6,          KC_7,        KC_8,        KC_9,         KC_0,      _______,
QK_UNDERGLOW_MODE_NEXT,     GRVTI,   S(KC_2),   S(KC_3),   S(KC_4),  _______,      S(KC_6),       S(KC_7),  LT(0,KC_9),  LT(0,KC_0),   LT(0,KC_8),      _______,
                               _______,  LLOCK,    _______,                      _______,     LLOCK,   _______
),
[_FUNC] = LAYOUT_split_3x6_3(
 _______,   KC_BTN1,     MS_SFTLC,      _______,      _______,          KC_MUTE,        KC_INS,       _______,     _______,  _______,    XXXXXXX,     XXXXXXX,
 _______,  MS_CTLLC,LT(0,KC_BTN1),      KC_MS_U,      KC_BTN2,          KC_VOLU,       KC_HOME,       XXXXXXX,       KC_UP,  XXXXXXX,    KC_PGUP,     XXXXXXX,
 _______,   _______,      KC_MS_L,      KC_MS_D,      KC_MS_R,          KC_VOLD,        KC_END,       KC_LEFT,     KC_DOWN, KC_RIGHT,    KC_PGDN,     XXXXXXX,
                                _______,      LLOCK ,    _______ ,          _______ ,  LLOCK ,  _______
),
[_SQL] = LAYOUT_split_3x6_3(
     MY_SLMC1,          MY_SCHMC1,    MY_SCHMC4,        MY_WHMCR,     MY_JNMCR,            _______,     MY_GBMCR,    MY_AGMCR,  MY_SYSMCR,   MY_DCMCR,    _______,   _______,
     MY_SLMC2,			MY_SCHMC2,      _______,         _______,      _______,            _______,      _______,     _______,    _______,   _______,     _______,   _______,
  LT(0,MY_WQ),          MY_SCHMC3,      _______,         _______,      _______,            _______,      _______,     _______,    _______,   _______,     _______,   _______,
                                       _______, QK_REP, _______,                                _______,  QK_REP,  _______
    ),
[_PSS] = LAYOUT_split_3x6_3(
XXXXXXX,                   MY_17,    MY_23,     MY_5,        MY_18,              MY_20,            MY_25,         MY_21,       MY_9,    MY_15,       MY_16,  XXXXXXX,
XXXXXXX,				    MY_1,    MY_19,     MY_4,         MY_6,               MY_7,             MY_8,         MY_10,      MY_11,    MY_12,       MY_29,  XXXXXXX,
XXXXXXX,                   MY_26,    MY_24,     MY_3,        MY_22,               MY_2,            MY_14,         MY_13,      MY_27,    MY_28,       MY_30,  XXXXXXX,
                               _______, XXXXXXX, XXXXXXX,           XXXXXXX,  XXXXXXX,  _______
)
};
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(KC_W):
            return TAPPING_TERM + 70;
        case RALT_T(KC_O):
            return TAPPING_TERM + 70;
        case LT(0,KC_A):
            return TAPPING_TERM + 170;
        case LT(0,KC_Z):
            return TAPPING_TERM + 170;
        case LT(0,KC_X):
            return TAPPING_TERM + 170;
        case LT(0,KC_C):
            return TAPPING_TERM + 170;
        default:
            return TAPPING_TERM;
    }
}


const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}
);
const rgblight_segment_t PROGMEM my_sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_func_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_sql_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_pss_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM _yes_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_GREEN} );
const rgblight_segment_t PROGMEM _no_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_RED} );


__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  layer_clear();
  return true;
}

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_qwerty_layer,//
    my_sym_layer,    // Overrides caps lock layer
    my_func_layer,    // Overrides other layers
    my_sql_layer,     // Overrides other layers
    my_pss_layer,     // Overrides other layers
    _yes_layer,
    _no_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

//bool led_update_user(led_t led_state) {
//    rgblight_set_layer_state(0, led_state.caps_lock);
//    return true;
//}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(2, layer_state_cmp(state, _FUNC));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SQL));
    rgblight_set_layer_state(4, layer_state_cmp(state, _PSS));
    return state;
}

void matrix_scan_user(void) {
  achordion_task();
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
        if (!process_achordion(keycode, record)) { return false; }
        if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
        switch (keycode) {
              case MO(_SYM):
                    if (record->event.pressed) {
                        layer_on(_SYM);
                        update_tri_layer(_SYM, _FUNC, _PSS);
                    } else {
                        layer_off(_SYM);
                        update_tri_layer(_SYM, _FUNC, _PSS);
                    }
                    return false;
                case MO(_FUNC):
                    if (record->event.pressed) {
                        layer_on(_FUNC);
                        update_tri_layer(_SYM, _FUNC, _PSS);
                    } else {
                        layer_off(_FUNC);
                        update_tri_layer(_SYM, _FUNC, _PSS);
                    }
                    return false;
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
            /*
          case MY_OPMCR:
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
                    if(!(mod_state & MOD_MASK_SHIFT) && !(mod_state & MOD_MASK_CTRL)){
		            send_string_with_delay_P(PSTR("+"), 10);
                    }
                    if((mod_state & MOD_MASK_SHIFT) && !(mod_state & MOD_MASK_CTRL)){
                      del_mods(MOD_MASK_SHIFT);
                      send_string_with_delay_P(PSTR("-"), 10);
                    }
                    if((mod_state & MOD_MASK_CTRL) && !(mod_state & MOD_MASK_SHIFT)){
                      del_mods(MOD_MASK_CTRL);
                      send_string_with_delay_P(PSTR("*"), 10);
                     // add_mods(MOD_MASK_CTRL);
                    }
                    if((mod_state & MOD_MASK_CTRL) && (mod_state & MOD_MASK_SHIFT)){
                      del_mods(MOD_MASK_CTRL);
                      del_mods(MOD_MASK_SHIFT);
                      send_string_with_delay_P(PSTR("\\"), 10);
                      add_mods(MOD_MASK_CTRL);
                      add_mods(MOD_MASK_SHIFT);
                    }
                    }
                    else {
                    clear_mods();
                    }
                   break;
          case MY_EQMCR:
                if (record->event.pressed) {
                    if(!(mod_state & MOD_MASK_SHIFT) && !(mod_state & MOD_MASK_CTRL)){
		            send_string_with_delay_P(PSTR("="), 10);
                    }
                    if((mod_state & MOD_MASK_SHIFT) && !(mod_state & MOD_MASK_CTRL)){
                      del_mods(MOD_MASK_SHIFT);
                      send_string_with_delay_P(PSTR("!="), 10);
                    }
                    if((mod_state & MOD_MASK_CTRL) && !(mod_state & MOD_MASK_SHIFT)){
                      del_mods(MOD_MASK_CTRL);
                      send_string_with_delay_P(PSTR("<="), 10);
                    }
                    if((mod_state & MOD_MASK_CTRL) && (mod_state & MOD_MASK_SHIFT)){
                      del_mods(MOD_MASK_CTRL);
                      del_mods(MOD_MASK_SHIFT);
                      send_string_with_delay_P(PSTR(">="), 10);
                    }
                }
                else {
                    clear_mods();
                    }
                   break;
         case MY_EXMCR:
                // MY_MACRO is being used normally.?_
                if (record->event.pressed) {
                 if(!(mod_state & MOD_MASK_SHIFT) && !(mod_state & MOD_MASK_CTRL)){
		            send_string_with_delay_P(PSTR("?"), 10);
                    }
                    if((mod_state & MOD_MASK_SHIFT) && !(mod_state & MOD_MASK_CTRL)){
                      del_mods(MOD_MASK_SHIFT);
                      send_string_with_delay_P(PSTR("_"), 10);
                    }
                    if((mod_state & MOD_MASK_CTRL) && !(mod_state & MOD_MASK_SHIFT)){
                      del_mods(MOD_MASK_CTRL);
                      send_string_with_delay_P(PSTR("|"), 10);
                      add_mods(MOD_MASK_CTRL);
                    }
                    if((mod_state & MOD_MASK_CTRL) && (mod_state & MOD_MASK_SHIFT)){
                      del_mods(MOD_MASK_CTRL);
                      del_mods(MOD_MASK_SHIFT);
                      send_string_with_delay_P(PSTR("/"), 10);
                      add_mods(MOD_MASK_CTRL);
                      add_mods(MOD_MASK_SHIFT);
                    }
            }
                else {
                    clear_mods();
                    }
                   break;*/
          case MY_DCMCR:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
			            send_string_with_delay_P(PSTR(SS_TAP(X_LEFT)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)"DECLARE @str VARCHAR(50) = ''"SS_TAP(X_LEFT)), 10);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
		            send_string_with_delay_P(PSTR("\nDECLARE @int INT = "), 10);
                }
            }
            return false;
        case MY_SYSMCR:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
			        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_UP(X_LSFT)), 10);
                    send_string_with_delay_P(PSTR("SELECT tab.TABLE_SCHEMA, tab.TABLE_NAME, col.COLUMN_NAME, col.ORDINAL_POSITION, \n"), 10);
                    send_string_with_delay_P(PSTR("col.DATA_TYPE, col.LENGTH, col.NUMERIC_SCALE \n"), 10);
                    send_string_with_delay_P(PSTR("FROM QSYS2.SYSTABLES tab \n"), 10);
                    send_string_with_delay_P(PSTR("INNER JOIN QSYS2.SYSCOLUMNS col \n"), 10);
                    send_string_with_delay_P(PSTR("ON tab.TABLE_NAME = col.TABLE_NAME \n"), 10);
                    send_string_with_delay_P(PSTR("WHERE col.COLUMN_NAME like '%%' \n"), 10);
                    send_string_with_delay_P(PSTR("AND tab.TABLE_NAME like '%%' \n"), 10);
                    send_string_with_delay_P(PSTR("AND tab.TABLE_SCHEMA like '%%' \n"), 10);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
                    send_string_with_delay_P(PSTR("SELECT TABLE_SCHEMA, TABLE_NAME, COLUMN_NAME, ORDINAL_POSITION, \n"), 10);
                    send_string_with_delay_P(PSTR("DATA_TYPE, CHARACTER_MAXIMUM_LENGTH, NUMERIC_PRECISION, NUMERIC_SCALE \n"), 10);
                    send_string_with_delay_P(PSTR("FROM [INFORMATION_SCHEMA].[COLUMNS] \n"), 10);
                    send_string_with_delay_P(PSTR("WHERE COLUMN_NAME like '%%' \n"), 10);
                    send_string_with_delay_P(PSTR("AND TABLE_NAME like '%%' \n"), 10);
                    send_string_with_delay_P(PSTR("AND TABLE_SCHEMA like '%%' \n"), 10);
                }
            }
            return false;
          case MY_GBMCR:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" GROUP BY \n"),10);
                    }
                    if (get_repeat_key_count() == 2){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" HAVING \n"),10);
                    }
                    if (get_repeat_key_count() == 3){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" ORDER BY "),10);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
			        send_string_with_delay_P(PSTR("\n ORDER BY "), 10);
                }
            }
            return false;
          case MY_SCHMC1:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" QSYS2. ,"),10);
                    }
                    if (get_repeat_key_count() == 2){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" SYSIBM. ,"),10);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
			        send_string_with_delay_P(PSTR("\n QS36F. ,"), 10);
                }
            }
            return false;
          case MY_SCHMC2:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" PROTBLPD. ,"),10);
                    }
                    if (get_repeat_key_count() == 2){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" PROQUERY. ,"),10);
                    }
                    if (get_repeat_key_count() == 3){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" QSYS2. ,"),10);
                    }
                    if (get_repeat_key_count() == 4){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" SYSIBM. ,"),10);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
			        send_string_with_delay_P(PSTR("\n PRODTAPD. ,"), 10);
                }
            }
            return false;
          case MY_SCHMC4:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" QS36F. ,"),10);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
			        send_string_with_delay_P(PSTR("\n DBO. ,"), 10);
                }
            }
            return false;
          case MY_SCHMC3:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" ICORPD. ,"),10);
                    }
                    if (get_repeat_key_count() == 2){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" ICORPDCD. ,"),10);
                    }
                    if (get_repeat_key_count() == 3){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" QSYS2. ,"),10);
                    }
                    if (get_repeat_key_count() == 4){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" SYSIBM. ,"),10);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
			        send_string_with_delay_P(PSTR("\n VTSINT. ,"), 10);
                }
            }
            return false;
          case MY_AGMCR:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
			        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_END)SS_UP(X_LSFT)" "SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT) ", AVG() as AvgOf "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);
                    }
                    if (get_repeat_key_count() == 2){
			        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_END)SS_UP(X_LSFT)" "SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT) ", MAX() as MaxOf "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);
                    }
                    if (get_repeat_key_count() == 3){
			        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_END)SS_UP(X_LSFT)" "SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT) ", MIN() as MinOf "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
			        send_string_with_delay_P(PSTR(" COUNT(*) as CntOf "), 10);
                }
            }
            return false;
         /* case MY_QTMCR:
                if (record->event.pressed) {
                  if(!(mod_state & MOD_MASK_SHIFT) && !(mod_state & MOD_MASK_CTRL)){
		            send_string_with_delay_P(PSTR("'"), 10);
                    }
                    if((mod_state & MOD_MASK_SHIFT) && !(mod_state & MOD_MASK_CTRL)){
                      del_mods(MOD_MASK_SHIFT);
                      send_string_with_delay_P(PSTR("\""), 10);
                    }
                    if((mod_state & MOD_MASK_CTRL) && !(mod_state & MOD_MASK_SHIFT)){
                      del_mods(MOD_MASK_CTRL);
                      send_string_with_delay_P(PSTR("%"), 10);
                    }
                    if((mod_state & MOD_MASK_CTRL) && (mod_state & MOD_MASK_SHIFT)){
                      del_mods(MOD_MASK_CTRL);
                      del_mods(MOD_MASK_SHIFT);
                      send_string_with_delay_P(PSTR("%%"), 10);
                    }
                }
            return false;
*/

          case MY_SLMC1:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                            send_string_with_delay_P(PSTR("*\n"SS_TAP(X_TAB)),10);//send_string_with_delay_P(PSTR(SS_TAP(X_LEFT)), 15);
                    }
                    if (get_repeat_key_count() == 2){
                            send_string_with_delay_P(PSTR("FROM\n\n"SS_TAP(X_TAB)),10);//send_string_with_delay_P(PSTR(SS_TAP(X_LEFT)), 15);
                    }
                    if (get_repeat_key_count() == 3){
                            send_string_with_delay_P(PSTR("WHERE\n"SS_TAP(X_TAB)),10);//send_string_with_delay_P(PSTR(SS_TAP(X_LEFT)), 15);
                    }
                    if (get_repeat_key_count() == 4){
                            send_string_with_delay_P(PSTR("ORDER BY 1\n"SS_TAP(X_TAB)),10);//send_string_with_delay_P(PSTR(SS_TAP(X_LEFT)), 15);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
                        send_string_with_delay_P(PSTR("SELECT\n"SS_TAP(X_TAB)),10);
                }
            }
            return false;
          case MY_SLMC2:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                            send_string_with_delay_P(PSTR("COUNT(*) as cnt\n"SS_TAP(X_TAB)),10);//send_string_with_delay_P(PSTR(SS_TAP(X_LEFT)), 15);
                    }
                    if (get_repeat_key_count() == 2){
                            send_string_with_delay_P(PSTR("FROM\n\n"SS_TAP(X_TAB)),10);//send_string_with_delay_P(PSTR(SS_TAP(X_LEFT)), 15);
                    }
                    if (get_repeat_key_count() == 3){
                            send_string_with_delay_P(PSTR(" WHERE \n"SS_TAP(X_TAB)"GROUP BY\n"SS_TAP(X_TAB)),10);//send_string_with_delay_P(PSTR(SS_TAP(X_LEFT)), 15);
                    }
                    if (get_repeat_key_count() == 4){
                            send_string_with_delay_P(PSTR("HAVING\n"SS_TAP(X_TAB)"ORDER BY 1\n"SS_TAP(X_TAB)),10);//send_string_with_delay_P(PSTR(SS_TAP(X_LEFT)), 15);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
                        send_string_with_delay_P(PSTR("SELECT\n"SS_TAP(X_TAB)),10);
                }
            }
            return false;
          case MY_JNMCR:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)"LEFT OUTER JOIN "),10);
                    }
                    if (get_repeat_key_count() == 2){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)"FULL OUTER JOIN "),10);
                    }
                    if (get_repeat_key_count() == 3){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)"CROSS JOIN "),10);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
                    send_string_with_delay_P(PSTR("\nINNER JOIN  AS B ON"), 10);
                }
            }
            return false;
          case MY_WHMCR:
            if (get_repeat_key_count() > 0) {
                // MY_MACRO is being repeated!
                if (record->event.pressed) {
                    if (get_repeat_key_count() == 1){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" != "),10);
                    }
                    if (get_repeat_key_count() == 2){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" Like '%' "),10);
                    }
                    if (get_repeat_key_count() == 3){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" IS NULL "),10);
                    }
                    if (get_repeat_key_count() == 4){
                        send_string_with_delay_P(PSTR(SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)" BETWEEN AND "),10);
                    }
                }
            } else {
                // MY_MACRO is being used normally.
                if (record->event.pressed) {
                   send_string_with_delay_P(PSTR("WHERE \n"), 10);
                   send_string_with_delay_P(PSTR(" ="), 10);
                }
            }
            return false;
        //case MY_SQ:
		//	if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" '' "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);git fetch upstream
         //   }
		//	return false;
        //case MY_DQ:
		//	if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" \"\" "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);
         //   }
		//	return false;
        //case MY_UP:
		//	if (record->event.pressed) {
         //   send_string_with_delay_P(PSTR("UPDATE A SET  =  FROM  as A WHERE A.  ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
        //   }
		//	return false;
        //case MY_IN:
		//	if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" IN (,) "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
         //   }
		//	return false;
        //case MY_ISN:
		//	if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" IS NULL "), 12);
         //   }
		//	return false;
        //case MY_OB:
		//	if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" ORDER BY "), 12);
         //   }
         		//	return false;
      //case MY_WQ:
		//	if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR(SS_TAP(X_HOME)"'"SS_TAP(X_END)"',"SS_TAP(X_DOWN)), 12);
        //    }
		//	return false;
      //case MY_SYS:
		//	if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR("Declare @tablename varchar(100) = ''\n"), 12);
        //    send_string_with_delay_P(PSTR("Declare @columnname varchar(100) = ''\n"), 12);
       //     send_string_with_delay_P(PSTR("SELECT\n"), 12);
       //     send_string_with_delay_P(PSTR("TABLE_SCHEMA\n"), 12);
         //   send_string_with_delay_P(PSTR(", TABLE_NAME\n"), 12);
         //   send_string_with_delay_P(PSTR(", COLUMN_NAME\n"), 12);
        //    send_string_with_delay_P(PSTR(", ORDINAL_POSITION\n"), 12);
        //    send_string_with_delay_P(PSTR(", column_Default\n"), 12);
        //    send_string_with_delay_P(PSTR(", IS_NULLABLE\n"), 12);
         //   send_string_with_delay_P(PSTR(", DATA_TYPE\n"), 12);
        //    send_string_with_delay_P(PSTR(", CHARACTER_MAXIMUM_LENGTH\n"), 12);
        //    send_string_with_delay_P(PSTR(", numeric_Scale\n"), 12);
         //   send_string_with_delay_P(PSTR(", NUMERIC_PRECISION\n"), 12);
         //   send_string_with_delay_P(PSTR(", DATETIME_PRECISION\n"), 12);
       //     send_string_with_delay_P(PSTR("FROM\n"), 12);
        //    send_string_with_delay_P(PSTR("INFORMATION_SCHEMA.COLUMNS\n"), 12);
         //   send_string_with_delay_P(PSTR("WHERE\n"), 12);
         //   send_string_with_delay_P(PSTR("TABLE_NAME LIKE '%' + @tablename + '%'\n"), 12);
          //  send_string_with_delay_P(PSTR("AND\n"), 12);
          //  send_string_with_delay_P(PSTR("COLUMN_NAME LIKE '%' + @columnname + '%'\n"), 12);
         //  send_string_with_delay_P(PSTR(""), 12);
         //   }
		//	return false;
        case GRVTI:
            if (record->tap.count && record->event.pressed) {
                send_string_with_delay_P(PSTR("`"), 10);
            } else if (record->event.pressed) {
                send_string_with_delay_P(PSTR("~"), 10);
            }
		return false;
         case EXCPI:
            if (record->tap.count && record->event.pressed) {
                send_string_with_delay_P(PSTR("!"), 10);
            } else if (record->event.pressed) {
                send_string_with_delay_P(PSTR("|"), 10);
            }
			return false;
        case QSUDR:
           if (record->tap.count && record->event.pressed) {
                send_string_with_delay_P(PSTR("?"), 10);
            } else if (record->event.pressed) {
                send_string_with_delay_P(PSTR("_"), 10);
            }
			return false;
         case SLBSL:
           if (record->tap.count && record->event.pressed) {
                send_string_with_delay_P(PSTR("/"), 10);
            } else if (record->event.pressed) {
                send_string_with_delay_P(PSTR("\\"), 10);
            }
			return false;
         case EQNEQ:
            if (record->tap.count && record->event.pressed) {
                send_string_with_delay_P(PSTR("="), 10);
            } else if (record->event.pressed) {
                  send_string_with_delay_P(PSTR("!="), 10);
            }
			return false;
        case PLSMN:
            if (record->tap.count && record->event.pressed) {
                send_string_with_delay_P(PSTR("+"), 10);
            } else if (record->event.pressed) {
                send_string_with_delay_P(PSTR("-"), 10);
            }
			return false;
         case QTDQT:
            if (record->tap.count && record->event.pressed) {
                send_string_with_delay_P(PSTR("'"), 10);
            } else if (record->event.pressed) {
                send_string_with_delay_P(PSTR("\""), 10);
            }
			return false;
         case ZCTRZ:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_Z); // Intercept tap function to send z
            } else if (record->event.pressed) {
                rgblight_blink_layer(6, 500);
                tap_code16(C(KC_Z)); // Intercept hold function to undo
            }
			return false;
         case ACTRA:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_A); // Intercept tap function to send a
            } else if (record->event.pressed) {
                rgblight_blink_layer(6, 500);
                tap_code16(C(KC_A)); // Intercept hold to select all
            }
			return false;
         case XCTRX:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_X); // Intercept tap function to send x
            } else if (record->event.pressed) {
                rgblight_blink_layer(6, 500);
                tap_code16(C(KC_X)); // Intercept hold top cut
            }
			return false;
         case CCTRC:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_C); // Intercept tap function to send c
            } else if (record->event.pressed) {
                rgblight_blink_layer(6, 500);
                tap_code16(C(KC_C)); // Intercept hold to copy
            }
			return false;
         case VCTRV:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_V); // Intercept tap function to send v
            } else if (record->event.pressed) {
                rgblight_blink_layer(6, 500);
                tap_code16(C(KC_V)); // Intercept hold function to paste
            }
			return false;
         case OCBRK:
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_LBRC)); // Intercept tap function to send 8
            } else if (record->event.pressed) {
                tap_code16(S(KC_RBRC)); // Intercept hold function to send *
                tap_code(KC_LEFT); //to move inside
            }
			return false;
         case OCPAR:
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_9)); // Intercept tap function to send 9
            } else if (record->event.pressed) {
                tap_code16(S(KC_0)); // Intercept hold function to send )
                tap_code(KC_LEFT); //to move ide
            }
			return false;
         case OCBRC:
            if (record->tap.count && record->event.pressed) {
               tap_code16(KC_LBRC); // Intercept hold function to send [
            } else if (record->event.pressed) {
                tap_code16(KC_RBRC); // Intercept hold function to send ]
                tap_code(KC_LEFT); //to move inside
            }
			return false;

         case ASTPC:
            if (record->tap.count && record->event.pressed) {
                send_string_with_delay_P(PSTR("*"), 10);
            } else if (record->event.pressed) {
                 send_string_with_delay_P(PSTR("%"), 10);
            }
			return false;
            /*
         case LT(0,KC_W):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V)); // Intercept hold function to send Paste
            } else if (record->event.pressed) {
                send_string_with_delay_P(PSTR(""SS_TAP(X_END)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LSFT)), 12);
                tap_code16(C(KC_C)); // Intercept tap function to send Copy
            }
			return false;*/
            /*
         case LT(0,KC_Q):
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C)); // Intercept tap function to send Copy
            } else if (record->event.pressed) {
                tap_code16(C(KC_X)); // Intercept hold function to send Cut
            }
			return false;
         case CMALT:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_COMM); // Intercept tap function to send ,
            } else if (record->event.pressed) {
                tap_code16(S(KC_COMM)); // Intercept hold function to send <
            }
			return false;*/
         case DOTGT:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DOT); // Intercept tap function to send .
            } else if (record->event.pressed) {
                tap_code16(S(KC_DOT)); // Intercept hold function to send >
            }
			return false;
            /*
         case LT(0,KC_BSLS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_BSLS); // Intercept tap function to send
            } else if (record->event.pressed) {
                tap_code16(KC_SLSH); // Intercept hold function to send /
            }
			return false;*/
         case SCLCL:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_SCLN); // Intercept tap function to send;
            } else if (record->event.pressed) {
                tap_code16(S(KC_SCLN)); // Intercept hold function to send :
            }
			return false;
                        /*
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
                tap_code16(KC_BSLS); // Intercept tap function to send 0 KC_BSLS
            } else if (record->event.pressed) {
                tap_code16(KC_PIPE);
            }
			return false;*/
       //case BSP_DEL:
       //     if (record->event.pressed) {
        //        saved_mods = get_mods() & MOD_MASK_SHIFT;
////
         //       if (saved_mods == MOD_MASK_SHIFT) {  // Both shifts pressed
        //            register_code(KC_DEL);
          //      } else if (saved_mods) {   // One shift pressed
          //          del_mods(saved_mods);  // Remove any Shifts present
           //         register_code(KC_DEL);
         //           add_mods(saved_mods);  // Add shifts again
          //      } else {
          //          register_code(KC_BSPC);
           //     }
         //   } else {
          //      unregister_code(KC_DEL);
         //       unregister_code(KC_BSPC);
          //  }
          //  return false;
        // case LT(0,KC_PPLS):
        //    if (record->tap.count && record->event.pressed) {
        //        tap_code16(KC_PPLS); // Intercept tap function to send +
        //    } else if (record->event.pressed) {
        //        tap_code16(KC_PMNS); // Intercept hold function to send -
        //    }
		//	return false;
         // case LT(0,KC_PAST):
         //   if (record->tap.count && record->event.pressed) {
        //        tap_code16(KC_PAST); // Intercept tap function to send *
         //   } else if (record->event.pressed) {
        //        tap_code16(KC_PSLS); // Intercept hold function to send /
        //    }
		//	return false;
        // case LT(0,KC_EQL):
         //   if (record->tap.count && record->event.pressed) {
        //        tap_code16(KC_EQL); // Intercept tap function to send =
        //    } else if (record->event.pressed) {
         //       tap_code16(S(KC_MINUS)); // Intercept hold function to send _
        //    }
		//	return false;
        // case LT(0,MY_SEL):
        //    if (record->tap.count && record->event.pressed) {
		//	send_string_with_delay_P(PSTR("SELECT\n"SS_TAP(X_TAB)"*\n"SS_TAP(X_TAB)"FROM\n"SS_TAP(X_TAB)), 12);
         //   } else if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR("SELECT\n"SS_TAP(X_TAB)"*\n"SS_TAP(X_TAB)"FROM  \n"SS_TAP(X_TAB)"WHERE  ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
         //   }
		//	return false;
        // case LT(0,MY_DECL):
         //   if (record->tap.count && record->event.pressed) {
		//	send_string_with_delay_P(PSTR("DECLARE @int INT = "), 12);
        //   } else if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR("DECLARE @str VARCHAR(50) = ''"SS_TAP(X_LEFT)), 12);
         //   }
		//	return false;
        //case LT(0,MY_WHR):
         //   if (record->tap.count && record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" WHERE  = "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
         //   } else if (record->event.pressed) {
        //    send_string_with_delay_P(PSTR(" WHERE  BETWEEN  AND "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
         //   }
		//	return false;
        // case LT(0,MY_WHRC):
         //   if (record->tap.count && record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" WHERE  = '' "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
         //   } else if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" WHERE  = \"\" "SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
         //   }
		//	return false;
        //case LT(0,MY_INC):
         //   if (record->tap.count && record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" IN ('','') "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
        //    } else if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" IN (\"\",\"\") " SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
        //    }
		//	return false;
        // case LT(0,MY_LK):
        //    if (record->tap.count && record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" LIKE '%%' "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
        //    } else if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" LIKE \"%%\" "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
         //   }
		//	return false;
        // case LT(0,MY_JN1):
        //    if (record->tap.count && record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" INNER JOIN  ON  = "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
        //    } else if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" LEFT OUTER JOIN  ON  = "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
         //   }
		//	return false;
         //case LT(0,MY_JN2):
         //   if (record->tap.count && record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" FULL OUTER JOIN  ON  = "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
         //   } else if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" CROSS JOIN "), 12);
        //    }
		//	return false;
        // case LT(0,MY_GB):
         //   if (record->tap.count && record->event.pressed) {
         //   send_string_with_delay_P(PSTR(" GROUP BY "), 12);
         //   } else if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" HAVING "), 12);
         //   }
		//	return false;
        // case LT(0,MY_AG1):
        //    if (record->tap.count && record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" COUNT(*) as CntOf "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
        //    } else if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" AVG() as AvgOf "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
        //   }
		//	return false;
        // case LT(0,MY_AG2):
        //    if (record->tap.count && record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" MAX() as MaxOf "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
        //    } else if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" MIN() as MinOf "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
        //    }
		//	return false;
         //case LT(0,MY_ISN):
         //   if (record->tap.count && record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" IS NULL "), 12);
         //   } else if (record->event.pressed) {
		//	send_string_with_delay_P(PSTR(" IS NOT NULL "), 12);
        //    }
		//	return false;
         case LT(0,MY_WQ):
            if (record->tap.count && record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_TAP(X_HOME)"'"SS_TAP(X_END)"',"SS_TAP(X_DOWN)), 10); //wrap a line in single quotes
            } else if (record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_TAP(X_HOME)"\""SS_TAP(X_END)"\","SS_TAP(X_DOWN)), 10); //wrap a line in double quotes
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

