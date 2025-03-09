#include QMK_KEYBOARD_H

#define _BASE 0

enum _layers {
    _QWERTY,
	_SHRT,
	_PER
};

enum combos {
  DF_LAYER,
  JK_LAYER,
  FG_LAYER,
  HJ_LAYER
};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [DF_LAYER] = COMBO(df_combo, OSL(1)),
  [JK_LAYER] = COMBO(jk_combo, OSL(1)),
  [FG_LAYER] = COMBO(fg_combo, OSL(2)),
  [HJ_LAYER] = COMBO(hj_combo, OSL(2)),
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
	KC_BKWD,
	KC_QTWD,
	KC_CMAL,
	USER,
	PHONE,
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
	KC_PAS12
};

#define KC_WNLO LGUI(KC_L)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
			QK_GESC,     KC_1,    KC_2,     KC_3,     KC_4,    KC_5, QK_GESC,     KC_6,       KC_7,       KC_8,    KC_9,    KC_0, KC_MINS, KC_EQL,  KC_BSPC,
			 KC_TAB,     KC_Q,    KC_W,     KC_E,     KC_R,    KC_T,   KC_NO,     KC_Y,       KC_U,       KC_I,    KC_O,    KC_P, KC_LBRC,KC_RBRC,  KC_BSLS,
			KC_LEAD,     KC_A,    KC_S,     KC_D,     KC_F,    KC_G, KC_LEAD,     KC_H,       KC_J,       KC_K,    KC_L, KC_SCLN, KC_QUOT, KC_ENT,   KC_ENT,
			KC_LSFT,     KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,   KC_NO,     KC_N,       KC_M,    KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,  KC_UP,    KC_NO,
			KC_WNLO,  KC_LCTL, KC_LGUI,  KC_LALT,   KC_SPC,  KC_SPC,   KC_NO,   KC_SPC,     KC_SPC,      KC_NO,   KC_NO,   KC_NO, KC_LEFT,KC_DOWN, KC_RIGHT
			)
		,
		[_SHRT] = LAYOUT(
			KC_TRNS,    KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,  KC_TRNS,   KC_F6,      KC_F7,      KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_TRNS,
			KC_TRNS,  KC_TRNS,  KC_QWHR,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,    KC_QUPD,    KC_QINS, KC_QORD, KC_TRNS, KC_BKWD, KC_TRNS, KC_TRNS,
			KC_TRNS,  KC_TRNS,  KC_QSLT,  KC_QDEL, KC_QFRM, KC_QGPB,  KC_TRNS, KC_QHAV,    KC_TRNS,    KC_TRNS, KC_QLIK, KC_TRNS, KC_QTWD, KC_TRNS, KC_TRNS, 
			KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_BTWN,  KC_TRNS, KC_TRNS,    KC_TRNS,    KC_CMAL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_LJOIN,KC_IJOIN,KC_RJOIN
		)
		,
		[_PER] = LAYOUT(
			KC_TRNS,  KC_PAS1,  KC_PAS2,  KC_PAS3, KC_PAS4, KC_PAS5,  KC_TRNS, KC_PAS6,    KC_PAS7,    KC_PAS8, KC_PAS9,KC_PAS10,KC_PAS11,KC_PAS12, KC_TRNS, 
			KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,       USER,    KC_TRNS, KC_TRNS,   PHONE, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
			KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS		
		)

};

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  // Key Matrix to LED Index
		{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}//,
		//{10,11,12,13,14,15,16,17,18,19}//,
		//{20,21,22,23,24,25,26,27,28,29},
	//	{30,31,32,33,34,35,36,37,38},
}, {
  // LED Index to Physical Position
	  {6,112},  {25,112}, {50,112}, {75,112}, {100,112}, {124,112}, {149,112}, {174,112}, {199,112}, {224,112}//,
     //{65,112},  {71,112}, {77,112}, {83,112}, {88,112}, {94,112},{100,112},{106,112},{112,112},{118,112}//,
	// {124,112},{130,112},{136,112},{141,112},{147,112},{153,112},{159,112},{165,112},{171,112},{177,112},
	// {183,112},{189,112},{195,112},{200,112},{206,112},{212,112},{218,112},{224,112},{230,112}
}, {
  // LED Index to Flag
		  4,4,4,4,4,4,4,4,4,4//,
		 // 4,4,4,4,4,4,4,4,4,4//,
		 // 4,4,4,4,4,4,4,4,4,4,
		 // 4,4,4,4,4,4,4,4,4
} 
};
#endif

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_D) {
	  send_string_with_delay_P(PSTR("[DBO]."), 10);
	}
    SEQ_ONE_KEY(KC_Q) {
	  send_string_with_delay_P(PSTR("[QS36F]."), 10);
    }
	SEQ_ONE_KEY(KC_P) {
	  send_string_with_delay_P(PSTR("[PRODTAPD]."), 10);
    }
	SEQ_ONE_KEY(KC_V) {
	  send_string_with_delay_P(PSTR("[VTSINT]."), 10);
    }
	SEQ_ONE_KEY(KC_I) {
	  send_string_with_delay_P(PSTR("[ICORPD]."), 10);
    }
	SEQ_ONE_KEY(KC_QUOT) {
	  send_string_with_delay_P(PSTR("''" SS_TAP(X_LEFT)), 10);
    }
	SEQ_TWO_KEYS(KC_QUOT, KC_QUOT) {
	  send_string_with_delay_P(PSTR("'%%'" SS_TAP(X_LEFT) SS_TAP(X_LEFT)), 10);
    }
	SEQ_THREE_KEYS(KC_QUOT, KC_QUOT, KC_QUOT) {
	  send_string_with_delay_P(PSTR("\"\"" SS_TAP(X_LEFT)), 10);
    }
	SEQ_FOUR_KEYS(KC_QUOT, KC_QUOT, KC_QUOT, KC_QUOT) {
	  send_string_with_delay_P(PSTR("\"%%\"" SS_TAP(X_LEFT)), 10);
    }
    SEQ_ONE_KEY(KC_LBRC) {
	  send_string_with_delay_P(PSTR("[]" SS_TAP(X_LEFT)), 10);
    }
	SEQ_TWO_KEYS(KC_LBRC, KC_LBRC) {
	  send_string_with_delay_P(PSTR("{}" SS_TAP(X_LEFT)), 10);
    }
	SEQ_ONE_KEY(KC_RBRC) {
	  send_string_with_delay_P(PSTR("()" SS_TAP(X_LEFT)), 10);
    }
	SEQ_TWO_KEYS(KC_RBRC, KC_RBRC) {
	  send_string_with_delay_P(PSTR("<>" SS_TAP(X_LEFT)), 10);
    }
	SEQ_TWO_KEYS(KC_X, KC_C) {
	  send_string_with_delay_P(PSTR("Max Contract"), 10);
    }
	SEQ_TWO_KEYS(KC_P, KC_P) {
	  send_string_with_delay_P(PSTR("PROTBPLD."), 10);
    }
	SEQ_TWO_KEYS(KC_F, KC_C) {
      SEND_STRING("FI Contract");
    }
	SEQ_TWO_KEYS(KC_W, KC_C) {
	  send_string_with_delay_P(PSTR("WA Contract"), 10);
    }
	SEQ_TWO_KEYS(KC_B, KC_C) {
	  send_string_with_delay_P(PSTR("BI Contract"), 10);
    }
	SEQ_TWO_KEYS(KC_R, KC_C) {
	  send_string_with_delay_P(PSTR("RV Contract"), 10);
    }
	SEQ_TWO_KEYS(KC_X, KC_L) {
	  send_string_with_delay_P(PSTR("Max Claim"), 10);
    }
	SEQ_TWO_KEYS(KC_F, KC_L) {
	  send_string_with_delay_P(PSTR("FI Claim"), 10);
    }
	SEQ_TWO_KEYS(KC_W, KC_L) {
	  send_string_with_delay_P(PSTR("WA Claim"), 10);
    }
	SEQ_TWO_KEYS(KC_B, KC_L) {
	  send_string_with_delay_P(PSTR("BI Claim"), 10);
    }
	SEQ_TWO_KEYS(KC_R, KC_L) {
	  send_string_with_delay_P(PSTR("RV Claim"), 10);
    }
	SEQ_TWO_KEYS(KC_S, KC_SLSH) {
      send_string_with_delay_P(PSTR("SELECT TABLE_SCHEMA, TABLE_NAME, COLUMN_NAME, ORDINAL_POSITION, \n"), 10);
	  send_string_with_delay_P(PSTR("DATA_TYPE, CHARACTER_MAXIMUM_LENGTH, NUMERIC_PRECISION, NUMERIC_SCALE \n"), 10);
	  send_string_with_delay_P(PSTR("FROM [INFORMATION_SCHEMA].[COLUMNS] \n"), 10);
	  send_string_with_delay_P(PSTR("WHERE COLUMN_NAME like '%%' \n"), 10);
	  send_string_with_delay_P(PSTR("AND TABLE_NAME like '%%' \n"), 10);
	  send_string_with_delay_P(PSTR("AND TABLE_SCHEMA like '%%' \n"), 10);
    }
	SEQ_TWO_KEYS(KC_A, KC_SLSH) {
      send_string_with_delay_P(PSTR("SELECT tab.TABLE_SCHEMA, tab.TABLE_NAME, col.COLUMN_NAME, col.ORDINAL_POSITION, \n"), 10);
	  send_string_with_delay_P(PSTR("col.DATA_TYPE, col.LENGTH, col.NUMERIC_SCALE \n"), 10);
	  send_string_with_delay_P(PSTR("FROM [QSYS2].[SYSTABLES] tab \n"), 10);
	  send_string_with_delay_P(PSTR("INNER JOIN [QSYS2].[SYSCOLUMNS] col \n"), 10);
	  send_string_with_delay_P(PSTR("ON tab.TABLE_NAME = col.TABLE_NAME \n"), 10);
	  send_string_with_delay_P(PSTR("WHERE col.COLUMN_NAME like '%%' \n"), 10);
	  send_string_with_delay_P(PSTR("AND tab.TABLE_NAME like '%%' \n"), 10);
	  send_string_with_delay_P(PSTR("AND tab.TABLE_SCHEMA like '%%' \n"), 10);
    }
    }
  }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
		
	const uint8_t mods = get_mods();
	const uint8_t oneshot_mods = get_oneshot_mods();
	
    switch (keycode) {
		case KC_PAS1:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("1diot1mp!"), 10);
			}
			return false;
		case KC_PAS2:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("Jump1ngJ4guar!"), 10);	
			}
			return false;
		case KC_PAS3:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("K0rnyK0ala!"), 10);
			}
			return false;
		case KC_PAS4:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("L0stL3pard!"), 10);
			}
			return false;
		case KC_PAS5:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("M0rbidM0use!"), 10);
			}
			return false;
		case KC_PAS6:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("N3roticN4rwhal!"), 10);
			}
			return false;
		case KC_PAS7:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("P4leP3nda!"), 10);
			}
			return false;
		case KC_PAS8:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("R4bidR4coon!"), 10);
			}
			return false;
		case KC_PAS9:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("S1llySn4ke!"), 10);
			}
			return false;
		case KC_PAS10:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("T4ckyT1ger!"), 10);
			}
			return false;
		case KC_PAS11:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("V4liantVultur3!"), 10);
			}
			return false;
		case KC_PAS12:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("W4rmW3asel!"), 10);
			}
			return false;
		case KC_QSLT:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("SELECT\n"SS_TAP(X_TAB)), 10);
			return false;
			}
		case KC_IJOIN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("INNER JOIN \n"), 10);
			}
			return false;
		case KC_LJOIN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("LEFT OUTER JOIN \n"), 10);
			}
			return false;
		case KC_RJOIN:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("RIGHT OUTER JOIN \n"), 10);
			}
			return false;
		case KC_QINS:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("IN (, )" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)), 10);
			}
			return false;
		case KC_QUPD:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("UPDATE \n"), 10);
			}
			return false;
		case KC_QFRM:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("FROM \n"), 10);
			}
			return false;
		case KC_QDEL:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("DELETE \n"), 10);
			}
			return false;
		case KC_QCNT:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("COUNT(*) as cnt,\n"), 10);
			}
			return false;
		case KC_QGPB:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("GROUP BY \n" SS_TAP(X_TAB)), 10);
			}
			return false;
		case KC_QORD:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("ORDER BY \n"SS_TAP(X_TAB)), 10);
			}
			return false;
		case KC_QLIK:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("LIKE '%%'"SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);
			}
			return false;
		case KC_QHAV:
			if (record->event.pressed) {
			send_string_with_delay_P(PSTR("HAVING \n"SS_TAP(X_LEFT)), 10);
			return false;
			}
		case KC_QWHR:
		if (record->event.pressed) {
			send_string_with_delay_P(PSTR("WHERE \n"SS_TAP(X_LEFT)), 10);
			return false;
			}
		case KC_BTWN:
		if (record->event.pressed) {
			send_string_with_delay_P(PSTR("BETWEEN  AND"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)), 10);
			return false;
			}
		case KC_BKWD:
		if (record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_DOWN(X_LCTRL) SS_DOWN(X_LSHIFT) SS_TAP(X_LEFT) SS_UP(X_LCTRL) SS_UP(X_LSHIFT) SS_DOWN(X_LCTRL) "c" SS_UP(X_LCTRL) SS_TAP(X_BSPC) "[" SS_DOWN(X_LCTRL) "v" SS_UP(X_LCTRL)"]."), 10);
			return false;
			}
		case KC_QTWD:
		if (record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_DOWN(X_LCTRL) SS_DOWN(X_LSHIFT) SS_TAP(X_LEFT) SS_UP(X_LCTRL) SS_UP(X_LSHIFT) SS_DOWN(X_LCTRL) "c" SS_UP(X_LCTRL) SS_TAP(X_BSPC) "'" SS_DOWN(X_LCTRL) "v" SS_UP(X_LCTRL)"'"), 10);
			return false;
			}
		case KC_CMAL:
		if (record->event.pressed) {
			send_string_with_delay_P(PSTR(SS_DOWN(X_LCTRL) SS_DOWN(X_LSHIFT) SS_TAP(X_LEFT) SS_UP(X_LCTRL) SS_UP(X_LSHIFT) SS_TAP(X_LEFT) "," SS_TAP(X_UP)), 10);
			return false;
			}
		case PHONE:
			if (record->event.pressed) {
			  clear_mods();  // Temporarily disable mods.
			  clear_oneshot_mods();
			  if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
				send_string_with_delay_P(PSTR("636-536-5726"), 10);
			  } else {
				send_string_with_delay_P(PSTR("636-288-8007"), 10);
			  }
			  set_mods(mods);  // Restore mods.
			}
			return false;
		case USER:
			if (record->event.pressed) {
			  clear_mods();  // Temporarily disable mods.
			  clear_oneshot_mods();
			  if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
				send_string_with_delay_P(PSTR("P056839"), 10);
			  } else {
				send_string_with_delay_P(PSTR("Roger.Young@Protective.com"), 10);
			  }
			  set_mods(mods);  // Restore mods.
			}
			return false;

	}
	return true;
}
