/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_desc.o -> zcl_cluster_get_attr_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_cluster_get_attr_desc(ushort *param_1,uint param_2,uint param_3)

{
  if (param_1 != (ushort *)0x0) {
    while (param_1 = *(ushort **)(param_1 + 6), param_1 != (ushort *)0x0) {
      if (*param_1 == param_2) {
        if (param_3 == 0) {
          return;
        }
        if (((*(byte *)((int)param_1 + 3) & 0x20) != 0) && (param_1[2] == param_3)) {
          return;
        }
      }
    }
  }
  return;
}

