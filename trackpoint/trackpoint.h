#pragma once

#include "quantum.h"

typedef union {
  uint32_t raw;
  struct {
    uint8_t dpi_config;
  };
} keyboard_config_t;

extern keyboard_config_t keyboard_config;

enum ploopy_keycodes {
    DPI_CONFIG = QK_KB_0,
};

void cycle_dpi(void);
