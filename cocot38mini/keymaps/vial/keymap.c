/*
Copyright 2024 aki27

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
#include <stdio.h>
#include "quantum.h"

#define LCLICK KC_MS_BTN1
#define RCLICK KC_MS_BTN2

#define JAP KC_LANGUAGE_1
#define ENG KC_LANGUAGE_2

// for moving tabs in browser, editor etc
#define L_TAB LCMD(KC_LCBR)
#define R_TAB LCMD(KC_RCBR)

#define SCREENSHOT_PART LCMD(LSFT(KC_4))
#define SCREENSHOT_WHOLE LCMD(LSFT(KC_3))

enum custom_keycodes {
  ESC_AND_ENG = SAFE_RANGE,
  EMOJI,
  EMAIL_1,
  EMAIL_2,
  EMAIL_3,
};

// Variables to store accumulated scroll values
float scroll_accumulated_horizontal = 0;
float scroll_accumulated_vertical = 0;

report_mouse_t pointing_device_task_user(report_mouse_t report) {
  // enable scroll mode when layer 1 is active
  if (IS_LAYER_ON(1)) {
    // ref: https://docs.qmk.fm/features/pointing_device#advanced-drag-scroll

    // Calculate and accumulate scroll values based on mouse movement and divisors
    // Accumulation is required to make the scroll smooth.
    scroll_accumulated_horizontal += (float)report.x / SCROLL_DIVISOR_H;
    scroll_accumulated_vertical += (float)report.y / SCROLL_DIVISOR_V;

    // Assign integer parts of accumulated scroll values to the mouse report
    report.h = (int8_t)scroll_accumulated_horizontal;
    report.v = -(int8_t)scroll_accumulated_vertical;

    // Update accumulated scroll values by subtracting the integer parts
    scroll_accumulated_horizontal -= (int8_t)scroll_accumulated_horizontal;
    scroll_accumulated_vertical -= (int8_t)scroll_accumulated_vertical;

    report.x = 0;
    report.y = 0;
  }

  return report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case ESC_AND_ENG:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC) SS_TAP(X_LANGUAGE_2));
      }
      break;

    case EMOJI:
      if (record->event.pressed) {
        // ctl + cmd + space for emoji
        SEND_STRING(SS_DOWN(X_LCTL));
        SEND_STRING(SS_DOWN(X_LCMD));
        SEND_STRING(SS_TAP(X_SPACE));
        SEND_STRING(SS_UP(X_LCMD));
        SEND_STRING(SS_UP(X_LCTL));
      }
      break;

    case EMAIL_1:
      if (record->event.pressed) {
        SEND_STRING(ENV_EMAIL_1);
      }
      break;

    case EMAIL_2:
      if (record->event.pressed) {
        SEND_STRING(ENV_EMAIL_2);
      }
      break;

    case EMAIL_3:
      if (record->event.pressed) {
        SEND_STRING(ENV_EMAIL_3);
      }
      break;
  }

  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_Q, KC_W,         KC_E,         KC_R,         KC_T,               KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
        KC_A, LCTL_T(KC_S), LALT_T(KC_D), LCMD_T(KC_F), KC_G,               KC_H,    RCMD_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), KC_COLON,
        KC_Z, KC_X,         KC_C,         KC_V,         KC_B,               KC_N,    KC_M,         KC_COMM,      KC_DOT,       CW_TOGG,

                            LCLICK, MO(1), LSFT_T(KC_SPACE),
                                                                  LCLICK, // key above trackball
                                                                 _______, RSFT_T(KC_ENT), MO(2),   _______
    ),

    [1] = LAYOUT(
        _______, EMOJI,   L_TAB  , R_TAB  , _______,          KC_0    ,KC_1,    KC_2,    KC_3,    _______,
        _______, KC_LCBR, KC_DEL , KC_BSPC, KC_RCBR,          KC_MINUS,KC_4,    KC_5,    KC_6,    _______,
        _______, KC_QUES, _______, _______, _______,          KC_EQUAL,KC_7,    KC_8,    KC_9,   KC_SLASH,
                          _______, _______, _______, 
                                                      RCLICK, // key above trackball
                                                     _______, ESC_AND_ENG, MO(3), _______
    ),

    [2] = LAYOUT(
     KC_EXCLAIM, KC_DQT,  KC_HASH, KC_DLR,  KC_PERCENT,       KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_CIRC,
        KC_TAB,  KC_QUOTE,ENG,     JAP,     KC_AT,            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_SCLN,
  LSFT(KC_TAB),  KC_GRAVE,KC_TILDE,KC_PIPE, _______,          KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BACKSLASH,
                           RCLICK, MO(3),   _______,  
                                                      RCLICK, 
                                                      _______, KC_LNG1, KC_BSPC, KC_BSPC
    ),

    [3] = LAYOUT(
        _______, EMAIL_1, _______, _______, RGB_TOG,          KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
        _______, EMAIL_2, _______, _______, SCREENSHOT_PART,  _______, KC_BRID, KC_BRIU, _______, _______,
        _______, EMAIL_3, _______, _______, SCREENSHOT_WHOLE, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______, _______, _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [2] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [3] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
};
#endif

// bool is_mouse_record_kb(uint16_t keycode, keyrecord_t* record) {
//     switch(keycode) {
//       case KC_LCTL:
//         return true;
//       case KC_LSFT:
//         return true;
//       case SCRL_MO:
//         return true;
//       default:
//         return false;
//     }
//     return is_mouse_record_user(keycode, record);
// }

#ifdef RGB_MATRIX_ENABLE

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) { 
    int is_layer = get_highest_layer(layer_state|default_layer_state);  
    HSV hsv = {0, 255, rgblight_get_val()};
    if (is_layer == 1) {
      hsv.h = 11; //CORAL
    } else if (is_layer == 2)  {
      hsv.h = 85; //GREEN
    } else if (is_layer == 3)  {
      hsv.h = 43; //YELLOW
    } else if (is_layer == 4)  {
      hsv.h = 0; //RED
    } else if (is_layer == 5)  {
      hsv.h = 191; //PURPLE
    } else if (is_layer == 6)  {
      hsv.h = 64; //CHARTREUSE
    } else if (is_layer == 7)  {
      hsv.h = 224;
    } else {
      hsv.h = 128; //CYAN
    }
    RGB rgb = hsv_to_rgb(hsv);
 
    for (uint8_t i = led_min; i <= led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x02)) {
          rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return false;
};

#endif

