#include QMK_KEYBOARD_H


// Defines names for use in layer keycodes and the keymap5
enum layer_names {
    _QWERTY,
	_SYM,
	_SQLL,
    _SQL1,
    _SQL2,
    _SQL3,
    _SQL4,
    _SQL5,
    _SQL6,
// _NAV,
 //   _NUM,
	_FUN,
 //   _MEDIA,
 //   _MOUSE,
	_PSS
};

#include "g/keymap_combo.h"

/*
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
//const uint16_t PROGMEM klsemi_tab[] = {KC_K, KC_L, KC_SCLN, COMBO_ENDocx};
const uint16_t PROGMEM fg_esc[] = {KC_F, KC_G, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [DF_SPC] = COMBO(df_spc, KC_SPC),
  [JK_ENT] = COMBO(jk_ent, KC_ENT),
  [UI_BKSP] = COMBO(ui_del, KC_BSPC),
  [YU_DEL] = COMBO(yu_del, KC_DEL),
  [FG_ESC] = COMBO(fg_esc, KC_ESC),
  [HJ_TAB] = COMBO(hj_tab, KC_TAB),
[KLSEMI_TAB] = COMBO(klsemi_tab, LSFT(KC_TAB))
};



enum {
    X_IN,
	X_LIK,
	X_AGS,
	X_AGG,
	X_SEL,
	X_VAR,
//    X_PLSMNS
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
//void xplsmns_finished(qk_tap_dance_state_t *state, void *user_data);
*/

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_BLUE}       // Light 4 LEDs, starting with LED 6
);
const rgblight_segment_t PROGMEM my_sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_RED}
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_sqll_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_sql1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PURPLE},
    {4, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM my_sql2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PURPLE},
    {4, 2, HSV_RED}
);
const rgblight_segment_t PROGMEM my_sql3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PURPLE},
    {4, 3, HSV_RED}
);
const rgblight_segment_t PROGMEM my_sql4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PURPLE},
    {4, 4, HSV_RED}
);
const rgblight_segment_t PROGMEM my_sql5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PURPLE},
    {4, 5, HSV_RED}
);
const rgblight_segment_t PROGMEM my_sql6_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PURPLE},
    {4, 6, HSV_RED}
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
    my_sqll_layer,    // Overrides caps lock layer
    my_sql1_layer,
    my_sql2_layer,
    my_sql3_layer,
    my_sql4_layer,
    my_sql5_layer,
    my_sql6_layer,
    my_fun_layer,    // Overrides other layers
    my_pss_layer    // Overrides other layers
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
/*
[_QWERTY] = LAYOUT_split_3x6_3(

XXXXXXX,                    KC_Q,         KC_W,         KC_E,         KC_R,      LT(_PSS,KC_T),    LT(_PSS,KC_Y),         KC_U,         KC_I,         KC_O,            KC_P,    XXXXXXX,
XXXXXXX,			LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),      LT(_SYM,KC_G),    LT(_SYM,KC_H), RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),    XXXXXXX,
XXXXXXX,                  KC_Z,         KC_X,         KC_C,         KC_V,               KC_B,             KC_N,         KC_M,      KC_COMM,       KC_DOT,         KC_SLSH,    XXXXXXX,
                      //    MY_LKYNE, MY_LSQLS, OSL(_SYM),           OSL(_FUN),  MO(_SQL),  OSL(_PSS)
                       //KC_Q,     KC_W,     KC_E,         KC_R,      KC_T,             KC_Y,          KC_U,       KC_I''''''';;;;;
                               LT(_MEDIA,KC_ESC),LT(_MOUSE,KC_TAB),LT(_NAV,KC_SPC), LT(_SQL,KC_ENT),  LT(_NUM,KC_BSPC), LT(_FUN,KC_DEL)jjjjj=____\\%555
    ),

    [_QWERTY] = LAYOUT_split_3x6_3(
TT(_SYM),                    KC_Q,         KC_W,         KC_E,         KC_R,      KC_T,    KC_Y,           KC_U,         KC_I,         KC_O,            KC_P,     TT(_SYM),
TT(_FUN),			 LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),       KC_G,     KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),     TT(_FUN),
OSL(_PSS),                     KC_Z,         KC_X,         KC_C,         KC_V,       KC_B,     KC_N,         KC_M,      KC_COMM,       KC_DOT,         KC_SLSH,   TO(_SQLL),
                               KC_ESC,KC_TAB,KC_SPC,    KC_ENT,  KC_BSPC, KC_DEL
),

*/
[_QWERTY] = LAYOUT_split_3x6_3(
TO(_SQLL),           LT(_PSS,KC_Q),         KC_W,         KC_E,         KC_R,          KC_T,     KC_Y,           KC_U,         KC_I,         KC_O,   LT(_PSS,KC_P),     TT(_SYM),
MO(_FUN),			  LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),          KC_G,     KC_H,   RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),     TT(_FUN),
MO(_SYM),                     KC_Z,         KC_X,         KC_C,         KC_V,          KC_B,     KC_N,           KC_M,      KC_COMM,       KC_DOT,         KC_SLSH,    TO(_SQLL),
                                          KC_ESC,       KC_TAB,       KC_SPC,        KC_ENT,  KC_BSPC,         KC_DEL
),

    /*
[_SYM] = LAYOUT_split_3x6_3(
XXXXXXX,                KC_GRAVE,   MY_TIL,  KC_PIPE,      XXXXXXX,            XXXXXXX,          XXXXXXX,        MY_UND,    MY_DQUO,  KC_QUOT,    KC_MINUS, XXXXXXX,
XXXXXXX,				 KC_EXLM,    KC_AT,  KC_HASH,       KC_DLR,            KC_PERC,          KC_CIRC,       KC_AMPR,    KC_ASTR,  KC_LPRN,     KC_RPRN, XXXXXXX,
XXXXXXX,                 KC_EQL,  KC_MINS,  KC_PLUS,      KC_LCBR,            KC_RCBR,          KC_LBRC,       KC_RBRC,    KC_SCLN,  KC_COLN,     KC_BSLS,  XXXXXXX,
                                XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXoooyujhhhhhhhhh,,,,,,\////;[PROTBLPD].iiiiiiiiinnnnnnnmmmmm  nm.,,,,,,,,,,,pppppppppccccccccccc      //KC_A,     KC_S,     KC_D,         KC_F,               KC_G,             KC_H,          KC_J,       KC_Kaaaa
*/
[_SYM] = LAYOUT_split_3x6_3(
XXXXXXX,    KC_1,     KC_2,      KC_3,     KC_4,      KC_5,         KC_6,          KC_7,        KC_8,      KC_9,         KC_0,   XXXXXXX,
XXXXXXX, S(KC_1),  S(KC_2),   S(KC_3),  S(KC_4),   S(KC_5),      S(KC_6),       S(KC_7),     S(KC_8),   S(KC_9),      S(KC_0),   XXXXXXX,
XXXXXXX,KC_GRAVE,   MY_TIL,   KC_PIPE,  KC_SQBR,   KC_CRBR,        KC_LT,         KC_GT,     KC_SCLN,   KC_COLN,      KC_BSLS,   XXXXXXX,
                              KC_MYESC, KC_EQL , KC_EQEQ ,              MY_UND ,  KC_QUOT ,  MY_DQUO
),

