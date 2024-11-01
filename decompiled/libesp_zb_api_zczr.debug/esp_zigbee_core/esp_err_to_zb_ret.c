/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> esp_err_to_zb_ret
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

