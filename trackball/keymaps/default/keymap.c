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

#include QMK_KEYBOARD_H

// Dummy
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {{{ KC_NO }}};

// Optional: set CPI so movement is noticeable
void pointing_device_init_user(void) {
    pointing_device_set_cpi(1600);   // adjust to taste
}

// Log every non-zero motion report
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (mouse_report.x || mouse_report.y) {
        uprintf("dx=%d dy=%d\n", mouse_report.x, mouse_report.y);
    }
    return mouse_report;
}
