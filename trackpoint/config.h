#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    YourName
#define PRODUCT         TrackpointModule

/* PS/2 trackpoint pins */
#define PS2_CLOCK_PIN   B5
#define PS2_DATA_PIN    B6

/* Polling interval for pointing device */
#define POINTING_DEVICE_TASK_THROTTLE_MS 10

/* Debugging options */
#define DEBUG_MATRIX_SCAN_RATE
#define DEBUG_POINTING_DEVICE
