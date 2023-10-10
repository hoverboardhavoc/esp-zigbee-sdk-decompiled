/*
 * Last changed at upstream commit 37b2129eea9960f95d70bf2e6607337834e2750d
 * https://github.com/espressif/esp-zigbee-sdk/commit/37b2129eea9960f95d70bf2e6607337834e2750d
 * Upstream date: 2023-10-10 17:40:24 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.0(8d71c0ae)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_multistate_value_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_add_multistate_value_cluster(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 *__ptr;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined4 uStack_34;
  uint3 uStack_2c;
  undefined1 uStack_29;
  undefined2 uStack_28;
  int iStack_24;
  
  __ptr = (undefined4 *)malloc(0x14);
  iStack_24 = 0;
  iVar3 = esp_zb_cluster_list_get_tail(param_1,param_2,0x14,param_3,&iStack_24);
  iVar1 = iStack_24;
  if (iStack_24 == 0) {
    uVar4 = zcl_get_attr_lists(param_2);
    uVar2 = zcl_get_attr_count(param_2);
    uStack_34 = CONCAT22(uVar2,0x14);
    if (param_3 == 1) {
      puVar5 = &zb_zcl_multi_value_init_server;
    }
    else if (param_3 == 2) {
      puVar5 = &zb_zcl_multi_value_init_client;
    }
    else {
      puVar5 = (undefined *)0x0;
    }
    _uStack_2c = CONCAT13((char)puVar5,(uint3)(byte)param_3);
    uStack_28 = (undefined2)((uint)puVar5 >> 8);
    *__ptr = uStack_34;
    __ptr[1] = uVar4;
    __ptr[2] = _uStack_2c;
    *(undefined2 *)(__ptr + 3) = uStack_28;
    *(undefined1 *)((int)__ptr + 0xe) = 0;
    __ptr[4] = 0;
    iStack_24 = iVar1;
    if (iVar3 == 0) {
      *(undefined4 **)(param_1 + 0x10) = __ptr;
    }
    else {
      *(undefined4 **)(iVar3 + 0x10) = __ptr;
    }
  }
  else {
    free(__ptr);
  }
  return iStack_24;
}

