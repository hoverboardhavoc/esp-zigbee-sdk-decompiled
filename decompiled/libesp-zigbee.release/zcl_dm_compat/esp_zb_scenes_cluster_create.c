/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_scenes_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_scenes_cluster_create(undefined1 *param_1)

{
  undefined1 uVar1;
  
  if (param_1 != (undefined1 *)0x0) {
    uVar1 = esp_zb_zcl_scenes_table_get_size();
    *param_1 = uVar1;
  }
  scenes_cluster_create(param_1);
  return;
}

