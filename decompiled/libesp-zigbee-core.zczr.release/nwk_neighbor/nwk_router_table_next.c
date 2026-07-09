/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_router_table_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_router_table_next(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = core_globals_get();
  if (param_1 == 0) {
    uVar4 = 0xffff;
  }
  else {
    uVar4 = (param_1 - *(int *)(iVar2 + 0xb20) >> 2) * -0x49249249 & 0xffff;
  }
  uVar1 = (uint)*(ushort *)(iVar2 + 0xb24) - (uint)*(ushort *)(iVar2 + 0xb26) & 0xffff;
  uVar4 = bitmap_find_next_bit(*(undefined4 *)(iVar2 + 0xb1c),uVar1,uVar4 + 1 & 0xffff);
  iVar3 = 0;
  if (uVar4 < uVar1) {
    iVar3 = *(int *)(iVar2 + 0xb20) + uVar4 * 0x1c;
  }
  return iVar3;
}

