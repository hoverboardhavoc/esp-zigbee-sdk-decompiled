/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_occupancy_sensing_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_add_occupancy_sensing_cluster(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined2 extraout_a0;
  undefined4 *__ptr;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_3c;
  uint uStack_34;
  int aiStack_24 [2];
  
  __ptr = (undefined4 *)malloc(0x14);
  aiStack_24[0] = 0;
  iVar2 = esp_zb_cluster_list_get_tail(param_1,param_2,0x406,param_3,aiStack_24);
  iVar1 = aiStack_24[0];
  if (aiStack_24[0] == 0) {
    uVar3 = zcl_convert_attr_list_to_array(param_2);
    uStack_3c = CONCAT22(extraout_a0,0x406);
    uStack_34 = param_3 & 0xff;
    *__ptr = uStack_3c;
    __ptr[1] = uVar3;
    __ptr[2] = uStack_34;
    *(undefined2 *)(__ptr + 3) = 0;
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

