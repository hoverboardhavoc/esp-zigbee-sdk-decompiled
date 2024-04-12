/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_custom_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_add_custom_cluster(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 extraout_a0;
  undefined4 *__ptr;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  uint3 uStack_34;
  undefined1 uStack_31;
  undefined2 uStack_30;
  int iStack_24;
  
  __ptr = (undefined4 *)malloc(0x14);
  iStack_24 = 0;
  iVar3 = esp_zb_cluster_list_get_tail(param_1,param_2,0x8000,param_3,&iStack_24);
  iVar2 = iStack_24;
  uVar1 = *(undefined2 *)(*(int *)(param_2 + 0xc) + 10);
  if (iStack_24 == 0) {
    uVar4 = zcl_convert_attr_list_to_array(param_2);
    if (param_3 == 1) {
      puVar5 = &esp_zb_zcl_custom_cluster_init_server;
    }
    else if (param_3 == 2) {
      puVar5 = &esp_zb_zcl_custom_cluster_init_client;
    }
    else {
      puVar5 = (undefined *)0x0;
    }
    _uStack_34 = CONCAT13((char)puVar5,(uint3)(byte)param_3);
    uStack_30 = (undefined2)((uint)puVar5 >> 8);
    *__ptr = CONCAT22(extraout_a0,uVar1);
    __ptr[1] = uVar4;
    __ptr[2] = _uStack_34;
    *(undefined2 *)(__ptr + 3) = uStack_30;
    *(undefined1 *)((int)__ptr + 0xe) = 0;
    __ptr[4] = 0;
    iStack_24 = iVar2;
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

