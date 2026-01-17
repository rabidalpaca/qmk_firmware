#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap5
enum layer_names {
    _QWERTY = 0,
	_SYM,
    _FUNC,
	_PSS
};


enum combos {
  //sdfSTab,//replace
  odfDel,
  dfBsp,
  n56Bsp,//replace
  o56Del,
  fgLead,
  jkEnt,
  hjLead,
  jklTab
};

//const uint16_t PROGMEM sdf_combo[] = {KC_S, KC_D, KC_F, COMBO_END};//replace
const uint16_t PROGMEM odf_combo[] = {OSM(MOD_RSFT), KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM o56_combo[] = {OSM(MOD_RSFT), KC_KP_5, KC_KP_6, COMBO_END};
const uint16_t PROGMEM n56B_combo[] = {KC_KP_5, KC_KP_6, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
combo_t key_combos[] = {
  //[sdfSTab] = COMBO(sdf_combo, S(KC_TAB)), //replace
  [odfDel] = COMBO(odf_combo, KC_DEL),
  [dfBsp] = COMBO(df_combo, KC_BSPC),
  [o56Del] = COMBO(o56_combo, KC_DEL),
  [n56Bsp] = COMBO(n56B_combo, KC_BSPC),
  [fgLead] = COMBO(fg_combo, QK_LEAD),
  [jkEnt] = COMBO(jk_combo, KC_ENT),
  [hjLead] = COMBO(hj_combo, QK_LEAD),
  [jklTab] = COMBO(jkl_combo, KC_TAB)
};

#define PAT LT(0,KC_P)
#define CMALT LT(0,KC_COMM)
#define DOTGT LT(0,KC_DOT)
#define SCLCL LT(0,KC_SCLN)
#define LBDLR LT(0,KC_E)
#define CTAMP LT(0,KC_R)
#define OCPAR LT(0,KC_9) //( and )
#define OCBRK LT(0,KC_8) //[ and ]
#define OCBRC LT(0,KC_0) //{ and }
#define QTDQT LT(0,KC_7) //single quote double quote,
#define PLSMN LT(0,KC_6) //plus minus
#define EQNEQ LT(0,KC_5) //equal not equal
#define SLBSL LT(0,KC_4) //slash backslash
#define QSUDR LT(0,KC_3) //question underline
#define EXCPI LT(0,KC_2) //eclamation pipe
#define GRVTI LT(0,KC_1) //grave tilda
#define ASTPC LT(0,KC_W) //Asterisk percent
#define QESC LT(0,KC_Q) //Q ESC
#define ZDOT LT(0,KC_T) //0 .
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

static uint16_t key_timer; // timer to track the last keyboard activity
static void refresh_rgb(void); // refreshes the activity timer and RGB, invoke whenever activity happens
static void check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
bool is_rgb_timeout = false; // store if RGB has timed out or not in a boolean

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_split_3x6_3(
        GRVTI,  QESC,         KC_W,         KC_E,         KC_R,        KC_T,              KC_Y,        KC_U,         KC_I,         KC_O,   PAT,        QTDQT, //MY_QTMCR,LT(0,KC_ESC)
        ASTPC,  KC_A,         KC_S,         KC_D,         KC_F,        KC_G,              KC_H,        KC_J,         KC_K,         KC_L, SCLCL,        SLBSL, //MY_OPMCR, //LT(0,KC_QUOT),LT(0,KC_Q)
        EXCPI,  KC_Z,         KC_X,         KC_C,         KC_V,        KC_B,              KC_N,        KC_M,        CMALT,        DOTGT, QSUDR,OSM(MOD_RCTL), //MY_EQMCR, //LT(0,KC_BSLS),S(KC_SLSH),LT(0,KC_W),MY_EXMCR
                               TT(_FUNC),       KC_SPC,   TT(_FUNC),          TT(_SYM),   KC_ENT,      OSM(MOD_RSFT)
),
[_SYM] = LAYOUT_split_3x6_3(
LT(0,KC_9),    LBDLR,      KC_KP_7,      KC_KP_8,      KC_KP_9,    PLSMN,      UG_TOGG,       _______,      _______,      _______,      _______,      _______, //LT(0,KC_PPLS),
LT(0,KC_0),    CTAMP,      KC_KP_4,      KC_KP_5,      KC_KP_6,    EQNEQ,      RGB_M_TW,       _______,      _______,      _______,      _______,      _______,
LT(0,KC_8),     ZDOT,      KC_KP_1,      KC_KP_2,      KC_KP_3,   KC_ENT,      QK_LLCK, OSM(MOD_RSFT),OSM(MOD_RCTL),OSM(MOD_RALT),OSM(MOD_RGUI),      _______,
                               _______,    _______,    MO(_PSS),                      _______,     _______,   _______
),
[_FUNC] = LAYOUT_split_3x6_3(
 XXXXXXX,   XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,       XXXXXXX,       XXXXXXX,     XXXXXXX,  XXXXXXX,    XXXXXXX,      KC_F24,
 XXXXXXX,   XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,         KC_F7,         KC_F8,       KC_F9,   KC_F10,     KC_F11,      KC_F12,
 XXXXXXX,   XXXXXXX,      XXXXXXX,      KC_RCTL,      KC_LSFT,          XXXXXXX,         KC_F1,         KC_F2,       KC_F3,    KC_F4,      KC_F5,       KC_F6,
                                _______,      _______ ,    _______ ,          _______ ,  _______ ,  _______
),
[_PSS] = LAYOUT_split_3x6_3(
MY_29,                 MY_17,    MY_23,     MY_5,        MY_18,              MY_20,            MY_25,         MY_21,       MY_9,    MY_15,       MY_16,    MY_32,
MY_30,				    MY_1,    MY_19,     MY_4,         MY_6,               MY_7,             MY_8,         MY_10,      MY_11,    MY_12,       MY_35,    MY_33,
MY_31,                 MY_26,    MY_24,     MY_3,        MY_22,               MY_2,            MY_14,         MY_13,      MY_27,    MY_28,       MY_36,    MY_34,
                               XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,  XXXXXXX,  XXXXXXX
)
};








void leader_start_user(void) {
    // Do something when the leader key is pressed
}

/*
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 3:
                rgb_matrix_set_color(i, RGB_RED);
                rgblight_mode(RGBLIGHT_MODE_TWINKLE + 2);
                break;
            case 2:
                rgb_matrix_set_color(i, RGB_GREEN);
                rgblight_mode(RGBLIGHT_MODE_TWINKLE + 2);
                break;
            case 1:
                rgb_matrix_set_color(i, RGB_CYAN);
                rgblight_mode(RGBLIGHT_MODE_TWINKLE + 2);
                break;
            default:
                rgb_matrix_set_color(i, RGB_BLUE);
                rgblight_mode(RGBLIGHT_MODE_TWINKLE + 2);
                break;
        }
    }
    return false;
}*/

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_A)) {
        // Leader, a => Types the below string
		send_string_with_delay_P(PSTR("SELECT \n*\nFROM\n\nWHERE\n\nORDER BY 1"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)), 10);
    } else if (leader_sequence_two_keys(KC_A,KC_A)) {
        // Leader, a,a => Types the below string
		send_string_with_delay_P(PSTR("SELECT\nCOUNT(*) as CntOf\n"),10);
        send_string_with_delay_P(PSTR("FROM\n\nWHERE\nGROUP BY\nORDER BY 1"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)), 10);
    } else if (leader_sequence_one_key(KC_S)) {
        // Leader, s => Types the below string
        send_string_with_delay_P(PSTR("\nINNER JOIN  AS B ON"), 10);
    } else if (leader_sequence_two_keys(KC_S, KC_S)) {
        // Leader, s => Types the below string
        send_string_with_delay_P(PSTR("\nLEFT OUTER JOIN  AS B ON"), 10);
    } else if (leader_sequence_one_key(KC_D)) {
        // Leader, s => Types the below string
        send_string_with_delay_P(PSTR("\nWHERE  = "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);
    } else if (leader_sequence_two_keys(KC_D, KC_D)) {
        // Leader, d, d => Ctrl+A, Ctrl+C
        send_string_with_delay_P(PSTR("\nWHERE  LIKE '%'"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);
    } else if (leader_sequence_three_keys(KC_D, KC_D, KC_D)) {
        // Leader, d, d, s => Types the below string
        send_string_with_delay_P(PSTR("\nWHERE  IS NULL"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);
    } else if (leader_sequence_four_keys(KC_D, KC_D, KC_D,KC_D)) {
        // Leader, d, d, s => Types the below string
        send_string_with_delay_P(PSTR("\nWHERE  IS BETWEEN  AND"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);
    } else if (leader_sequence_one_key(KC_F)) {
        send_string_with_delay_P(PSTR("COUNT(*) as CntOf,\n"), 10);
    } else if (leader_sequence_two_keys(KC_F,KC_F)) {
        send_string_with_delay_P(PSTR("MAX(*) as MaxOf,\n"), 10);
    } else if (leader_sequence_three_keys(KC_F,KC_F,KC_F)) {
        send_string_with_delay_P(PSTR("MIN(*) as MinOf,\n"), 10);
    } else if (leader_sequence_one_key(KC_G)) {
        send_string_with_delay_P(PSTR("SELECT TABLE_SCHEMA, TABLE_NAME, COLUMN_NAME, ORDINAL_POSITION, \n"), 10);
        send_string_with_delay_P(PSTR("DATA_TYPE, CHARACTER_MAXIMUM_LENGTH, NUMERIC_PRECISION, NUMERIC_SCALE \n"), 10);
        send_string_with_delay_P(PSTR("FROM [INFORMATION_SCHEMA].[COLUMNS] \n"), 10);
        send_string_with_delay_P(PSTR("WHERE COLUMN_NAME like '%%' \n"), 10);
        send_string_with_delay_P(PSTR("AND TABLE_NAME like '%%' \n"), 10);
        send_string_with_delay_P(PSTR("AND TABLE_SCHEMA like '%%' \n"), 10);
        send_string_with_delay_P(PSTR("ORDER BY ORDINAL_POSITION"), 10);
    } else if (leader_sequence_two_keys(KC_G,KC_G)) {
        send_string_with_delay_P(PSTR("SELECT tab.TABLE_SCHEMA, tab.TABLE_NAME, col.COLUMN_NAME, col.ORDINAL_POSITION, \n"), 10);
        send_string_with_delay_P(PSTR("col.DATA_TYPE, col.LENGTH, col.NUMERIC_SCALE \n"), 10);
        send_string_with_delay_P(PSTR("FROM QSYS2.SYSTABLES tab \n"), 10);
        send_string_with_delay_P(PSTR("INNER JOIN QSYS2.SYSCOLUMNS col \n"), 10);
        send_string_with_delay_P(PSTR("ON tab.TABLE_NAME = col.TABLE_NAME and tab.SCHEMA_NAME = col.SCHEMA_NAME \n"), 10);
        send_string_with_delay_P(PSTR("WHERE col.COLUMN_NAME like '%%' \n"), 10);
        send_string_with_delay_P(PSTR("AND tab.TABLE_NAME like '%%' \n"), 10);
        send_string_with_delay_P(PSTR("AND tab.TABLE_SCHEMA like '%%' \n"), 10);
        send_string_with_delay_P(PSTR("ORDER BY col.ORDINAL_POSITION"), 10);
    } else if (leader_sequence_one_key(KC_T)) {
		send_string_with_delay_P(PSTR("DECLARE @int INT = "), 10);
    } else if (leader_sequence_two_keys(KC_T,KC_T)) {
		send_string_with_delay_P(PSTR("DECLARE @str VARCHAR(50) = ''"SS_TAP(X_LEFT)), 10);
    } else if (leader_sequence_one_key(KC_Y)) {
		send_string_with_delay_P(PSTR(SS_TAP(X_HOME)"'"SS_TAP(X_END)"',"SS_TAP(X_DOWN)), 10); //wrap a line in single quotes
    } else if (leader_sequence_two_keys(KC_Y,KC_Y)) {
		send_string_with_delay_P(PSTR(SS_TAP(X_HOME)"\""SS_TAP(X_END)"\","SS_TAP(X_DOWN)), 10); //wrap a line in double quotes
    } else if (leader_sequence_one_key(KC_H)) {
		send_string_with_delay_P(PSTR("DBO."), 10);
    } else if (leader_sequence_two_keys(KC_H,KC_H)) {
		send_string_with_delay_P(PSTR("QSYS2."), 10);
    } else if (leader_sequence_three_keys(KC_H,KC_H,KC_H)) {
		send_string_with_delay_P(PSTR("SYSIBM."), 10);
    } else if (leader_sequence_one_key(KC_J)) {
		send_string_with_delay_P(PSTR("PRODTAPD."), 10);
    } else if (leader_sequence_two_keys(KC_J,KC_J)) {
		send_string_with_delay_P(PSTR("PROTBLPD."), 10);
    } else if (leader_sequence_three_keys(KC_J,KC_J,KC_J)) {
		send_string_with_delay_P(PSTR("PROQUERY."), 10);
    } else if (leader_sequence_one_key(KC_L)) {
		send_string_with_delay_P(PSTR("QS36F."), 10);
    } else if (leader_sequence_one_key(KC_K)) {
		send_string_with_delay_P(PSTR("VTSINT."), 10);
    } else if (leader_sequence_two_keys(KC_K,KC_K)) {
		send_string_with_delay_P(PSTR("ICORPD."), 10);
    } else if (leader_sequence_three_keys(KC_K,KC_K,KC_K)) {
		send_string_with_delay_P(PSTR("ICORPDCD."), 10);
    } else if (leader_sequence_one_key(KC_N)) {
        send_string_with_delay_P(PSTR(SS_LGUI("r")), 10); //run
    } else if (leader_sequence_two_keys(KC_N, KC_N)) {
        send_string_with_delay_P(PSTR(SS_LGUI("l")), 10); //log out
    }
}
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(0,KC_T):
            return TAPPING_TERM + 100;
        case LT(0,KC_P):
            return TAPPING_TERM + 100;
        case LT(0,KC_Q):
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}
bool modlocked;

bool get_combo_must_press_in_order(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        /* List combos here that you want to only activate if their keys
         * are pressed in the same order as they are defined in the combo's key
         * array. */
        default:
            return false;
    }
}


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(0,KC_P):
            // Do not select the hold action when another key is tapped.pppp@.>,<
            return false;
        case LT(0,KC_Q):
            // Do not select the hold action when another key is tapped.
            return false;
        case LT(0,KC_7):
            // Do not select the hold action when another key is tapped.
            return false;
        default:
            // Immediately select the hold action when another key is tapped.
            return true;
    }
}
const uint8_t RGBLED_TWINKLE_INTERVALS[] PROGMEM = {50, 25, 10};
const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 120, HSV_BLUE});
const rgblight_segment_t PROGMEM my_sym_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 120, HSV_ORANGE});
const rgblight_segment_t PROGMEM my_func_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 120, HSV_PURPLE});
const rgblight_segment_t PROGMEM my_pss_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 10, HSV_RED});
const rgblight_segment_t PROGMEM _yes_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 10, HSV_GREEN} );
const rgblight_segment_t PROGMEM _no_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 10, HSV_RED} );

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_qwerty_layer,  //
    my_sym_layer,     // Other layers
    my_func_layer,    // Overrides other layers
    my_pss_layer,     // Overrides other layers
    _yes_layer,
    _no_layer
);


