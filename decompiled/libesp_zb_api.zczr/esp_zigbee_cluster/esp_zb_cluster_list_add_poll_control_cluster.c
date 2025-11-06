/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_poll_control_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

int esp_zb_cluster_list_add_poll_control_cluster(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 *__ptr;
  int iVar1;
  undefined *puVar2;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  int aiStack_28 [3];
  
  __ptr = (undefined4 *)malloc(0x14);
  iVar1 = esp_zb_cluster_list_get_tail(param_1,param_2,0x20,param_3,aiStack_28);
  if (aiStack_28[0] != 0) {
    free(__ptr);
    return aiStack_28[0];
  }
  if ((param_3 & 2) == 0) {
    if (param_3 == 1) {
      puVar2 = &esp_zb_zcl_poll_control_init_server;
      goto _L0;
    }
  }
  else {
    uStack_2c = 0;
    uStack_2a = 0;
    aiStack_28[1] = 0;
    esp_zb_poll_control_cluster_add_attr(param_2,0xefff,&uStack_2c);
    esp_zb_poll_control_cluster_add_attr(param_2,0xeffe,aiStack_28 + 1);
    if (param_3 == 2) {
      puVar2 = &esp_zb_zcl_poll_control_init_client;
      goto _L0;
    }
  }
  puVar2 = (undefined *)0x0;
_L0:
  *__ptr = 0x20;
  *(char *)((int)__ptr + 0xb) = (char)puVar2;
  *(char *)(__ptr + 3) = (char)((uint)puVar2 >> 8);
  __ptr[1] = param_2;
  *(char *)(__ptr + 2) = (char)param_3;
  *(undefined1 *)((int)__ptr + 9) = 0;
  *(undefined1 *)((int)__ptr + 10) = 0;
  *(char *)((int)__ptr + 0xd) = (char)((uint)puVar2 >> 0x10);
  *(undefined1 *)((int)__ptr + 0xe) = 0;
  __ptr[4] = 0;
  if (iVar1 == 0) {
    *(undefined4 **)(param_1 + 0x10) = __ptr;
  }
  else {
    *(undefined4 **)(iVar1 + 0x10) = __ptr;
  }
  return 0;
}

