#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap5
enum layer_names {
    _QWERTY,
	_SYM,
	_SQL,
	_KYBNAV,
	_PSS
	_MOUSE
};

//#define KC_LOWER  MO(_LOWER)
//#define KC_RAISE  MO(_RAISE)

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
    KC_PAS13,
	KC_PAS14,
	KC_PAS15,
	KC_PAS16,
	KC_PAS17,
	KC_PAS18,
	KC_PAS19,
	KC_PAS20,
	KC_PAS21,
	KC_PAS22,
	KC_PAS23,
	KC_PAS24,
	KC_PAS25,
	KC_PAS28,
	KC_DECLA,
	KC_INDQ, 
	KC_LKDQ,
	KC_LOJ,
	KC_LSFT,
	KC_SELEC,
	KC_WHERE,
	KC_INSQ,
	KC_LKSQ,
	KC_IJ,
	KC_GRPB,
	KC_HAVIN,   
	KC_ORDBY,
	KC_ALTTA, 
	KC_FOJ,
	KC_CNTO, 
	KC_AVGO,
	KC_IN,
	KC_BTWN
	};
	
enum combos {
  sd_ent,
  kl_spc,
  wer_lysql,
  sdf_lysym,
  xcv_lypss,
  uio_lysql,
  jkl_lysym,
  mcommaddot_lypss,
  asdf_lymouse,
  zxcv_lykybnav
};

