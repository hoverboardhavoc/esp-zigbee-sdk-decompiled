/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_next_dst_by_src
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_bind_table_next_dst_by_src(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 0) {
    uVar1 = 0xffff;
  }
  else {
    iVar2 = core_globals_get();
    uVar1 = (param_2 - *(int *)(iVar2 + 0x974) >> 1) * -0x55555555 & 0xffff;
  }
  iVar2 = core_globals_get();
  uVar1 = bitmap_find_next_bit(param_1 + 6,*(undefined2 *)(iVar2 + 0x97c),uVar1 + 1 & 0xffff);
  iVar2 = core_globals_get();
  iVar3 = 0;
  if (uVar1 < *(ushort *)(iVar2 + 0x97c)) {
    iVar2 = core_globals_get(0);
    iVar3 = *(int *)(iVar2 + 0x974) + uVar1 * 6;
  }
  return iVar3;
}

