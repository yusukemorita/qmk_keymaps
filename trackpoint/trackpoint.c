#include "keyboard.h"
#include "pointing_device.h"

/* Custom initialization function */
void keyboard_pre_init_user(void) {
    // Initialize any custom hardware, if needed.
}

/* Main pointing device task */
void pointing_device_task(void) {
    // Trackpoint's movement will automatically be handled by QMK's pointing device system.
}

/* Optional: Override default pointing device processing (not required for basic functionality) */
// void process_pointing_device_report(report_mouse_t *mouse_report) {
//     // Modify or inspect the mouse report before it is sent.
//     // For example: apply custom scaling or acceleration.
// }
