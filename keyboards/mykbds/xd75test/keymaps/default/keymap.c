#include QMK_KEYBOARD_H

#define _BASE 0

enum _layers {
    _QWERTY,
    _MAX,
    _FII,
	_BID,
	_REV,
	_USW,
	_WA,
	_PER,
	_SHRT,
	_MOUS
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
	KC_NUSER,
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
	KC_OCPA,
	KC_OCBK,
	KC_OCBR,
	KC_OCSQ,
	KC_OCDQ,
	KC_QWHR,
	KC_QLIK,
	KC_EMAIL,
	KC_MXCNT,
	KC_FICNT,
	KC_BICNT,
	KC_REVCNT,
	KC_WACNT,
	KC_USWCNT,
	KC_OPHONE,
	KC_CPHONE,
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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
			KC_A,KC_B
			)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case KC_PAS1:
			if (record->event.pressed) {
			SEND_STRING("1diot1mp!");
			}
			return false;
		case KC_PAS2:
			if (record->event.pressed) {
			SEND_STRING("Jump1ngJ4guar!");	}
			return false;
		case KC_PAS3:
			if (record->event.pressed) {
			SEND_STRING("K0rnyK0ala!");
			}
			return false;
		case KC_PAS4:
			if (record->event.pressed) {
			SEND_STRING("L0stL3pard!");
			}
			return false;
		case KC_PAS5:
			if (record->event.pressed) {
			SEND_STRING("M0rbidM0use!");
			}
			return false;
		case KC_PAS6:
			if (record->event.pressed) {
			SEND_STRING("N3roticN4rwhal!");
			}
			return false;
		case KC_PAS7:
			if (record->event.pressed) {
			SEND_STRING("P4leP3nda!");
			}
			return false;
		case KC_PAS8:
			if (record->event.pressed) {
			SEND_STRING("R4bidR4coon!");
			}
			return false;
		case KC_PAS9:
			if (record->event.pressed) {
			SEND_STRING("S1llySn4ke!");
			}
			return false;
		case KC_PAS10:
			if (record->event.pressed) {
			SEND_STRING("T4ckyT1ger!");
			}
			return false;
		case KC_PAS11:
			if (record->event.pressed) {
			SEND_STRING("V4liantVultur3!");
			}
			return false;
		case KC_PAS12:
			if (record->event.pressed) {
			SEND_STRING("W4rmW3asel!");
			}
			return false;
		case KC_NUSER:
			if (record->event.pressed) {
			SEND_STRING("P056839\n");
			}
			return false;
		case KC_EMAIL:
			if (record->event.pressed) {
			SEND_STRING("Roger.Young@Protective.com\n");
			}
			return false;
		case KC_QSLT:
			if (record->event.pressed) {
			SEND_STRING("SELECT\n"SS_TAP(X_TAB));
			return false;
			}
		case KC_IJOIN:
			if (record->event.pressed) {
			SEND_STRING("INNER JOIN \n");
			}
			return false;
		case KC_LJOIN:
			if (record->event.pressed) {
			SEND_STRING("LEFT OUTER JOIN \n");
			}
			return false;
		case KC_RJOIN:
			if (record->event.pressed) {
			SEND_STRING("RIGHT OUTER JOIN \n");
			}
			return false;
		case KC_QINS:
			if (record->event.pressed) {
			SEND_STRING("INSERT \n");
			}
			return false;
		case KC_QUPD:
			if (record->event.pressed) {
			SEND_STRING("UPDATE \n");
			}
			return false;
		case KC_QFRM:
			if (record->event.pressed) {
			SEND_STRING("FROM \n");
			}
			return false;
		case KC_QDEL:
			if (record->event.pressed) {
			SEND_STRING("DELETE \n");
			}
			return false;
		case KC_QGPB:
			if (record->event.pressed) {
			SEND_STRING("GROUP BY \n"SS_TAP(X_TAB));
			}
			return false;
		case KC_QORD:
			if (record->event.pressed) {
			SEND_STRING("ORDER BY \n"SS_TAP(X_TAB));
			}
			return false;
		case KC_OCPA:
			if (record->event.pressed) {
			SEND_STRING("()"SS_TAP(X_LEFT));
			}
			return false;
		case KC_OCBK:
			if (record->event.pressed) {
			SEND_STRING("[]"SS_TAP(X_LEFT));
			}
			return false;
		case KC_OCBR:
			if (record->event.pressed) {
			SEND_STRING("{}"SS_TAP(X_LEFT));
			}
			return false;
		case KC_OCSQ:
			if (record->event.pressed) {
			SEND_STRING("''"SS_TAP(X_LEFT));
			}
			return false;
		case KC_OCDQ:
			if (record->event.pressed) {
			SEND_STRING("\"\""SS_TAP(X_LEFT));
			}
			return false;
		case KC_QLIK:
			if (record->event.pressed) {
			SEND_STRING("LIKE '%%'"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
			}
			return false;
		case KC_QHAV:
			if (record->event.pressed) {
			SEND_STRING("HAVING \n"SS_TAP(X_LEFT));
			return false;
			}
		case KC_QWHR:
		if (record->event.pressed) {
			SEND_STRING("WHERE \n"SS_TAP(X_LEFT));
			return false;
			}
		case KC_OPHONE:
		if (record->event.pressed) {
			SEND_STRING("1-636-536-5726");
			return false;
			}
		case KC_CPHONE:
		if (record->event.pressed) {
			SEND_STRING("1-288-8007");
			return false;
			}
		case KC_MXCNT:
		if (record->event.pressed) {
			SEND_STRING("SELECT * FROM PRODTAPD.SCSVCP LIMIT 10");
			return false;
			}
		case KC_FICNT:
		if (record->event.pressed) {
			SEND_STRING("SELECT TOP 100 * FROM FIIDMART..WHVSPAMACONTRACT ");
			return false;
			}
		case KC_USWCNT:
		if (record->event.pressed) {
			SEND_STRING("SELECT * FROM QS6F.ALLWRN_VW1 LIMIT 10");
			return false;
			}
		case KC_BICNT:
		if (record->event.pressed) {
			SEND_STRING("SELECT TOP 10 * FROM BI_DM_ASSETPROTECTION..CONTRACTCOVERAGE");
			return false;
			}
		case KC_WACNT:
		if (record->event.pressed) {
			SEND_STRING("SELECT TOP 10 * FROM BI_DM_ASSETPROTECTION..CONTRACTCOVERAGE");
			return false;
			}
		case KC_REVCNT:
		if (record->event.pressed) {
			SEND_STRING("SELECT TOP 10 * FROM BI_DM_ASSETPROTECTION..CONTRACTCOVERAGE");
			return false;
			}
	}
	return true;
}
