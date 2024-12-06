/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> zb_ret_to_esp_err
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
    if (param_1 + 0xbU < 2) {
      return 0x102;
    }
    if (param_1 == -0xc) {
      return 0x102;
    }
    if (param_1 == -0xd) {
      return 0x102;
    }
    if (param_1 == -0xf) {
      return 0x102;
    }
    if (param_1 == -6) {
      return 0x104;
    }
    if (param_1 != -0x1e) {
      if (param_1 == -2) {
        return 0x10c;
      }
      param_1 = -1;
    }
  }
  return param_1;
}

