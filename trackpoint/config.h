#pragma once

#include "config_common.h"
#include <serial_config.h>

#define USE_I2C
#define USE_SERIAL

#ifdef USE_Link_Time_Optimization
  // LTO has issues with macros (action_get_macro) and "functions" (fn_actions),
  //  so just disable them
  #define NO_ACTION_MACRO
  #define NO_ACTION_FUNCTION

  #define DISABLE_LEADER
#endif // USE_Link_Time_Optimization