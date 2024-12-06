/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_occupancy_sensing_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_add_occupancy_sensing_cluster(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 *__ptr;
  int iVar1;
  uint uStack_2c;
  int aiStack_24 [4];
  
  __ptr = (undefined4 *)malloc(0x14);
  aiStack_24[0] = 0;
  iVar1 = esp_zb_cluster_list_get_tail(param_1,param_2,0x406,param_3,aiStack_24);
  if (aiStack_24[0] == 0) {
    uStack_2c = param_3 & 0xff;
    *__ptr = 0x406;
    __ptr[1] = param_2;
    __ptr[2] = uStack_2c;
    *(undefined2 *)(__ptr + 3) = 0;
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

