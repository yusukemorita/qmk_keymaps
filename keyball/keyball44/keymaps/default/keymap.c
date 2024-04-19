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
               XXXXXXX  , XXXXXXX  , KC_LGUI  , LT(1,KC_MS_BTN1), LSFT(KC_SPACE),                         RSFT(KC_ENT), LT(2,KC_MS_BTN1), KC_RALT,       KC_RALT  , KC_MS_BTN1
  ),

  [1] = LAYOUT_universal(
    XXXXXXX  ,  KC_1    , KC_2     , KC_3    , KC_4     , KC_5     ,                                         KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , XXXXXXX  ,
    XXXXXXX  ,  _______ , _______  , _______ , _______  , _______  ,                                         KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT , XXXXXXX  , XXXXXXX  ,
    XXXXXXX  ,  _______ , _______  , _______ , _______  , _______  ,                                         KC_DEL   , KC_BSPC  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
                  _______  , _______ , _______  ,         _______  , _______  ,                   KC_ESC_AND_ENG , LT(3,_______)  , _______       , _______  , _______
  ),

  [2] = LAYOUT_universal(
    XXXXXXX , KC_EXCLAIM, KC_DOUBLE_QUOTE, KC_HASH, KC_DOLLAR, KC_PERCENT,                                         S(KC_9)  , S(KC_1)  , S(KC_6)  , KC_LBRC  , S(KC_4)  , XXXXXXX  ,
    XXXXXXX  ,KC_TAB, KC_4     , KC_5    , KC_6     , KC_RBRC  ,                                         KC_NUHS  , KC_MINS  , S(KC_EQL), S(KC_3)  , KC_QUOT  , XXXXXXX  ,
    XXXXXXX  ,S(KC_MINS), KC_1     , KC_2    , KC_3     ,S(KC_RBRC),                                        S(KC_NUHS),S(KC_INT1), KC_EQL   ,S(KC_LBRC),S(KC_SLSH), XXXXXXX  ,
                  KC_0     , KC_DOT  , _______  ,         _______  , _______  ,                   KC_DEL   , _______  , _______       , _______  , _______
  ),

  [3] = LAYOUT_universal(
    XXXXXXX  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                        RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , XXXXXXX  ,
    XXXXXXX  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI ,                                        RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , XXXXXXX  ,
    XXXXXXX  , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SCRL_DVD ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , XXXXXXX  ,
                  QK_BOOT  , KBC_RST  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , KBC_RST  , QK_BOOT
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
