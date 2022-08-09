/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> get_default_attribute_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 * get_default_attribute_value(uint param_1,uint param_2)

{
  if (param_1 == 5) {
    if (param_2 == 2) {
      reset_value_2 = 0;
    }
    else if (param_2 < 3) {
      if (param_2 == 0) {
        reset_value_2 = 0;
      }
      else if (param_2 == 1) {
        reset_value_2 = 0;
      }
    }
    else if (param_2 == 3) {
      reset_value_2 = 0;
    }
    else if (param_2 == 4) {
      reset_value_2 = 0;
    }
  }
  else if (param_1 < 6) {
    if (param_1 == 3) {
      if (param_2 == 0) {
        reset_value_2 = 0;
      }
    }
    else if (param_1 == 4) {
      if (param_2 == 0) {
        reset_value_2 = 0;
      }
    }
    else if (param_1 == 0) {
      if (param_2 == 1) {
        reset_value_2 = 0;
      }
      else if (param_2 == 7) {
        reset_value_2 = 0;
      }
      else if (param_2 == 0) {
        reset_value_2 = 3;
      }
    }
  }
  else if (param_1 == 8) {
    if (param_2 == 0) {
      reset_value_2 = 0xff;
    }
  }
  else if (param_1 == 0x300) {
    if (param_2 == 0x4001) {
      reset_value_2 = 1;
    }
    else if (param_2 < 0x4002) {
      if (param_2 == 7) {
        reset_value_2 = 0xfa;
      }
      else if (param_2 < 8) {
        if (param_2 == 3) {
          reset_value_2 = 0x616b;
        }
        else if (param_2 < 4) {
          if (param_2 == 0) {
            reset_value_2 = 0;
          }
          else if (param_2 == 1) {
            reset_value_2 = 0;
          }
        }
        else if (param_2 == 4) {
          reset_value_2 = 0x607d;
        }
      }
      else if (param_2 == 0xf) {
        reset_value_2 = 0;
      }
      else if (param_2 == 0x4000) {
        reset_value_2 = 0;
      }
      else if (param_2 == 8) {
        reset_value_2 = 1;
      }
    }
    else if (param_2 == 0x4006) {
      reset_value_2 = 0;
    }
    else if (param_2 < 0x4007) {
      if (param_2 == 0x4004) {
        reset_value_2 = 0x19;
      }
      else if (param_2 < 0x4005) {
        if (param_2 == 0x4002) {
          reset_value_2 = 0;
        }
        else if (param_2 == 0x4003) {
          reset_value_2 = 0;
        }
      }
      else if (param_2 == 0x4005) {
        reset_value_2 = 0x2300;
      }
    }
    else if (param_2 == 0x400b) {
      reset_value_2 = 0;
    }
    else if (param_2 == 0x400c) {
      reset_value_2 = 0xfeff;
    }
    else if (param_2 == 0x400a) {
      reset_value_2 = 8;
    }
  }
  else if ((param_1 == 6) && (param_2 == 0)) {
    reset_value_2 = 0;
  }
  return &reset_value_2;
}

