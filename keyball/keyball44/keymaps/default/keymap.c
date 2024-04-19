/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// aliases

#define JAP KC_LANG1
#define ENG KC_LANG2

#define CPI_INC CPI_I100
#define CPI_DEC CPI_D100
#define CLICK KC_MS_BTN1

// macro

enum custom_keycodes {
  KC_ESC_AND_ENG = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case KC_ESC_AND_ENG:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC) SS_TAP(X_LANGUAGE_2));
      }
      break;
  }
  return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    XXXXXXX  , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , XXXXXXX  ,
    XXXXXXX  , LCTL_T(KC_A), KC_S  , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , RCTL_T(KC_COLON), XXXXXXX,
    XXXXXXX  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLASH , XXXXXXX  ,
    XXXXXXX  , XXXXXXX  ,            KC_LGUI  , LT(1,CLICK), LSFT(KC_SPACE),                            RSFT(KC_ENT), LT(2,CLICK),            _______  , KC_RALT  , CLICK
  ),

  [1] = LAYOUT_universal(
    XXXXXXX  , KC_1     , KC_2     , KC_3    , KC_4     , KC_5     ,                                         KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , XXXXXXX  ,
    XXXXXXX  , _______  , _______  , _______ , _______  , _______  ,                                         KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT , XXXXXXX  , XXXXXXX  ,
    XXXXXXX  , _______  , _______  , _______ , _______  , _______  ,                                         KC_DEL   , KC_BSPC  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    _______  , _______  ,            _______ , _______  , _______  ,                                   KC_ESC_AND_ENG , LT(3,_______) ,       _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    XXXXXXX  , KC_EXCLAIM, KC_DQT  , KC_HASH , KC_DOLLAR, KC_PERCENT,                                        KC_AMPR  , KC_ASTR  , KC_LPRN  , KC_RPRN  , KC_CIRC  , XXXXXXX  ,
    XXXXXXX  , KC_TAB   , KC_QUOTE , ENG     , JAP      , KC_AT    ,                                         KC_MINUS , KC_EQUAL , KC_LCBR  , KC_RCBR  , KC_SCLN  , XXXXXXX  ,
    XXXXXXX  , _______  , KC_GRAVE , KC_TILDE, KC_PIPE  , _______  ,                                     KC_UNDERSCORE, KC_PLUS  , KC_EQL   , KC_LBRC  , KC_RBRC  , XXXXXXX  ,
    _______  , _______  ,            _______ , LT(3,_______) , _______  ,                                    _______  , _______  ,            _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    XXXXXXX  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , XXXXXXX  ,
    XXXXXXX  , _______  , _______  , _______  , _______  , CPI_INC  ,                                        _______  , _______  , _______  , _______  , _______  , XXXXXXX  ,
    XXXXXXX  , _______  , _______  , _______  , _______  , CPI_DEC  ,                                        _______  , _______  , _______  , _______  , _______  , XXXXXXX  ,
    XXXXXXX  , _______  , _______  ,            _______  , _______  ,                                        _______  , _______  ,            _______  , _______  , XXXXXXX
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
