/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
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
  esp_zb_internal_zcl_add_attr_list_to_set();
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

