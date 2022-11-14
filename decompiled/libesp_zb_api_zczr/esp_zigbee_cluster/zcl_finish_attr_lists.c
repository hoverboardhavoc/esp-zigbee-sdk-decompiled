/*
 * Last changed at upstream commit 7abab98979b3ea95f88c7b3687103b07986e5dd5
 * https://github.com/espressif/esp-zigbee-sdk/commit/7abab98979b3ea95f88c7b3687103b07986e5dd5
 * Upstream date: 2022-11-14 17:26:16 +0800
 * Upstream subject: examples: support rename esp32h2 to esp32h4
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> zcl_finish_attr_lists
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_finish_attr_lists(int param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)malloc(0x10);
  puVar1[5] = *(undefined2 *)(param_1 + 10);
  puVar1[2] = 0xffff;
  *(undefined1 *)((int)puVar1 + 3) = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  *puVar1 = 0xffff;
  *(undefined1 *)(puVar1 + 1) = 0;
  *(undefined4 *)(puVar1 + 6) = 0;
  *(undefined2 **)(param_1 + 0xc) = puVar1;
  return;
}

