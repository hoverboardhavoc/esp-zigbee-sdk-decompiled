/*
 * Last changed at upstream commit 9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * https://github.com/espressif/esp-zigbee-sdk/commit/9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * Upstream date: 2023-11-10 18:10:39 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.3(ba5a889a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_err_to_zb_ret
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_err_to_zb_ret(int param_1)

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

