/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_groups_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_add_groups_cluster(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *__ptr;
  int iVar1;
  undefined *puVar2;
  uint3 uStack_2c;
  undefined1 uStack_29;
  undefined2 uStack_28;
  int aiStack_24 [4];
  
  __ptr = (undefined4 *)malloc(0x14);
  aiStack_24[0] = 0;
  iVar1 = esp_zb_cluster_list_get_tail(param_1,param_2,4,param_3,aiStack_24);
  if (aiStack_24[0] == 0) {
    if (param_3 == 1) {
      puVar2 = &zb_zcl_groups_init_server;
    }
    else if (param_3 == 2) {
      puVar2 = &esp_zb_zcl_groups_init_client;
    }
    else {
      puVar2 = (undefined *)0x0;
    }
    _uStack_2c = CONCAT13((char)puVar2,(uint3)(byte)param_3);
    uStack_28 = (undefined2)((uint)puVar2 >> 8);
    *__ptr = 4;
    __ptr[1] = param_2;
    __ptr[2] = _uStack_2c;
    *(undefined2 *)(__ptr + 3) = uStack_28;
    *(undefined1 *)((int)__ptr + 0xe) = 0;
    __ptr[4] = 0;
    if (iVar1 == 0) {
      *(undefined4 **)(param_1 + 0x10) = __ptr;
    }
    else {
      *(undefined4 **)(iVar1 + 0x10) = __ptr;
    }
  }
  else {
    free(__ptr);
  }
  return aiStack_24[0];
}

