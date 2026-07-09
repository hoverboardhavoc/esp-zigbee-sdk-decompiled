/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_custom_cluster_add_custom_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_custom_cluster_add_custom_attr
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined2 *puVar1;
  
  if (param_1 == 0) {
    puVar1 = (undefined2 *)0x0;
  }
  else {
    puVar1 = (undefined2 *)(param_1 + -0xc);
  }
  esp_zb_cluster_add_manufacturer_attr(*puVar1,param_2,0,param_3,param_4,param_5);
  return;
}

