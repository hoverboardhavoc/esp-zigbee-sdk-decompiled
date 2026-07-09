/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_cluster_list_add_custom_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_cluster_list_add_custom_cluster(int param_1,int param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 2;
  }
  else {
    uVar1 = 2;
    if (param_2 != 0) {
      *(undefined1 *)(param_2 + -10) = param_3;
      *(undefined4 *)(param_2 + -4) = 0x10000;
      uVar1 = ezb_af_endpoint_add_cluster_desc(param_1 + -4,param_2 + -0xc);
    }
  }
  esp_zigbee_err_to_esp(uVar1);
  return;
}

