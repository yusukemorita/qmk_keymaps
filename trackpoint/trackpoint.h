#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    YourName
#define PRODUCT         TrackpointModule
#define DESCRIPTION     Trackpoint-only firmware

/* Matrix size  */
#define MATRIX_ROWS 1
#define MATRIX_COLS 1

/* Pointing device settings (PS/2 trackpoint) */
#define PS2_CLOCK_PIN B5
#define PS2_DATA_PIN  B6

/* Debounce time (irrelevant for trackpoint-only setup but required) */
#define DEBOUNCE 0
