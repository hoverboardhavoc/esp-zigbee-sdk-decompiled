/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_metering_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_metering_cluster_create(undefined4 *param_1)

{
  undefined4 extraout_a1;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  local_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 != (undefined4 *)0x0) {
    local_20 = convert_uint48_to_uint64();
    uStack_18 = *(undefined4 *)((int)param_1 + 6);
    param_1 = &local_20;
    uStack_1c = extraout_a1;
  }
  metering_cluster_create(param_1);
  return;
}

