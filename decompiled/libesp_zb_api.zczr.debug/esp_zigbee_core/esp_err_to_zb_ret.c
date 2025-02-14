/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> esp_err_to_zb_ret
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
    if (param_1 == 0x101) {
      return -0x16;
    }
    if (0x101 < param_1) {
      if (param_1 == 0x103) {
        return -0x23;
      }
      return -1;
    }
    if (param_1 != -1) {
      if (param_1 == 0) {
        return 0;
      }
      return -1;
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

