/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_poll_control_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_add_poll_control_cluster(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 *__ptr;
  int iVar2;
  undefined *puVar3;
  undefined2 uStack_3c;
  undefined1 uStack_3a;
  undefined4 auStack_38 [3];
  uint3 uStack_2c;
  undefined1 uStack_29;
  undefined2 uStack_28;
  int aiStack_24 [2];
  
  aiStack_24[0] = 0;
  __ptr = (undefined4 *)malloc(0x14);
  iVar2 = esp_zb_cluster_list_get_tail(param_1,param_2,0x20,param_3,aiStack_24);
  iVar1 = aiStack_24[0];
  if (aiStack_24[0] == 0) {
    if ((param_3 & 2) != 0) {
      uStack_3c = 0;
      uStack_3a = 0;
      auStack_38[0] = 0;
      esp_zb_poll_control_cluster_add_attr(param_2,0xefff,&uStack_3c);
      esp_zb_poll_control_cluster_add_attr(param_2,0xeffe,auStack_38);
    }
    if (param_3 == 1) {
      puVar3 = &esp_zb_zcl_poll_control_init_server;
    }
    else if (param_3 == 2) {
      puVar3 = &esp_zb_zcl_poll_control_init_client;
    }
    else {
      puVar3 = (undefined *)0x0;
    }
    _uStack_2c = CONCAT13((char)puVar3,(uint3)(byte)param_3);
    uStack_28 = (undefined2)((uint)puVar3 >> 8);
    *__ptr = 0x20;
    __ptr[1] = param_2;
    __ptr[2] = _uStack_2c;
    *(undefined2 *)(__ptr + 3) = uStack_28;
    *(undefined1 *)((int)__ptr + 0xe) = 0;
    __ptr[4] = 0;
    aiStack_24[0] = iVar1;
    if (iVar2 == 0) {
      *(undefined4 **)(param_1 + 0x10) = __ptr;
    }
    else {
      *(undefined4 **)(iVar2 + 0x10) = __ptr;
    }
  }
  else {
    free(__ptr);
  }
  return aiStack_24[0];
}

