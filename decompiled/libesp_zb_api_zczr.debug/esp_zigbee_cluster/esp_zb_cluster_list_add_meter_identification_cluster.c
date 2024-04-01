/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_meter_identification_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_add_meter_identification_cluster(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined2 extraout_a0;
  undefined4 *__ptr;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 uStack_3c;
  uint3 uStack_34;
  undefined1 uStack_31;
  undefined2 uStack_30;
  int aiStack_24 [2];
  
  __ptr = (undefined4 *)malloc(0x14);
  aiStack_24[0] = 0;
  iVar2 = esp_zb_cluster_list_get_tail(param_1,param_2,0xb01,param_3,aiStack_24);
  iVar1 = aiStack_24[0];
  if (aiStack_24[0] == 0) {
    uVar3 = zcl_convert_attr_list_to_array(param_2);
    uStack_3c = CONCAT22(extraout_a0,0xb01);
    if (param_3 == 1) {
      puVar4 = &zb_zcl_meter_identification_init_server;
    }
    else if (param_3 == 2) {
      puVar4 = &zb_zcl_meter_identification_init_client;
    }
    else {
      puVar4 = (undefined *)0x0;
    }
    _uStack_34 = CONCAT13((char)puVar4,(uint3)(byte)param_3);
    uStack_30 = (undefined2)((uint)puVar4 >> 8);
    *__ptr = uStack_3c;
    __ptr[1] = uVar3;
    __ptr[2] = _uStack_34;
    *(undefined2 *)(__ptr + 3) = uStack_30;
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

