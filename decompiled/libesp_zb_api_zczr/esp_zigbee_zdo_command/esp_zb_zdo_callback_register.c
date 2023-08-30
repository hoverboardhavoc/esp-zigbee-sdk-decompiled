/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_callback_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_callback_register(uint param_1,byte param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *__ptr;
  undefined4 uVar3;
  
  pbVar1 = zdo_resp_cb_list_head;
  __ptr = (byte *)malloc(0x10);
  if (__ptr == (byte *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(2,0x10000,&_LC17,uVar3,0x10000);
    __ptr = zdo_resp_cb_list_head;
  }
  else {
    do {
      pbVar2 = pbVar1;
      if (pbVar2 == (byte *)0x0) break;
      if (param_1 == *pbVar2) {
        free(__ptr);
        return;
      }
      pbVar1 = *(byte **)(pbVar2 + 0xc);
    } while (*(byte **)(pbVar2 + 0xc) != (byte *)0x0);
    *__ptr = (byte)param_1;
    __ptr[1] = param_2;
    *(undefined4 *)(__ptr + 4) = param_3;
    *(undefined4 *)(__ptr + 8) = param_4;
    __ptr[0xc] = 0;
    __ptr[0xd] = 0;
    __ptr[0xe] = 0;
    __ptr[0xf] = 0;
    if (pbVar2 != (byte *)0x0) {
      *(byte **)(pbVar2 + 0xc) = __ptr;
      __ptr = zdo_resp_cb_list_head;
    }
  }
  zdo_resp_cb_list_head = __ptr;
  return;
}

