#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap5
enum layer_names {
    _QWERTY = 0,
	_SYM,
    _MOUS,
    _FUNC,
	_PSS
};


enum combos {
  //sdfSTab,//replace
  odfDel,
  dfBsp,
  n56Bsp,//replace
  o56Del,
  jkEnt,
  fjLead,
  jklTab,
  vbTab,
  cvTab,
};

//const uint16_t PROGMEM sdf_combo[] = {KC_S, KC_D, KC_F, COMBO_END};//replace
const uint16_t PROGMEM odf_combo[] = {OSM(MOD_RSFT), KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM o56_combo[] = {OSM(MOD_RSFT), KC_KP_5, KC_KP_6, COMBO_END};
const uint16_t PROGMEM n56B_combo[] = {KC_KP_5, KC_KP_6, COMBO_END};
//const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
combo_t key_combos[] = {
  //[sdfSTab] = COMBO(sdf_combo, S(KC_TAB)), //replace
  [odfDel] = COMBO(odf_combo, KC_DEL),
  [dfBsp] = COMBO(df_combo, KC_BSPC),
  [o56Del] = COMBO(o56_combo, KC_DEL),
  [n56Bsp] = COMBO(n56B_combo, KC_BSPC),
  //[fgLead] = COMBO(fg_combo, QK_LEAD),
  [jkEnt] = COMBO(jk_combo, KC_ENT),
  [fjLead] = COMBO(fj_combo, QK_LEAD),
  [jklTab] = COMBO(jkl_combo, KC_TAB),
  [vbTab] = COMBO(vb_combo, LCG(KC_RGHT)),
  [cvTab] = COMBO(cv_combo, LCG(KC_LEFT))
};

//#define XCTRX LT(0,KC_X)
//#define CCTRC LT(0,KC_C)
//#define VCTRV LT(0,KC_V)
//#define BCTRA LT(0,KC_B)
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
#define VDF LCG(KC_RGHT)
#define VDB LCG(KC_LEFT)
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




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_3x6_3(
        GRVTI,  QESC,         KC_W,         KC_E,         KC_R,        KC_T,              KC_Y,        KC_U,         KC_I,         KC_O,   PAT,        QTDQT, //MY_QTMCR,LT(0,KC_ESC)
        ASTPC,  KC_A,         KC_S,         KC_D,         KC_F,        KC_G,              KC_H,        KC_J,         KC_K,         KC_L, SCLCL,        SLBSL, //MY_OPMCR, //LT(0,KC_QUOT),LT(0,KC_Q)
        EXCPI,  KC_Z,         KC_X,         KC_C,         KC_V,        KC_B,              KC_N,        KC_M,        CMALT,        DOTGT, QSUDR,OSM(MOD_RCTL), //MY_EQMCR, //LT(0,KC_BSLS),S(KC_SLSH),LT(0,KC_W),MY_EXMCR
                            OSM(MOD_RALT),       KC_SPC,   TT(_MOUS),          TT(_SYM),   KC_ENT,      OSM(MOD_RSFT)
),
[_SYM] = LAYOUT_split_3x6_3(
LT(0,KC_9),    LBDLR,      KC_KP_7,      KC_KP_8,      KC_KP_9,    PLSMN,      XXXXXXX,       XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX, //LT(0,KC_PPLS),
LT(0,KC_0),    CTAMP,      KC_KP_4,      KC_KP_5,      KC_KP_6,    EQNEQ,      XXXXXXX,       XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
LT(0,KC_8),     ZDOT,      KC_KP_1,      KC_KP_2,      KC_KP_3,   KC_ENT,      XXXXXXX, OSM(MOD_RSFT),OSM(MOD_RCTL),OSM(MOD_RALT),OSM(MOD_RGUI),      XXXXXXX,
                               QK_LLCK,    MO(_FUNC),    MO(_PSS),                      _______,     _______,   _______
),
[_MOUS] = LAYOUT_split_3x6_3(
 XXXXXXX,   XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,       KC_MUTE,           VDB,   XXXXXXX,        VDF,      XXXXXXX,     XXXXXXX,
 XXXXXXX,   XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,          XXXXXXX,       KC_VOLU,       MS_BTN1,     MS_UP,    MS_BTN2,      XXXXXXX,     MS_WHLU,
 XXXXXXX,   XXXXXXX,      XXXXXXX,      KC_LCTL,      KC_LSFT,          XXXXXXX,       KC_VOLD,       MS_LEFT,   MS_DOWN,    MS_RGHT,      XXXXXXX,     MS_WHLD,
                                _______,      _______ ,    _______ ,          MO(_PSS) ,  _______ ,  QK_LLCK
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

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_Y)) {
        // Leader, a => Types the below string
		send_string_with_delay_P(PSTR("SELECT \n*\nFROM\n\nWHERE\n\nORDER BY 1"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)), 10);
    } else if (leader_sequence_two_keys(KC_Y,KC_Y)) {
        // Leader, a,a => Types the below string
		send_string_with_delay_P(PSTR("SELECT\nCOUNT(*) as CntOf\n"),10);
        send_string_with_delay_P(PSTR("FROM\n\nWHERE\nGROUP BY\nORDER BY 1"SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)), 10);
    } else if (leader_sequence_one_key(KC_H)) {
        // Leader, s => Types the below string
        send_string_with_delay_P(PSTR("\nINNER JOIN  AS B ON"), 10);
    } else if (leader_sequence_two_keys(KC_H, KC_H)) {
        // Leader, s => Types the below string
        send_string_with_delay_P(PSTR("\nLEFT OUTER JOIN  AS B ON"), 10);
    } else if (leader_sequence_one_key(KC_N)) {
        // Leader, s => Types the below string
        send_string_with_delay_P(PSTR("\nWHERE  = "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);
    } else if (leader_sequence_two_keys(KC_N, KC_N)) {
        // Leader, d, d => Ctrl+A, Ctrl+C
        send_string_with_delay_P(PSTR("\nWHERE  IN ()"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);
    } else if (leader_sequence_three_keys(KC_N, KC_N, KC_N)) {
        // Leader, d, d => Ctrl+A, Ctrl+C
        send_string_with_delay_P(PSTR("\nWHERE  LIKE '%'"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);
    } else if (leader_sequence_four_keys(KC_N, KC_N, KC_N, KC_N)) {
        // Leader, d, d, s => Types the below string
        send_string_with_delay_P(PSTR("\nWHERE  IS NULL"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);
    } else if (leader_sequence_five_keys(KC_N, KC_N, KC_N, KC_N, KC_N)) {
        // Leader, d, d, s => Types the below string
        send_string_with_delay_P(PSTR("\nWHERE  IS BETWEEN  AND"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);
    } else if (leader_sequence_one_key(KC_U)) {
        send_string_with_delay_P(PSTR("COUNT(*) as CntOf,\n"), 10);
    } else if (leader_sequence_two_keys(KC_U,KC_U)) {
        send_string_with_delay_P(PSTR("MAX(*) as MaxOf,\n"), 10);
    } else if (leader_sequence_three_keys(KC_U,KC_U,KC_U)) {
        send_string_with_delay_P(PSTR("MIN(*) as MinOf,\n"), 10);
    } else if (leader_sequence_one_key(KC_J)) {
        send_string_with_delay_P(PSTR("DECLARE @col NVARCHAR(200) = NULL; -- set to search text or leave NULL\n"), 10);
        send_string_with_delay_P(PSTR("DECLARE @tbl NVARCHAR(200) = NULL;\n"), 10);
        send_string_with_delay_P(PSTR("DECLARE @sch NVARCHAR(200) = NULL;\n"), 10);
        send_string_with_delay_P(PSTR("DECLARE @dtype NVARCHAR(100) = NULL; -- optional data type filter\n\n"), 10);
        send_string_with_delay_P(PSTR("SELECT TABLE_CATALOG, TABLE_SCHEMA, TABLE_NAME, COLUMN_NAME, ORDINAL_POSITION, \n"), 10);
        send_string_with_delay_P(PSTR("       DATA_TYPE, CHARACTER_MAXIMUM_LENGTH, NUMERIC_PRECISION, NUMERIC_SCALE, IS_NULLABLE, COLUMN_DEFAULT\n"), 10);
        send_string_with_delay_P(PSTR("FROM INFORMATION_SCHEMA.COLUMNS\n"), 10);
        send_string_with_delay_P(PSTR("WHERE (@col   IS NULL OR COLUMN_NAME LIKE '%%' + @col + '%%')\n"), 10);
        send_string_with_delay_P(PSTR("  AND (@tbl   IS NULL OR TABLE_NAME  LIKE '%%' + @tbl + '%%')\n"), 10);
        send_string_with_delay_P(PSTR("  AND (@sch   IS NULL OR TABLE_SCHEMA LIKE '%%' + @sch + '%%')\n"), 10);
        send_string_with_delay_P(PSTR("  AND (@dtype IS NULL OR DATA_TYPE    = @dtype)\n"), 10);
        send_string_with_delay_P(PSTR("ORDER BY TABLE_SCHEMA, TABLE_NAME, ORDINAL_POSITION"), 10);
        send_string_with_delay_P(PSTR(SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)), 10);
    } else if (leader_sequence_two_keys(KC_J, KC_J)) {
        send_string_with_delay_P(PSTR("-- Search for text inside stored procedure definitions\n"), 10);
        send_string_with_delay_P(PSTR("DECLARE @search NVARCHAR(200) = ''\n"), 10);
        send_string_with_delay_P(PSTR("SELECT o.name    AS object_name,\n"), 10);
        send_string_with_delay_P(PSTR("       s.name    AS schema_name,\n"), 10);
        send_string_with_delay_P(PSTR("       m.definition\n"), 10);
        send_string_with_delay_P(PSTR("FROM sys.sql_modules m\n"), 10);
        send_string_with_delay_P(PSTR("JOIN sys.objects   o ON m.object_id = o.object_id\n"), 10);
        send_string_with_delay_P(PSTR("JOIN sys.schemas   s ON o.schema_id = s.schema_id\n"), 10);
        send_string_with_delay_P(PSTR("WHERE m.definition LIKE '%%' + @search + '%%'\n"), 10);
        send_string_with_delay_P(PSTR("  AND o.type IN ('P','PC') -- P = SQL Stored Procedure, PC = Assembly (CLR) Stored Proc\n"), 10);
        send_string_with_delay_P(PSTR("ORDER BY s.name, o.name\n"), 10);
                send_string_with_delay_P(PSTR(SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)), 10);
    } else if (leader_sequence_one_key(KC_M)) {
		send_string_with_delay_P(PSTR("DECLARE @int INT = "), 10);
    } else if (leader_sequence_two_keys(KC_M, KC_M)) {
		send_string_with_delay_P(PSTR("DECLARE @str VARCHAR(50) = ''"SS_TAP(X_LEFT)), 10);
    } else if (leader_sequence_one_key(KC_R)) {
		send_string_with_delay_P(PSTR(SS_TAP(X_HOME)"'"SS_TAP(X_END)"',"SS_TAP(X_DOWN)), 10); //wrap a line in single quotes
    } else if (leader_sequence_two_keys(KC_R,KC_R)) {
		send_string_with_delay_P(PSTR(SS_TAP(X_HOME)"\""SS_TAP(X_END)"\","SS_TAP(X_DOWN)), 10); //wrap a line in double quotes
    } else if (leader_sequence_one_key(KC_F)) {
		send_string_with_delay_P(PSTR("DBO."), 10);
    } else if (leader_sequence_one_key(KC_V)) {
        send_string_with_delay_P(PSTR(SS_LGUI("r")), 10); //run
    } else if (leader_sequence_two_keys(KC_V, KC_V)) {
        send_string_with_delay_P(PSTR(SS_LGUI("l")), 10); //log out
    } else if (leader_sequence_three_keys(KC_V, KC_V, KC_V)) {
        tap_code16(C(A(KC_DEL)));
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

const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}
);
const rgblight_segment_t PROGMEM my_sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_func_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_mous_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM my_pss_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM _yes_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_GREEN} );
const rgblight_segment_t PROGMEM _no_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 1, HSV_RED} );




