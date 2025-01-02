
#include QMK_KEYBOARD_H

enum layer_names {
	_BASE,
	_QWERTY,
	_NUM,
	_NUMALT,
	_SYM
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
		KC_F1,				KC_F2,				KC_F3,				KC_F4,				KC_F5,				KC_F6,						KC_F7,				KC_F8,				KC_F9,				KC_F10,				KC_F11,				KC_F12,
		_______,			KC_W, 				KC_F,				KC_M,				KC_P,				KC_V,						KC_COMM,			KC_DOT,				KC_Q,				KC_Z,				KC_J,				_______,
		KC_ESC,				LSFT_T(KC_R),		LCTL_T(KC_S),		LGUI_T(KC_N),		LALT_T(KC_T),		KC_B,						KC_MINS,			RALT_T(KC_A),		RGUI_T(KC_E),		RCTL_T(KC_I),		RSFT_T(KC_H),		_______,
		_______,			KC_X,				KC_C,				KC_L,				KC_D,				KC_G,						KC_SLSH,			KC_U,				KC_O,				KC_Y,				KC_K,				_______,
		KC_LSFT,			TG(_QWERTY),		_______,			_______,			LT(_NUMALT, KC_TAB),LT(_NUM, KC_SPC),			LT(_SYM, KC_ENT),	_______,			KC_LEFT,			KC_DOWN,			KC_UP,				KC_RIGHT
		),
	[_QWERTY] = LAYOUT_ortho_5x12(
		KC_TILD,			KC_1,				KC_2,				KC_3,				KC_4,				KC_5,						KC_6,				KC_7,				KC_8,				KC_9,				KC_0,				KC_BSPC,
		KC_TAB, 			KC_Q,				KC_W,				KC_E,				KC_R,				KC_T,						KC_Y,				KC_U,				KC_I,				KC_O,				KC_P,				KC_DEL,
		KC_ESC, 			KC_A,				KC_S,				KC_D,				KC_F,				KC_G,						KC_H,				KC_J,				KC_K,				KC_L,				KC_SCLN,			KC_QUOT,
		KC_LSFT,			KC_Z,				KC_X,				KC_C,				KC_V,				KC_B,						KC_N,				KC_M,				KC_COMM,			KC_DOT,				KC_SLSH,			KC_ENT,
		KC_LCTL,			_______,			XXXXXXX,			KC_LALT,			KC_SPC,				XXXXXXX,					KC_LBRC,			KC_RBRC,			KC_LEFT,			KC_DOWN,			KC_UP,				KC_RGHT
		),
	[_NUM] = LAYOUT_ortho_5x12(
		_______,			_______,			_______,			_______,			_______,			_______,					_______,			_______,			_______,			_______,			_______,			QK_BOOT,
		_______,			_______,			KC_BSPC,			KC_UP,				KC_DEL,				_______,					_______,			KC_7,				KC_8,				KC_9,				_______,			_______,
		_______,			_______,			KC_LEFT,			KC_DOWN,			KC_RIGHT,			_______,					_______,			KC_4,				KC_5,				KC_6,				_______,			_______,
		_______,			_______,			_______,			_______,			_______,			_______,					_______,			KC_1,				KC_2,				KC_3,				_______,			_______,
		_______,			_______,			_______,			_______,			_______,			_______,					KC_P0,				KC_DOT,				_______,			_______,			_______,			_______
		),
	[_NUMALT] = LAYOUT_ortho_5x12(
		_______,			_______,			_______,			_______,			_______,			_______,					_______,			_______,			_______,			_______,			_______,			_______,
		_______,			_______,			_______,			KC_PGUP,			KC_INS,				_______,					_______,			KC_AMPR,			KC_ASTR,			_______,			_______,			_______,
		_______,			_______,			KC_HOME,			KC_PGDN,			KC_END,				_______,					_______,			KC_DLR,				KC_PERC,			KC_CIRC,			_______,			_______,
		_______,			_______,			_______,			_______,			_______,			_______,					_______,			KC_EXLM,			KC_AT,				KC_HASH,			_______,			_______,
		_______,			_______,			_______,			_______,			_______,			_______,					KC_P0,				KC_DOT,				_______,			_______,			_______,			_______
		),
	[_SYM] = LAYOUT_ortho_5x12(
		_______,			_______,			_______,			_______,			_______,			_______,					_______,			_______,			_______,			_______,			_______,			_______,
		_______,			_______,			KC_BSLS,			KC_QUOT,			KC_DQT,				KC_TILD,					_______,			KC_LPRN,			KC_RPRN,			_______,			_______,			_______,
		_______,			_______,			KC_PIPE,			KC_COLN,			KC_SCLN,			KC_EQL,						_______,			KC_LBRC,			KC_RBRC,			_______,			_______,			_______,
		_______,			_______,			_______,			KC_GRV,				KC_PLUS,			_______,					_______,			KC_LCBR,			KC_RCBR,			_______,			_______,			_______,
		_______,			_______,			_______,			_______,			_______,			_______,					_______,			_______,			_______,			_______,			_______,			_______
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
