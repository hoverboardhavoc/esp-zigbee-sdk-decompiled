/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_err_to_zcl_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_err_to_zcl_status(int param_1)

{
  if (param_1 == 0x102) {
    return 0x85;
  }
  if (0x102 < param_1) {
    if (param_1 == 0x106) {
      return 0x81;
    }
    if (param_1 == 0x107) {
      return 0x94;
    }
    return 1;
  }
  if (param_1 == 0) {
    return 0;
  }
  if (param_1 != 0x101) {
    return 1;
  }
  return 0x89;
}

