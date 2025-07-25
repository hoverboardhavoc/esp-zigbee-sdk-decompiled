/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_cluster.o -> esp_zb_cluster_list_add_ec_measurement_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_add_ec_measurement_cluster(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 *__ptr;
  int iVar1;
  undefined2 uVar2;
  uint uStack_2c;
  int aiStack_24 [4];
  
  __ptr = (undefined4 *)malloc(0x14);
  aiStack_24[0] = 0;
  iVar1 = esp_zb_cluster_list_get_tail(param_1,param_2,0x40a,param_3,aiStack_24);
  if (aiStack_24[0] == 0) {
    if (param_3 == 1) {
      uVar2 = 0x162;
    }
    else {
      uVar2 = 0;
    }
    uStack_2c = param_3 & 0xff;
    *__ptr = 0x40a;
    __ptr[1] = param_2;
    __ptr[2] = uStack_2c;
    *(undefined2 *)(__ptr + 3) = uVar2;
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

