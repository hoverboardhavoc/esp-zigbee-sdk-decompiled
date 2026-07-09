/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_cluster_get_next_attr_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_cluster_get_next_attr_desc(int param_1,int param_2)

{
  if (param_1 != 0) {
    if (param_2 == 0) {
      return *(int *)(param_1 + 0xc);
    }
    param_1 = *(int *)(param_2 + 0xc);
  }
  return param_1;
}

