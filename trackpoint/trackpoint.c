#include "keyboard.h"
#include "pointing_device.h"

/* Matrix stubs */
void matrix_init_user(void) {
    // No initialization required
}

void matrix_scan_user(void) {
    // No scanning required
}

/* Main pointing device task */
void pointing_device_task(void) {
    // Trackpoint's movement will automatically be handled by QMK's pointing device system.
}
