/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> aps_group_table_is_endpoint_in_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool aps_group_table_is_endpoint_in_group(uint param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = group_table_find(param_2);
  if (iVar2 == 0) {
    bVar1 = false;
  }
  else {
    fence();
    fence();
    bVar1 = ((uint)*(byte *)(iVar2 + (param_1 >> 3) + 2) & 1 << (param_1 & 7)) != 0;
  }
  return bVar1;
}

