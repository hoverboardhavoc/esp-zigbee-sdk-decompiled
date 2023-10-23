/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> error_to_zb_ret
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int error_to_zb_ret(int param_1)

{
  if (param_1 == 0x104) {
    return -6;
  }
  if (param_1 < 0x105) {
    if (param_1 != 0) {
      if (param_1 != 0x101) {
        return -1;
      }
      return -0x16;
    }
  }
  else {
    if (param_1 == 0x107) {
      return -0x1e;
    }
    if (param_1 == 0x10c) {
      return -2;
    }
    if (param_1 == 0x105) {
      return -0x1c;
    }
    param_1 = -1;
  }
  return param_1;
}

