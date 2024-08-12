
#include QMK_KEYBOARD_H

enum layer_names {
	_BASE,
	_FKEYS,
	_QWERTY,
	_NUM,
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
	KC_GRV,				KC_1,				KC_2,				KC_3,				KC_4,				KC_5,						KC_6,				KC_7,				KC_8,				KC_9,				KC_0,				KC_BSLS,
	KC_LBRC,			KC_W, 				KC_F,				KC_M,				KC_P,				KC_V,						KC_COMM,			KC_DOT,				KC_Q,				KC_QUOT,			KC_EQL,				KC_Z,
	KC_ESC,				LSFT_T(KC_R),		LCTL_T(KC_S),		LGUI_T(KC_N),		LALT_T(KC_T),		KC_B,						KC_MINS,			RALT_T(KC_A),		RGUI_T(KC_E),		RCTL_T(KC_I),		RSFT_T(KC_H),		KC_J,
	KC_RBRC,			KC_X,				KC_C,				KC_L,				KC_D,				KC_G,						KC_SLSH,			KC_U,				KC_O,				KC_Y,				KC_K,				_______,
	KC_LSFT,			TG(_QWERTY),		_______,			_______,			LT(_FKEYS, KC_TAB),	LT(_NUM, KC_SPC),			LT(_SYM, KC_ENT),	KC_SCLN,			KC_LEFT,			KC_DOWN,			KC_UP,				KC_RIGHT
	),
  [_FKEYS] = LAYOUT_ortho_5x12(
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			KC_F10,				KC_F11,				KC_F12,				_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			KC_F7,				KC_F8,				KC_F9,				_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			KC_F4,				KC_F5,				KC_F6,				_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			KC_F1,				KC_F2,				KC_F3,				_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			_______,			_______,			_______,			_______,			_______
	),
  [_QWERTY] = LAYOUT_ortho_5x12(
	_______,			KC_1,				KC_2,				KC_3,				KC_4,				KC_5,						KC_6,				KC_7,				KC_8,				KC_9,				KC_0,				_______,
	KC_TAB, 			KC_Q,				KC_W,				KC_E,				KC_R,				KC_T,						KC_Y,				KC_U,				KC_I,				KC_O,				KC_P,				KC_DEL,
	KC_ESC, 			KC_A,				KC_S,				KC_D,				KC_F,				KC_G,						KC_H,				KC_J,				KC_K,				KC_L,				KC_SCLN,			KC_QUOT,
	KC_LSFT,			KC_Z,				KC_X,				KC_C,				KC_V,				KC_B,						KC_N,				KC_M,				KC_COMM,			KC_DOT,				KC_SLSH,			KC_ENT,
	KC_LCTL,			_______,			_______,			KC_LALT,			KC_SPC,				_______,					KC_LBRC,			KC_RBRC,			KC_LEFT,			KC_DOWN,			KC_UP,				KC_RGHT
	),
  [_NUM] = LAYOUT_ortho_5x12(
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			KC_NUM,				KC_PSLS,			KC_PAST,			KC_PMNS,			QK_BOOT,
	_______,			_______,			KC_BSPC,			KC_UP,				KC_DEL,				_______,					_______,			KC_P7,				KC_P8,				KC_P9,				KC_PPLS,			_______,
	_______,			_______,			KC_LEFT,			KC_DOWN,			KC_RIGHT,			_______,					_______,			RALT_T(KC_P4),		RGUI_T(KC_P5),		RCTL_T(KC_P6),		KC_PENT,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			KC_P1,				KC_P2,				KC_P3,				_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,					LT(_SYM, KC_P0),	KC_PDOT,			KC_HOME,			KC_PGDN,			KC_PGUP,			KC_END
	),
  [_SYM] = LAYOUT_ortho_5x12(
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			_______,			_______,			_______,			_______,			_______,
	_______,			RGB_TOG,			RGB_RMOD,			RGB_MOD,			_______,			_______,					_______,			_______,			_______,			_______,			_______,			_______,
	_______,			RGB_HUI,			RGB_SAI,			RGB_VAI,			RGB_SPI,			_______,					_______,			_______,			_______,			_______,			_______,			_______,
	_______,			RGB_HUD,			RGB_SAD,			RGB_VAD,			RGB_SPD,			_______,					_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			_______,			_______,			_______,			_______,			_______
	)
};

bool rgb_matrix_indicators_user(void) {
	if(IS_LAYER_ON(_QWERTY)) {
		for (uint8_t i = 0; i < 72; i++) {
			if (i != 11 && i != 16 && i != 17 && i != 18) {
				rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
			}
		}
	} else if(IS_LAYER_ON(_NUM) && host_keyboard_led_state().num_lock) {
		for (uint8_t i = 0; i < 72; i++) {
			if (i != 37) {
				rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
		    }
        }
    } else {
		for (uint8_t i = 0; i < 72; i++) {
			rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
		}
	}

	return true;
};
