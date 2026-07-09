/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> aps_group_table_remove_endpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_group_table_remove_endpoint(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = core_globals_get();
  uVar2 = 0;
  while (uVar2 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar1 + 0x960),*(undefined2 *)(iVar1 + 0x964),uVar2),
        uVar2 < *(ushort *)(iVar1 + 0x964)) {
    group_remove_endpoint(*(int *)(iVar1 + 0x95c) + uVar2 * 0x22,param_1);
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return;
}

