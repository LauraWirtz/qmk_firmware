/* Copyright 2020 IFo Hancroft
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers{
  BASE,
  QWERTY,
  NUM,
  SYM
};

enum {
	TD_LANG_IME,
};

enum custom_keycodes {
	UMLAUT_UE = SAFE_RANGE,
	UMLAUT_AE,
	UMLAUT_OE,
	UMLAUT_EURO,
	UMLAUT_ESZETT,
	LANG_IME = TD(TD_LANG_IME),
};


void lang_ime(tap_dance_state_t *state, void *user_data) {
	 switch (state->count) {
		case 1:
			SEND_STRING(SS_LGUI("r"));	//Screen Reader
			break;
		case 2:
			SEND_STRING(SS_LCTL(" "));	//Toggle IME
		case 3:
			SEND_STRING(SS_LGUI(" "));	//none
			break;
	}
}

tap_dance_action_t tap_dance_actions[] = {
	[TD_LANG_IME] = ACTION_TAP_DANCE_FN(lang_ime),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case UMLAUT_AE:
			if (record->event.pressed) {
				if (get_mods() & MOD_MASK_SHIFT) {
					SEND_STRING(SS_TAP(X_CAPS) SS_DOWN(X_LSFT) SS_TAP(X_QUOT) SS_TAP(X_A) SS_UP(X_LSFT));
				} else {
					SEND_STRING(SS_TAP(X_CAPS) SS_DOWN(X_LSFT) SS_TAP(X_QUOT) SS_UP(X_LSFT) SS_TAP(X_A));
				}
			}return false;
		case UMLAUT_UE:
			if (record->event.pressed) {
				if (get_mods() & MOD_MASK_SHIFT) {
					SEND_STRING(SS_TAP(X_CAPS) SS_DOWN(X_LSFT) SS_TAP(X_QUOT) SS_TAP(X_U) SS_UP(X_LSFT));
				} else {
					SEND_STRING(SS_TAP(X_CAPS) SS_DOWN(X_LSFT) SS_TAP(X_QUOT) SS_UP(X_LSFT) SS_TAP(X_U));
				}
			}return false;
		case UMLAUT_OE:
			if (record->event.pressed) {
				if (get_mods() & MOD_MASK_SHIFT) {
					SEND_STRING(SS_TAP(X_CAPS) SS_DOWN(X_LSFT) SS_TAP(X_QUOT) SS_TAP(X_O) SS_UP(X_LSFT));
				} else {
					SEND_STRING(SS_TAP(X_CAPS) SS_DOWN(X_LSFT) SS_TAP(X_QUOT) SS_UP(X_LSFT) SS_TAP(X_O));
				}
			}return false;
		case UMLAUT_EURO:
			if (record->event.pressed) {SEND_STRING(SS_TAP(X_CAPS) SS_TAP(X_EQL) SS_TAP(X_E));}return false;
		case UMLAUT_ESZETT:
			if (record->event.pressed) {SEND_STRING(SS_TAP(X_CAPS) SS_TAP(X_S) SS_TAP(X_S));}return false;
		}
	return true;
};

bool rgb_matrix_indicators_user(void) {
	if(IS_LAYER_ON(QWERTY)) {
		for (uint8_t i = 0; i < 75; i++) {
			if (i != 36 && i != 37 && i != 38 && i != 52) {
				rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
			}
		}
	} else {
		rgb_matrix_set_color_all(0x00, 0x00, 0x00);
	}
	return true;
}

//R5 60-74
//R4 45-59
//R3 30-44
//R2 15-29
//R1 0-14


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ortho_5x15(
	KC_F1,				KC_F2,				KC_F3,				KC_F4,				KC_F5,				KC_F6,				KC_F7,				KC_F8,				KC_F9,				KC_F10,				KC_F11,				KC_F12,				_______,			_______,			_______,
	KC_W, 				KC_F,				KC_M,				KC_P,				KC_V,				KC_TAB, 			KC_Q,				KC_W,				KC_E,				KC_R,				KC_COMM,			KC_DOT,				KC_Q,				KC_Z,				KC_J,
	LSFT_T(KC_R),		LCTL_T(KC_S),		LGUI_T(KC_N),		LALT_T(KC_T),		KC_B,				KC_ESC, 			KC_A,				KC_S,				KC_D,				KC_F,				KC_MINS,			RALT_T(KC_A),		RGUI_T(KC_E),		RCTL_T(KC_I),		RSFT_T(KC_H),
	KC_X,				KC_C,				KC_L,				KC_D,				KC_G,				KC_LSFT,			KC_Z,				KC_X,				KC_C,				KC_V,				KC_SLSH,			KC_U,				KC_O,				KC_Y,				KC_K,
	KC_ESC,				KC_LSFT,			_______,			KC_TAB,				LT(NUM, KC_SPC),	KC_LCTL,			KC_LGUI,			TG(QWERTY),			KC_LALT,			KC_SPC,				LT(SYM, KC_ENT),	LM(SYM, MOD_LSFT),	_______,			_______,			_______
	),
  [QWERTY] = LAYOUT_ortho_5x15(
	_______,			_______,			_______,			_______,			_______,			KC_1,				KC_2,				KC_3,				KC_4,				KC_5,				KC_6,				KC_7,				KC_8,				KC_9,				KC_0,
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______
	),
  [NUM] = LAYOUT_ortho_5x15(
	_______,			_______,			_______,			_______,			_______,			_______,			RGB_TOG,			RGB_RMOD,			RGB_MOD,			_______,			_______,			_______,			_______,			_______,			QK_BOOT,
	_______,			KC_BSPC,			KC_UP,				KC_DEL,				_______,			_______,			RGB_HUI,			RGB_SAI,			RGB_VAI,			RGB_SPI,			_______,			KC_7,				KC_8,				KC_9,				KC_0,
	_______,			KC_LEFT,			KC_DOWN,			KC_RIGHT,			_______,			_______,			RGB_HUD,			RGB_SAD,			RGB_VAD,			RGB_SPD,			_______,			RALT_T(KC_4),		RGUI_T(KC_5),		RCTL_T(KC_6),		_______,
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			KC_1,				KC_2,				KC_3,				_______,
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			LT(SYM, KC_0),		_______,			_______,			_______,			_______
	),
  [SYM] = LAYOUT_ortho_5x15(
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			KC_LBRC,			KC_RBRC,			KC_GRV,				_______,
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			KC_SCLN,			KC_QUOT,			KC_EQL,				KC_BSLS,
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______
	)
};
