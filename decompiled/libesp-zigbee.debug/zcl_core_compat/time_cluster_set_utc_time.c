/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_core_compat.o -> time_cluster_set_utc_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void time_cluster_set_utc_time(__time_t param_1)

{
  timeval local_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (s_get_utc_time_cb == 0) {
    local_20.tv_usec = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    local_20.tv_sec = param_1;
    settimeofday(&local_20,(timezone *)0x0);
  }
  return;
}