[_FUN] = LAYOUT_split_3x6_3(
 XXXXXXX,     KC_F1,    KC_F2,        KC_F3,        KC_F4,            KC_F5,         KC_F6,         KC_F7,      KC_F8,    KC_F9,     KC_F10,     XXXXXXX,
 XXXXXXX,	KC_LGUI,  KC_LALT,      KC_LCTL,      KC_LSFT,          KC_MUTE,       XXXXXXX,       KC_LEFT,    KC_DOWN,    KC_UP,   KC_RIGHT,     XXXXXXX,
 XXXXXXX,   MY_UNDO,   MY_CUT,      MY_COPY,      MY_PSTE,          MY_REDO,        KC_INS,       KC_HOME,    KC_PGDN,  KC_PGUP,     KC_END,     XXXXXXX,
                                KC_MYESC,      _______ ,    _______ ,          _______ ,  _______ ,  _______
),
     /*
[_FUN] = LAYOUT_split_3x6_3(
XXXXXXX,                 XXXXXXX,    KC_F7,    KC_F8,        KC_F9,            XXXXXXX,          XXXXXXX,        XXXXXXX,    XXXXXXX,   XXXXXXX,      XXXXXXX,  XXXXXXX,
XXXXXXX,			     XXXXXXX,    KC_F4,    KC_F5,        KC_F6,            XXXXXXX,          XXXXXXX,        KC_LGUI,    KC_LALT,   KC_LCTL,     KC_LSFT,   XXXXXXX,
XXXXXXX,			     XXXXXXX,    KC_F1,    KC_F2,        KC_F3,            XXXXXXX,          XXXXXXX,        XXXXXXX,    XXXXXXX,   XXXXXXX,      XXXXXXX,  XXXXXXX,WHERE WHERE WHERE WHERE  =LEFT OUTER JOIN  ON
                                      KC_F10,       KC_F11,             KC_F12,          XXXXXXX,        XXXXXXX,    XXXXXXX
                                //KC_E,         KC_R,               KC_T,             KC_Y,          KC_U,       KC_I,     KC_O,        KC_P
     ),
[_NUM] = LAYOUT_split_3x6_3(


XXXXXXX,                 KC_PSLS,     KC_7,     KC_8,         KC_9,            KC_PMNS,          XXXXXXX,        XXXXXXX,    XXXXXXX,   XXXXXXX,     XXXXXXX, XXXXXXX,
XXXXXXX,			     KC_PAST,     KC_4,     KC_5,         KC_6,            KC_PPLS,          XXXXXXX,        KC_LGUI,    KC_LALT,   KC_LCTL,     KC_LSFT, XXXXXXX,
XXXXXXX,				    KC_0,     KC_1,     KC_2,         KC_3,             KC_EQL,          XXXXXXX,        XXXXXXX,    XXXXXXX,   XXXXXXX,     XXXXXXX, XXXXXXX,
                                     XXXXXXX,      XXXXXXX,             KC_DOT,          XXXXXXX,        XXXXXXX,    XXXXXXX
                                //KC_E,         KC_R,               KC_T,             KC_Y,          KC_U,       KC_I,     KC_O,        KC_ ON
     ),*/
