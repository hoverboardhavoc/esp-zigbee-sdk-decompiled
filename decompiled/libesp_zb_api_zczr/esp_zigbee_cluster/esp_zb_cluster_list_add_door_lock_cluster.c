/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_door_lock_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_add_door_lock_cluster(int param_1,undefined4 param_2,int param_3)

{
  undefined2 extraout_a0;
  undefined2 *__ptr;
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int aiStack_2c [4];
  
  __ptr = (undefined2 *)malloc(0x14);
  iVar1 = esp_zb_cluster_list_get_tail(param_1,param_2,0x101,param_3,aiStack_2c);
  if (aiStack_2c[0] == 0) {
    uVar2 = zcl_convert_attr_list_to_array(param_2);
    if (param_3 == 1) {
      puVar3 = &zb_zcl_door_lock_init_server;
    }
    else if (param_3 == 2) {
      puVar3 = &zb_zcl_door_lock_init_client;
    }
    else {
      puVar3 = (undefined *)0x0;
    }
    *__ptr = 0x101;
    *(char *)((int)__ptr + 0xb) = (char)puVar3;
    *(char *)(__ptr + 6) = (char)((uint)puVar3 >> 8);
    __ptr[1] = extraout_a0;
    *(undefined4 *)(__ptr + 2) = uVar2;
    *(char *)(__ptr + 4) = (char)param_3;
    *(undefined1 *)((int)__ptr + 9) = 0;
    *(undefined1 *)(__ptr + 5) = 0;
    *(char *)((int)__ptr + 0xd) = (char)((uint)puVar3 >> 0x10);
    *(undefined1 *)(__ptr + 7) = 0;
    *(undefined4 *)(__ptr + 8) = 0;
    if (iVar1 == 0) {
      *(undefined2 **)(param_1 + 0x10) = __ptr;
    }
    else {
      *(undefined2 **)(iVar1 + 0x10) = __ptr;
    }
  }
  else {
    free(__ptr);
  }
  return aiStack_2c[0];
}

