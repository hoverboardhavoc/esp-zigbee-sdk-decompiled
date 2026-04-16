/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> search_extended
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_addr_ref_t search_extended(nwk_addr_table_t *tbl,ezb_extaddr_t *extaddr)

{
  _Bool _Var1;
  undefined3 extraout_var;
  uint uVar2;
  
  uVar2 = 0;
  while ((uVar2 = bitmap_find_next_bit(tbl->ent_in_use,tbl->ent_nr,uVar2), uVar2 < tbl->ent_nr &&
         (((*(ushort *)&tbl->ents[uVar2].ref_cnt >> 10 & 1) != 0 ||
          (_Var1 = nwk_extaddr_cmp(extaddr,&tbl->ents[uVar2].extaddr_c),
          CONCAT31(extraout_var,_Var1) == 0))))) {
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return (nwk_addr_ref_t)uVar2;
}

