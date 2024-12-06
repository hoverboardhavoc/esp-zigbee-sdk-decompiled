/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_secur.o -> ic_remove_cb
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

