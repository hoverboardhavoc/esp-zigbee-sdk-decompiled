/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_endpoint.o -> esp_zb_ep_list_add_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ep_list_add_ep(byte *param_1,undefined4 param_2,uint param_3,undefined2 param_4)

{
  byte *pbVar1;
  undefined1 *__ptr;
  uint *puVar2;
  
  if (param_1 != (byte *)0x0) {
    do {
      pbVar1 = *(byte **)(param_1 + 0x24);
      if (pbVar1 == (byte *)0x0) {
        __ptr = (undefined1 *)malloc(0x28);
        if (__ptr != (undefined1 *)0x0) {
          puVar2 = (uint *)malloc(6);
          if (puVar2 != (uint *)0x0) {
            memset(__ptr + 3,0,0x25);
            __ptr[0x11] = (char)param_2;
            *puVar2 = param_3;
            *(undefined2 *)(puVar2 + 1) = param_4;
            __ptr[1] = (char)(param_3 >> 8);
            __ptr[2] = (char)(param_3 >> 0x10);
            __ptr[0x12] = (char)((uint)param_2 >> 8);
            *__ptr = (char)param_3;
            *(uint **)(__ptr + 0xc) = puVar2;
            __ptr[0x13] = (char)((uint)param_2 >> 0x10);
            __ptr[0x14] = (char)((uint)param_2 >> 0x18);
            *(undefined1 **)(param_1 + 0x24) = __ptr;
            return 0;
          }
          free(__ptr);
        }
        return 0x101;
      }
      param_1 = pbVar1;
    } while ((uint)*pbVar1 != (param_3 & 0xff));
  }
  return 0x102;
}

