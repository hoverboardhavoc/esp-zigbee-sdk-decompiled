/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_cluster_list_add_custom_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_cluster_list_add_custom_cluster(int param_1,int param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    param_1 = param_1 + -4;
  }
  if (param_2 != 0) {
    param_2 = param_2 + -0xc;
  }
  if (param_1 == 0) {
    uVar1 = 2;
  }
  else if (param_2 == 0) {
    uVar1 = 2;
  }
  else {
    *(undefined1 *)(param_2 + 2) = param_3;
    *(code **)(param_2 + 8) = zb_zcl_custom_cluster_init;
    uVar1 = ezb_af_endpoint_add_cluster_desc();
  }
  esp_zigbee_err_to_esp(uVar1);
  return;
}

