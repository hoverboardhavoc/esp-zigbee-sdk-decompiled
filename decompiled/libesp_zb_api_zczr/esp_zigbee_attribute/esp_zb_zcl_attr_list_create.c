/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_zcl_attr_list_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * esp_zb_zcl_attr_list_create(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar1 = (undefined4 *)malloc(0x10);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar2 = (undefined4 *)malloc(0x10);
  *puVar2 = 0x121fffd;
  *(short *)((int)puVar2 + 10) = (short)param_1;
  *(undefined2 *)(puVar2 + 1) = 0xffff;
  puVar3 = (undefined2 *)malloc(2);
  *(short *)(puVar2 + 2) = (short)((uint)puVar3 >> 0x10);
  *puVar3 = 4;
  *(short *)((int)puVar2 + 6) = (short)puVar3;
  puVar2[3] = 0;
  puVar1[3] = puVar2;
  if (param_1 == 8) {
    puVar4 = (undefined4 *)malloc(0x10);
    *puVar4 = 0x4012efff;
    *(short *)((int)puVar4 + 10) = (short)param_1;
    *(undefined2 *)(puVar4 + 1) = 0xffff;
    puVar5 = (undefined4 *)malloc(0x12);
    *(short *)((int)puVar4 + 6) = (short)puVar5;
    *(short *)(puVar4 + 2) = (short)((uint)puVar5 >> 0x10);
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    *(undefined2 *)(puVar5 + 4) = 0;
    puVar4[3] = 0;
    puVar2[3] = puVar4;
  }
  return puVar1;
}

