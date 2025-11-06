/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_custom_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_add_custom_cluster(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  undefined2 *__ptr;
  int iVar2;
  undefined *puVar3;
  int aiStack_24 [3];
  
  __ptr = (undefined2 *)malloc(0x14);
  iVar2 = esp_zb_cluster_list_get_tail(param_1,param_2,0x8000,param_3,aiStack_24);
  if (aiStack_24[0] == 0) {
    if (param_3 == 1) {
      puVar3 = &esp_zb_zcl_custom_cluster_init_server;
    }
    else {
      puVar3 = (undefined *)0x0;
      if (param_3 == 2) {
        puVar3 = &esp_zb_zcl_custom_cluster_init_client;
      }
    }
    uVar1 = *(undefined2 *)(*(int *)(param_2 + 0xc) + 10);
    *(char *)((int)__ptr + 0xb) = (char)puVar3;
    __ptr[1] = 0;
    *__ptr = uVar1;
    *(char *)(__ptr + 6) = (char)((uint)puVar3 >> 8);
    *(int *)(__ptr + 2) = param_2;
    *(char *)(__ptr + 4) = (char)param_3;
    *(undefined1 *)((int)__ptr + 9) = 0;
    *(undefined1 *)(__ptr + 5) = 0;
    *(char *)((int)__ptr + 0xd) = (char)((uint)puVar3 >> 0x10);
    *(undefined1 *)(__ptr + 7) = 0;
    *(undefined4 *)(__ptr + 8) = 0;
    if (iVar2 == 0) {
      *(undefined2 **)(param_1 + 0x10) = __ptr;
    }
    else {
      *(undefined2 **)(iVar2 + 0x10) = __ptr;
    }
  }
  else {
    free(__ptr);
  }
  return aiStack_24[0];
}

