/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> aps_group_table_next_by_endpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_group_table_next_by_endpoint(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = core_globals_get();
  if (param_2 == 0) {
    uVar2 = 0xffff;
  }
  else {
    uVar2 = (param_2 - *(int *)(iVar1 + 0x95c) >> 1) * -0xf0f0f0f & 0xffff;
  }
  do {
    uVar2 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar1 + 0x960),*(undefined2 *)(iVar1 + 0x964),
                       uVar2 + 1 & 0xffff);
    if (*(ushort *)(iVar1 + 0x964) <= uVar2) {
      return 0;
    }
    fence();
    fence();
  } while (((uint)*(byte *)(*(int *)(iVar1 + 0x95c) + uVar2 * 0x22 + (param_1 >> 3) + 2) &
           1 << (param_1 & 7)) == 0);
  return *(int *)(iVar1 + 0x95c) + uVar2 * 0x22;
}

