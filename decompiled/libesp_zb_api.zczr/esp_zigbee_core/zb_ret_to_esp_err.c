/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> zb_ret_to_esp_err
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_ret_to_esp_err(int param_1)

{
  if (param_1 != 0) {
    if (param_1 == -0x1c) {
      return 0x105;
    }
    if (param_1 == -0x16) {
      return 0x101;
    }
    if ((param_1 + 0xdU < 4) || (param_1 == -0xf)) {
      return 0x102;
    }
    if (param_1 == -6) {
      return 0x104;
    }
    if (param_1 != -0x1e) {
      if (param_1 == -2) {
        return 0x10c;
      }
      if (param_1 == -0x23) {
        return 0x103;
      }
      param_1 = -1;
    }
  }
  return param_1;
}

