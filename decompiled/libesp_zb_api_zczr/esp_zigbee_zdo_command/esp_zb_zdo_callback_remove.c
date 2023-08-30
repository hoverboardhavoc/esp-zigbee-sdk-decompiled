/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
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
  undefined4 uVar2;
  byte *pbVar3;
  
  pbVar1 = zdo_resp_cb_list_head;
  pbVar3 = zdo_resp_cb_list_head;
  if ((zdo_resp_cb_list_head == (byte *)0x0) || (*zdo_resp_cb_list_head != param_1)) {
    while ((__ptr = pbVar1, __ptr != (byte *)0x0 && (*__ptr != param_1))) {
      pbVar3 = __ptr;
      pbVar1 = *(byte **)(__ptr + 0xc);
    }
    if (__ptr == (byte *)0x0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(2,0x10000,&_LC3,uVar2,0x10000);
    }
    else {
      *(undefined4 *)(pbVar3 + 0xc) = *(undefined4 *)(__ptr + 0xc);
      free(__ptr);
    }
  }
  else {
    zdo_resp_cb_list_head = *(byte **)(zdo_resp_cb_list_head + 0xc);
    free(pbVar1);
  }
  return;
}

