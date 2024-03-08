/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
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
      if (param_1 == 0x101) {
        return -0x16;
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

