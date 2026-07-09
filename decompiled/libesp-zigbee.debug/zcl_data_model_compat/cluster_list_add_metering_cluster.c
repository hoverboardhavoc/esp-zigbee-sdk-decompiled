/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_data_model_compat.o -> cluster_list_add_metering_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cluster_list_add_metering_cluster(int param_1,int param_2,byte param_3)

{
  undefined4 uVar1;
  undefined *puVar2;
  
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
    *(byte *)(param_2 + 2) = param_3;
    if ((param_3 & 1) == 0) {
      puVar2 = &ezb_zcl_metering_cluster_client_init;
    }
    else {
      puVar2 = &ezb_zcl_metering_cluster_server_init;
    }
    *(undefined **)(param_2 + 8) = puVar2;
    zcl_cluster_desc_add_revision_attr(param_2,3);
    uVar1 = ezb_af_endpoint_add_cluster_desc(param_1,param_2);
  }
  esp_zigbee_err_to_esp(uVar1);
  return;
}

