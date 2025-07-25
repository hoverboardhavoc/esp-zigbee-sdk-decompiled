/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_callback_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_callback_register
               (uint param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *__ptr;
  
  pbVar2 = zdo_resp_cb_list_head;
  __ptr = (byte *)malloc(0x10);
  pbVar1 = zdo_resp_cb_list_head;
  if (__ptr != (byte *)0x0) {
    pbVar1 = pbVar2;
    if (pbVar2 != (byte *)0x0) {
      do {
        pbVar2 = pbVar1;
        if (*pbVar2 == param_1) {
          free(__ptr);
          return;
        }
        pbVar1 = *(byte **)(pbVar2 + 0xc);
      } while (*(byte **)(pbVar2 + 0xc) != (byte *)0x0);
    }
    *__ptr = (byte)param_1;
    *(undefined2 *)(__ptr + 2) = param_2;
    *(undefined4 *)(__ptr + 4) = param_3;
    *(undefined4 *)(__ptr + 8) = param_4;
    __ptr[0xc] = 0;
    __ptr[0xd] = 0;
    __ptr[0xe] = 0;
    __ptr[0xf] = 0;
    pbVar1 = __ptr;
    if (pbVar2 != (byte *)0x0) {
      *(byte **)(pbVar2 + 0xc) = __ptr;
      pbVar1 = zdo_resp_cb_list_head;
    }
  }
  zdo_resp_cb_list_head = pbVar1;
  return;
}

