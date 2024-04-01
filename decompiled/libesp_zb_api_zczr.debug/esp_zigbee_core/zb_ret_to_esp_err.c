/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zb_ret_to_esp_err
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

