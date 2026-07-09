/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_data_model_compat.o -> ias_wd_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_wd_cluster_add_attr(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar1 = 2;
  }
  else {
    iVar2 = param_1 + -0xc;
    if (*(char *)(param_1 + -10) == '\0') {
      *(undefined1 *)(param_1 + -10) = 2;
      iVar1 = ezb_zcl_ias_wd_cluster_desc_add_attr(iVar2);
      if (iVar1 != 0) {
        *(undefined1 *)(param_1 + -10) = 1;
        iVar1 = ezb_zcl_ias_wd_cluster_desc_add_attr(iVar2,param_2,param_3);
      }
    }
    else {
      iVar1 = ezb_zcl_ias_wd_cluster_desc_add_attr(iVar2);
    }
  }
  esp_zigbee_err_to_esp(iVar1);
  return;
}

