/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_desc.o -> zcl_get_attr_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_get_attr_desc(uint param_1,uint param_2)

{
  ushort *puVar1;
  
  puVar1 = (ushort *)zcl_get_cluster_desc();
  if (puVar1 != (ushort *)0x0) {
    while (puVar1 = *(ushort **)(puVar1 + 6), puVar1 != (ushort *)0x0) {
      if (*puVar1 == param_1) {
        if (param_2 == 0) {
          return;
        }
        if (((*(byte *)((int)puVar1 + 3) & 0x20) != 0) && (puVar1[2] == param_2)) {
          return;
        }
      }
    }
  }
  return;
}

