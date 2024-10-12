/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zdo_command.o -> esp_zb_zdo_callback_remove
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
  pbVar2 = zdo_resp_cb_list_head;
  if ((zdo_resp_cb_list_head == (byte *)0x0) || (*zdo_resp_cb_list_head != param_1)) {
    while ((__ptr = pbVar1, __ptr != (byte *)0x0 && (*__ptr != param_1))) {
      pbVar2 = __ptr;
      pbVar1 = *(byte **)(__ptr + 0xc);
    }
    if (__ptr != (byte *)0x0) {
      *(undefined4 *)(pbVar2 + 0xc) = *(undefined4 *)(__ptr + 0xc);
      free(__ptr);
    }
  }
  else {
    zdo_resp_cb_list_head = *(byte **)(zdo_resp_cb_list_head + 0xc);
    free(pbVar1);
  }
  return;
}

