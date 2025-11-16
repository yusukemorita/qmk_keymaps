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

// Serial uses PIO0, change PS2 to PIO1.
#define PS2_PIO_USE_PIO1

#define PS2_MOUSE_INVERT_X
#define PS2_MOUSE_INVERT_Y

// #define PS2_DATA_PIN    GP2
// #define PS2_CLOCK_PIN   GP3

// pin labelled 2 on pro micro
#define PS2_DATA_PIN D1
// pin labelled 3 on pro micro
#define PS2_CLOCK_PIN D0

// Start faster when keyboard resets.
#define PS2_MOUSE_INIT_DELAY 500
