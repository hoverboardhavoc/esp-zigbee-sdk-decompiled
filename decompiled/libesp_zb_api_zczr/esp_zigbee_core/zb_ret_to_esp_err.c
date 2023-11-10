/*
 * Last changed at upstream commit 9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * https://github.com/espressif/esp-zigbee-sdk/commit/9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * Upstream date: 2023-11-10 18:10:39 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.3(ba5a889a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_ret_to_esp_err
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

