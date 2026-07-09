/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_neighbor_table_next(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = core_globals_get();
  if (param_1 == 0) {
    uVar2 = 0xffff;
  }
  else {
    uVar2 = (param_1 - *(int *)(iVar1 + 0xb20) >> 2) * -0x49249249 & 0xffff;
  }
  uVar2 = bitmap_find_next_bit
                    (*(undefined4 *)(iVar1 + 0xb1c),*(undefined2 *)(iVar1 + 0xb24),
                     uVar2 + 1 & 0xffff);
  if (uVar2 < *(ushort *)(iVar1 + 0xb24)) {
    iVar1 = *(int *)(iVar1 + 0xb20) + uVar2 * 0x1c;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

