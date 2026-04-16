/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> addr_table_new
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_addr_ref_t addr_table_new(nwk_addr_table_t *tbl)

{
  uint n;
  
  n = bitmap_find_first_zero_bit(tbl->ent_in_use,tbl->ent_nr);
  if (n < tbl->ent_nr) {
    test_and_set_bitmap(n,tbl->ent_in_use);
    tbl->ents[n].lru.next = 0xffff;
    tbl->ents[n].lru.prev = 0xffff;
    addr_table_lru_add(tbl,(nwk_addr_ref_t)n);
  }
  else {
    n = 0xffff;
  }
  return (nwk_addr_ref_t)n;
}

