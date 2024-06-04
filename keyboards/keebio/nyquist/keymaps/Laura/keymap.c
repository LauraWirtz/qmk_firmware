// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
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
	_______,			KC_1,				KC_2,				KC_3,				KC_4,				KC_5,						KC_6,				KC_7,				KC_8,				KC_9,				KC_0,				_______,
	_______,			KC_W, 				KC_F,				KC_M,				KC_P,				KC_V,						KC_COMM,			KC_DOT,				KC_Q,				KC_Z,				KC_J,				_______,
	_______,			LSFT_T(KC_R),		LCTL_T(KC_S),		LGUI_T(KC_N),		LALT_T(KC_T),		KC_B,						KC_MINS,			RALT_T(KC_A),		RGUI_T(KC_E),		RCTL_T(KC_I),		RSFT_T(KC_H),		_______,
	_______,			KC_X,				KC_C,				KC_L,				KC_D,				KC_G,						KC_SLSH,			KC_U,				KC_O,				KC_Y,				KC_K,				_______,
	_______,			KC_ESC,				KC_LSFT,			_______,			LT(_FKEYS, KC_TAB),	LT(_NUM, KC_SPC),			LT(_SYM, KC_ENT),	KC_COLN,			_______,			_______,			_______,			_______
	),
  [_FKEYS] = LAYOUT_ortho_5x12(
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			KC_F10,				KC_F11,				KC_F12,				_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			KC_F7,				KC_F8,				KC_F9,				_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			KC_F4,				KC_F5,				KC_F6,				_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			KC_F1,				KC_F2,				KC_F3,				_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			_______,			_______,			_______,			_______,			_______
	),
  [_QWERTY] = LAYOUT_ortho_5x12(
	_______,			KC_1,				KC_2,				KC_3,				KC_4,				KC_5,						_______,			_______,			_______,			_______,			_______,			_______,
	_______,			KC_TAB, 			KC_Q,				KC_W,				KC_E,				KC_R,						_______,			_______,			_______,			_______,			_______,			_______,
	_______,			KC_ESC, 			KC_A,				KC_S,				KC_D,				KC_F,						_______,			_______,			_______,			_______,			_______,			_______,
	_______,			KC_LSFT,			KC_Z,				KC_X,				KC_C,				KC_V,						_______,			_______,			_______,			_______,			_______,			_______,
	_______,			KC_LCTL,			_______,			TG(_QWERTY),		KC_LALT,			KC_SPC,						_______,			_______,			_______,			_______,			_______,			_______
	),
  [_NUM] = LAYOUT_ortho_5x12(
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			_______,			_______,			_______,			QK_BOOT,			_______,
	_______,			_______,			KC_BSPC,			KC_UP,				KC_DEL,				_______,					_______,			KC_7,				KC_8,				KC_9,				KC_0,				_______,
	_______,			_______,			KC_LEFT,			KC_DOWN,			KC_RIGHT,			_______,					_______,			RALT_T(KC_4),		RGUI_T(KC_5),		RCTL_T(KC_6),		_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			KC_1,				KC_2,				KC_3,				_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,					LT(_SYM, KC_0),		_______,			_______,			_______,			_______,			_______
	),
  [_SYM] = LAYOUT_ortho_5x12(
	_______,			RGB_TOG,			RGB_RMOD,			RGB_MOD,			_______,			_______,					_______,			_______,			_______,			_______,			_______,			_______,
	_______,			RGB_HUI,			RGB_SAI,			RGB_VAI,			RGB_SPI,			_______,					_______,			_______,			KC_LBRC,			KC_RBRC,			KC_GRV,				_______,
	_______,			RGB_HUD,			RGB_SAD,			RGB_VAD,			RGB_SPD,			_______,					_______,			_______,			KC_SCLN,			KC_QUOT,			KC_EQL,				KC_BSLS,
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			_______,			_______,			_______,			_______,			_______,
	_______,			_______,			_______,			_______,			_______,			_______,					_______,			_______,			_______,			_______,			_______,			_______
	)
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;  }
  return true;
}
