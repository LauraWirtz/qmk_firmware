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
  FKEYS,
  QWERTY,
  FN,
  FN1
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


const uint16_t PROGMEM combo_EQL[] = {KC_DOT, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_GRV[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_QUOT[] = {KC_MINS, RALT_T(KC_A), COMBO_END};
const uint16_t PROGMEM combo_BSLS[] = {KC_SLSH, KC_U, COMBO_END};
const uint16_t PROGMEM combo_SCLN[] = {RALT_T(KC_A), RGUI_T(KC_E), COMBO_END};
const uint16_t PROGMEM combo_LBRC[] = {RALT_T(KC_A), KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_RBRC[] = {RGUI_T(KC_E), KC_Q, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_EQL, KC_EQL),
    COMBO(combo_GRV, KC_GRV),
    COMBO(combo_QUOT, KC_QUOT),
    COMBO(combo_BSLS, KC_BSLS),
    COMBO(combo_SCLN, KC_SCLN),
    COMBO(combo_LBRC, KC_LBRC),
    COMBO(combo_RBRC, KC_RBRC),
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
		rgb_matrix_set_color(36, 0x50, 0x08, 0x05);
		rgb_matrix_set_color(37, 0x50, 0x08, 0x05);
		rgb_matrix_set_color(38, 0x50, 0x08, 0x05);
		rgb_matrix_set_color(52,0x50, 0x08, 0x05);
	} else if(IS_LAYER_ON(FKEYS)){
		rgb_matrix_set_color(22, 0x50, 0x08, 0x05);
		rgb_matrix_set_color(23, 0x50, 0x08, 0x05);
		rgb_matrix_set_color(24, 0x50, 0x08, 0x05);
		rgb_matrix_set_color(37, 0x50, 0x08, 0x05);
		rgb_matrix_set_color(38, 0x50, 0x08, 0x05);
		rgb_matrix_set_color(39, 0x50, 0x08, 0x05);
		rgb_matrix_set_color(52, 0x50, 0x08, 0x05);
		rgb_matrix_set_color(53, 0x50, 0x08, 0x05);
		rgb_matrix_set_color(54, 0x50, 0x08, 0x05);
		rgb_matrix_set_color(67, 0x50, 0x08, 0x05);
		rgb_matrix_set_color(68, 0x50, 0x08, 0x05);
		rgb_matrix_set_color(69, 0x50, 0x08, 0x05);
	} else {
		if(host_keyboard_led_state().num_lock){
			//(38, 0x50, 0x08, 0x05);
		} else {
			rgb_matrix_set_color(23, 0x50, 0x08, 0x05);
			rgb_matrix_set_color(37, 0x50, 0x08, 0x05);
			rgb_matrix_set_color(39, 0x50, 0x08, 0x05);
			rgb_matrix_set_color(53, 0x50, 0x08, 0x05);
		}
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
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	KC_W, 				KC_F,				KC_M,				KC_P,				KC_V,				KC_P7,				KC_P8,				KC_P9,				_______,			_______,			KC_COMM,			KC_DOT,				KC_Q,				KC_Z,				KC_J,
	LSFT_T(KC_R),		LCTL_T(KC_S),		LGUI_T(KC_N),		LALT_T(KC_T),		KC_B,				KC_P4,				KC_P5,				KC_P6,				KC_VOLD,			KC_VOLU,			KC_MINS,			RALT_T(KC_A),		RGUI_T(KC_E),		RCTL_T(KC_I),		RSFT_T(KC_H),
	KC_X,				KC_C,				KC_L,				KC_D,				KC_G,				KC_P1,				KC_P2,				KC_P3,				KC_MSTP,			KC_MPLY,			KC_SLSH,			KC_U,				KC_O,				KC_Y,				KC_K,
	KC_ESC,				KC_LSFT,			_______,			KC_TAB,				LT(FN, KC_SPC),		MO(FKEYS),			KC_P0,				KC_PDOT,			KC_MPRV,			KC_MNXT,			LT(FN1, KC_ENT),	KC_LEFT,			KC_DOWN,			KC_UP,				KC_RIGHT
	),
 [FKEYS] = LAYOUT_ortho_5x15(
	_______,			_______,			_______,			_______,			_______,			KC_F10,				KC_F11,				KC_F12,				_______,			_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			KC_F7,				KC_F8,				KC_F9,				_______,			_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			KC_F4,				KC_F5,				KC_F6,				_______,			_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			KC_F1,				KC_F2,				KC_F3,				_______,			_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______
	),
  [QWERTY] = LAYOUT_ortho_5x15(
	KC_1,				KC_2,				KC_3,				KC_4,				KC_5,				_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	KC_TAB, 			KC_Q,				KC_W,				KC_E,				KC_R,				_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	KC_ESC, 			KC_A,				KC_S,				KC_D,				KC_F,				KC_G,				_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	KC_LSFT,			KC_Z,				KC_X,				KC_C,				KC_V,				_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	KC_LCTL,			KC_LGUI,			XXXXXXX,			KC_LALT,			KC_SPC,				_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______
	),
 [FN] = LAYOUT_ortho_5x15(
	_______,			TG(QWERTY),			_______,			_______,			_______,			RGB_TOG,			RGB_RMOD,			RGB_MOD,			_______,			_______,			QK_BOOT,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			RGB_HUI,			RGB_SAI,			RGB_VAI,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			KC_BSPC,			KC_DEL,				_______,			RGB_HUD,			RGB_SAD,			RGB_VAD,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			KC_HOME,			KC_PGDN,			KC_PGUP,			KC_END
	),
 [FN1] = LAYOUT_ortho_5x15(
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	LSFT_T(KC_1),		LCTL_T(KC_2),		LGUI_T(KC_3),		LALT_T(KC_4),		KC_5,				_______,			_______,			_______,			_______,			_______,			KC_6,				RALT_T(KC_7),		RGUI_T(KC_8),		RCTL_T(KC_9),		RSFT_T(KC_0),
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______,			_______
	)
};
