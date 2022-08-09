/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_secur.o -> ic_remove_all_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ic_remove_all_cb(void)

{
  char *pcVar1;
  
  pcVar1 = (char *)zb_buf_get_tail_func(1);
  if (*pcVar1 == '\0') {
    ic_remove_all_cb_ret = 0;
  }
  else if (*pcVar1 == -0x2b) {
    ic_remove_all_cb_ret = 0x105;
  }
  else {
    ic_remove_all_cb_ret = 0;
  }
  return;
}