void keyboard_post_init_user(void) {
     //Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_enable(); // Enable RGB by default
    rgblight_enable_noeeprom(); // enables RGB, without saving settings
    //rgblight_setrgb_noeeprom(RGB_BLUE); // sets the color to red without saving
    rgblight_mode_noeeprom(RGBLIGHT_MODE_TWINKLE + 3); // sets mode to Fast breathing without saving

   //rgblight_mode(RGBLIGHT_MODE_TWINKLE);

}


layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));

    rgblight_mode(RGBLIGHT_MODE_TWINKLE);
    return state;
}


layer_state_t layer_state_set_user(layer_state_t state) {
   rgblight_set_layer_state(1, layer_state_cmp(state, _SYM));
   rgblight_set_layer_state(2, layer_state_cmp(state, _FUNC));
   rgblight_set_layer_state(3, layer_state_cmp(state, _PSS));

    switch (get_highest_layer(state)) {
    case _SYM:
      rgblight_sethsv (HSV_CYAN);
      break;
    case _FUNC:
      rgblight_sethsv (HSV_YELLOW);
      break;
    case _PSS:
      rgblight_sethsv (HSV_RED);
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv (HSV_BLUE);
      break;
  }
   rgblight_mode(RGBLIGHT_MODE_TWINKLE+2);
   return state;
}


