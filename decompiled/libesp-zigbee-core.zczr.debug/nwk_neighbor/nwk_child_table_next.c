/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_child_table_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_neighbor_t * nwk_child_table_next(nwk_neighbor_t *nbr)

{
  int iVar1;
  nwk_neighbor_t *pnVar2;
  uint uVar3;
  
  iVar1 = core_globals_get();
  if (nbr == (nwk_neighbor_t *)0x0) {
    uVar3 = ((uint)*(ushort *)(iVar1 + 0xb24) - (uint)*(ushort *)(iVar1 + 0xb26) & 0xffff) - 1;
  }
  else {
    uVar3 = ((int)nbr - *(int *)(iVar1 + 0xb20) >> 2) * -0x49249249;
  }
  uVar3 = bitmap_find_next_bit
                    (*(undefined4 *)(iVar1 + 0xb1c),*(undefined2 *)(iVar1 + 0xb24),
                     (uVar3 & 0xffff) + 1 & 0xffff);
  if (uVar3 < *(ushort *)(iVar1 + 0xb24)) {
    pnVar2 = (nwk_neighbor_t *)(*(int *)(iVar1 + 0xb20) + uVar3 * 0x1c);
  }
  else {
    pnVar2 = (nwk_neighbor_t *)0x0;
  }
  return pnVar2;
}

