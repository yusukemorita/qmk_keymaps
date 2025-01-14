/* Copyright 2024 Yusuke Morita
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

#pragma once

#define PS2_MOUSE_USE_REMOTE_MODE
// disable scroll
#define PS2_MOUSE_SCROLL_BTN_MASK 0

// Copied from https://docs.qmk.fm/features/ps2_mouse#interrupt-version-avr
// #ifdef PS2_DRIVER_INTERRUPT
// pin translation: https://golem.hu/article/pro-micro-pinout/
#define PS2_CLOCK_PIN  D2 // pin labelled RX1 on pro micro
#define PS2_DATA_PIN   D3 // pin labelled TX0 on pro micro

#define PS2_INT_INIT()  do {    \
    EICRA |= ((1<<ISC21) |      \
              (0<<ISC20));      \
} while (0)
#define PS2_INT_ON()  do {      \
    EIMSK |= (1<<INT2);         \
} while (0)
#define PS2_INT_OFF() do {      \
    EIMSK &= ~(1<<INT2);        \
} while (0)
#define PS2_INT_VECT   INT2_vect
// #endif