[_PSS] = LAYOUT_split_3x6_3(
XXXXXXX,                   MY_17,    MY_23,     MY_5,        MY_18,              MY_20,            MY_25,         MY_21,       MY_9,    MY_15,       MY_16,  XXXXXXX,
XXXXXXX,				    MY_1,    MY_19,     MY_4,         MY_6,               MY_7,             MY_8,         MY_10,      MY_11,    MY_12,       MY_29,  XXXXXXX,
XXXXXXX,                   MY_26,    MY_24,     MY_3,        MY_22,               MY_2,            MY_14,         MY_13,      MY_27,    MY_28,       MY_30,  XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX
),

[_SQLL] = LAYOUT_split_3x6_3(
OSL(_SQL1),    _______ ,     _______,    _______,      _______,             _______,            _______,         _______,      _______,    _______,      _______, OSL(_SQL4),
OSL(_SQL2),        KC_A,        KC_S,       KC_D,         KC_F,             _______,            _______,           KC_J,         KC_K,       KC_L,       KC_SCLN, OSL(_SQL5),
OSL(_SQL3),     _______,     _______,    _______,      _______,             _______,            _______,        _______,      _______,    _______,       _______, OSL(_SQL6),
                              KC_MYESC , _______, _______,                                  _______,       _______,     _______
),
[_SQL1] = LAYOUT_split_3x6_3(
XXXXXXX,               _______,   KC_QWH1,  _______,      _______,          _______,            KC_QU1,         KC_QI1,      KC_QORB,    _______,    _______, XXXXXXX,
XXXXXXX,			    KC_QA1,    KC_QS1,   KC_QD1,      _______,           KC_QG1,            KC_QH1,        KC_QJN1,      _______,     KC_QL1,    _______, XXXXXXX,
XXXXXXX,               _______,   _______,   KC_QC1,      _______,          _______,           _______,        _______,      _______,    _______,    _______, XXXXXXX,
                              KC_MYESC , _______, _______,                                  _______,       _______,     _______
),
[_SQL2] = LAYOUT_split_3x6_3(
XXXXXXX,               _______,  KC_QWH2,  _______,      _______,            _______,          _______,         KC_QI2,      _______,    _______,    _______, XXXXXXX,
XXXXXXX,			    KC_QA2,  _______,   KC_QD2,      _______,            _______,          _______,        KC_QJN2,      _______,     KC_QL2,    _______, XXXXXXX,
XXXXXXX,               _______,  _______,  _______,      _______,            _______,          _______,        _______,      _______,    _______,    _______, XXXXXXX,
                              KC_MYESC , _______, _______,                                  _______,       _______,     _______
),
[_SQL3] = LAYOUT_split_3x6_3(
XXXXXXX,               _______,  KC_QWH3, _______,      _______,            _______,          _______,         KC_QI3,      _______,    _______,     _______, XXXXXXX,
XXXXXXX,			   _______,   _______,  KC_QD3,      _______,           _______,          _______,        KC_QJN3,      _______,    _______,     _______, XXXXXXX,
XXXXXXX,               _______,   _______, _______,      _______,           _______,          _______,        _______,      _______,    _______,     _______, XXXXXXX,
                              KC_MYESC , _______, _______,                                  _______,       _______,     _______
),
[_SQL4] = LAYOUT_split_3x6_3(
XXXXXXX,                KC_QQ4,  _______,  _______,      _______,           _______,          _______,         KC_QI4,      _______,    _______,       KC_QP4, XXXXXXX,
XXXXXXX,			   _______,  _______,   KC_QD4,      _______,           _______,          _______,        _______,      _______,    _______,      _______, XXXXXXX,
XXXXXXX,               _______,  _______,  _______,       KC_QV4,           _______,          _______,        _______,      _______,    _______,      _______, XXXXXXX,
                              KC_MYESC , _______, _______,                                  _______,       _______,     _______
),
[_SQL5] = LAYOUT_split_3x6_3(
XXXXXXX,                KC_QQ5,  _______,  _______,      _______,            _______,          _______,        KC_QI5,      _______,    _______,      KC_QP5, XXXXXXX,
XXXXXXX,			   _______,  _______,  _______,      _______,            _______,          _______,       _______,      _______,    _______,     _______, XXXXXXX,
XXXXXXX,               _______,  _______,  _______,      _______,            _______,          _______,       _______,      _______,    _______,     _______, XXXXXXX,
                              KC_MYESC , _______, _______,                                  _______,       _______,     _______
),
[_SQL6] = LAYOUT_split_3x6_3(
XXXXXXX,               _______,  _______,  _______,      _______,            _______,          _______,       _______,      _______,    _______,      KC_QP6, XXXXXXX,
XXXXXXX,			   _______,  _______,  _______,      _______,            _______,          _______,       _______,      _______,    _______,     _______, XXXXXXX,
XXXXXXX,               _______,  _______,  _______,      _______,            _______,          _______,       _______,      _______,    _______,     _______, XXXXXXX,
                              KC_MYESC , _______, _______,                                  _______,       _______,     _______
)
/*

[_NAV] = LAYOUT_split_3x6_3(
XXXXXXX,                 XXXXXXX,  XXXXXXX,  XXXXXXX,      XXXXXXX,            XXXXXXX,          MY_REDO,       MY_PSTE,    MY_COPY,   MY_CUT,    MY_UNDO,  XXXXXXX,qqqqqqqwwf
XXXXXXX,				 KC_LGUI,  KC_LALT,  KC_LCTL,      KC_LSFT,            XXXXXXX,          XXXXXXX,       KC_LEFT,    KC_DOWN,    KC_UP,   KC_RIGHT,  XXXXXXX,
XXXXXXX,                 XXXXXXX,  XXXXXXX,  XXXXXXX,      XXXXXXX,            XXXXXXX,           KC_INS,       KC_HOME,    KC_PGDN,  KC_PGUP,     KC_END,  XXXXXXX,dddddddd
                                     XXXXXXX,      XXXXXXX,            XXXXXXX,           KC_ENT,       KC_BSPC,     KC_DEL
),

[_MEDIA] = LAYOUT_split_3x6_3(
XXXXXXX,                 XXXXXXX,  XXXXXXX,  XXXXXXX,      XXXXXXX,            XXXXXXX,          RGB_TOG,       RGB_MOD,    RGB_HUI,  RGB_SAI,    RGB_VAI,  XXXXXXX,
XXXXXXX,				 KC_LGUI,  KC_LALT,  KC_LCTL,      KC_LSFT,            XXXXXXX,          XXXXXXX,       KC_MPRV,    KC_VOLD,  KC_VOLU,    KC_MNXT,  XXXXXXX,
XXXXXXX,                 XXXXXXX,  XXXXXXX,  XXXXXXX,      XXXXXXX,            XXXXXXX,          XXXXXXX,       XXXXXXX,    XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,
                                     XXXXXXX,      XXXXXXX,            XXXXXXX,          KC_MSTP,       KC_MPLY,    KC_MUTE
    )
,
[_MOUSE] = LAYOUT_split_3x6_3(
XXXXXXX,                 XXXXXXX,  XXXXXXX,  XXXXXXX,      XXXXXXX,            XXXXXXX,          MY_REDO,       MY_PSTE,    MY_COPY,   MY_CUT,    MY_UNDO,  XXXXXXX,
XXXXXXX,				 KC_LGUI,  KC_LALT,  KC_LCTL,      KC_LSFT,            XXXXXXX,          XXXXXXX,       KC_MS_L,    KC_MS_D,  KC_MS_U,    KC_MS_R,  XXXXXXX,dddda222222222222aaddddddddddddddwWHERE qALTER  TABLE !
XXXXXXX,                 XXXXXXX,  XXXXXXX,  XXXXXXX,      XXXXXXX,            XXXXXXX,          XXXXXXX,       KC_WH_L,    KC_WH_D,  KC_WH_U,    KC_WH_R,  XXXXXXX,
                                     XXXXXXX,      XXXXXXX,            XXXXXXX,          KC_BTN1,       KC_BTN2,    KC_BTN3
    )*/
};




