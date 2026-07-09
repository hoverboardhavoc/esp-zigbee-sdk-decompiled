/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_get_by_addr_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_neighbor_table_get_by_addr_ref(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = core_globals_get();
  uVar4 = 0;
  while( true ) {
    uVar4 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar2 + 0xb1c),*(undefined2 *)(iVar2 + 0xb24),uVar4);
    if (*(ushort *)(iVar2 + 0xb24) <= uVar4) {
      return 0;
    }
    iVar1 = *(int *)(iVar2 + 0xb20) + uVar4 * 0x1c;
    iVar3 = nbr_is_matched(iVar1,param_1);
    if (iVar3 != 0) break;
    uVar4 = uVar4 + 1 & 0xffff;
  }
  return iVar1;
}

