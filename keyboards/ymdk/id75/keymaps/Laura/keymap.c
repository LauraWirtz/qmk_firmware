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
};

enum {
	TD_LANG_IME,
};

enum custom_keycodes {
	LANG_IME = TD(TD_LANG_IME),
};

void lang_ime(tap_dance_state_t *state, void *user_data) {
	 switch (state->count) {
		case 1:
			leader_start();
			break;
		case 2:
			SEND_STRING(SS_LALT("q"));
			break;
		 case 3:
			SEND_STRING(SS_LALT("`"));
			break;
		case 4:
			SEND_STRING(SS_LGUI(" "));
			break;
	}
}

tap_dance_action_t tap_dance_actions[] = {
	[TD_LANG_IME] = ACTION_TAP_DANCE_FN(lang_ime),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case LT(FN, QK_LEAD):
			if (record->tap.count && record->event.pressed) {leader_start();return false;}break;
		}
	return true;
};

void leader_end_user(void) {
	//Sizer Shortcuts
	if (leader_sequence_one_key(KC_DOWN)) {
		SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT("1"))));
	} else if (leader_sequence_two_keys(KC_LEFT, KC_LEFT)) {
		SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT("2"))));
	} else if (leader_sequence_two_keys(KC_RIGHT, KC_RIGHT)) {
		SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT("3"))));
	} else if (leader_sequence_three_keys(KC_LEFT, KC_LEFT, KC_UP)) {
		SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT("4"))));
	} else if (leader_sequence_three_keys(KC_LEFT, KC_LEFT, KC_DOWN)) {
		SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT("5"))));
	} else if (leader_sequence_three_keys(KC_RIGHT, KC_RIGHT, KC_UP)) {
		SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT("6"))));
	} else if (leader_sequence_three_keys(KC_RIGHT, KC_RIGHT, KC_DOWN)) {
		SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT("7"))));
	} else if (leader_sequence_one_key(KC_LEFT)) {
		SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT("8"))));
	} else if (leader_sequence_one_key(KC_RIGHT)) {
		SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT("9"))));
	}
	//Umlaut Shortcuts
	 else if (leader_sequence_one_key(KC_A)) {
		SEND_STRING(SS_TAP(X_CAPS) SS_DOWN(X_LSFT) SS_TAP(X_QUOT) SS_UP(X_LSFT) SS_TAP(X_A));
	}else if (leader_sequence_two_keys(KC_A, KC_A)) {
		SEND_STRING(SS_TAP(X_CAPS) SS_DOWN(X_LSFT) SS_TAP(X_QUOT) SS_TAP(X_A) SS_UP(X_LSFT));
	}else if (leader_sequence_one_key(KC_O)) {
		SEND_STRING(SS_TAP(X_CAPS) SS_DOWN(X_LSFT) SS_TAP(X_QUOT) SS_UP(X_LSFT) SS_TAP(X_O));
	}else if (leader_sequence_two_keys(KC_O, KC_O)) {
		SEND_STRING(SS_TAP(X_CAPS) SS_DOWN(X_LSFT) SS_TAP(X_QUOT) SS_TAP(X_O) SS_UP(X_LSFT));
	}else if (leader_sequence_one_key(KC_U)) {
		SEND_STRING(SS_TAP(X_CAPS) SS_DOWN(X_LSFT) SS_TAP(X_QUOT) SS_UP(X_LSFT) SS_TAP(X_U));
	}else if (leader_sequence_two_keys(KC_U, KC_U)) {
		SEND_STRING(SS_TAP(X_CAPS) SS_DOWN(X_LSFT) SS_TAP(X_QUOT) SS_TAP(X_U) SS_UP(X_LSFT));
	}else if (leader_sequence_one_key(KC_S)) {
		SEND_STRING(SS_TAP(X_CAPS) SS_TAP(X_S) SS_TAP(X_S));
	}else if (leader_sequence_one_key(KC_E)) {
		SEND_STRING(SS_TAP(X_CAPS) SS_TAP(X_EQL) SS_TAP(X_E));
	}
}

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
	KC_1,							KC_2,							KC_3,							KC_4,							KC_5,							KC_NUM,					_______,						_______,						_______,						_______,						KC_6,							KC_7,							KC_8,							KC_9,							KC_0,
	KC_W, 						KC_F,							KC_M,						KC_P,							KC_V,							KC_P7,						KC_P8,						KC_P9,						_______,						_______,						KC_COMM,				KC_DOT,					KC_Q,						KC_Z,							KC_J,
	LSFT_T(KC_R),		LCTL_T(KC_S),		LGUI_T(KC_N),		LALT_T(KC_T),		KC_B,							KC_P4,						KC_P5,						KC_P6,						_______,						_______,						KC_MINS,					RALT_T(KC_A),		RGUI_T(KC_E),		RCTL_T(KC_I),		RSFT_T(KC_H),
	KC_X,							KC_C,							KC_L,							KC_D,						KC_G,						KC_P1,						KC_P2,						KC_P3,						KC_MSTP,				KC_MPLY,				KC_SLSH,					KC_U,							KC_O,						KC_Y,							KC_K,
	KC_ESC,					KC_LSFT,					LANG_IME,				KC_TAB,					LT(FN, KC_SPC),	MO(FKEYS),			KC_P0,						KC_PDOT,				KC_MPRV,				KC_MNXT,				KC_ENT,					KC_LEFT,					KC_DOWN,				KC_UP,						KC_RIGHT
	),
 [FKEYS] = LAYOUT_ortho_5x15(
	_______,						_______,						_______,						_______,						_______,						KC_F10,					KC_F11,					KC_F12,					_______,						_______,						_______,						_______,						_______,						_______,						_______,
	_______,						_______,						_______,						_______,						_______,						KC_F7,						KC_F8,						KC_F9,						_______,						_______,						_______,						_______,						_______,						_______,						_______,
	_______,						_______,						_______,						_______,						_______,						KC_F4,						KC_F5,						KC_F6,						_______,						_______,						_______,						_______,						_______,						_______,						_______,
	_______,						_______,						_______,						_______,						_______,						KC_F1,						KC_F2,						KC_F3,						_______,						_______,						_______,						_______,						_______,						_______,						_______,
	_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______
	),
  [QWERTY] = LAYOUT_ortho_5x15(
	_______,						_______,						_______,						_______,						_______,						KC_1,							KC_2,							KC_3,							KC_4,							KC_5,							_______,						_______,						_______,						_______,						_______,
	_______,						_______,						_______,						_______,						_______,						KC_TAB, 					KC_Q,						KC_W,						KC_E,							KC_R,							_______,						_______,						_______,						_______,						_______,
	_______,						_______,						_______,						_______,						_______,						KC_ESC, 					KC_A,							KC_S,							KC_D,						KC_F,							_______,						_______,						_______,						_______,						_______,
	_______,						_______,						_______,						_______,						_______,						KC_LSFT,					KC_Z,							KC_X,							KC_C,							KC_V,							_______,						_______,						_______,						_______,						_______,
	_______,						_______,						_______,						_______,						_______,						KC_LCTL,					KC_LGUI,					XXXXXXX,				KC_LALT,					KC_SPC,					_______,						_______,						_______,						_______,						_______
	),
 [FN] = LAYOUT_ortho_5x15(
	QK_BOOT,				TG(QWERTY),		_______,						_______,						_______,						RGB_TOG,				RGB_RMOD,			RGB_MOD,				_______,						_______,						_______,						_______,						_______,						_______,						_______,
	_______,						_______,						_______,						_______,						_______,						RGB_HUI,					RGB_SAI,					RGB_VAI,					_______,						_______,						_______,						KC_LBRC,					KC_RBRC,					KC_GRV,					_______,
	_______,						_______,						KC_BSPC,					KC_DEL,					_______,						RGB_HUD,				RGB_SAD,				RGB_VAD,				_______,						_______,						_______,						RALT_T(KC_SCLN),	RGUI_T(KC_QUOT),	RCTL_T(KC_EQL),	RSFT_T(KC_BSLS),
	_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,
	_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						_______,						KC_HOME,				KC_PGDN,				KC_PGUP,				KC_END
	)
};
