/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_record_table_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_route_record_table_next(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = core_globals_get();
  if (param_1 == 0) {
    uVar3 = 0xffff;
  }
  else {
    uVar3 = (param_1 - *(int *)(iVar1 + 0xc70) >> 2) * -0x49249249 & 0xffff;
  }
  uVar3 = bitmap_find_next_bit
                    (*(undefined4 *)(iVar1 + 0xc74),*(undefined2 *)(iVar1 + 0xc78),
                     uVar3 + 1 & 0xffff);
  iVar2 = 0;
  if (uVar3 < *(ushort *)(iVar1 + 0xc78)) {
    iVar2 = *(int *)(iVar1 + 0xc70) + uVar3 * 0x1c;
  }
  return iVar2;
}

