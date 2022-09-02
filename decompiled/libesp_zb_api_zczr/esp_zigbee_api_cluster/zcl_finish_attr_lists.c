/*
 * Last changed at upstream commit 161b24f200d3999849a30e5fddeac9123c04dbfe
 * https://github.com/espressif/esp-zigbee-sdk/commit/161b24f200d3999849a30e5fddeac9123c04dbfe
 * Upstream date: 2022-09-02 14:39:54 +0800
 * Upstream subject: Components: Separation of the zigbee_core_api header
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_cluster.o -> zcl_finish_attr_lists
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_finish_attr_lists(int param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)malloc(0x10);
  puVar1[4] = *(undefined2 *)(param_1 + 8);
  *(undefined1 *)((int)puVar1 + 3) = 0;
  *(undefined4 *)(puVar1 + 2) = 0;
  *puVar1 = 0xffff;
  *(undefined1 *)(puVar1 + 1) = 0;
  *(undefined4 *)(puVar1 + 6) = 0;
  *(undefined2 **)(param_1 + 0xc) = puVar1;
  return;
}

