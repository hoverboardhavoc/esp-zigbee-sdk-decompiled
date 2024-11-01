/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
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
    __ptr[1] = param_2;
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

