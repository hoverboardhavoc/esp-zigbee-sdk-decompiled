/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_secur.o -> ic_add_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ic_add_cb(int param_1)

{
  if (param_1 == 0) {
    ic_add_cb_ret = 0;
    return;
  }
  if (param_1 != -0x32) {
    ic_add_cb_ret = 0;
    return;
  }
  ic_add_cb_ret = 0x109;
  return;
}

