/*
 * Last changed at upstream commit 7abab98979b3ea95f88c7b3687103b07986e5dd5
 * https://github.com/espressif/esp-zigbee-sdk/commit/7abab98979b3ea95f88c7b3687103b07986e5dd5
 * Upstream date: 2022-11-14 17:26:16 +0800
 * Upstream subject: examples: support rename esp32h2 to esp32h4
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_zcl_attr_list_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * esp_zb_zcl_attr_list_create(int param_1)

{
  void *pvVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  pvVar1 = malloc(0x10);
  puVar2 = (undefined2 *)malloc(0x10);
  puVar2[5] = (short)param_1;
  *puVar2 = 0xfffd;
  *(undefined1 *)((int)puVar2 + 3) = 1;
  *(undefined1 *)(puVar2 + 1) = 0x21;
  puVar2[2] = 0xffff;
  *(undefined2 **)(puVar2 + 3) = &cluster_revision_1;
  *(undefined4 *)(puVar2 + 6) = 0;
  *(undefined2 **)((int)pvVar1 + 0xc) = puVar2;
  if (param_1 == 8) {
    puVar3 = (undefined2 *)malloc(0x10);
    puVar3[5] = (short)param_1;
    *puVar3 = 0xefff;
    *(undefined1 *)((int)puVar3 + 3) = 0x40;
    *(undefined1 *)(puVar3 + 1) = 0;
    puVar2[2] = 0xffff;
    *(undefined1 **)(puVar3 + 3) = ls_move_status_data_ctx_0;
    *(undefined4 *)(puVar3 + 6) = 0;
    *(undefined2 **)(puVar2 + 6) = puVar3;
  }
  return pvVar1;
}

