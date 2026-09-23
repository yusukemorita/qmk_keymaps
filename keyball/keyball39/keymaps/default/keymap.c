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

#define JAP KC_LANGUAGE_1
#define ENG KC_LANGUAGE_2

#define LCLICK KC_MS_BTN1
#define RCLICK KC_MS_BTN2

// for moving tabs in browser, editor etc
#define L_TAB LCMD(KC_LCBR)
#define R_TAB LCMD(KC_RCBR)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_COLON ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , LCLICK   ,
    KC_LCTL  , KC_LGUI  , KC_LALT  , LCLICK   , MO(1)    , KC_SPACE,        KC_ENT,   MO(2)    , _______  , KC_RALT  , KC_RGUI  , KC_RSFT
  ),

  [1] = LAYOUT_universal(
    _______  , _______  , L_TAB    , R_TAB    , _______  ,                            KC_0    ,  KC_1     , KC_2     , KC_3     , _______  ,
    _______  , KC_LCBR  , KC_DEL   , KC_BSPC  , KC_RCBR  ,                           S(KC_INT1), KC_4     , KC_5     , KC_6     , _______  ,
    _______  , KC_QUES  , _______  , _______  , _______  ,                            KC_LBRC  , KC_7     , KC_8     , KC_9     , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      TO(2)    , MO(3)    , _______  , KC_RALT  , KC_RGUI  , _______
  ),

  [2] = LAYOUT_universal(
   KC_EXCLAIM, KC_DQT   , KC_HASH  , KC_DOLLAR,KC_PERCENT,                            KC_AMPR  , KC_ASTR  , KC_LPRN  , KC_RPRN  , KC_CIRC  ,
    KC_TAB   , KC_QUOTE , ENG      , JAP      , KC_AT    ,                            KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT , KC_SCLN  ,
   LSFT(KC_TAB),KC_GRAVE, KC_TILDE , KC_PIPE  , _______  ,                        KC_UNDERSCORE, KC_PLUS  , KC_LBRC  , KC_RBRC  , KC_BACKSLASH,
    _______  , _______  , RCLICK   , MO(3)    , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            KC_MUTE  , KC_VOLD  , KC_VOLU  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , KC_BRID  , KC_BRIU  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
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
