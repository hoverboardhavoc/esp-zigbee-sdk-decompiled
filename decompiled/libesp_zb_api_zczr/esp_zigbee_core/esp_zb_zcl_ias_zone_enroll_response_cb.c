/*
 * Last changed at upstream commit 0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * https://github.com/espressif/esp-zigbee-sdk/commit/0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * Upstream date: 2023-07-14 11:30:10 +0800
 * Upstream subject: esp-zigbee-sdk: release v0.7.1(5785a2c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_ias_zone_enroll_response_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_ias_zone_enroll_response_cb(void)

{
  int iVar1;
  undefined1 uStack_14;
  undefined1 uStack_13;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  if (zcl_ias_zone_enroll_resp_cb != (code *)0x0) {
    uStack_13 = (undefined1)((ushort)*(undefined2 *)(iVar1 + 0xc) >> 8);
    uStack_14 = (undefined1)*(undefined2 *)(iVar1 + 0xc);
    (*zcl_ias_zone_enroll_resp_cb)(uStack_14,uStack_13);
  }
  return;
}