__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  layer_clear();
  return true;
}

void check_rgb_timeout() {
  if (!is_rgb_timeout && timer_elapsed(key_timer) > RGBLIGHT_TIMEOUT) {
    rgblight_suspend();
    is_rgb_timeout = true;
  }
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

void refresh_rgb() {
  key_timer = timer_read(); // store time of last refresh
  if (is_rgb_timeout) { // only do something if rgb has timed out
    print("Activity detected, removing timeout\n");
    is_rgb_timeout = false;
    rgblight_wakeup();

  }
}

uint8_t mod_state;

void oneshot_locked_mods_changed_user(uint8_t mods) {
    //if entering a lock state update led to red, else it will be blue
  if (mods & MOD_MASK_SHIFT) {
    modlocked = true;
    rgblight_set_layer_state(5, true);
  }
  if (mods & MOD_MASK_CTRL) {
    modlocked = true;
    rgblight_set_layer_state(5, true);
  }
  if (mods & MOD_MASK_ALT) {
    modlocked = true;
    rgblight_set_layer_state(5, true);
  }
  if (mods & MOD_MASK_GUI) {
    modlocked = true;
    rgblight_set_layer_state(5, true);
  }
  if (!mods) {
    modlocked = false;
    rgblight_set_layer_state(5, false);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
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
            case KC_BSPC:
                {
                // Initialize a boolean variable that keeps track
                // of the delete key status: registered or not?
                static bool delkey_registered;
                if (record->event.pressed) {
                    // Detect the activation of either shift keys
                    if (mod_state & MOD_MASK_SHIFT) {
                        // First temporarily canceling both shifts so that
                        // shift isn't applied to the KC_DEL keycode
                        del_mods(MOD_MASK_SHIFT);
                        register_code(KC_DEL);
                        // Update the boolean variable to reflect the status of KC_DEL
                        delkey_registered = true;
                        // Reapplying modifier state so that the held shift key(s)
                        // still work even after having tapped the Backspace/Delete key.
                        set_mods(mod_state);
                        return false;
                    }
                } else { // on release of KC_BSPC
                    // In case KC_DEL is still being sent even after the release of KC_BSPC
                    if (delkey_registered) {
                        unregister_code(KC_DEL);
                        delkey_registered = false;
                        return false;
                    }
                // Let QMK process the KC_BSPC keycode as usual outside of shift

                }
                return true;
            }
         case EXCPI:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("!"), 10);
                tap_code16(KC_EXLM);
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("|"), 10);
                tap_code16(KC_PIPE);
            }
			return false;
         case LBDLR:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("#"), 10);
                tap_code16(S(KC_3));  //#
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("$"), 10);
                tap_code16(S(KC_4));  //$
            }
			return false;
         case CTAMP:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("^"), 10);
                tap_code16(S(KC_6));  //^
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("&"), 10);
                tap_code16(S(KC_7));  //&
            }
			return false;
         case ZDOT:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("0"), 10);
                tap_code16(KC_0);  //0
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("."), 10);
                tap_code16(KC_DOT);  //.
            }
			return false;
         case QSUDR:
           if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("?"), 10);
                tap_code16(KC_QUES);  //?
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("_"), 10);
                tap_code16(KC_UNDS);  //_
            }
			return false;
         case SLBSL:
           if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("/"), 10);
                tap_code16(KC_SLASH);  //?
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("\\"), 10);
                 tap_code16(KC_BSLS);  //r
            }
			return false;
         case EQNEQ:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("="), 10);
                tap_code16(KC_EQL);  //=
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("!="), 10);
                tap_code16(KC_EXLM);  //!
                tap_code16(KC_EQL);  //=cccccccccccjj
            }
			return false;
         case QESC:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("q"), 10);
                tap_code(KC_Q);
            } else if (record->event.pressed) {
                tap_code(KC_ESC);
            }
			return false;
         case PLSMN:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("+"), 10);
                tap_code16(S(KC_EQL));  //+
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("-"), 10);
                tap_code16(KC_MINS);  //-
            }
			return false;
         case QTDQT:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("'"), 10);
                tap_code(KC_QUOT);  //'
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("\""), 10);
                tap_code16(S(KC_QUOT));  //"
            }
			return false;
         case PAT:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P); // Intercept tap function to send x p
            } else if (record->event.pressed) {
                tap_code16(S(KC_2)); // Intercept hold @
            }
			return false;
         case OCBRK:
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_LBRC)); // Intercept tap function to send 8
            } else if (record->event.pressed) {
                tap_code16(S(KC_RBRC)); // Intercept hold function to send *
                tap_code16(KC_LEFT); //to move inside
            }
			return false;
         case OCPAR:
            if (record->tap.count && record->event.pressed) {
                tap_code16(S(KC_9)); // Intercept tap function to send 9
            } else if (record->event.pressed) {
                tap_code16(S(KC_0)); // Intercept hold function to send )
                tap_code16(KC_LEFT); //to move ide
            }
			return false;
         case OCBRC:
            if (record->tap.count && record->event.pressed) {
               tap_code16(KC_LBRC); // Intercept hold function to send [
            } else if (record->event.pressed) {
                tap_code16(KC_RBRC); // Intercept hold function to send ]
                tap_code16(KC_LEFT); //to move inside
            }
			return false;
         case ASTPC:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("*"), 10);
                tap_code16(KC_ASTR);
            } else if (record->event.pressed) {
                //send_string_with_delay_P(PSTR("%"), 10);
                tap_code16(KC_PERC);
            }
			return false;
         case CMALT:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_COMM); // Intercept tap function to send ,
            } else if (record->event.pressed) {
                tap_code16(S(KC_COMM)); // Intercept hold function to send <
            }
			return false;
         case DOTGT:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_DOT); // Intercept tap function to send .
            } else if (record->event.pressed) {
                tap_code16(S(KC_DOT)); // Intercept hold function to send >
            }
			return false;
         case SCLCL:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_SCLN); // Intercept tap function to send;
            } else if (record->event.pressed) {
                tap_code16(S(KC_SCLN)); // Intercept hold function to send :
            }
			return false;
        }
	return process_record_secrets(keycode, record);
}

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}



