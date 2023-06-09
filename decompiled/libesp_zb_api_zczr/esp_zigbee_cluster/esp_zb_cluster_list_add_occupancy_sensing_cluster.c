/*
 * Last changed at upstream commit 6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * https://github.com/espressif/esp-zigbee-sdk/commit/6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * Upstream date: 2023-06-09 17:12:37 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.6.2(2626797)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_occupancy_sensing_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_add_occupancy_sensing_cluster(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 *__ptr;
  int iVar3;
  undefined4 uVar4;
  undefined4 uStack_34;
  uint uStack_2c;
  int iStack_24;
  
  __ptr = (undefined4 *)malloc(0x14);
  iStack_24 = 0;
  iVar3 = esp_zb_cluster_list_get_tail(param_1,param_2,0x406,param_3,&iStack_24);
  iVar1 = iStack_24;
  if (iStack_24 == 0) {
    uVar4 = zcl_get_attr_lists(param_2);
    uVar2 = zcl_get_attr_count(param_2);
    uStack_34 = CONCAT22(uVar2,0x406);
    uStack_2c = param_3 & 0xff;
    *__ptr = uStack_34;
    __ptr[1] = uVar4;
    __ptr[2] = uStack_2c;
    *(undefined2 *)(__ptr + 3) = 0;
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