void keyboard_post_init_user(void) {
    //rgb_matrix_mode(RGB_MATRIX_BREATHING);
   // rgblight_sethsv(HSV_BLUE);
    //rgblight_mode(RGBLIGHT_MODE_BREATHING);
    //rgb_matrix_set_color_all(RGB_BLACK);
        rgblight_layers = my_rgb_layers;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
            return TAPPING_TERM + 350;
            break;
        case RGUI_T(KC_SCLN):
            return TAPPING_TERM + 250;
            break;
        case LALT_T(KC_S):
            return TAPPING_TERM + 250;
            break;
        case RALT_T(KC_L):
            return TAPPING_TERM + 250;
        break;
        default:
            return TAPPING_TERM;
    }
}

layer_state_t layer_state_set_user(layer_state_t state){
//switch(get_highest_layer(state)) {
//  case _SYM:
   // green-ish
 //   rgblight_sethsv(HSV_RED);
///    break;
// case _SQLL:
    // Red
  //  rgblight_sethsv(HSV_GREEN);
 //   break;
//  case _SQL1:uyuy
    // Red
  //  rgblight_sethsv(HSV_PURPLE);
  //  rgblight_sethsv_at(HSV_RED, 0);
  //  break;
  //case _SQL2:
    // Red
  //  rgblight_sethsv(HSV_PURPLE);
 //   rgblight_sethsv_at(HSV_RED, 1);
 //   break;
  //case _SQL3:
    // Red
 //   rgblight_sethsv(HSV_RED);
  //  rgblight_sethsv_at(HSV_PURPLE, 2);
  //  break;
 // case _SQL4:
    // Red
 //   rgblight_sethsv(HSV_PURPLE);
 //   rgblight_sethsv_at(HSV_RED, 3);
 //   break;
 // case _SQL5:
    // Red
   // rgblight_sethsv(HSV_PURPLE);
  //  rgblight_sethsv_at(HSV_RED, 4);
  //  break;
 // case _SQL6:
    // Red
 //   rgblight_sethsv(HSV_PURPLE);
 //   rgblight_sethsv_at(HSV_RED, 5);
//    break;
 // case _FUN:
    // Dark Blue
    //rgblight_sethsv(HSV_MAGENTA);
  //  break;
 ///// case _PSS:
    // Dark Blue
 //   rgblight_sethsv(HSV_ORANGE);
  //  break;
 //default:
//    rgblight_sethsv(HSV_BLUE);
 //   break;
//  }
 // rgblight_set();
 // return state;

 //if (layer_state_cmp(state, _SQLL))
 //{
   // combo_enable();
 //}
 //else
 //{
 //   combo_disable();
 //}

rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
rgblight_set_layer_state(1, layer_state_cmp(state, _SYM));
rgblight_set_layer_state(2, layer_state_cmp(state, _SQLL));
rgblight_set_layer_state(3, layer_state_cmp(state, _SQL1));
rgblight_set_layer_state(4, layer_state_cmp(state, _SQL2));
rgblight_set_layer_state(5, layer_state_cmp(state, _SQL3));
rgblight_set_layer_state(6, layer_state_cmp(state, _SQL4));
rgblight_set_layer_state(7, layer_state_cmp(state, _SQL5));
rgblight_set_layer_state(8, layer_state_cmp(state, _SQL6));
rgblight_set_layer_state(9, layer_state_cmp(state, _FUN));
rgblight_set_layer_state(10, layer_state_cmp(state, _PSS));
return state;
}

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  layer_clear();
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case KC_QORB:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("ORDER BY "), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
            return false;}
        case KC_PAR:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("()"SS_TAP(X_LEFT)), 12);
			return false;}
        case KC_CRBR:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("{}"SS_TAP(X_LEFT)), 12);
			return false;}
        case KC_SQBR:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("[]"SS_TAP(X_LEFT)), 12);
			return false;}
        case KC_EQEQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("=="SS_TAP(X_LEFT)), 12);
			return false;}
        case KC_QA1:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("ALTER  TABLE "), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QA2:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("AVG(*) as avgof, \n"), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QC1:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("COUNT(*) as cntof, \n"), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QD1:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("DELETE FROM  WHERE ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QD2:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("DECLARE @str VARCHAR(50) = ''"SS_TAP(X_LEFT)), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QD3:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("DECLARE @int INT = "), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QD4:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("[DBO]."), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QS1:
			if (record->event.pressed) {
		    send_string_with_delay_P(PSTR("SELECT\n * \n FROM "), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QG1:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("GROUP BY \n" SS_TAP(X_TAB)), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QH1:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("HAVING \n"SS_TAP(X_LEFT)), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QI1:
			if (record->event.pressed) {
            send_string_with_delay_P(PSTR("IN (, )" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QI2:
			if (record->event.pressed) {
            send_string_with_delay_P(PSTR("IN ('','')" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QI3:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("IN (\"\",\"\")" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
       case KC_QI4:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("[ICORPD]."), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
       case KC_QI5:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("[ICORPDCD]."), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QL1:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("LIKE '%%'"SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QL2:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("LIKE \"%%\""SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QU1:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("UPDATE A SET  =  FROM  as A WHERE A.  ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_MYESC:
			if (record->event.pressed) {
            send_string_with_delay_P(PSTR(SS_TAP(X_ESC)), 12);
			layer_clear();
			return false;}
        case KC_QP4:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("[PRODTAPD]."), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QP5:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("[PROTBLPD]."), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QP6:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("[PROQUERY]."), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QQ4:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("[QS36F]."), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QQ5:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("[QSYS2]."), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
        case KC_QV4:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("[VTSINT]."), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
			return false;}
		case KC_QWH1:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("WHERE "), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
            return false;}
		case KC_QWH2:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("WHERE  ="SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
            return false;}
		case KC_QWH3:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("WHERE  BETWEEN  AND"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
            return false;}
		case KC_QJN1:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("INNER JOIN  ON"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
            return false;}
		case KC_QJN2:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("LEFT OUTER JOIN  ON"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
            return false;}
		case KC_QJN3:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("FULL OUTER JOIN  ON"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
	        layer_off(_SQL1);
            layer_off(_SQL2);
            layer_off(_SQL3);
            layer_off(_SQL4);
	        layer_off(_SQL5);
	        layer_off(_SQL6);
            return false;}
    }
    //return true;
	return process_record_secrets(keycode, record);
}



/*
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
        case TD_DOUBLE_TAP:q
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
 //   [X_PLSMNS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xplsmns_finished, generic_reset)
};
*/


