/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_cluster_list_get_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cluster_list_get_cluster(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    param_1 = param_1 + -4;
  }
  iVar1 = ezb_af_endpoint_get_cluster_desc(param_1);
  if (iVar1 != 0) {
    iVar1 = iVar1 + 0xc;
  }
  return iVar1;
}

