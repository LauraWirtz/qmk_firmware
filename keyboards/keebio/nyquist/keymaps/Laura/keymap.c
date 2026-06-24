
#include QMK_KEYBOARD_H

enum layer_names {
	_BASE,
	_QWERTY,
	_NUM,
	_FKEY
};

enum custom_keycodes {
	QWERTY = SAFE_RANGE,
	COLEMAK,
	DVORAK,
	LOWER,
	RAISE,
	ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_ortho_5x12(
		KC_GRV,					KC_1,					KC_2,					KC_3,					KC_4,					KC_5,								KC_6,					KC_7,					KC_8,					KC_9,					KC_0,					KC_BSLS,
		KC_TAB,					KC_W, 					KC_F,					KC_M,					KC_P,					KC_V,								KC_SCLN,				KC_EQL,					KC_Q,					KC_LBRC,				KC_RBRC,				KC_QUOT,
		KC_ESC,					LSFT_T(KC_R),			LCTL_T(KC_S),			LGUI_T(KC_N),			LALT_T(KC_T),			KC_B,								KC_MINS,				RALT_T(KC_A),			RGUI_T(KC_E),			RCTL_T(KC_I),			RSFT_T(KC_H),			KC_J,
		LM(_QWERTY, MOD_LSFT),	KC_X,					KC_C,					KC_L,					KC_D,					KC_G,								KC_SLSH,				KC_U,					KC_O,					KC_Y,					KC_K,					KC_Z,
		LM(_QWERTY, MOD_LCTL),	LM(_QWERTY, MOD_LGUI),	TG(_QWERTY),			LM(_QWERTY, MOD_LALT),	LT(_FKEY, KC_ENT),	LT(_NUM, KC_SPC),						KC_COMM,				KC_DOT,					KC_LEFT,				KC_DOWN,				KC_UP,					KC_RIGHT
		),
	[_QWERTY] = LAYOUT_ortho_5x12(
		_______,				_______,				_______,				_______,				_______,				_______,							_______,				_______,				_______,				_______,				_______,				KC_BSPC,
		_______,				KC_Q,					KC_W,					KC_E,					KC_R,					KC_T,								KC_Y,					KC_U,					KC_I,					KC_O,					KC_P,					KC_DEL,
		_______,				KC_A,					KC_S,					KC_D,					KC_F,					KC_G,								KC_H,					KC_J,					KC_K,					KC_L,					KC_SCLN,				KC_QUOT,
		_______,				KC_Z,					KC_X,					KC_C,					KC_V,					KC_B,								KC_N,					KC_M,					KC_COMM,				KC_DOT,					KC_SLSH,				KC_ENT,
		_______,				_______,				_______,				_______,				KC_SPC,					XXXXXXX,							KC_LBRC,				KC_RBRC,				KC_LEFT,				KC_DOWN,				KC_UP,					KC_RGHT
		),
	[_NUM] = LAYOUT_ortho_5x12(
		_______,				_______,				_______,				_______,				_______,				_______,							_______,				_______,				_______,				_______,				_______,				QK_BOOT,
		_______,				_______,				KC_BSPC,				KC_UP,					KC_DEL,					_______,							_______,				KC_P7,					KC_P8,					KC_P9,					_______,				_______,
		_______,				_______,				KC_LEFT,				KC_DOWN,				KC_RIGHT,				_______,							_______,				KC_P4,					KC_P5,					KC_P6,					_______,				_______,
		_______,				_______,				_______,				_______,				_______,				_______,							_______,				KC_P1,					KC_P2,					KC_P3,					_______,				_______,
		_______,				_______,				_______,				_______,				_______,				_______,							KC_P0,					KC_PDOT,				_______,				_______,				_______,				_______
		),
	[_FKEY] = LAYOUT_ortho_5x12(
		_______,				_______,				_______,				_______,				_______,				_______,							_______,				_______,				_______,				_______,				_______,				_______,
		_______,				_______,				_______,				KC_PGUP,				KC_INS,					_______,							_______,				KC_F9,					KC_F10,					KC_F11,					KC_F12,					_______,
		_______,				_______,				KC_HOME,				KC_PGDN,				KC_END,					_______,							_______,				KC_F5,					KC_F6,					KC_F7,					KC_F8,					_______,
		_______,				_______,				_______,				_______,				_______,				_______,							_______,				KC_F1,					KC_F2,					KC_F3,					KC_F4,					_______,
		_______,				_______,				_______,				_______,				_______,				_______,							_______,				_______,				_______,				_______,				_______,				_______
		)
};

bool rgb_matrix_indicators_user(void) {
	if(IS_LAYER_ON(_QWERTY)) {
		rgb_matrix_set_color(11, 0x44, 0x11, 0x22);
		rgb_matrix_set_color(16, 0x44, 0x11, 0x22);
		rgb_matrix_set_color(17, 0x44, 0x11, 0x22);
		rgb_matrix_set_color(18, 0x44, 0x11, 0x22);
	}

	return true;
};
