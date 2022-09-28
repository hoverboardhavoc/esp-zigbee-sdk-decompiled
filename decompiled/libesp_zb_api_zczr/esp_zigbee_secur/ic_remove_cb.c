/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_secur.o -> ic_remove_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ic_remove_cb(void)

{
  char *pcVar1;
  
  pcVar1 = (char *)zb_buf_get_tail_func(1);
  if (*pcVar1 == '\0') {
    ic_remove_cb_ret = 0;
  }
  else if (*pcVar1 == -0x2b) {
    ic_remove_cb_ret = 0x105;
  }
  else {
    ic_remove_cb_ret = 0;
  }
  return;
}

