/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_basic_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_add_basic_cluster(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  ushort extraout_a0;
  int *__ptr;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int iStack_3c;
  uint3 uStack_34;
  undefined1 uStack_31;
  undefined2 uStack_30;
  int aiStack_24 [2];
  
  __ptr = (int *)malloc(0x14);
  aiStack_24[0] = 0;
  iVar2 = esp_zb_cluster_list_get_tail(param_1,param_2,0,param_3,aiStack_24);
  iVar1 = aiStack_24[0];
  if (aiStack_24[0] == 0) {
    iVar3 = zcl_convert_attr_list_to_array(param_2);
    iStack_3c = (uint)extraout_a0 << 0x10;
    if (param_3 == 1) {
      puVar4 = &esp_zb_zcl_basic_init_server;
    }
    else if (param_3 == 2) {
      puVar4 = &zb_zcl_basic_init_client;
    }
    else {
      puVar4 = (undefined *)0x0;
    }
    _uStack_34 = CONCAT13((char)puVar4,(uint3)(byte)param_3);
    uStack_30 = (undefined2)((uint)puVar4 >> 8);
    *__ptr = iStack_3c;
    __ptr[1] = iVar3;
    __ptr[2] = _uStack_34;
    *(undefined2 *)(__ptr + 3) = uStack_30;
    *(undefined1 *)((int)__ptr + 0xe) = 0;
    __ptr[4] = 0;
    aiStack_24[0] = iVar1;
    if (iVar2 == 0) {
      *(int **)(param_1 + 0x10) = __ptr;
    }
    else {
      *(int **)(iVar2 + 0x10) = __ptr;
    }
  }
  else {
    free(__ptr);
  }
  return aiStack_24[0];
}