const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_qwerty_layer,//
    my_sym_layer,    // Overrides caps lock layer
    my_mous_layer,    // Overrides caps lock layer
    my_func_layer,    // Overrides other layers
    my_pss_layer,     // Overrides other layers
    _yes_layer,
    _no_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(2, layer_state_cmp(state, _MOUS));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FUNC));
    rgblight_set_layer_state(4, layer_state_cmp(state, _PSS));
    return state;
}


__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  layer_clear();
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
                        update_tri_layer(_SYM, _MOUS, _PSS);
                    } else {
                        layer_off(_SYM);
                        update_tri_layer(_SYM, _MOUS, _PSS);
                    }
                    return false;
                case MO(_MOUS):
                    if (record->event.pressed) {
                        layer_on(_MOUS);
                        update_tri_layer(_SYM, _MOUS, _PSS);
                    } else {
                        layer_off(_MOUS);
                        update_tri_layer(_SYM, _MOUS, _PSS);
                    }
                    return false;
          case MS_SFTLC:
            if (record->event.pressed) {
                    // when keycode  is pressed
                    register_code16(LSFT(MS_BTN1));
                } else
                    // when keycode is released
                    unregister_code16(LSFT(MS_BTN1));

            break;
          case MS_CTLLC:
            if (record->event.pressed) {
                    // when keycode  is pressed
                    register_code16(LCTL(MS_BTN1));
                } else {
                    // when keycode is released
                    unregister_code16(LCTL(MS_BTN1));
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
                }
                // Let QMK process the KC_BSPC keycode as usual outside of shift
                return true;
            }
                    /*
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
                        */
        case GRVTI:
            if (record->tap.count && record->event.pressed) {
                //send_string_with_delay_P(PSTR("`"), 10);
                tap_code(KC_GRV);
            } else if (record->event.pressed) {
                send_string_with_delay_P(PSTR("~"), 10);
            }
		return false;
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
                tap_code16(KC_EQL);  //=
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
            /*
         case BCTRA:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_B); // Intercept tap function to send a
            } else if (record->event.pressed) {
                rgblight_blink_layer(5, 500);
                tap_code16(C(KC_A)); // Intercept hold to select all
            }
			return false;

         case XCTRX:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_X); // Intercept tap function to send x
            } else if (record->event.pressed) {
                rgblight_blink_layer(5, 500);
                tap_code16(C(KC_X)); // Intercept hold top cut
            }
			return false;
            */
         case PAT:
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_P); // Intercept tap function to send x p
            } else if (record->event.pressed) {
                tap_code16(S(KC_2)); // Intercept hold @
            }
			return false;
            /*
         case CCTRC:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_C); // Intercept tap function to send c
            } else if (record->event.pressed) {
                rgblight_blink_layer(5, 500);
                tap_code16(C(KC_C)); // Intercept hold to copy
            }
			return false;

         case VCTRV:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_V); // Intercept tap function to send v
            } else if (record->event.pressed) {
                rgblight_blink_layer(5, 500);
                tap_code16(C(KC_V)); // Intercept hold function to paste
            }
			return false;            */
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
            /*
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
			return false; */
            //}
    }
	return process_record_secrets(keycode, record);
}

