/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_secur.o -> ic_remove_cb
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

