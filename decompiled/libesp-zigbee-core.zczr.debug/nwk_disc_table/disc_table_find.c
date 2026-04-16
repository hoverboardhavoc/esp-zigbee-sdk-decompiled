/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> disc_table_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_potential_parent_t *
disc_table_find(nwk_disc_table_t *tbl,nwk_panid_ref_t panid_ref,_Bool is_short,ezb_addr_t *addr)

{
  _Bool _Var1;
  undefined3 extraout_var;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    uVar2 = bitmap_find_next_bit(tbl->ent_in_use,6,uVar2);
    if (5 < uVar2) {
      return (nwk_potential_parent_t *)0x0;
    }
    _Var1 = disc_table_ent_match(tbl->ents + uVar2,panid_ref,is_short,addr);
    if (CONCAT31(extraout_var,_Var1) != 0) break;
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return tbl->ents + uVar2;
}

