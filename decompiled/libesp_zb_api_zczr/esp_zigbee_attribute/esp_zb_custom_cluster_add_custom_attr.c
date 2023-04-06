/*
 * Last changed at upstream commit 6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * https://github.com/espressif/esp-zigbee-sdk/commit/6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * Upstream date: 2023-04-06 16:02:34 +0800
 * Upstream subject: example: support single C6 gateway example and other API support(a1884f9)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_custom_cluster_add_custom_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_custom_cluster_add_custom_attr
              (int param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,
              undefined4 param_5)

{
  undefined2 *__ptr;
  int iVar1;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar1 = esp_zb_attr_list_get_tail(param_1,0xfc00,param_2,aiStack_24);
  if (aiStack_24[0] == 0) {
    *__ptr = (short)param_2;
    *(undefined1 *)(__ptr + 1) = param_3;
    *(undefined1 *)((int)__ptr + 3) = param_4;
    __ptr[2] = 0xffff;
    __ptr[3] = (short)param_5;
    __ptr[4] = (short)((uint)param_5 >> 0x10);
    __ptr[5] = *(undefined2 *)(iVar1 + 10);
    *(undefined4 *)(__ptr + 6) = 0;
    if (iVar1 == 0) {
      *(undefined2 **)(param_1 + 0xc) = __ptr;
    }
    else {
      *(undefined2 **)(iVar1 + 0xc) = __ptr;
    }
  }
  else {
    free(__ptr);
  }
  return aiStack_24[0];
}

