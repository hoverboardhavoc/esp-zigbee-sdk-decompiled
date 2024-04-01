/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_callback_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_callback_remove(uint param_1)

{
  byte *pbVar1;
  byte *__ptr;
  byte *pbVar2;
  
  pbVar1 = zdo_resp_cb_list_head;
  __ptr = zdo_resp_cb_list_head;
  if ((zdo_resp_cb_list_head == (byte *)0x0) || (*zdo_resp_cb_list_head != param_1)) {
    do {
      pbVar2 = __ptr;
      __ptr = pbVar1;
      if (__ptr == (byte *)0x0) {
        return;
      }
      pbVar1 = *(byte **)(__ptr + 0xc);
    } while (*__ptr != param_1);
    *(byte **)(pbVar2 + 0xc) = *(byte **)(__ptr + 0xc);
  }
  else {
    zdo_resp_cb_list_head = *(byte **)(zdo_resp_cb_list_head + 0xc);
  }
  free(__ptr);
  return;
}

