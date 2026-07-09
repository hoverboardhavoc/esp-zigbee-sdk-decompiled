/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_set_ed_capacity
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_neighbor_table_set_ed_capacity(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = core_globals_get();
  uVar2 = nwk_neighbor_table_get_capacity();
  if (uVar2 < param_1) {
    uVar4 = 2;
  }
  else {
    iVar3 = nwk_neighbor_table_get_size();
    if (iVar3 == 0) {
      *(short *)(iVar1 + 0xb26) = (short)param_1;
      uVar4 = 0;
    }
    else {
      uVar4 = 0xd;
    }
  }
  return uVar4;
}