const uint16_t PROGMEM sd_ent[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM kl_spc[] = {KC_K, KC_L, COMBO_END};

const uint16_t PROGMEM wer_lysql[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM sdf_lysym[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM xcv_lypss[] = {KC_X, KC_C, KC_V, COMBO_END};

const uint16_t PROGMEM uio_lysql[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM jkl_lysym[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM mcommaddot_lypss[] = {KC_M, KC_COMM, KC_DOT, COMBO_END};

const uint16_t PROGMEM asdf_lymouse[] = {KC_A, KC_S, KC_D, KD_F, COMBO_END};
const uint16_t PROGMEM zxcv_lykybnav[] = {KC_Z, KC_X, KC_C, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [SD_ENT] = COMBO(sd_ent, KC_ENT),
  [KL_SPC] = COMBO(kl_spc, KC_SPC),
  
  [WER_LYSQL] = COMBO(wer_lysql, MO(_SQL)),
  [SDF_LYSYM] = COMBO(sdf_lysym, MO(_SYM)),
  [XCV_LYPSS] = COMBO(xcv_lypss, MO(_PSS)),
  [UIO_LYSQL] = COMBO(uio_lysql, MO(_SQL)), 
  [JKL_LYSYM] = COMBO(jkl_lysym, MO(_SYM)),  
  [MCOMDOT_LYPSS] = COMBO(mcommaddot_lypss, MO(_PSS)),  

  [ASDF_LYMS] = COMBO(asdf_lymouse, MO(_MOUSE)),
  [ZXCV_LYKN] = COMBO(zxcv_lykybnav,MO(_KYBNAV))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|````
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI | Alt  | App  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT(
                KC_GRAVE,  KC_1,    KC_2,    KC_3,     KC_4,               KC_5,           KC_MUTE,                             KC_MUTE,         KC_6,     KC_7,       KC_8,    KC_9,       KC_0,   KC_MINUS, 
                  KC_ESC,  KC_Q,    KC_W,    KC_E,     KC_R,      LT(_SQL,KC_T),                                                        LT(_SQL,KC_Y),     KC_U,       KC_I,    KC_O,       KC_P,    KC_BSPC, 
				  KC_TAB,  KC_A,    KC_S,    KC_D,     KC_F,      LT(_SYM,KC_G),                                                        LT(_SYM,KC_H),     KC_J,       KC_K,    KC_L,    KC_SCLN,    KC_QUOT,  
                 KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,      LT(_PSS,KC_B),          KC_RAISE,                            KC_RAISE,LT(_PSS,KC_N),     KC_M,    KC_COMM,  KC_DOT,    KC_SLSH,    KC_RSFT,
        KC_LEAD,                                             KC_LCTL, KC_LGUI, KC_LALT,   KC_LOWER,    KC_SPC,     KC_ENT,     KC_LOWER,  KC_RALT,  KC_RGUI,   KC_RCTL,  				 			         KC_LEAD
    ),
[_SYM] = LAYOUT(
                 _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,              KC_F5,           _______,                             _______,        KC_F6,    KC_F7,      KC_F8,   KC_F9,     KC_F10,     _______, 
                 _______,   KC_1,    KC_2,    KC_3,    KC_4,               KC_5,                                                                 KC_6,     KC_7,       KC_8,    KC_9,       KC_0,      KC_DEL,
				 _______,KC_EXLM,   KC_AT, KC_HASH,  KC_DLR,            KC_PERC,                                                              KC_CIRC,  KC_AMPR,    KC_ASTR, KC_LPRN,    KC_RPRN,     KC_PIPE, 
                 _______, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR,            KC_RCBR,           _______,                             _______,      KC_LBRC,  KC_RBRC,    KC_SCLN, KC_COLN,    KC_BSLS,     KC_RCTL,
        _______,                                            _______, _______, _______,     _______,   _______,     _______,     _______,   _______, _______,    _______,  				 			         _______
    )   ,
[_SQL] = LAYOUT(
                 _______, _______, _______,_______, _______,           _______,            _______,                             _______,      _______, _______,    _______, _______,    _______,    _______, 
                 _______,KC_DECLA, _______,KC_INDQ, KC_LKDQ,            KC_LOJ,                                                               _______, _______,      KC_IN,KC_ORDBY,    _______,    _______,
				 _______,KC_SELEC,KC_WHERE,KC_INSQ, KC_LKSQ,             KC_IJ,                                                               KC_GRPB,KC_HAVIN,   KC_ORDBY, _______,    _______,    _______,  
                 _______,KC_ALTTA, _______,  KC_IN, KC_BTWN,            KC_FOJ,            _______,                             _______,      KC_CNTO, KC_AVGO,    _______, _______,    _______,    _______,
       _______,                                             _______, _______, _______,     _______,   _______,     _______,     _______,   _______, _______,    _______,  				 			         _______
    ) , 
[_KYBNAV] = LAYOUT(
                 _______,   KC_1,    KC_2,    KC_3,    KC_4,               KC_5,           _______,                             _______,         KC_6,     KC_7,       KC_8,    KC_9,       KC_0,    _______, 
                 _______, KC_INS, KC_PSCR, XXXXXXX, XXXXXXX,            XXXXXXX,                                                              KC_PGUP, KC_PRVWD,      KC_UP,KC_NXTWD,   KC_DLINE,     KC_DEL, 
				 _______,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX,                                                              KC_PGDN,  KC_LEFT,    KC_DOWN, KC_RGHT,    _______,    _______,  
                 _______,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX,           _______,                             _______,      XXXXXXX, KC_LSTRT,    XXXXXXX, KC_LEND,    XXXXXXX,    _______,
       _______,                                             _______, _______, _______,     _______,   _______,     _______,     _______,   _______, _______,    _______,  				 			         _______
    ),
[_PSS] = LAYOUT(
                 _______, _______, _______,_______, _______,           _______,            _______,                             _______,      _______,  _______,    _______, _______,    _______,    _______, 
                 _______,KC_PAS17,KC_PAS23,KC_PAS5,KC_PAS18,          KC_PAS20,                                                              KC_PAS25, KC_PAS21,    KC_PAS9,KC_PAS15,   KC_PAS16,    _______, 
				 _______, KC_PAS1,KC_PAS19,KC_PAS4, KC_PAS6,           KC_PAS7,                                                               KC_PAS8, KC_PAS10,   KC_PAS11,KC_PAS12,    _______,    _______,  
                 _______,KC_PAS1,KC_PAS24,KC_PAS3,KC_PAS22,           KC_PAS2,            _______,                             _______,     KC_PAS14, KC_PAS13,    _______, _______,    _______,    _______,
       _______,                                             _______, _______, _______,     _______,   _______,      _______,    _______,   _______,  _______,    _______,  				 			         _______
    ),
[_MOUSE] = LAYOUT(
                 _______, _______, _______,_______, _______,           _______,           _______,                              _______,      _______,  _______,    _______, _______,    _______,    _______, 
                 _______, _______, _______,_______, _______,           _______,                                                				  _______,  KC_BTN1,    KC_BTN3, KC_BTN2,    _______,    _______, 
				 _______, _______, _______,_______, _______,           _______,                                                               _______,  KC_MS_L,    KC_MS_U, KC_MS_R,    _______,    _______,  
                 _______, _______, _______,_______, _______,           _______,           _______,                              _______,      _______,  _______,    KC_MS_D, _______,    _______,    _______,
       _______,                                             _______, _______, _______,    _______,   _______,       _______,    _______,   _______,  _______,    _______,  				 			         _______
    )   
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

   SEQ_ONE_KEY(KC_U) {
      // Anything you can do in a macro.
      send_string_with_delay_P(PSTR("P056839"), 12);
    }

   SEQ_ONE_KEY(KC_P) {
      // Anything you can do in a macro.
      send_string_with_delay_P(PSTR("636-536-5726"), 12);
    }

    SEQ_TWO_KEYS(KC_U, KC_U) {
       send_string_with_delay_P(PSTR("roger.young@protective.com", 12);
    }

    SEQ_TWO_KEYS(KC_P, KC_P) {
       send_string_with_delay_P(PSTR("636-288-8007"), 12);
    }


  }
}

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
		case KC_PAS1:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("4Nnoying4Nt!"), 12);
			layer_clear();return false;}
		case KC_PAS2:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("B0ringB4t!"), 12);
			layer_clear();return false;}
		case KC_PAS3:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("Cr4zyC4t!"), 12);
			layer_clear();return false;}
		case KC_PAS4:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("D0peyD1ngo"), 12);
			layer_clear();return false;}
		case KC_PAS5:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("3Nvious3Lephant!"), 12);
			layer_clear();return false;}
		case KC_PAS6:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("F1estyF1sh!"), 12);
			layer_clear();return false;}
		case KC_PAS7:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("G0ryG0rilla!"), 12);
			layer_clear();return false;}
		case KC_PAS8:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("H4ppyH1ppo!"), 12);
			layer_clear();return false;}
		case KC_PAS9:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("1Diot1Mp!"), 12);
			layer_clear();return false;}
		case KC_PAS10:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("Jump1ngJ4guar!"), 12);	
			layer_clear();return false;}
		case KC_PAS11:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("K0rnyK0ala!"), 12);
			layer_clear();return false;}
		case KC_PAS12:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("L0stL3pard!"), 12);
			layer_clear();return false;}
		case KC_PAS13:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("M0rbidM0use!"), 12);
			layer_clear();return false;}
		case KC_PAS14:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("N3roticN4rwhal!"), 12);
			layer_clear();return false;}
		case KC_PAS15:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("0Vert0Ctopus!"), 12);
			layer_clear();return false;}
		case KC_PAS16:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("P4leP3nda!"), 12);
			layer_clear();return false;}
		case KC_PAS17:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("Qu1etQu4il!"), 12);
			layer_clear();return false;}
		case KC_PAS18:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("R4bidR4coon!"), 12);
			layer_clear();return false;}
		case KC_PAS19:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("S1llySn4ke!"), 12);
			layer_clear();return false;}
		case KC_PAS20:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("T4ckyT1ger!"), 12);
			layer_clear();return false;}
		case KC_PAS21:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("Us3lessU4kari!"), 12);
			layer_clear();return false;}
		case KC_PAS22:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("V4liantVultur3!"), 12);
			layer_clear();return false;}
		case KC_PAS23:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("W4rmW3asel!"), 12);
			layer_clear();return false;}
		case KC_PAS24:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("X3nophobicX3rus!"), 12);
			layer_clear();return false;}
		case KC_PAS25:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("Y0ungY4k!"), 12);
			layer_clear();return false;}
		case KC_PAS26:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("Z3alousZ3bra!"), 12);
			layer_clear();return false;}
		case KC_DECLA:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("Declare @variable as "), 12);
			layer_clear();return false;}	
		case KC_INDQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" IN (\"\",\"\")" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)), 12);
			layer_clear();return false;}	
		case KC_INSQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("IN (, )" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)), 12);
			layer_clear();return false;}	
		case KC_IN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("IN (, )" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)), 12);
			layer_clear();return false;}				
		case KC_LKDQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("LIKE \"%%\""SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			layer_clear();return false;}
		case KC_LKSQ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("LIKE '%%'"SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			layer_clear();return false;}
		case KC_LOJ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("LEFT OUTER JOIN  ON"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			layer_clear();return false;}
		case KC_SELEC:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("SELECT\n * \n FROM "), 12);
			layer_clear();return false;}
		case KC_WHERE:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR(" WHERE "), 12);
			layer_clear();return false;}
		case KC_IJ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("INNER JOIN  ON"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			layer_clear();return false;}
		case KC_GRPB:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("GROUP BY \n" SS_TAP(X_TAB)), 12);
			layer_clear();return false;}
		case KC_HAVIN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("HAVING \n"SS_TAP(X_LEFT)), 12);
			layer_clear();return false;}
 		case KC_ORDBY:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("ORDER BY \n"SS_TAP(X_TAB)), 12);
			layer_clear();return false;}  
 		case KC_ALTTA:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("ALTER TABLE \n"SS_TAP(X_TAB)), 12);
			layer_clear();return false;}  
 		case KC_FOJ:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("FULL OUTER JOIN  ON"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
			layer_clear();return false;}  
 		case KC_CNTO:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("COUNT(*) as cntof, \n"), 12);
			layer_clear();return false;} 
 		case KC_AVGO:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("AVG(*) as avgof, \n"), 12);
			layer_clear();return false;} 
 		case KC_BTWN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("BETWEEN  AND"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 12);
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
