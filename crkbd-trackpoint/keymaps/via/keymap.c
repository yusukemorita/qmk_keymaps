/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include "holykeebs.h"

// aliases

#define JAP KC_LANGUAGE_1
#define ENG KC_LANGUAGE_2

#define LCLICK KC_MS_BTN1
#define RCLICK KC_MS_BTN2

#define SCREENSHOT_PART LCMD(LSFT(KC_4))
#define SCREENSHOT_WHOLE LCMD(LSFT(KC_3))

// for moving tabs in browser, editor etc
#define L_TAB LCMD(KC_LCBR)
#define R_TAB LCMD(KC_RCBR)

// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(

      _______,    KC_Q,        KC_W,       KC_E,         KC_R,      KC_T,                               KC_Y,        KC_U,        KC_I,        KC_O,     KC_P,  _______,

      _______,    KC_A,LCTL_T(KC_S),LALT_T(KC_D),LCMD_T(KC_F),      KC_G,                               KC_H,RCMD_T(KC_J),RALT_T(KC_K),RCTL_T(KC_L), KC_COLON,  _______,

      _______,    KC_Z,        KC_X,        KC_C,        KC_V,      KC_B,                               KC_N,        KC_M,     KC_COMM,      KC_DOT,  CW_TOGG,  _______,

                                LCLICK,       MO(1),     LSFT_T(KC_SPACE),                    RSFT_T(KC_ENT),       MO(2),      LCLICK

  ),

  // (mostly) numbers and shortcuts
  [1] = LAYOUT_split_3x6_3(
    _______   , _______   , EMOJI     , L_TAB     , R_TAB     , _______   ,                          KC_0     , KC_1     , KC_2     , KC_3     , _______  , _______,

    _______   , _______   , KC_LCBR   , KC_DEL    , KC_BSPC   , KC_RCBR   ,                          KC_MINUS , KC_4     , KC_5     , KC_6     , _______  , _______,

    _______   , _______   , KC_QUES   , _______   , _______   , _______   ,                          KC_EQUAL , KC_7     , KC_8     , KC_9     , KC_SLASH , _______,

                                        _______   , _______   , HOLD_QK_BOOT,                     ESC_AND_ENG , MO(3)    , _______
  ),

  // symbols
  [2] = LAYOUT_split_3x6_3(
    _______   , KC_EXCLAIM, KC_DQT    , KC_HASH  , KC_DOLLAR , KC_PERCENT ,                           KC_AMPR   , KC_ASTR   , KC_LPRN   , KC_RPRN   , KC_CIRC   , _______,

    _______   , KC_TAB    , KC_QUOTE  , ENG      , JAP       , KC_AT      ,                           KC_LEFT   , KC_DOWN   , KC_UP     , KC_RIGHT  , KC_SCLN   , _______,

    _______ , LSFT(KC_TAB), KC_GRAVE  , KC_TILDE , KC_PIPE   , _______    ,                           KC_UNDERSCORE, KC_PLUS, KC_LBRC   , KC_RBRC   , KC_BACKSLASH,_______,

                                        RCLICK   , MO(3)     , _______    ,                         HOLD_QK_BOOT, _______   , _______
  ),

  // shortcuts
  [3] = LAYOUT_split_3x6_3(
    _______   , _______   , EMAIL_1   , _______   , _______   , _______   ,                           KC_MUTE   , KC_VOLD   , KC_VOLU   , _______   , _______   , _______,

    _______   , _______   , EMAIL_2   , _______   , _______   , SCREENSHOT_PART,                      _______   , KC_BRID   , KC_BRIU   , _______   , _______   , _______,

    _______   , _______   , EMAIL_3   , _______   , _______   , SCREENSHOT_WHOLE,                     _______   , _______   , _______   , _______   , _______   , _______,

                                        _______   , _______   , _______   ,                           _______   , _______   , _______ 
  )
};
