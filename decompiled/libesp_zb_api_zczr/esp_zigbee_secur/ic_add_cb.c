/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_secur.o -> ic_add_cb
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

