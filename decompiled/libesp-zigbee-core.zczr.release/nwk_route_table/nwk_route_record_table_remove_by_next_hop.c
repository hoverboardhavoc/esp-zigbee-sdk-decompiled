/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_record_table_remove_by_next_hop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_record_table_remove_by_next_hop(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = core_globals_get();
  uVar2 = 0;
  while( true ) {
    uVar2 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar1 + 0xc74),*(undefined2 *)(iVar1 + 0xc78),uVar2);
    if (*(ushort *)(iVar1 + 0xc78) <= uVar2) break;
    iVar3 = *(int *)(iVar1 + 0xc70) + uVar2 * 0x1c;
    if (*(ushort *)(iVar3 + (*(byte *)(iVar3 + 2) - 1) * 2 + 4) == param_1) {
      mempool_free_idx(*(undefined4 *)(iVar1 + 0xc74),uVar2);
    }
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return;
}

