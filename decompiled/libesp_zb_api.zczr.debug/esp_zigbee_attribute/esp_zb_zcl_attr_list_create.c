/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_zcl_attr_list_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * esp_zb_zcl_attr_list_create(int param_1)

{
  void *__s;
  undefined2 *puVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  void *__s_00;
  
  __s = malloc(0x10);
  memset(__s,0,0x10);
  puVar1 = (undefined2 *)malloc(0x10);
  puVar1[5] = (short)param_1;
  *puVar1 = 0xfffd;
  *(undefined1 *)((int)puVar1 + 3) = 1;
  *(undefined1 *)(puVar1 + 1) = 0x21;
  puVar1[2] = 0xffff;
  puVar2 = (undefined1 *)malloc(2);
  puVar1[3] = (short)puVar2;
  puVar1[4] = (short)((uint)puVar2 >> 0x10);
  *puVar2 = 4;
  puVar2[1] = 0;
  *(undefined4 *)(puVar1 + 6) = 0;
  *(undefined2 **)((int)__s + 0xc) = puVar1;
  if (param_1 == 8) {
    puVar3 = (undefined2 *)malloc(0x10);
    puVar3[5] = (short)param_1;
    *puVar3 = 0xefff;
    *(undefined1 *)((int)puVar3 + 3) = 0x40;
    *(undefined1 *)(puVar3 + 1) = 0x12;
    puVar3[2] = 0xffff;
    __s_00 = malloc(0x12);
    puVar3[3] = (short)__s_00;
    puVar3[4] = (short)((uint)__s_00 >> 0x10);
    memset(__s_00,0,0x12);
    *(undefined4 *)(puVar3 + 6) = 0;
    *(undefined2 **)(puVar1 + 6) = puVar3;
  }
  return __s;
}

