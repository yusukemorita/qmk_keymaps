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

#include "trackpoint.h"
#include "wait.h"

// void ps2_mouse_moved_user(report_mouse_t *mouse_report);

void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
    // Print a message to indicate the function is called
    print("Mouse moved:\n");

    // Print each field in the mouse_report structure
    dprintf("  x: %d\n", mouse_report->x);
    dprintf("  y: %d\n", mouse_report->y);
    dprintf("  wheel: %d\n", mouse_report->h);
    dprintf("  horizontal wheel: %d\n", mouse_report->v);
    dprintf("  buttons: 0x%02X\n", mouse_report->buttons);
}
