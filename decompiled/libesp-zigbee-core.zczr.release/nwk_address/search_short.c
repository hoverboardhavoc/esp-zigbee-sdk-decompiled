/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> search_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_addr_ref_t search_short(nwk_addr_table_t *tbl,ezb_shortaddr_t shortaddr)

{
  undefined2 in_register_0000202e;
  uint uVar1;
  nwk_addr_table_ent_t *ent;
  
  uVar1 = 0;
  while ((uVar1 = bitmap_find_next_bit(tbl->ent_in_use,tbl->ent_nr,uVar1), uVar1 < tbl->ent_nr &&
         (((*(ushort *)&tbl->ents[uVar1].ref_cnt >> 10 & 1) != 0 ||
          ((uint)tbl->ents[uVar1].shortaddr != CONCAT22(in_register_0000202e,shortaddr)))))) {
    uVar1 = uVar1 + 1 & 0xffff;
  }
  return (nwk_addr_ref_t)uVar1;
}

