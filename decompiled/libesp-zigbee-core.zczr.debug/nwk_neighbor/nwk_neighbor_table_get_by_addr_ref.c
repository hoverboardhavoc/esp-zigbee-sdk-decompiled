/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_get_by_addr_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_neighbor_t * nwk_neighbor_table_get_by_addr_ref(nwk_addr_ref_t addr_ref)

{
  nwk_neighbor_t *nbr;
  _Bool _Var1;
  int iVar2;
  undefined3 extraout_var;
  uint uVar3;
  
  iVar2 = core_globals_get();
  uVar3 = 0;
  while( true ) {
    uVar3 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar2 + 0xb1c),*(undefined2 *)(iVar2 + 0xb24),uVar3);
    if (*(ushort *)(iVar2 + 0xb24) <= uVar3) {
      return (nwk_neighbor_t *)0x0;
    }
    nbr = (nwk_neighbor_t *)(*(int *)(iVar2 + 0xb20) + uVar3 * 0x1c);
    _Var1 = nbr_is_matched(nbr,addr_ref);
    if (CONCAT31(extraout_var,_Var1) != 0) break;
    uVar3 = uVar3 + 1 & 0xffff;
  }
  return nbr;
}

