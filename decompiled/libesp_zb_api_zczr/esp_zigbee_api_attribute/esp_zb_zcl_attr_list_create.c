/*
 * Last changed at upstream commit 161b24f200d3999849a30e5fddeac9123c04dbfe
 * https://github.com/espressif/esp-zigbee-sdk/commit/161b24f200d3999849a30e5fddeac9123c04dbfe
 * Upstream date: 2022-09-02 14:39:54 +0800
 * Upstream subject: Components: Separation of the zigbee_core_api header
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_attribute.o -> esp_zb_zcl_attr_list_create
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
  puVar2[4] = (short)param_1;
  *puVar2 = 0xfffd;
  *(undefined1 *)((int)puVar2 + 3) = 1;
  *(undefined1 *)(puVar2 + 1) = 0x21;
  *(undefined2 **)(puVar2 + 2) = &cluster_revision_1;
  *(undefined4 *)(puVar2 + 6) = 0;
  *(undefined2 **)((int)pvVar1 + 0xc) = puVar2;
  if (param_1 == 8) {
    puVar3 = (undefined2 *)malloc(0x10);
    puVar3[4] = (short)param_1;
    *puVar3 = 0xefff;
    *(undefined1 *)((int)puVar3 + 3) = 0x40;
    *(undefined1 *)(puVar3 + 1) = 0;
    *(undefined1 **)(puVar3 + 2) = ls_move_status_data_ctx_0;
    *(undefined4 *)(puVar3 + 6) = 0;
    *(undefined2 **)(puVar2 + 6) = puVar3;
  }
  return pvVar1;
}

