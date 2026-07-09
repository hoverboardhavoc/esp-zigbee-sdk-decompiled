/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_next_by_endpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_group_table_next_by_endpoint(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = core_globals_get();
  if (param_2 == 0) {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = (param_2 - *(int *)(iVar2 + 0x95c) >> 1) * -0xf0f0f0f & 0xffff;
  }
  do {
    uVar1 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar2 + 0x960),*(undefined2 *)(iVar2 + 0x964),
                       uVar1 + 1 & 0xffff);
    if (*(ushort *)(iVar2 + 0x964) <= uVar1) {
      return 0;
    }
    iVar3 = group_check_endpoint(*(int *)(iVar2 + 0x95c) + uVar1 * 0x22,param_1);
  } while (iVar3 == 0);
  return *(int *)(iVar2 + 0x95c) + uVar1 * 0x22;
}

