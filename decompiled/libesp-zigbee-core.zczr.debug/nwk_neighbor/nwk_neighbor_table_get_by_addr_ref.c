/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
    nbr = (nwk_neighbor_t *)(*(int *)(iVar2 + 0xb20) + uVar3 * 0x20);
    _Var1 = nbr_is_matched(nbr,addr_ref);
    if (CONCAT31(extraout_var,_Var1) != 0) break;
    uVar3 = uVar3 + 1 & 0xffff;
  }
  return nbr;
}

